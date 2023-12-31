#include <iostream>
#include "MyString.h"

int test_string() {
    String s1 = "123";
    String s2("abc");
    String* s3 = new String("xyz");

    String s4 = s1;
    if (s1 == s4) {
        std::cout << "s1 == s4\n";
    }

    std::cout << "===========strcat============" << std::endl;
    s1 = s1 + "456";
    std::cout << s1 << std::endl;
    s1.append("789");
    std::cout << s1 << std::endl;
    s1.push_back('!');
    std::cout << s1 << std::endl;

    std::cout << s1 << " " << s2 << std::endl;
    std::cout << "===========strswap============" << std::endl;
    s1.swap(s2);
    std::cout << s1 << " " << s2 << std::endl;

    std::cout << s2.size() << std::endl;

    std::cout << "===========strfind============" << std::endl << s2.find("456", 0) << std::endl;
    return 0;
}
