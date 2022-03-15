/**
 * \file Player.c
 * \brief gestion des joueurs
 * \author LE GLEAU Yoann
 * \date 23/02/2022
 * \version 1
 */

#include <stdio.h>
#include <malloc.h>
#include "player.h"
#include "../mainSDL.h"





Player * playerFactory( int id){
    Player * player = malloc(sizeof(Player));
    player->idPlayer = id;
    player->nbPionRantrer = 0;
    player->cards = linkedListFactory(sizeof(enum Card));
    player->pt = &play;
    return player;
}

void drawPlayer(const Player *player) {
    printf("player %i: a renter %i pions\n Cartes:%i\n",player->idPlayer,player->nbPionRantrer,length(player->cards));
    drawListe(player->cards,drawCard);
}

int play(Player *p, Bord * bord) {
        Linkedlist * pownsLocations = getPlayerPansLocation(bord, p->idPlayer);
        bool played = false;
        if (!isEmpty(pownsLocations))
            for (int j = 0; j <= length(p->cards); j++) {
                played = playCard(bord, get(p->cards,j), (int)getFirst(pownsLocations));
                if(played){
                    printf("player %i a jouer ",p->idPlayer);
                    drawCard(get(p->cards,j));
                    removeElem(p->cards,j);
                    return true;
                }
            }
        if (!played && !isEmpty(p->cards)){
            printf("player %i a jeter ",p->idPlayer);
            drawCard(getFirst(p->cards));
            pollFirst(p->cards);

        }
        return false;
    }
