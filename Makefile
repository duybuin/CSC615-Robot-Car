all: main.c
	sudo gcc -Wall -o main main.c -lwiringPi

main: main.c
	sudo gcc -Wall -o main main.c -lwiringPi

clean:
	sudo rm main

run:
	sudo gcc -Wall -o main main.c -lwiringPi
	sudo ./main