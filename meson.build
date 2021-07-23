project('sqlite3management', 'c')
gtkdep = dependency('gtk+-3.0')
executable('sqlite3mgt', files('main.c',
            'library/gui/pages/pages.c',
            'library/gui/pages/global/global.c',
            'library/gui/pages/home/home.c',
            'library/gui/pages/popupwindow/createtable/createtable.c',
            'library/gui/pages/popupwindow/deletetable/deletetable.c',
            'library/sqlite3/sqlite3.c',
            'library/sqlite3mgt/sqlite3mgt.c',
            'library/gui/pages/getosinfo/getosinfo.c'),
            dependencies: [gtkdep], link_args: ['-pthread','-ldl','-std=c99',])