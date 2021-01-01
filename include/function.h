#ifndef FUNCTION_H
#define FUNCTION_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "token_tab.h"

typedef struct typelist //structure for a lsit of arguments
{
	int type; 					//type of argument
	char *name;					//name of argument when declared
	struct typelist* next;		//next argument
} typelist ;

/*
* initialize a typelist with a name and a type
*/
typelist* create_typelist(char *id, char *type);

/*
* concat 2 arglist
*/
typelist* add_to_typelist(typelist *l1, typelist *l2);

/*
* compare 2 arglist, returns an error when different
*/
void cmp_typelist(typelist *l1, typelist *l2);

void print_par(typelist *l);

/*
* returns a typelist for a function id
*/
typelist* get_typelist(char *id);

/*
* checks if a function id exists in the symb_tab
* returns an error when not found
*/
void chk_symb_fct(char *id);

/*
* add the typelist to the function id P_symb in the symb_tab
*/
void add_typelist_to_symb(char *id, typelist* arg);

/*
* does a gencode for the parameters of function
* returns the number of param
*/
int gencode_param(typelist* arg);












#endif
