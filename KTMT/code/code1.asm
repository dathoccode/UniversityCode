.model small
.stack 100h
.data  
    s1  db 13, 10, 'nhap 1 ky tu: $'
    s2  db 13, 10, 'ky tu phia truoc la: $' 
    s3  db 13, 10, 'ky tu phia sau la: $'

.code
    main proc
        
        mov bl, 65
        
lab1:
        mov ah, 2 
        mov dl, bl
        int 21h 
        mov dl, ' '
        int 21h 
        inc bl
        cmp bl, 90
        jg thoat
        jmp lab1
thoat:        
        mov ah, 4ch
        int 21h  
        main endp
    end main
    