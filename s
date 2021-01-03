#	SCALPA Project
#	Output test code in MIPS
#	



.data
# In the section .data we establish data components such as 
# variables or strings to be displayed on the console. 

VAR_i_:	.word	0
VAR_j_:	.word	0
VAR_t0_:	.word	0
VAR_dfd_:	.word	0
VAR_max_:	.word	0
VAR_floata_:	.word	0



.text
# In the section .text we put our executable code 

LABEL_0:
		j LABEL_1

LABEL_1:

LABEL_2:
		lw $t1, VAR_t0_
		sw $t1, VAR_i_

LABEL_3:
		li $t1, 6
		sw $t1, VAR_j_

LABEL_4:
		li $t1, 7
		sw $t1, VAR_max_

LABEL_5:
		li $t0, 5
		li $t1, 6
		blt $t0, $t1, LABEL_7

LABEL_6:
		j LABEL_END

LABEL_7:
		li $t1, 0
		sw $t1, VAR_max_

LABEL_END:
		li $v0, 10
		syscall
