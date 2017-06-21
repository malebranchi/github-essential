#include <streambuf>  // for std::streambuf
#include <ostream>    // for std::ostream
#include <vector>
#include <memory>
#include <map>
#include <string>
#include <iostream>
#include <ostream>
#include <iterator>
#include <algorithm>

#include <stdio.h>
#include <stdlib.h>
#include <map>
#include <functional>

#include <iostream>
#include <vector>
#include <numeric>
#include <string>
#include <functional>

static int s_i = 0;

struct TestStruct
{
	int x;
	int y;

	TestStruct() {}
	TestStruct(int x, int y) : x(x), y(y) {}

	static TestStruct& getNext()
	{
		TestStruct ts;
		ts.x = s_i++;
		ts.y = s_i++;

		return ts;
	}
};

std::ostream& operator<<(std::ostream& os, const TestStruct& obj)
{
	return os << "x: " << obj.x << " y: " << obj.y;
}
/*
int main(void)
{
	std::vector<TestStruct> vec(10);

	std::generate(std::begin(vec), std::end(vec), []{ return TestStruct::getNext(); });
	std::copy(std::begin(vec), std::end(vec), std::ostream_iterator<TestStruct>(std::cout, "\n" ));

	std::cout << "acc: " << std::accumulate(std::begin(vec), std::end(vec), 0, [](int acc, const TestStruct& obj) { return acc + std::abs(obj.x - obj.y); }) << std::endl;

	return 0;
}*/

int main()
{
	std::vector<int> a{ 0, 1, 2, 7, 4 };
	std::vector<int> b{ 5, 4, 2, 3, 1 };

	int r1 = std::inner_product(a.begin(), a.end(), b.begin(), 0);
	std::cout << "Inner product of a and b: " << r1 << '\n';

	int r2 = std::inner_product(a.begin(), a.end(), b.begin(), 0, std::plus<>(), std::less<>());
	std::cout << "Number of pairwise matches between a and b: " << r2 << '\n';
}