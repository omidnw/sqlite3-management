#include "global.h"

void checknullerror(g_widget)
GtkWidget *g_widget;
{
    if (NULL == g_widget)
    {
        g_error("stop baby! %s", gtk_widget_get_name(g_widget));
    }
}

void css_set(cssProvider, g_widget)
GtkCssProvider *cssProvider;
GtkWidget *g_widget;
{
	GtkStyleContext *context = gtk_widget_get_style_context(g_widget);
	
	gtk_style_context_add_provider(context,
                                    GTK_STYLE_PROVIDER(cssProvider),
                                    GTK_STYLE_PROVIDER_PRIORITY_USER);

    gtk_style_context_save (context);
}

void sqlitemgt_set_menu_gui_settings(window)
GtkWidget *window;
{
}
void sqlitemgt_set_statusbar_gui_settings(window)
GtkWidget *window;
{
}
void sqlitemgt_set_g_signal_global(window)
GtkWidget *window;
{
    g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);
}
void sqlitemgt_set_global_gui_settings(window ,namepage)
GtkWidget *window;
gchar *namepage;
{
    if (strcmp("home", namepage)==0){
        sqlitemgt_set_g_signal_global(window);
    }
    else{
        g_error("not found please check your code.");
    }
}