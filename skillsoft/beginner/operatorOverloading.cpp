#include <iostream>

class Counter
{
    public:
        Counter():count_(0){}
        ~Counter(){}

        /* prefix */
        unsigned operator++()
        {
            return ++this->count_;
        }

        /* postfix */
        unsigned operator++(int)
        {
            return this->count_++;
        }

        unsigned currentCount() const
        {
            return this->count_;
        }

    private:
        unsigned count_;

};

int main(int argc, char const *argv[])
{
    Counter counter;
    std::cout << "current count 1: " << counter.currentCount() << std::endl;
    ++counter;
    std::cout << "current count 2: " << counter.currentCount() << std::endl;
    counter++;
    std::cout << "current count 3: " << counter.currentCount() << std::endl;

    unsigned res = 1 + counter++;
    std::cout << "res: " << res << std::endl;
    std::cout << "current count 4: " << counter.currentCount() << std::endl;

    return 0;
}
