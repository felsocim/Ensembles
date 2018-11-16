CC = gcc
CFLAGS = -Wall -Werror -Wextra -g
RM = rm -f
DATETIME = `date +%F_%H-%M-%S`

log : all
	[ -d logs ] || mkdir logs
	mkdir logs/$(DATETIME)
	./NTEns_base > logs/$(DATETIME)/Log_NTEns_base.txt
	./NTEns_op > logs/$(DATETIME)/Log_NTEns_op.txt
	./NTEns_app > logs/$(DATETIME)/Log_NTEns_app.txt
	./TEns_base > logs/$(DATETIME)/Log_TEns_base.txt
	./TEns_op > logs/$(DATETIME)/Log_TEns_op.txt
	./TEns_app > logs/$(DATETIME)/Log_TEns_app.txt

all : tests_non_tries tests_tries

ensemble1 : source/ensemble1.c include/ensemble.h include/base.h
	[ -d obj ] || mkdir obj
	$(CC) -c source/ensemble1.c -o obj/ensemble1.o

ensemble2 : source/ensemble2.c include/ensemble.h include/base.h
	[ -d obj ] || mkdir obj
	$(CC) -c source/ensemble2.c -o obj/ensemble2.o
	
antecedent : source/antecedent.c include/antecedent.h include/base.h
	[ -d obj ] || mkdir obj
	$(CC) -c source/antecedent.c -o obj/antecedent.o
	
application : source/application.c include/application.h include/ensemble.h $(EMODE_FILE) include/base.h
	[ -d obj ] || mkdir obj
	$(CC) -c source/application.c -o obj/application.o
	
tests_non_tries : source/test_ensembles_base.c source/test_operations_ensemblistes.c source/test_applications_composition.c ensemble1 antecedent application
	$(CC) $(CFLAGS) source/test_ensembles_base.c obj/ensemble1.o -o NTEns_base
	$(CC) $(CFLAGS) source/test_operations_ensemblistes.c obj/ensemble1.o -o NTEns_op
	$(CC) $(CFLAGS) source/test_applications_composition.c obj/ensemble1.o obj/antecedent.o obj/application.o -o NTEns_app
	
tests_tries : source/test_ensembles_base.c source/test_operations_ensemblistes.c source/test_applications_composition.c ensemble2 antecedent application
	$(CC) $(CFLAGS) source/test_ensembles_base.c obj/ensemble2.o -o TEns_base
	$(CC) $(CFLAGS) source/test_operations_ensemblistes.c obj/ensemble2.o -o TEns_op
	$(CC) $(CFLAGS) source/test_applications_composition.c obj/ensemble2.o obj/antecedent.o obj/application.o -o TEns_app

clean_all: clean clean_logs

clean :
	$(RM) -r obj
	$(RM) NTEns_base NTEns_op NTEns_app TEns_base TEns_op TEns_app

clean_logs :
	$(RM) -r logs
