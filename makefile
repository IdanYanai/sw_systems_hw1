CC=gcc
AR=ar
FLAGS= -Wall -g

all: mains maindloop maindrec loops

mains : main.o libclassrec.a
	$(CC) $(FLAGS) -o $@ main.o libclassrec.a

maindloop : main.o libclassloops.so
	$(CC) $(FLAGS) -o $@ main.o ./libclassloops.so

maindrec : main.o libclassrec.so
	$(CC) $(FLAGS) -o $@ main.o ./libclassrec.so

loops : libclassloops.a

libclassloops.a: basicClassification.o advancedClassificationLoop.o
	$(AR) -rcs libclassloops.a $^

recursives : libclassrec.a

libclassrec.a : basicClassification.o advancedClassificationRecursion.o
	$(AR) -rcs libclassrec.a $^

loopd : libclassloops.so

libclassloops.so : basicClassification.o advancedClassificationLoop.o
	$(CC) -shared -o libclassloops.so $^

recursived : libclassrec.so

libclassrec.so : basicClassification.o advancedClassificationRecursion.o
	$(CC) -shared -o libclassrec.so $^

main.o : main.c NumClass.h
	$(CC) $(FLAGS) -c $<

basicClassification.o : basicClassification.c NumClass.h
	$(CC) $(FLAGS) -c -fpic $<

advancedClassificationLoop.o : advancedClassificationLoop.c NumClass.h
	$(CC) $(FLAGS) -c -fpic $<

advancedClassificationRecursion.o : advancedClassificationRecursion.c NumClass.h
	$(CC) $(FLAGS) -c -fpic $<

.PHONY: clean recursived loopd recursives loops all

clean:
	rm -f *.o *.so *.a mains maindloop maindrec
