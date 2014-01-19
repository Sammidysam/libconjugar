#include "test_verb.h"

#include "../src/verb.h"

/* Includes from other header files. */
/* test_stem.h */
// #include <check.h>

START_TEST(test_verb_ending_actual_verbs)
{
	ck_assert_str_eq(cjr_get_ending("bailar"), "ar");
	ck_assert_str_eq(cjr_get_ending("lavarse"), "arse");
	
	ck_assert_str_eq(cjr_get_ending("comer"), "er");
	ck_assert_str_eq(cjr_get_ending("ponerse"), "erse");
	
	ck_assert_str_eq(cjr_get_ending("abrir"), "ir");
	ck_assert_str_eq(cjr_get_ending("aburrirse"), "irse");
}
END_TEST

TCase *verb_case(void)
{
	TCase *verb = tcase_create("Verb");

	tcase_add_test(verb, test_verb_ending_actual_verbs);

	return verb;
}
