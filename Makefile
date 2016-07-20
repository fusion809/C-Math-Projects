all:
	gcc program8.8.c -o program8.8 && ./program8.8
	gcc cubicroot.c -o cubicroot && ./cubicroot
clean:
	rm program8.8
	rm cubicroot
