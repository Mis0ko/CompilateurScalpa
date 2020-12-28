.data
.text
main:

LABEL_Q_1:
    li $t0, 22
    sw $t0, VAR_i_

LABEL_Q_2:
    lw $t0, VAR_j_
    li $t1, 1
    add $t2, $t0, $t1
    sw $t2, VAR_t0_

LABEL_Q_3:
    lw $t0, VAR_t0_
    sw $t0, VAR_i_

LABEL_Q_4:
    lw $t0, VAR_j_
    li $t1, 1
    sub $t2, $t0, $t1
    sw $t2, VAR_t1_

LABEL_Q_5:
    lw $t0, VAR_t1_
    sw $t0, VAR_i_

LABEL_Q_6:
    lw $t0, VAR_j_
    li $t1, 1
	 mult $t0, $t1
    mflo $t2
    sw $t2, VAR_t2_

LABEL_Q_7:
    lw $t0, VAR_t2_
    sw $t0, VAR_i_

LABEL_Q_8:
    lw $t0, VAR_max_
    li $t1, 1
    add $t2, $t0, $t1
    sw $t2, VAR_t3_

LABEL_Q_9:
    lw $t0, VAR_t3_
    sw $t0, VAR_i_

LABEL_Q_10:
    lw $t0, VAR_i_
    li $v0, 5
    syscall
    move $t0, $v0
    sw $t0, VAR_i_

LABEL_Q_11:
    lw $a0, VAR_i_
    li $v0, 1
    syscall

LABEL_END:
    li $v0, 10
    syscall
