all:
	gcc -I/home/fusion809/GitHub/mine/math/C-Math-Projects/lib program8.8.c -o program8.8 && ./program8.8
	gcc -I/home/fusion809/GitHub/mine/math/C-Math-Projects/lib cubicroot.c -o cubicroot && ./cubicroot
	gcc -I/home/fusion809/GitHub/mine/math/C-Math-Projects/lib cubeqroot.c -o cubeqroot && ./cubeqroot
clean:
	rm program8.8
	rm cubicroot
	rm cubeqroot
