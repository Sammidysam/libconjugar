#include "verb.h"

#include <stdlib.h>
#include <string.h>

/* Includes from other header files. */
/* verb.h */
// #include <stdbool.h>

/*
 * Retrieves the ending of string verb.
 * If it has a valid ending, the function will return that ending.
 * If the ending is not valid, the function will return "".
 *
 * Other functions that call this function
 *
 * cjr_is_verb
 * cjr_is_verb_type
 * cjr_is_reflexive (through calling cjr_is_verb_type)
 */
char *cjr_get_ending(char *verb)
{
	char *last_two_characters = &verb[(strlen(verb) > 2) ? (strlen(verb) - 2) : 0];

	/* If ending is se, then we need to get more information. */
	if (strcmp(last_two_characters, cjr_verb_ending(CJR_VERB_TYPE_REFL)) == 0) {
		/*
		 * We need the last four characters to determine
		 * what kind of verb ending in "se" it is.
		 */
		char *last_four_characters = &verb[(strlen(verb) > 4) ? (strlen(verb) - 4) : 0];

		return strcmp(last_four_characters, cjr_verb_ending(CJR_VERB_TYPE_REFL_AR)) == 0 ||
			strcmp(last_four_characters, cjr_verb_ending(CJR_VERB_TYPE_REFL_ER)) == 0 ||
			strcmp(last_four_characters, cjr_verb_ending(CJR_VERB_TYPE_REFL_IR)) == 0 ? last_four_characters : "";
	} else {
		return strcmp(last_two_characters, cjr_verb_ending(CJR_VERB_TYPE_AR)) == 0 ||
			strcmp(last_two_characters, cjr_verb_ending(CJR_VERB_TYPE_ER)) == 0 ||
			strcmp(last_two_characters, cjr_verb_ending(CJR_VERB_TYPE_IR)) == 0 ? last_two_characters : "";
	}
}

/*
 * Maps the return value of cjr_get_ending to the enum cjr_verb_type_t.
 * Will return -1 if the verb is not a valid verb.
 * Does not deal with verbs ending in "se", for that
 * see the function cjr_is_reflexive.
 */
cjr_verb_type_t cjr_get_verb_type(char *verb)
{
	for (int i = CJR_VERB_TYPE_AR; i <= CJR_VERB_TYPE_REFL_IR; i++)
		if (strcmp(cjr_get_ending(verb), cjr_verb_ending(i)) == 0)
			return i;

	return -1;
}

/*
 * Retrieves the verb ending for verb type type.
 * Functions as a const char pointer array, but
 * does not add a variable to the end user's program.
 *
 * If type is not known, "" will be returned.
 *
 * TODO: Put verb endings on configuration file?
 */
char *cjr_verb_ending(cjr_verb_type_t type)
{
	switch (type) {
		case CJR_VERB_TYPE_AR:
			return "ar";
		case CJR_VERB_TYPE_ER:
			return "er";
		case CJR_VERB_TYPE_IR:
			return "ir";
		case CJR_VERB_TYPE_REFL:
			return "se";
		case CJR_VERB_TYPE_REFL_AR:
			return "arse";
		case CJR_VERB_TYPE_REFL_ER:
			return "erse";
		case CJR_VERB_TYPE_REFL_IR:
			return "irse";
		default:
			return "";
	}
}

/* Determines if string verb is a valid Spanish verb. */
bool cjr_is_verb(char *verb)
{
	return strlen(cjr_get_ending(verb)) > 0;
}

/* Determines if string verb is of type type. */
bool cjr_is_verb_type(char *verb, cjr_verb_type_t type)
{
	return strcmp(cjr_get_ending(verb), cjr_verb_ending(type)) == 0;
}

/* Determines if string verb is reflexive (ends in "se"). */
bool cjr_is_reflexive(char *verb)
{
	return cjr_is_verb_type(verb, CJR_VERB_TYPE_REFL_AR) ||
		cjr_is_verb_type(verb, CJR_VERB_TYPE_REFL_ER) ||
		cjr_is_verb_type(verb, CJR_VERB_TYPE_REFL_IR);
}
