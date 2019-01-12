.model small
.stack 100h

.data 
count_str db 00h 

buffer db '$'    
 
file_open_message db 0dh,0ah,"Chield:File is open$",0dh,0ah
 
result_message db 0dh,0ah,"Chield:Result:$"
file_open_error db 0dh,0ah,"Chield:Error open$" 
file_read_error_message db 0dh,0ah,"Chield:Error read$"   

file_name db 126 dup(0)

begin:
    mov ax,@data
    mov ds,ax
    xor cx,cx
    
    mov cl,es:80h
    cmp cl,00h
    je file_error 
    
    xor si,si
    lea si,file_name
    mov bx,81h 
    xor ax,ax 
    dec cl
read_name_file:
    inc bx
    mov ax,es:[bx]
    mov [si],ax
    inc si
loop read_name_file        
    mov [si],'$'
    
    lea dx,file_name
    mov ah,3dh         ;open file
    mov al,00h
    int 21h
    jc file_error
    mov bx,ax
    
    jmp file_open
    
read:    
    mov cx,0001h
    lea dx,buffer
   
read_file:
    mov ah,3fh     ;read simvol
    int 21h
    jc file_read_error
    
    cmp ax,0000h
    je show
    
    cmp buffer,20h  ;space
    je read_file
    
    cmp buffer,09h  ;tab
    je read_file
    
    cmp buffer,0dh  ;\r
    je finded_str 
    
    cmp buffer,0ah  ;\n
    je finded_str
    
        
    jmp find_next_str 
    
finded_str:
    mov ah,3fh          ;read \n
    int 21h
    jc file_read_error
    
    push ax
    mov ah,count_str
    inc ah
    mov count_str,ah
    pop ax
    jmp read_file
    
find_next_str: 
    cmp buffer,00h      ;if null
    je finded_str
         
    mov ah,3fh          ;read next simvol
    int 21h
    jc file_read_error
    
    cmp ax,0000h        ; if eof
    je  show
    
    cmp buffer,00h      ;if null
    je show
    
    cmp buffer,0dh      ;if not \r
    jne find_next_str
    
    mov ah,3fh          ;read \n
    int 21h
    jc file_read_error
    
    jmp read_file       ;read next str
    
file_error:
    lea dx,file_open_error
    mov ax,0900h
    int 21h
    
    jmp _end 
    
file_open:
    lea dx,file_open_message
    mov ax,0900h
    int 21h
    
    jmp read    
    
file_read_error:
    lea dx,file_read_error_message
    mov ax,0900h
    int 21h
    
    jmp _end 
    
show:
    mov ah,3eh
    int 21h
   
    lea dx,result_message
    mov ax,0900h
    int 21h
   
    xor cx,cx
    xor ax,ax
    mov al,count_str
    mov dh,0ah
    
convert:
    div dh
    push ax
    inc cl
    xor ah,ah    
    cmp al,00h
    jne convert
    
show_result: 
    pop ax
    xchg ah,al
    xor ah,ah
    add al,30h    
    mov dl,al   
    mov ax,0200h
    int 21h
loop show_result         

_end:    
    mov ax,4c00h
    int 21h   
end begin