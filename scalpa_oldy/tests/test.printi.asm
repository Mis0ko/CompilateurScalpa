.data
PTC_CONST_1_:	.word 4
PTC_CONST_3_:	.word 6
PTC_CONST_5_:	.word 2
PTC_TEMP_1_:	.word 0
PTC_CONST_7_:	.word 72
PTC_a_:	.word 0
PTC_CONST_9_:	.word 72
.text
main:
LABEL_Q_0:
    li $v0, 1
    lw $a0, PTC_CONST_1_
    syscall
    li $v0, 0xB
    li $a0, 0xA
    syscall
LABEL_Q_1:
    lw $t0, PTC_CONST_3_
    lw $t1, PTC_CONST_5_
    add $t2, $t0, $t1
    sw $t2, PTC_TEMP_1_
LABEL_Q_2:
    li $v0, 1
    lw $a0, PTC_TEMP_1_
    syscall
    li $v0, 0xB
    li $a0, 0xA
    syscall
LABEL_Q_3:
    lw $t0, PTC_CONST_7_
    sw $t0, PTC_a_
LABEL_Q_4:
    li $v0, 1
    lw $a0, PTC_CONST_9_
    syscall
    li $v0, 0xB
    li $a0, 0xA
    syscall
LABEL_END:
    li $v0, 10
    syscall
