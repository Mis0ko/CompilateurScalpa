#	SCALPA Project
#	Output test code in MIPS
#	



.data
# In the section .data we establish data components such as 
# variables or strings to be displayed on the console. 

VAR_i_:	.word	0
VAR_j_:	.word	0
TAB_tableau_:
				.word	0	0	0	0	0	0	0



.text
# In the section .text we put our executable code 

LABEL_0:
		j LABEL_1

LABEL_1:
		li  $t0, 0
		li $s7, 0
		add  $t0, $t0, $s7 
		mul  $t0, $t0, 4
		la   $s1, TAB_tableau_
		addi  $s1, $s1, 12
		add  $t0, $t0, $s1
		lw $a0, 0($t0)
		li $v0, 1
		syscall

LABEL_END:
		li $v0, 10
		syscall
