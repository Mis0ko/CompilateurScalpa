.data
PTC_a_:	.word 0
PTC_b_:	.word 0
PTC_c_:	.word 0
PTC_d_:	.word 0
PTC_CONST_1_:	.word 40
PTC_CONST_3_:	.word 10
PTC_CONST_5_:	.word 2
PTC_CONST_7_:	.word 1
PTC_TEMP_1_:	.word 0
PTC_TEMP_3_:	.word 0
PTC_TEMP_5_:	.word 0
PTC_CONST_9_:	.word 3
PTC_TEMP_7_:	.word 0
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
    lw $t0, PTC_b_
    lw $t1, PTC_CONST_7_
    div $t0, $t1
    mflo $t2
    sw $t2, PTC_TEMP_1_
LABEL_Q_4:
    lw $t0, PTC_TEMP_1_
    lw $t1, PTC_c_
    div $t0, $t1
    mflo $t2
    sw $t2, PTC_TEMP_3_
LABEL_Q_5:
    lw $t0, PTC_a_
    lw $t1, PTC_TEMP_3_
    add $t2, $t0, $t1
    sw $t2, PTC_TEMP_5_
LABEL_Q_6:
    lw $t0, PTC_TEMP_5_
    lw $t1, PTC_CONST_9_
    sub $t2, $t0, $t1
    sw $t2, PTC_TEMP_7_
LABEL_Q_7:
    lw $t0, PTC_TEMP_7_
    sw $t0, PTC_d_
LABEL_Q_8:
    li $v0, 1
    lw $a0, PTC_d_
    syscall
    li $v0, 0xB
    li $a0, 0xA
    syscall
LABEL_END:
    li $v0, 10
    syscall
