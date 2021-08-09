#include "popupwindows.h"

gboolean sqlitemgt_is_database_open();
void checknullerror(GtkWidget *g_widget);
void sqlitemgt_open_database_with_path(gchar *gdatabasename);


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
      sqlitemgt_open_database_with_path(filename);

      g_free(filename);
   }

   gtk_widget_destroy(fileChooser);
   /****************File Chooser***************/
}

void on_menu_save(GtkWindow *menuitem,
                  gpointer user_data)
{
   g_message("save menu clicked!");
   GtkWidget *fileChooser;
   /****************File Chooser***************/
   GtkFileFilter *filter;
   GtkFileChooserAction action = GTK_FILE_CHOOSER_ACTION_SAVE;
   gint res;

   fileChooser = gtk_file_chooser_dialog_new("Save File",
                                             NULL,
                                             action,
                                             ("_Cancel"),
                                             GTK_RESPONSE_CANCEL,
                                             ("_Save"),
                                             GTK_RESPONSE_ACCEPT,
                                             NULL);

   filter = gtk_file_filter_new(); // filter 1
   gtk_file_filter_set_name(filter, "DataBase File");
   gtk_file_filter_add_pattern(filter, ".db");
   gtk_file_chooser_add_filter(GTK_FILE_CHOOSER(fileChooser), filter);

   res = gtk_dialog_run(GTK_DIALOG(fileChooser));
   if (res == GTK_RESPONSE_ACCEPT)
   {
      char *filename;
      GtkFileChooser *chooser = GTK_FILE_CHOOSER(fileChooser);
      filename = gtk_file_chooser_get_filename(chooser);
      sqlitemgt_open_database_with_path(filename);

      g_free(filename);
   }

   gtk_widget_destroy(fileChooser);
   /****************File Chooser***************/
}

/*********************create table*********************/

void clicked_create_table_popupwindow(createtable, builder)
GtkWidget *createtable;
GtkBuilder *builder;
{
   GtkWidget *tablename, *columnsname;
   const gchar *gtablename, *gcolumnsname;
   tablename = GTK_WIDGET(gtk_builder_get_object(builder, "tablename"));
   columnsname = GTK_WIDGET(gtk_builder_get_object(builder, "columnsname"));
   checknullerror(tablename);
   checknullerror(columnsname);
   gtablename = gtk_entry_get_text(GTK_ENTRY(tablename));
   gcolumnsname = gtk_entry_get_text(GTK_ENTRY(columnsname));
   sqlitemgt_create_table(gtablename, gcolumnsname);
   g_warning("CreateTable | %s %s.", gtablename, gcolumnsname);
}

void create_table_popupwindow(){

   GtkWidget *window, *createtablebutton;
   GtkBuilder *createtablebuilder;

   createtablebuilder = gtk_builder_new();
   gtk_builder_add_from_file(createtablebuilder, "xml/createtable.xml", NULL);

   window = GTK_WIDGET(gtk_builder_get_object(createtablebuilder, "createtablewindow"));
   createtablebutton = GTK_WIDGET(gtk_builder_get_object(createtablebuilder, "createtablebutton"));

   g_signal_connect(G_OBJECT(createtablebutton), "clicked", G_CALLBACK(clicked_create_table_popupwindow), createtablebuilder);

   gtk_widget_show_all(window);
}
/*********************create table*********************/

/*********************delete table*********************/
void delete_table_popupwindow(){

   GtkWidget *window;
   GtkBuilder *builder;

    builder = gtk_builder_new();
    gtk_builder_add_from_file(builder, "xml/deletetable.xml", NULL);

    window = GTK_WIDGET(gtk_builder_get_object(builder, "deletetablewindow"));

    gtk_widget_show_all(window);
}
/*********************delete table*********************/

/*********************insert value*********************/
void insert_value_popupwindow(){

   GtkWidget *window;
   GtkBuilder *builder;

    builder = gtk_builder_new();
    gtk_builder_add_from_file(builder, "xml/insertvalue.xml", NULL);

    window = GTK_WIDGET(gtk_builder_get_object(builder, "insertvaluewindow"));

    gtk_widget_show_all(window);
}
/*********************insert value*********************/

/*********************delete value*********************/
void delete_value_popupwindow(){

   GtkWidget *window;
   GtkBuilder *builder;

    builder = gtk_builder_new();
    gtk_builder_add_from_file(builder, "xml/deletevalue.xml", NULL);

    window = GTK_WIDGET(gtk_builder_get_object(builder, "deletevaluewindow"));

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