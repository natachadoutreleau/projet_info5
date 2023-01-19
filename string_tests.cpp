#include<iostream>
#include "string_tests.h"
#include "String.h"



int test_default_constructor(){
  String s= new String();
  std::cout<<s.string_<<std::endl;
  return 0;
}
