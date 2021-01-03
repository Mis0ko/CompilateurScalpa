#	SCALPA Project
#	Output test code in MIPS
#	



.data
# In the section .data we establish data components such as 
# variables or strings to be displayed on the console. 

VAR_i_:	.word	0
VAR_j_:	.word	0
VAR_max_:	.word	0

STR_1:	.asciiz	 "premier appel de fonction" 
STR_2:	.asciiz	 "\n" 
STR_3:	.asciiz	 "Hello" 
STR_4:	.asciiz	 "programme vraiment terminé" 
STR_5:	.asciiz	 "\n" 
STR_6:	.asciiz	 " World" 
STR_7:	.asciiz	 "\n" 
STR_8:	.asciiz	 "\n" 


.text
# In the section .text we put our executable code 

LABEL_0:
		j LABEL_16

appel_1:

LABEL_1:
		la $a0, STR_1
		li $v0, 4
		syscall

LABEL_2:
		la $a0, STR_2
		li $v0, 4
		syscall

LABEL_3:
		jr $ra
bjr:

LABEL_4:
		la $a0, STR_3
		li $v0, 4
		syscall

LABEL_5:
		jr $ra
fini:

LABEL_6:
		la $a0, STR_4
		li $v0, 4
		syscall

LABEL_7:
		la $a0, STR_5
		li $v0, 4
		syscall

LABEL_8:
		jr $ra
WORLD:

LABEL_9:
		la $a0, STR_6
		li $v0, 4
		syscall

LABEL_10:
		la $a0, STR_7
		li $v0, 4
		syscall

LABEL_11:
		jr $ra
LABEL_12:
		li $t1, 4
		sw $t1, VAR_i_

LABEL_13:
		li $t1, 0
		sw $t1, VAR_j_

LABEL_14:
		lw $a0, VAR_i_
		li $v0, 1
		syscall

LABEL_15:
		lw $a0, VAR_j_
		li $v0, 1
		syscall

LABEL_16:
		la $a0, STR_8
		li $v0, 4
		syscall

LABEL_17:
		jal appel_1
LABEL_18:
		jal bjr
LABEL_19:
		jal WORLD
LABEL_20:
		jal fini
LABEL_END:
		li $v0, 10
		syscall