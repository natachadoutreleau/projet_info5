#include<iostream>
#include "string_tests.h"
#include "String.h"
#include<iostream>

void test_ctor_c_str(){
    String s;
    s.stingify();
}


void test_destructor(){
  String *s= new String; //sans delete on a une mémoire utilisée à 24 bytes definitivement perdue et 15 bytes indirectement perdue
  delete s; // avec le delete on ne perd plus de mémoire
}

void test_capacity(){
  String s;
  int capacity=s.capacity();
  if (capacity==15){
      std::cout  << "The capacity is :" << capacity<< std::endl;
  }
  else{
      std::cout  << "Bad capacity :" << capacity<< std::endl;
  }
}

void test_reserve_normal(){
  String s;
  s.reserve(20);
  s.stingify();
  std::cout  << "The capacity is :" << s.capacity()<< std::endl;
}

void test_reserve_more_than_capacity(){
  String s;
  s.reserve(150);
  s.stingify();
  std::cout  << " The capacity requested is 150. The new capacity is :" << s.capacity()<< std::endl;
}

void test_reserve_lower_than_size(){
  String s;
  s.reserve(10);
  s.stingify();
  std::cout  << "The capacity requested is 10. The new capacity is :" << s.capacity()<< std::endl;
}

void test_empty_when_empty(){
  String s;
  if(s.empty()){
    std::cout  << "empty"<< std::endl;
  }
  else{
    std::cout  << "not empty"<< std::endl;
  }
}

void test_empty_when_not_empty(){
  String s("Hello World");
  if(s.empty()){
    std::cout  << "empty"<< std::endl;
  }
  else{
    std::cout  << "not empty"<< std::endl;
  }
}

void test_operator_equal_char(){
  String s("Hello World");
  s.stingify();
  s="New string";
  s.stingify();
}

void test_operator_plus_two_str(){
  String s("Hello World");
  s.stingify();
  s="New string";
  s.stingify();
    std::cout<<s.max_size()<<std::endl;
}


void test_ctor_cpy(){
    String s;
    s.stingify();
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
    char var[] = "I like to code in C++";
    std::cout << var << std::endl;
    std::cout << "size : " << sizeof(var) << std::endl;
    String s1(var);
    String a("even more than in Python!");
    s1.stingify();
    a.stingify();
}

void test_length(){
    String s2;
    std::cout << "The size of the String with the length function is " << s2.length() << std::endl;
    std::cout << "It can also be calculated with the size function and is "<< s2.size() << std::endl;
    std::cout << "It is incredible that two functions can code the same thing!"<< std::endl;
}



void test_resize(){
    String s("I like to code in C++");
    s.resize(2,'+');
    s.stingify();
}

void test_operator_eg(){
    String s;
    String s1("I like to code in C++");
    s = s1;
    s.stingify();
}


void test_clear(){
    String s;
    std::cout<<"Before clearing: "<<std::endl;
    s.stingify();
    s.clear();
    std::cout<<"After clearing: "<<std::endl;
    s.stingify();
    std::cout << "After clearing, the size is: " << s.length() << std::endl;
}

void test_operator_equal_c(){
  String s;
  s.stingify();
  s='c';
  s.stingify();
}

void test_operator_plus_char(){
    String s;
    s = s+'a';
    s.stingify();
}
void test_operator_plus_tab(){
  String s;
  String t;
  String a =s+" test";
  a.stingify();
}
