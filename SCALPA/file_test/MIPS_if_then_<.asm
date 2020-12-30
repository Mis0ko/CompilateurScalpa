#	SCALPA Project
#	Output test code in MIPS
#	



.data
# In the section .data we establish data components such as 
# variables or strings to be displayed on the console. 

VAR_i_:  .word  0
VAR_j_:  .word  0
VAR_max_:  .word  0

.text
# In the section .text we put our executable code 

.text
# In the section .text we put our executable code 

LABEL_0:
		li $t0, 1
		sw $t0, VAR_i_

LABEL_1:
		li $t0, 2
		sw $t0, VAR_j_

LABEL_2:
		lw $t0, VAR_i_
		lw $t1, VAR_j_
		bge $t1, $t2, LABEL_4

LABEL_3:
		j LABEL_5

LABEL_4:
		lw $t0, VAR_j_
		sw $t0, VAR_max_

LABEL_5:
		lw $a0, VAR_max_
		li $v0, 1
		syscall

LABEL_END:
		li $v0, 10
		syscall
