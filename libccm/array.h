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

#ifdef __cplusplus
extern "C" {
#endif

#define CC_DEC_ARRAY(Type,Name) \
    typedef struct cc_##Name##_t { \
        Type* data; \
        size_t length; \
    } cc_##Name##_t; \
    \
    extern cc_##Name##_t* cc_##Name##_new(); \
    extern void cc_##Name##_delete(cc_##Name##_t*); \
    extern size_t cc_##Name##_len(cc_##Name##_t*); \
    extern Type cc_##Name##_get(cc_##Name##_t*,size_t); \
    extern void cc_##Name##_put(cc_##Name##_t*,size_t,Type)

#define CC_DEF_ARRAY(Type,Name) \
    cc_##Name##_t* cc_##Name##_new() { \
        return malloc(sizeof(cc_##Name##_t)); \
    } \
    \
    void cc_##Name##_delete(cc_##Name##_t* p) { \
        free(p); \\
    } \
    \
    size_t cc_##Name##_len(cc_##Name##_t* p) { \
        return p->length; \
    } \
    Type cc_##Name##_get(cc_##Name##_t*,size_t) { \
        /* TODO */ \
    } \
    void cc_##Name##_put(cc_##Name##_t*,size_t,Type) { \
        /* TODO */ \
    }

C_DEC_ARRAY(int,    arrint);
C_DEC_ARRAY(long,   arrlng);
C_DEC_ARRAY(float,  arrflt);
C_DEC_ARRAY(double, arrdbl);

#ifdef __cplusplus
} // extern "C"
#endif

#endif /* CCM_ARRAY_H_ */
