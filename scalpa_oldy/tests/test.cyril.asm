.data
PTC_a_:	.word 0
PTC_b_:	.word 0
PTC_CONST_1_:	.word 5
PTC_CONST_3_:	.word 5
PTC_CONST_5_:	.word 5
PTC_CONST_7_:	.word 5
PTC_CONST_9_:	.word 1
PTC_TEMP_1_:	.word 0
PTC_CONST_11_:	.word 0
PTC_CONST_13_:	.word 1
PTC_TEMP_3_:	.word 0
PTC_CONST_15_:	.word 7
PTC_CONST_17_:	.word 111
PTC_CONST_19_:	.word 7
PTC_CONST_21_:	.word 222
PTC_CONST_23_:	.word 7
PTC_CONST_25_:	.word 333
PTC_CONST_27_:	.word 7
PTC_CONST_29_:	.word 444
PTC_CONST_31_:	.word 7
PTC_CONST_33_:	.word 555
PTC_CONST_35_:	.word 7
PTC_CONST_37_:	.word 666
PTC_tmp_:	.word 0
PTC_CONST_39_:	.word 2
PTC_CONST_41_:	.word 4
PTC_TEMP_5_:	.word 0
PTC_CONST_43_:	.word 2
PTC_CONST_45_:	.word 4
PTC_TEMP_7_:	.word 0
PTC_CONST_47_:	.word 2
PTC_CONST_49_:	.word 4
PTC_TEMP_9_:	.word 0
PTC_CONST_51_:	.word 4
PTC_CONST_53_:	.word 2
PTC_TEMP_11_:	.word 0
PTC_CONST_55_:	.word 5
.text
main:
LABEL_Q_0:
    lw $t0, PTC_CONST_1_
    sw $t0, PTC_a_
LABEL_Q_1:
    li $v0, 1
    lw $a0, PTC_CONST_3_
    syscall
    li $v0, 0xB
    li $a0, 0xA
    syscall
LABEL_Q_2:
    li $v0, 1
    lw $a0, PTC_a_
    syscall
    li $v0, 0xB
    li $a0, 0xA
    syscall
LABEL_Q_3:
    lw $t0, PTC_a_
    lw $t1, PTC_CONST_5_
    beq $t0, $t1, LABEL_Q_5
LABEL_Q_4:
    j LABEL_Q_7
LABEL_Q_5:
    lw $t0, PTC_CONST_7_
    lw $t1, PTC_CONST_9_
    add $t2, $t0, $t1
    sw $t2, PTC_TEMP_1_
LABEL_Q_6:
    lw $t0, PTC_TEMP_1_
    sw $t0, PTC_a_
LABEL_Q_7:
    lw $t0, PTC_CONST_11_
    sw $t0, PTC_b_
LABEL_Q_8:
    lw $t0, PTC_b_
    lw $t1, PTC_a_
    slt $t2, $t0, $t1
    beq $t2, 1, LABEL_Q_10
    beq $t0, $t1, LABEL_Q_10
LABEL_Q_9:
    j LABEL_Q_14
LABEL_Q_10:
    lw $t0, PTC_b_
    lw $t1, PTC_CONST_13_
    add $t2, $t0, $t1
    sw $t2, PTC_TEMP_3_
LABEL_Q_11:
    lw $t0, PTC_TEMP_3_
    sw $t0, PTC_b_
LABEL_Q_12:
    li $v0, 1
    lw $a0, PTC_b_
    syscall
    li $v0, 0xB
    li $a0, 0xA
    syscall
LABEL_Q_13:
    j LABEL_Q_8
LABEL_Q_14:
    lw $t0, PTC_b_
    lw $t1, PTC_CONST_15_
    beq $t0, $t1, LABEL_Q_16
LABEL_Q_15:
    j LABEL_Q_17
LABEL_Q_16:
    li $v0, 1
    lw $a0, PTC_CONST_17_
    syscall
    li $v0, 0xB
    li $a0, 0xA
    syscall
LABEL_Q_17:
    lw $t0, PTC_b_
    lw $t1, PTC_CONST_19_
    slt $t2, $t1, $t0
    beq $t2, 1, LABEL_Q_19
    beq $t0, $t1, LABEL_Q_19
LABEL_Q_18:
    j LABEL_Q_20
LABEL_Q_19:
    li $v0, 1
    lw $a0, PTC_CONST_21_
    syscall
    li $v0, 0xB
    li $a0, 0xA
    syscall
LABEL_Q_20:
    lw $t0, PTC_b_
    lw $t1, PTC_CONST_23_
    slt $t2, $t1, $t0
    beq $t2, 1, LABEL_Q_22
LABEL_Q_21:
    j LABEL_Q_23
LABEL_Q_22:
    li $v0, 1
    lw $a0, PTC_CONST_25_
    syscall
    li $v0, 0xB
    li $a0, 0xA
    syscall
LABEL_Q_23:
    lw $t0, PTC_b_
    lw $t1, PTC_CONST_27_
    slt $t2, $t0, $t1
    beq $t2, 1, LABEL_Q_25
LABEL_Q_24:
    j LABEL_Q_26
LABEL_Q_25:
    li $v0, 1
    lw $a0, PTC_CONST_29_
    syscall
    li $v0, 0xB
    li $a0, 0xA
    syscall
LABEL_Q_26:
    lw $t0, PTC_b_
    lw $t1, PTC_CONST_31_
    slt $t2, $t0, $t1
    beq $t2, 1, LABEL_Q_28
    beq $t0, $t1, LABEL_Q_28
LABEL_Q_27:
    j LABEL_Q_29
LABEL_Q_28:
    li $v0, 1
    lw $a0, PTC_CONST_33_
    syscall
    li $v0, 0xB
    li $a0, 0xA
    syscall
LABEL_Q_29:
    lw $t0, PTC_b_
    lw $t1, PTC_CONST_35_
    bne $t0, $t1, LABEL_Q_31
LABEL_Q_30:
    j LABEL_Q_32
LABEL_Q_31:
    li $v0, 1
    lw $a0, PTC_CONST_37_
    syscall
    li $v0, 0xB
    li $a0, 0xA
    syscall
LABEL_Q_32:
    lw $t0, PTC_CONST_39_
    lw $t1, PTC_CONST_41_
    div $t0, $t1
    mflo $t2
    sw $t2, PTC_TEMP_5_
LABEL_Q_33:
    lw $t0, PTC_TEMP_5_
    sw $t0, PTC_tmp_
LABEL_Q_34:
    li $v0, 1
    lw $a0, PTC_tmp_
    syscall
    li $v0, 0xB
    li $a0, 0xA
    syscall
LABEL_Q_35:
    lw $t0, PTC_CONST_43_
    lw $t1, PTC_CONST_45_
    mult $t0, $t1
    mflo $t2
    sw $t2, PTC_TEMP_7_
LABEL_Q_36:
    lw $t0, PTC_TEMP_7_
    sw $t0, PTC_tmp_
LABEL_Q_37:
    li $v0, 1
    lw $a0, PTC_tmp_
    syscall
    li $v0, 0xB
    li $a0, 0xA
    syscall
LABEL_Q_38:
    lw $t0, PTC_CONST_47_
    lw $t1, PTC_CONST_49_
    add $t2, $t0, $t1
    sw $t2, PTC_TEMP_9_
LABEL_Q_39:
    lw $t0, PTC_TEMP_9_
    sw $t0, PTC_tmp_
LABEL_Q_40:
    li $v0, 1
    lw $a0, PTC_tmp_
    syscall
    li $v0, 0xB
    li $a0, 0xA
    syscall
LABEL_Q_41:
    lw $t0, PTC_CONST_51_
    lw $t1, PTC_CONST_53_
    sub $t2, $t0, $t1
    sw $t2, PTC_TEMP_11_
LABEL_Q_42:
    lw $t0, PTC_TEMP_11_
    sw $t0, PTC_tmp_
LABEL_Q_43:
    li $v0, 1
    lw $a0, PTC_tmp_
    syscall
    li $v0, 0xB
    li $a0, 0xA
    syscall
LABEL_END:
    li $v0, 10
    syscall
