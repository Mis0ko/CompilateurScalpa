#ifndef MIPSSY_H
#define MIPSSY
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "token_tab.h"
#include "quad.h"

void tomips(quad* globalcode, symbol st, FILE* os);
void translatemips(quad q, FILE* os) ;




#endif
