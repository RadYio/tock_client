/**
 * \file mainSDL.c
 * \author LE GLEAU yoann
 * \date 20/01/2022
 */

#include <stdio.h>
#include <SDL2/SDL_ttf.h>
#include "mainSDL.h"

/**
 * \var window
 * \brief pointeur vers la fenêtre principal
 */
SDL_Window *window = NULL;

/**
 * \brief singleton de l'écran principal
 * \return pointeur vers l'écran principal
 */
SDL_Window * getWindow(){
    //TOTEST
    if(window == NULL)
        winCreate();
    return window;
}

/**
 * \brief Crée la fenêtre principal avec les caractéristique par default et initialisation des libraires graphiques SDL2 et SDL_TTF
 * \private
 */
void winCreate() {

    SDL_Init(SDL_INIT_VIDEO); // Initialise SDL2
    TTF_Init(); // Initialise SDL2_TTF


    // Créez la fenêtre de l'application avec les paramètres suivants :
    window = SDL_CreateWindow(
            "Tock.io",                  // window title
            SDL_WINDOWPOS_UNDEFINED,           // initial x position
            SDL_WINDOWPOS_UNDEFINED,           // initial y position
            640,                               // width, in pixels
            480,                               // height, in pixels
            SDL_WINDOW_SHOWN|SDL_WINDOW_RESIZABLE|SDL_WINDOW_OPENGL // flags - see below
    );

    // Vérifiez que la fenêtre a bien été créé
    if (window == NULL) {
        // Dans le cas où la fenêtre ne pourrait pas être créé...
        printf("Could not create window: %s\n", SDL_GetError());
    }
}

/**
 * \brief Ferme la fenêtre principal et fermeture des libraires graphiques SDL2 et SDL_TTF
 * \warning Penser a bien fermer les polices avent d'utiliser cette fonction
 */
void winDestroy() {
    // ferme la fenêtre principal
    SDL_DestroyWindow(window);

    // fermeture des libraires graphiques SDL2 et SDL_TTF
    TTF_Quit();
    SDL_Quit();
}
