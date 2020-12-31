#	SCALPA Project
#	Output test code in MIPS
#	



.data
# In the section .data we establish data components such as 
# variables or strings to be displayed on the console. 

STR_1:	.asciiz	 "Hello \n" 
VAR_a_:  .word  0
VAR_t0_:  .word  0


.text
# In the section .text we put our executable code 

LABEL_0:
		lw $t0, VAR_a_
		li $t1, 3
		bge $t1, $t2, LABEL_2

LABEL_1:
		j LABEL_6

LABEL_2:
		lw $t0, VAR_a_
		li $t1, 1
		add $t2, $t0, $t1
		sw $t2, VAR_t0_

LABEL_3:
		lw $t0, VAR_t0_
		sw $t0, VAR_a_

LABEL_4:
		la $a0, STR_1
		li $v0, 4
		syscall

LABEL_5:
		j LABEL_0

LABEL_6:
		li $t0, 9
		sw $t0, VAR_a_

LABEL_7:
		lw $a0, VAR_a_
		li $v0, 1
		syscall

LABEL_END:
		li $v0, 10
		syscall
