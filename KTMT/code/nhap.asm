.model small
.stack 100h
.data
    s1 db 'nhap a: $'
    s2 db 10, 13, 'nhap b: $'
    s3 db 10, 13, 'a < b$'
    s4 db 10, 13, 'a = b$'
    s5 db 10, 13, 'a > b$'
.code
    main proc
        mov ax, @data
        mov ds, ax
        
        mov ah, 9
        lea dx, s1
        int 21h
        
        mov ah, 1
        int 21h
        mov bl, al
        
        
        mov ah, 9
        lea dx, s2
        int 21h
        
        mov ah, 1
        int 21h
        mov bh, al
          
        
            
        cmp bl, bh  
        jg greater
        je equal
        jl less
        
greater: 
        mov ah, 9
        lea dx, s5
        int 21h
        jmp end

less:   
        mov ah, 9
        lea dx, s3 
        int 21h 
        jmp end      

equal:   
        mov ah, 9
        lea dx, s4 
        int 21h
        jmp end
        
end:                      
        mov ah, 4ch
        int 21h
    
        main endp
    end main