all:
	gcc -O3 -Imlx_Linux -Lmlx_Linux -g -o main.exe ./src/*.c -lmlx -lXext -lX11 -lm
