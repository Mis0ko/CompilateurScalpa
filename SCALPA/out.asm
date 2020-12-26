.data
VAR_i_:	.word 0
VAR_j_:	.word 0
VAR_max_:	.word 0
.text
main:

LABEL_Q_1:
    lw $t0, VAR_j_
    lw $t1, 1
    add $t2, $t0, $t1
    sw $t2, VAR_t0_

LABEL_Q_2:
    lw $t0, VAR_j_
    lw $t1, 1
    sub $t2, $t0, $t1
    sw $t2, VAR_t1_

LABEL_Q_3:
    lw $t0, VAR_j_
    lw $t1, 1
    mult $t0, $t1
    mflo $t2
    sw $t2, VAR_t2_

LABEL_Q_4:
    lw $t0, VAR_max_
    lw $t1, 1
    add $t2, $t0, $t1
    sw $t2, VAR_t3_

LABEL_Q_5:
    lw $t0, VAR_max_
    lw $t1, VAR_i_
    add $t2, $t0, $t1
    sw $t2, VAR_t4_
