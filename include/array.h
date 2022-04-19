#ifndef ARRAY_H
#define ARRAY_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "quad.h"
#include "fct_utilitaires.h"

struct quadop;

/*
* struct of dimensions of an array
*/
typedef struct dim_list {
	int min_dim;
	int max_dim;
	struct dim_list* next;
} dim_list;

/*
 * struct of a list of index
 */
typedef struct index_list {
	char *tab;
	enum { INDX_CST, INDX_NAME} type;
	union un {
		char *index_name;
		int index_int;
	} un;
	struct index_list* next_indxlist;

} index_list;

/*
 * struct of an array call , name of array ,
 * elementcall tab[i][j] , index_list(i,j)
 */
typedef struct array_call {
	char *tab_name;
	char *tab_element;
	struct index_list* head_array;
} array_call;



//********* Declarationde tableau ********

void check_indx(char *tab_id, index_list *index_list);

array_call *array_call_info(char *tab_id, index_list *index_list);

index_list *all_indexs(index_list *indx, struct quadop *index);

index_list *solo_index(struct quadop *index);

dim_list *add_dim(int dim_inf, int dim_sup);

dim_list *add_dims(dim_list *old_list, int dim_inf, int dim_sup);

void print_dims(dim_list *dims_list);

dim_list * lookfor_dims(char *tab_id);

#endif
