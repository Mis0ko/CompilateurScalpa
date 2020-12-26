.data
PTC_a_:	.word 0
PTC_b_:	.word 0
PTC_CONST_1_:	.word 40
PTC_CONST_3_:	.word 10
PTC_CONST_5_:	.word 0
PTC_CONST_7_:	.word 1
.text
main:
LABEL_Q_0:
    lw $t0, PTC_CONST_1_
    sw $t0, PTC_a_
LABEL_Q_1:
    lw $t0, PTC_CONST_3_
    sw $t0, PTC_b_
LABEL_Q_2:
    lw $t0, PTC_a_
    lw $t1, PTC_b_
    beq $t0, $t1, LABEL_Q_4
LABEL_Q_3:
    j LABEL_Q_5
LABEL_Q_4:
    li $v0, 1
    lw $a0, PTC_CONST_5_
    syscall
    li $v0, 0xB
    li $a0, 0xA
    syscall
LABEL_Q_5:
    li $v0, 1
    lw $a0, PTC_CONST_7_
    syscall
    li $v0, 0xB
    li $a0, 0xA
    syscall
LABEL_END:
    li $v0, 10
    syscall
