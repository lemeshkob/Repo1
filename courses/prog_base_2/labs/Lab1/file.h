#ifndef FILE_H
#define FILE_H
#include "dictionary.h"
typedef struct file_s file_t;

file_t * file_new(char * FileText);
void file_process(file_t * fself, dictionary_t * dself);
void print_file(file_t * fself);
void file_free(file_t * self);

#endif // FILE_H
