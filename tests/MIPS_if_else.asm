#	SCALPA Project
#	Output test code in MIPS
#	



.data
# In the section .data we establish data components such as 
# variables or strings to be displayed on the console. 

VAR_max_:	.word	0

STR_1:	.asciiz	 "success" 
STR_2:	.asciiz	 "fail" 


.text
# In the section .text we put our executable code 

LABEL_0:
		j LABEL_1

LABEL_1:
		li $t0, 5
		li $t1, 6
		blt $t0, $t1, LABEL_3

LABEL_2:
		j LABEL_5

LABEL_3:
		li $t1, 1
		sw $t1, VAR_max_

LABEL_4:
		j LABEL_7

LABEL_5:
		li $t1, 0
		sw $t1, VAR_max_

LABEL_6:
		j LABEL_7

LABEL_7:
		lw $a0, VAR_max_
		li $v0, 1
		syscall

LABEL_8:
		li $t0, 5
		li $t1, 6
		blt $t0, $t1, LABEL_10

LABEL_9:
		j LABEL_12

LABEL_10:
		la $a0, STR_1
		li $v0, 4
		syscall

LABEL_11:
		j LABEL_END

LABEL_12:
		la $a0, STR_2
		li $v0, 4
		syscall

LABEL_13:
		j LABEL_END

LABEL_END:
		li $v0, 10
		syscall
