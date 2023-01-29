#include<iostream>
#include "string_tests.h"
#include "String.h"
#include<iostream>




void test_ctor_c_str(){
    String s;
    s.stingify();
}


void test_destructor(){
  String *s= new String; //sans delete on a une mémoire utilisé a 24 bytes definiteky lost et 15 bytes indirectly lost
  delete s; // avec le delete on ne perds plus de mémoire
}

void test_capacity(){
  String s;
  int capacity=s.capacity();
  if (capacity==15){
      std::cout  << "La capacité est bien :" << capacity<< std::endl;
  }
  else{
      std::cout  << "Mauvaise capacité :" << capacity<< std::endl;
  }
}

void test_reserve_normal(){
  String s;
  s.reserve(20);
  s.stingify();
  std::cout  << "La nouvelle capacité est :" << s.capacity()<< std::endl;
}

void test_reserve_more_than_capacity(){
  String s;
  s.reserve(150);
  s.stingify();
  std::cout  << "La capicité demandé est 150. La nouvelle capacité est :" << s.capacity()<< std::endl;
}

void test_reserve_lower_than_size(){
  String s;
  s.reserve(10);
  s.stingify();
  std::cout  << "La capicité demandé est 10. La nouvelle capacité est :" << s.capacity()<< std::endl;
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
  s="Nouveau string";
  s.stingify();
}

void test_operator_plus_two_str(){
  String s("Hello World");
  String t("Bonjour");
  s.stingify();
  std::cout<< "taille est : "<<s.size()<<std::endl;
  t.stingify();
  std::cout<< "taille est : "<<t.size()<<std::endl;
  String new_str;
  new_str= s+t;
  new_str.stingify();
  std::cout<<"taille: "<< new_str.size()<<" capacity : "<<new_str.capacity()<<std::endl;
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
