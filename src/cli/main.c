/* $Id$ */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <re/re.h>

/*
 * TODO: match a regexp against arguments. return $? if all match
 *
 * output to various forms, too (print the fsm as ERE, glob, etc)
 *
 * TODO: accepting a delimiter would be useful: /abc/. perhaps provide that as
 * a convenience function, especially wrt. escaping for lexing. Also convenient
 * for specifying flags: /abc/g
 *
 * getopts:
 * pass optarg for "form" of regex. -g for glob etc
 * remaining argv is string(s) to match
 * print the matching strings to stdout?
 *
 * ./re -e '^012.*abc$' -b '[a-z]_xx$' -g 'abc*def' "some string" "some other string"
 */

static void usage(void) {
	fprintf(stderr, "usage: re [-h] { [-geb9p] <re> } <string>\n");
}

static enum re_form form(char c) {
	switch (c) {
/* TODO:
	case 'e': return RE_ERE;
	case 'b': return RE_BRE;
	case '9': return RE_PLAN9;
	case 'p': return RE_PCRE;
*/
	case 'g': return RE_GLOB;
	case 's': return RE_SIMPLE;

	default:
		fprintf(stderr, "unrecognised re form \"%c\"", c);
		exit(EXIT_FAILURE);
	}

	assert(!"unreached");
}

int main(int argc, char *argv[]) {
	struct re *re;

	if (argc < 2) {
		usage();
		return EXIT_FAILURE;
	}

	re = re_new_empty();
	if (re == NULL) {
		perror("re_new_empty");
		return EXIT_FAILURE;
	}

	{
		int c;

		while ((c = getopt(argc, argv, "hg:s:")) != -1) {
			struct re *new;
			enum re_err err;

			switch (c) {
			case 'h':
				usage();
				return EXIT_SUCCESS;

/* TODO:
			case 'b':
			case 'e':
			case '9':
			case 'p':
*/
			case 'g':
			case 's':
				/* TODO: flags? */
				new = re_new_comp(form(c), optarg, NULL, 0, &err);
				if (new == NULL) {
					fprintf(stderr, "re_new_comp: %s\n", re_strerror(err));
					return EXIT_FAILURE;
				}

				if (!re_merge(re, new, optarg)) {
					perror("re_merge");
					return EXIT_FAILURE;
				}

				re_free(new);
				break;

			case '?':
			default:
				usage();
				return EXIT_FAILURE;
			}
		}

		argc -= optind;
		argv += optind;
	}

	/* TODO: flags? */
	re_exec(re, argv[0], 0);

	re_free(re);

	return EXIT_SUCCESS;
}

