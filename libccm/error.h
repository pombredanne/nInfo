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

#ifndef CCM_ERROR_H_
#define CCM_ERROR_H_

#ifdef __cplusplus
extern "C" {
#endif

typedef int cc_error_t;

extern cc_error_t ccerror;

const cc_error_t CCENONE     = 0;
const cc_error_t CCEOVERFLOW = 1;
const cc_error_t CCEARG      = 2;

#define cc_error_reset() ccerror = CCENONE

typedef int cc_bool;

#if !defined(__cplusplus) && !defined(true)
#define true 1
#define false 0
#endif

#ifdef __cplusplus
}
#endif


#endif /* CCM_ERROR_H_ */