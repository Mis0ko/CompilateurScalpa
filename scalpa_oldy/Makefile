OS:=$(shell uname)
LFLAGS= -ly	    # Lex linking flags
CFLAGS= -g -Wall -Iheaders -Ibuild   # C Flags
C_COMPILER = gcc		    # C compiler
EXS = binary/scalpa # Final output files

DIR = build binary			    # Folders to create
COMMON_DEPS = $(SOURCES) $(HEADERS)

SOURCES = $(wildcard src/*.c)
HEADERS = $(wildcard headers/*.h)
OBJS = $(SOURCES:src/%.c=binary/%.o)

# OS Specific
$(info Running on $(OS))
ifeq ($(OS),Darwin)
    LFLAGS += -ll
endif

ifeq ($(OS),Linux)
    LFLAGS += -lfl
endif

# Main

all: $(DIR) $(OBJS) $(EXS)

# Directories

$(DIR):
	mkdir -p $(DIR)

# C Library 

binary/%.o: src/%.c headers/%.h
	$(C_COMPILER) -o $@ -c $< $(CFLAGS)

# scalpa

binary/scalpa: yacc/scalpa.y lex/scalpa.l $(OBJS)
	yacc -v -d yacc/scalpa.y -o build/y.scalpa.c
	flex -o build/scalpa.yy.c lex/scalpa.l
	$(C_COMPILER) $(CFLAGS) build/y.scalpa.c build/scalpa.yy.c $(OBJS) $(LFLAGS) -o $@


clean:
	rm -rif *.o ./binary/*.o y.*.c y.*.o y.*.h *.yy.c a.out $(EXS) y.*.output build

archive:
	tar zcvf compil_masson_meyer.tar.gz Makefile doc/scalpa src headers lex yacc tests test.log run_tests.sh COMPIL_MASSON_MEYER.pdf