#include <iostream>
#include <thread>
#include <vector>

class Wallet
{
public:
	Wallet():money_(0){}
	~Wallet() = default;

	void addMoney(int money)
	{
		for(int index = 0; index < money; ++index)
		{
			//std::cout << "Adding money: " << index << std::endl;
			money_++;
		}
	}

	int getMoney()
	{
		return money_;
	}

private:
	int money_;

};


int testMultithreadedWallet()
{
	Wallet wallet;
	std::vector<std::thread> threadPool;

	for(int iter = 0; iter < 5; iter++)
	{
		threadPool.push_back(std::thread(&Wallet::addMoney, &wallet, 2000));
	}

	for (int index = 0; index < threadPool.size(); index++)
	{
		threadPool.at(index).join();
	}

	return wallet.getMoney();
}

int main ()
{
	int val = 0;

	for(int index = 0; index < 1000; index++)
	{
		val = testMultithreadedWallet();
		//std::cout <<" Val is : " << val << std::endl;
		if(val != 10000)
		{
			std::cout << "Error at count: " << index << " Money at the wallet: " << val << std::endl;
		}		
	}

	return 0;
}