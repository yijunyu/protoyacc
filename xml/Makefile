PREFIX=yy
YACC = bison$(X)
LEX  = flex
YFLAGS  = -dv -S yaxx-${Y}-bison-$(X).c 
CFLAGS  = -g -O
LFLAGS  =
BIN = .
CC = gcc

SRC = xml.y xml.l main.c
OBJ = xml.tab.o lex.yy.o main.o

all: test-yaxx.xml

%-yaxx.xml:%.xml $(BIN)/xmlc
	$(BIN)/xmlc < $*.xml
	mv yaxx.xml $*-yaxx.xml

$(BIN)/xmlc : $(OBJ)
	${CC} $(CFLAGS) $(OBJ) -ll -o $@

%.tab.c: %.y
	export BISON_SIMPLE=../bison/src/bison.simple.yaxx
	${YACC} ${YFLAGS} $< 

lex.yy.c: xml.l
	${LEX} $< 

lex.yy.o: lex.yy.c
	${CC} -c ${CFLAGS} $< -o $@

lex.yy.o: xml.tab.h
xml.tab.h: xml.tab.c

clean   :
	rm -f xml.tab.h xml.tab.c xml.output lex.yy.c *.o

realclean:
	${MAKE} clean
	rm -f $(BIN)/xmlc* *yaxx.xml yaxx.dtd
