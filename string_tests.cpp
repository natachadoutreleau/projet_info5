#include "string_tests.h"
#include "String.h"
#include<iostream>


void test_ctor_c_str(){
    String s;
    s.stingify();
    std::cout<<s.max_size()<<std::endl;
}

void test_ctor_cpy(){
    String s;
    String s_cpy(s);
    s_cpy.stingify();
}

void test_cstr(){
    String s;
    char *temp;
    temp = s.c_str();
    int t_size = s.length();
    for(int i=0; i<t_size;i++)
        std::cout << temp[i];
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
    std::cout << s2.size() << std::endl;
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


void test_clear(){
    String s;
    s.stingify();
    s.clear();
    s.stingify();
    std::cout << s.length() << std::endl;
}
