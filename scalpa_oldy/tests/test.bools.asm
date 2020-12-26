.data
PTC_CONST_1_:	.word 1
PTC_a_:	.word 0
PTC_e_:	.word 0
PTC_f_:	.word 0
PTC_CONST_3_:	.word 2
PTC_CONST_5_:	.word 2
PTC_CONST_7_:	.word 3
PTC_CONST_9_:	.word 100
PTC_CONST_11_:	.word 90
PTC_CONST_13_:	.word 0
PTC_CONST_15_:	.word 6
PTC_CONST_17_:	.word 6
PTC_TEMP_1_:	.word 0
PTC_CONST_19_:	.word 6
PTC_CONST_21_:	.word 5
PTC_CONST_23_:	.word 9
PTC_CONST_25_:	.word 10
PTC_CONST_27_:	.word 500
PTC_CONST_29_:	.word 0
.text
main:
LABEL_Q_0:
    lw $t0, PTC_CONST_1_
    sw $t0, PTC_a_
LABEL_Q_1:
    j LABEL_Q_2
LABEL_Q_2:
    lw $t0, PTC_CONST_3_
    sw $t0, PTC_a_
LABEL_Q_3:
    lw $t0, PTC_a_
    lw $t1, PTC_CONST_5_
    beq $t0, $t1, LABEL_Q_5
LABEL_Q_4:
    j LABEL_Q_6
LABEL_Q_5:
    lw $t0, PTC_CONST_7_
    sw $t0, PTC_a_
LABEL_Q_6:
    j LABEL_Q_8
LABEL_Q_7:
    lw $t0, PTC_CONST_9_
    sw $t0, PTC_a_
LABEL_Q_8:
    lw $t0, PTC_a_
    lw $t1, PTC_CONST_11_
    slt $t2, $t1, $t0
    beq $t2, 1, LABEL_Q_10
    beq $t0, $t1, LABEL_Q_10
LABEL_Q_9:
    j LABEL_Q_11
LABEL_Q_10:
    lw $t0, PTC_CONST_13_
    sw $t0, PTC_a_
LABEL_Q_11:
    lw $t0, PTC_CONST_15_
    lw $t1, PTC_CONST_17_
    add $t2, $t0, $t1
    sw $t2, PTC_TEMP_1_
LABEL_Q_12:
    lw $t0, PTC_CONST_19_
    lw $t1, PTC_CONST_21_
    beq $t0, $t1, LABEL_Q_14
LABEL_Q_13:
    j LABEL_Q_19
LABEL_Q_14:
    j LABEL_Q_15
LABEL_Q_15:
    j LABEL_Q_16
LABEL_Q_16:
    lw $t0, PTC_CONST_23_
    lw $t1, PTC_CONST_25_
    slt $t2, $t1, $t0
    beq $t2, 1, LABEL_Q_19
LABEL_Q_17:
    j LABEL_Q_18
LABEL_Q_18:
    lw $t0, PTC_CONST_27_
    sw $t0, PTC_e_
LABEL_Q_19:
    lw $t0, PTC_CONST_29_
    sw $t0, PTC_f_
LABEL_END:
    li $v0, 10
    syscall
