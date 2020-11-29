typedef enum ident_type 
{ 
    VARIABLE , FUNCTION , ARRAY , PARAMETER 
} ident_type ;

typedef struct function_values
{
    const int   nb_param    ; // Number of parameters ;
    const int*  param_mode  ; // Mode of passage of the parameter ( adress , value )
} function_val ;

typedef struct array_values
{
    const int   nb_param    ; // Number of parameters ;
    const int*  param_mode  ; // Mode of passage of the parameter ( adress , value )
} array_val ;

typedef struct ident
{
    const char*         name        ; // Name of the identifier 
    ident_type          type        ; // Type of the identifier ( variable , function , array , function parameter , ... )
    unsigned int        addr        ; // Memory address

    const function_val  function_v  ; // Important values if it is a function      
    const array_val     array_v     ; // Imoortant values if it is an array
} ident ;