#include "../include/function.h"
extern struct P_symb** symb_tab;

typelist* create_typelist(char *id, char *type)
{
	typelist *list = malloc(sizeof(typelist));
	CHK_MALLOC(list);

	list->name = strdup(id);

	if (strcmp(type, "int") == 0)
		list->type = T_INT;
	else if (strcmp(type, "bool") == 0)
		list->type = T_BOOL;
	else if (strcmp(type, "unit") == 0)
		list->type = T_UNIT;

	list->next = NULL;
    return list;
}

typelist* add_to_typelist(typelist *l1, typelist *l2)
{
	typelist* res;
	if (l1 != NULL) res = l1;
	else if (l2 != NULL) res = l2;
	else res = NULL;
	if (l1 != NULL) {
		while (l1->next!=NULL)
			l1 = l1->next;
	l1->next = l2;
	}
	return res;
}


void cmp_typelist(typelist *l1, typelist *l2)
{
	typelist *loop1 = l1;
	typelist *loop2 = l2;
	while (loop1 != NULL || loop2 != NULL)
	{
		if (loop1->type != loop2->type)
		{
			printf("mauvais type fonction\n");
			exit(1);
		}
		loop1 = loop1->next;
		loop2 = loop2->next;
	}

	return;
}

void print_par(typelist *l)
{
	typelist *loop = l;
	printf("param : ");
	while (loop != NULL)
	{
		switch (loop->type) {
			case 0:
				printf("int\n");
				break;
			case 1:
				printf("unit\n" );
				break;
			case 2:
				printf("bool\n");
				break;
			default :
				printf("type pas trouvé\n");
		}

		loop = loop->next;
	}
}


typelist* get_typelist(char *id)
{
	int pos = hachage(id);

	P_symb *symb_loop = symb_tab[pos];

	while (symb_loop != NULL)
	{
		if (!strcmp(symb_loop->name, id))
			return symb_loop->arglist;
		symb_loop = symb_loop->next_doublon;
	}

	printf("fonction %s pas trouvée\n",id );
	exit(1);
}

void chk_symb_fct(char *id)
{
	int pos = hachage(id);

	P_symb *symb_loop = symb_tab[pos];

	while (symb_loop != NULL)
	{
		if (!strcmp(symb_loop->name, id) && symb_loop->type_I == FUNCTION)
			return;
		symb_loop = symb_loop->next_doublon;
	}

	printf("%s pas une fonction\n", id);
	exit(1);
}

void add_typelist_to_symb(char *id, typelist* arg)
{
	int pos = hachage(id);

	P_symb *symb_loop = symb_tab[pos];

	while (symb_loop != NULL)
	{
		if (!strcmp(symb_loop->name, id))
			{
				symb_loop->arglist = arg;
				return;
			}
		symb_loop = symb_loop->next_doublon;
	}

	return;
}

int gencode_param(typelist* arg)
{
	typelist* l;
	int len = 0;

	//need to reverse the linked list arg
	typelist* prev = NULL;
    typelist* current = arg;
    typelist* next = NULL;
    while (current != NULL) {
        next = current->next;

        current->next = prev;

        prev = current;
        current = next;
    }

    l = prev;

	while (l != NULL)
	{
		quad q = quad_make(Q_PARAM, NULL, NULL, quadop_name(l->name));
		gencode(q);
		len++;
		l = l->next;
	}

	return len;
}


int len_param(typelist* arg)
{
	typelist* loop = arg;
	int len = 0;

	while (loop != NULL)
	{
		len++;
		loop = loop->next;
	}

	return len;
}
