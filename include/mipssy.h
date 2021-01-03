#ifndef MIPSSY_H
#define MIPSSY_H

#include "token_tab.h"
#include "array.h"
/**
 *  @brief translates each quad to mips
 * 	@param q : a quad
 *  @param os : output file
 *  @return void
 *
 *  This function translates each quad to mips code , depending of the type
 *  of operation in the quad
 *  Remark: for code optimisation we divided the types to opb/oprel where
 *  we should load both quad_ops
 *  and operation like reading/writing where there isn't two quad_ops
 */
void translate_mips(quad q, FILE* os);

/**
 *  @brief translates intermediate code to mips code
 * 	@param globalcode : global code containing all the quads
 *  @param nextquad : the final number of quads
 *  @param os : output file
 *  @return void
 *
 *  This function prints the MIPS code format in the asm output file
 * 	with .data section where we display the symbol_table variables and strings
 *  then .text section where we display MIPS executable code
 */
void mips_code(quad* globalcode, int nextquad, FILE* os);
#endif
