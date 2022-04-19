#include "../include/fct_utilitaires.h"

void output_S(const char *msg) { printf("Analyseur syntaxique: %s\n", msg); }

void bug(const char *msg) { printf("DEBUG : %s\n", msg); }

void CHK_MALLOC(void *monmalloc) {
	if (monmalloc == NULL) {
		perror("Unable to allocate memory");
		exit(EXIT_FAILURE);
	}
}
