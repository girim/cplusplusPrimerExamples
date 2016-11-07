#ifndef __PARTIAL_SPECIALIZATION_WITH_MULTI_PARAMS__
#define __PARTIAL_SPECIALIZATION_WITH_MULTI_PARAMS__

/* 1. */
template<typename T1, typename T2>
class MyClass
{
    public:
        MyClass(std::string name = "[T1,T2]");
        ~MyClass();
        std::string getName();
    private:
        std::string name_;
        T1 t1_;
        T2 t2_;
};

template<typename T1, typename T2>
MyClass<T1, T2>::MyClass(std::string name) :name_(name){}

template<typename T1, typename T2>
MyClass<T1, T2>::~MyClass(){}

template<typename T1, typename T2>
std::string MyClass<T1, T2>::getName()
{
    return name_;
}

/* 2. */
template<typename T>
class MyClass<T,T>
{
    public:
        MyClass(std::string name = "[T,T]");
        ~MyClass();
        std::string getName();
    private:
        std::string name_;
        T t1_;
};

template<typename T>
MyClass<T,T>::MyClass(std::string name) : name_(name) {}

template<typename T>
MyClass<T,T>::~MyClass() {}

template<typename T>
std::string MyClass<T,T>::getName()
{
    return name_;
}

/* 3. */
template<typename T>
class MyClass<T, char>
{
    public:
        MyClass(std::string name = "[T, char]");
        ~MyClass();
        std::string getName();

    private:
        std::string name_;
        T t1_;
};

template<typename T>
MyClass<T, char>::MyClass(std::string name) : name_(name) {}

template<typename T>
MyClass<T, char>::~MyClass() {}

template<typename T>
std::string MyClass<T,char>::getName()
{
    return name_;
}

/* 4. */
template<typename T1, typename T2>
class MyClass<T1*, T2*>
{
    public:
        MyClass(std::string name = "[T1*,T2*]");
        ~MyClass();
        std::string getName();
    private:
        std::string name_;
        T1* t1_;
        T2* t2_;
};

template<typename T1, typename T2>
MyClass<T1*, T2*>::MyClass(std::string name) : name_(name){}

template<typename T1, typename T2>
MyClass<T1*, T2*>::~MyClass() {}

template<typename T1, typename T2>
std::string MyClass<T1*, T2*>::getName()
{
    return name_;
}

/* 5. */
template<typename T>
class MyClass<T*, T*>
{
    public:
        MyClass(std::string name = "[T*,T*]");
        ~MyClass();
        std::string getName();

    private:
        std::string name_;
        T* t_;
};

template<typename T>
MyClass<T*, T*>::MyClass(std::string name) :name_(name) {}

template<typename T>
MyClass<T*, T*>::~MyClass() {}

template<typename T>
std::string MyClass<T*, T*>::getName()
{
    return name_;
}
#endif //__PARTIAL_SPECIALIZATION_WITH_MULTI_PARAMS__