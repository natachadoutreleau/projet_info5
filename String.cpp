#include "String.h"
#define NULL std::nullptr

<<<<<<< HEAD
// String::String(){
//     string_ = "Hello World";
//     size_ = 11;
// }
=======
String::String(){
    
    //string_ = new char[15];
    for(int i=0;i<sizeof("Hello World");i++)
        *string_[i] = "Hello World"[i];
    size_ = sizeof("Hello World");
}
>>>>>>> refs/remotes/origin/main


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
<<<<<<< HEAD

=======
*/
>>>>>>> refs/remotes/origin/main
/*
String::String(const char* cstring) {
 //faire vérification de la taille aumenter capacité
    for(int i=0;i<sizeof(cstring);i++)
        *string_[i] = csting[i];
    size = sizeof(cstring);
}
<<<<<<< HEAD
=======
*/
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
