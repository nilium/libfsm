/*
 * Copyright 2008-2017 Katherine Flavel
 *
 * See LICENCE for the full copyright terms.
 */

#include <ctype.h>
#include <assert.h>
#include <limits.h>
#include <stdio.h>

#include <fsm/options.h>

#include <print/esc.h>

int
ebnf_escputc(FILE *f, const struct fsm_options *opt, int c)
{
	assert(f != NULL);
	assert(opt != NULL);
	assert(c >= 0 && c <= UCHAR_MAX);

	if (opt->always_hex) {
		return fprintf(f, "\\x%02x", (unsigned char) c);
	}

	switch (c) {
	case '\"': return fputs("\\\"", f);

	case '\f': return fputs("\\f", f);
	case '\n': return fputs("\\n", f);
	case '\r': return fputs("\\r", f);
	case '\t': return fputs("\\t", f);
	case '\v': return fputs("\\v", f);

	default:
		break;
	}

	if (!isprint((unsigned char) c)) {
		return fprintf(f, "\\x%02x", (unsigned char) c);
	}

	return fprintf(f, "%c", c);
}
