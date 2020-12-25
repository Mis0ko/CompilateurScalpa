#include "mips.h"

void toMips(symbol st, quad_list qt, FILE* os) {

	// Data segment
	fprintf(os, ".data\n");

	// Print alll symbols in ToS
	while (st != NULL) {
		{
			fprintf(os, "SYM_%s_:\t.word %d\n", st->name, st->value);
		}
		st = st->next;
	}

	fprintf(os, ".text\n");
	fprintf(os, "main:\n");

	while (qt != NULL) {
		fprintf(os, "GOTO_%d:\n", qt->q->id);
		switch (qt->q->type) {
			case QUAD_OP_PLUS:
				// Load t0 with SYM_X0
				fprintf(os, "    lw $t0, SYM_%s_\n", qt->q->left->name);
				// Load t1 with SYM_X1
				fprintf(os, "    lw $t1, SYM_%s_\n", qt->q->right->name);
				// Add t0 and t1 and put the result in t2
				fprintf(os, "    add $t2, $t0, $t1\n");
				// Put the value in t2 in SYM_X2
				fprintf(os, "    sw $t2, SYM_%s_\n", qt->q->res->name);
				break;
			case QUAD_OP_MINUS:
				fprintf(os, "    lw $t0, SYM_%s_\n", qt->q->left->name);
				fprintf(os, "    lw $t1, SYM_%s_\n", qt->q->right->name);
				fprintf(os, "    sub $t2, $t0, $t1\n");
				fprintf(os, "    sw $t2, SYM_%s_\n", qt->q->res->name);
				break;
			case QUAD_OP_MULT:
				fprintf(os, "    lw $t0, SYM_%s_\n", qt->q->left->name);
				fprintf(os, "    lw $t1, SYM_%s_\n", qt->q->right->name);
				fprintf(os, "    mult $t0, $t1\n");
				fprintf(os, "    mflo $t2\n");
				fprintf(os, "    sw $t2, SYM_%s_\n", qt->q->res->name);
				break;
			case QUAD_OP_DIVI:
				fprintf(os, "    lw $t0, SYM_%s_\n", qt->q->left->name);
				fprintf(os, "    lw $t1, SYM_%s_\n", qt->q->right->name);
				fprintf(os, "    div $t0, $t1\n");
				fprintf(os, "    mflo $t2\n");
				fprintf(os, "    sw $t2, SYM_%s_\n", qt->q->res->name);
				break;
			case QUAD_OP_MODULO:
				fprintf(os, "    lw $t0, SYM_%s_\n", qt->q->left->name);
				fprintf(os, "    lw $t1, SYM_%s_\n", qt->q->right->name);
				fprintf(os, "    div $t0, $t1\n");
				fprintf(os, "    mfhi $t2\n");
				fprintf(os, "    sw $t2, SYM_%s_\n", qt->q->res->name);
				break;
			case QUAD_UOP_MINUS:
				fprintf(os, "    li $t0, %d\n", 0);
				fprintf(os, "    lw $t1, SYM_%s_\n", qt->q->right->name);
				fprintf(os, "    sub $t2, $t0, $t1\n");
				fprintf(os, "    sw $t2, SYM_%s_\n", qt->q->res->name);
				break;
			case QUAD_UOP_PLUS:
				fprintf(os, "    li $t0, %d\n", 0);
				fprintf(os, "    lw $t1, SYM_%s_\n", qt->q->right->name);
				fprintf(os, "    add $t2, $t0, $t1\n");
				fprintf(os, "    sw $t2, SYM_%s_\n", qt->q->res->name);
				break;
			case QUAD_PRINTI:
				fprintf(os, "    li $v0, 1\n");
				fprintf(os, "    lw $a0, SYM_%s_\n", qt->q->res->name);
				fprintf(os, "    syscall\n");
				fprintf(os, "    li $v0, 0xB\n");
				fprintf(os, "    li $a0, 0xA\n");
				fprintf(os, "    syscall\n");
				break;
			// AFFECT
			case QUAD_UOP_ASSIGN:
				fprintf(os, "    lw $t0, SYM_%s_\n", qt->q->right->name);
				fprintf(os, "    sw $t0, SYM_%s_\n", qt->q->res->name);
				break;
			// GOTO
			case QUAD_GOTO_IF:
				fprintf(os, "    lw $t0, SYM_%s_\n", qt->q->left->name);
				fprintf(os, "    lw $t1, SYM_%s_\n", qt->q->right->name);
				switch (qt->q->cmp) {
					case QUAD_RELOP_EQ:
						fprintf(os, "    beq $t0, $t1, GOTO_%d\n",
								qt->q->dest->id);
						break;
					case QUAD_RELOP_NEQ:
						fprintf(os, "    bne $t0, $t1, GOTO_%d\n",
								qt->q->dest->id);
						break;
					case QUAD_RELOP_GT:
						fprintf(os, "    slt $t2, $t1, $t0\n");
						fprintf(os, "    beq $t2, 1, GOTO_%d\n",
								qt->q->dest->id);
						break;
					case QUAD_RELOP_GTE:
						fprintf(os, "    slt $t2, $t1, $t0\n");
						fprintf(os, "    beq $t2, 1, GOTO_%d\n",
								qt->q->dest->id);
						fprintf(os, "    beq $t0, $t1, GOTO_%d\n",
								qt->q->dest->id);
						break;
					case QUAD_RELOP_LT:
						fprintf(os, "    slt $t2, $t0, $t1\n");
						fprintf(os, "    beq $t2, 1, GOTO_%d\n",
								qt->q->dest->id);
						break;
					case QUAD_RELOP_LTE:
						fprintf(os, "    slt $t2, $t0, $t1\n");
						fprintf(os, "    beq $t2, 1, GOTO_%d\n",
								qt->q->dest->id);
						fprintf(os, "    beq $t0, $t1, GOTO_%d\n",
								qt->q->dest->id);
						break;
				}
				break;
			case QUAD_GOTO:
				fprintf(os, "    j GOTO_%d\n", qt->q->dest->id);
				break;
			case QUAD_GOTO_END:
				fprintf(os, "    j GOTO_END\n");
				break;
		}

		qt = qt->next;
	}
	// Ready to end & exit
	fprintf(os, "GOTO_END:\n");
	fprintf(os, "    li $v0, 10\n");
	fprintf(os, "    syscall\n");
}
