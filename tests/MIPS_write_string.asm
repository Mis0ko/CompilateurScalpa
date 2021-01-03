#	SCALPA Project
#	Output test code in MIPS
#	



.data
# In the section .data we establish data components such as 
# variables or strings to be displayed on the console. 


STR_1:	.asciiz	 "Hello World\n" 


.text
# In the section .text we put our executable code 

LABEL_0:
		j LABEL_1

LABEL_1:
		la $a0, STR_1
		li $v0, 4
		syscall

LABEL_END:
		li $v0, 10
		syscall
