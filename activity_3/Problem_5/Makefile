all: ser client_5

ser: ser.c 
	gcc -o ser.out ser.c -lrt
	
client_5: client_5.c 
	gcc -o client_5.out client_5.c -lrt
	
runclient_5:
	./client_5.out

runser:
	./server.out

clean:
	rm -rf *.out *.o
