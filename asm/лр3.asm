.model small
.stack 100h 

.data

flag db 00h 
flag_two db 00h
          
left_board dw 0  
right_board dw 0  

max_size dw equ 30
size dw '$'  
arr dw 30 dup(0)
                                  
max_len_num	db equ 	8
len_num	    db 	'$'
num	db 8 dup(0)

message_for_size_arr            db "input size arr(1-30):$"
message_for_input_arr           db 0ah,0dh,"input arr:$"
message_for_input_left_board    db 0ah,0dh,"input left board:$"
message_for_input_right_board   db 0ah,0dh,"input right board:$"
message_for_result              db 0ah,0dh,"count numbers:$"
space                           db " $"
message_for_error_board         db 0ah,0dh,"left board more than right$"
message_overflow                db 0ah,0dh,"number overflow$" 
message_error_value             db 0ah,0dh,"invalid number$"

.code
begin:
    mov ax,@data
    mov ds,ax
    xor si,si
    xor bx,bx
    mov bl,10  
       
input_size_arr:
    
    lea dx,message_for_size_arr
    call output_message
    call input_num
    call convert
    
    cmp ax,1
    jl error_value
    
    cmp ax,30
    ja error_value
    
    mov size,ax 
    mov cx,size 
    
    lea dx,message_for_input_arr
    call output_message   
    
    mov flag_two,0000h 
input_arr:
    call input_num  
    call convert
    cmp flag_two,0000h ;if num is empty
    je input_arr
    
    mov arr[si],ax ;insert in array 
    add si,2       ;step on two
    
    lea dx,space
    call output_message
    mov flag_two,0000h
                         
loop input_arr

    lea dx,message_for_input_left_board
    call output_message
      
input_left_board:        
    call input_num
    call convert
    cmp flag_two,0 ;if num is empty
    je input_left_board
    
    mov left_board,ax 
    
    lea dx,message_for_input_right_board
    call output_message 
    
    mov flag_two,0000h
input_right_board:    
    call input_num
    call convert
     cmp flag_two,0 ;if num is empty
    je input_right_board
    
    mov right_board,ax
    
    mov cx,left_board 
    cmp cx,ax
    jg error_board    ; if left_board more than right_board
 
    xor si,si
    xor cx,cx 
    xor ax,ax 
    
    mov cx,size
    sub si,2h
    
find_num:
    add si,2h  
    cmp cl,0 
    je show  
    
    dec cl 
    mov dx,arr[si]
    mov ax,left_board
    cmp arr[si],ax
    jl find_num        ; if value less than left board
     
    mov dx,arr[si]            
    mov ax,right_board          
    cmp arr[si],ax
    jg find_num     ; if value more than left board
    
    inc ch
    jmp find_num    

convert proc
    push cx
    xor ax,ax
    xor dx,dx
    xor ch,ch
    mov flag,0h
     
    mov cl,len_num
    
    cmp cl,0h
    je end_convert 
    
    cmp [di],2dh
    je change_flag
       
convert_num:    
    mul bx
    jc error_overflow
    mov dl,[di]
    
    cmp dl,'0'
    jl error_value
    cmp dl,'9' 
    ja error_value
    
    sub dl,30h
    
    add al,dl
    jc error_overflow
    inc di
    
    inc flag_two
loop convert_num
 
    mov dx,7fffh
    cmp ax,0000h
    je end_convert
    
    cmp flag,0h      ;if value is negativ
    jne not_value
    
cmp_value:  
    cmp ax,dx
    jg error_overflow
        
end_convert:
    pop cx        
    ret                    
convert endp

not_value:
    not ax
    jmp cmp_value    

input_num proc
    lea dx,max_len_num
    mov ax,0a00h 
    int 21h    
    lea di,num
    ret
input_num endp

output_message proc
    mov ax,0900h
    int 21h
    ret
output_message endp

change_flag:
    mov flag, 1h 
    inc di
    dec cx
    jmp convert_num

error_board:
    lea dx,message_for_error_board
    call output_message
    jmp _end

error_overflow: 
    lea dx,message_overflow
    call output_message
    jmp _end

error_value: 
    lea dx,message_error_value
    call output_message
    jmp _end
    
show:
    lea dx,message_for_result
    call output_message
    
    xor ax,ax
    mov al,ch
    mov dh,0ah
    div dh   
   
    mov bh,ah
    cmp al,0h
    je show_two_num
    
    add al,30h    
    mov dl,al   
    mov ax,0200h
    int 21h

show_two_num:           
    add bh,30h    
    mov dl,bh   
    mov ax,0200h
    int 21h

_end:
    mov ax,4c00h 
    int 21h        
end begin