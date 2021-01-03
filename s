#	SCALPA Project
#	Output test code in MIPS
#	



.data
# In the section .data we establish data components such as 
# variables or strings to be displayed on the console. 

VAR_a_:	.word	0
VAR_t0_:	.word	0

STR_1:	.asciiz	 "Hello" 


.text
# In the section .text we put our executable code 

LABEL_0:
		j LABEL_1

LABEL_1:
		lw $t0, VAR_a_
		li $t1, 3
		blt $t0, $t1, LABEL_3

LABEL_2:
		j LABEL_7

LABEL_3:
		lw $t0, VAR_a_
		li $t1, 1
		add $t2, $t0, $t1
		sw $t2, VAR_t0_

LABEL_4:
		lw $t1, VAR_t0_
		sw $t1, VAR_a_

LABEL_5:
		la $a0, STR_1
		li $v0, 4
		syscall

LABEL_6:
		j LABEL_1

LABEL_7:
		li $t1, 9
		sw $t1, VAR_a_

LABEL_8:
		lw $a0, VAR_a_
		li $v0, 1
		syscall

LABEL_END:
		li $v0, 10
		syscall
