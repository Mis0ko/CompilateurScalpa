#include "../include/token_tab.h"

P_symb **symb_tab;

/******************** begining of the functions ********************/

void init_symb_tab()
{
    symb_tab = malloc(SIZE_HASH_TABLE * sizeof(P_symb *));
}

ident_list *create_symblist(char *var, ident_list *list, char *typename)
{
    ident_list *list_parcour = list;
    while (list_parcour != NULL)
    {
        create_symb(var, typename, list_parcour->name);
        list_parcour = list_parcour->next;
    }
    return list;
}

int hachage(char *chaine)
{
    int i = 0, nombreHache = 0;
    for (i = 0; chaine[i] != '\0'; i++)
    {
        nombreHache += chaine[i];
    }
    nombreHache %= SIZE_HASH_TABLE;
    return nombreHache;
}

void create_symb(char *var, char *typename, char *id)
{
    P_symb *symb = malloc(sizeof(P_symb));
    symb->next_doublon = NULL;
    symb->name = malloc(SYMBNAME_SIZE);
    CHK_MALLOC(symb->name);
    sprintf(symb->name, "%s", id);

    if (strcmp(var, "var") == 0)
        symb->type_I = VARIABLE;

    if (strcmp(typename, "int") == 0)
        symb->type_A = T_INT;
    else if (strcmp(typename, "bool") == 0)
        symb->type_A = T_BOOL;
    else if (strcmp(typename, "unit") == 0)
        symb->type_A = T_UNIT;

    symb->idx = hachage(id);
    symb->addr = 0;  // on verra plus tard
    symb->scope = 0; //idem
    if (!add_symb(symb))
    {
        printf("we free the symb \"%s\" created because already exist in the symbole table\n", id);
        free(symb);
    }

    return;
}

int add_symb(P_symb *symb)
{
    int already_in = search_symb(symb);

    if (already_in == -1)
    {
        if (symb_tab[symb->idx] != NULL)
        {
            P_symb *symb_parcour = symb_tab[symb->idx];
            while (symb_parcour->next_doublon != NULL)
            {
                symb_parcour = symb_parcour->next_doublon;
            }
            symb_parcour->next_doublon = symb;
            printf("hash table case wasn't empty, symb %s added\n", symb->name);
        }
        else
        { // hash table case empty, just copy the symb
            symb_tab[symb->idx] = symb;
            printf("hash table case was empty, symb %s added\n", symb->name);
        }
        return 1;
    }
    return 0; //symb already exist, wasnt added
}

int search_symb(P_symb *symb)
{

    P_symb *symb_loop = symb_tab[symb->idx];

    if (symb_loop != NULL)
    {
        while (symb_loop != NULL)
        {
            if (same_symb(symb, symb_loop))
            {
                printf("symb present\n");
                return 1;
            }
            symb_loop = symb_loop->next_doublon;
        }
    }
    return -1;
}

int same_symb(P_symb *symb1, P_symb *symb2)
{
    if (!strcmp(symb1->name, symb2->name))
    {
        if (symb1->type_I == symb2->type_I && symb1->type_A == symb2->type_A)
            return 1;
    }
    return 0;
}

ident_list *create_identlist(char *ident)
{
    ident_list *my_list = malloc(sizeof(ident_list));
    my_list->name = malloc(SYMBNAME_SIZE);
    sprintf(my_list->name, "%s", ident);
    my_list->next = NULL;
    return my_list;
}

ident_list *add_to_identlist(ident_list *old_list, char *ident)
{
    ident_list *new_ident = malloc(sizeof(ident_list));
    new_ident->name = malloc(SYMBNAME_SIZE);
    sprintf(new_ident->name, "%s", ident);
    new_ident->next = NULL;
    ident_list *loop_ident = old_list;
    while (loop_ident->next != NULL)
        loop_ident = loop_ident->next;
    loop_ident->next = new_ident;
    return old_list;
}

void print_symb(P_symb *symb)
{
    if (strlen(symb->name) >= 8)
        printf("|\t\t%i\t\t|\t\t%s\t|", symb->idx, symb->name);
    else
        printf("|\t\t%i\t\t|\t\t%s\t\t|", symb->idx, symb->name);
    if (symb->type_I == VARIABLE)
    {
        printf("\t\t");
        switch (symb->type_A)
        {
        case T_INT:
            printf("int");
            break;
        case T_BOOL:
            printf("bool");
            break;
        case T_UNIT:
            printf("unit");
            break;
        }
        printf("\t\t|\n");
    }
    else
        printf("\n");
}

void print_tab()
{
    printf("|-------------------------------|");
    printf("-------------------------------|");
    printf("-------------------------------|\n");
    printf("|\t\tindex\t\t|\t\tident \t\t|\t\tatomic_type\t|\n");
    printf("|-------------------------------|");
    printf("-------------------------------|");
    printf("-------------------------------|\n");
    for (int i = 0; i < SIZE_HASH_TABLE; i++)
    {
        if (symb_tab[i] != NULL)
        {
            print_symb(symb_tab[i]);
            if (symb_tab[i]->next_doublon != NULL)
            {
                P_symb *symb_parcour = symb_tab[i]->next_doublon;
                while (symb_parcour != NULL)
                {
                    print_symb(symb_parcour);
                    symb_parcour = symb_parcour->next_doublon;
                }
            }
        }
    }
    printf("|-------------------------------|");
    printf("-------------------------------|");
    printf("-------------------------------|\n");
}
