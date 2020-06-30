output: json.o node.o stack.o queue.o
	gcc -c json.o node.o stack.o queue.o -o output.o
node.o: node.c node.h
	gcc -c node.c -o node.o
json.o: json.c json.h
	gcc -c json.c -o json.o
stack.o: stack.c stack.h
	gcc -c stack.c -o stack.o
queue.o: queue.c queue.h
	gcc -c queue.c -o queue.o

test-json: tests/test-json.c json.o
	gcc test-json.c *.o -o ./tests/test-json
test-queue: tests/test-queue.c queue.o
	gcc test-queue.c *.o -o ./tests/test-queue
tests: test-json test-queue