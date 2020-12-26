.data
PTC_big_:	.word 0
PTC_medium_:	.word 0
PTC_little_:	.word 0
PTC_CONST_1_:	.word 100
PTC_CONST_3_:	.word 10
PTC_CONST_5_:	.word 1
PTC_CONST_7_:	.word 2
PTC_CONST_9_:	.word 42
PTC_CONST_11_:	.word 3
.text
main:
LABEL_Q_0:
    lw $t0, PTC_CONST_1_
    sw $t0, PTC_big_
LABEL_Q_1:
    lw $t0, PTC_CONST_3_
    sw $t0, PTC_medium_
LABEL_Q_2:
    lw $t0, PTC_CONST_5_
    sw $t0, PTC_little_
LABEL_Q_3:
    lw $t0, PTC_big_
    lw $t1, PTC_medium_
    slt $t2, $t1, $t0
    beq $t2, 1, LABEL_Q_5
LABEL_Q_4:
    j LABEL_Q_11
LABEL_Q_5:
    lw $t0, PTC_medium_
    lw $t1, PTC_little_
    slt $t2, $t0, $t1
    beq $t2, 1, LABEL_Q_7
LABEL_Q_6:
    j LABEL_Q_9
LABEL_Q_7:
    lw $t0, PTC_CONST_7_
    sw $t0, PTC_little_
LABEL_Q_8:
    j LABEL_Q_12
LABEL_Q_9:
    lw $t0, PTC_CONST_9_
    sw $t0, PTC_little_
LABEL_Q_10:
    j LABEL_Q_12
LABEL_Q_11:
    lw $t0, PTC_CONST_11_
    sw $t0, PTC_little_
LABEL_Q_12:
    li $v0, 1
    lw $a0, PTC_little_
    syscall
    li $v0, 0xB
    li $a0, 0xA
    syscall
LABEL_END:
    li $v0, 10
    syscall
