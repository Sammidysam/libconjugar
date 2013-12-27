#include "verb.h"

#include <string.h>

#include "stem.h"

/* Includes from other header files. */
/* verb.h */
// #include <stdbool.h>

/* Determines if string verb is a valid Spanish verb. */
bool cjr_is_verb(char *verb)
{
	return strlen(cjr_get_ending(verb)) > 0;
}
