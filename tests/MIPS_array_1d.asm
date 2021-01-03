#	SCALPA Project
#	Output test code in MIPS
#	



.data
# In the section .data we establish data components such as 
# variables or strings to be displayed on the console. 

VAR_i_:	.word	0
VAR_j_:	.word	0
TAB_tableau_:
				.word	0	0	0	0	0	0	0	0	0

STR_1:	.asciiz	 "\n" 
STR_2:	.asciiz	 "\n" 


.text
# In the section .text we put our executable code 

LABEL_0:
		j LABEL_1

LABEL_1:
		li $t1, 2
		sw $t1, VAR_i_

LABEL_2:
		li $v0, 5
		syscall
		move $t0, $v0
		li  $t1, 0
		li $s7, 2
		add  $t1, $t1, $s7 
		mul  $t1, $t1, 4
		la   $s1, TAB_tableau_
		addi  $s1, $s1, 20
		add  $t1, $t1, $s1
		sw $t0, 0($t1)

LABEL_3:
		li  $t0, 0
		ld $s7, VAR_i_
		add  $t0, $t0, $s7 
		mul  $t0, $t0, 4
		la   $s1, TAB_tableau_
		addi  $s1, $s1, 20
		add  $t0, $t0, $s1
		lw $a0, 0($t0)
		li $v0, 1
		syscall

LABEL_4:
		la $a0, STR_1
		li $v0, 4
		syscall

LABEL_5:
		li $v0, 5
		syscall
		move $t0, $v0
		li  $t1, 0
		li $s7, -3
		add  $t1, $t1, $s7 
		mul  $t1, $t1, 4
		la   $s1, TAB_tableau_
		addi  $s1, $s1, 20
		add  $t1, $t1, $s1
		sw $t0, 0($t1)

LABEL_6:
		li  $t0, 0
		li $s7, -3
		add  $t0, $t0, $s7 
		mul  $t0, $t0, 4
		la   $s1, TAB_tableau_
		addi  $s1, $s1, 20
		add  $t0, $t0, $s1
		lw $a0, 0($t0)
		li $v0, 1
		syscall

LABEL_7:
		la $a0, STR_2
		li $v0, 4
		syscall

LABEL_8:
		li $v0, 5
		syscall
		move $t0, $v0
		li  $t1, 0
		li $s7, 3
		add  $t1, $t1, $s7 
		mul  $t1, $t1, 4
		la   $s1, TAB_tableau_
		addi  $s1, $s1, 20
		add  $t1, $t1, $s1
		sw $t0, 0($t1)

LABEL_9:
		li  $t0, 0
		li $s7, 3
		add  $t0, $t0, $s7 
		mul  $t0, $t0, 4
		la   $s1, TAB_tableau_
		addi  $s1, $s1, 20
		add  $t0, $t0, $s1
		lw $a0, 0($t0)
		li $v0, 1
		syscall

LABEL_END:
		li $v0, 10
		syscall
