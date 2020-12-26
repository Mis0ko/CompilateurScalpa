.data
PTC_CONST_1_:	.word 0
PTC_a_:	.word 0
PTC_CONST_3_:	.word 100
PTC_CONST_5_:	.word 2
PTC_TEMP_1_:	.word 0
PTC_CONST_7_:	.word 1
PTC_CONST_9_:	.word 1
PTC_TEMP_3_:	.word 0
PTC_CONST_11_:	.word 4
PTC_TEMP_5_:	.word 0
PTC_CONST_13_:	.word 200
PTC_end_:	.word 0
.text
main:
LABEL_Q_0:
    lw $t0, PTC_CONST_1_
    sw $t0, PTC_a_
LABEL_Q_1:
    lw $t0, PTC_a_
    lw $t1, PTC_CONST_3_
    slt $t2, $t0, $t1
    beq $t2, 1, LABEL_Q_3
LABEL_Q_2:
    j LABEL_Q_12
LABEL_Q_3:
    lw $t0, PTC_a_
    lw $t1, PTC_CONST_5_
    div $t0, $t1
    mflo $t2
    sw $t2, PTC_TEMP_1_
LABEL_Q_4:
    lw $t0, PTC_TEMP_1_
    lw $t1, PTC_CONST_7_
    beq $t0, $t1, LABEL_Q_6
LABEL_Q_5:
    j LABEL_Q_9
LABEL_Q_6:
    lw $t0, PTC_a_
    lw $t1, PTC_CONST_9_
    add $t2, $t0, $t1
    sw $t2, PTC_TEMP_3_
LABEL_Q_7:
    lw $t0, PTC_TEMP_3_
    sw $t0, PTC_a_
LABEL_Q_8:
    j LABEL_Q_1
LABEL_Q_9:
    lw $t0, PTC_a_
    lw $t1, PTC_CONST_11_
    add $t2, $t0, $t1
    sw $t2, PTC_TEMP_5_
LABEL_Q_10:
    lw $t0, PTC_TEMP_5_
    sw $t0, PTC_a_
LABEL_Q_11:
    j LABEL_Q_1
LABEL_Q_12:
    lw $t0, PTC_CONST_13_
    sw $t0, PTC_end_
LABEL_END:
    li $v0, 10
    syscall
