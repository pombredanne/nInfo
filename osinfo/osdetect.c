/*
 * osinfo (part of the nInfo suite)
 * Copyright (C) 2012 Frank "SeySayux" Erens <seysayux@gmail.com>
 *
 * This software is provided 'as-is', without any express or implied
 * warranty. In no event will the authors be held liable for any damages
 * arising from the use of this software.
 *
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute it
 * freely, subject to the following restrictions:
 *
 *   1. The origin of this software must not be misrepresented; you must not
 *   claim that you wrote the original software. If you use this software
 *   in a product, an acknowledgment in the product documentation would be
 *   appreciated but is not required.
 *
 *   2. Altered source versions must be plainly marked as such, and must not be
 *   misrepresented as being the original software.
 *
 *   3. This notice may not be removed or altered from any source
 *   distribution.
 *
 *  Created on: 9 jan. 2012
 */

#include "osinfo.h"
#include "../ccinfo/guessos.h"

extern cc_string_t* os_class(void) {
    cc_string_t* to_return = 0;
    cc_error_reset();

    switch(os_class_id()) {
    case OS_MSDOS:
        to_return = cc_string_new_from("MS-DOS");
        break;
    case OS_WINDOWS:
        to_return = cc_string_new_from("Windows");
        break;
    case OS_DARWIN:
        to_return = cc_string_new_from("Darwin");
        break;
    case OS_GNU:
        to_return = cc_string_new_from("GNU");
        break;
    case OS_FREEBSD:
        to_return = cc_string_new_from("FreeBSD");
        break;
    case OS_OPENBSD:
        to_return = cc_string_new_from("OpenBSD");
        break;
    case OS_NETBSD:
        to_return = cc_string_new_from("NetBSD");
        break;
    }
    if(!cc_string_len(to_return)) {
        to_return = cc_string_new_from("UNK");
    }

    return to_return;
}

int os_class_id(void) {
    /* One can, with reasonable accuracy, determine that an application is
     * most likely to run on the operating system it was compiled for, or
     * at least one that is compatible (in which case a distinction can still
     * be made at runtime). In any case, any runtime method to determine this
     * would require compile-time checks to determine the availability of
     * certain calls anyways. Therefore, "os detection" happens at compile
     * time.
     */
#ifdef CC_OS_WINDOWS
    return OS_WINDOWS;
#endif

#ifdef CC_OS_DARWIN
    return OS_DARWIN;
#endif

#ifdef CC_OS_GNU
    return OS_GNU;
#endif

#ifdef CC_OS_FREEBSD
    return OS_FREEBSD;
#endif

#ifdef CC_OS_OPENBSD
    return OS_OPENBSD;
#endif

#ifdef CC_OS_NETBSD
    return OS_NETBSD;
#endif

    return OS_UNK;
}
