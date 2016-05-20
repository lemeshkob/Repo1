#ifndef FOLDER_H
#define FOLDER_H
#include "file.h"
#include "dictionary.h"
typedef struct folder_s folder_t;

folder_t * folder_new(char * name);
int folder_get_files_count(folder_t * self);
void folder_free(folder_t * self);
file_t * folder_add_new_file(folder_t * self, char * FileText);
void folder_process_and_remove_files(folder_t * self, file_t * fself, dictionary_t * dself);

#endif // FOLDER_H
