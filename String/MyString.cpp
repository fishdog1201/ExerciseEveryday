#include <cstring>
#include "MyString.h"

int String::string_nums = 0;

int String::how_many()
{
    return string_nums;
}

void String::append(const String& s)
{
    strcat(this->str, s.str);
    this->len = strlen(this->str);
    return;
}

void String::push_back(const char ch)
{
    strcat(this->str, &ch);
    this->len = strlen(this->str);
    return;
}

void String::swap(String& s)
{
    char temp[CINLIM];
    strcpy(temp, this->str);
    strcpy(this->str, s.str);
    strcpy(s.str, temp);
    this->len = strlen(this->str);
    s.len = strlen(s.str);
    return;
}

void String::swap(char* s)
{
    char temp[CINLIM];
    strcpy(temp, this->str);
    strcpy(this->str, s);
    strcpy(s, temp);
    this->len = strlen(this->str);
    return;
}

int String::find(const char* s, size_t index)
{
    int length = strlen(s);
    // Can be replaced with KMP algorithm
    for (int this_index = index; this_index < this->len; this_index++) {
        if (this->str[this_index] == s[0]) {
            for (int s_index = 0; s_index < length; s_index++) {
                if (this->str[this_index + s_index] != s[s_index]) {
                    break;
                }
                if (s_index == length - 1) {
                    return this_index;
                }
            }
        }
    }
    return -1;
}

int String::find(const String& s, size_t index)
{
    for (int this_index = index; this_index < this->len; this_index++) {
        if (this->str[this_index] == s.str[0]) {
            for (int s_index = 0; s_index < s.len; s_index++) {
                if (this->str[this_index + s_index] != s.str[s_index]) break;
                if (s_index == s.len - 1) {
                    return this_index;
                }
            }
        }
    }
    return -1;
}

String::String()
{
    len = 4;
    str = new char[1];
    str[0] = '\0';
    string_nums++;
}

String::String(const char* s)
{
    len = std::strlen(s);
    str = new char[len + 1];
    std::strcpy(str, s);
    string_nums++;
}

String::String(const String & s)
{
    len = s.len;
    str = new char[len + 1];
    std::strcpy(str, s.str);
    string_nums++;
}

String::~String()
{
    --string_nums;
    delete[] str;
}

// assign a String to a String
String & String::operator=(const String & st)
{
    if (this == &st)
        return *this;
    delete [] str;
    len = st.len;
    str = new char[len + 1];
    std::strcpy(str, st.str);
    return *this;
}

// assign a C string to a String
String & String::operator=(const char * s)
{
    delete [] str;
    len = std::strlen(s);
    str = new char[len + 1];
    std::strcpy(str, s);
    return *this;
}

// read-write char access for non-const String
char & String::operator[](int i)
{
    return str[i];
}

// read-only char access for const String
const char & String::operator[](int i) const
{
    return str[i];
}

String & String::operator+(const String & s)
{
    strcat(this->str, s.str);
    return *this;
}

String & String::operator+(const char * s)
{
    strcat(this->str, s);
    return *this;
}

// overloaded operator friends

bool operator<(const String& s1, const String& s2)
{
    return (std::strcmp(s1.str, s2.str) < 0);
}

bool operator>(const String& s1, const String& s2)
{
    return s2 < s1;
}

bool operator==(const String& s1, const String& s2)
{
    return (std::strcmp(s1.str, s2.str) == 0);
}

bool operator==(const String& s1, const char* s2)
{
    return (strcmp(s1.str, s2) == 0);
}

// simple String output
std::ostream & operator<<(std::ostream& os, const String& s)
{
    os << s.str;
    return os;
}

// quick and dirty String input
std::istream & operator>>(std::istream& is, String& s)
{
    char temp[String::CINLIM];
    is.get(temp, String::CINLIM);
    if (is)
        s = temp;
    while (is && is.get() != '\n')
        continue;
    return is;
}

