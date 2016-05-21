#include <stdio.h>
#include <stdlib.h>
#include "videoPlayer.h"

int main(void){
    videoPlayer_t * player = player_initialized();
    film_t * film1 = player_addNewFilm("Holly",0);
    film_t * film2 = player_addNewFilm("Cow",1);
    film_t * film3 = player_addNewFilm("It so difficult",2);
    printf("FilmName \tid\n");
    printf("State: %i\n", player_getState(player));
    player_printFilm(film1);
    player_printFilm(film2);
    player_printFilm(film3);
    player_free(player);
}
