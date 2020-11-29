#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#define UNDEF           0
#define UNIT_TYPE       1
#define BOOL_TYPE       2
#define INT_TYPE        3
#define ARRAY_TYPE      4
#define FUNCTION_TYPE   5

#define BY_VALUE        1
#define BY_REFER        2

typedef struct AddrList
{
    int                 address ;
    struct AddrList*    next    ;
    int                 type    ;
    int                 test_pour_voir_sur_git ;
} AddrList ;

#endif 