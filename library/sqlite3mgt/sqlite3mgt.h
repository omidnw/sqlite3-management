#ifndef SQLITE3MGT_H
#define SQLITE3MGT_H

#include <gtk/gtk.h>
#include "../sqlite3/sqlite3.h"

gchar *databasename;
void open_sqlite_database_with_path(gchar *gdatabasename);
void sqlite_create_table(gchar *tablename, gchar *columnnames);
void sqlite_delete_table(gchar *tablename);
void sqlite_insert_value_to_table(gchar *tablename, gchar *columnnames, gchar *value);
gboolean sqlite_is_database_open();

#endif