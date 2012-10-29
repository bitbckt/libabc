/*
 * libabc - something with abc
 *
 * Copyright (C) 2012 Someone <someone@example.com>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once

#include <stdbool.h>
#include <syslog.h>

#include <abc/libabc.h>

static inline void __attribute__((always_inline, format(printf, 2, 3)))
abc_log_null(struct abc_ctx *ctx, const char *format, ...) {}

#define abc_log_cond(ctx, prio, arg...) \
  do { \
    if (abc_get_log_priority(ctx) >= prio) \
      abc_log(ctx, prio, __FILE__, __LINE__, __FUNCTION__, ## arg); \
  } while (0)

#ifdef ENABLE_LOGGING
#  ifdef ENABLE_DEBUG
#    define dbg(ctx, arg...) abc_log_cond(ctx, LOG_DEBUG, ## arg)
#  else
#    define dbg(ctx, arg...) abc_log_null(ctx, ## arg)
#  endif
#  define info(ctx, arg...) abc_log_cond(ctx, LOG_INFO, ## arg)
#  define err(ctx, arg...) abc_log_cond(ctx, LOG_ERR, ## arg)
#else
#  define dbg(ctx, arg...) abc_log_null(ctx, ## arg)
#  define info(ctx, arg...) abc_log_null(ctx, ## arg)
#  define err(ctx, arg...) abc_log_null(ctx, ## arg)
#endif

#define ABC_EXPORT __attribute__ ((visibility("default")))

void abc_log(struct abc_ctx *ctx,
           int priority, const char *file, int line, const char *fn,
           const char *format, ...)
           __attribute__((format(printf, 6, 7)));
