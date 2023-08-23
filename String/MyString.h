#pragma once

#include <iostream>

class String
{
public:
    // constructors
    String();
    String(const char* s);
    String(const String&);
    ~String();

    int length() const { return len; }
    int size() const { return len; }
    static int how_many();

    // overload operate methods
    String& operator=(const String&);
    String& operator=(const char*);
    char& operator[](int idx);
    const char& operator[](int idx) const;
    String& operator+(const String&);
    String& operator+(const char*);

    //overload operator friends
    friend bool operator<(const String& s1, const String& s2);
    friend bool operator>(const String& s1, const String& s2);
    friend bool operator==(const String& s1, const String& s2);
    friend bool operator==(const String& s1, const char* s2);
    friend std::ostream& operator<<(std::ostream& os, const String& s);
    friend std::istream& operator>>(std::istream& is, const String& s);

    // some function
    void append(const String& s);
    void append(const char* s);
    void push_back(const char ch);
    void swap(char* s);
    void swap(String& s);
    int find(const char* s, size_t index);
    int find(const String& s, size_t index);

    static const int CINLIM = 80;
private:
    char* str;
    int len;
    static int string_nums;
};

int test_string();
