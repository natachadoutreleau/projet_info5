#include "String.h"
#define NULL std::nullptr

// String::String(){
//     string_ = "Hello World";
//     size_ = 11;
// }


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

/*
String::String(const char* cstring) {

}
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
	//return this->length();
}

void String::clear(){
  string_[0]='\0';
}
/*
int String::length(){
	return size_;
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
*/
String& String::operator=(char c){
	//string_[0]=str;
	string_[1]='\0';
	return *this;
}
/*
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
