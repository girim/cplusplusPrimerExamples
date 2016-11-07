#include <iostream>

class Triangle
{
	public:
		explicit Triangle(int sideA = 1, int sideB = 1, int sideC = 1) : \
			sideA_(sideA), sideB_(sideB), sideC_(sideC) {}
		 //Triangle() = default;
		~Triangle() {};

		int getSideA() const { return sideA_;}
		int getSideB() const { return sideB_;}
		int getSideC() const { return sideC_;}

	private:
		int sideA_;
		int sideB_;
		int sideC_;
};

std::ostream& operator<<(std::ostream& os, const Triangle& triangle)
{
	os << "{ sideA: " << triangle.getSideA() << \
			", sideB: " << triangle.getSideB() << \
			", sideC: " << triangle.getSideC() << " }";
	return os;
}

int main(int argc, char const *argv[])
{
	Triangle triangle_0 {};
	Triangle triangle_1 {2,2,3};

	std::cout << triangle_0 << std::endl;
	std::cout << triangle_1 << std::endl;

	return 0;
}