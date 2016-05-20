#include <stdlib.h>
#include "file.h"

struct file_s
{
    char * text;
};


file_t * file_new(char * FileText)
{
    file_t * file = malloc(sizeof(struct file_s));
    if(file == NULL)
        return NULL;
    file->text = malloc(sizeof(char) * strlen(FileText));
    strcpy(file->text, FileText);
    return file;
}

void file_process(file_t * fself, dictionary_t * dself)
{
    dict_write(dself, fself->text);
    //free(fself);
}

void print_file(file_t * fself)
{
    printf("%s\n", fself->text);
}

void file_free(file_t * self)
{
    free(self->text);
    free(self);
}
