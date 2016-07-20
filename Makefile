all:
	gcc -I/home/fusion809/Documents/CodeLite/C-Math-Projects/lib program8.8.c -o program8.8 && ./program8.8
	gcc -I/home/fusion809/Documents/CodeLite/C-Math-Projects/lib cubicroot.c -o cubicroot && ./cubicroot
clean:
	rm program8.8
	rm cubicroot
