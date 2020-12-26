.data
PTC_val_:	.word 0
PTC_CONST_1_:	.word 42
.text
main:
LABEL_Q_0:
    lw $t0, PTC_CONST_1_
    sw $t0, PTC_val_
LABEL_Q_1:
    li $v0, 1
    lw $a0, PTC_val_
    syscall
    li $v0, 0xB
    li $a0, 0xA
    syscall
LABEL_END:
    li $v0, 10
    syscall
