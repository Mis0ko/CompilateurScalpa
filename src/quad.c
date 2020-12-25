#include "../include/quad.h"


quad globalcode[100];
int nextquad =0;
int ntp=0;

quadop* quadop_cst(int val)
{
	quadop *res = malloc(sizeof(quadop));
	res->type = QO_CST;
	res->u.cst = val;
	return res;
}

quadop* quadop_name(char *str)
{
	quadop *res = malloc(sizeof(quadop));
	res->type = QO_NAME;
	res->u.name = str;
	return res;
}


quad quad_make(quad_type t, quadop* o1, quadop* o2, quadop* r)
{
	quad res;
	res.type = t;
	res.op1 = o1;
	res.op2 = o2;
	res.res = r;
	return res;
}

void gencode(quad q)
{
	globalcode[nextquad] = q;
	nextquad++;
}

quadop *new_temp()
{
	char *nom_temp = malloc(4);
	sprintf(nom_temp,"t%i", ntp);
	quadop* tp = quadop_name(nom_temp);
	ntp++;
	return tp;
}

void affiche(quad q)
{
	switch(q.type)
	{
		case Q_PLUS:
			printf("%s = ", q.res->u.name);
			if (q.op1->type == QO_CST)
				printf("%d + ", q.op1->u.cst);
			else
				printf("%s + ", q.op1->u.name);
			if (q.op2->type == QO_CST)
				printf("%d\n", q.op2->u.cst);
			else
				printf("%s\n", q.op2->u.name);
			break;

		case Q_TIMES:
			printf("%s = ", q.res->u.name);
			if (q.op1->type == QO_CST)
				printf("%d * ", q.op1->u.cst);
			else
				printf("%s * ", q.op1->u.name);
			if (q.op2->type == QO_CST)
				printf("%d\n", q.op2->u.cst);
			else
				printf("%s\n", q.op2->u.name);
			break;

		case Q_POWER:
			printf("%s = ", q.res->u.name);
			if (q.op1->type == QO_CST)
				printf("%d^", q.op1->u.cst);
			else
				printf("%s^", q.op1->u.name);
			if (q.op2->type == QO_CST)
				printf("%d\n", q.op2->u.cst);
			else
				printf("%s\n", q.op2->u.name);
			break;

		case Q_MINUS:
			printf("%s = ", q.res->u.name);
			if (q.op1->type == QO_CST)
				printf("%d - ", q.op1->u.cst);
			else
				printf("%s - ", q.op1->u.name);
			if (q.op2->type == QO_CST)
				printf("%d\n", q.op2->u.cst);
			else
				printf("%s\n", q.op2->u.name);
			break;

		case Q_DIVIDE:
			printf("%s = ", q.res->u.name);
			if (q.op1->type == QO_CST)
				printf("%d / ", q.op1->u.cst);
			else
				printf("%s / ", q.op1->u.name);
			if (q.op2->type == QO_CST)
				printf("%d\n", q.op2->u.cst);
			else
				printf("%s\n", q.op2->u.name);
			break;

		case Q_NEG:
			printf("%s = ", q.res->u.name);
			if (q.op1->type == QO_CST)
				printf("-%d\n", q.op1->u.cst);
			else
				printf("-%s\n", q.op1->u.name);
			break;
		case Q_NOT:
			printf("%s = ", q.res->u.name);
			if (q.op1->type == QO_CST)
				printf("not %d\n", q.op1->u.cst);
			else
				printf("not %s\n", q.op1->u.name);
			break;

		case Q_AFFECT:
			if (q.op1->type == QO_NAME)
				printf("%s = %s\n", q.res->u.name, q.op1->u.name);
			else
				printf("%s = %d\n", q.res->u.name, q.op1->u.cst);
			break;

		case Q_SUP:
			printf("if ");
			if (q.op1->type == QO_CST)
				printf("%d > ", q.op1->u.cst);
			else
				printf("%s > ", q.op1->u.name);
			if (q.op2->type == QO_CST)
				printf("%d ", q.op2->u.cst);
			else
				printf("%s ", q.op2->u.name);
			printf("goto %i\n", q.res->u.cst);
			break;

		case Q_SUPEQ:
			printf("if ");
			if (q.op1->type == QO_CST)
				printf("%d >= ", q.op1->u.cst);
			else
				printf("%s >= ", q.op1->u.name);
			if (q.op2->type == QO_CST)
				printf("%d ", q.op2->u.cst);
			else
				printf("%s ", q.op2->u.name);
			printf("goto %i\n", q.res->u.cst);
			break;

		case Q_INF:
			printf("if ");
			if (q.op1->type == QO_CST)
				printf("%d < ", q.op1->u.cst);
			else
				printf("%s < ", q.op1->u.name);
			if (q.op2->type == QO_CST)
				printf("%d ", q.op2->u.cst);
			else
				printf("%s ", q.op2->u.name);
			printf("goto %i\n", q.res->u.cst);
			break;

		case Q_INFEQ:
			printf("if ");
			if (q.op1->type == QO_CST)
				printf("%d < ", q.op1->u.cst);
			else
				printf("%s < ", q.op1->u.name);
			if (q.op2->type == QO_CST)
				printf("%d ", q.op2->u.cst);
			else
				printf("%s ", q.op2->u.name);
			printf("goto %i\n", q.res->u.cst);
			break;

		case Q_EQ:
			printf("if ");
			if (q.op1->type == QO_CST)
				printf("%d = ", q.op1->u.cst);
			else
				printf("%s = ", q.op1->u.name);
			if (q.op2->type == QO_CST)
				printf("%d ", q.op2->u.cst);
			else
				printf("%s ", q.op2->u.name);
			printf("goto %i\n", q.res->u.cst);
			break;

		case Q_DIFF:
			printf("if ");
			if (q.op1->type == QO_CST)
				printf("%d <> ", q.op1->u.cst);
			else
				printf("%s <> ", q.op1->u.name);
			if (q.op2->type == QO_CST)
				printf("%d ", q.op2->u.cst);
			else
				printf("%s ", q.op2->u.name);
			printf("goto %i\n", q.res->u.cst);
			break;
		case Q_AND:
			printf("if ");
			if (q.op1->type == QO_CST)
				printf("%d and ", q.op1->u.cst);
			else
				printf("%s and ", q.op1->u.name);
			if (q.op2->type == QO_CST)
				printf("%d ", q.op2->u.cst);
			else
				printf("%s ", q.op2->u.name);
			printf("goto %i\n", q.res->u.cst);
			break;
		case Q_OR:
			printf("if ");
			if (q.op1->type == QO_CST)
				printf("%d or ", q.op1->u.cst);
			else
				printf("%s or ", q.op1->u.name);
			if (q.op2->type == QO_CST)
				printf("%d ", q.op2->u.cst);
			else
				printf("%s ", q.op2->u.name);
			printf("goto %i\n", q.res->u.cst);
			break;
		case Q_XOR:
			printf("%s = ", q.res->u.name);
			if (q.op1->type == QO_CST)
				printf("%d xor ", q.op1->u.cst);
			else
				printf("%s xor ", q.op1->u.name);
			if (q.op2->type == QO_CST)
				printf("%d\n", q.op2->u.cst);
			else
				printf("%s\n", q.op2->u.name);
			break;
		case Q_GOTO:
			printf("goto ");
			if (q.res->u.cst != -1)
			 	printf("%i\n", q.res->u.cst);
			else
				printf("?\n");
			break;
		case Q_READ:
			printf("read %s\n", q.res->u.name);
			break;
		case Q_WRITE:
			printf("write ");
			/*if (q.res->type == QO_CST)
				printf("%dbla%i\n", q.res->u.cst, QO_CST);
			else*/
				printf("%s\n", q.res->u.name);
			break;
		case Q_RET:
			printf("ret ");
			if (q.res->type == QO_CST)
				printf("%i\n", q.res->u.cst);
			else
				printf("%s\n", q.res->u.name);
			break;
		default:
			printf("pas compris\n");
	}
}

lpos* crelist(int position) {
	lpos* new = malloc(sizeof(lpos));
	new->position = position;
	new->suivant = NULL;
	return new;
}

lpos* concat(lpos* l1, lpos* l2) {
	lpos* res;
	if (l1 != NULL) res = l1;
	else if (l2 != NULL) res = l2;
	else res = NULL;
	if (l1 != NULL) {
		while (l1->suivant!=NULL)
			l1 = l1->suivant;
	l1->suivant = l2;
	}
	return res;
}

void complete(lpos* liste, int cible) {
	if (liste == NULL)
		return;
	globalcode[liste->position].res = quadop_cst(cible);
	while (liste->suivant != NULL) {
		liste = liste->suivant;
		globalcode[liste->position].res = quadop_cst(cible);
	}
}
