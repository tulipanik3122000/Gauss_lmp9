all:
	gcc -Wall --pedantic src/*.c -o bin/gauss

test: all
	bin/gauss dane/A dane/b

compile:
	gcc -Wall --pedantic src/*.c -o bin/testy

test1: compile
	bin/testy dane/3na41 dane/3na42

test2: compile
	bin/testy dane/C dane/d

test3: compile
	bin/testy dane/E1 dane/e2

test4: compile
	bin/testy dane/osobliwa1 dane/osobliwa2

testall: test1 test2 test3 test4
