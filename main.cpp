
#include<iostream>
#include "String.h"
#include "string_tests.h"

int main(){
    test_destructor();
    test_capacity();
    test_reserve_normal();
    test_reserve_more_than_capacity();
    test_reserve_lower_than_size();
    return 0;
}
