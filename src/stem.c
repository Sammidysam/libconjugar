#include "stem.h"

#include <string.h>

#include "verb.h"

/* Includes from other header files. */
/* verb.h */
// #include <stdbool.h>

/*
 * Retrieves the ending of the string verb.
 * If it has a valid ending, the function will return that ending.
 * If the ending is not valid, the function will return "".
 *
 * verb.c->cjr_is_verb(char *verb) calls this function, so
 * do not call that function within this function!
 */
char *cjr_get_ending(char *verb)
{
	return verb;
}

char *cjr_get_stem(char *verb)
{
	return verb;
}
