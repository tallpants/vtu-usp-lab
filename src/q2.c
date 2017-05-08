/*
 * Write a C/C++ POSIX compliant program that prints the POSIX defined configuration
 * options supported on any given system using feature test macros
 */

/*
 * _POSIX feature test macros are defined in <unistd.h>
 */

#include <stdio.h>
#include <unistd.h>

int main(void) {

#ifdef _POSIX_JOB_CONTROL
    printf("\n_POSIX_JOB_CONTROL: Job control is supported");
#else
    printf("\n_POSIX_JOB_CONTROL: Job control is not supported.");
#endif

#ifdef _POSIX_SAVED_IDS
    printf("\n_POSIX_SAVED_IDS: Processes have a saved set-user-ID and a saved set-group-ID.");
#else
    printf("\n_POSIX_SAVED_IDS: Processes do not have a saved set-user-ID and a saved set-group-ID");
#endif

#ifdef _POSIX_CHOWN_RESTRICTED
    printf("\n_POSIX_CHOWN_RESTRICTED: Value is %d", _POSIX_CHOWN_RESTRICTED);
#else
    printf("\n_POSIX_CHOWN_RESTRICTED: Option is not in effect.");
#endif

#ifdef _POSIX_NO_TRUNC
    printf("\n_POSIX_NO_TRUNC: Filenames are not silently truncated.");
#else
    printf("\n_POSIX_NO_TRUNC: Filenames can be silently truncated.");
#endif

#ifdef _POSIX_VDISABLE
    printf("\n_POSIX_VDISABLE: The virtual disabling character for terminal files is defined %c\n", _POSIX_VDISABLE);
#else
    printf("\n_POSIX_VDISABLE: Not defined.");
#endif

    return 0;
}
