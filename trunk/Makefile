all:
	gcc -Wall --pedantic src/*.c -o bin/gauss

test: all
	bin/gauss dane/A dane/b

compile:
	gcc -Wall --pedantic src_test/*.c -o bin/testy

test1: compile
	bin/testy dane/A1 dane/b1
test2: compile
	bin/testy dane/A2 dane/b2
test3: compile
	bin/testy dane/A3 dane/b3
test4: compile
	bin/testy dane/A4 dane/b4
test5: compile
	bin/testy dane/A5 dane/b5

testall: test1 test2 test3 test4 test5





