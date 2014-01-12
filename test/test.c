#include <stdlib.h>

#include <check.h>

#include "../src/stem.h"

START_TEST(test_stem_actual_verbs)
{
	ck_assert_str_eq(cjr_get_stem("bailar"), "bail");
	ck_assert_str_eq(cjr_get_stem("lavarse"), "lav");
	
	ck_assert_str_eq(cjr_get_stem("comer"), "com");
	ck_assert_str_eq(cjr_get_stem("ponerse"), "pon");
	
	ck_assert_str_eq(cjr_get_stem("abrir"), "abr");
	ck_assert_str_eq(cjr_get_stem("aburrirse"), "aburr");
}
END_TEST

START_TEST(test_stem_not_verbs)
{
	/* When cjr_get_stem returns "", the word is not a verb. */
	ck_assert_str_eq(cjr_get_stem("funny"), "");
	ck_assert_str_eq(cjr_get_stem("words"), "");
}
END_TEST

Suite *libconjugar_suite()
{
	Suite *suite = suite_create("libconjugar");
	
	TCase *stem = tcase_create("Stem");
	tcase_add_test(stem, test_stem_actual_verbs);
	tcase_add_test(stem, test_stem_not_verbs);

	TCase *verb = tcase_create("Verb");

	/* Add groups of tests to the suite. */
	suite_add_tcase(suite, stem);
	suite_add_tcase(suite, verb);

	return suite;
}

int main(int argc, char *argv[])
{
	Suite *suite = libconjugar_suite();
	SRunner *runner = srunner_create(suite);
	
	srunner_run_all(runner, CK_NORMAL);
	
	int failed_tests = srunner_ntests_failed(runner);
	
	srunner_free(runner);
	
	return failed_tests == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}
