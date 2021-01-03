#	SCALPA Project
#	Output test code in MIPS
#	



.data
# In the section .data we establish data components such as 
# variables or strings to be displayed on the console. 

VAR_i_:	.word	0
VAR_j_:	.word	0
VAR_t0_:	.word	0
VAR_t1_:	.word	0
TAB_tableau_:
				.word	0	0	0	0	0	0	0
				.word	0	0	0	0	0	0	0
				.word	0	0	0	0	0	0	0
				.word	0	0	0	0	0	0	0
				.word	0	0	0	0	0	0	0


.text
# In the section .text we put our executable code 

LABEL_0:
		j LABEL_1

LABEL_1:
		li $v0, 5
		syscall
		move $t0, $v0
		li $s5, 7
		li $s6, 0
		mul  $t1, $s5, $s6
		li $s7, 0
		add  $t1, $t1, $s7 
		mul  $t1, $t1, 4
		la   $s1, TAB_tableau_
		addi  $s1, $s1, 12
		addi  $s1, $s1, 56
		add  $t1, $t1, $s1
		sw $t0, 0($t1)

LABEL_2:
		li $s5, 7
		li $s6, 0
		mul  $t0, $s5, $s6
		li $s7, 0
		add  $t0, $t0, $s7 
		mul  $t0, $t0, 4
		la   $s1, TAB_tableau_
		addi  $s1, $s1, 12
		addi  $s1, $s1, 56
		add  $t0, $t0, $s1
		lw $a0, 0($t0)
		li $v0, 1
		syscall

LABEL_3:
		li $t1, 0
		sw $t1, VAR_i_

LABEL_4:
		li $t1, 0
		sw $t1, VAR_j_

LABEL_5:
		lw $t0, VAR_i_
		li $t1, 2
		ble $t0, $t1, LABEL_7

LABEL_6:
		j LABEL_17

LABEL_7:
		li $t1, 0
		sw $t1, VAR_j_

LABEL_8:
		lw $t0, VAR_j_
		li $t1, 3
		ble $t0, $t1, LABEL_10

LABEL_9:
		j LABEL_14

LABEL_10:
		li $v0, 5
		syscall
		move $t0, $v0
		li $s5, 7
		ld $s6, VAR_i_
		mul  $t1, $s5, $s6
		ld $s7, VAR_j_
		add  $t1, $t1, $s7 
		mul  $t1, $t1, 4
		la   $s1, TAB_tableau_
		addi  $s1, $s1, 12
		addi  $s1, $s1, 56
		add  $t1, $t1, $s1
		sw $t0, 0($t1)

LABEL_11:
		lw $t0, VAR_j_
		li $t1, 1
		add $t2, $t0, $t1
		sw $t2, VAR_t0_

LABEL_12:
		lw $t1, VAR_t0_
		sw $t1, VAR_j_

LABEL_13:
		j LABEL_8

LABEL_14:
		lw $t0, VAR_i_
		li $t1, 1
		add $t2, $t0, $t1
		sw $t2, VAR_t1_

LABEL_15:
		lw $t1, VAR_t1_
		sw $t1, VAR_i_

LABEL_16:
		j LABEL_5

LABEL_17:
		li $s5, 7
		li $s6, 1
		mul  $t0, $s5, $s6
		li $s7, 2
		add  $t0, $t0, $s7 
		mul  $t0, $t0, 4
		la   $s1, TAB_tableau_
		addi  $s1, $s1, 12
		addi  $s1, $s1, 56
		add  $t0, $t0, $s1
		lw $a0, 0($t0)
		li $v0, 1
		syscall

LABEL_END:
		li $v0, 10
		syscall
