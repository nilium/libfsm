/* Generated by libfsm */

#include LF_HEADER

#include <stddef.h>

#include <fsm/fsm.h>

struct fsm *
utf8_Katakana_fsm(const struct fsm_options *opt)
{
	struct fsm *fsm;
	size_t i;

	struct fsm_state *s[15] = { 0 };

	fsm = fsm_new(opt);
	if (fsm == NULL) {
		return NULL;
	}

	for (i = 0; i < 15; i++) {
		s[i] = fsm_addstate(fsm);
		if (s[i] == NULL) {
			goto error;
		}
	}

	if (!fsm_addedge_literal(fsm, s[0], s[1], 0xe3)) { goto error; }
	if (!fsm_addedge_literal(fsm, s[0], s[2], 0xef)) { goto error; }
	if (!fsm_addedge_literal(fsm, s[0], s[3], 0xf0)) { goto error; }
	if (!fsm_addedge_literal(fsm, s[1], s[9], 0x82)) { goto error; }
	if (!fsm_addedge_literal(fsm, s[1], s[10], 0x83)) { goto error; }
	if (!fsm_addedge_literal(fsm, s[1], s[11], 0x87)) { goto error; }
	if (!fsm_addedge_literal(fsm, s[1], s[12], 0x8b)) { goto error; }
	if (!fsm_addedge_literal(fsm, s[1], s[13], 0x8c)) { goto error; }
	if (!fsm_addedge_literal(fsm, s[1], s[14], 0x8d)) { goto error; }
	if (!fsm_addedge_literal(fsm, s[2], s[7], 0xbd)) { goto error; }
	if (!fsm_addedge_literal(fsm, s[2], s[8], 0xbe)) { goto error; }
	if (!fsm_addedge_literal(fsm, s[3], s[4], 0x9b)) { goto error; }
	if (!fsm_addedge_literal(fsm, s[4], s[5], 0x80)) { goto error; }
	if (!fsm_addedge_literal(fsm, s[5], s[6], 0x80)) { goto error; }
	for (i = 0xa6; i <= 0xaf; i++) {
		if (!fsm_addedge_literal(fsm, s[7], s[6], i)) { goto error; }
	}
	for (i = 0xb1; i <= 0xbf; i++) {
		if (!fsm_addedge_literal(fsm, s[7], s[6], i)) { goto error; }
	}
	for (i = 0x80; i <= 0x9d; i++) {
		if (!fsm_addedge_literal(fsm, s[8], s[6], i)) { goto error; }
	}
	for (i = 0xa1; i <= 0xbf; i++) {
		if (!fsm_addedge_literal(fsm, s[9], s[6], i)) { goto error; }
	}
	for (i = 0x80; i <= 0xba; i++) {
		if (!fsm_addedge_literal(fsm, s[10], s[6], i)) { goto error; }
	}
	for (i = 0xbd; i <= 0xbf; i++) {
		if (!fsm_addedge_literal(fsm, s[10], s[6], i)) { goto error; }
	}
	for (i = 0xb0; i <= 0xbf; i++) {
		if (!fsm_addedge_literal(fsm, s[11], s[6], i)) { goto error; }
	}
	for (i = 0x90; i <= 0xbe; i++) {
		if (!fsm_addedge_literal(fsm, s[12], s[6], i)) { goto error; }
	}
	for (i = 0x80; i <= 0xbf; i++) {
		if (!fsm_addedge_literal(fsm, s[13], s[6], i)) { goto error; }
	}
	for (i = 0x80; i <= 0x97; i++) {
		if (!fsm_addedge_literal(fsm, s[14], s[6], i)) { goto error; }
	}

	fsm_setstart(fsm, s[0]);
	fsm_setend(fsm, s[6], 1);

	return fsm;

error:

	fsm_free(fsm);

	return NULL;
}
