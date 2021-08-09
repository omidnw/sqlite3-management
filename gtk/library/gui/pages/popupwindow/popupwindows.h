#ifndef SQLITEMGT_GUI_POPUPWINDOWS
#define SQLITEMGT_GUI_POPUPWINDOWS

#include <gtk/gtk.h>
#include <glib/gstdio.h>
#include"../../../sqlite3mgt/sqlite3mgt.h"

void on_menu_save(GtkWindow *menuitem, gpointer user_data);
void edit_menu_create_table();
void edit_menu_delete_table();
void edit_menu_insert_value();
void edit_menu_delete_value();

#endif