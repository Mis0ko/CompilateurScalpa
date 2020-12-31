#	SCALPA Project
#	Output test code in MIPS
#	



.data
# In the section .data we establish data components such as 
# variables or strings to be displayed on the console. 


VAR_max_:  .word  0
STR_1:	.asciiz	 "success" 
STR_2:	.asciiz	 "fail" 
STR_3:	.asciiz	 "\nje suis encore ici : bref nextquad marche" 


.text
# In the section .text we put our executable code 

LABEL_0:
		li $t0, 5
		li $t1, 6
		bge $t1, $t2, LABEL_2

LABEL_1:
		j LABEL_6

LABEL_2:
		li $t0, 1
		li $t1, 1
		bne $t1, $t2, LABEL_4

LABEL_3:
		j LABEL_6

LABEL_4:
		li $t0, 1
		sw $t0, VAR_max_

LABEL_5:
		j LABEL_8

LABEL_6:
		li $t0, 0
		sw $t0, VAR_max_

LABEL_7:
		j LABEL_8

LABEL_8:
		lw $a0, VAR_max_
		li $v0, 1
		syscall

LABEL_9:
		li $t0, 5
		li $t1, 6
		bge $t1, $t2, LABEL_11

LABEL_10:
		j LABEL_15

LABEL_11:
		li $t0, 1
		li $t1, 1
		bne $t1, $t2, LABEL_13

LABEL_12:
		j LABEL_15

LABEL_13:
		la $a0, STR_1
		li $v0, 4
		syscall

LABEL_14:
		j LABEL_17

LABEL_15:
		la $a0, STR_2
		li $v0, 4
		syscall

LABEL_16:
		j LABEL_17

LABEL_17:
		la $a0, STR_3
		li $v0, 4
		syscall

LABEL_END:
		li $v0, 10
		syscall
