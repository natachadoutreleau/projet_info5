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
