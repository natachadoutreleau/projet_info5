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
String::String(const String &other){
	size_=other.size_;
	capacity_=other.capacity_;
	string_=new char[capacity_];
	for(int i =0; i<size_;i++){
		string_[i]=other.string_[i];
	}
}

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
        for (int i = 0; i < size_; ++i){
          string_[i] = temp[i];
        }
        delete [] temp;
    }

}

 //faire vérification de la taille aumenter capacité


String::~String(){
  delete[] string_;
}

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
    for(int i=0; i<size_;i++)
        string_[i] = '\0';
    size_ = 0;
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
            reserve(tmp_size+5);
        for(int i = 0; i<size_t;i++){
            string_[size_ + i - 1] = c;
        }
    }
}


int String::capacity(){
  return capacity_;
}


bool String::empty(){
  if (size_==0){
    return true;
  }
  else {
    return false;
  }
}

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


String& String::operator=(char c){
	this->clear();
	string_[0]=c;
	size_=1;
	return *this;
}

String& String::operator=(const String& str){
    char* temp = str.c_str();
    string_ = new char [str.capacity_];
    capacity_ = str.capacity_;
    size_ = str.size_;
    for(int i=0; i< str.size_; i++)
        string_[i] = temp[i];
    return *this;
    /*
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
    return *this;*/
}

String& String::operator=(const char* c){
  int i=0;
  while(c[i] != '\0'){
      i++;
  }
  if (i>100){
    std::cout<< "Warning the string is too long"<< std::endl;
    i=100;
  }
  if (i>95){
    capacity_=100;
  }
  else{
    capacity_= i+5;
  }
  size_=i;
  char* temp=string_;
  string_ = new char [capacity_];
  for(int j=0; j<size_;j++){
    string_[j]=c[j];
  }
  delete [] temp;

  return *this;
}





String operator+(const String& str , char c){
    String s(str);
    if(s.length() + 1 > s.capacity())
        s.reserve(s.length()+1);
    s.resize(c, 1);
    return s;
}


String operator+(const String& str, const String& str2){
  int new_size = str.size_ + str2.size_;
  if(new_size>100){
    std::cout<<"Warning: adding this two string will reach maximum capacity; new string might be truncated"<< std::endl;
    new_size=100;
  }
  char* temp= new char[new_size];
  int i=0;
  while (i<str.size_){
    temp[i]=str.string_[i];
    i++;
  }
  int j=0;
  while(i<new_size){
    temp[i]=str2.string_[j];
    i++;
    j++;
  }
  String new_string(temp);
  return new_string;
}
