#include <iostream>

template <typename T>
class Node
{
    public:
        explicit Node(T data, Node* nextNode = nullptr) : data_(data), next_(nextNode){};
        ~Node(){};

        T getData() const 
        {
            return this->data_;
        } 

        Node* next() const
        {
            return this->next_;
        }

    private:
        T data_;
        Node* next_;
};

/* Function templates */
template<typename T>
void swap(T& lhs, T& rhs)
{
    T temp = lhs;
    lhs = rhs;
    rhs = temp;
}

int main(int argc, char const *argv[])
{
    Node<unsigned> node_1(100, nullptr);
    Node<unsigned> node_2(200, &node_1);
    Node<unsigned> node_3(300, &node_2);
    Node<unsigned> node_4(400, &node_3);

    Node<unsigned>* tmp = nullptr;
    tmp = &node_4;

    while(tmp->next() != nullptr)
    {
        std::cout << "value: " << tmp->getData() << "\n";
        tmp = tmp->next();
    }
    std::cout << "value: " << tmp->getData() << "\n";

    /* String Linked List */
    Node<std::string> strNode_1("C++", nullptr);
    Node<std::string> strNode_2("C", &strNode_1);
    Node<std::string> strNode_3("JavaScript", &strNode_2);

    Node<std::string>* strTmp =  &strNode_3;

    while(strTmp->next() != nullptr)
    {
        std::cout << "data: " << strTmp->getData() << "\n";
        strTmp = strTmp->next();
    }
    std::cout << "data: " << strTmp->getData() << "\n";

    int x = 10, y = 20;
    std::cout << "Before swap: x : " << x << " y : " << y << "\n";
    swap(x, y); 
    std::cout << "After swap: x : " << x << " y : " << y << "\n";

 
    return 0;
}
