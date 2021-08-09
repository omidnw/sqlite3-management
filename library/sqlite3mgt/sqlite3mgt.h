#ifndef SQLITE3MGT_H
#define SQLITE3MGT_H

#include <stdio.h>
#include <gtk/gtk.h>
#include "../sqlite3/sqlite3.h"

void sqlitemgt_open_database_with_path(gchar *gdatabasename);
void sqlitemgt_create_table(const gchar *tablename, const gchar *columnnames);
void sqlitemgt_delete_table(gchar *tablename);
void sqlitemgt_insert_value_to_table(gchar *tablename, gchar *columnnames, gchar *value);
void sqlitemgt_delete_value_from_table(gchar *tablename, gchar *columnname, gchar *value);
gboolean sqlitemgt_is_database_open();

#endif