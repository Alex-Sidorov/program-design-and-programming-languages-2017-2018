.model tiny
.code  
.386
org 100h

start:

	jmp start_resident
	
	name_file db "file.txt", 0
	buffer   db 3000 dup ('0') 
	max_size_buffer dw 3000
	size_buffer dw 0
	handle_file dw 0
	col db 0
	row db 0
	
	message_start db 'B',19h,'E',19h,'G',19h,'I',19h, 'N',19h
    size_message_start = $-message_start  
    message_save db 'S',29h,'A',29h,'V',29h,'E',29h, ' ',00h
    size_message_save = $-message_save   
    message_error db 'E',40h,'R',40h,'R',40h,'O',40h, 'R',40h
    size_message_error = $-message_error
	
	old_09	dd	0

proc new_09
    pusha
    pushf
    push ds
    push es
    push cs
    pop ds
	
	in al, 60h 
	
	cmp al, 3bh ;проверка на f1
    je writing_to_file
	
	jmp end_interrupt
	
writing_to_file:      

	push si
	push ax
	push dx
	push bx
	
	xor si,si
	xor bx,bx
	xor dx,dx
	
	mov ax,0303h;чтение курсора
	int 10h
	
	mov col,dl
	mov row,dh
	
	xor dx,dx
	
	mov ax, 0203h;установка курсора
    int 10h
	
	dec dl
	
	mov size_buffer,00h
read_cmd:
	inc dl
	cmp dl,50h
	jl continue
	
	xor dl,dl
	inc dh
	
continue:	
	mov ax, 0203h;установка курсора
	int 10h 
	
	cmp dh,19h
	jae end_read
	
	mov ax,0803h
	int 10h
	
	cmp al,20h
	je read_cmd
	
	cmp al,00h
	je read_cmd
	
	
	
	mov buffer[si],al
	inc size_buffer
	
	inc si
	jmp read_cmd


end_read:

	mov dl,col
	mov dh,row
	
	mov ax, 0203h;установка курсора
	int 10h 

	pop bx
	pop dx
	pop ax
	pop si
	
	push cx
    call open_file 
    call write_file
    call close_file 
    pop cx 
    lea dx, message_save 
    mov bx, size_message_save
    call video_print 
	
    jmp end_interrupt
	
end_interrupt:  
    mov  al,20H   
    out  20H,al 
	
	pop es
	pop ds  
	popf  
	popa
	
	jmp dword ptr cs:old_09 ;вызов старого обработчика	
	
	iret

endp new_09

	
start_resident:
	mov ax, 0003h;очистка экрана и установка курсора в 0,0
    int 10h	
    lea dx, message_start 
    mov bx, size_message_start
	
	call video_print
	mov	ax, 3509h;; сохранить адрес предыдущего обработчика прерывания 09h	
	int	21h	
	mov	word ptr old_09, bx	;смещение обработчика
	mov	word ptr old_09+2, es;сегмент обработчика
	
	mov	ax, 2509h	;; устанавливаем новый обработчика прерывания 09h
	lea	dx, new_09	
	int	21h  
	
	lea	dx, start_resident	;резидентная
	int	27h	;завершает программу, но оставляет резидентной

error:
	lea dx, message_error 
    mov bx, size_message_error
    call video_print
	int 20h;exit

open_file proc
	push ax
	push dx    
    lea dx, name_file
    mov ax, 3d01h 
    int 21h
    jc error
    mov handle_file, ax  
    pop dx
    pop ax
    ret
endp open_file 

write_file proc 
	mov   ax, 4202h  ;конец файла
	mov bx, handle_file
	xor  cx, cx
    xor  dx, dx
    int   21h  
    jc error          
	
	mov cx, size_buffer
	lea dx, buffer
	mov ah, 40h
	int 21h 
	jc error 
	ret
endp write_file 

close_file proc
	mov ah, 3eh 
	mov bx, handle_file
	int 21h 
	jc error
    ret
endp close_file	

video_print proc
    push ax
    push es
    push si
    push cx
    cld
    mov ax,0B800h ;
    mov es,ax
    mov di,0 ; 
    mov si, dx ; 
    mov cx, bx ; 
    repne movsb
    pop cx
    pop si
    pop es
    pop ax
    ret
endp video_print  
               
end start