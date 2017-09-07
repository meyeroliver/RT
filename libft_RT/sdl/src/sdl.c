/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpillay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 08:22:05 by dpillay           #+#    #+#             */
/*   Updated: 2017/09/07 11:09:39 by dpillay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <SDL2/SDL.h>

//typedef struct
//{
//	int		x;
//	int		y;
//	char		*name;
//	unsigned char	life;
//}test;

int draw_vertical_line(SDL_Renderer *ren, int x1, int x2, int y)
{
	int i;

	i = 0;
	while(x1 < x2)
		i += SDL_RenderDrawPoint(ren, x1++, y);
	while(x2 < x1)
		i += SDL_RenderDrawPoint(ren, x2++, y);
	return (i == 0);
}
int main(int argc, char **argv)
{
	SDL_Window *window;
	SDL_Renderer *renderer;
	static const int width =  1040;
	static const int height = 1000;
	int x;
	int y;

	SDL_Init(SDL_INIT_VIDEO);

	window = SDL_CreateWindow("RT", SDL_WINDOWPOS_UNDEFINED, 
			SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_OPENGL);

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | 
			SDL_RENDERER_PRESENTVSYNC);
	bool running = true;
	SDL_Event event;
	while (running)
	{
		while(SDL_PollEvent(&event))
		{
			SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
			SDL_RenderClear(renderer);
			SDL_SetRenderDrawColor(renderer, 0, 0, 250, 255);
			draw_vertical_line(renderer, 320, 240, x);
			if (event.type == SDL_QUIT)
			{
				running = false;
			}
		}

		SDL_RenderClear(renderer);
		SDL_RenderPresent(renderer);
	}
	SDL_DestroyWindow(window);
	SDL_Quit();
	return (0);
}

