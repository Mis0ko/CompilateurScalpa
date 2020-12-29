.data
STR_1: .asciiz	 "lol" 

.text
main:

LABEL_0:
		li $t0, 5
		sw $t0, VAR_i_

LABEL_1:
		li $t0, 6
		sw $t0, VAR_j_

LABEL_2:
		li $t0, 7
		sw $t0, VAR_max_

LABEL_3:
		lw $a0, VAR_dfd_
		li $v0, 1
		syscall

LABEL_4:
		li $t0, 5
		li $t1, 6
		bge $t1, $t2, LABEL_6

LABEL_5:
		j LABEL_8

LABEL_6:
		li $t0, 0
		sw $t0, VAR_max_

LABEL_7:
		j LABEL_10

LABEL_8:
		li $t0, 1
		sw $t0, VAR_max_

LABEL_9:
		j LABEL_10

LABEL_10:
		lw $t0, VAR_i_
		li $t1, 1
		add $t2, $t0, $t1
		sw $t2, VAR_t0_

LABEL_11:
		lw $t0, VAR_t0_
		sw $t0, VAR_i_

LABEL_12:
		li $t0, 5
		li $t1, 6
		bne $t1, $t2, LABEL_14

LABEL_13:
		j LABEL_16

LABEL_14:
		li $t0, 0
		sw $t0, VAR_max_

LABEL_15:
		j LABEL_18

LABEL_16:
		li $t0, 1
		sw $t0, VAR_max_

LABEL_17:
		j LABEL_18

LABEL_18:
		lw $t0, VAR_i_
		li $t1, 1
		add $t2, $t0, $t1
		sw $t2, VAR_t1_

LABEL_19:
		lw $t0, VAR_t1_
		sw $t0, VAR_i_

LABEL_20:
		lw $a0 STR_1
		li $v0, 4
		syscall

LABEL_21:
		li $t0, 5
		li $t1, 6
		bge $t1, $t2, LABEL_23

LABEL_22:
		j LABEL_27

LABEL_23:
		li $t0, 1
		li $t1, 1
		bne $t1, $t2, LABEL_25

LABEL_24:
		j LABEL_27

LABEL_25:
		li $t0, 0
		sw $t0, VAR_max_

LABEL_26:
		j LABEL_END

LABEL_27:
		li $t0, 1
		sw $t0, VAR_max_

LABEL_28:
		j LABEL_END

LABEL_END:
		li $v0, 10
		syscall
