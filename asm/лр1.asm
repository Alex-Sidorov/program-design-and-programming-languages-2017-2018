.model small
.stack 100h

.code
.data
    string db "HELLO, WORLD!",0ah,0dh,'$'
    
begin:

    mov ax,@data
    mov ds,ax
    mov dx,offset string
    mov ah,09h
    int 21h 
    mov ah,4Ch
    int 21h
    
end begin       