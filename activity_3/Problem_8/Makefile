all: write read

write: write.c 
	gcc -o write.out write.c -lpthread -lrt
	
sol8read: read.c 
	gcc -o read.out read.c -lpthread -lrt
	
 runread:
	./sol8read.out

runwrite:
	./write.out

clean:
	rm -rf *.out *.o
