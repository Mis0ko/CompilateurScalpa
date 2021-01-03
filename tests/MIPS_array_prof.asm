#	SCALPA Project
#	Output test code in MIPS
#	



.data
# In the section .data we establish data components such as 
# variables or strings to be displayed on the console. 

VAR_i_:	.word	0
VAR_j_:	.word	0



.text
# In the section .text we put our executable code 

LABEL_END:
		li $v0, 10
		syscall
