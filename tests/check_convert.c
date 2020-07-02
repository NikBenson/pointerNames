//
// Created by NikBe on 23.06.2020.
//
#include <check.h>
#include "../src/PointerNames.h"

int main() {
	return 0;
}

START_TEST(test_convert)
{
	int* test = (int *) 5;

	const char name[16] = "test";

	printf("test\n");

	setPointerToNamesList((const char[][16]){name}, 1);

	ck_assert_str_eq(getPointerName(test), "name");
}
END_TEST