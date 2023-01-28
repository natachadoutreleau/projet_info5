#include "String.h"

#include<iostream>

String::String(){
    /*
    //string_ = new char[15];
    for(int i=0;i<sizeof("Hello World");i++){
        string_[i] = "Hello World"[i];
    }
    size_ = sizeof("Hello World");
    //std::cout << sizeof("Hello World") << std::endl;
     */
    string_ = new char[15];
    capacity_=15;
    size_ = 0;
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
    char* temp;
    temp = new char [max_size_];
    int i = 0;
    while(cstring[i] != '\0'){
        if(i == max_size_){
            i = -1;
            break;
        }
        temp[i] = cstring[i];
        std::cout<<temp[i]<<std::endl;
        i++;
    }
    if(i == -1)
        std::cout<<"erreur la séquence doit faire moins de :" << max_size_ << std::endl;
    else{
        std::cout << std::endl;
        size_ = i;
        if(i != max_size_){
            string_ = new char[size_+5];
            capacity_ = size_+5;
        }
            
        else{
            string_ = new char[max_size_];
            capacity_ = max_size_;
        }
        memcpy(string_, temp, size_ * sizeof(char));
        delete [] temp;
    }
}
 //faire vérification de la taille aumenter capacité

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
}

int String::max_size(){
    return max_size_;
}
void String::resize(int size_t, char c){
    int tmp_size = size_t + size_;
    if(tmp_size > max_size_)
        std::cout<<"erreur la séquence doit faire moins de :" << max_size_ << std::endl;
    else{
        if(tmp_size > capacity_)
            reserve(tmp_size);
        for(int i; i<size_t;i++){
            string_[size_ + i - 1] = c;
        }
    }
}/*
int String::capacity(){

return 0;
}
bool String::empty(){

return 0;
}
void String::reserve(int size_t){

}

String& String::operator=(char c){


}*/
String& String::operator=(const String& str){
    this->clear();
    delete string_;
    char* temp;
    temp = new char [max_size_];
    int i = 0;
    while(str.string_[i] != '\0'){
        if(i == max_size_){
            i = -1;
            break;
        }
        temp[i] = str.string_[i];
        std::cout<<temp[i]<<std::endl;
        i++;
    }
    if(i == -1)
        std::cout<<"erreur la séquence doit faire moins de :" << max_size_ << std::endl;
    else{
        std::cout << std::endl;
        size_ = i;
        if(i != max_size_){
            string_ = new char[size_+5];
            capacity_ = size_+5;
        }
            
        else{
            string_ = new char[max_size_];
            capacity_ = max_size_;
        }
        memcpy(string_, temp, size_ * sizeof(char));
        delete [] temp;
    }
    return *this;

}
/*
String& String::operator=(const char* c){


}

String operator+( const String& str, const char* c){

}

String operator+(const String& str , char c){

}
String operator+(const String& str, const String& str2){

}
*/
