/**
 * \file mainSDL.c
 * \brief gestion de la fenetre principale
 * \author JARRIER Allan
 * \date 20/01/2022
 * \version 1
 */

#include <SDL2/SDL.h>
#include <stdbool.h>

#ifndef TOCK_CLIENT_MAINSDL_H
#define TOCK_CLIENT_MAINSDL_H

SDL_Window *window;

void winCreate();
void winDestroy();
SDL_Window * getWindow();

void drawCircle(SDL_Renderer *renderer, int x, int y, int radius, SDL_Color color);
void drawCircleBorder(SDL_Renderer *renderer, int x, int y, int radius, SDL_Color colorOut, int width , SDL_Color colorIn);
bool playCard(enum Card * card,int location);

#endif //TOCK_CLIENT_MAINSDL_H