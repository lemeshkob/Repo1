#include <stdlib.h>
#include <stdio.h>
#include "videoPlayer.h"
struct videoPlayer_s {
    film_t * arr[10];
    int state;
};
struct film_s{
    char name[100];
    int index;
};

videoPlayer_t * player_initialized(){

    videoPlayer_t *  player = malloc(sizeof(struct videoPlayer_s));

    if(player==NULL){
        player->state = STATUS_NOT_INITIALIZED;
        return;
    }

    for(int i = 0; i < 10; i++){
        player->arr[i] = player_addNewFilm("",-1);
    }

    player->state= STATUS_STOPPED;
    return player;
}

film_t * player_addNewFilm(char filmName[100],int filmID)
{
    film_t * film = malloc(sizeof(struct film_s));

    if(film == NULL){
        return;
    }

    film->index = filmID;
    strcpy(film->name,filmName);
    return film;
}

void player_free(videoPlayer_t * player){
    free(player);
}

void player_printFilm(film_t * film){
    printf("%-15s %-10i\n",film->name,film->index);
}

int player_getState(videoPlayer_t * player){
    return player->state;
}
/*
void player_addFilmToList(film_t * film, list_t * list, int filmID){
    list->array[filmID] = film;
}
*/
