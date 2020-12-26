.data
PTC_CONST_1_:	.word 5
PTC_a_:	.word 0
PTC_CONST_3_:	.word 1
PTC_TEMP_1_:	.word 0
.text
main:
LABEL_Q_0:
    lw $t0, PTC_CONST_1_
    sw $t0, PTC_a_
LABEL_Q_1:
    lw $t0, PTC_a_
    lw $t1, PTC_CONST_3_
    add $t2, $t0, $t1
    sw $t2, PTC_TEMP_1_
LABEL_Q_2:
    lw $t0, PTC_TEMP_1_
    sw $t0, PTC_a_
LABEL_END:
    li $v0, 10
    syscall
