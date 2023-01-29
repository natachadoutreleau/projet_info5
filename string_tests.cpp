#include "string_tests.h"
#include "String.h"
#include<iostream>


void test_ctor_c_str(){
    String s;
    s.stingify();
    std::cout<<s.max_size()<<std::endl;
}
void test_ctor_cstring(){
    char var[] = "Je suis un gamin et je suis nul en anglais";
    std::cout << var << std::endl;
    std::cout << "taille : " << sizeof(var) << std::endl;
    String s1(var);
    String a("lalalala");
    s1.stingify();
    a.stingify();
}

void test_length(){
    String s2;
    std::cout << s2.length() << std::endl;
}

void test_resize(){
    String s("I like to code in C");
    //s.resize(2,'a');
    s.stingify();
}

void test_operator_eg(){
    String s;
    String s1("I like to code in C");
    s = s1;
    s.stingify();
}
