#ifndef STRING_TESTS_H_
#define STRING_TESTS_H_

void test_ctor_c_str(void);
void test_destructor(void);
void test_capacity(void);
void test_reserve_normal(void);
void test_reserve_more_than_capacity(void);
void test_reserve_lower_than_size(void);
void test_empty_when_empty(void);
void test_empty_when_not_empty(void);
void test_operator_equal_char(void);
#endif
