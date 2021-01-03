#include "../include/array.h"



void check_indx(char *tab_id, index_list *index_list) {
	dim_list *dim_tab = lookfor_dims(tab_id);
	if (dim_tab == NULL) {
		printf("failed finding dims\n");
		exit(EXIT_FAILURE);
	}
	int min_dim, max_dim;
	min_dim = dim_tab->min_dim;
	max_dim = dim_tab->max_dim;
	if (index_list->type == INDX_CST) {
		// printf("%d %d %d\n",min_dim, index_list->un.index_int, max_dim);
		if (index_list->un.index_int > max_dim ||
			index_list->un.index_int < min_dim) {
			printf("error index isn't valid");
			exit(EXIT_FAILURE);
		}
	}
	if (index_list->next_indxlist != NULL) {
		dim_tab = dim_tab->next;
		min_dim = dim_tab->min_dim;
		max_dim = dim_tab->max_dim;
		if (index_list->next_indxlist->type == INDX_CST) {
			// printf("%d %d %d\n",min_dim,
			// index_list->next_indxlist->un.index_int, max_dim);
			if (index_list->next_indxlist->un.index_int > max_dim ||
				index_list->next_indxlist->un.index_int < min_dim) {
				printf("error index isn't valid");
				exit(1);
			}
		}
	}
}

array_call *array_call_info(char *tab_id, index_list *index_list) {
	char *tabid_tabindx = malloc(100);
	CHK_MALLOC(tabid_tabindx);
	sprintf(tabid_tabindx, "%s%s", tab_id, index_list->tab);

	array_call *arraycall = malloc(sizeof(array_call));
	CHK_MALLOC(arraycall);

	arraycall->tab_name = strdup(tab_id);
	arraycall->tab_element = strdup(tabid_tabindx);
	arraycall->head_array = index_list;

	return arraycall;
}

index_list *all_indexs(index_list *indx, quadop *index) {
	index_list *indxlist = malloc(sizeof(index_list));
	char *expr_list = malloc(100);
	CHK_MALLOC(indxlist);
	CHK_MALLOC(expr_list);

	if (index->type == QO_CST) {
		sprintf(expr_list, "%s[%d]", indx->tab, index->u.cst);
		indxlist->un.index_int = index->u.cst;
		indxlist->type = INDX_CST;
	} else {
		sprintf(expr_list, "%s[%s]", indx->tab, index->u.name);
		indxlist->un.index_name = strdup(index->u.name);
		indxlist->type = INDX_NAME;
	}
	indxlist->tab = strdup(expr_list);

	indxlist->next_indxlist = indx;
	return indxlist;
}
index_list *solo_index(quadop *index) {
	index_list *indxlist = malloc(sizeof(index_list));
	char *expr = malloc(100);
	CHK_MALLOC(indxlist);
	CHK_MALLOC(expr);

	if (index->type == QO_CST) {
		sprintf(expr, "[%d]", index->u.cst);
		indxlist->un.index_int = index->u.cst;
		indxlist->type = INDX_CST;
	} else {
		sprintf(expr, "[%s]", index->u.name);
		indxlist->un.index_name = strdup(index->u.name);
		indxlist->type = INDX_NAME;
	}
	indxlist->tab = strdup(expr);

	indxlist->next_indxlist = NULL;
	return indxlist;
}
//*********ADDITION********* Added dans token_tab.h

dim_list *add_dim(int dim_inf, int dim_sup) {
	dim_list *st_dimension = malloc(sizeof(dim_list));
	CHK_MALLOC(st_dimension);

	st_dimension->min_dim = dim_inf;
	st_dimension->max_dim = dim_sup;
	st_dimension->next = NULL;
	return st_dimension;
}

dim_list *add_dims(dim_list *old_list, int dim_inf, int dim_sup) {
	dim_list *loop_dim = old_list;
	while (loop_dim->next != NULL) loop_dim = loop_dim->next;
	loop_dim->next = add_dim(dim_inf, dim_sup);
	return old_list;
}

void print_dims(dim_list *dims_list) {
	dim_list *loop_dim = dims_list;
	while (loop_dim->next != NULL) {
		printf("dim : %d %d \n", loop_dim->min_dim, loop_dim->max_dim);
		loop_dim = loop_dim->next;
	}
	printf("dim : %d %d \n", loop_dim->min_dim, loop_dim->max_dim);
}
