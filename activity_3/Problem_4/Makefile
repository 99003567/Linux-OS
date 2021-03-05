all: recieve send

sol4send: send.c 
	gcc -o send.out send.c -lrt
	
sol4receive: receive.c 
	gcc -o receive.out receive.c -lrt
	
runreceive:
	./receive.out

runsend:
	./send.out

clean:
	rm -rf *.out *.o
