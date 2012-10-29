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

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <ctype.h>
#include <errno.h>
#include <unistd.h>

#include <abc/libabc.h>

int
main(int argc, char *argv[])
{
     struct abc_ctx *ctx;
     struct abc_thing *thing = NULL;
     int err;

     err = abc_new(&ctx);
     if (err < 0) {
          exit(EXIT_FAILURE);
     }

     printf("version %s\n", VERSION);

     err = abc_thing_new_from_string(ctx, "foo", &thing);
     if (err >= 0) {
          abc_thing_unref(thing);
     }

     abc_unref(ctx);
     return EXIT_SUCCESS;
}
