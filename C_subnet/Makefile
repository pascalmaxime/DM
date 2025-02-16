all: partie1 partie2 partie3 partie4 partie5

partie1: partie1.c 
	gcc -o partie1 partie1.c 

test1:
	cat test1_1.txt | ./partie1
	cat test1_2.txt | ./partie1
	cat test1_3.txt | ./partie1

partie2: partie2.c
	gcc -o partie2 partie2.c 

test2:
	cat test2_1.txt | ./partie2
	cat test2_2.txt | ./partie2
	cat test2_3.txt | ./partie2
	cat test2_4.txt | ./partie2
	cat test2_5.txt | ./partie2
	cat test2_6.txt | ./partie2
	cat test2_7.txt | ./partie2
	cat test2_8.txt | ./partie2

partie3: partie3.c 
	gcc -o partie3 partie3.c 

test3:
	cat test3_1.txt | ./partie3
	cat test3_2.txt | ./partie3

partie5: partie5.c 
	gcc -o partie5 partie5.c 

test5:
	cat test5_1.txt | ./partie5
	cat test5_2.txt | ./partie5
	cat test5_3.txt | ./partie5
	cat test5_4.txt | ./partie5
clean:
	rm -f partie1 partie2 partie3 partie4 partie5
