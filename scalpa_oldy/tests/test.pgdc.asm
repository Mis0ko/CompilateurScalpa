.data
PTC_CONST_1_:	.word 600
PTC_a_:	.word 0
PTC_CONST_3_:	.word 888
PTC_b_:	.word 0
PTC_i_:	.word 0
PTC_gdc_:	.word 0
PTC_CONST_5_:	.word 1
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
    sw $t0, PTC_i_
LABEL_Q_3:
    lw $t0, PTC_i_
    lw $t1, PTC_a_
    slt $t2, $t0, $t1
    beq $t2, 1, LABEL_Q_5
LABEL_Q_4:
    j LABEL_END
LABEL_Q_5:
    j LABEL_END
LABEL_Q_6:
    j LABEL_END
LABEL_END:
    li $v0, 10
    syscall
