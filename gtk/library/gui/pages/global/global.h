#ifndef SQLITE3MGT_GUI_GLOBAL_SETTINGS_H
#define SQLITE3MGT_GUI_GLOBAL_SETTINGS_H

#include <gtk/gtk.h>

void checknullerror(GtkWidget *g_widget);
void sqlitemgt_set_global_gui_settings(GtkWidget *window, gchar *namepage);
void css_set(GtkCssProvider *cssProvider, GtkWidget *g_widget);

#endif