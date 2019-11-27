/*!  ************************************************************************
 *
 * @file output/zeus2/fast_api_support.h
 * @brief Details the functions that needs to be implemented
 *        for the smart fabric driver to work in custom application
 *
 * @internal
 * This file contains information definitons of the FAST API
 *
 *   Copyright (C) 2017 Zglue  Inc. All rights reserved.
 *   Author: Arjun Hary
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 * @endinternal
 *
 *****************************************************************************/

#ifndef FAST_API_INCLUDE_ZEUS2_H
#define FAST_API_INCLUDE_ZEUS2_H

#undef EXTERN
#if defined(__cplusplus)
#define EXTERN extern "C"
extern "C"
{
#else
#define EXTERN extern
#endif

#define dbg_printf printf
#define f_malloc malloc
#define f_free free

/* Read from a specific register in the FAST */
/*! @brief . */
fast_status_e fast_read_register(uint8_t dev_id, uint32_t reg_addr, uint8_t *read_data, uint16_t len);

/* Write to a specific register in the FAST */
/*! @brief . */
fast_status_e fast_write_register(uint8_t dev_id, uint32_t reg_addr, uint8_t *read_data, uint16_t len);

/* Read the configuration file from specific place in memory of the HOST system */
/*! @brief . */
fast_status_e fast_config_file_read(uint32_t offset, uint32_t length, uint16_t *buffer);

/* Toggle the ULPM Wake up pin of the fast */
/*! @brief . */
fast_status_e fast_toggle_ulpm_wake(void);

/* Sleep in uS */
/*! @brief . */
void fast_sleep(uint32_t time_us);

#undef EXTERN
#if defined(__cplusplus)
}
#endif

#endif //FAST_API_INCLUDE_ZEUS2_H
