.data
PTC_a_:	.word 0
PTC_CONST_1_:	.word 100
PTC_b_:	.word 0
PTC_CONST_3_:	.word 2
PTC_TEMP_1_:	.word 0
PTC_c_:	.word 0
PTC_CONST_5_:	.word 50
PTC_CONST_7_:	.word 72
PTC_CONST_9_:	.word 100
PTC_CONST_11_:	.word 6
PTC_CONST_13_:	.word 10
PTC_CONST_15_:	.word 129
.text
main:
LABEL_Q_0:
    lw $t0, PTC_CONST_1_
    sw $t0, PTC_b_
LABEL_Q_1:
    lw $t0, PTC_b_
    lw $t1, PTC_CONST_3_
    div $t0, $t1
    mflo $t2
    sw $t2, PTC_TEMP_1_
LABEL_Q_2:
    lw $t0, PTC_TEMP_1_
    sw $t0, PTC_a_
LABEL_Q_3:
    lw $t0, PTC_a_
    lw $t1, PTC_CONST_5_
    beq $t0, $t1, LABEL_Q_5
LABEL_Q_4:
    j LABEL_Q_7
LABEL_Q_5:
    lw $t0, PTC_CONST_7_
    sw $t0, PTC_a_
LABEL_Q_6:
    lw $t0, PTC_CONST_9_
    sw $t0, PTC_b_
LABEL_Q_7:
    lw $t0, PTC_b_
    lw $t1, PTC_CONST_11_
    bne $t0, $t1, LABEL_Q_9
LABEL_Q_8:
    j LABEL_Q_11
LABEL_Q_9:
    lw $t0, PTC_CONST_13_
    sw $t0, PTC_a_
LABEL_Q_10:
    j LABEL_END
LABEL_Q_11:
    lw $t0, PTC_CONST_15_
    sw $t0, PTC_a_
LABEL_END:
    li $v0, 10
    syscall
