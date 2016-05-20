#ifndef DIC_INCLUDE
#define DIC_INCLUDE

#define MAX_TEXT_SIZE 1000

typedef struct dictionary_s dictionary_t;

dictionary_t * dictionary_new(void);

void dict_free(dictionary_t * self);
void dict_double_size(dictionary_t * dict);
void word_add(dictionary_t * dict, char * word);
void dict_write(dictionary_t * self, char * text);
void dict_print(dictionary_t * self);
int dict_get_wordscount(dictionary_t * self);
int dic_get_wordcount(dictionary_t * self, char word[]);

#endif
