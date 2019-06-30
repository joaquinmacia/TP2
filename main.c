#include <SDL2/SDL.h>
#include <time.h>
#include <math.h>
#include <stdio.h>


int main()
{
	SDL_Init(SDL_INIT_VIDEO);

	SDL_Window *window;
	SDL_Renderer *renderer;
	SDL_Event event;

	SDL_CreateWindowAndRenderer(VENTANA_ANCHO, VENTANA_ALTO, 0, &window, &renderer);
	SDL_SetWindowTitle(window, "Lunar Lander");

	int dormir = 0;

	// BEGIN código del alumno
	srand (time(NULL));

	//Condiciones iniciales de partida:
	int* sprites_cant_levantada;
	sprite_t** v_sprite = sprites_desde_archivo(sprites_cant_levantada);
	if (v_sprite)
		return EXIT_FAILURE;


	// END código del alumno



	unsigned int ticks = SDL_GetTicks();
	while(1)
	{
		if(SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
				break;
	    	if (event.type == SDL_KEYDOWN)
	    	{
				// BEGIN código del alumno
				//Zona dentro de la rutina de chequeo de teclado para modificar variables de estado en función de la entrada del usuario:
				switch(event.key.keysym.sym)
				{
					case SDLK_UP:

						break;
					case SDLK_DOWN:

						break;
					case SDLK_RIGHT:

						break;
					case SDLK_LEFT:

						break;
				}
				// END código del alumno
			}
			continue;
		}

        SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0x00);
        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0x00);

		//BEGIN código del alumno
		//Zona dentro de la rutina de dibujado de ventana para evolucionar las variables de estado y dibujar todo lo referido a la parte gráfica:
		//EVOLUCIONO VARIABLES DE ESTADO

		//Pasa 1 diferencial de tiempo DT
		tiempo += DT;

		//Computo la aceleracion en x en ese preciso momento.
		//Computo la velocidad en x
		//Computo la velocidad en y
		//Computo la posición en x
		//Computo la posición en y
		//La coordenada x deberá estar siempre entre 0 y VENTANA_ANCHO , si sobrepasara estos valores deberá reaparecer del otro lado.
		if(posicion_en_x > VENTANA_ANCHO)
			posicion_en_x = 0;

		if(posicion_en_x < 0)
			posicion_en_x = VENTANA_ANCHO;

		//IMPRIMO LEYENDAS.

		//Mientras x cosa se jugarán “partidas” del juego.
		//Verifico x cosa. inicia una nueva partida?
		if()
		{
			dormir = 3000;

			//Reinicio la nave en su posicion y angulo inicial.
		}
		// END código del alumno

        SDL_RenderPresent(renderer);
		ticks = SDL_GetTicks() - ticks;
		if(dormir)
		{
			SDL_Delay(dormir);
			dormir = 0;
		}
		else if(ticks < 1000 / JUEGO_FPS)
			SDL_Delay(1000 / JUEGO_FPS - ticks);
		ticks = SDL_GetTicks();
	}

	// BEGIN código del alumno
	//Aca destruyo
	// END código del alumno

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

	SDL_Quit();
	return 0;
}
