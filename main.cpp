
#include<iostream>
#include "String.h"
#include "string_tests.h"

int main(){
    test_destructor();
    test_capacity();
    test_reserve_normal();
    test_reserve_more_than_capacity();
    test_reserve_lower_than_size();
    test_empty_when_empty();
    test_empty_when_not_empty();
    test_operator_equal_char();
    return 0;
}
