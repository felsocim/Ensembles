#Compilateur
CC = gcc

#Flags
CFLAGS = -Wall -Werror -Wextra -g
RM = rm -f

#Choix de la représentation des ensembles
#UTILISER: source/ensemble1.c pour les ensembles non-triés
#		   source/ensemble2.c pour les ensembles triés
EMODE_FILE = source/ensemble2.c
EMODE = obj/ensemble2.o

#Cibles
all : non_trie_test other_tests

ensemble1 : source/ensemble1.c include/ensemble.h include/base.h
	$(CC) -c source/ensemble1.c -o obj/ensemble1.o

ensemble2 : source/ensemble2.c include/ensemble.h include/base.h
	$(CC) -c source/ensemble2.c -o obj/ensemble2.o
	
antecedent : source/antecedent.c include/antecedent.h include/base.h
	$(CC) -c source/antecedent.c -o obj/antecedent.o
	
application : source/application.c include/application.h include/ensemble.h $(EMODE_FILE) include/base.h
	$(CC) -c source/application.c -o obj/application.o
	
non_trie_test : bin/test_ens1.c ensemble1
	$(CC) $(CFLAGS) bin/test_ens1.c obj/ensemble1.o -o Test1
	
other_tests : bin/test_ens2.c bin/test_app1.c ensemble1 ensemble2 antecedent application
	$(CC) $(CFLAGS) bin/test_ens2.c $(EMODE) -o Test2
	$(CC) $(CFLAGS) bin/test_app1.c $(EMODE) obj/antecedent.o obj/application.o -o Test3

#Nettoyage
clean :
	$(RM) obj/*.o
	$(RM) Test1 Test2 Test3
