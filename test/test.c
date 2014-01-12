#include <stdlib.h>

#include <check.h>

#include "test_stem.h"

Suite *libconjugar_suite()
{
	Suite *suite = suite_create("libconjugar");

	/* Add groups of tests to the suite. */
	suite_add_tcase(suite, stem_case());

	return suite;
}

int main(void)
{
	Suite *suite = libconjugar_suite();
	SRunner *runner = srunner_create(suite);
	
	srunner_run_all(runner, CK_NORMAL);
	
	int failed_tests = srunner_ntests_failed(runner);
	
	srunner_free(runner);
	
	return failed_tests == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}
