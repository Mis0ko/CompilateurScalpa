.data
PTC_CONST_1_:	.word 5
PTC_a_:	.word 0
PTC_CONST_3_:	.word 3
PTC_b_:	.word 0
PTC_CONST_5_:	.word 100
PTC_c_:	.word 0
PTC_CONST_7_:	.word 10
PTC_CONST_9_:	.word 0
PTC_CONST_11_:	.word 0
PTC_CONST_13_:	.word 200
PTC_CONST_15_:	.word 100
PTC_CONST_17_:	.word 500
PTC_CONST_19_:	.word 100
PTC_CONST_21_:	.word 6
PTC_CONST_23_:	.word 10
PTC_CONST_25_:	.word 1
PTC_CONST_27_:	.word 0
.text
main:
LABEL_Q_0:
    lw $t0, PTC_CONST_1_
    sw $t0, PTC_a_
LABEL_Q_1:
    lw $t0, PTC_CONST_3_
    sw $t0, PTC_b_
LABEL_Q_2:
    lw $t0, PTC_CONST_5_
    sw $t0, PTC_c_
LABEL_Q_3:
    lw $t0, PTC_a_
    lw $t1, PTC_b_
    slt $t2, $t1, $t0
    beq $t2, 1, LABEL_Q_5
    beq $t0, $t1, LABEL_Q_5
LABEL_Q_4:
    j LABEL_Q_6
LABEL_Q_5:
    lw $t0, PTC_CONST_7_
    sw $t0, PTC_b_
LABEL_Q_6:
    lw $t0, PTC_b_
    lw $t1, PTC_a_
    slt $t2, $t1, $t0
    beq $t2, 1, LABEL_Q_8
LABEL_Q_7:
    j LABEL_Q_9
LABEL_Q_8:
    lw $t0, PTC_CONST_9_
    sw $t0, PTC_b_
LABEL_Q_9:
    lw $t0, PTC_b_
    lw $t1, PTC_CONST_11_
    beq $t0, $t1, LABEL_Q_11
LABEL_Q_10:
    j LABEL_Q_12
LABEL_Q_11:
    lw $t0, PTC_CONST_13_
    sw $t0, PTC_c_
LABEL_Q_12:
    lw $t0, PTC_c_
    lw $t1, PTC_CONST_15_
    bne $t0, $t1, LABEL_Q_14
LABEL_Q_13:
    j LABEL_Q_15
LABEL_Q_14:
    lw $t0, PTC_c_
    sw $t0, PTC_a_
LABEL_Q_15:
    lw $t0, PTC_a_
    lw $t1, PTC_c_
    slt $t2, $t0, $t1
    beq $t2, 1, LABEL_Q_17
    beq $t0, $t1, LABEL_Q_17
LABEL_Q_16:
    j LABEL_Q_18
LABEL_Q_17:
    lw $t0, PTC_CONST_17_
    sw $t0, PTC_a_
LABEL_Q_18:
    lw $t0, PTC_a_
    lw $t1, PTC_c_
    slt $t2, $t0, $t1
    beq $t2, 1, LABEL_Q_20
LABEL_Q_19:
    j LABEL_Q_21
LABEL_Q_20:
    lw $t0, PTC_CONST_19_
    sw $t0, PTC_a_
LABEL_Q_21:
    lw $t0, PTC_CONST_21_
    lw $t1, PTC_CONST_23_
    slt $t2, $t0, $t1
    beq $t2, 1, LABEL_Q_23
LABEL_Q_22:
    j LABEL_Q_25
LABEL_Q_23:
    li $v0, 1
    lw $a0, PTC_CONST_25_
    syscall
    li $v0, 0xB
    li $a0, 0xA
    syscall
LABEL_Q_24:
    j LABEL_END
LABEL_Q_25:
    li $v0, 1
    lw $a0, PTC_CONST_27_
    syscall
    li $v0, 0xB
    li $a0, 0xA
    syscall
LABEL_END:
    li $v0, 10
    syscall
