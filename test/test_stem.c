#include "test_stem.h"

#include "../src/stem.h"

/* Includes from other header files. */
/* test_stem.h */
// #include <check.h>

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
	ck_assert_str_eq(cjr_get_stem("these"), "");
	ck_assert_str_eq(cjr_get_stem("are"), "");
	ck_assert_str_eq(cjr_get_stem("not"), "");
	ck_assert_str_eq(cjr_get_stem("verbs"), "");
}
END_TEST

START_TEST(test_stem_short_non_verbs)
{
	ck_assert_str_eq(cjr_get_stem("a"), "");
	ck_assert_str_eq(cjr_get_stem("an"), "");
	ck_assert_str_eq(cjr_get_stem("the"), "");
	ck_assert_str_eq(cjr_get_stem("that"), "");
}
END_TEST

START_TEST(test_stem_short_verbs)
{
	ck_assert_str_eq(cjr_get_stem("ser"), "s");
	ck_assert_str_eq(cjr_get_stem("ver"), "v");
}
END_TEST

TCase *stem_case(void)
{
	TCase *stem = tcase_create("Stem");
	
	tcase_add_test(stem, test_stem_actual_verbs);
	tcase_add_test(stem, test_stem_not_verbs);
	tcase_add_test(stem, test_stem_short_non_verbs);
	tcase_add_test(stem, test_stem_short_verbs);

	return stem;
}
