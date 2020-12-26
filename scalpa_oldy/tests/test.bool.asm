.data
PTC_a_:	.word 0
PTC_b_:	.word 0
PTC_CONST_1_:	.word 5
PTC_CONST_3_:	.word 5
PTC_CONST_5_:	.word 5
PTC_CONST_7_:	.word 1
PTC_TEMP_1_:	.word 0
PTC_CONST_9_:	.word 6
PTC_CONST_11_:	.word 4
PTC_CONST_13_:	.word 4
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
    lw $t1, PTC_CONST_7_
    add $t2, $t0, $t1
    sw $t2, PTC_TEMP_1_
LABEL_Q_4:
    lw $t0, PTC_TEMP_1_
    sw $t0, PTC_a_
LABEL_Q_5:
    lw $t0, PTC_CONST_9_
    sw $t0, PTC_b_
LABEL_Q_6:
    lw $t0, PTC_b_
    lw $t1, PTC_CONST_11_
    beq $t0, $t1, LABEL_Q_8
LABEL_Q_7:
    j LABEL_END
LABEL_Q_8:
    lw $t0, PTC_CONST_13_
    sw $t0, PTC_b_
LABEL_END:
    li $v0, 10
    syscall
