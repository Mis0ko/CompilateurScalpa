#include "token_tab.h"
/*
Just dynamic init for token table
*/
void init_symb_tab(){
    symb_tab = malloc(SIZE_HASH_TABLE * sizeof(P_symb));
}





/*
It's in this function that we create all the symbols
(for now only variable), cf the grammar.
Check others comment's function for further details
*/
ident_list* create_symblist(char* var, ident_list* list, char* typename)
{
    ident_list* list_parcour = list;
    while(list_parcour != NULL){
        create_symb(var, typename,  list);
        list_parcour = list_parcour->next;
    }
    return list;
}







/*
Hash Function
(sum of ASCII carac)
*/
int hachage(char *chaine){
    int i = 0, nombreHache = 0;
    for (i = 0 ; chaine[i] != '\0' ; i++)
        nombreHache += chaine[i];
    nombreHache %= SIZE_HASH_TABLE;
        printf("%s : %i\n", chaine, nombreHache);
    return nombreHache;
}


/* 
* This Function creates a symbol thanks to the args from the grammar.
*(cf grammar)
* It create a symb and try to add it to the hash table.
* (Add_symb already check if the symb is already in the table)
*/
void create_symb(char* var, char* typename, ident_list* list)
{
        P_symb* symb = malloc(sizeof(P_symb));

        symb->idx = hachage(list->name);
        symb->name = list->name;

        if(strcmp(var, "var") == 0)
            symb->type_I = VARIABLE;

        if(strcmp(typename, "int") == 0)
            symb->type_A = T_INT;
        else if(strcmp(typename, "real") == 0)
            symb->type_A = T_REAL;
        else if(strcmp(typename, "bool") == 0)
            symb->type_A = T_BOOL;
        else if(strcmp(typename, "char") == 0)
            symb->type_A = T_CHAR;

        symb->addr = 0;      // on verra plus tard
        symb->scope = 0;     //idem
        
        symb->next_doublon = NULL;

        if(!add_symb(symb)){
            printf("on free pck il existe déja le symb\n");
            free(symb);
        }

        return ;
}

/*
* Add a symbole given in argument in the hash table (global variable, symb_tab).
* Before that it checks (with search_symb function) if the symb 
* isn't already in the table. if not it check if a doublon 
* already exist at the idx of our current symb and add it to the 
* linked list, otherwise it just affect it.
*/
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
            printf("hash table case was free, symb %s added\n", symb->name);
        }
        else{ // hash table case empty, just copy the symb
            symb_tab[symb->idx] =  symb;
            printf("hash table case was empty, symb %s added\n", symb->name);
        }
        return 1;
    }
    return 0;   //symb already exist, wasnt added
    
}


/*
function that check if a symb is in the hash table.
It use the hash number from the structure symb
and compare to the symb in the hash table, and loop
for all the symb that pocess the same hash number

return 1 if found -1 if not found
*/

int search_symb(P_symb* symb){
    P_symb* symb_loop = symb_tab[symb->idx];
    if(symb_loop != NULL){
        while(symb_loop != NULL){
            if(same_symb(symb, symb_loop))
            {
                printf("symb present");
                return 1;
            }
            symb_loop = symb_loop->next_doublon;
        }
    }
    return -1;
}



/*
compare 2 symbs base on all their arguments
When we use this function we already consider that
the index / hash number is the same.
return:
1 if the same, 0 else.

in the futur ,need to check addr and scope (or not
, IDK didnt think about it right now)
*/
int same_symb(P_symb* symb1, P_symb* symb2)
{
    if(!strcmp(symb1->name, symb2->name)){
        if(symb1->type_I == symb2->type_I
        && symb1->type_A == symb2->type_A)
            return 1;
    }
    return 0;
}


/*
* identlists are just linked-list of futur variable,
* that are componded of a char* (the ident), and a 
* identlist*, for the next ident in the list.
*/




ident_list* create_identlist(char* ident)
{
    ident_list* my_list = malloc(sizeof(ident_list));
    //strncpy(my_list->name, ident, strlen(ident));
    my_list->name = ident;
    my_list->next = NULL;
    return my_list;
}

ident_list* add_to_identlist(ident_list* old_list, char* ident)
{
    ident_list* new_ident = malloc(sizeof(ident_list));
    //strncpy(new_ident->name, ident, strlen(ident));
    new_ident->name = ident;
    new_ident->next = NULL;
    ident_list* loop_ident = old_list;
    while(loop_ident->next != NULL)
        loop_ident = loop_ident->next;
    loop_ident->next = new_ident;
    return old_list;
}



void print_symb(P_symb* symb)
{
    printf("\t%i|\t%s|\n", symb->idx, symb-> name);
}

void print_tab()
{
        printf("		index   	|   	string		\n");
        for(int i =0; i < SIZE_HASH_TABLE ; i++){
            if(symb_tab[i]!= NULL){
                print_symb(symb_tab[i]);
                if(symb_tab[i]->next_doublon != NULL)
                {
                    P_symb* symb_parcour = symb_tab[i]->next_doublon;
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