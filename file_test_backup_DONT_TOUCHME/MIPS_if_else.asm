#	SCALPA Project
#	Output test code in MIPS
#	



.data
# In the section .data we establish data components such as 
# variables or strings to be displayed on the console. 


VAR_max_:  .word  0
STR_1:	.asciiz	 "success" 
STR_2:	.asciiz	 "fail" 

.text
# In the section .text we put our executable code 

LABEL_0:
		li $t0, 5
		li $t1, 6
		bge $t1, $t2, LABEL_2

LABEL_1:
		j LABEL_4

LABEL_2:
		li $t0, 1
		sw $t0, VAR_max_

LABEL_3:
		j LABEL_6

LABEL_4:
		li $t0, 0
		sw $t0, VAR_max_

LABEL_5:
		j LABEL_6

LABEL_6:
		lw $a0, VAR_max_
		li $v0, 1
		syscall

LABEL_7:
		li $t0, 5
		li $t1, 6
		bge $t1, $t2, LABEL_9

LABEL_8:
		j LABEL_11

LABEL_9:
		la $a0, STR_1
		li $v0, 4
		syscall

LABEL_10:
		j LABEL_END

LABEL_11:
		la $a0, STR_2
		li $v0, 4
		syscall

LABEL_12:
		j LABEL_END

LABEL_END:
		li $v0, 10
		syscall
