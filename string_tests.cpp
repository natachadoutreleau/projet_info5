#include<iostream>
#include "string_tests.h"
#include "String.h"



int getter_string(){
  String s= new String();
  std::cout<<s.string_<<std::endl;
  return 0;
}

int getter_s(){
  String s= new String();
  std::cout<<s.s<<std::endl;
  return 0;
}

int getter_max_s(){
  String s= new String();
  std::cout<<s.max_s<<std::endl;
  return 0;
}
