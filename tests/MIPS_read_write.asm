#	SCALPA Project
#	Output test code in MIPS
#	



.data
# In the section .data we establish data components such as 
# variables or strings to be displayed on the console. 

VAR_i_:	.word	0

STR_1:	.asciiz	 "Enter integer\n" 


.text
# In the section .text we put our executable code 

LABEL_0:
		j LABEL_1

LABEL_1:
		la $a0, STR_1
		li $v0, 4
		syscall

LABEL_2:
		li $v0, 5
		syscall
		move $t0, $v0
		sw $t0, VAR_i_

LABEL_3:
		lw $a0, VAR_i_
		li $v0, 1
		syscall

LABEL_END:
		li $v0, 10
		syscall
