#ifndef VIDEO_PLAYER_H
#define VIDEO_PLAYER_H

#define PLAYER_MAX_SIZE
#define STATUS_NOT_INITIALIZED 0
#define STATUS_INITIALIZED 1
#define STATUS_STOPPED 2
#define STATUS_PAUSED 3
#define STATUS_PLAYING 4

typedef struct videoPlayer_s videoPlayer_t;
typedef struct film_s film_t;

videoPlayer_t * player_initialized();
film_t * player_addNewFilm(char filmName[100],int filmID);
void player_printFilm(film_t * film);
void player_free(videoPlayer_t * player);
void film_free(film_t * film);
int player_getState(videoPlayer_t * player);




#endif // VIDEO_PLAYER_H
