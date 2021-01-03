#	SCALPA Project
#	Output test code in MIPS
#	



.data
# In the section .data we establish data components such as 
# variables or strings to be displayed on the console. 

VAR_i_:	.word	0
VAR_j_:	.word	0
TAB_tableau_:
				.word	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0
				.word	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0
				.word	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0
				.word	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0
				.word	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0
				.word	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0
				.word	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0
				.word	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0
				.word	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0
				.word	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0
				.word	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0
				.word	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0
				.word	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0
STR_1:	.asciiz	 "hello" 
STR_2:	.asciiz	 "stfw" 


.text
# In the section .text we put our executable code 

LABEL_0:
		j LABEL_1

LABEL_1:
		li $t1, 2
		sw $t1, VAR_i_

LABEL_2:
		li $t1, 4
		sw $t1, VAR_j_

LABEL_3:
		la $a0, STR_1
		li $v0, 4
		syscall

LABEL_4:
		li $s5, 16
		ld $s6, VAR_i_
		mul  $t0, $s5, $s6
		ld $s7, VAR_j_
		add  $t0, $t0, $s7 
		mul  $t0, $t0, 4
		la   $s1, TAB_tableau_
		add  $t0, $t0, $s1
		lw $a0, 0($t0)
		li $v0, 1
		syscall

LABEL_5:
		li $v0, 5
		syscall
		move $t0, $v0
		li $s5, 16
		ld $s6, VAR_i_
		mul  $t1, $s5, $s6
		li $s7, 4
		add  $t1, $t1, $s7 
		mul  $t1, $t1, 4
		la   $s1, TAB_tableau_
		add  $t1, $t1, $s1
		sw $t0, 0($t1)

LABEL_6:
		la $a0, STR_2
		li $v0, 4
		syscall

LABEL_7:
		li $s5, 16
		li $s6, 2
		mul  $t0, $s5, $s6
		ld $s7, VAR_j_
		add  $t0, $t0, $s7 
		mul  $t0, $t0, 4
		la   $s1, TAB_tableau_
		add  $t0, $t0, $s1
		lw $a0, 0($t0)
		li $v0, 1
		syscall

LABEL_END:
		li $v0, 10
		syscall
