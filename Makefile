ens : main.o ensemble.o
	gcc -Wall -g -Werror -Wextra main.o ensemble.o -o ens_NT
	
ensemble.o : ensemble.c ensemble.h
	gcc -c ensemble.c -o ensemble.o
	
main.o : main.c ensemble.h ensemble.c
	gcc -c main.c -o main.o
	
clean:
	rm -f *.o
	rm -f ens_NT
