#include "String.h"

#include<iostream>


String::String(){
    string_ = new char[15];
    for(int i=0;i<sizeof("Hello World");i++){
        string_[i] = "Hello World"[i];
    }
    size_ = sizeof("Hello World");
    //std::cout << sizeof("Hello World") << std::endl;
     
    /*
    string_ = new char[15];
    string_[0]='\0';
    capacity_=15;
    size_ = 0;*/
}

void String::stingify(){
    for(int i=0; i<size_; i++){
        std::cout << string_[i];
    }
    std::cout  << std::endl;
}
String::String(const String &other) = default;
/*
String::String(const String &other){
	int len = other.length();
	if(len > max_size_)
		throw std::length_error("Error");
		string_ = new char[len+1];
	 	max_size_= len+1;
	for (int i = 0; i<len+1; i++){
	    string_[i] = other.string_[i];
	}
	string_[len]='\0';
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
        i++;
    }
    if(i == -1)
        std::cout<<"erreur la séquence doit faire moins de :" << max_size_ << std::endl;
    else{
        size_ = i;
        if(i < max_size_-5){
            string_ = new char[size_+5];
            capacity_ = size_+5;
        }
            
        else{
            string_ = new char[max_size_];
            capacity_ = max_size_;
        }
        for(int i = 0; i<size_;i++)
            string_[i] = temp[i];
        delete [] temp;
    }
}

 //faire vérification de la taille aumenter capacité

/*
>>>>>>> refs/remotes/origin/main
String::~String(){
}
*/
char* String::c_str() const{
	char* cstr = new char[this->size_+1];
	for(int i=0; i<this->size_;i++){
	cstr[i]=string_[i];
	}
	cstr[this->size_] = '\0';
	return cstr;
}

int String::size() const {
	return size_;
}



int String::length(){
    return size_;
}

void String::clear(){
  string_[0]='\0';
}



int String::max_size(){
    return max_size_;
}/*
void String::resize(int size_t, char c){
    int tmp_size = size_t + size_;
    if(tmp_size > max_size_)
        std::cout<<"erreur la séquence doit faire moins de :" << max_size_ << std::endl;
    else{
        if(tmp_size > capacity_)
            reserve(tmp_size+5);
        for(int i = 0; i<size_t;i++){
            string_[size_ + i - 1] = c;
        }
    }
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
	string_[0]=c;
	string_[1]='\0';
	return *this;
}

String& String::operator=(const String& str){
    String s(str);
    return s;
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



String operator+( const String& str, const char* c){

}

String operator+(const String& str , char c){
    String s(str);
    if(s.length() + 1 > s.capacity())
        s.reserve(s.length()+1);
    s.resize(c, 1);
    return s;
}
String operator+(const String& str, const String& str2){

}
*/
