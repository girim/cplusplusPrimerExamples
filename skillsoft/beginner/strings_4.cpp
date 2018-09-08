#include <iostream>
#include <string>
#define EOL "\n"

int main(int argc, char const *argv[])
{
    /* string Modifiers */

    /* 1. using compound addition operator oprator+= */
    std::string str = "Hello", language = "C++";
    const char* desig = "Developer";
    const char space = ' ';
    std::initializer_list<char> il = {'w', 'e', 'l', 'c', '0', 'm', 'e'};

    str += space + language;        // string& operator+=(const std::string& str)
    str += space;                   // string& operator+=(const char* c)
    str += desig;                   // string& operator+=(char c)
    str += '!';                     // string& operator+=(char c)
    str += space;
    str += il;                      // string& operator+=(initializer_list<char> il)

    std::cout << str << EOL;

    /* 2. using append() function */
    std::string alphabets = "a", ijk = "ijk";
    alphabets.append(ijk);
    std::cout << "alphabets: " << alphabets <<EOL;

    alphabets.append(ijk, 1, 2);    
    std::cout << "alphabets: " << alphabets <<EOL;

    alphabets.append("cdefg");
    std::cout << "alphabets: " << alphabets <<EOL;

    alphabets.append(4, '*');
    std::cout << "alphabets: " << alphabets <<EOL;

    alphabets.append("uveikr", 4);
    std::cout << "alphabets: " << alphabets <<EOL;

    alphabets.append(alphabets.begin()+1, alphabets.end()-4);
    std::cout << "alphabets: " << alphabets <<EOL;

    //std::initializer_list<int> ilist = {'m', 'n', 'o','p'};
    //alphabets.append(ilist);     //supported from c++14
    //std::cout << "alphabets: " << alphabets <<EOL;

    alphabets.push_back('G');
    std::cout << "alphabets: " << alphabets <<EOL;

    alphabets.pop_back();
    std::cout << "alphabets: " << alphabets <<EOL;

    /* insert 8-ways of inserting string */
    std::string sentence = "The brown fox";

    /* 1. string */
    std::string strToInsert = "quick ";
    sentence.insert(4, strToInsert);
    std::cout << "sentence: " << sentence << EOL; 

    /* 2. substring */
    strToInsert = "fox jumped over";
    sentence.insert(15, strToInsert, 3, 7);
    std::cout << "sentence: " << sentence << EOL; 

    /* 3. c-string */
    sentence.insert(20, " C-string ");
    std::cout << "sentence: " << sentence << EOL; 

    /* 4. buffer */
    sentence.insert(30, "someText", 4);
    std::cout << "sentence: " << sentence << EOL; 

    /* 5. fill */
    sentence.insert(31, 4, '*');
    std::cout << "sentence: " << sentence << EOL; 

    /* 6. single character */
    sentence.insert(sentence.end(), 'A');
    std::cout << "sentence: " << sentence << EOL; 

    /* 7. range */
    sentence.insert(sentence.begin()+ 1, strToInsert.begin(), strToInsert.end());
    std::cout << "sentence: " << sentence << EOL;

    /* 8. initializer list */
    std::initializer_list<char> dog = {'d','o', 'g'};
    sentence.insert(sentence.begin(), dog);
    std::cout << "sentence: " << sentence << EOL;

    return 0;
}
