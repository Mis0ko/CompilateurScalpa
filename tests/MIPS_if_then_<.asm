#	SCALPA Project
#	Output test code in MIPS
#	



.data
# In the section .data we establish data components such as 
# variables or strings to be displayed on the console. 

VAR_i_:	.word	0
VAR_j_:	.word	0
VAR_max_:	.word	0



.text
# In the section .text we put our executable code 

LABEL_0:
		j LABEL_1

LABEL_1:
		li $t1, 1
		sw $t1, VAR_i_

LABEL_2:
		li $t1, 2
		sw $t1, VAR_j_

LABEL_3:
		lw $t0, VAR_i_
		lw $t1, VAR_j_
		blt $t0, $t1, LABEL_5

LABEL_4:
		j LABEL_6

LABEL_5:
		lw $t1, VAR_j_
		sw $t1, VAR_max_

LABEL_6:
		lw $a0, VAR_max_
		li $v0, 1
		syscall

LABEL_END:
		li $v0, 10
		syscall
