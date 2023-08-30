
MOV R0, #0x14000000 ;R0 è indirizzo base
MOV R1, #0 ; i=0
; R3 = int N

XOR
FOR     CMP R1, #10       ;  i< 10;
        BGE FINE           ; se i>=10 esce dal for
        LSL R2, R1, #2     ; R2 = i*4
        LDR R12, [R0,R2]    ; R12 = array[i]
        EOR R12, R12, R3          ; R12 = array[i] XOR N
        STR R12, [R0, R2]   ; array[i] = array[i] XOR N 
        ADD R1, R1, #1     ; i = i + 1
        B FOR              ; ripete ciclo for
        MOV PC, LR
FINE