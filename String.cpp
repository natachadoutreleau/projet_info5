#include "String.h"
#include <iostream>


String::String(){
  //string_ = new char[15];
  for(int i=0;i<sizeof("Hello World");i++){
        string_[i] = "Hello World"[i];
    }
    size_ = sizeof("Hello World");
}

void String::stingify(){
    for(int i=0; i<size_; i++){
        std::cout << string_[i];
    }
    std::cout  << std::endl;
}

/*
String::String(const String &other){

}

String::String(const char* cstring) {

}
*/


String::~String(){
  delete[] string_;
}

/*
char* String::c_str() const{

return 0;
}

int String::size() const {

return 0;
}
void String::clear(){


}
int String::length(){

return 0;
}
int String::max_size(){

return 0;
}

void String::resize(int size_t, char c){

}
*/
int String::capacity(){
  return capacity_;
}
/*
bool String::empty(){

return 0;
}
*/

void String::reserve(int size_t){
    if(size_t>max_size_){
      std::cout  << "Warning: the maximum capacity for a String is "<< max_size_<< "; The new capacity has been set to"<<max_size_<< std::endl;
      size_t=100;
    }
    if(size_t< size_){
      std::cout  << "Warning: the String is of size "<< size_ << ". Use resize() if you want to change the size of the String. The capacity has been set to "<< size_<<  std::endl;
      size_t= size_;
    }
    capacity_= size_t;
    char * temp= string_;
    char * new_str = new char[size_t];
    for (int i = 0; i < size_; ++i){
      new_str[i] = temp[i];
    }
    string_=new_str;
    delete [] temp;
}

/*
String& String::operator=(char c){


}
String& String::operator=(const String& str){


}

String& String::operator=(const char* c){


}

String operator+( const String& str, const char* c){

}

String operator+(const String& str , char c){

}
String operator+(const String& str, const String& str2){

}
*/
