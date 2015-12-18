SRC=../src/
INCLUDE=../include/
OUTPUT=../bin/
OPT= -g -Wall

all: exe 

exe: ${SRC}*.c ${INCLUDE}*.h
	gcc ${SRC}*.c -o ${OUTPUT}exe ${OPT}

clean:
   rm *.o
   rm ../*~
