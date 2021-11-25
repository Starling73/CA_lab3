build: main.o
	g++ -o schdl main.o

main.o:
	g++ -c main.cpp

clean:
	rm -f main.o schdl
