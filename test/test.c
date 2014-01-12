#include <stdlib.h>

#include <check.h>

#include "../src/stem.h"

START_TEST(test_stem)
{
	ck_assert_str_eq(cjr_get_stem("bailar"), "bail");
	ck_assert_str_eq(cjr_get_stem("lavarse"), "lav");
}
END_TEST

Suite *libconjugar_suite()
{
	Suite *suite = suite_create("libconjugar");

	/* Core tests. */
	TCase *core = tcase_create("Core");
	tcase_add_test(core, test_stem);

	suite_add_tcase(suite, core);

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
