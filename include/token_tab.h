#ifndef TOKEN_TAB_H
#define TOKEN_TAB
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fct_utilitaires.h"

#define DINT 0
#define DBOOL 1
#define DUNIT 2

struct P_symb;
struct ident_list;
#define SIZE_HASH_TABLE 1000
#define SYMBNAME_SIZE 100



/******************** STRUCT/ENUM for syntaxe analysis ********************/
typedef enum ident_type
{
    VARIABLE , FUNCTION , ARRAY , PARAMETER
} ident_type ;


// T_TYPE au lieu de juste TYPE pck sinn redeclaration avec
// le fichier y.tab.h
typedef enum atomic_type
{
    T_INT , T_UNIT , T_BOOL
} atomic_type ;

typedef struct ident_list
{
    char*       name;           // name
    struct ident_list* next;
} ident_list ;

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


/******************** FUNCTIONS ********************/
/*
* Just dynamic init for token table
*/
void init_symb_tab();

/*
* Hash Function
* (sum of ASCII carac)
*/
int hachage(char *chaine);

/*
* This Function creates a symbol thanks to the args from the grammar.
* (cf grammar)
* It create a symb and try to add it to the hash table.
* (Add_symb already check if the symb is already in the table)
*/
void create_symb(char* var, char* typename, char *id);

/*
* It's in this function that we create all the symbols
* (for now only variable), cf the grammar.
* Check others comment's function for further details
*/
ident_list* create_symblist(char* var, ident_list* list, char* typename);

/*
* Add a symbole given in argument in the hash table (global variable, symb_tab).
* Before that it checks (with search_symb function) if the symb
* isn't already in the table. if not it check if a doublon
* already exist at the idx of our current symb and add it to the
* linked list, otherwise it just affect it.
*/
int add_symb(P_symb* symb);

/*
* Function that check if a symb is in the hash table.
* It use the hash number from the structure symb
* and compare to the symb in the hash table, and loop
* for all the symb that pocess the same hash number
*
* return 1 if found -1 if not found
*/

int search_symb(P_symb* symb);


/*
* compare 2 symbs base on all their arguments
* When we use this function we already consider that
* the index / hash number is the same.
* return: 1 if the same, 0 else.
*
* in the futur ,need to check addr and scope (or not
* , IDK didnt think about it right now)
*/
int same_symb(P_symb* symb1, P_symb* symb2);

/*
* identlists are just linked-list of variables,
* that are componded of a char* (the ident), and a
* identlist*, for the next ident in the list.
*/
ident_list* create_identlist(char* ident);

/*
* Add a new ident to the linked-list that already exists
*/
ident_list* add_to_identlist(ident_list* old_list, char* ident);
void print_symb(P_symb* symb);
void print_tab();

#endif
