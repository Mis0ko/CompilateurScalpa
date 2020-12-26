.data
PTC_a_:	.word 0
PTC_b_:	.word 0
PTC_c_:	.word 0
PTC_CONST_1_:	.word 15
PTC_TEMP_1_:	.word 0
PTC_CONST_3_:	.word 5
PTC_CONST_5_:	.word 2
PTC_TEMP_3_:	.word 0
PTC_TEMP_5_:	.word 0
PTC_CONST_7_:	.word 5
PTC_TEMP_7_:	.word 0
PTC_TEMP_9_:	.word 0
PTC_CONST_9_:	.word 2
PTC_TEMP_11_:	.word 0
PTC_CONST_11_:	.word 5
PTC_TEMP_13_:	.word 0
PTC_TEMP_15_:	.word 0
PTC_CONST_13_:	.word 2
PTC_TEMP_17_:	.word 0
.text
main:
LABEL_Q_0:
    li $t0, 0
    lw $t1, PTC_CONST_1_
    sub $t2, $t0, $t1
    sw $t2, PTC_TEMP_1_
LABEL_Q_1:
    lw $t0, PTC_TEMP_1_
    sw $t0, PTC_a_
LABEL_Q_2:
    lw $t0, PTC_CONST_3_
    sw $t0, PTC_b_
LABEL_Q_3:
    lw $t0, PTC_CONST_5_
    lw $t1, PTC_a_
    mult $t0, $t1
    mflo $t2
    sw $t2, PTC_TEMP_3_
LABEL_Q_4:
    li $t0, 0
    lw $t1, PTC_TEMP_3_
    sub $t2, $t0, $t1
    sw $t2, PTC_TEMP_5_
LABEL_Q_5:
    lw $t0, PTC_TEMP_5_
    sw $t0, PTC_c_
LABEL_Q_6:
    lw $t0, PTC_a_
    lw $t1, PTC_b_
    beq $t0, $t1, LABEL_Q_10
LABEL_Q_7:
    j LABEL_Q_8
LABEL_Q_8:
    lw $t0, PTC_a_
    lw $t1, PTC_b_
    slt $t2, $t1, $t0
    beq $t2, 1, LABEL_Q_10
LABEL_Q_9:
    j LABEL_Q_17
LABEL_Q_10:
    lw $t0, PTC_b_
    lw $t1, PTC_CONST_7_
    sub $t2, $t0, $t1
    sw $t2, PTC_TEMP_7_
LABEL_Q_11:
    lw $t0, PTC_TEMP_7_
    sw $t0, PTC_b_
LABEL_Q_12:
    lw $t0, PTC_b_
    lw $t1, PTC_a_
    sub $t2, $t0, $t1
    sw $t2, PTC_TEMP_9_
LABEL_Q_13:
    lw $t0, PTC_TEMP_9_
    sw $t0, PTC_c_
LABEL_Q_14:
    lw $t0, PTC_c_
    lw $t1, PTC_CONST_9_
    sub $t2, $t0, $t1
    sw $t2, PTC_TEMP_11_
LABEL_Q_15:
    lw $t0, PTC_TEMP_11_
    sw $t0, PTC_c_
LABEL_Q_16:
    j LABEL_Q_23
LABEL_Q_17:
    lw $t0, PTC_b_
    lw $t1, PTC_CONST_11_
    add $t2, $t0, $t1
    sw $t2, PTC_TEMP_13_
LABEL_Q_18:
    lw $t0, PTC_TEMP_13_
    sw $t0, PTC_b_
LABEL_Q_19:
    lw $t0, PTC_b_
    lw $t1, PTC_a_
    add $t2, $t0, $t1
    sw $t2, PTC_TEMP_15_
LABEL_Q_20:
    lw $t0, PTC_TEMP_15_
    sw $t0, PTC_c_
LABEL_Q_21:
    lw $t0, PTC_c_
    lw $t1, PTC_CONST_13_
    add $t2, $t0, $t1
    sw $t2, PTC_TEMP_17_
LABEL_Q_22:
    lw $t0, PTC_TEMP_17_
    sw $t0, PTC_c_
LABEL_Q_23:
    li $v0, 1
    lw $a0, PTC_c_
    syscall
    li $v0, 0xB
    li $a0, 0xA
    syscall
LABEL_END:
    li $v0, 10
    syscall
