#ifndef STRING_H_
#define STRING_H_

class String{
public:

    String();
    void stringify();
    String(const String &other); //copy constructor
    String(const char* cstring); // constructor from a c-string
    ~String();

    char* c_str() const; //  pointer to the c-string representation of the string object's value.
    int size() const;
    void clear();
    int length();
    int max_size();
    void resize(int size_t, char c);
    int capacity(); // Return size of allocated storage
    bool empty(); // Test if string is empty
    void reserve(int size_t); //Request a change in capacity
    String & operator=(const String& str);
    String & operator=(char c);
    String& operator=(const char* c); //String assignment from a char array
    friend String operator+(const String& str, const String& str2); //Concatenate two strings objects
    friend String operator+(const String& str, const char* c);
    friend String operator+(const String& str , char c);


    protected :
        char* string_;
        int size_ ;
        int max_size_=100;
        int capacity_;
};


#endif
