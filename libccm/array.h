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

#ifndef CCM_ARRAY_H_
#define CCM_ARRAY_H_

#include "error.h"
#include "new.h"

#ifdef __cplusplus
extern "C" {
#endif

#define CC_DEC_ARRAY(Type,Name) \
    typedef struct cc_##Name##_t { \
        Type* data; \
        size_t length; \
    } cc_##Name##_t; \
    \
    extern cc_##Name##_t* cc_##Name##_new(void); \
    extern cc_##Name##_t* cc_##Name##_new_from(Type*, size_t); \
    extern cc_##Name##_t* cc_##Name##_new_len(size_t); \
    extern cc_##Name##_t* cc_##Name##_new_copy(cc_##Name##_t*); \
    extern void cc_##Name##_delete(cc_##Name##_t*); \
    extern size_t cc_##Name##_len(cc_##Name##_t*); \
    extern cc_bool cc_##Name##_inbounds(cc_##Name##_t*, size_t); \
    extern Type cc_##Name##_get_at(cc_##Name##_t*, size_t); \
    extern void cc_##Name##_set_at(cc_##Name##_t*, size_t, Type); \
    extern Type* cc_##Name##_get(cc_##Name##_t*); \
    extern void cc_##Name##_set(cc_##Name##_t*, Type*, size_t); \
    extern void cc_##Name##_copy(cc_##Name##_t*, cc_##Name##_t*)

#define CC_DEF_ARRAY(Type,Name) \
    cc_##Name##_t* cc_##Name##_new(void) { \
        ccnew(cc_##Name##_t); \
        cc_error_reset(); \
        \
        ccthis->length = 0; \
        ccthis->data = 0; \
        \
        return ccthis; \
    } \
    \
    cc_##Name##_t* cc_##Name##_new_from(Type* orig, size_t len) { \
        ccnew(cc_##Name##_t); \
        cc_error_reset(); \
        \
        ccthis->length = len; \
        ccthis->data = malloc(sizeof(Type)*len); \
        memcpy(ccthis->data, orig, sizeof(Type)*len); \
        \
        return ccthis; \
    } \
    \
    cc_##Name##_t* cc_##Name##_new_len(size_t len) { \
        ccnew(cc_##Name##_t); \
        cc_error_reset(); \
        \
        ccthis->length = len; \
        ccthis->data = calloc(len, sizeof(Type)); \
        \
        return ccthis; \
    } \
    \
    cc_##Name##_t* cc_##Name##_new_copy(cc_##Name##_t* orig) { \
        ccnew(cc_##Name##_t); \
        cc_error_reset(); \
        \
        ccthis->length = orig->length; \
        ccthis->data = malloc(sizeof(Type)*ccthis->length); \
        memcpy(ccthis->data, orig->data, sizeof(Type)*ccthis->length); \
        \
        return ccthis; \
    } \
    \
    void cc_##Name##_delete(cc_##Name##_t* ccthis) { \
        cc_error_reset(); \
        \
        if(!ccthis) return; \
        \
        free(ccthis->data); \
        free(ccthis); \
    } \
    \
    size_t cc_##Name##_len(cc_##Name##_t* ccthis) { \
        cc_error_reset(); \
        \
        return ccthis->length; \
    } \
    \
    cc_bool cc_##Name##_inbounds(cc_##Name##_t* ccthis, size_t i) { \
        cc_error_reset(); \
        \
        return i < ccthis->length; \
    } \
    \
    Type cc_##Name##_get_at(cc_##Name##_t* ccthis, size_t i) { \
        cc_error_reset(); \
        \
        if(!cc_##Name##_inbounds(ccthis,i)) { \
            ccerror = CCEOVERFLOW; \
            return '\0'; \
        } else { \
            return ccthis->data[i]; \
        } \
    } \
    \
    void cc_##Name##_set_at(cc_##Name##_t* ccthis, size_t i, Type t) { \
        cc_error_reset(); \
        \
        if(!cc_##Name##_inbounds(ccthis, i)) { \
            ccerror = CCEOVERFLOW; \
        } else { \
            ccthis->data[i] = t; \
        } \
    } \
    \
    Type* cc_##Name##_get(cc_##Name##_t* ccthis) { \
        cc_error_reset(); \
        \
        return ccthis->data; \
    } \
    \
    void cc_##Name##_set(cc_##Name##_t* ccthis, Type* orig, size_t len) { \
        cc_error_reset(); \
        \
        free(ccthis->data); \
        ccthis->length = len; \
        ccthis->data = malloc(ccthis->length*sizeof(Type)); \
        memcpy(ccthis->data, orig, sizeof(Type)*len); \
    } \
    \
    void cc_##Name##_copy(cc_##Name##_t* ccthis, cc_##Name##_t* orig) { \
        cc_error_reset(); \
        \
        free(ccthis->data); \
        ccthis->length = orig->length; \
        ccthis->data = malloc(ccthis->length*sizeof(Type)); \
        memcpy(ccthis->data, orig->data, sizeof(Type)*ccthis->length); \
    } \
    \
    extern void cc__unused(void)

CC_DEC_ARRAY(int,    arrint);
CC_DEC_ARRAY(long,   arrlng);
CC_DEC_ARRAY(float,  arrflt);
CC_DEC_ARRAY(double, arrdbl);

#ifdef __cplusplus
} // extern "C"
#endif

#endif /* CCM_ARRAY_H_ */
