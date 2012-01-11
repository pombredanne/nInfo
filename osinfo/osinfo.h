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

#ifndef OSINFO_OSINFO_H_
#define OSINFO_OSINFO_H_

#include "../libccm/string.h"

#ifdef __cplusplus
extern "C" {
#endif

    /**
     * Supported OS strings:
     *
     * MS-DOS: MS-DOS, Windows versions prior to 95
     * Windows: Microsoft Windows, 95 and onwards
     * Darwin: Darwin, Mac OS X, iOS
     * GNU: GNU/Linux (Linux, Android), GNU/kFreebsd, GNU/Hurd
     * FreeBSD: FreeBSD
     * OpenBSD: OpenBSD
     * NetBSD: NetBSD
     */
    extern cc_string_t* os_class(void);

    #define OS_UNK        0
    #define OS_MSDOS      1
    #define OS_WINDOWS    2
    #define OS_DARWIN     3
    #define OS_GNU        4
    #define OS_FREEBSD    5
    #define OS_OPENBSD    6
    #define OS_NETBSD     7

    /**
     * msdos:       1
     * windows:     2
     * darwin:      3
     * gnu          4
     * freebsd:     5
     * openbsd:     6
     * netbsd:      7
     */
    extern int os_class_id(void);

    extern cc_string_t* os_name(void);

    extern cc_string_t* os_version(void);

    /**
     * Internally allocated id
     */
    extern int os_version_id(void);


    extern cc_string_t* os_release_date(void);

    /**
     * Operating system name and version, e.g. "Windows Vista", "Mac OS X 10.7",
     * "Ubuntu 10.04"
     */
    extern cc_string_t* os_common_name(void);

    /**
     * Codename, e.g. "Snow Leopard", "Lion", "Hardy Heron", "Sarge", ...
     */
    extern cc_string_t* os_codename(void);


    extern cc_bool os_is_posix(void);


/******************************************************************************/

    extern cc_bool os_msdos_has_windows(void);

/******************************************************************************/

    extern cc_string_t* os_windows_version(void);

    /**
     * 100: Windows 1
     * 200: Windows 2
     * 300: Windows 3
     * 310: Windows 3.1
     * 311: Windows 3.11
     *
     * 1095: Windows 95
     * 1098: Windows 98
     * 1099: Windows 98 SE
     * 1200: Windows ME
     *
     * 10100: Windows NT 1
     * 10200: Windows NT 2
     * 10300: Windows NT 3
     * 10400: Windows NT 4
     *
     * 10500: Windows 2000 (NT 5)
     * 10501: Windows XP (NT 5.1)
     * 10600: Windows Vista (NT 6)
     * 10601: Windows 7 (NT 6.1)
     */
    extern int os_windows_version_id(void);

    extern cc_string_t* os_windows_release_date(void);


    extern cc_bool os_windows_is_nt(void);

    extern cc_string_t* os_winnt_ntversion(void);


    extern cc_bool os_windows_cygwin(void);

    extern cc_string_t* os_cygwin_version();

    /**
     * TBD.
     */
    extern int os_cygwin_version_id();

    extern cc_string_t* os_cygwin_release_date(void);

/******************************************************************************/

    extern cc_bool os_darwin_is_macosx(void);

    extern cc_bool os_darwin_is_ios(void);


    extern cc_string_t* os_darwin_version(void);

    extern int os_darwin_version_major(void);

    extern int os_darwin_version_minor(void);

    extern int os_darwin_version_bugfix(void);

    /**
     * 10000 + os_darwin_version_major() * 100 + os_darwin_version_minor()
     */
    extern int os_darwin_version_id(void);

    extern cc_string_t* os_darwin_release_date(void);


    extern cc_string_t* os_macosx_version(void);

    extern int os_macosx_version_major(void);

    extern int os_macosx_version_minor(void);

    extern int os_macosx_version_bugfix(void);

    /**
     * 10000 + os_macosx_version_major() * 100 + os_macosx_version_minor()
     */
    extern int os_macosx_version_id(void);

    extern cc_string_t* os_macosx_release_date(void);


    extern cc_string_t* os_ios_version(void);

    extern int os_ios_version_major(void);

    extern int os_ios_version_minor(void);

    extern int os_ios_version_bugfix(void);

    /**
     * os_ios_version_major() * 100 + os_ios_version_minor()
     */
    extern int os_ios_version_id(void);

    extern cc_string_t* os_darwin_release_date(void);

/******************************************************************************/

    /**
     * Kernel used on a GNU-based operating system
     * linux
     * hurd
     * kfreebsd
     */
    extern cc_string_t* os_gnu_kernel(void);

    extern cc_string_t* os_gnu_kernel_version(void);

    /**
     * Linux: major * 10000 + minor * 100 + revision
     */
    extern int os_gnu_kernel_version_id(void);


    extern int os_linux_kernel_version_major(void);

    extern int os_linux_kernel_version_minor(void);

    extern int os_linux_kernel_version_revision(void);

    /**
     * True if the given Linux distribution is an Android distribution,
     * false if the given Linux distribution isn't Android, false and
     * CCESTATE if not a Linux distribution.
     */
    extern cc_bool os_gnu_is_android(void);

    extern cc_bool os_gnu_is_lsb_compliant(void);

    /**
     * As returned by the lsb_release
     */
    extern cc_string_t* os_gnu_distro(void);

    extern cc_string_t* os_gnu_distro_base(void);

    extern cc_bool os_gnu_distro_base_debian(void);

    extern cc_bool os_gnu_distro_base_redhat(void);

    extern cc_bool os_gnu_distro_base_gentoo(void);

    extern cc_string_t* os_gnu_distro_version(void);

    extern int os_gnu_distro_version_id(void);

#ifdef __cplusplus
}
#endif


#endif /* OSINFO_OSINFO_H_ */
