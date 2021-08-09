#include "getosinfo.h"

struct utsname getosinfodata;

char *get_operation_system_information(condition) int condition;
{
        uname(&getosinfodata);

        if (condition == GETOSINFO_SYSNAME)
        {
                return getosinfodata.sysname;
        }
        else if (condition == GETOSINFO_NODENAME)
        {
                return getosinfodata.nodename;
        }
        else if (condition == GETOSINFO_RELEASE)
        {
                return getosinfodata.release;
        }
        else if (condition == GETOSINFO_VERSION)
        {
                return getosinfodata.version;
        }
        else if (condition == GETOSINFO_MACHINE)
        {
                return getosinfodata.machine;
        }
#ifdef __USE_GNU
        else if (condition == GETOSINFO_GNU_DOMAINNAME)
        {
                return getosinfodata.__domainname;
        }
#else
        else if (condition == GETOSINFO_GNU_DOMAINNAME)
        {
                return getosinfodata.__domainname;
        }
#endif
        else if (GETOSINFO_JUST_OS_NAME)
        {
        }
        else
        {
                return NULL;
        }
        return NULL;
}