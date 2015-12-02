prog:	gen_laby.o monstre.o Outil.o 
	gcc gen_laby.o monstre.o Outil.o -o prog 
gen_laby.o:	gen_laby.c 
	gcc -c gen_laby.c -Wall
Outil.o: Outil.c Outil.h
	gcc -c Outil.c Outil.h -Wall
monstre.o: monstre.c monstre.h
	gcc -c monstre.c monstre.h -Wall 
