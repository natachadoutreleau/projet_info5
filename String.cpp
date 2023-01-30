#include "String.h"

#include<iostream>

/**
 * Constructs a string object, initializing its value
 * @param none
 */
String::String(){
  /*
    string_ = new char[15];
    for(int i=0;i<sizeof("Hello World");i++){
        string_[i] = "Hello World"[i];
    }
    size_ = sizeof("Hello World");
    capacity_ = 15;
    //std::cout << sizeof("Hello World") << std::endl;
    */
    string_ = new char[15];
    string_[0]='\0';
    capacity_=15;
    size_ = 0;
}

/**
 * Print the string.
 * @param none
 * @return none
 */
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

/**
 * Constructs a string object, initializing its value
 * @param cstring Pointer to an array of characters
 */
String::String(const char* cstring) {
  char* temp;
    temp = new char [max_size_];
    int i = 0;
    int j =0;
    while(cstring[i] != '\0'){
        if(i >= max_size_){
            j = -1;
        }
        else{
            temp[i] = cstring[i];
        }
        i++;
    }
    if(j == -1){
        std::cout  << "Warning: the maximum capacity for a String is "<< max_size_<< std::endl;
        size_ = max_size_;
    }
    else
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

/**
 * Returns the length of the string, in terms of bytes.
 * @param none
 * @return The number of bytes in the string.
 */
int String::length(){
    return size_;
}

void String::clear(){
    for(int i=0; i<size_;i++)
        string_[i] = '\0';
    size_ = 0;
}

/**
 * Returns the maximum length the string can reach.
 * @param none.
 * @return The maximum length the string can reach.
 */
int String::max_size(){
    return max_size_;
}

/**
 * Resizes the string to a length of n characters.
 * If n is greater than the current string length, the current content is extended by inserting at the end as many characters as needed to reach a size of n. If c is specified, the new elements are initialized as copies of c, otherwise, they are value-initialized characters (null characters).
 * @param size_t New string length, expressed in number of characters.
 * @param c  Character used to fill the new character space added to the string (in case the string is expanded).
 * @return none
 */
void String::resize(int size_t, char c){
    if(size_t < 0){
        std::cout  << "Warning: the number of size_t must be more than 0 "<< std::endl;
        return;
    }
    int tmp_size = size_t + size_;

    if(tmp_size > max_size_)
        std::cout  << "Warning: the maximum capacity for a String is "<< max_size_<< std::endl;
    else{
        if(tmp_size > capacity_)
            reserve(tmp_size);
        for(int i = 0; i<size_t;i++){
            string_[size_ + i ] = c;
        }
        size_ = tmp_size;
    }
}

/**
* Returns the size of the storage space currently allocated for the string, expressed in terms of bytes.
*
* @param none
* @return The size of the storage capacity currently allocated for the string.
*/
int String::capacity(){
    return capacity_; // return the capacity (lenght of the array containing the string)
}

/**
* Returns whether the string is empty (i.e. whether its length is 0
*
* @param none
* @return true if the string length is 0, false otherwise.
*/
bool String::empty(){
  if (size_==0 && string_[0]=='\0'){ //check if the strings empty and the size is 0
    return true;
  }
  else {
    return false;
  }
}

/**
* Requests that the string capacity be adapted to a planned change in size to a length of up to n characters.
* If n is greater than the maximum capacity, the new capaicty is the maximum capacity
* If n si smaller than the string lenght, the new capacity is the string lenght.
*
* @param n Planned length for the string.
* @return none
*/
void String::reserve(int n){
  if(n>max_size_){
      std::cout  << "Warning: the maximum capacity for a String is "<< max_size_<< "; The new capacity has been set to"<<max_size_<< std::endl;
      n=max_size_;
    }
    if(n< size_){
      std::cout  << "Warning: the String is of size "<< size_ << ". Use resize() if you want to change the size of the String. The capacity has been set to "<< size_<<  std::endl;
      n= size_;
    }
    capacity_= n;
    char * temp= string_;
    char * new_str = new char[n];
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
/**
 * Assigns a new value to the string, replacing its current contents.
 * @param str A string object, whose value is either copied (1) or moved (5) if different from *this (if moved, str is left in an unspecified but valid state).
 * @return *this
 */
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

/**
* Assigns a new value to the string, replacing its current contents.
*
* @param c: Pointer to a null-terminated sequence of characters. The sequence is copied as the new value for the string.
* @return *this
*/
String& String::operator=(const char* c){
  int i=0;
  while(c[i] != '\0'){ //count the size of the array
      i++;
  }
  if (i>max_size_){ //if the array is too long it is cut to the max_capacity_
    std::cout<< "Warning the string is too long"<< std::endl;
    i=max_size_;
  }
  if (i>(max_size_-5)){ //if the size is close to the max_capacity_ the capacity is max_capacity
    capacity_=max_size_;
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

/**
 * Returns a newly constructed string object with its value being the concatenation of the characters
 * @param str Argument to the left-hand side of the operator.
 * @param c Argument to the right-hand side of the operator.
 * @return A string whose value is the concatenation.
 */
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

/**
* Returns a newly constructed string object with its value being the concatenation of the characters in str followed by those of str2
* If the size of str and str2 is greater than the maximum capacity then str2 is truncated
*
* @param str and str2 Arguments to the left- and right-hand side of the operator, respectively.
* @return new_string: a String object
*/
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
