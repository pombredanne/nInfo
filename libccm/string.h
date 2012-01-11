/*
 * libccm (part of the nInfo suite)
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
 *  Created on: 4 jan. 2012
 */

#ifndef CCM_STRING_H_
#define CCM_STRING_H_

#include "error.h"
#include "array.h"

/* TODO: i18n */
#define  _(X) (X)
#define N_(X) (X)

#ifdef __cplusplus
extern "C" {
#endif

typedef struct cc_string_t {
    size_t length;
    char* data;
} cc_string_t;

extern cc_string_t* cc_string_new(void);
extern cc_string_t* cc_string_new_from(const char*);
extern cc_string_t* cc_string_new_copy(cc_string_t*);
extern void cc_string_delete(cc_string_t*);

extern size_t cc_string_len(cc_string_t*);
extern cc_bool cc_string_inbounds(cc_string_t*, size_t);

extern void cc_string_copy(cc_string_t*, cc_string_t*);
extern void cc_string_set(cc_string_t*, const char*);
extern const char* cc_string_get(cc_string_t*);

extern char cc_string_get_at(cc_string_t*, size_t);
extern void cc_string_set_at(cc_string_t*, size_t, char);

extern void cc_string_append(cc_string_t*, cc_string_t*);
extern void cc_string_prepend(cc_string_t*, cc_string_t*);

extern cc_string_t* cc_strerror(cc_error_t);
extern void cc_perror(const char*);

CC_DEC_ARRAY(cc_string_t*, arrstr);

#ifdef __cplusplus
}
#endif

#endif /* CCM_STRING_H_ */
