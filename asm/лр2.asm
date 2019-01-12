.model small
.stack 100h
.code
.data

str1max_len	db equ 	201
str1len	    db 	'$'
str1	    db	200 dup('$')

str2max_len	db equ 201
str2len	    db	'$'
str2	    db	200 dup('$') 

str3max_len	db equ 201
str3len	    db	'$'
str3	    db	200 dup('$')

input_str1 db "input str1:$"  
input_str2 db 0ah,0dh,"input str2:$" 
input_str3 db 0ah,0dh,"input str3:$"
result db 0ah,0dh,"result:$"       

str1_empty_message db 0ah,0dh,"str1 empty$"
str2_empty_message db 0ah,0dh,"str2 empty$"
str3_empty_message db 0ah,0dh,"str3 empty$"

str3_not_finded db 0ah,0dh,"str3 not finded$"
str2_cant_inserted_message db 0ah,0dh,"str2 can't inserted$"
                     
begin:
    mov ax,@data
    mov ds,ax
    mov es,ax 
    
    lea dx,input_str1
    mov ah,09h
    int 21h 
   
    lea dx,str1max_len
    mov ah,0Ah
    int 21h
    
    xor ah,ah
    cmp ah,str1len
    je str1_empty
    
    lea dx,input_str2
    mov ah,09h
    int 21h
   
    lea dx,str2max_len
    mov ah,0Ah
    int 21h
    
    xor ah,ah
    cmp ah,str2len
    je str2_empty   
    
    lea dx,input_str3
    mov ah,09h
    int 21h
    
    lea dx,str3max_len
    mov ah,0Ah
    int 21h  
    
    xor ah,ah
    cmp ah,str3len
    je str3_empty 
    
    mov bh,str1len
    add bh,str2len
    sub bh,str3len
    
    cmp bh,str1max_len
    ja str2_cant_inserted 
    
    
    xor	cx, cx
    mov	cl, str1len
    sub cl, str3len
    inc cl
    cld       
      
    lea si,str1
    lea di,str3
    
    xor ax,ax
    
cicle1:

    push cx
    push si
    push di
    
    mov bx,si
    
    mov cl,str3len
    repe cmpsb
    je finded     
    
    pop di
    pop si
    pop cx
    
    inc si
        
loop cicle1    

not_finded:
    lea dx,str3_not_finded
    mov ah,09h
    int 21h
    jmp go_to_end
            
finded:
    mov ah,str2len
    mov al,str3len
    cmp ah,al
    je if_equally
    ja if_larger
    jl if_less
        
if_equally:
    mov si,bx
    xor cx,cx
    mov cl,al
    xor di,di
    
cicle2:
    mov al,str2[di]
    mov [si],al
    inc si
    inc di
loop cicle2    
    jmp show

if_larger:

    mov si,bx
    xor ax,ax
    mov al,str3len
    add si,ax 
    
    xor ax,ax
    mov al,str2len
    sub al,str3len
    
    mov dx,0
    call proc1
    
if_less:

    mov si,bx
    xor ax,ax
    mov al,str3len
    add si,ax 
    
    xor ax,ax 
    
    mov al,str3len
    sub al,str2len
    
    mov dx,1
    call proc1 
       
show:
    lea dx,result
    mov ah,09h
    int 21h
    lea dx,str1
    mov ah,09h
    int 21h
    
go_to_end:
    mov ax,4c00h 
    int 21h

proc1 proc       
    dec si
    xor cx,cx
     
cicle3:
    inc si
    inc cx
    push [si]   
    cmp [si],0dh
    jne cicle3
    
    cmp dx,0
    je add_si
    jne sub_si
    
cicle4:
    pop [si]    
    dec si 
    
loop cicle4
    xor cx,cx
    xor bx,bx
    mov bl,str2len
    dec bl
    mov cl,str2len

cicle5:
    mov al,str2[bx]
    mov [si],al
    dec si
    dec bx 
    
loop cicle5
    jmp show
proc1 endp 

add_si:
    add si,ax
    jmp cicle4
    
sub_si:
    sub si,ax
    jmp cicle4 
    
str1_empty:
    lea dx,str1_empty_message
    mov ah,09h
    int 21h
    jmp go_to_end

str2_empty:
    lea dx,str2_empty_message
    mov ah,09h
    int 21h
    jmp go_to_end
    
str3_empty:
    lea dx,str3_empty_message
    mov ah,09h
    int 21h
    jmp go_to_end
    
str2_cant_inserted:
    lea dx,str2_cant_inserted_message
    mov ah,09h
    int 21h
    jmp go_to_end
           
end begin                     