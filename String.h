#ifndef STRING_H_
#define STRING_H_

class String{
public:

    String(const String &other); //copy constructor
    String(const char* cstring); // constructor from a c-string
    ~String();

    char* c_str() const; //  pointer to the c-string representation of the string object's value.
    int size() const;
    void clear();
    int length();
    int max_size();
    void resize(size_t, char);
    int capacity();
    bool empty();
    void reserve(size_t);

    String & operator=(char);
    String & operator=(const string&);
    String & operator=(const char*);

    String operator+(const string&, const char*);
    String operator+(const string&, char);
    String operator+(const string&, const string&);

    protected :
    char* string_;
    int size_ ;
    int max_size=100; 
}


#endif
