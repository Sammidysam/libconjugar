#ifndef VERB_H
#define VERB_H

#include <stdbool.h>

/* Verb endings. */
typedef enum {
	CJR_VERB_TYPE_AR,
	CJR_VERB_TYPE_ER,
	CJR_VERB_TYPE_IR,
	CJR_VERB_TYPE_REFL,
	CJR_VERB_TYPE_REFL_AR,
	CJR_VERB_TYPE_REFL_ER,
	CJR_VERB_TYPE_REFL_IR
} cjr_verb_type_t;

char *cjr_get_ending(char *verb);

char *cjr_verb_ending(cjr_verb_type_t type);

bool cjr_is_verb(char *verb);
bool cjr_is_verb_type(char *verb, cjr_verb_type_t type);
bool cjr_is_reflexive(char *verb);

#endif
