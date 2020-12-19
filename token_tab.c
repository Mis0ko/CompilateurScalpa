#include <stdio.h>
#include <stdlib.h>
struct P_symb;
#define SIZE_HASH_TABLE 1000
#define SYMBNAME_SIZE 100
char buffer[200];

typedef enum token_type 
{ 
    VARIABLE , FUNCTION , ARRAY , PARAMETER 
} token_type ;

typedef enum atomic_type
{ 
    INT , REAL , BOOL , CHAR 
} atomic_type ;

/* need to crate a function to desallocate a symb */

typedef struct P_symb
{
    int                 idx;
    const char*         name;           // Name of the identifier 
    ident_type          type_I;         // Type of the identifier ( variable , function , array , function parameter , ... )
    atomic_type         type_A;         // atomic type of ident / return value if function (int, real, bool, char)
    unsigned int        addr;           // Memory address
    int                 scope;          // globale/locale, begin with 0 for globable and +1 for each new bloc, but we begin without it.
    struct P_symb* next_doublon;
} P_symb ;


P_symb** symb_tab; 

void init_symb_tab(){
    symb_tab = malloc(SIZE_HASH_TABLE * sizeof(P_symb));
}


void output(const char* msg)
{
    printf("Analyseur lexical: %s\n", msg);
}

/*
fonction de hachage basique (somme des caractères ASCII)
A changer pour de meilleurs perf plus tard
*/
void hachage(char *chaine){
    int i = 0, nombreHache = 0;
    for (i = 0 ; chaine[i] != '\0' ; i++)
        nombreHache += chaine[i];
    nombreHache %= SIZE_HASH_TABLE;
        printf("%s : %i\n", chaine, nombreHache);
}


/* créé un unique symb à partir de ce qu'on récupère de 
la grammaire */
P_symb* create_symb(char* var, char* name, char* typename)
{
        P_symb* symb = malloc(P_symb);

        symb->idx = hachage(name);

        symb->name = malloc(strlen(identlist->name));
        strncpy(symb->name, identlist->name, strlen(identlist->name));

        if(strcompare(var, "var") == 0)
            symb->type_I = VARIABLE;

        if(strcompare(typename, "int") == 0)
            symb->type_A = INT;
        else if(strcompare(typename, "real") == 0)
            symb->type_A = REAL;
        else if(strcompare(typename, "bool") == 0)
            symb->type_A = BOOL;
        else if(strcompare(typename, "char") == 0)
            symb->type_A = CHAR;

        symb->addr = 0;     // on verra plus tard
        symb->score = 0;     //idem
        
        symb->next_doublon = NULL;

        return symb;
}



P_symb* create_symblist(char* var, ident_list* identlist, char* typename)
{
    while(identlist != NULL){

        identlist = identlist->next;
    }
}




/*
compare 2 symbs base on all their arguments
When we use this function we consider that
the index / hash number is the same.
1 if the same, 0 else.
*/
int same_symb(P_symb* symb1, P_symb* symb2)
{
    if(!strcmp(symb1->symb_name, symb2->symb_name)){
        if(symb1->type_I == symb2->type_A
        && symb1->type_A == symb2->type_A)
            return 1;
    }
    return 0;
}

/*
function that check if a symb is in the hash table.
It use the hash number from the structure symb
and compare to the symb in the hash table, and loop
for all the symb that pocess the same hash number

not tested yet
return 1 if found -1 if not found
*/

int search_symb(P_symb* symb){
    P_symb* symb_table = symb_tab[symb->idx];
    if(symb_table != NULL){
        while(symb_table != NULL){
            if(same_symb(symb, symb_table))
            {
                printf("symb present");
                return 1;
            }
            symb_table = symb_table->next_doublon;
        }
    }
    return -1;
}



int add_symb(P_symb* symb)
{
    int already_in = search_symb(symb);
    if(already_in == -1)
    {
        if(symb_tab[symb->idx]!= NULL)
        {
            P_symb* symb_parcour = symb_tab[symb->idx];
            while(symb_parcour->next_doublon != NULL){
                symb_parcour = symb_parcour-> next_doublon;
            }
            symb_parcour->next_doublon = symb;
        }
        else{ // hash table case empty, just copy the symb
            symb_tab[symb->idx] =  symb;
        }
    }
    
}

/*******************************************************************/
/****************** reste ce qui ya en dessous à *******************
*********checker et ensuite on compile et debug issou **************/
/******************************************************************/

void print_symb(P_symb* symb)
{
    printf("	%i	|	%s	| ", symb->idx, symb-> name);
    printf("\n");
}

void print_tab()
{
        printf("		index   	|   	chaine		\n");
        for(int i =0; i < SIZE_HASH_TABLE ; i++){
            if(&symb_tab[i]!= NULL){
                print_symb(&symb_tab[i]);
                if(symb_tab[i].next_doublon != NULL)
                {
                    P_symb* symb_parcour = symb_tab[i].next_doublon;
                    while(symb_parcour != NULL){
                        print_symb(symb_parcour);
                        symb_parcour = symb_parcour-> next_doublon;
                    }
                }
            }
        }
}




void test_symb_tab(void)
{}