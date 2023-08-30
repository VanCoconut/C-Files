MOV R0, #0x14000000 ;R0 è indirizzo base
MOV R1, #0 ; i=0
 
FOR     CMP R1, #200       ;  i< 200;
        BGE FINE           ; se i>=200 esce dal for
        LSL R2, R1, #2     ; R2 = i*4
        LDR R3, [R0, R2]    ; R3 = punteggi[i]
        ADD R3, R3, #10    ; R3 = punteggi[i] + 10
        STR R3, [R0, R2]   ; punteggi[i] = punteggi[i] + 10 
        ADD R1, R1, #1     ; i = i + 1
        B FOR              ; ripete ciclo for
FINE