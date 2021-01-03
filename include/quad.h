#ifndef QUAD_H
#define QUAD_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "array.h"
/*
 * structure of an operand
 */
typedef struct quadop {
	enum { QO_CST, QO_NAME, QO_STR, QO_ARRAY } type;
	union u {
		int cst;
		char* name;
		char* str;
	} u;
	struct array_call* array;
} quadop;

/*
 * different types of operation/instruction
 */
typedef enum quad_type {
	Q_PLUS,
	Q_TIMES,
	Q_MINUS,
	Q_DIVIDE,
	Q_NEG,
	Q_POWER,
	Q_AFFECT,
	Q_RET,
	Q_READ,
	Q_WRITE,
	Q_SUP,
	Q_SUPEQ,
	Q_INF,
	Q_INFEQ,
	Q_DIFF,
	Q_EQ,
	Q_OR,
	Q_AND,
	Q_XOR,
	Q_NOT,
	Q_GOTO,
	Q_FBEGIN,
	Q_FEND,
	Q_PARAM,
	Q_CALL,
	Q_CALL_AFFECT
} quad_type;

typedef struct quad {
	enum quad_type type;
	quadop *op1, *op2, *res;
} quad;

/*
 * attribute next
 */
typedef struct lpos {
	int position;
	struct lpos* suivant;
} lpos;


////// ADDITION
/*
 * allocate an operand type array
 * u.name contains the array element
 * array_call contains info of array
 */
quadop* quadop_array(struct array_call* array_call) ;
/*
 * allocate an operand type number
 * u.cst contains the value
 */
quadop* quadop_cst(int val);

/*
 * allocate an operand type name (i.e an identifier)
 * u.name contains the string
 */
quadop* quadop_name(char* str);

/*
 * allocate an operand type constant string
 * u.name contains the string
 */
quadop* quadop_str(char* str);

/*
 * creates a quadruplet through pointers
 */
quad quad_make(quad_type t, quadop* o1, quadop* o2, quadop* r);

/*
 * appends a quadruplet to the global code which is an array
 * and incrementes nextquad
 */
void gencode(quad q);

/*
 * creates a temporary variable
 */
quadop* new_temp();

/*
 * displays a quadruplet according his type
 */
void affiche(quad q);

/*
 * creates a new list of next
 */
lpos* crelist(int position);

/*
 * fills the missing targets of goto
 */
void complete(lpos* liste, int cible);
lpos* concat(lpos* l1, lpos* l2);

/*
 * gives the value 0 or 1 to the temp t
 * according the value of the condition
 */
quadop* reify(lpos * true, lpos * false);



#endif
