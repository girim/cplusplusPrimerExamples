#include <iostream>

class Quote
{
 public:
    std::string isbn() const;
    virtual double net_price(std::size_t n ) const;

 protected:
    double price = 0.0;
};

std::string Quote::isbn() const
{
     std::string isbnNum = "ISBN12345";
     std::cout << "ISBN number is : " << isbnNum << std::endl;
     return isbnNum;
}

double Quote::net_price(std::size_t n) const
{
    double netPrice = n * price;
    std::cout << "Net price for Quote is : " <<  netPrice << std::endl;
    return netPrice;
}

class BulkQuote : public Quote
{
  public:
    //std::string isbn() const;
    double net_price(std::size_t n) const override;
};

/*
std::string BulkQuote::isbn() const
{
     std::string isbnNum = "ISBN12345";
     std::cout << "ISBN number bulk is : " << isbnNum << std::endl;
     return isbnNum;
}*/

double BulkQuote::net_price(std::size_t n) const
{
   //double netPrice =  n * 400;
   double netPrice =  n * price;
   std::cout << "Net price for BulkQuote is : " <<  netPrice << std::endl;
   return netPrice;
}


int main()
{
   Quote quote;
   quote.isbn();
   quote.net_price(10);

   BulkQuote bulkQuote;
   bulkQuote.isbn();
   bulkQuote.net_price(10);

}
