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
VAR_t2_:	.word	0
VAR_max_:	.word	0

STR_1:	.asciiz	 "\n" 
STR_2:	.asciiz	 "\n" 
STR_3:	.asciiz	 "\n" 
STR_4:	.asciiz	 "\n" 


.text
# In the section .text we put our executable code 

LABEL_0:
		j LABEL_1

LABEL_1:
		li $t1, 22
		sw $t1, VAR_j_

LABEL_2:
		lw $t0, VAR_j_
		li $t1, 18
		add $t2, $t0, $t1
		sw $t2, VAR_t0_

LABEL_3:
		lw $t1, VAR_t0_
		sw $t1, VAR_i_

LABEL_4:
		lw $a0, VAR_i_
		li $v0, 1
		syscall

LABEL_5:
		la $a0, STR_1
		li $v0, 4
		syscall

LABEL_6:
		lw $a0, VAR_i_
		li $v0, 1
		syscall

LABEL_7:
		la $a0, STR_2
		li $v0, 4
		syscall

LABEL_8:
		lw $t0, VAR_j_
		li $t1, 4
		mult $t0, $t1
		mflo $t2
		sw $t2, VAR_t1_

LABEL_9:
		lw $t1, VAR_t1_
		sw $t1, VAR_i_

LABEL_10:
		lw $a0, VAR_i_
		li $v0, 1
		syscall

LABEL_11:
		la $a0, STR_3
		li $v0, 4
		syscall

LABEL_12:
		lw $t0, VAR_max_
		li $t1, 1
		add $t2, $t0, $t1
		sw $t2, VAR_t2_

LABEL_13:
		lw $t1, VAR_t2_
		sw $t1, VAR_i_

LABEL_14:
		lw $a0, VAR_i_
		li $v0, 1
		syscall

LABEL_15:
		la $a0, STR_4
		li $v0, 4
		syscall

LABEL_END:
		li $v0, 10
		syscall
