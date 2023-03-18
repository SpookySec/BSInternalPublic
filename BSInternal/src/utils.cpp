#include "../hdr/utils.h"

FILE* CreateConsole()
{
    FILE* fp;

    AllocConsole();
    freopen_s(&fp, "CONOUT$", "w", stdout);
    return fp;
}