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
	/* Max verb ending length is 4, so 8 is safe. */
	char *ending = malloc(8 * sizeof(char));
	char *last_two_characters = &verb[(strlen(verb) > 2) ? (strlen(verb) - 2) : 0];

	/* If ending is se, then we need to get more information. */
	if (strcmp(last_two_characters, cjr_verb_ending(CJR_VERB_REFLEXIVE)) == 0) {
		/*
		 * We need the last four characters to determine
		 * what kind of verb ending in "se" it is.
		 */
		char *last_four_characters = &verb[(strlen(verb) > 4) ? (strlen(verb) - 4) : 0];

		if (strcmp(last_four_characters, cjr_verb_ending(CJR_VERB_ARSE)) == 0
		    || strcmp(last_four_characters, cjr_verb_ending(CJR_VERB_ERSE)) == 0
		    || strcmp(last_four_characters, cjr_verb_ending(CJR_VERB_IRSE)) == 0)
			ending = last_four_characters;
	} else {
		if (strcmp(last_two_characters, cjr_verb_ending(CJR_VERB_AR)) == 0
		    || strcmp(last_two_characters, cjr_verb_ending(CJR_VERB_ER)) == 0
		    || strcmp(last_two_characters, cjr_verb_ending(CJR_VERB_IR)) == 0)
			ending = last_two_characters;
	}
	
	return strlen(ending) == 0 ? "" : ending;
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
		case CJR_VERB_AR:
			return "ar";
		case CJR_VERB_ER:
			return "er";
		case CJR_VERB_IR:
			return "ir";
		case CJR_VERB_REFLEXIVE:
			return "se";
		case CJR_VERB_ARSE:
			return "arse";
		case CJR_VERB_ERSE:
			return "erse";
		case CJR_VERB_IRSE:
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
	return cjr_is_verb_type(verb, CJR_VERB_REFLEXIVE);
}
