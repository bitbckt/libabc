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

#include <stdarg.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 * abc_ctx
 *
 * library user context - reads the config and system
 * environment, user variables, allows custom logging
 */
struct abc_ctx;
struct abc_ctx *abc_ref(struct abc_ctx *ctx);
struct abc_ctx *abc_unref(struct abc_ctx *ctx);
int abc_new(struct abc_ctx **ctx);
void abc_set_log_fn(struct abc_ctx *ctx,
                  void (*log_fn)(struct abc_ctx *ctx,
                                 int priority, const char *file, int line, const char *fn,
                                 const char *format, va_list args));
int abc_get_log_priority(struct abc_ctx *ctx);
void abc_set_log_priority(struct abc_ctx *ctx, int priority);
void *abc_get_userdata(struct abc_ctx *ctx);
void abc_set_userdata(struct abc_ctx *ctx, void *userdata);

/*
 * abc_list
 *
 * access to abc generated lists
 */
struct abc_list_entry;
struct abc_list_entry *abc_list_entry_get_next(struct abc_list_entry *list_entry);
const char *abc_list_entry_get_name(struct abc_list_entry *list_entry);
const char *abc_list_entry_get_value(struct abc_list_entry *list_entry);
#define abc_list_entry_foreach(list_entry, first_entry) \
        for (list_entry = first_entry; \
             list_entry != NULL; \
             list_entry = abc_list_entry_get_next(list_entry))

/*
 * abc_thing
 *
 * access to things of abc
 */
struct abc_thing;
struct abc_thing *abc_thing_ref(struct abc_thing *thing);
struct abc_thing *abc_thing_unref(struct abc_thing *thing);
struct abc_ctx *abc_thing_get_ctx(struct abc_thing *thing);
int abc_thing_new_from_string(struct abc_ctx *ctx, const char *string, struct abc_thing **thing);
struct abc_list_entry *abc_thing_get_some_list_entry(struct abc_thing *thing);

#ifdef __cplusplus
} /* extern "C" */
#endif
