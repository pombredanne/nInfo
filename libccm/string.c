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
 *  Created on: 6 jan. 2012
 */

#include "string.h"
#include "new.h"

#include <string.h>

cc_string_t* cc_string_new(void) {
    ccnew(cc_string_t);
    cc_error_reset();

    /* Initialize to empty string */
    ccthis->length = 0;
    ccthis->data = malloc(1);
    ccthis->data[0] = '\0';

    return ccthis;
}

cc_string_t* cc_string_new_from(const char* str) {
    ccnew(cc_string_t);
    cc_error_reset();

    /* Copy string */
    ccthis->length = strlen(str);
    ccthis->data = malloc(ccthis->length + 1);
    strcpy(ccthis->data, str);

    return ccthis;
}

cc_string_t* cc_string_new_copy(cc_string_t* orig) {
    ccnew(cc_string_t);
    cc_error_reset();

    ccthis->length = orig->length;
    ccthis->data = malloc(ccthis->length + 1);
    strcpy(ccthis->data, orig->data);

    return ccthis;
}

void cc_string_delete(cc_string_t* ccthis) {
    cc_error_reset();

    if(!ccthis) return;

    free(ccthis->data);
    free(ccthis);
}


size_t cc_string_len(cc_string_t* ccthis) {
    cc_error_reset();

    return ccthis->length;
}

cc_bool cc_string_inbounds(cc_string_t* ccthis, size_t i) {
    cc_error_reset();

    return i < ccthis->length;
}

void cc_string_copy(cc_string_t* ccthis, cc_string_t* orig) {
    cc_error_reset();

    free(ccthis->data);
    ccthis->length = orig->length;
    ccthis->data = malloc(ccthis->length + 1);
    strcpy(ccthis->data, orig->data);
}

void cc_string_set(cc_string_t* ccthis, const char* str) {
    cc_error_reset();

    free(ccthis->data);
    ccthis->length = strlen(str);
    ccthis->data = malloc(ccthis->length + 1);
    strcpy(ccthis->data, str);
}

const char* cc_string_get(cc_string_t* ccthis) {
    cc_error_reset();

    return ccthis->data;
}


char cc_string_get_at(cc_string_t* ccthis, size_t i) {
    cc_error_reset();

    if(!cc_string_inbounds(ccthis, i)) {
        ccerror = CCEOVERFLOW;
        return '\0';
    } else {
        return ccthis->data[i];
    }
}

void cc_string_set_at(cc_string_t* ccthis, size_t i, char c) {
    cc_error_reset();

    if(!cc_string_inbounds(ccthis, i)) {
        ccerror = CCEOVERFLOW;
    } else {
        ccthis->data[i] = c;
    }
}


void cc_string_append(cc_string_t* ccthis, cc_string_t* rhs) {
    /* TODO */
}

void cc_string_prepend(cc_string_t* ccthis, cc_string_t* rhs) {
    /* TODO */
}


cc_string_t* cc_strerror(cc_error_t error) {
    cc_string_t* to_return = 0;
    cc_error_reset();

    switch(error) {
    case CCENONE:
        to_return = cc_string_new_from(_(""));
        break;
    case CCEOVERFLOW:
        to_return = cc_string_new_from(_("Buffer overflow"));
        break;
    case CCEARG:
        to_return = cc_string_new_from(_("Invalid argument"));
        break;
    default:
        ccerror = CCEARG;
    }

    return to_return;
}

void cc_perror(const char* pname) {
    cc_string_t* cerr;
    cc_error_reset();

    cerr = cc_strerror(ccerror);
    printf("%s: %s\n", pname, cerr->data);
    cc_string_delete(cerr);
}

CC_DEF_ARRAY(cc_string_t*, arrstr);
