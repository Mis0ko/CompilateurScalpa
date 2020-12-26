.data
PTC_CONST_1_:	.word 6
PTC_CONST_3_:	.word 2
PTC_TEMP_1_:	.word 0
PTC_a_:	.word 0
PTC_b_:	.word 0
PTC_CONST_5_:	.word 4
PTC_CONST_7_:	.word 6
PTC_CONST_9_:	.word 2
PTC_TEMP_3_:	.word 0
PTC_TEMP_5_:	.word 0
.text
main:
LABEL_Q_0:
    lw $t0, PTC_CONST_1_
    lw $t1, PTC_CONST_3_
    add $t2, $t0, $t1
    sw $t2, PTC_TEMP_1_
LABEL_Q_1:
    lw $t0, PTC_CONST_7_
    lw $t1, PTC_CONST_9_
    add $t2, $t0, $t1
    sw $t2, PTC_TEMP_3_
LABEL_Q_2:
    lw $t0, PTC_CONST_5_
    lw $t1, PTC_TEMP_3_
    mult $t0, $t1
    mflo $t2
    sw $t2, PTC_TEMP_5_
LABEL_Q_3:
    lw $t0, PTC_TEMP_5_
    sw $t0, PTC_a_
LABEL_Q_4:
    lw $t0, PTC_a_
    sw $t0, PTC_b_
LABEL_END:
    li $v0, 10
    syscall
