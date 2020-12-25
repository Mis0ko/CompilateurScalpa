LFLAGS= -ly 	# Lex
CFLAGS= -g -Wall -Iheaders -Ibuild  
C_COMPILER = gcc		    
EXS = ./binary/scalpa 

DIR = build binary			   
COMMON_DEPS = $(SOURCES) $(HEADERS)

SOURCES = $(wildcard utils/*.c)
HEADERS = $(wildcard headers/*.h)
OBJS = $(SOURCES:utils/%.c=binary/%.o)

LFLAGS += -lfl

# Main

all: $(DIR) $(OBJS) $(EXS)

# Directories

$(DIR):
	mkdir -p $(DIR)


binary/%.o: utils/%.c headers/%.h
	$(C_COMPILER) -o $@ -c $< $(CFLAGS)


binary/scalpa: yacc/scalpa.y lex/scalpa.l $(OBJS)
	yacc -v -d yacc/scalpa.y -o build/y.scalpa.c
	flex -o build/scalpa.yy.c lex/scalpa.l
	$(C_COMPILER) $(CFLAGS) build/y.scalpa.c build/scalpa.yy.c $(OBJS) $(LFLAGS) -o $@


clean:
	rm -rif *.o ./binary/*.o y.*.c y.*.o y.*.h *.yy.c a.out $(EXS) y.*.output build
