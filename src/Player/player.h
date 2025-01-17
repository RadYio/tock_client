/**
 * \file Player.h
 * \brief gestion des joueurs
 * \author LE GLEAU Yoann
 * \date 23/02/2022
 * \version 1
 */

#ifndef TOCK_CLIENT_PLAYER_H
#define TOCK_CLIENT_PLAYER_H


#include "../linkedlist.h"
#include "../card.h"

/**
 * \brief structure represante un joueur
 */

typedef struct Player Player;
struct Player {
    /** \brief Id unique d'un joueur */
    int idPlayer;

    /** \brief nombre de pion que le joueur a reusit a meter dans l'arriver */
    int nbPionRantrer; //TODO trouver un meilleur nom

    /** \brief liste de carte representent la main du joueur */
    Linkedlist * cards;

    enum Card (* play)(Player * p);
};

Player * playerFactory( int id);

void drawPlayer(const Player *player);

bool play(Player *p);


#endif //TOCK_CLIENT_PLAYER_H
