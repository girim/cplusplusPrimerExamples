#include <iostream>

template<typename T>
class Node
{
    public:
        explicit Node(T data, Node* next = nullptr) : data_(data), next_(next){};
        ~Node(){};

        T getData() const { return data_;}
        Node* getNext() const { return next_;}

    private:
        Node *next_;
        T data_;
};

int main(int argc, char const *argv[])
{
    Node<int> node(10);
    std::cout << "First node data: " << node.getData() << std::endl;

    Node<int> node1(20, &node);
    std::cout << "First node data: " << node1.getNext()->getData() << std::endl;

    Node<std::string> strNode("c++");
    std::cout << "strNode data: " << strNode.getData() << std::endl;


    return 0;
}
