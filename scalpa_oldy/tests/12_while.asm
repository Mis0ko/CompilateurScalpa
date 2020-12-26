.data
PTC_a_:	.word 0
PTC_b_:	.word 0
PTC_c_:	.word 0
PTC_d_:	.word 0
PTC_e_:	.word 0
PTC_CONST_1_:	.word 1
PTC_CONST_3_:	.word 2
PTC_CONST_5_:	.word 2
PTC_TEMP_1_:	.word 0
PTC_CONST_7_:	.word 54
PTC_CONST_9_:	.word 1
PTC_CONST_11_:	.word 0
PTC_CONST_13_:	.word 1
PTC_TEMP_3_:	.word 0
PTC_CONST_15_:	.word 1
PTC_TEMP_5_:	.word 0
PTC_CONST_17_:	.word 0
.text
main:
LABEL_Q_0:
    lw $t0, PTC_CONST_1_
    sw $t0, PTC_a_
LABEL_Q_1:
    lw $t0, PTC_CONST_3_
    sw $t0, PTC_b_
LABEL_Q_2:
    li $t0, 0
    lw $t1, PTC_CONST_5_
    sub $t2, $t0, $t1
    sw $t2, PTC_TEMP_1_
LABEL_Q_3:
    lw $t0, PTC_TEMP_1_
    sw $t0, PTC_c_
LABEL_Q_4:
    lw $t0, PTC_CONST_7_
    sw $t0, PTC_d_
LABEL_Q_5:
    lw $t0, PTC_CONST_9_
    sw $t0, PTC_e_
LABEL_Q_6:
    lw $t0, PTC_e_
    lw $t1, PTC_CONST_11_
    bne $t0, $t1, LABEL_Q_8
LABEL_Q_7:
    j LABEL_Q_16
LABEL_Q_8:
    lw $t0, PTC_c_
    lw $t1, PTC_CONST_13_
    add $t2, $t0, $t1
    sw $t2, PTC_TEMP_3_
LABEL_Q_9:
    lw $t0, PTC_TEMP_3_
    sw $t0, PTC_c_
LABEL_Q_10:
    lw $t0, PTC_b_
    lw $t1, PTC_CONST_15_
    sub $t2, $t0, $t1
    sw $t2, PTC_TEMP_5_
LABEL_Q_11:
    lw $t0, PTC_TEMP_5_
    sw $t0, PTC_b_
LABEL_Q_12:
    lw $t0, PTC_c_
    lw $t1, PTC_d_
    slt $t2, $t1, $t0
    beq $t2, 1, LABEL_Q_14
LABEL_Q_13:
    j LABEL_Q_6
LABEL_Q_14:
    lw $t0, PTC_CONST_17_
    sw $t0, PTC_e_
LABEL_Q_15:
    j LABEL_Q_6
LABEL_Q_16:
    li $v0, 1
    lw $a0, PTC_b_
    syscall
    li $v0, 0xB
    li $a0, 0xA
    syscall
LABEL_Q_17:
    li $v0, 1
    lw $a0, PTC_c_
    syscall
    li $v0, 0xB
    li $a0, 0xA
    syscall
LABEL_END:
    li $v0, 10
    syscall
