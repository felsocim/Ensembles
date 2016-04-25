all : obj/enst0.o obj/ensemble.o obj/enst1.o obj/t_ensemble.o
	gcc -Wall -g -Werror -Wextra obj/enst0.o obj/ensemble.o -o bin/enst0
	gcc -Wall -g -Werror -Wextra obj/enst1.o obj/t_ensemble.o -o bin/enst1
	
obj/ensemble.o : source/ensemble.c include/ensemble.h
	gcc -c source/ensemble.c -o obj/ensemble.o

obj/t_ensemble.o : source/t_ensemble.c include/ensemble.h
	gcc -c source/t_ensemble.c -o obj/t_ensemble.o
	
obj/enst0.o : bin/enst0.c include/ensemble.h source/ensemble.c
	gcc -c bin/enst0.c -o obj/enst0.o
	
obj/enst1.o : bin/enst1.c include/ensemble.h source/t_ensemble.c
	gcc -c bin/enst1.c -o obj/enst1.o
	
clean:
	rm -f obj/*.o
	rm -f bin/enst0
	rm -f bin/enst1
