/*
 * The MIT License (MIT)
 *
 * Copyright (c) 2019, Erik Moqvist
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use, copy,
 * modify, merge, publish, distribute, sublicense, and/or sell copies
 * of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 * This file is part of the Monolinux project.
 */

#include "ml.h"

int main()
{
    struct ml_log_object_t log_object_1;
    struct ml_log_object_t log_object_2;

    ml_init();

    /* Initialize two log objects. */
    ml_log_object_init(&log_object_1, "object-1", ML_LOG_UPTO(DEBUG));
    ml_log_object_init(&log_object_2, "object-2", ML_LOG_UPTO(INFO));

    /* Use the first log object. */
    ml_log_object_print(&log_object_1, ML_LOG_DEBUG, "Debug level 1!");
    ml_log_object_print(&log_object_1, ML_LOG_INFO, "Info level 1!");

    /* Use the second log object. */
    ml_log_object_print(&log_object_2, ML_LOG_DEBUG, "Debug level 2!");
    ml_log_object_print(&log_object_2, ML_LOG_INFO, "Info level 2!");
    ml_log_object_set_mask(&log_object_2, ML_LOG_MASK(DEBUG));
    ml_log_object_print(&log_object_2, ML_LOG_DEBUG, "Debug level 3!");
    ml_log_object_print(&log_object_2, ML_LOG_INFO, "Info level 3!");

    /* Short form. */
    ML_DEBUG(&log_object_1, "Debug level 4!");
    ML_INFO(&log_object_1, "Info level 4!");

    return (0);
}