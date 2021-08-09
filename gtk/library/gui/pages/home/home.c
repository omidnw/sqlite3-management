#include "home.h"

void create_home_page()
{
    GtkWidget *window, *createtablefilemenu, *deletetablefilemenu, *insertvaluefilemenu, *deletevaluefilemenu, *savemenu, *quitmenu;
    GtkBuilder *homebuilder;

    homebuilder = gtk_builder_new();
    gtk_builder_add_from_file(homebuilder, "xml/homepage.xml", NULL);

    window = GTK_WIDGET(gtk_builder_get_object(homebuilder, "gtkhomepagewindow"));
    createtablefilemenu = GTK_WIDGET(gtk_builder_get_object(homebuilder, "createtablefilemenu"));
    deletetablefilemenu = GTK_WIDGET(gtk_builder_get_object(homebuilder, "deletetablefilemenu"));
    insertvaluefilemenu = GTK_WIDGET(gtk_builder_get_object(homebuilder, "insertvaluefilemenu"));
    deletevaluefilemenu = GTK_WIDGET(gtk_builder_get_object(homebuilder, "deletevaluefilemenu"));
    savemenu = GTK_WIDGET(gtk_builder_get_object(homebuilder, "save"));
    quitmenu = GTK_WIDGET(gtk_builder_get_object(homebuilder, "quit"));

    /*********************check null*********************/
    checknullerror(window);
    checknullerror(createtablefilemenu);
    checknullerror(deletetablefilemenu);
    checknullerror(insertvaluefilemenu);
    checknullerror(deletevaluefilemenu);
    /*********************check null*********************/
    g_message("create home page successfuly!");
    GtkCssProvider *cssProvider = gtk_css_provider_new();
    if(cssProvider == NULL) g_error("Bye Css"); 
    gtk_css_provider_load_from_path(cssProvider, "xml/css/homepage.css", NULL);
    gtk_style_context_add_provider_for_screen(gdk_screen_get_default(),
                               GTK_STYLE_PROVIDER(cssProvider),
                               GTK_STYLE_PROVIDER_PRIORITY_USER);

    sqlitemgt_set_global_gui_settings(window, "home");

    g_signal_connect(G_OBJECT(savemenu), "activate", G_CALLBACK(on_menu_save), NULL);
    g_signal_connect(G_OBJECT(quitmenu), "activate", G_CALLBACK(gtk_main_quit), NULL);
    g_signal_connect(G_OBJECT(createtablefilemenu), "activate", G_CALLBACK(edit_menu_create_table), NULL);
    g_signal_connect(G_OBJECT(deletetablefilemenu), "activate", G_CALLBACK(edit_menu_delete_table), NULL);
    g_signal_connect(G_OBJECT(insertvaluefilemenu), "activate", G_CALLBACK(edit_menu_insert_value), NULL);
    g_signal_connect(G_OBJECT(deletevaluefilemenu), "activate", G_CALLBACK(edit_menu_delete_value), NULL);

    gtk_widget_show(window);
}