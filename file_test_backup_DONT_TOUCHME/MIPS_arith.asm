#	SCALPA Project
#	Output test code in MIPS
#	



.data
# In the section .data we establish data components such as 
# variables or strings to be displayed on the console. 

STR_1:	.asciiz	 "\n" 
STR_2:	.asciiz	 "\n" 
STR_3:	.asciiz	 "\n" 
STR_4:	.asciiz	 "\n" 
VAR_i_:  .word  0
VAR_j_:  .word  0
VAR_max_:  .word  0
VAR_t0_:  .word  0
VAR_t1_:  .word  0
VAR_t2_:  .word  0
VAR_t3_:  .word  0


.
.text
# In the section .text we put our executable code 

LABEL_0:
		li $t0, 22
		sw $t0, VAR_j_

LABEL_1:
		lw $t0, VAR_j_
		li $t1, 18
		add $t2, $t0, $t1
		sw $t2, VAR_t0_

LABEL_2:
		lw $t0, VAR_t0_
		sw $t0, VAR_i_

LABEL_3:
		lw $a0, VAR_i_
		li $v0, 1
		syscall

LABEL_4:
		la $a0, STR_1
		li $v0, 4
		syscall

LABEL_5:
		lw $t0, VAR_j_
		li $t1, 19
		sub $t2, $t0, $t1
		sw $t2, VAR_t1_

LABEL_6:
		lw $t0, VAR_t1_
		sw $t0, VAR_i_

LABEL_7:
		lw $a0, VAR_i_
		li $v0, 1
		syscall

LABEL_8:
		la $a0, STR_2
		li $v0, 4
		syscall

LABEL_9:
		lw $t0, VAR_j_
		li $t1, 4
		mult $t0, $t1
		mflo $t2
		sw $t2, VAR_t2_

LABEL_10:
		lw $t0, VAR_t2_
		sw $t0, VAR_i_

LABEL_11:
		lw $a0, VAR_i_
		li $v0, 1
		syscall

LABEL_12:
		la $a0, STR_3
		li $v0, 4
		syscall

LABEL_13:
		lw $t0, VAR_max_
		li $t1, 1
		add $t2, $t0, $t1
		sw $t2, VAR_t3_

LABEL_14:
		lw $t0, VAR_t3_
		sw $t0, VAR_i_

LABEL_15:
		lw $a0, VAR_i_
		li $v0, 1
		syscall

LABEL_16:
		la $a0, STR_4
		li $v0, 4
		syscall

LABEL_END:
		li $v0, 10
		syscall
