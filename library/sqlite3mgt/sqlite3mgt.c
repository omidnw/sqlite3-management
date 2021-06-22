#include "sqlite3mgt.h"

sqlite3 *db;
char sqlarray[255], *err_msg = 0;
int rc;

void open_sqlite_database_with_path(gdatabasename)
gchar *gdatabasename;
{
    if (databasename == NULL) {
        databasename = malloc(512 * sizeof(gchar));
    }
    strcpy(databasename, gdatabasename);
    rc = sqlite3_open(gdatabasename, &db);
    if (rc != SQLITE_OK){
        g_warning("database not found!");
    }
    else{
        g_print("database successfuly opened or create.");
        sqlite3_close(db);
    }
}

void sqlite_create_table(tablename, columnnames)
gchar *tablename, *columnnames;
{
    if (databasename == NULL){
        g_warning("database name empty please try again!");
    }
    else{
        sqlite3_open(databasename, &db);
    
        snprintf(sqlarray, sizeof(sqlarray), "CREATE TABLE %s(%s);", tablename, columnnames);
        g_print("database address: %s | sql query: %s", databasename, sqlarray);
        rc = sqlite3_exec(db, sqlarray, 0, 0, &err_msg);
        if(rc != SQLITE_OK)
        {
            g_warning("%s", err_msg);
            sqlite3_free(err_msg);
            sqlite3_close(db);
        }
        else
        {
            g_print("table successfuly created.");
            sqlite3_close(db);
        }
    }
}

void sqlite_delete_table(tablename)
gchar *tablename;
{
    if (databasename == NULL){
        g_warning("database name empty please try again!");
    }
    else{
        sqlite3_open(databasename, &db);
    
        snprintf(sqlarray, sizeof(sqlarray), "DROP TABLE IF EXISTS %s;", tablename);
        g_print("database address: %s | sql query: %s", databasename, sqlarray);
        rc = sqlite3_exec(db, sqlarray, 0, 0, &err_msg);
        if(rc != SQLITE_OK)
        {
            g_warning("%s", err_msg);
            sqlite3_free(err_msg);
            sqlite3_close(db);
        }
        else
        {
            g_print("table successfuly created.");
            sqlite3_close(db);
        }
    }
}

void sqlite_insert_value_to_table(tablename, columnnames, value)
gchar *tablename, *columnnames, *value;
{
    if (databasename == NULL){
        g_warning("database name empty please try again!");
    }
    else{
        sqlite3_open(databasename, &db);
    
        snprintf(sqlarray, sizeof(sqlarray), "INSERT INTO %s(%s) VALUES(%s);", tablename,
                     columnnames, value);
        g_print("database address: %s | sql query: %s", databasename, sqlarray);
        rc = sqlite3_exec(db, sqlarray, 0, 0, &err_msg);
        if(rc != SQLITE_OK)
        {
            g_warning("%s", err_msg);
            sqlite3_free(err_msg);
            sqlite3_close(db);
        }
        else
        {
            g_print("insert value to table successfuly.");
            sqlite3_close(db);
        }
    }
}