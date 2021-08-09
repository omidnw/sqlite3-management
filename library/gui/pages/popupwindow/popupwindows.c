#include "popupwindows.h"

gboolean sqlitemgt_is_database_open();

void on_menu_open(GtkWindow *menuitem,
                  gpointer user_data)
{
   g_message("open menu clicked!");
   GtkWidget *fileChooser;
   /****************File Chooser***************/
   GtkFileChooserAction action = GTK_FILE_CHOOSER_ACTION_OPEN;
   gint res;

   fileChooser = gtk_file_chooser_dialog_new("Open File",
                                             NULL,
                                             action,
                                             ("_Cancel"),
                                             GTK_RESPONSE_CANCEL,
                                             ("_Open"),
                                             GTK_RESPONSE_ACCEPT,
                                             NULL);

   res = gtk_dialog_run(GTK_DIALOG(fileChooser));
   if (res == GTK_RESPONSE_ACCEPT)
   {
      char *filename;
      GtkFileChooser *chooser = GTK_FILE_CHOOSER(fileChooser);
      filename = gtk_file_chooser_get_filename(chooser);
      sqlitemgt_is_database_open(filename);

      g_free(filename);
   }

   gtk_widget_destroy(fileChooser);
   /****************File Chooser***************/
}

/*********************create table*********************/
void create_table_popupwindow(){
    GtkWidget *window;
    GtkBuilder *createtablebuilder;

    createtablebuilder = gtk_builder_new();
    gtk_builder_add_from_file(createtablebuilder, "xml/createtable.xml", NULL);

    window = GTK_WIDGET(gtk_builder_get_object(createtablebuilder, "createtablewindow"));

    gtk_widget_show_all(window);
}
/*********************create table*********************/

/*********************delete table*********************/
void delete_table_popupwindow(){
    GtkWidget *window;
    GtkBuilder *createtablebuilder;

    createtablebuilder = gtk_builder_new();
    gtk_builder_add_from_file(createtablebuilder, "xml/deletetable.xml", NULL);

    window = GTK_WIDGET(gtk_builder_get_object(createtablebuilder, "deletetablewindow"));

    gtk_widget_show_all(window);
}
/*********************delete table*********************/

/*********************insert value*********************/
void insert_value_popupwindow(){
    GtkWidget *window;
    GtkBuilder *createtablebuilder;

    createtablebuilder = gtk_builder_new();
    gtk_builder_add_from_file(createtablebuilder, "xml/insertvalue.xml", NULL);

    window = GTK_WIDGET(gtk_builder_get_object(createtablebuilder, "insertvaluewindow"));

    gtk_widget_show_all(window);
}
/*********************insert value*********************/

/*********************delete value*********************/
void delete_value_popupwindow(){
    GtkWidget *window;
    GtkBuilder *createtablebuilder;

    createtablebuilder = gtk_builder_new();
    gtk_builder_add_from_file(createtablebuilder, "xml/deletevalue.xml", NULL);

    window = GTK_WIDGET(gtk_builder_get_object(createtablebuilder, "deletevaluewindow"));

    gtk_widget_show_all(window);
}
/*********************delete value*********************/

void edit_menu_create_table(GtkMenuItem *item)
{
    g_message("edit menu create table clicked!");
   if (!sqlitemgt_is_database_open()) {
      on_menu_open(NULL, NULL);
      create_table_popupwindow();
   }
   else{
      create_table_popupwindow();
   }
}

void edit_menu_delete_table(GtkMenuItem *item)
{
    g_message("edit menu create table clicked!");
   if (!sqlitemgt_is_database_open()) {
      on_menu_open(NULL, NULL);
      delete_table_popupwindow();
   }
   else{
      delete_table_popupwindow();
   }
}

void edit_menu_insert_value(GtkMenuItem *item)
{
    g_message("edit menu create table clicked!");
   if (!sqlitemgt_is_database_open()) {
      on_menu_open(NULL, NULL);
      insert_value_popupwindow();
   }
   else{
      insert_value_popupwindow();
   }
}

void edit_menu_delete_value(GtkMenuItem *item)
{
    g_message("edit menu create table clicked!");
   if (!sqlitemgt_is_database_open()) {
      on_menu_open(NULL, NULL);
      delete_value_popupwindow();
   }
   else{
      delete_value_popupwindow();
   }
}