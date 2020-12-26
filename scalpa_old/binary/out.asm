.data
SYM_a_:	.word 0
SYM_CONST_1_:	.word 51
.text
main:
GOTO_0:
    lw $t0, SYM_CONST_1_
    sw $t0, SYM_a_
GOTO_END:
    li $v0, 10
    syscall
