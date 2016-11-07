#include "strBlob.hpp"

StrBlob::StrBlob(): data_(std::make_shared<std::vector<std::string>>()) 
{ 
}

StrBlob::StrBlob(std::initializer_list<std::string> il) : \
   data_(std::make_shared<std::vector<std::string>>(il))
{ 

}

StrBlob::~StrBlob()
{

}

bool StrBlob::isEmpty() const
{
	return data_->empty();
}

StrBlob::size_type StrBlob::size() const
{
	return data_->size();
}

void StrBlob::check(size_type length, const std::string& msg)
{
	if(length >= data_->size())
		throw std::out_of_range(msg);
}

std::string& StrBlob::front()
{
	check(0, "Cannot fetch front element....");
	return data_->front();
} 

std::string& StrBlob::back()
{
	check(0, "Cannot fetch back element....");
	return data_->back();
}

void StrBlob::push_back(const std::string& str)
{
	data_->push_back(str);
}

void StrBlob::pop_back()
{
	check(0, "Cannot pop back....");
	data_->pop_back();
}

void StrBlob::printElements()
{
	/*for (auto itr = data_->begin(); itr!= data_->end(); ++itr)
	{
        std::cout << "Element is : " << *itr << std::endl;
	}*/

	for(auto str: *data_)
	{
		std::cout << "Element: " << str << std::endl;
	}
}

