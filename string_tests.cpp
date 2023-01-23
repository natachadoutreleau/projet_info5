#include "string_tests.h"
#include "String.h"
#include<iostream>


void test_ctor_c_str(){
    String s;
    s.stingify();
}
void test_ctor_cstring(){
    String s1("HelloWorld\0");
    s1.stingify();
}

void test_length(){
    String s2;
    std::cout << s2.length() << std::endl;
}
