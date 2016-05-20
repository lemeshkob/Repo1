#include <stdlib.h>
#include <string.h>
#include "dictionary.h"

struct words_s
{
    char * word;
    int count;
};

struct dictionary_s
{
    int wordscount;
    int max_size;
    struct words_s * words;
};

dictionary_t * dictionary_new(void)
{
    dictionary_t * self = NULL;
    self = malloc(sizeof(struct dictionary_s));
    self->max_size = 10;
    self->words = malloc(sizeof(struct words_s) * 10);
    self->wordscount = 0;
    return self;
}

void dict_free(dictionary_t * self)
{
    for (int i = 0; i < self->wordscount; i++)
        free(self->words[i].word);
    free(self->words);
    free(self);
}

void dict_double_size(dictionary_t * dict)
{
    struct words_s * tmparr = malloc(sizeof(struct words_s) * dict->max_size);
    for (int i = 0; i < dict->max_size; i++)
        tmparr[i] = dict->words[i];
    free(dict->words);
    dict->max_size *= 2;
    dict->words = malloc(sizeof(struct words_s) * dict->max_size);
    for (int i = 0; i < dict->max_size / 2; i++)
        dict->words[i] = tmparr[i];
    free(tmparr);
}

void word_add(dictionary_t * dict, char * word)
{
    if (word == NULL)
        return;
    for (int i = 0; i < dict->wordscount; i++)
        if (strcmp(dict->words[i].word, word) == 0)
        {
            dict->words[i].count++;
            return;
        }
    if (dict->max_size <= dict->wordscount)
        dict_double_size(dict);
    dict->words[dict->wordscount].word = malloc(sizeof(char) * strlen(word));
    strcpy(dict->words[dict->wordscount].word, word);
    dict->words[dict->wordscount++].count = 1;
}
void dict_write(dictionary_t * self, char * text)
{
    char * tmpstr = malloc(sizeof(char) * strlen(text));
    for (int i = 0; i < strlen(text); i++)
    {
        if ((text[i] < 'a' || text[i] > 'z') && (text[i] < 'A' || text[i] > 'Z'))
            tmpstr[i] = ' ';
        else
            tmpstr[i] = text[i];
    }

    char * word = strtok(tmpstr, " ");
    while (word != NULL)
    {
        word_add(self, word);
        do
        {
            word = strtok(NULL, " ");
            if (word == NULL)
                break;
        }while(strlen(word) == 0 );


    }
    free(tmpstr);
}

void dict_print(dictionary_t * self)
{
    for(int i = 0; i < self->wordscount; i++)
    {
        printf("%i ", self->words[i].count);
        printf("%s", self->words[i].word);
        printf("\n");
    }
}

int dict_get_wordscount(dictionary_t * self)
{
    return self->wordscount;
}

int dic_get_wordcount(dictionary_t * self, char word[])
{
    for(int i = 0; i < self->wordscount; i ++)
    {
        if(strcmp(self->words[i].word, word) == 0)
            return self->words[i].count;
    }
    return 0;
}
