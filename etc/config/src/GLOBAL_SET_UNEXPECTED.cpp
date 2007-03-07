// checking for ::set_unexpected()

#include "config.h"

#ifdef _RWSTD_NO_EXCEPTION_SPECIFICATION

#  define throw()

#endif   // _RWSTD_NO_EXCEPTION_SPECIFICATION

typedef void (*unexpected_handler)();

// looking for a definition in compiler support library
unexpected_handler set_unexpected (unexpected_handler) throw ();


void handler () { }

int main (int argc, char *argv[])
{
    if (argc > 1) {
        unexpected_handler save = set_unexpected (handler);

        return save == handler;
    }

    return 0;
}
