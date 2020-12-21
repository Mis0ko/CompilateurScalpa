#include <stdio.h>
#include <stdlib.h>
struct P_symb;
#define SIZE_HASH_TABLE 1000
#define SYMBNAME_SIZE 100


typedef enum ident_type 
{ 
    VARIABLE , FUNCTION , ARRAY , PARAMETER 
} ident_type ;

typedef enum atomic_type
{ 
    INT , REAL , BOOL , CHAR 
} atomic_type ;

/* need to crate a function to desallocate a symb */

typedef struct P_symb
{
    int                 idx;
    char*               name;           // Name of the identifier 
    ident_type          type_I;         // Type of the identifier ( variable , function , array , function parameter , ... )
    atomic_type         type_A;         // atomic type of ident / return value if function (int, real, bool, char)
    unsigned int        addr;           // Memory address
    int                 scope;          // globale/locale, begin with 0 for globable and +1 for each new bloc, but we begin without it.
    struct P_symb* next_doublon;
} P_symb ;



typedef struct ident_list
{
    char*       name;           // name
    struct ident_list* next;
} ident_list ;




P_symb** symb_tab; //global table

void init_symb_tab();
int hachage(char *chaine);
void create_symb(char* var, char* typename, ident_list* list);
void create_symblist(char* var, ident_list* list, char* typename);
int same_symb(P_symb* symb1, P_symb* symb2);
int search_symb(P_symb* symb);
int add_symb(P_symb* symb);
void print_symb(P_symb* symb);
void print_tab();