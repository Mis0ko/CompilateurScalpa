.data
STR_1: .asciiz	 "Hello World" 

.text
main:

LABEL_0:
		lw $a0 STR_1
		li $v0, 4
		syscall
		li $v0, 1
		syscall

LABEL_END:
		li $v0, 10
		syscall
