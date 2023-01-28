#include<iostream>
#include "string_tests.h"
#include "String.h"



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
