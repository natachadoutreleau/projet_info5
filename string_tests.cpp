#include<iostream>
#include "string_tests.h"
#include "String.h"
#include<iostream>




void test_ctor_c_str(){
    String s("test");
    s.stringify();
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
  s.stringify();
  std::cout  << "La nouvelle capacité est :" << s.capacity()<< std::endl;
}

void test_reserve_more_than_capacity(){
  String s;
  s.reserve(150);
  s.stringify();
  std::cout  << "La capicité demandé est 150. La nouvelle capacité est :" << s.capacity()<< std::endl;
}

void test_reserve_lower_than_size(){
  String s;
  s.reserve(10);
  s.stringify();
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
  s.stringify();
  s="Nouveau string";
  s.stringify();
}

void test_operator_plus_two_str(){
  String s("Hello World");
  String t("Bonjour");
  s.stringify();
  std::cout<< "taille est : "<<s.size()<<std::endl;
  t.stringify();
  std::cout<< "taille est : "<<t.size()<<std::endl;
  String new_str;
  new_str= s+t;
  new_str.stringify();
  std::cout<<"taille: "<< new_str.size()<<" capacity : "<<new_str.capacity()<<std::endl;
  s="Nouveau string";
  s.stringify();
    std::cout<<s.max_size()<<std::endl;
}


void test_ctor_cpy(){
    String s;
    s.stringify();
    String s_cpy(s);
    s_cpy.stringify();
}

void test_operator_plus(){
  String s("Hello World");
  s.stringify();
  std::cout<< "taille est : "<<s.size()<<std::endl;
  String new_str;
  new_str= s+"test";
  new_str.stringify();
  std::cout<<"taille: "<< new_str.size()<<" capacity : "<<new_str.capacity()<<std::endl;
}

void test_ctor_cstring(){
    char var[] = "Je suis un gamin et je suis nul en anglais";
    std::cout << var << std::endl;
    std::cout << "taille : " << sizeof(var) << std::endl;
    String s1(var);
    String a("lalalala");
    s1.stringify();
    a.stringify();
}

void test_length(){
    String s2;
    std::cout << s2.length() << std::endl;
}

void test_resize(){
    String s("I like to code in C");
    s.stringify();
    s.resize(2,'+');
    s.stringify();
}

void test_operator_eg(){
    String s;
    String s1("I like to code in C");
    s = s1;
    s.stringify();
}


void test_clear(){
    String s;
    s.stringify();
    s.clear();
    s.stringify();
    std::cout << s.length() << std::endl;
}

void test_operator_equal_c(){
  String s;
  s.stringify();
  s='a';
  s.stringify();

}

void test_operator_plus_char(){
    String s;
    s = s+'a';
    s.stringify();
}
void test_operator_plus_tab(){
  String s;
  String t;
  String a =s+" test";
  a.stringify();
}
