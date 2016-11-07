    #include <iostream>
    #include <string>
    #include <vector>
    #include <functional>
    #include <algorithm>

    void printWords_1(const std::vector<std::string>& words, 
    				std::ostream &os = std::cout, 
    				const char delimiter = ' ')
    {
    	std::for_each(words.begin(), words.end(), [&os, delimiter](const std::string& word){
    			os << word << delimiter;
    	});
    	std::cout << std::endl;
    }

    void printWords_2(const std::vector<std::string>& words,
    				std::ostream &os = std::cout,
    				const char delimiter =  '\n')
    {
    	//Captures everything by 'reference' except delimiter [&, identifier_list]
    	std::for_each(words.begin(), words.end(), [&, delimiter](const std::string& word){
    		os << word << delimiter;
    	});
    	std::cout << std::endl;
    }

    void printWords_3(const std::vector<std::string>& words,
    				std::ostream& os = std::cout,
    				const char delimiter = ',')
    {
    	//Captures everything by 'value' except ostream [=, identifier_list]
    	std::for_each(words.begin(), words.end(), [=, &os](const std::string& word) {
    		os << word << delimiter;
    	});
    	std::cout << std::endl;
    }

    void mutableLambda(const std::vector<std::string> words,
    				std::ostream& os = std::cout,
    				std::string delimiter = " ")
    {
    	std::for_each(words.begin(), words.end(), [=, &os](const std::string& word) mutable {
    		delimiter = " $ "; // We can modifiy the variables captured by 'value' if mutable is added
    		os << word << delimiter;
    	});
    	std::cout << std::endl;
    }

    class Printer
    {
    public:
    	Printer(std::ostream& os = std::cout, char delimiter = ' '): \
    		os_(os), delimiter_(delimiter) {}
    	~Printer(){}

        void printWords(std::vector<std::string>& words)
        {
        	//Passing 'this' to access the private members of class Printer
        	std::for_each(words.begin(), words.end(), [this](const std::string& word){
        		os_ << word << delimiter_;
        	});
        	os_ << std::endl;
        }

    private:
    	std::ostream& os_;
    	char delimiter_;
    };


    int main()
    {
    	std::vector<std::string> words = {"Lambda","capture","List", "examples"};
    	std::size_t lengthOfString = 4;
    	std::size_t stringSizeMoreThanSeven = 7;

    	//Lambda capture by value
        auto iter = std::find_if(words.begin(), words.end(), \
        		[lengthOfString](const std::string& word)-> bool { 
        			return (word.size() == lengthOfString); 
        	});
        std::cout <<"Word with string length 4 is : " << *iter << std::endl;

        //Lambda capture by reference
        auto wordWithMoreThanSevenLetters = std::find_if(words.begin(), words.end(), \
        	[&stringSizeMoreThanSeven](const std::string& word)-> bool {
        			stringSizeMoreThanSeven = 8;
        			return (word.size() == stringSizeMoreThanSeven);
        	});

        std::cout << "Word with more than seven letters is : " << *wordWithMoreThanSevenLetters << std::endl;
        std::cout << "stringSizeMoreThanSeven: " << stringSizeMoreThanSeven << std::endl;

     	printWords_1(words);
     	printWords_1(words, std::cout ,':');
     	printWords_2(words);
     	printWords_3(words);

        mutableLambda(words);

        Printer printer(std::cout, '@');
        printer.printWords(words);

    	return 0;
    }