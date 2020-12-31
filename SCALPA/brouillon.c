		case Q_INFEQ:
			// Loading in register depending on type
			if (q.op1->type == QO_CST)
				fprintf(os, "\tli $t0, %d\n", q.op1->u.cst);
			else
				fprintf(os, "\tlw $t0, VAR_%s_\n", q.op1->u.name);
			if (q.op2->type == QO_CST)
				fprintf(os, "\tli $t1, %d\n", q.op2->u.cst);
			else
				fprintf(os, "\tlw $t1, VAR_%s_\n", q.op2->u.name);

			// Branch in case it's not infeq= greater => bgt
			fprintf(os, "\tbgt $t1, $t2, LABEL_Q_%d\n", q.res->u.cst);
			break;
		case Q_INF:
			// Loading in register depending on type
			if (q.op1->type == QO_CST)
				fprintf(os, "\tli $t0, %d\n", q.op1->u.cst);
			else
				fprintf(os, "\tlw $t0, VAR_%s_\n", q.op1->u.name);
			if (q.op2->type == QO_CST)
				fprintf(os, "\tli $t1, %d\n", q.op2->u.cst);
			else
				fprintf(os, "\tlw $t1, VAR_%s_\n", q.op2->u.name);

			// Branch in case it's not inf= greater or eq=> bge
			fprintf(os, "\tbge $t1, $t2, LABEL_Q_%d\n", q.res->u.cst);
			break;		
		case Q_SUPEQ:
			// Loading in register depending on type
			if (q.op1->type == QO_CST)
				fprintf(os, "\tli $t0, %d\n", q.op1->u.cst);
			else
				fprintf(os, "\tlw $t0, VAR_%s_\n", q.op1->u.name);
			if (q.op2->type == QO_CST)
				fprintf(os, "\tli $t1, %d\n", q.op2->u.cst);
			else
				fprintf(os, "\tlw $t1, VAR_%s_\n", q.op2->u.name);

			// Branch in case it's not supeq = less => blt
			fprintf(os, "\tblt $t1, $t2, LABEL_Q_%d\n", q.res->u.cst);
		case Q_SUP:
			// Loading in register depending on type
			if (q.op1->type == QO_CST)
				fprintf(os, "\tli $t0, %d\n", q.op1->u.cst);
			else
				fprintf(os, "\tlw $t0, VAR_%s_\n", q.op1->u.name);
			if (q.op2->type == QO_CST)
				fprintf(os, "\tli $t1, %d\n", q.op2->u.cst);
			else
				fprintf(os, "\tlw $t1, VAR_%s_\n", q.op2->u.name);

			// Branch in case it's not sup = less or eq => ble
			fprintf(os, "\tble $t1, $t2, LABEL_Q_%d\n", q.res->u.cst);
			break;		


					case Q_PLUS:
			// Loading in register depending on type
			if (q.op1->type == QO_CST)
				fprintf(os, "\tli $t0, %d\n", q.op1->u.cst);
			else
				fprintf(os, "\tlw $t0, VAR_%s_\n", q.op1->u.name);
			if (q.op2->type == QO_CST)
				fprintf(os, "\tli $t1, %d\n", q.op2->u.cst);
			else
				fprintf(os, "\tlw $t1, VAR_%s_\n", q.op2->u.name);
			// Addition operation
			fprintf(os, "\tadd $t2, $t0, $t1\n");
			// Storing the result
			fprintf(os, "\tsw $t2, VAR_%s_\n", q.res->u.name);
			break;
		case Q_MINUS:
			// Loading in register depending on type
			if (q.op1->type == QO_CST)
				fprintf(os, "\tli $t0, %d\n", q.op1->u.cst);
			else
				fprintf(os, "\tlw $t0, VAR_%s_\n", q.op1->u.name);
			if (q.op2->type == QO_CST)
				fprintf(os, "\tli $t1, %d\n", q.op2->u.cst);
			else
				fprintf(os, "\tlw $t1, VAR_%s_\n", q.op2->u.name);
			// Substraction operation
			fprintf(os, "\tsub $t2, $t0, $t1\n");
			// Storing the result
			fprintf(os, "\tsw $t2, VAR_%s_\n", q.res->u.name);
			break;
		case Q_DIVIDE:
			// Loading in register depending on type
			if (q.op1->type == QO_CST)
				fprintf(os, "\tli $t0, %d\n", q.op1->u.cst);
			else
				fprintf(os, "\tlw $t0, VAR_%s_\n", q.op1->u.name);
			if (q.op2->type == QO_CST)
				fprintf(os, "\tli $t1, %d\n", q.op2->u.cst);
			else
				fprintf(os, "\tlw $t1, VAR_%s_\n", q.op2->u.name);
			// Signed Division operation
			fprintf(os, "\tdiv $t0, $t1\n");
			// 32 most significant bits of multiplication to $t2
			fprintf(os, "\tmflo $t2\n");
			// Storing the result
			fprintf(os, "\tsw $t2, VAR_%s_\n", q.res->u.name);
			break;
		case Q_TIMES:
			// Loading in register depending on type
			if (q.op1->type == QO_CST)
				fprintf(os, "\tli $t0, %d\n", q.op1->u.cst);
			else
				fprintf(os, "\tlw $t0, VAR_%s_\n", q.op1->u.name);
			if (q.op2->type == QO_CST)
				fprintf(os, "\tli $t1, %d\n", q.op2->u.cst);
			else
				fprintf(os, "\tlw $t1, VAR_%s_\n", q.op2->u.name);
			// Signed Multioperation
			fprintf(os, "	 mult $t0, $t1\n");
			// 32 most significant bits of multiplication to $t2
			fprintf(os, "\tmflo $t2\n");
			// Storing the result
			fprintf(os, "\tsw $t2, VAR_%s_\n", q.res->u.name);
			break;	
			