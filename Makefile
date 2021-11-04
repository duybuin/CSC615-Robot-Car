all: main.c
	sudo gcc -Wall -o main main.c

main: main.c
	sudo gcc -Wall -o main main.c

clean:
	sudo rm main

run:
	sudo gcc -Wall -o main main.c
	sudo ./main