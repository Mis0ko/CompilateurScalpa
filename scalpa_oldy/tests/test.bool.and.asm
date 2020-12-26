.data
PTC_CONST_1_:	.word 3
PTC_CONST_3_:	.word 4
PTC_CONST_5_:	.word 6
PTC_CONST_7_:	.word 2
PTC_CONST_9_:	.word 1
PTC_a_:	.word 0
PTC_CONST_11_:	.word 1
PTC_b_:	.word 0
PTC_CONST_13_:	.word 3
PTC_CONST_15_:	.word 4
PTC_CONST_17_:	.word 6
PTC_CONST_19_:	.word 2
PTC_CONST_21_:	.word 1
PTC_CONST_23_:	.word 1
.text
main:
LABEL_Q_0:
    lw $t0, PTC_CONST_1_
    lw $t1, PTC_CONST_3_
    slt $t2, $t0, $t1
    beq $t2, 1, LABEL_Q_2
LABEL_Q_1:
    j LABEL_Q_5
LABEL_Q_2:
    lw $t0, PTC_CONST_5_
    lw $t1, PTC_CONST_7_
    slt $t2, $t1, $t0
    beq $t2, 1, LABEL_Q_4
LABEL_Q_3:
    j LABEL_Q_5
LABEL_Q_4:
    lw $t0, PTC_CONST_9_
    sw $t0, PTC_a_
LABEL_Q_5:
    lw $t0, PTC_CONST_11_
    sw $t0, PTC_b_
LABEL_Q_6:
    lw $t0, PTC_CONST_13_
    lw $t1, PTC_CONST_15_
    slt $t2, $t0, $t1
    beq $t2, 1, LABEL_Q_8
LABEL_Q_7:
    j LABEL_Q_11
LABEL_Q_8:
    lw $t0, PTC_CONST_17_
    lw $t1, PTC_CONST_19_
    slt $t2, $t1, $t0
    beq $t2, 1, LABEL_Q_11
LABEL_Q_9:
    j LABEL_Q_10
LABEL_Q_10:
    lw $t0, PTC_CONST_21_
    sw $t0, PTC_a_
LABEL_Q_11:
    lw $t0, PTC_CONST_23_
    sw $t0, PTC_b_
LABEL_END:
    li $v0, 10
    syscall
