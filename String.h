#ifndef STRING_H_
#define STRING_H_

class String{
public:

    String();/*
    String(const String &other); //copy constructor
    String(const char* cstring); // constructor from a c-string
    ~String();

    char* c_str() const; //  pointer to the c-string representation of the string object's value.
    int size() const;
    void clear();
    int length();
    int max_size();
    void resize(int size_t, char c);
    int capacity();
    bool empty();
    void reserve(int size_t);

    String & operator=(char c);
    String & operator=(const String& str);
    String & operator=(const char* c);

*/
    protected :
    const char *  string_;
    int size_ ;
    int max_size_=100;
};

String operator+(const String& str, const char* c);
String operator+(const String& str , char c);
String operator+( const String& str, const String& str2);

#endif
