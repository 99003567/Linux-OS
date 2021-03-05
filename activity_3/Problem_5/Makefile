all: server client_5

sol5server: sol5server.c 
	gcc -o server.out server.c -lrt
	
sol5client: sol5client.c 
	gcc -o client_5.out client_5.c -lrt
	
runsol5client:
	./client_5.out

runsol6server:
	./server.out

clean:
	rm -rf *.out *.o
