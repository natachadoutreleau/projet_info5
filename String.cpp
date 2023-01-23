#include "String.h"

#include<iostream>

String::String(){
    
    //string_ = new char[15];
    for(int i=0;i<sizeof("Hello World");i++){
        string_[i] = "Hello World"[i];
    }
    size_ = sizeof("Hello World");
    //std::cout << sizeof("Hello World") << std::endl;
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
*/

String::String(const char* cstring) {
    int sizeC = sizeof(cstring)-2;
    if(sizeC > max_size_)
        std::cout<<"erreur la séquence doit faire moins de :" << max_size_ << std::endl;
    else{
        if(15 < sizeC){
            char string[sizeC+3];
        }
        for(int i=0;i<sizeC;i++)
            string_[i] = cstring[i];
        size_ = sizeC;
    }
 //faire vérification de la taille aumenter capacité
}

/*
String::~String(){
}

char* String::c_str() const{

return 0;
}

int String::size() const {

return 0;
}
void String::clear(){


}*/
int String::length(){
    return size_;
}/*
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
*/
