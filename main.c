#include <gtk/gtk.h>
#include "library/gui/pages/home/home.h"

int main(int argc, char *argv[]) {

    gtk_init(&argc, &argv);

    create_home_page();

    gtk_main();

    return 0;
}