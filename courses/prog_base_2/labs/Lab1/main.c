#include <stdlib.h>  // !
#include <stdarg.h>  // !
#include <stddef.h>  // !
#include <setjmp.h>  // !

#include <cmocka.h>
#include <stdio.h>
#include <stdlib.h>
#include "file.h"
#include "folder.h"

static void new_folder_files_zeroCount(void ** state)
{
    folder_t * myFolder = folder_new("Folder");
    assert_int_equal(folder_get_files_count(myFolder), 0);
    folder_free(myFolder);
}

static void folder_add_new_file_filesCount_oneCount(void **state)
{
    dictionary_t * dictionary = dictionary_new();
    folder_t * myFolder = folder_new("Folder");
    file_t * FirstFile = folder_add_new_file(myFolder, "This file is empty");
    assert_int_equal(folder_get_files_count(myFolder), 1);
    folder_process_and_remove_files(myFolder, FirstFile, dictionary);
    assert_int_equal(folder_get_files_count(myFolder), 0);
    folder_free(myFolder);
}

static void folder_add_new_file_filesCount_threeCount(void **state)
{
    dictionary_t * dictionary = dictionary_new();
    folder_t * myFolder = folder_new("Folder");
    file_t * FirstFile = folder_add_new_file(myFolder, "This file is not empty");
    file_t * SecondFile = folder_add_new_file(myFolder, "This file is not empty");
    file_t * ThirdFile = folder_add_new_file(myFolder, "This file is not empty");
    assert_int_equal(folder_get_files_count(myFolder), 3);
    folder_process_and_remove_files(myFolder, FirstFile, dictionary);
    folder_process_and_remove_files(myFolder, SecondFile, dictionary);
    folder_process_and_remove_files(myFolder, ThirdFile, dictionary);
    assert_int_equal(folder_get_files_count(myFolder), 0);
    folder_free(myFolder);
}

static void new_dictionary_wordsCount_zerowords(void ** state)
{
    dictionary_t * dictionary = dictionary_new();
    assert_int_equal(dict_get_wordscount(dictionary), 0);
    dict_free(dictionary);
}

static void process_and_remove_file_wordscount_in_dictionary_fivewords(void ** state)
{
    dictionary_t * dictionary = dictionary_new();
    folder_t * myFolder = folder_Ñnew("Folder");
    file_t * FirstFile = folder_add_new_file(myFolder, "This file is not empty");
    folder_process_and_remove_files(myFolder, FirstFile, dictionary);
    assert_int_equal(dict_get_wordscount(dictionary), 5);
    dict_free(dictionary);
    folder_free(myFolder);
}

static void process_and_remove_file_filesCount_zeroCount(void ** state)
{
    dictionary_t * dictionary = dictionary_new();
    folder_t * myFolder = folder_new("Folder");
    file_t * FirstFile = folder_add_new_file(myFolder, "a b c d e r t y u w v n m l p");
    folder_process_and_remove_files(myFolder, FirstFile, dictionary);
    assert_int_equal(folder_get_files_count(myFolder), 0);
    dict_free(dictionary);
    folder_free(myFolder);
}

static void process_and_remove_file_wordscount_in_dictionary_fifteenwords(void ** state)
{
    dictionary_t * dictionary = dictionary_new();
    folder_t * myFolder = folder_new("Folder");
    file_t * FirstFile = folder_add_new_file(myFolder, "a b c d e r t y u w v n m l p");
    folder_process_and_remove_files(myFolder, FirstFile, dictionary);
    assert_int_equal(dict_get_wordscount(dictionary), 15);
    dict_free(dictionary);
    folder_free(myFolder);
}

static void process_and_remove_file_wordscount_in_dictionary_fivewords_and_one_word_passing_two_times(void ** state)
{
    dictionary_t * dictionary = dictionary_new();
    folder_t * myFolder = folder_new("Folder");
    file_t * FirstFile = folder_add_new_file(myFolder, "This file file is empty");
    folder_process_and_remove_files(myFolder, FirstFile, dictionary);
    assert_int_equal(dic_get_wordcount(dictionary, "file"), 2);
    assert_int_equal(dict_get_wordscount(dictionary), 4);
    dict_free(dictionary);
    folder_free(myFolder);
}



int main(void)
{
    const struct CMUnitTest tests[] =
    {
        cmocka_unit_test(new_folder_files_zeroCount),
        cmocka_unit_test(folder_add_new_file_filesCount_oneCount),
        cmocka_unit_test(folder_add_new_file_filesCount_threeCount),
        cmocka_unit_test(new_dictionary_wordsCount_zerowords),
        cmocka_unit_test(process_and_remove_file_wordscount_in_dictionary_fivewords),
        cmocka_unit_test(process_and_remove_file_wordscount_in_dictionary_fivewords_and_one_word_passing_two_times),
        cmocka_unit_test(process_and_remove_file_wordscount_in_dictionary_fifteenwords),
        cmocka_unit_test(process_and_remove_file_filesCount_zeroCount),
    };

    return cmocka_run_group_tests(tests, NULL, NULL);

}
