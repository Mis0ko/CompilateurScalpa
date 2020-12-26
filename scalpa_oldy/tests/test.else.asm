.data
PTC_CONST_1_:	.word 1
PTC_a_:	.word 0
PTC_e_:	.word 0
PTC_f_:	.word 0
PTC_CONST_3_:	.word 1
PTC_CONST_5_:	.word 120
PTC_CONST_7_:	.word 128
PTC_CONST_9_:	.word 1
PTC_CONST_11_:	.word 120
PTC_CONST_13_:	.word 120
PTC_CONST_15_:	.word 0
PTC_CONST_17_:	.word 12
.text
main:
LABEL_Q_0:
    lw $t0, PTC_CONST_1_
    sw $t0, PTC_a_
LABEL_Q_1:
    lw $t0, PTC_a_
    lw $t1, PTC_CONST_3_
    beq $t0, $t1, LABEL_Q_3
LABEL_Q_2:
    j LABEL_Q_5
LABEL_Q_3:
    lw $t0, PTC_CONST_5_
    sw $t0, PTC_e_
LABEL_Q_4:
    j LABEL_Q_6
LABEL_Q_5:
    lw $t0, PTC_CONST_7_
    sw $t0, PTC_f_
LABEL_Q_6:
    lw $t0, PTC_a_
    lw $t1, PTC_CONST_9_
    slt $t2, $t1, $t0
    beq $t2, 1, LABEL_Q_8
LABEL_Q_7:
    j LABEL_Q_10
LABEL_Q_8:
    lw $t0, PTC_e_
    lw $t1, PTC_CONST_11_
    beq $t0, $t1, LABEL_Q_10
LABEL_Q_9:
    j LABEL_Q_12
LABEL_Q_10:
    lw $t0, PTC_e_
    lw $t1, PTC_CONST_13_
    bne $t0, $t1, LABEL_Q_12
LABEL_Q_11:
    j LABEL_Q_14
LABEL_Q_12:
    lw $t0, PTC_CONST_15_
    sw $t0, PTC_f_
LABEL_Q_13:
    j LABEL_END
LABEL_Q_14:
    lw $t0, PTC_CONST_17_
    sw $t0, PTC_a_
LABEL_END:
    li $v0, 10
    syscall
