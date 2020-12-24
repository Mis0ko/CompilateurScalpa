#ifndef QUAD_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct quadop{
	enum { QO_CST, QO_NAME } type;
	union { int cst; char *name ; } u;
} quadop ;

typedef enum quad_type { Q_PLUS, Q_TIMES, Q_MINUS, Q_DIVIDE, Q_NEG, Q_POWER,
	Q_AFFECT, Q_SUP, Q_SUPEQ, Q_INF, Q_INFEQ, Q_DIFF, Q_EQ, Q_OR, Q_AND,
	Q_XOR, Q_NOT,Q_GOTO, Q_RET} quad_type ;

typedef struct quad {
	enum quad_type type;
	quadop* op1, *op2, *res;
} quad;

typedef struct lpos {
	int position;
	struct lpos* suivant;
} lpos;

quadop* quadop_cst(int val);
quadop* quadop_name(char *str);
quad quad_make(quad_type t, quadop* o1, quadop* o2, quadop* r);
void gencode(quad q);
quadop *new_temp();
void affiche(quad q);
lpos* crelist(int position);
void complete(lpos* liste, int cible);
lpos* concat(lpos* l1, lpos* l2);



#endif
