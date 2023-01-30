#include "String.h"

#include<iostream>


String::String(){
  /*
    string_ = new char[15];
    for(int i=0;i<sizeof("Hello World");i++){
        string_[i] = "Hello World"[i];
    }
    size_ = sizeof("Hello World");
    //std::cout << sizeof("Hello World") << std::endl;
    */
    string_ = new char[15];
    string_[0]='\0';
    capacity_=15;
    size_ = 0;
}

void String::stringify(){
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
    delete[] string_; //delete the array
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
        for(int i = 0; i<tmp_size;i++){
            string_[size_ + i ] = c;
        }
        size_ = tmp_size;
    }
}


int String::capacity(){
    return capacity_; // return the capacity (lenght of the array containing the string)
}


bool String::empty(){ // return True if empty; False if not
  if (size_==0 && string_[0]=='\0'){ //check if the stringis empty and the size is 0
    return true;
  }
  else {
    return false;
  }
}

void String::reserve(int size_t){ //Change the capacity of the array: if the new size is smaller than the string, the new capacity is the size of the string; if the new size is bigger than the maximum capacity the new capacity is the maximum capacity.
    if(size_t>max_size_){
      std::cout  << "Warning: the maximum capacity for a String is "<< max_size_<< "; The new capacity has been set to"<<max_size_<< std::endl;
      size_t=max_size_;
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
    delete [] string_;
    char* temp = str.c_str();
    string_ = new char [str.capacity_];
    capacity_ = str.capacity_;
    size_ = str.size_;
    for(int i=0; i< str.size_; i++)
        string_[i] = temp[i];
    delete [] temp;
    return *this;
}

String& String::operator=(const char* c){ //Assign the new array to the current object
  int i=0;
  while(c[i] != '\0'){ //count the size of the array
      i++;
  }
  if (i>max_capacity_){ //if the array is too long it is cut to the max_capacity_
    std::cout<< "Warning the string is too long"<< std::endl;
    i=max_capacity_;
  }
  if (i>(max_capacity_-5)){ //if the size is close to the max_capacity_ the capacity is max_capacity
    capacity_=max_capacity_;
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
    s.resize(1, c);
    return s;
}


String operator+(const String& str, const char* c){
  int size_c=0;
  while(c[size_c] != '\0'){
      size_c++;
  }
	int new_size = str.size_ + size_c;
	if(new_size>str.max_size_){
    std::cout<<"Warning: adding this two string will reach maximum capacity; new string might be truncated"<< std::endl;
    new_size=100;
  }
	char* temp= new char[20];
  int i=0;
  while (i<str.size_){
    temp[i]=str.string_[i];
    i++;
  }

  int j=0;
  while(i<new_size){
    temp[i-1]=c[j];
    i++;
    j++;
  }
	std::cout<<temp[15]<<std::endl;
  String new_string(temp);
	delete[] temp;
  return new_string;
}


String operator+(const String& str, const String& str2){
  int new_size = str.size_ + str2.size_;
  if(new_size>100){
    std::cout<<"Warning: adding this two string will reach maximum capacity; new string might be truncated"<< std::endl;
    new_size=100;
  }
  char* temp = new char[new_size];
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
  delete[] temp;
  return new_string;
}
