#ifndef FUNCTION_H
#define FUNCTION_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "token_tab.h"

typedef struct typelist
{
	int type;
	char *name;
	struct typelist* next;
} typelist ;


typelist* create_typelist(char *id, char *type);
typelist* add_to_typelist(typelist *l1, typelist *l2);
void cmp_typelist(typelist *l1, typelist *l2);
void print_par(typelist *l);
typelist* get_typelist(char *id);
void chk_symb_fct(char *id);
void add_typelist_to_symb(char *id, typelist* arg);
int gencode_param(typelist* arg);












#endif
