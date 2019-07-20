CC := gcc
CFLAGS := sprites.bin -Wall -c -pedantic -std=c99 -g
LFLAGS := -lm -lSDL2
OBJFLAGS := main.o graficador.o caracteres.o vectores.o velocidad_movimiento.o diccionario.o lista.o

all: Asteroids_Juego

main.o: main.c
	$(CC) $(CFLAGS) main.c

caracteres.o: caracteres.c
	$(CC) $(CFLAGS) caracteres.c

lista.o: lista.c
	$(CC) $(CFLAGS) lista.c

vectores.o: vectores.c
	$(CC) $(CFLAGS) vectores.c

velocidad_movimiento.o: velocidad_movimiento.c
	$(CC) $(CFLAGS)  velocidad_movimiento.c

graficador.o: graficador.c
	$(CC) $(CFLAGS)  graficador.c

diccionario.o: diccionario.c
	$(CC) $(CFLAGS) diccionario.c


Asteroids_Juego: $(OBJFLAGS)
	$(CC) $(OBJFLAGS) $(LFLAGS) -o Asteroids_Juego

clean:
	rm *.o
