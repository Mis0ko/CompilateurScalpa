#include "../include/mips.h"
// #define SIZE_INSTR 100
// void MIPS_OPREL_COMP(quad q, FILE *os)
// {
//     char instr[SIZE_INSTR];
//     switch (q.type)
//     {
//     case Q_SUP:
//         snprintf(instr, SIZE_INSTR - strlen(instr), "bgt\t");
//         break;

//     case Q_SUPEQ:
//         snprintf(instr, SIZE_INSTR - strlen(instr), "bge\t");
//         break;
//     case Q_INF:
//         snprintf(instr, SIZE_INSTR - strlen(instr), "blt\t");
//         break;
//     case Q_INFEQ:
//         snprintf(instr, SIZE_INSTR - strlen(instr), "ble\t");
//         break;
//     case Q_EQ:
//         snprintf(instr, SIZE_INSTR - strlen(instr), "ble\t");
//         break;
//     }
//     if (strlen(instr) != 0)
//     {
//         if (q.op1->type == QO_CST)
//             snprintf(instr, SIZE_INSTR - strlen(instr), "%i, ", q.op1->u.cst);
//         else
//             snprintf(instr, SIZE_INSTR - strlen(instr), "$%s, ", q.op1->u.name);

//         if (q.op2->type == QO_CST)
//             snprintf(instr, SIZE_INSTR - strlen(instr), "%i, ", q.op1->u.cst);
//         else
//             snprintf(instr, SIZE_INSTR - strlen(instr), "$%s, ", q.op1->u.name);

//         // faudra changer ça plus tard pck pas propre en vrai,
//         // peut y avoir des doublons and co mais plus tard.
//         snprintf(instr, SIZE_INSTR - strlen(instr), "QUAD_%s\n", q.res->u.name);
//     }
//     else {
//         snprintf(instr, SIZE_INSTR, "quad pas encore pris en charge\n");
//     }
//     fputs(instr, os);
// }


// void MIPS_ALL(FILE *os){

//     for(int i = 0 ; i < nextquad; i++){
//         MIPS_OPREL_COMP(globalcode[i], os);
//     }
// }

// void trad_mips_all(int argc, char **argv)
// {

//     FILE *code_mips;

//     code_mips = fopen(argv[1], "w+");
//     if (code_mips == NULL)
//     {
//         fprintf(stderr, "Erreur durant l'ouverture du fichier\n");
//         exit(-1);
//     }
//     MIPS_ALL(code_mips);
//     int ret_close = fclose(code_mips);
//     if (ret_close == EOF)
//     {
//         fprintf(stderr, "Erreur durant la fermeture du fichier\n");
//         exit(-1);
//     }
// }