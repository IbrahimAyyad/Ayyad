Build : main.c
	gcc -E -P main.c -o out.i
	gcc -S main.c -o out.asm
	gcc -c main.c -o out.obj
	gcc main.c -o out.exe