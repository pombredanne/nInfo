/*
 * ccinfo (part of the nInfo suite)
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
 */

/*
 * Originally adapted from LibSylph. Licensing conditions indentical to ccinfo
 * license.
 *
 * Created on 30 januari 2009, 9:08
 */

/*
// Partially copied from The Boost Library, v 1.37.0
// Original copyright below:

//  Boost compiler configuration selection header file

//  (C) Copyright John Maddock 2001 - 2002.
//  (C) Copyright Jens Maurer 2001.
//  Use, modification and distribution are subject to the
//  Boost Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

//  See http://www.boost.org for most recent version.
*/

#ifndef CCINFO_GUESSOS_H_
#define CCINFO_GUESSOS_H_

#include <limits.h>

#if defined(_WIN32) || defined(__WIN32__) || defined(WIN32)
/* win32: */
#define CC_OS_WINDOWS
#endif

#if defined(__CYGWIN__)
/* cygwin is not win32 -- Linux can be used as a substitute: */
#define CC_OS_CYGWIN
#define CC_OS_WINDOWS
#define CC_OS_POSIX
#endif

#if defined(__APPLE__) || defined(__APPLE_CC__)
/* Mac OS X */
#define CC_OS_DARWIN
#define CC_OS_POSIX

#include <TargetConditionals.h>
#ifdef TARGET_OS_IPHONE
#define CC_OS_IOS
#define CC_OS_IOS_REAL_DEVICE
#endif

#ifdef TARGET_IPHONE_SIMULATOR
#define CC_OS_IOS
#define CC_OS_IOS_SIMULATOR
#endif

#endif

/* GNU is distributed with a collection of other kernels and tools, and many
 * other operating systems include GNU packages in their distribution. For the
 * sake of simplicity, we define a GNU system as one that uses glibc.
 */
#if defined(__GNU_LIBRARY__) || defined(__GLIBC_VERSION__)
#define CC_OS_GNU
#define CC_OS_POSIX
#endif

/* The uClibc is an alternative to glibc that is also commonly found on "gnu"
 * systems.
 */
#if defined(__UCLIBC__)
#define CC_OS_GNU
#define CC_OS_POSIX
#endif

#if defined(linux) || defined(__linux) || defined(__linux__)
/* linux: */
#define CC_OS_LINUX
#endif

#if defined(__GNU__)
/* hurd: */
#define CC_OS_HURD
#endif

#if defined(__FreeBSD_kernel__)
/* kfreebsd: */
#define CC_OS_KFREEBSD
#endif

#if defined(BSD)
/* bsd: */
#define CC_OS_BSD
#endif

#if defined(__FreeBSD__)
/* freebsd: */
#define CC_OS_BSD
#define CC_OS_FREEBSD
#define CC_OS_POSIX
#endif

#if defined(__NetBSD__)
/* netbsd: */
#define CC_OS_BSD
#define CC_OS_NETBSD
#define CC_OS_POSIX
#endif

#if defined(__OpenBSD__)
/* openbsd: */
#define CC_OS_BSD
#define CC_OS_OpenBSD
#define CC_OS_POSIX
#endif




#endif  /* CCINFO_GUESSOS_H_ */
