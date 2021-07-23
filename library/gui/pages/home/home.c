#include "home.h"
#include "../global/global.h"

void create_home_page()
{
    GtkWidget *window, *homepagebox;
    GtkBuilder *homebuilder;

    homebuilder = gtk_builder_new();
    gtk_builder_add_from_file(homebuilder, "xml/homepage.xml", NULL);

    window = GTK_WIDGET(gtk_builder_get_object(homebuilder, "gtkhomepagewindow"));
    homepagebox = GTK_WIDGET(gtk_builder_get_object(homebuilder, "welcometosqlitemanagementtext"));

    /*********************check null*********************/
    checknullerror(window);
    checknullerror(homepagebox);
    /*********************check null*********************/

    GtkCssProvider *cssProvider = gtk_css_provider_new();
    if(cssProvider == NULL) g_error("Bye Css"); 
    gtk_css_provider_load_from_path(cssProvider, "xml/css/homepage.css", NULL);
    gtk_style_context_add_provider_for_screen(gdk_screen_get_default(),
                               GTK_STYLE_PROVIDER(cssProvider),
                               GTK_STYLE_PROVIDER_PRIORITY_USER);

    sqlitemgt_set_global_gui_settings(window, "home");

    gtk_widget_show(window);
}