#include <iostream>
#include <string>
#include <algorithm>

class printString 
{
  public:

  	printString(std::ostream& os = std::cout, char delimiter = '\n') : \
  		os_(os), delimiter_(delimiter) {}
  	~printString(){}

    void operator()(std::string text)
    {
    	os_ << text << delimiter_;
    }

  private:
	std::ostream &os_;
 	char delimiter_;
};

int main()
{
	printString printer;
	printer("Hello!"); //Function object

    printString printerTwo(std::cerr, ' ');
	std::vector<std::string> words = {"The", "Kite", "Runner"};
	std::for_each(words.begin(), words.end(), printerTwo);
    std::cout << std::endl;
}