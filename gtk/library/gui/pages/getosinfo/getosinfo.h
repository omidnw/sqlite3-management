#ifndef ADERINAAI_GETOSINFO_H
#define ADERINAAI_GETOSINFO_H

#include <stdio.h>
#include <string.h>

#ifdef _WIN32
#include <windows.h>
#endif
#ifdef __UNIX__
#endif
#ifdef __linux__
#include <sys/utsname.h>
#endif

#define GETOSINFO_SYSNAME 0
#define GETOSINFO_NODENAME 1
#define GETOSINFO_RELEASE 2
#define GETOSINFO_VERSION 3
#define GETOSINFO_MACHINE 4
#define GETOSINFO_GNU_DOMAINNAME 5
#define GETOSINFO_JUST_OS_NAME 6

char* get_operation_system_information(int condition);

#endif