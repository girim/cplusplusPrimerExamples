#include <iostream>
#include <cstring>

class salesData
{
public:
	salesData(std::string bookno ="", unsigned int unitsSold = 0): \
		bookNo_(bookno),unitsSold_(unitsSold){}
	~salesData(){}

    
    double getRevenue()
    {
    	return revenue_ = unitsSold_ * price;
    }

    unsigned int getUnitsSold()
    {
    	return unitsSold_;
    }

    void setUnitsSold(unsigned int unitsSold)
    {
    	unitsSold_ = unitsSold; 
    }

    std::string getBookNo()
    {
    	return bookNo_;
    }

    salesData& operator+=(const salesData& rhs)
    {
    	this->unitsSold_ += rhs.getUnitsSold();
    	return *this;
    }

    salesData& operator-=(const salesData& rhs)
    {
    	this->unitsSold_ -= rhs.getUnitsSold();
    	return *this;
    }

    unsigned  int price = 100;
    
private:
	std::string bookNo_;
	unsigned int unitsSold_;
	double revenue_;
};
	
salesData operator+(const salesData& lhs, const salesData& rhs)
{
	std::cout <<"overloaded + operator called ...." << std::endl;
	salesData sum = lhs;
	sum += rhs;
    return sum;
}

salesData operator-(const salesData& lhs, const salesData& rhs)
{
	std::cout << "overloaded - operator called ...." << std::endl;
	salesData diff = lhs;
	diff -= rhs;
	return diff;
}

int main()
{
    salesData data1("Book-1", 20);
    salesData data2("Book-1", 40);

    salesData sum = data1 + data2;
    std::cout << "Revenue from " << sum.getBookNo() << " sales is: " << sum.getRevenue() << std::endl;

    salesData diff = data2 - data1;
    std::cout << "Revenue from " << diff.getBookNo() <<" sales is: " << diff.getRevenue() << std::endl;
}