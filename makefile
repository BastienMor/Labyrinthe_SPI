SRC=src/
INCLUDE=include/
OUTPUT=bin/
OPT= -g -Wall

all: laby 

laby: ${SRC}%.c ${INCLUDE}%.h
	gcc ${SRC}%.c -o ${OUTPUT}laby ${OPT}

clean:
   rm *.o
   rm ../*~
