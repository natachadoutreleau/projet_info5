#include "String.h"
#define NULL std::nullptr

String::String(){
    string_ = "Hello Wolrd";
    size_ = 11;
}

/*
String::String(const String &other){

}

String::String(const char* cstring) {

}


String::~String(){
}

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
int String::capacity(){

return 0;
}
bool String::empty(){

return 0;
}
void String::reserve(int size_t){

}

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
