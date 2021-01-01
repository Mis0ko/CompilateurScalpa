#	SCALPA Project
#	Output test code in MIPS
#	



.data
# In the section .data we establish data components such as 
# variables or strings to be displayed on the console. 

VAR_i_: .word 0
VAR_j_: .word 0
STR_1:	.asciiz	 "\n" 
STR_2:	.asciiz	 "\n" 
STR_3:	.asciiz	 "\n" 
STR_4:	.asciiz	 "\n"

.text
# In the section .text we put our executable code 

.text
# In the section .text we put our executable code 

LABEL_0:
		li $t0, 53
		sw $t0, VAR_i_

LABEL_1:
		lw $a0, VAR_i_
		li $v0, 1
		syscall

LABEL_2:
		la $a0, STR_1
		li $v0, 4
		syscall

LABEL_3:
		lw $t0, VAR_i_
		sw $t0, VAR_j_

LABEL_4:
		lw $a0, VAR_j_
		li $v0, 1
		syscall

LABEL_5:
		la $a0, STR_2
		li $v0, 4
		syscall

LABEL_6:
		li $t0, 3
		sw $t0, VAR_j_

LABEL_7:
		lw $a0, VAR_j_
		li $v0, 1
		syscall

LABEL_8:
		la $a0, STR_3
		li $v0, 4
		syscall

LABEL_9:
		lw $a0, VAR_i_
		li $v0, 1
		syscall

LABEL_10:
		la $a0, STR_4
		li $v0, 4
		syscall

LABEL_END:
		li $v0, 10
		syscall
