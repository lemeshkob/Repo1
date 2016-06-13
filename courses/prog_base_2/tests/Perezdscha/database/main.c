#include <stdio.h>
#include <stdlib.h>

#include <sqlite3.h>

int main(void)
{
    sqlite3 * db;
    int rc = 0;
    const char * databaseFile = "test.db";
    rc = sqlite3_open(databaseFile, &db);
    if(SQLITE_OK != rc)
    {
        printf("Error opening database.\n");
        exit(1);
    }

    sqlite3_stmt * stmt = NULL;
    const char * sqlDeleteTest = "DELETE FROM Students WHERE City = 'Rovno';";
    if(SQLITE_OK != sqlite3_prepare_v2(db, sqlDeleteTest, strlen(sqlDeleteTest) + 1, &stmt, NULL))
    {
        printf("Not prepared!\n");
    }
    if (SQLITE_DONE != (rc = sqlite3_step(stmt)))
    {
        printf("Not deleted! %i\n", rc);
    }
    sqlite3_finalize(stmt);



    const char * sqlScript = "INSERT INTO "
                             "Human  (Name, Surname, Patronymic, Birthdate, City, ID) "
                             "VALUES ('Olegka', 'test', 'lalala', 50, 'Krivoy Rog', 1);";

    if(SQLITE_OK != sqlite3_prepare_v2(db, sqlScript, strlen(sqlScript) + 1, &stmt, NULL))
    {
        printf("Not prepared!\n");
    }
    if (SQLITE_DONE != (rc = sqlite3_step(stmt)))
    {
        printf("Not inserted! %i\n", rc);
    }

    int last = (int) sqlite3_last_insert_rowid (db);
    printf("Last inserted row: %i\n", last);

    sqlite3_finalize(stmt);
    sqlite3_close(db);
    return 0;
}
