.model small
.stack 100h
.data
  

table dw 0,0,0,0
      dw 0,0,0,0
      dw 0,0,0,0
      dw 0,0,0,0

x db 0
y db 0      

count_value db 10h

value_col dw 0
value_row dw 0

is_change db 0
                  

result dw 0
str_result db 7 dup('$')

is_win db 0      
      
start:
    mov ax,@data
    mov ds,ax 
    inc is_change
while:
    call insert_rand_value
    call print_stage
    call is_lose
    
    cmp is_win,00h
    jne win
    
while_not_print:    
    mov ax, 0100h
    int 16h
    jz  while_not_print
               
    xor ah, ah
    int 16h
 
is_up:    
    cmp ah,48h  ;scan code
    jne is_left
    
    call up
    jmp while
    
is_left:    
    cmp ah,4bh
    jne is_down 
    
    call left
    jmp while

is_down:    
    cmp ah,50h
    jne is_right
    
    call down
    jmp while
    
is_right:
    cmp ah,4dh
    jne is_esc
        
    call right
    jmp while
    
is_esc:
    cmp ah,01
    jne while_not_print
    
    jmp  _end       


;;; is lose ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
is_lose proc
    push si
    push ax
    push cx
    
    xor si,si

    mov cx,16
    
    push cx
find_empty:
    cmp table[si],0000h
    je end_is_lose 
    add si,2
loop find_empty   
    pop cx
empty_not:
    xor si,si    
    mov cx,0003h
       
check_full_row:

    push cx
    mov cx,0003h
    
check_row:
    
    mov ax,table[si] 
    
    cmp ax,table[si+2]
    je end_is_lose
    
    cmp ax,table[si+8]
    je end_is_lose
    add si,2
loop check_row
    
    mov ax,table[si] 
    
    cmp ax,table[si+8]
    je end_is_lose
    
    add si,2    
    pop cx
loop check_full_row
    
    push cx
    mov ax,table[si]     
    cmp ax,table[si+2]
    je end_is_lose
    
    add si,2
    mov ax,table[si]  
    cmp ax,table[si+2]
    je end_is_lose 
    
    add si,2
    mov ax,table[si]  
    cmp ax,table[si+2]
    je end_is_lose   
    
lose:
    jmp _lose 

end_is_lose:
    pop cx
    pop cx
    pop ax
    pop si
    ret
endp is_lose    

;;;insert rand value;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;   
insert_rand_value proc 
        
    push si
    push cx
    push bx 
    push ax
    push dx
    
    cmp is_change,00h
    je end_insert_rand_value
    
    xor si,si
    mov cx,17
    
    xor bx,bx
    
    sub si,2
    
find_empty_value:
    dec cx
    cmp cx,0000h
    je check_count_empty
    add si,2
    
    cmp table[si],0000h
    jne find_empty_value
    
    inc bx
    jmp find_empty_value
       
check_count_empty:    
    cmp bx,0000h
    je end_insert_rand_value

    mov ax,2c00h ;read time dh-sec dl-part sec
    int 21h    
    
      
    mov ax,dx 
    add al,ah
    xor ah,ah
    div bl
   
    xor si,si
    
insert_value:
    
    cmp table[si],0000h
    je is_can_insert
    
    add si,2
    jmp insert_value     

is_can_insert:
    cmp ah,0000h
    je insert  
        
    dec ah
    cmp ah,0000h
    je insert
    
    add si,2
    jmp insert_value
    
insert:
    mov table[si],2    
      
end_insert_rand_value: 

    pop ax
    pop dx      
    pop bx
    pop si
    pop cx
    ret 
endp insert_rand_value        

;;; up ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
up proc
    mov is_change,00h
    
    mov value_col,0000h
    mov cx,4
       
work_with_col_up:
    mov si,value_col
    call check_col_up    
    call work_col_up
    add value_col,2
loop work_with_col_up
 
    ret   
endp up 

check_col_up proc
    push si
    mov ax,table[si]
    cmp ax,0000h
    jne check_up_2
  
     
  add si,8   ;2
  mov ax,table[si]
  cmp ax,0000h
  je empty_1_2_up
  
  inc is_change
  
  sub si,8     ;1
  mov table[si],ax
  
  add si,16      ;3
  mov ax,table[si]
  sub si,8         ;2
  mov table[si],ax
  
  add si,16         ;4
  mov ax,table[si]
  sub si,8           ;3
  mov table[si],ax
  
  add si,8          ;4
  mov table[si],0000h 
  
  sub si,24         ;1
  jmp check_up_2

empty_1_2_up:
  add si,8         ;3
  mov ax,table[si]
  cmp ax,0000h
  je empty_1_3_up
  
  inc is_change

  sub si,16        ;1
  mov table[si],ax
  
  add si,16         ;3
  mov table[si],0000h

  sub si,16
  jmp check_up_2
  
empty_1_3_up:
  add si,8  ;4
  mov ax,table[si]
  cmp ax,0000h
  je end_check_col_up
      
   inc is_change
     
   sub si,24   ;1
  mov table[si],ax
  
  add si,24
  mov table[si],0000h
  jmp end_check_col_up
  

check_up_2:
  add si,8  ;2
  mov ax,table[si]
  cmp ax,0000h
  jne check_up_3 
  
  
  add si,8     ;3
  mov ax,table[si]
  cmp ax,0000h
  je empty_2_3
  
    inc is_change
    
  sub si,8     ;2
  mov table[si],ax
  add si,16      ;4
  
  mov ax,table[si]
  sub si,8        ;3
  mov table[si],ax
  
  add si,8         ;4
  mov table[si],0000h
  sub si,16
  
  jmp check_up_3
  
empty_2_3:
  add si,8      ;4
  mov ax,table[si]
  cmp ax,0000h
  je end_check_col_up
  
    inc is_change
    
  sub si,16       ;2
  mov table[si],ax      
  add si,16         ;4
  mov table[si],0000h
  
  jmp end_check_col_up
check_up_3:
  add si,8        ;3
  mov ax,table[si]
  cmp ax,0000h
  jne end_check_col_up
  
  add si,8        ;
  mov ax,table[si]
  mov table[si],0000h
  sub si,8     ;3
  mov table[si],ax
  
  cmp ax,0000h
  je end_check_col_up
  
  inc is_change     
  
 end_check_col_up:    
    pop si
    ret
endp check_col_up    

work_col_up proc
      
  mov ax,table[si]
  add si,8
  mov bx,table[si]
 
  cmp ax,bx
  jne not_equel_up_1_2
 
  cmp ax,0000h
  je not_equel_up_1_2 
  
   inc is_change
  
  sub si,8
  add table[si],ax
  add result,ax 
  add result,ax
  
  add si,16
  mov ax,table[si]
  sub si,8
  mov table[si],ax
  
  add si,16
  mov ax,table[si]
  sub si,8
  mov table[si],ax
  
  add si,8
  mov table[si],0000h
         
  sub si,16   
 
not_equel_up_1_2:
  mov ax,table[si];2
  add si,8
  mov bx,table[si];3
 
  cmp ax,bx
  jne not_equel_up_2_3  
  
  cmp ax,0000h
  je not_equel_up_2_3
  
   inc is_change
  
  sub si,8
  add table[si],ax
  add result,ax
  add result,ax
  
  add si,16
  mov ax,table[si]
  sub si,8
  mov table[si],ax
  
  add si,8
  mov table[si],0000h
         
  sub si,8
   
not_equel_up_2_3:
  mov ax,table[si]
  add si,8
  mov bx,table[si]
 
  cmp ax,bx
  jne not_equel_up_3_4
  
  cmp ax,0000h
  je not_equel_up_3_4
  
  inc is_change
  
  sub si,8
  add table[si],ax 
  add result,ax
  add result,ax
  
  add si,8
  mov table[si],0000h
  
not_equel_up_3_4:     
  ret  
endp work_col_up    


;;;; down ;;;;; ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
down proc
  mov is_change,00h
    
  mov value_col,24
    mov cx,4
       
work_with_col_down:
    mov si,value_col
    call check_col_down    
    call work_col_down
    add value_col,2
loop work_with_col_down
  ret  
endp down

check_col_down proc
    push si
    mov ax,table[si]
    cmp ax,0000h
    jne check_down_3
    
    
  sub si,8        ;3
  mov ax,table[si]
  cmp ax,0000h
  je empty_4_3_down
  
    inc is_change
  
  add si,8       ;4
  mov table[si],ax
  
  sub si,16     ;2
  mov ax,table[si]
  add si,8         ;3
  mov table[si],ax
  
  sub si,16          ;1
  mov ax,table[si]
  add si,8             ;2
  mov table[si],ax
  
  sub si,8               ;1
  mov table[si],0000h 
  
  add si,24
  jmp check_down_3

empty_4_3_down:
  sub si,8      ;2
  mov ax,table[si]
  cmp ax,0000h
  je empty_4_2_down
  
   inc is_change

  add si,16        ;4
  mov table[si],ax
  
  sub si,16          
  mov table[si],0000h
  
  add si, 16
  jmp check_down_3
  
empty_4_2_down:
  sub si,8   ;1
  mov ax,table[si]
  cmp ax,0000h
  je end_check_col_down
  
  inc is_change
  
  add si,24    ;4
  mov table[si],ax
  
  sub si,24
  mov table[si],0000h
  jmp end_check_col_down
  

check_down_3:
  sub si,8   ;3
  mov ax,table[si]
  cmp ax,0000h
  jne check_down_2 
  
  sub si,8  ;2
  mov ax,table[si]
  cmp ax,0000h
  je empty_3_2_down 
  
    inc is_change
  
  add si,8    ;3
  mov table[si],ax
  sub si,16     ;1
  
  mov ax,table[si]
  add si,8        ;2
  mov table[si],ax
  
  sub si,8          ;1
  mov table[si],0000h
  add si,16
  jmp check_down_2
   
  
empty_3_2_down:
  sub si,8 ;1
  mov ax,table[si]
  cmp ax,0000h
  je end_check_col_down
  
    inc is_change
    
  add si,16 ;3
  mov table[si],ax      
  sub si,16     ;1
  mov table[si],0000h
  
  jmp end_check_col_down
check_down_2:
  sub si,8    ;2
  mov ax,table[si]
  cmp ax,0000h
  jne end_check_col_down
  
  
  
  sub si,8       ;1
  mov ax,table[si]
  cmp ax,0000h
  je end_check_col_down
  
  mov table[si],0000h
  add si,8   ;2
  mov table[si],ax
   inc is_change
    
 end_check_col_down:    
    pop si
    ret
endp check_col_down

work_col_down proc
      
  mov ax,table[si]
  sub si,8
  mov bx,table[si]
 
  cmp ax,bx
  jne not_equel_down_3_4 
  
  cmp ax,0000h
  je not_equel_down_3_4
   
  inc is_change
 
  add si,8
  add table[si],ax
  add result,ax
  add result,ax
  
  sub si,16
  mov ax,table[si]
  add si,8
  mov table[si],ax
  
  sub si,16
  mov ax,table[si]
  add si,8
  mov table[si],ax
  
  sub si,8
  mov table[si],0000h
         
  add si,16   
 
not_equel_down_3_4:
  mov ax,table[si];2
  sub si,8
  mov bx,table[si];3
 
  cmp ax,bx
  jne not_equel_down_2_3
  
  cmp ax,0000h
  je not_equel_down_2_3
  inc is_change  
  
  add si,8
  add table[si],ax
  add result,ax
  add result,ax
  
  sub si,16
  mov ax,table[si]
  add si,8
  mov table[si],ax
  
  sub si,8
  mov table[si],0000h
         
  add si,8
   
not_equel_down_2_3:
  mov ax,table[si]
  sub si,8
  mov bx,table[si]
 
  cmp ax,bx
  jne not_equel_down_1_2
  
  cmp ax,0000h
  je not_equel_down_1_2
  inc is_change
  
  add si,8
  add table[si],ax
  add result,ax
  add result,ax
  
  sub si,8
  mov table[si],0000h
  
not_equel_down_1_2:     
  ret  
endp work_col_down 

 
;;; left ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;; 
left proc
   mov is_change,00h
    
   mov value_row,0
   mov cx,4
       
work_with_row_left:
    mov si,value_row
    call check_row_left    
    call work_row_left
    add value_row,8
loop work_with_row_left

  ret    
endp left

check_row_left proc
    push si
    mov ax,table[si];1
    cmp ax,0000h
    jne check_left_2
 
    
  add si,2   ;2
  mov ax,table[si]
  cmp ax,0000h
  je empty_1_2_left
  
   inc is_change
  
  sub si,2     ;1
  mov table[si],ax
  
  add si,4     ;3
  mov ax,table[si]
  sub si,2       ;2
  mov table[si],ax
  
  add si,4         ;4
  mov ax,table[si]
  sub si,2          ;3
  mov table[si],ax
  
  add si,2         ;4
  mov table[si],0000h 
  
  sub si,6         ;1
  jmp check_left_2

empty_1_2_left:
  add si,2         ;3
  mov ax,table[si]
  cmp ax,0000h
  je empty_1_3_left
  
   inc is_change

  sub si,4        ;1
  mov table[si],ax
  
  add si,4         ;3
  mov table[si],0000h

  sub si,4
  jmp check_left_2
  
empty_1_3_left:
  add si,2  ;4
  mov ax,table[si]
  cmp ax,0000h
  je end_check_row_left
  
   sub si,6   ;1
  mov table[si],ax
  
  cmp ax,0000h
  je  end_check_row_left
  
   inc is_change
  
  add si,6
  mov table[si],0000h
  jmp end_check_row_left
  

check_left_2:
  add si,2  ;2
  mov ax,table[si]
  cmp ax,0000h
  jne check_left_3

  
  add si,2     ;3
  mov ax,table[si]
  cmp ax,0000h
  je empty_2_3_left  
  
    
  inc is_change 
  
  sub si,2     ;2
  mov table[si],ax
  add si,4      ;4
  
  mov ax,table[si]
  sub si,2        ;3
  mov table[si],ax
  
  add si,2         ;4
  mov table[si],0000h
  sub si,4
  
  jmp check_left_3
  
empty_2_3_left:
  add si,2      ;4
  mov ax,table[si]
  cmp ax,0000h
  je end_check_row_left
  
  
  sub si,4       ;2
  mov table[si],ax 
     
  add si,4         ;4
  mov table[si],0000h
  
    
  cmp ax,0000h
  je end_check_row_left 
  inc is_change 
  
  jmp end_check_row_left 
  
check_left_3:
  add si,2        ;3
  mov ax,table[si]
  cmp ax,0000h
  jne end_check_row_left
  
  add si,2        ;4
  mov ax,table[si]
  mov table[si],0000h
  sub si,2     ;3
  mov table[si],ax 
  
   cmp ax,0000h
  je end_check_row_left
  inc is_change
  
    
 end_check_row_left:    
    pop si
    ret
endp check_row_left

work_row_left proc
      
  mov ax,table[si]
  add si,2;2
  mov bx,table[si]
 
  cmp ax,bx
  jne not_equel_left_1_2
  
   cmp ax,0000h
  je not_equel_left_1_2
  inc is_change
 
  sub si,2;1
  add table[si],ax
  add result,ax
  add result,ax
  
  add si,4;3
  mov ax,table[si]
  sub si,2;2
  mov table[si],ax
  
  add si,4;4
  mov ax,table[si]
  sub si,2;3
  mov table[si],ax
  
  add si,2  ;4
  mov table[si],0000h
         
  sub si,4   
 
not_equel_left_1_2:
  mov ax,table[si];2
  add si,2
  mov bx,table[si];3
 
  cmp ax,bx
  jne not_equel_left_2_3 
  
  cmp ax,0000h
  je not_equel_left_2_3
  inc is_change 
  
  sub si,2;2
  add table[si],ax
  add result,ax 
  add result,ax
  
  add si,4;4
  mov ax,table[si]
  sub si,2;3
  mov table[si],ax
  
  add si,2;4
  mov table[si],0000h
         
  sub si,2
   
not_equel_left_2_3:
  mov ax,table[si];3
  add si,2
  mov bx,table[si];4
 
  cmp ax,bx
  jne not_equel_left_3_4
  
  cmp ax,0000h
  je not_equel_left_3_4
  inc is_change
  
  sub si,2;3
  add table[si],ax 
  add result,ax
  add result,ax
  
  add si,2;4
  mov table[si],0000h
  
not_equel_left_3_4:     
  ret  
endp work_row_left
                 

;;;;;right;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
right proc
    
   mov is_change,00h
    
   mov value_row,6
   mov cx,4
       
work_with_row_right:
    mov si,value_row
    call check_row_right    
    call work_row_right
    add value_row,8
loop work_with_row_right

  ret    
endp right

check_row_right proc
    push si
    mov ax,table[si];4
    cmp ax,0000h
    jne check_right_3
        
  sub si,2   ;3
  mov ax,table[si]
  cmp ax,0000h
  je empty_4_3_right
  
   inc is_change
  
  add si,2     ;4
  mov table[si],ax
  
  sub si,4     ;2
  mov ax,table[si]
  add si,2       ;3
  mov table[si],ax
  
  sub si,4         ;1
  mov ax,table[si]
  add si,2          ;2
  mov table[si],ax
  
  sub si,2         ;1
  mov table[si],0000h 
  
  add si,6         ;4
  jmp check_right_3

empty_4_3_right:
  sub si,2         ;2
  mov ax,table[si]
  cmp ax,0000h
  je empty_4_2_right 
  
   inc is_change

  add si,4        ;4
  mov table[si],ax
  
  sub si,4         ;2
  mov table[si],0000h

  add si,4
  jmp check_right_3
  
empty_4_2_right:
  sub si,2  ;1
  mov ax,table[si]
  cmp ax,0000h
  je end_check_row_right
  
   inc is_change
  
  add si,6   ;4
  mov table[si],ax
  
  sub si,6
  mov table[si],0000h
  jmp end_check_row_right
  

check_right_3:
  sub si,2  ;3
  mov ax,table[si]
  cmp ax,0000h
  jne check_right_2  
 
  
  sub si,2     ;2
  mov ax,table[si]
  cmp ax,0000h
  je empty_3_2_right
  
   inc is_change
  
  add si,2     ;3
  mov table[si],ax
  sub si,4      ;1
  
  mov ax,table[si]
  add si,2        ;2
  mov table[si],ax
  
  sub si,2         ;1
  mov table[si],0000h
  add si,4
  
  jmp check_right_2
  
empty_3_2_right:
  sub si,2      ;1
  mov ax,table[si]
  cmp ax,0000h
  je end_check_row_right
  
   inc is_change
  
  add si,4       ;3
  mov table[si],ax      
  sub si,4         ;1
  mov table[si],0000h
  
  jmp end_check_row_right 
  
check_right_2:  

  sub si,2        ;2
  mov ax,table[si]
  cmp ax,0000h
  jne end_check_row_right
  
  
  sub si,2        ;1
  mov ax,table[si]
  mov table[si],0000h
  add si,2     ;2
  mov table[si],ax
  
  cmp ax,0000h
  je end_check_row_right
  
   inc is_change
    
 end_check_row_right:    
    pop si
    ret
endp check_row_right

work_row_right proc
      
  mov ax,table[si]
  sub si,2;3
  mov bx,table[si]
 
  cmp ax,bx
  jne not_equel_right_3_4
  
  cmp ax,0000h
  je not_equel_right_3_4
  inc is_change
 
  add si,2;4
  add table[si],ax
  add result,ax
  add result,ax
  
  sub si,4;2
  mov ax,table[si]
  add si,2;3
  mov table[si],ax
  
  sub si,4;1
  mov ax,table[si]
  add si,2;2
  mov table[si],ax
  
  sub si,2  ;1
  mov table[si],0000h
         
  add si,4   
 
not_equel_right_3_4:
  mov ax,table[si];3
  sub si,2
  mov bx,table[si];2
 
  cmp ax,bx
  jne not_equel_right_2_3  
                            
  cmp ax,0000h
  je not_equel_right_2_3
  inc is_change    
  
  add si,2;3
  add table[si],ax  
  add result,ax 
  add result,ax
  
  sub si,4;1
  mov ax,table[si]
  add si,2;2
  mov table[si],ax
  
  sub si,2;1
  mov table[si],0000h
         
  add si,2
   
not_equel_right_2_3:
  mov ax,table[si];2
  sub si,2
  mov bx,table[si];1
 
  cmp ax,bx
  jne not_equel_right_1_2
  
  cmp ax,0000h
  je not_equel_right_1_2
  inc is_change
  
  add si,2;2
  add table[si],ax
  add result,ax
  add result,ax
  
  sub si,2;1
  mov table[si],0000h
  
not_equel_right_1_2:     
  ret  
endp work_row_right

;;;;;;;  video  ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;    
print_stage proc
    mov ax, 0003h
    int 10h
  
    mov value_col,0
    mov value_row,0
    mov cx,0004h 
    xor dx,dx
    
    call print_full_str
    call next_row
print_full_stage:
    push cx
    mov cx,0004h 
    
print_one_row_stage:    
    call print_empty_str 
    
    call next_row 
    call print_empty_str
    
    call next_row
    call print_one_str_matrix
    
    call next_row
    call print_empty_str
    
    call next_row 
    call print_empty_str
         
    call next_row
    add value_row,8
loop print_one_row_stage
    pop cx
    call print_full_str  
loop print_full_stage
    call next_row
    call print_result
  
    
    mov x,0
    mov y,0    
    ret
endp print_stage

print_result proc
   mov ax,0952h
   mov cx,0001h
   mov bx,0007h
   int 10h
   
   add dl,01h
   mov ax,0203h
   int 10h
   
   mov ax,0945h
   mov cx,0001h
   mov bx,0007h
   int 10h
   
   add dl,01h
   mov ax,0203h
   int 10h
   
   mov ax,0953h
   mov cx,0001h
   mov bx,0007h
   int 10h
   
   add dl,01h
   mov ax,0203h
   int 10h
   
   mov ax,0955h
   mov cx,0001h
   mov bx,0007h
   int 10h
   
   add dl,01h
   mov ax,0203h
   int 10h 
   
   mov ax,094ch
   mov cx,0001h
   mov bx,0007h
   int 10h
   
   add dl,01h
   mov ax,0203h
   int 10h
   
   mov ax,0954h
   mov cx,0001h
   mov bx,0007h
   int 10h
   
   add dl,01h
   mov ax,0203h
   int 10h 
   
   mov ax,093ah
   mov cx,0001h
   mov bx,0007h
   int 10h
   
   add dl,01h
   mov ax,0203h  
   int 10h     
   
   call convert_and_print_result
   
   push dx
   mov dh,20h
   mov ax,0203h  
   int 10h
   pop dx
                
   
   ret
endp print_result

convert_and_print_result proc
    push cx
    push ax 
    push bx
    push dx
    
    mov x,dl
    
    xor bx,bx
    xor cx,cx
    xor ax,ax
    mov ax, result
    mov bl,0ah
    
    xor dx,dx 
convert:
    div bx
    push dx
    inc cl
    xor dx,dx    
    cmp ax,0000h
    jne convert
    
    show_result: 
    pop dx
    xor dh,dh
    add dl,30h
    
    
    push cx
    
    mov ah,09
    mov al,dl 
    
   mov cx,0001h
   mov bx,0007h
   int 10h
   
   push dx
   mov dh,y
   mov dl,x
   inc x
   add dl,01h
   mov ax,0203h
   int 10h
   pop dx 
   
   pop cx
loop show_result 
    
    pop dx
    pop bx
    pop ax
    pop cx
   ret 
endp convert_and_print_result    

next_row proc
   xor dl,dl 
   inc y
   mov dh,y
   mov ax,0203h
   int 10h
   ret 
endp next_row

next_col proc
   inc x
   mov dl,x
   mov ax,0203h
   int 10h
   ret 
endp next_col

print_one_str_matrix proc
   mov ax,092ah
   mov cx,0001h
   mov bx,0007h
   int 10h
   
   mov si,value_row
   add si,value_col 
   mov ax,table[si]
   cmp table[si],0000h 
   je not_print_number_one 
   
   mov dl,01h
   mov ax,0203h
   int 10h
    
   call print_value_matrix

not_print_number_one:
    
   mov dl,13h
   mov ax,0203h
   int 10h
   
   mov ax,092ah
   mov cx,0001h
   mov bx,0007h
   int 10h 
    
   add si,2 
   mov ax,table[si]
   cmp table[si],0000h  
   je not_print_number_two 
   
   mov dl,14h
   mov ax,0203h
   int 10h
call print_value_matrix

not_print_number_two:
    
   mov dl,28h
   mov ax,0203h
   int 10h
   
   mov ax,092ah
   mov cx,0001h
    mov bx,0007h
    int 10h 
   
   add si,2 
   mov ax,table[si]
   cmp table[si],0000h  
   je not_print_number_three 
   
   mov dl,29h
   mov ax,0203h
   int 10h
   call print_value_matrix

not_print_number_three:
   mov dl,3bh
   mov ax,0203h
   int 10h
   
   mov ax,092ah
   mov cx,0001h
   mov bx,0007h
   int 10h 
   
   add si,2
   mov ax,table[si]
   cmp table[si],0000h 
   je end_print_str
   
   mov dl,3ch
   mov ax,0203h
   int 10h
   call print_value_matrix

end_print_str:
    
   mov dl,4fh
   mov ax,0203h
   int 10h
   
   mov ax,092ah
   mov cx,0001h
   mov bx,0007h
   int 10h 
   mov value_col, 0000h            
   ret 
endp print_one_str_matrix



print_full_str proc 
   push cx 
   mov ax,092ah
   mov cx,0050h
   mov bx,0007h
   int 10h
   pop cx 
   ret 
endp print_full_str    

print_empty_str proc
    mov ax,092ah
    mov cx,0001h
    mov bx,0007h
    int 10h
    
    mov dl,13h
    mov ax,0203h
    int 10h
    
    mov ax,092ah
    mov cx,0001h
    mov bx,0007h
    int 10h
    
    mov dl,28h
    mov ax,0203h
    int 10h
    
    mov ax,092ah
    mov cx,0001h
    mov bx,0007h
    int 10h 
    
    mov dl,3bh
    mov ax,0203h
    int 10h
    
    mov ax,092ah
    mov cx,0001h
    mov bx,0007h
    int 10h
    
    mov dl,4fh
    mov ax,0203h
    int 10h
    
    mov ax,092ah
    mov cx,0001h
    mov bx,0007h
    int 10h
    
    ret
endp print_empty_str    

print_value_matrix proc
    push cx
    push ax
    push bx
    push dx
    push bp 
  
if_2:
    cmp table[si],0002h
    jne if_4
    
    call .2
    
    jmp end_print_value       
if_4: 

    cmp table[si],0004h
    jne if_8
    
    call .4
    
    jmp end_print_value
if_8: 
    cmp table[si],0008h
    jne if_16 
    
    call .8 
    
    jmp end_print_value
    
if_16: 
    cmp table[si],0010h
    jne if_32
    
    call .16
    
    jmp end_print_value
    
if_32:
    cmp table[si],0020h
    jne if_64
    
    call .32
                  
    jmp end_print_value   
    
if_64:
    cmp table[si],0040h
    jne if_128
     
    call .64 
    
    jmp end_print_value
    
if_128: 
    cmp table[si],0080h
    jne if_256
    
    call .128
    
    jmp end_print_value 
    
if_256: 
    cmp table[si],0100h
    jne if_512
    
    call .256
    
    jmp end_print_value 
    
if_512:
    cmp table[si],0200h
    jne if_1024
    
    call .512
    
    jmp end_print_value 

if_1024:
    cmp table[si],0400h
    jne if_2048
    
    call .1024
    
    jmp end_print_value 

if_2048:
    cmp table[si],0800h
    jne _empty

    call .2048
    jmp end_print_value
    
_empty:
    call .empty    
           
end_print_value: 

    pop bp
    pop dx
    pop bx
    pop ax
    pop cx
    ret
            
endp print_value_matrix    

.2 proc 
   
   add dl,05h
   mov ax,0203h
   int 10h
   
   mov ax,0920h
   mov cx,0001h
   mov bx,0007h
   int 10h
   
   add dl,01h
   mov ax,0203h
   int 10h
   
   mov ax,0920h
   mov cx,0001h
   mov bx,0007h
   int 10h
   
   add dl,01h
   mov ax,0203h
   int 10h
   
   mov ax,0920h
   mov cx,0001h
   mov bx,0007h
   int 10h
   
   add dl,01h
   mov ax,0203h
   int 10h
   
   mov ax,0932h
   mov cx,0001h
   mov bx,0006h
   int 10h
   
   ret
endp .2

.4 proc
    
   add dl,05h
   mov ax,0203h
   int 10h
   
   mov ax,0920h
   mov cx,0001h
   mov bx,0007h
   int 10h
   
   add dl,01h
   mov ax,0203h
   int 10h
   
   mov ax,0920h
   mov cx,0001h
   mov bx,0007h
   int 10h
   
   add dl,01h
   mov ax,0203h
   int 10h
   
   mov ax,0920h
   mov cx,0001h
   mov bx,0007h
   int 10h
   
   add dl,01h
   mov ax,0203h
   int 10h
   
   mov ax,0934h
   mov cx,0001h
   mov bx,0001h
   int 10h
     
   ret
endp .4

.8 proc
   
   add dl,05h
   mov ax,0203h
   int 10h
   
   mov ax,0920h
   mov cx,0001h
   mov bx,0007h
   int 10h
   
   add dl,01h
   mov ax,0203h
   int 10h
   
   mov ax,0920h
   mov cx,0001h
   mov bx,0007h
   int 10h
   
   add dl,01h
   mov ax,0203h
   int 10h
   
   mov ax,0920h
   mov cx,0001h
   mov bx,0007h
   int 10h
   
   add dl,01h
   mov ax,0203h
   int 10h
   
   mov ax,0938h
   mov cx,0001h
   mov bx,0002h
   int 10h
   
   ret
endp .8

.16 proc
   
   add dl,05h
   mov ax,0203h
   int 10h
   
   mov ax,0920h
   mov cx,0001h
   mov bx,0007h
   int 10h
   
   add dl,01h
   mov ax,0203h
   int 10h
   
   mov ax,0920h
   mov cx,0001h
   mov bx,0007h
   int 10h
   
   add dl,01h
   mov ax,0203h
   int 10h
   
   mov ax,0931h
   mov cx,0001h
   mov bx,0003h
   int 10h
   
   add dl,01h
   mov ax,0203h
   int 10h
   
   mov ax,0936h
   mov cx,0001h
   mov bx,0003h
   int 10h
   
   ret 
endp .16
    	  
.32 proc
   
   add dl,05h
   mov ax,0203h
   int 10h
   
   mov ax,0920h
   mov cx,0001h
   mov bx,0007h
   int 10h
   
   add dl,01h
   mov ax,0203h
   int 10h
   
   mov ax,0920h
   mov cx,0001h
   mov bx,0007h
   int 10h
   
   add dl,01h
   mov ax,0203h
   int 10h
   
   mov ax,0933h
   mov cx,0001h
   mov bx,0004h
   int 10h
   
   add dl,01h
   mov ax,0203h
   int 10h
   
   mov ax,0932h
   mov cx,0001h
   mov bx,0004h
   int 10h
   
   ret
endp .32

.64 proc
  
   add dl,05h
   mov ax,0203h
   int 10h
   
   mov ax,0920h
   mov cx,0001h
   mov bx,0007h
   int 10h
   
   add dl,01h
   mov ax,0203h
   int 10h
   
   mov ax,0920h
   mov cx,0001h
   mov bx,0007h
   int 10h
   
   add dl,01h
   mov ax,0203h
   int 10h
   
   mov ax,0936h
   mov cx,0001h
   mov bx,0005h
   int 10h
   
   add dl,01h
   mov ax,0203h
   int 10h
   
   mov ax,0934h
   mov cx,0001h
   mov bx,0005h
   int 10h
   
   ret
endp .64

.128 proc 
   
   add dl,05h
   mov ax,0203h
   int 10h
   
   mov ax,0920h
   mov cx,0001h
   mov bx,0007h
   int 10h
   
   add dl,01h
   mov ax,0203h
   int 10h
   
   mov ax,0931h
   mov cx,0001h
   mov bx,000eh
   int 10h
   
   add dl,01h
   mov ax,0203h
   int 10h
   
   mov ax,0932h
   mov cx,0001h
   mov bx,000eh
   int 10h
   
   add dl,01h
   mov ax,0203h
   int 10h
   
   mov ax,0938h
   mov cx,0001h
   mov bx,000eh
   int 10h
   
   ret
endp .128

.256 proc 
   
   add dl,05h
   mov ax,0203h
   int 10h
   
   mov ax,0920h
   mov cx,0001h
   mov bx,0007h
   int 10h
   
   add dl,01h
   mov ax,0203h
   int 10h
   
   mov ax,0932h
   mov cx,0001h
   mov bx,000dh
   int 10h
   
   add dl,01h
   mov ax,0203h
   int 10h
   
   mov ax,0935h
   mov cx,0001h
   mov bx,000dh
   int 10h
   
   add dl,01h
   mov ax,0203h
   int 10h
   
   mov ax,0936h
   mov cx,0001h
   mov bx,000dh
   int 10h
   
   ret
endp .256

.512 proc 
   
   add dl,05h
   mov ax,0203h
   int 10h
   
   mov ax,0920h
   mov cx,0001h
   mov bx,0007h
   int 10h
   
   add dl,01h
   mov ax,0203h
   int 10h
   
   mov ax,0935h
   mov cx,0001h
   mov bx,000ch
   int 10h
   
   add dl,01h
   mov ax,0203h
   int 10h
   
   mov ax,0931h
   mov cx,0001h
   mov bx,000ch
   int 10h
   
   add dl,01h
   mov ax,0203h
   int 10h
   
   mov ax,0932h
   mov cx,0001h
   mov bx,000ch
   int 10h
   
   ret
endp .512

.1024 proc 
   
   add dl,05h
   mov ax,0203h
   int 10h
   
   mov ax,0931h
   mov cx,0001h
   mov bx,000bh
   int 10h
   
   add dl,01h
   mov ax,0203h
   int 10h
   
   mov ax,0930h
   mov cx,0001h
   mov bx,000bh
   int 10h
   
   add dl,01h
   mov ax,0203h
   int 10h
   
   mov ax,0932h
   mov cx,0001h
   mov bx,000bh
   int 10h
   
   add dl,01h
   mov ax,0203h
   int 10h
   
   mov ax,0934h
   mov cx,0001h
   mov bx,000bh
   int 10h
   
   ret
endp .1024

.2048 proc 
   
   add dl,05h
   mov ax,0203h
   int 10h
   
   mov ax,0932h
   mov cx,0002h
   mov bx,0009h
   int 10h
   
   add dl,01h
   mov ax,0203h
   int 10h
   
   mov ax,0930h
   mov cx,0001h
   mov bx,0009h
   int 10h
   
   add dl,01h
   mov ax,0203h
   int 10h
   
   mov ax,0934h
   mov cx,0001h
   mov bx,0009h
   int 10h
   
   add dl,01h
   mov ax,0203h
   int 10h
   
   mov ax,0938h
   mov cx,0001h
   mov bx,0009h
   int 10h
   
   inc is_win
   
   ret
endp .2048

.empty proc 
   
   add dl,05h
   mov ax,0203h
   int 10h
   
   mov ax,0920h
   mov cx,0002h
   mov bx,0007h
   int 10h
   
   add dl,01h
   mov ax,0203h
   int 10h
   
   mov ax,0920h
   mov cx,0001h
   mov bx,0007h
   int 10h
   
   add dl,01h
   mov ax,0203h
   int 10h
   
   mov ax,0920h
   mov cx,0001h
   mov bx,0007h
   int 10h
   
   add dl,01h
   mov ax,0203h
   int 10h
   
   mov ax,0920h
   mov cx,0001h
   mov bx,0007h
   int 10h
   
   ret
endp .empty

_lose:
   mov dx,1700h
   mov ax,0203h
   int 10h 
   
    mov ax,0959h
   mov cx,0001h
   mov bx,0007h
   int 10h
   
   add dl,01h
   mov ax,0203h
   int 10h 
   
    mov ax,094fh
   mov cx,0001h
   mov bx,0007h
   int 10h
   
   add dl,01h
   mov ax,0203h
   int 10h 
   
    mov ax,0955h
   mov cx,0001h
   mov bx,0007h
   int 10h
   
   add dl,01h
   mov ax,0203h
   int 10h 
   
    mov ax,0920h
   mov cx,0001h
   mov bx,0007h
   int 10h
   
   add dl,01h
   mov ax,0203h
   int 10h
   
    mov ax,0941h
   mov cx,0001h
   mov bx,0007h
   int 10h
   
   add dl,01h
   mov ax,0203h
   int 10h
   
    mov ax,0952h
   mov cx,0001h
   mov bx,0007h
   int 10h
   
   add dl,01h
   mov ax,0203h
   int 10h
   
    mov ax,0945h
   mov cx,0001h
   mov bx,0007h
   int 10h
   
   add dl,01h
   mov ax,0203h
   int 10h 
   
    mov ax,0920h
   mov cx,0001h
   mov bx,0007h
   int 10h
   
   add dl,01h
   mov ax,0203h
   int 10h
   
    mov ax,094ch
   mov cx,0001h
   mov bx,0007h
   int 10h
   
   add dl,01h
   mov ax,0203h
   int 10h  
   
    mov ax,094fh
   mov cx,0001h
   mov bx,0007h
   int 10h
   
   add dl,01h
   mov ax,0203h
   int 10h 
   
    mov ax,0953h
   mov cx,0001h
   mov bx,0007h
   int 10h
   
   add dl,01h
   mov ax,0203h
   int 10h 
   
    mov ax,0945h
   mov cx,0001h
   mov bx,0007h
   int 10h

   jmp _end

win:
   mov dx,1700h
   mov ax,0203h
   int 10h 
   
    mov ax,0959h
   mov cx,0001h
   mov bx,0007h
   int 10h
   
   add dl,01h
   mov ax,0203h
   int 10h 
   
    mov ax,094fh
   mov cx,0001h
   mov bx,0007h
   int 10h
   
   add dl,01h
   mov ax,0203h
   int 10h 
   
    mov ax,0955h
   mov cx,0001h
   mov bx,0007h
   int 10h
   
   add dl,01h
   mov ax,0203h
   int 10h 
   
    mov ax,0920h
   mov cx,0001h
   mov bx,0007h
   int 10h
   
   add dl,01h
   mov ax,0203h
   int 10h
   
    mov ax,0941h
   mov cx,0001h
   mov bx,0007h
   int 10h
   
   add dl,01h
   mov ax,0203h
   int 10h
   
    mov ax,0952h
   mov cx,0001h
   mov bx,0007h
   int 10h
   
   add dl,01h
   mov ax,0203h
   int 10h
   
    mov ax,0945h
   mov cx,0001h
   mov bx,0007h
   int 10h
   
   add dl,01h
   mov ax,0203h
   int 10h 
   
    mov ax,0920h
   mov cx,0001h
   mov bx,0007h
   int 10h
   
   add dl,01h
   mov ax,0203h
   int 10h
   
    mov ax,0957h
   mov cx,0001h
   mov bx,0007h
   int 10h
   
   add dl,01h
   mov ax,0203h
   int 10h  
   
    mov ax,0949h
   mov cx,0001h
   mov bx,0007h
   int 10h
   
   add dl,01h
   mov ax,0203h
   int 10h 
   
    mov ax,094eh
   mov cx,0001h
   mov bx,0007h
   int 10h
   
   add dl,01h
   mov ax,0203h
   int 10h
   
    	  
_end:
    mov dh,17h
     mov ax,0203h
    int 10h
    mov ax,4c00h
    int 21h 
 
end start
