#include "../include/token_tab.h"

P_symb **symb_tab;

dim_list *lookfor_dims(char *tab_id) {
	for (int i = 0; i < SIZE_HASH_TABLE; i++) {	 // QUEL LES VARS
		if (symb_tab[i] != NULL && symb_tab[i]->type_I == ARRAY) {
			if (strcmp(tab_id, symb_tab[i]->name) == 0) {
				printf("found tab\n");
				return symb_tab[i]->dim;
			}
		}
	}
	return NULL;
}

ident_list *create_symblist_array(char *var, ident_list *list, char *typename,
								  dim_list *dims) {
	ident_list *list_parcour = list;
	while (list_parcour != NULL) {
		create_symb_array(var, typename, list_parcour->name, dims);
		list_parcour = list_parcour->next;
	}
	return list;
}

void create_symb_array(char *var, char *typename, char *id, dim_list *dims) {
	P_symb *symb = malloc(sizeof(P_symb));
	CHK_MALLOC(symb);
	symb->next_doublon = NULL;
	symb->name = malloc(SYMBNAME_SIZE);
	CHK_MALLOC(symb->name);
	sprintf(symb->name, "%s", id);

	// ADDITION
	if (strcmp(var, "var") == 0)
		symb->type_I = VARIABLE;
	else if (strcmp(var, "array") == 0)
		symb->type_I = ARRAY;

	if (strcmp(typename, "int") == 0)
		symb->type_A = T_INT;
	else if (strcmp(typename, "bool") == 0)
		symb->type_A = T_BOOL;
	else if (strcmp(typename, "unit") == 0)
		symb->type_A = T_UNIT;

	symb->idx = hachage(id);
	symb->addr = 0;	  // on verra plus tard
	symb->scope = 0;  // idem
	symb->dim = dims;
	if (!add_symb(symb)) {
		printf(
			"we free the symb \"%s\" created because already exist in the "
			"symbole table\n",
			id);
		free(symb);
	}

	return;
}

void print_words(FILE *os, int i) {
	if (symb_tab[i]->dim->next) {
		int min_col = symb_tab[i]->dim->min_dim;
		int max_col = symb_tab[i]->dim->max_dim;
		int min_row = symb_tab[i]->dim->next->min_dim;
		int max_row = symb_tab[i]->dim->next->max_dim;
		// Rester fidèle à l'exemple
		while (min_row <= max_row) {
			fprintf(os, "\n\t\t\t\t.word");
			min_col = symb_tab[i]->dim->min_dim;
			while (min_col <= max_col) {
				fprintf(os, "\t0");
				min_col++;
			}
			min_row++;
		}
	} else {
		int min_col = symb_tab[i]->dim->min_dim;
		int max_col = symb_tab[i]->dim->max_dim;
		// Rester fidèle à l'exemple
		fprintf(os, "\n\t\t\t\t.word");
		while (min_col <= max_col) {
			fprintf(os, "\t0");
			min_col++;
		}
		fprintf(os, "\n");
	}
}

//************** addition for  mips
/* @brief this function print all variables of the sym_table
 *  in the mips format
 */
void print_vars(FILE *os) {
	for (int i = 0; i < SIZE_HASH_TABLE; i++) {	 // QUEL LES VARS
		if (symb_tab[i] != NULL && symb_tab[i]->type_A == T_INT &&
			symb_tab[i]->type_I == VARIABLE) {
			fprintf(os, "VAR_%s_:\t.word\t0\n", symb_tab[i]->name);
			if (symb_tab[i]->next_doublon != NULL) {
				P_symb *symb_parcour = symb_tab[i]->next_doublon;
				while (symb_parcour != NULL) {
					fprintf(os, "VAR_%s_\t.word\t0\n", symb_tab[i]->name);
					symb_parcour = symb_parcour->next_doublon;
				}
			}
		}
	}
	// Array declaration
	for (int i = 0; i < SIZE_HASH_TABLE; i++) {
		if (symb_tab[i] != NULL && symb_tab[i]->type_I == ARRAY) {
			// fprintf(os, "VAR_%s_:\t.word\t0:%d\n", symb_tab[i]->name,
			// symb_tab[i]->dim->max_dim - symb_tab[i]->dim->min_dim);
			fprintf(os, "TAB_%s_:", symb_tab[i]->name);
			print_words(os, i);
			if (symb_tab[i]->next_doublon != NULL) {
				P_symb *symb_parcour = symb_tab[i]->next_doublon;
				while (symb_parcour != NULL) {
					// fprintf(os, "VAR_%s_\t.word\t0:%d\n",
					// symb_tab[i]->name,symb_tab[i]->dim->max_dim -
					// symb_tab[i]->dim->min_dim);
					fprintf(os, "TAB_%s_:\t.word\n", symb_tab[i]->name);
					print_words(os, i);
					symb_parcour = symb_parcour->next_doublon;
				}
			}
		}
	}
}

/**********************************/

/******************** begining of the functions ********************/

void init_symb_tab() {
	symb_tab = malloc(SIZE_HASH_TABLE * sizeof(P_symb *));
	CHK_MALLOC(symb_tab);
}

ident_list *create_symblist(char *var, ident_list *list, char *typename) {
	ident_list *list_parcour = list;
	while (list_parcour != NULL) {
		create_symb(var, typename, list_parcour->name);
		list_parcour = list_parcour->next;
	}
	return list;
}

int hachage(char *chaine) {
	int i = 0, nombreHache = 0;
	for (i = 0; chaine[i] != '\0'; i++) {
		nombreHache += chaine[i];
	}
	nombreHache %= SIZE_HASH_TABLE;
	return nombreHache;
}

void create_symb(char *var, char *typename, char *id) {
	P_symb *symb = malloc(sizeof(P_symb));
	CHK_MALLOC(symb);
	symb->next_doublon = NULL;
	symb->name = malloc(SYMBNAME_SIZE);
	CHK_MALLOC(symb->name);
	sprintf(symb->name, "%s", id);

	if (strcmp(var, "var") == 0)
		symb->type_I = VARIABLE;
	else if (strcmp(var, "param") == 0)
		symb->type_I = PARAMETER;
	if (strcmp(var, "function") == 0) symb->type_I = FUNCTION;

	if (strcmp(typename, "int") == 0)
		symb->type_A = T_INT;
	else if (strcmp(typename, "bool") == 0)
		symb->type_A = T_BOOL;
	else if (strcmp(typename, "unit") == 0)
		symb->type_A = T_UNIT;

	symb->idx = hachage(id);
	symb->addr = 0;	  // on verra plus tard
	symb->scope = 0;  // idem
	symb->arglist = NULL;
	if (!add_symb(symb)) {
		printf(
			"we free the symb \"%s\" created because already exist in the "
			"symbole table\n",
			id);
		free(symb);
	}

	return;
}

int add_symb(P_symb *symb) {
	int already_in = search_symb(symb);

	if (already_in == -1) {
		if (symb_tab[symb->idx] != NULL) {
			P_symb *symb_parcour = symb_tab[symb->idx];
			while (symb_parcour->next_doublon != NULL) {
				symb_parcour = symb_parcour->next_doublon;
			}
			symb_parcour->next_doublon = symb;
			printf("hash table case wasn't empty, symb %s added\n", symb->name);
		} else {  // hash table case empty, just copy the symb
			symb_tab[symb->idx] = symb;
			printf("hash table case was empty, symb %s added\n", symb->name);
		}
		return 1;
	}
	return 0;  // symb already exist, wasnt added
}

int search_symb(P_symb *symb) {
	P_symb *symb_loop = symb_tab[symb->idx];

	if (symb_loop != NULL) {
		while (symb_loop != NULL) {
			if (same_symb(symb, symb_loop)) {
				printf("symb present\n");
				return 1;
			}
			symb_loop = symb_loop->next_doublon;
		}
	}
	return -1;
}

int search_symb_char(char *id) {
	int pos = hachage(id);

	if (symb_tab[pos] == NULL) return -1;

	P_symb *symb_loop = symb_tab[pos];

	while (symb_loop != NULL) {
		if (!strcmp(symb_loop->name, id)) return 1;
		symb_loop = symb_loop->next_doublon;
	}
	return -1;
}

void chk_symb_declared(char *id) {
	if (search_symb_char(id) == -1)	 // if symb not declared
	{
		printf("error : %s not declared\n", id);
		print_tab();
		exit(1);
	}
	return;
}

int same_symb(P_symb *symb1, P_symb *symb2) {
	if (!strcmp(symb1->name, symb2->name)) {
		if (symb1->type_I == symb2->type_I && symb1->type_A == symb2->type_A)
			return 1;
	}
	return 0;
}

void chk_symb_type(char *id, quadop *op1) {
	int pos = hachage(id);
	P_symb *symb_loop = symb_tab[pos];
	while (strcmp(symb_loop->name, id)) symb_loop = symb_loop->next_doublon;
	if (op1 == NULL &&
		(symb_loop->type_I == VARIABLE || symb_loop->type_I == PARAMETER) &&
		symb_loop->type_A ==
			T_BOOL)	 // if op1 is a condition and id a boolean for affect
		return;
	else if (op1 == NULL) {
		printf("erreur typage de %s\n", id);
		print_tab();
		exit(1);
	}

	if (symb_loop->type_A == T_INT &&
		op1->type == QO_CST)  // if op1 and id are int
		return;

	if (op1->type == QO_NAME)  // if op1 is an identifier
	{
		int pos2 = hachage(op1->u.name);
		P_symb *symb_loop2 = symb_tab[pos2];

		while (strcmp(symb_loop2->name, op1->u.name))
			symb_loop2 = symb_loop2->next_doublon;

		if (symb_loop->type_A == symb_loop2->type_A) {
			return;
		}
	}
	// otherwise
	printf("erreur typage de %s\n", id);
	print_tab();
	exit(1);
}

void chk_symb_typechar(char *id1, char *id2) {
	int pos = hachage(id1);
	P_symb *symb_loop = symb_tab[pos];

	while (strcmp(symb_loop->name, id1)) symb_loop = symb_loop->next_doublon;

	int pos2 = hachage(id2);
	P_symb *symb_loop2 = symb_tab[pos2];

	while (strcmp(symb_loop2->name, id2)) symb_loop2 = symb_loop2->next_doublon;

	if (symb_loop->type_A == symb_loop2->type_A) return;
	// otherwise
	printf("erreur typage de %s %s\n", id1, id2);
	print_tab();
	exit(1);
}

void chk_symb_typeE(quadop *op1, quadop *op2) {
	if (op1->type == QO_STR || op2->type == QO_STR) {
		printf("erreur typage comparaison\n");
		print_tab();
		exit(1);
	} else if (op1->type == QO_CST && op2->type == QO_NAME)
		chk_symb_type(op2->u.name, op1);
	else if (op1->type == QO_NAME && op2->type == QO_CST)
		chk_symb_type(op1->u.name, op2);
	else if (op1->type == QO_NAME && op2->type == QO_NAME)
		chk_symb_typechar(op1->u.name, op2->u.name);

	return;
}

ident_list *create_identlist(char *ident) {
	ident_list *my_list = malloc(sizeof(ident_list));
	my_list->name = malloc(SYMBNAME_SIZE);
	CHK_MALLOC(my_list);
	CHK_MALLOC(my_list->name);
	sprintf(my_list->name, "%s", ident);
	my_list->next = NULL;
	return my_list;
}

ident_list *add_to_identlist(ident_list *old_list, char *ident) {
	ident_list *new_ident = malloc(sizeof(ident_list));
	new_ident->name = malloc(SYMBNAME_SIZE);
	CHK_MALLOC(new_ident);
	CHK_MALLOC(new_ident->name);

	sprintf(new_ident->name, "%s", ident);

	new_ident->next = NULL;

	ident_list *loop_ident = old_list;

	while (loop_ident->next != NULL) loop_ident = loop_ident->next;
	loop_ident->next = new_ident;
	return old_list;
}

char *get_symb_type_A_char(char *id) {
	P_symb *symb = get_symb_char(id);
	if (symb == NULL) return NULL;

	if (symb->type_A == T_INT) return "int";
	if (symb->type_A == T_BOOL) return "bool";
	if (symb->type_A == T_UNIT) return "unit";
}

P_symb *get_symb_char(char *id) {
	int pos = hachage(id);

	if (symb_tab[pos] == NULL) return NULL;

	P_symb *symb_loop = symb_tab[pos];

	while (symb_loop != NULL) {
		if (!strcmp(symb_loop->name, id)) return symb_loop;
		symb_loop = symb_loop->next_doublon;
	}
	return NULL;
}

int get_symb_type_A(char *id) {
	P_symb *symb = get_symb_char(id);
	if (symb == NULL) return -1;
	return symb->type_A;
}

int get_CSTval_symb_ident(char *id) {
	P_symb *my_symb = get_symb_char(id);
	if (my_symb == NULL) return -1;
	if (get_symb_type_A(id) == -1) return -1;
	switch (my_symb->type_A) {
		case T_INT:
			return my_symb->u.int_val;
			break;
		case T_BOOL:
			return my_symb->u.bool_val;
			break;
	}
	printf("value of this symb not known\n");
	return -1;
}

// /***
//  * for now this function is useless, we dont implement char* as variable
//  *get the char* value from a sym that is a string
//  *
//  * ***/
// char* get_charval_symb_ident(char *id)
// {
//     P_symb *my_symb = get_symb_char(id);
//     if (my_symb == NULL)
//         return -1;
//     if (get_symb_type_A(id) == -1)
//         return -1;
//     switch (my_symb->type_A)
//     {
//     case T_STR:
//         return my_symb->u.str_val;
//         break;
//     }
//     printf("value of this symb not known\n");
//     return -1;
// }

void affect_symb(char *ident, quadop *qsymb) {
	int val;
	P_symb *my_symb = get_symb_char(ident);
	// printf("Le symbole normalement %s et sa val %i\n", my_symb->name,
	// my_symb->u.bool_val); printf("\n\n"); print_symb(my_symb);
	// printf("\n\n\n");
	if (my_symb == NULL) {
		bug("affect_symb : NULL");
		return;
	}
	switch (qsymb->type) {
		case QO_CST:
			my_symb->u.int_val = qsymb->u.cst;
			break;
		// met à jour la tab des symboles sur leur valeur, mais pas sur que ça
		// soit ce que l'on veut ....
		case QO_NAME:
			val = get_CSTval_symb_ident(qsymb->u.name);
			quadop *val_quadop = malloc(sizeof(quadop));  //à free après
			CHK_MALLOC(val_quadop);
			val_quadop->type = QO_CST;
			val_quadop->u.cst = val;
			affect_symb(ident, val_quadop);
	}
	return;
}

void affect_opb(quadop *q1, int opb, quadop *q2, quadop *q3) {
	int v1, v2, v3;
	v3 = -1;
	if (q2 == NULL) {
		bug("affect_opb: q2 NULL");
		return;
	}

	if (q2->type == QO_NAME)
		v2 = get_CSTval_symb_ident(q2->u.name);
	else
		v2 = q2->u.cst;

	if (q1 == NULL && q2 != NULL)  // case opb == NEG
	{
		if (opb == Q_NEG) {
			v3 = -v2;
		}
	}

	if (q1->type == QO_NAME)
		v1 = get_CSTval_symb_ident(q1->u.name);
	else
		v1 = q1->u.cst;

	switch (opb) {
		case Q_PLUS:
			v3 = v1 + v2;
			break;

		case Q_TIMES:
			v3 = v1 * v2;
			break;

		case Q_POWER:
			v3 = pow(v1, v2);
			break;

		case Q_MINUS:
			v3 = v1 - v2;
			break;

		case Q_DIVIDE:
			v3 = v1 / v2;
			break;

		default:
			printf("affect_opb : pas compris\n");
			break;
	}

	q3->type = QO_CST;
	q3->u.cst = v3;
	return;
}

/************** pour quand ya un opb ***********************/
void print_intvar_name() {
	for (int i = 0; i < SIZE_HASH_TABLE; i++) {
		if (symb_tab[i] != NULL && symb_tab[i]->type_A == T_INT) {
			printf("%s\n", symb_tab[i]->name);
			if (symb_tab[i]->next_doublon != NULL) {
				P_symb *symb_parcour = symb_tab[i]->next_doublon;
				while (symb_parcour != NULL) {
					printf("%s\n", symb_tab[i]->name);
					symb_parcour = symb_parcour->next_doublon;
				}
			}
		}
	}
}

void print_symb(P_symb *symb) {
	if (strlen(symb->name) >= 8)
		printf("|\t%i\t|\t\t%s\t|", symb->idx, symb->name);
	else
		printf("|\t%i\t|\t\t%s\t\t|", symb->idx, symb->name);

	if (symb->type_I == VARIABLE)
		printf("   var  |");
	else if (symb->type_I == PARAMETER)
		printf("   par  |");
	else if (symb->type_I == FUNCTION)
		printf("   fun  |");
	else if (symb->type_I == ARRAY)
		printf("   arr  |");

	if (symb->type_A == T_INT)
		printf("   int   |");
	else if (symb->type_A == T_BOOL)
		printf("   bool  |");
	else if (symb->type_A == T_UNIT)
		printf("   unit  |");

	printf("\t");
	if (symb->type_I == VARIABLE) switch (symb->type_A) {
			case T_INT:
				printf("  %i ", symb->u.int_val);
				break;
			case T_BOOL:
				printf("  %i ", symb->u.bool_val);
				break;
			default:
				printf("   ");
		}
	printf("\t|\n");
}

void print_tab() {
	printf("|---------------|");
	printf(
		"-------------------------------|--------|---------|------------|\n");
	printf("|\tindex\t|\t\tident\t\t| idtype | rettype |\tvalue\t|\n");
	printf("|---------------|");
	printf(
		"-------------------------------|--------|---------|------------|\n");
	for (int i = 0; i < SIZE_HASH_TABLE; i++) {
		if (symb_tab[i] != NULL) {
			print_symb(symb_tab[i]);
			if (symb_tab[i]->next_doublon != NULL) {
				P_symb *symb_parcour = symb_tab[i]->next_doublon;
				while (symb_parcour != NULL) {
					print_symb(symb_parcour);
					symb_parcour = symb_parcour->next_doublon;
				}
			}
		}
	}
	printf("|---------------|");
	printf(
		"-------------------------------|--------|---------|------------|\n");
}

struct typelist *Free_typelist(struct typelist *list) {
	struct typelist *next;
	if (list != NULL) {
		free(list->name);
		next = list->next;
		free(list);
	}
	return (next);
}

P_symb *Free_symb(P_symb *symb) {
	P_symb *next;
	if (symb != NULL) {
		if (symb->name != NULL) free(symb->name);
		if (symb->arglist != NULL) {
			struct typelist *next = symb->arglist->next;
			while ((next = Free_typelist(next)) != NULL)
				;
			free(symb->arglist);
		}
		next = symb->next_doublon;
		free(symb);
	}
	return next;
}
void free_symbtab() {
	for (int i = 0; i < SIZE_HASH_TABLE; i++) {
		if (symb_tab[i] != NULL) {
			P_symb *next = symb_tab[i]->next_doublon;
			while ((next = Free_symb(next)) != NULL)
				;
			free(symb_tab[i]);
		}
	}
}
