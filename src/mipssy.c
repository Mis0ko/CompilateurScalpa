
#include "../include/mipssy.h"

// quad counter
int quad_compt;
// strings coubter
int number_strings;

void mips_array(FILE *os, int reg, quadop *q)
{
	int number_col;
	if (q->array->head_array->next_indxlist != NULL)
	{
		// CAS 2D
		// number of columns !!!!!!!ARG!!!!!
		number_col = lookfor_dims(q->array->tab_name)->max_dim -
					 lookfor_dims(q->array->tab_name)->min_dim + 1;
		// printf("numb col%d\n",number_col);
		fprintf(os, "\t\tli $s5, %d\n", number_col);

		// i value !!!!!!!ARG!!!!!
		if (q->array->head_array->next_indxlist->type == INDX_CST)
			fprintf(os, "\t\tli $s6, %d\n",
					q->array->head_array->next_indxlist->un.index_int);
		else
			fprintf(os, "\t\tld $s6, VAR_%s_\n",
					q->array->head_array->next_indxlist->un.index_name);
		// #t0 = n*i
		fprintf(os, "\t\tmul  $t%d, $s5, $s6\n", reg);
	}
	else
	{
		// vider t0
		fprintf(os, "\t\tli  $t%d, 0\n", reg);
	}
	// CAS 1D
	// j value  !!!!!!!ARG!!!!!
	if (q->array->head_array->type == INDX_CST)
		fprintf(os, "\t\tli $s7, %d\n", q->array->head_array->un.index_int);
	else
		fprintf(os, "\t\tld $s7, VAR_%s_\n",
				q->array->head_array->un.index_name);

	// #t0 = t0 + j = n*i + j
	fprintf(os, "\t\tadd  $t%d, $t%d, $s7 \n", reg, reg);

	// bytes 4
	fprintf(os, "\t\tmul  $t%d, $t%d, 4\n", reg, reg);

	// load add of matrix !!ARG§!!
	fprintf(os, "\t\tla   $s1, TAB_%s_\n", q->array->tab_name);

	// case dim negative
	if (q->array->head_array->next_indxlist == NULL)
	{
		if (lookfor_dims(q->array->tab_name)->min_dim < 0)
			fprintf(os, "\t\taddi  $s1, $s1, %d\n",
					-lookfor_dims(q->array->tab_name)->min_dim * 4);
	}
	else
	{
		if (lookfor_dims(q->array->tab_name)->min_dim < 0)
			fprintf(os, "\t\taddi  $s1, $s1, %d\n",
					-lookfor_dims(q->array->tab_name)->min_dim * 4);
		if (lookfor_dims(q->array->tab_name)->next->min_dim < 0)
		{
			int offset = -lookfor_dims(q->array->tab_name)->next->min_dim * 4 *
						 number_col;
			fprintf(os, "\t\taddi  $s1, $s1, %d\n", offset);
		}
	}

	//  #t0 = adressematC + t0 =  adressematC + n*i + j
	fprintf(os, "\t\tadd  $t%d, $t%d, $s1\n", reg, reg);
}

void translatemips(quad q, FILE *os)
{
	if (q.type == Q_FBEGIN)
	{
		fprintf(os, "\n%s:\n", q.res->u.name);
	}
	else
	{
		// Label , we assign to each instrcution a specific unique label
		fprintf(os, "\nLABEL_%d:\n", quad_compt);
		quad_compt++;
	}

	if (q.type == Q_DIFF || q.type == Q_EQ || q.type == Q_SUP ||
		q.type == Q_SUPEQ || q.type == Q_INF || q.type == Q_INFEQ ||
		q.type == Q_PLUS || q.type == Q_MINUS || q.type == Q_TIMES ||
		q.type == Q_DIVIDE)
	{
		// Loading in register depending on type
		if (q.op1->type == QO_CST)
			fprintf(os, "\t\tli $t0, %d\n", q.op1->u.cst);
		else if (q.op1->type == QO_NAME)
			// Load a word in case of a var
			fprintf(os, "\t\tlw $t0, VAR_%s_\n", q.op1->u.name);
		else if (q.op1->type == QO_ARRAY)
		{
			mips_array(os, 5, q.op1);
			fprintf(os, "\t\tlw $t0, 0($t5)\n");
		}
		if (q.op2->type == QO_CST)
			fprintf(os, "\t\tli $t1, %d\n", q.op2->u.cst);
		else if (q.op2->type == QO_NAME)
			// Load a word in case of a var
			fprintf(os, "\t\tlw $t1, VAR_%s_\n", q.op2->u.name);
		else if (q.op2->type == QO_ARRAY)
		{
			mips_array(os, 5, q.op2);
			fprintf(os, "\t\tlw $t1, 0($t5)\n");
		}
		switch (q.type)
		{
		case Q_EQ:
			// Branch in case it's not eq => bne
			fprintf(os, "\t\tbeq $t0, $t1, LABEL_%d\n", q.res->u.cst);
			break;
		case Q_DIFF:
			// Branch in case it's equal => beq
			fprintf(os, "\t\tbne $t0, $t1, LABEL_%d\n", q.res->u.cst);
			break;
		case Q_SUP:
			// Branch in case it's not sup = less or eq => ble
			fprintf(os, "\t\tbgt $t0, $t1, LABEL_%d\n", q.res->u.cst);
			break;
		case Q_SUPEQ:
			// Branch in case it's not supeq = less => blt
			fprintf(os, "\t\tbge $t0, $t1, LABEL_%d\n", q.res->u.cst);
			break;
		case Q_INF:
			// Branch in case it's not inf= greater or eq=> bge
			fprintf(os, "\t\tblt $t0, $t1, LABEL_%d\n", q.res->u.cst);
			break;
		case Q_INFEQ:
			// Branch in case it's not infeq= greater => bgt
			fprintf(os, "\t\tble $t0, $t1, LABEL_%d\n", q.res->u.cst);
			break;
		case Q_MINUS:
			// Substraction operation
			fprintf(os, "\t\tsub $t2, $t0, $t1\n");
			// Storing the result
			fprintf(os, "\t\tsw $t2, VAR_%s_\n", q.res->u.name);
			break;
		case Q_PLUS:
			fprintf(os, "\t\tadd $t2, $t0, $t1\n");
			// Storing the result
			fprintf(os, "\t\tsw $t2, VAR_%s_\n", q.res->u.name);
			break;
		case Q_TIMES:
			// Signed Multioperation (the following two instr can be replace
			// by one using "mul" but the memo of the prof doesn't include
			// "mul")
			fprintf(os, "\t\tmult $t0, $t1\n");
			// 32 most significant bits of multiplication to $t2
			fprintf(os, "\t\tmflo $t2\n");
			// Storing the result
			fprintf(os, "\t\tsw $t2, VAR_%s_\n", q.res->u.name);
			break;
		case Q_DIVIDE:
			// Signed Division operation (same)
			fprintf(os, "\t\tdiv $t0, $t1\n");
			// 32 most significant bits of multiplication to $t2
			fprintf(os, "\t\tmflo $t2\n");
			// Storing the result
			fprintf(os, "\t\tsw $t2, VAR_%s_\n", q.res->u.name);
			break;
		default:
			break;
		}
	}
	switch (q.type)
	{
	case Q_GOTO:
		if (q.res->u.cst == -1)
			// Case of incompleted goto
			fprintf(os, "\t\tj LABEL_END\n");
		else
			fprintf(os, "\t\tj LABEL_%d\n", q.res->u.cst);
		break;
	case Q_WRITE:
		if (q.res->type == QO_STR)
		{
			number_strings++;
			fprintf(os, "\t\tla $a0, STR_%d\n",
					number_strings); // TO COMPLETE
			fprintf(os, "\t\tli $v0, 4\n");
			fprintf(os, "\t\tsyscall\n");
			break;
		}
		if (q.res->type == QO_CST)
			// Load integer to print
			fprintf(os, "\t\tli $a0, %d\n", q.res->u.cst);
		else if (q.res->type == QO_NAME)
			// Load variable to print
			fprintf(os, "\t\tlw $a0, VAR_%s_\n", q.res->u.name);
		else if (q.res->type == QO_ARRAY)
		{
			mips_array(os, 0, q.res);
			fprintf(os, "\t\tlw $a0, 0($t0)\n");
		}
		// system call code for print_int
		fprintf(os, "\t\tli $v0, 1\n");
		fprintf(os, "\t\tsyscall\n");
		break;
	case Q_READ:
		// system call code for read_int
		fprintf(os, "\t\tli $v0, 5\n");
		fprintf(os, "\t\tsyscall\n");
		// Moving the integer input to another register (is it necessary?)
		fprintf(os, "\t\tmove $t0, $v0\n");
		// save in var

		if (q.res->type == QO_NAME)
			// Load variable to print
			fprintf(os, "\t\tsw $t0, VAR_%s_\n", q.res->u.name);
		else if (q.res->type == QO_ARRAY)
		{
			mips_array(os, 1, q.res);
			fprintf(os, "\t\tsw $t0, 0($t1)\n");
		}
		break;
	case Q_AFFECT:
		// Loading in register depending on type
		if (q.op1->type == QO_CST)
			// Load Integer in case of a cst
			fprintf(os, "\t\tli $t1, %d\n", q.op1->u.cst);
		else if (q.op1->type == QO_NAME)
			// Load a word in case of a var
			fprintf(os, "\t\tlw $t1, VAR_%s_\n", q.op1->u.name);
		else if (q.op1->type == QO_ARRAY)
		{
			mips_array(os, 0, q.op1);
			fprintf(os, "\t\tlw $t1, 0($t0)\n");
		}

		if (q.res->type == QO_NAME)
			// Storing the value in the register in a variable
			fprintf(os, "\t\tsw $t1, VAR_%s_\n", q.res->u.name);
		else if (q.res->type == QO_ARRAY)
		{
			mips_array(os, 0, q.res);
			fprintf(os, "\t\tsw $t1, 0($t0)\n");
		}

		break;
	case Q_XOR:
		if (q.op1->type == QO_CST)
			// Load Integer in case of a cst
			fprintf(os, "\t\tli $t0, %d\n", q.op1->u.cst);
		else if (q.op1->type == QO_NAME)
			// Load a word in case of a var
			fprintf(os, "\t\tlw $t0, VAR_%s_\n", q.op1->u.name);
		else if (q.op1->type == QO_ARRAY)
		{
			mips_array(os, 5, q.op1);
			fprintf(os, "\t\tlw $t0, 0($t5)\n");
		}
		if (q.op2->type == QO_CST)
			// Load Integer in case of a cst
			fprintf(os, "\t\tli $t1, %d\n", q.op2->u.cst);
		else if (q.op2->type == QO_NAME)
			// Load a word in case of a var
			fprintf(os, "\t\tlw $t1, VAR_%s_\n", q.op2->u.name);
		else if (q.op2->type == QO_ARRAY)
		{
			mips_array(os, 5, q.op2);
			fprintf(os, "\t\tlw $t1, 0($t5)\n");
		}
		// XOR operation
		fprintf(os, "\t\txor $t2, $t0, $t1\n");
		// Storing the result
		fprintf(os, "\t\tsw $t2, VAR_%s_\n", q.res->u.name);
		break;
	case Q_AND:
		if (q.op1->type == QO_CST)
			// Load Integer in case of a cst
			fprintf(os, "\t\tli $t0, %d\n", q.op1->u.cst);
		else if (q.op1->type == QO_NAME)
			// Load a word in case of a var
			fprintf(os, "\t\tlw $t0, VAR_%s_\n", q.op1->u.name);
		else if (q.op1->type == QO_ARRAY)
		{
			mips_array(os, 5, q.op1);
			fprintf(os, "\t\tlw $t0, 0($t5)\n");
		}
		if (q.op2->type == QO_CST)
			// Load Integer in case of a cst
			fprintf(os, "\t\tli $t1, %d\n", q.op2->u.cst);
		else if (q.op2->type == QO_NAME)
			// Load a word in case of a var
			fprintf(os, "\t\tlw $t1, VAR_%s_\n", q.op2->u.name);
		else if (q.op2->type == QO_ARRAY)
		{
			mips_array(os, 5, q.op2);
			fprintf(os, "\t\tlw $t1, 0($t5)\n");
		}
		// AND operation
		fprintf(os, "\t\tand $t2, $t0, $t1\n");
		// Storing the result
		fprintf(os, "\t\tsw $t2, VAR_%s_\n", q.res->u.name);
		break;
	case Q_OR:
		if (q.op1->type == QO_CST)
			// Load Integer in case of a cst
			fprintf(os, "\t\tli $t0, %d\n", q.op1->u.cst);
		else if (q.op1->type == QO_NAME)
			// Load a word in case of a var
			fprintf(os, "\t\tlw $t0, VAR_%s_\n", q.op1->u.name);
		else if (q.op1->type == QO_ARRAY)
		{
			mips_array(os, 5, q.op1);
			fprintf(os, "\t\tlw $t0, 0($t5)\n");
		}
		if (q.op2->type == QO_CST)
			// Load Integer in case of a cst
			fprintf(os, "\t\tli $t1, %d\n", q.op2->u.cst);
		else if (q.op2->type == QO_NAME)
			// Load a word in case of a var
			fprintf(os, "\t\tlw $t1, VAR_%s_\n", q.op2->u.name);
		else if (q.op2->type == QO_ARRAY)
		{
			mips_array(os, 5, q.op2);
			fprintf(os, "\t\tlw $t1, 0($t5)\n");
		}
		// OR operation
		fprintf(os, "\t\tor $t2, $t0, $t1\n");
		// Storing the result
		fprintf(os, "\t\tsw $t2, VAR_%s_\n", q.res->u.name);
		break;
	case Q_NOT:
		// Loading in register depending on type
		if (q.op1->type == QO_CST)
			// Load Integer in case of a cst
			fprintf(os, "\t\tli $t0, %d\n", q.op1->u.cst);
		else if (q.op1->type == QO_NAME)
			// Load a word in case of a var
			fprintf(os, "\t\tlw $t0, VAR_%s_\n", q.op1->u.name);
		else if (q.op1->type == QO_ARRAY)
		{
			mips_array(os, 5, q.op1);
			fprintf(os, "\t\tlw $t0, 0($t5)\n");
		}
		// NOT operation
		fprintf(os, "\t\tnot $t1, $t0\n");
		// Storing the value in the register in a variable
		fprintf(os, "\t\tsw $t1, VAR_%s_\n", q.res->u.name);
		break;
	case Q_RET:
		// return from function call
		//fprintf(os, "\t\tjr $ra");
		break;
	case Q_CALL:
		fprintf(os, "\t\tjal %s", (q.res->u.name));
		break;
	case Q_FEND:
		// rendre le registre param
		fprintf(os, "\t\tjr $ra");
		break;
	default:
		break;
	}
}

void mips_code(quad *globalcode, int nextquad, FILE *os)
{
	// Code info
	fprintf(os, "#\tSCALPA Project\n#\tOutput test code in MIPS\n#\t\n\n\n\n");

	// Data section
	fprintf(os, ".data\n");
	fprintf(os,
			"# In the section .data we establish data components such as \n");
	fprintf(os, "# variables or strings to be displayed on the console. \n\n");

	// Loop on table and show vars
	print_vars(os);
	// ASCIIZ gérer write "string"
	int number_str = 0;
	fprintf(os, "\n");
	for (int i = 0; i < nextquad; i++)
	{
		if (globalcode[i].type == Q_WRITE &&
			globalcode[i].res->type == QO_STR)
		{
			number_str++;
			fprintf(os, "STR_%d:\t.asciiz\t \"%s\" \n", number_str,
					globalcode[i].res->u.str);
		}
	}
	// Text section
	fprintf(os, "\n\n.text\n");
	fprintf(os, "# In the section .text we put our executable code \n");
	// fprintf(os, "main:\n");
	quad_compt = 0;
	for (int i = 0; i < nextquad; i++)
	{
		translatemips(globalcode[i], os);
	}
	fprintf(os, "\nLABEL_END:\n");
	// Exit code
	fprintf(os, "\t\tli $v0, 10\n");
	fprintf(os, "\t\tsyscall\n");
}
