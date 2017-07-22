/* Generated by libfsm */

#include LF_HEADER

#include <stddef.h>

#include <fsm/fsm.h>

struct fsm *
class_word_fsm(const struct fsm_options *opt)
{
	struct fsm *fsm;
	size_t i;

	struct fsm_state *s[2] = { 0 };

	fsm = fsm_new(opt);
	if (fsm == NULL) {
		return NULL;
	}

	for (i = 0; i < 2; i++) {
		s[i] = fsm_addstate(fsm);
		if (s[i] == NULL) {
			goto error;
		}
	}

	for (i = 0x30; i <= 0x39; i++) { /* '0' .. '9' */
		if (!fsm_addedge_literal(fsm, s[0], s[1], i)) { goto error; }
	}
	for (i = 0x41; i <= 0x5a; i++) { /* 'A' .. 'Z' */
		if (!fsm_addedge_literal(fsm, s[0], s[1], i)) { goto error; }
	}
	if (!fsm_addedge_literal(fsm, s[0], s[1], '_')) { goto error; }
	for (i = 0x61; i <= 0x7a; i++) { /* 'a' .. 'z' */
		if (!fsm_addedge_literal(fsm, s[0], s[1], i)) { goto error; }
	}

	fsm_setstart(fsm, s[0]);
	fsm_setend(fsm, s[1], 1);

	return fsm;

error:

	fsm_free(fsm);

	return NULL;
}

