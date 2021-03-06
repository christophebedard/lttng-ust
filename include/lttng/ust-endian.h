#ifndef _LTTNG_UST_ENDIAN_H
#define _LTTNG_UST_ENDIAN_H

/*
 * lttng/ust-endian.h
 *
 * Copyright 2012 (c) - Mathieu Desnoyers <mathieu.desnoyers@efficios.com>
 *
 * endian.h compatibility layer.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#if (defined(__linux__) || defined(__CYGWIN__))
#include <endian.h>
#include <byteswap.h>
#elif defined(__FreeBSD__)
#include <sys/endian.h>
#define bswap_16(x)	bswap16(x)
#define bswap_32(x)	bswap32(x)
#define bswap_64(x)	bswap64(x)
#else
#error "Please add support for your OS."
#endif

/*
 * BYTE_ORDER, LITTLE_ENDIAN, and BIG_ENDIAN are only defined on Linux
 * if __USE_BSD is defined. Force their definition.
 */
#ifndef BYTE_ORDER
#define BYTE_ORDER __BYTE_ORDER
#endif

#ifndef LITTLE_ENDIAN
#define LITTLE_ENDIAN __LITTLE_ENDIAN
#endif

#ifndef BIG_ENDIAN
#define BIG_ENDIAN __BIG_ENDIAN
#endif

#ifndef FLOAT_WORD_ORDER
#ifdef __FLOAT_WORD_ORDER
#define FLOAT_WORD_ORDER	__FLOAT_WORD_ORDER
#else /* __FLOAT_WORD_ORDER */
#define FLOAT_WORD_ORDER	BYTE_ORDER
#endif /* __FLOAT_WORD_ORDER */
#endif /* FLOAT_WORD_ORDER */

#endif /* _LTTNG_UST_ENDIAN_H */
