#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sqlite3.h>

int main(void) {
    sqlite3 * db = NULL;
    int rc = 0;
    const char * dbFile = "test.db";

    rc = sqlite3_open(dbFile, &db); // open connection to DB
    if (SQLITE_OK != rc) {
        printf("Can't open file `%s`\n", dbFile);
        return 1;
    }

    printf("OK: Database connection established!");
    sqlite3_close(db);  // close connection to DB
    return 0;
}
