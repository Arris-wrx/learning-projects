
#include <iostream>
#include <cstdlib>
#include <chrono>
#include <array>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>

constexpr size_t n = 10000000;

using time_s = std::chrono::high_resolution_clock;
using second = std::chrono::duration<double, std::ratio<1>>;

std::chrono::time_point<time_s> timer;

void start ()
{
	timer = time_s::now();
}

auto stop()
{
	return std::chrono::duration_cast<second>(time_s::now() - timer).count();
}

int main()
{
	std::cout << "Hello!" << std::endl;
//-----------declare variables
	double t = 0;
	auto arr = new std::array<int, n>; // такое объ€вление, потому что Linux создает на стеке
	std::vector<int> vector;
	std::deque<int> deq;
	std::list<int> list;
	std::set<int> set;
	std::map<int, int> map;
	std::unordered_set<int> u_set;
	std::unordered_map<int, int> u_map;

	srand(1234);
//-----insert elements

	std::cout << "Insert time" << std::endl;

	start();
	for (size_t i = 0; i < n; ++i)
	{
		arr->at(i) = i;
	}
	t = stop();
	std::cout << "\tArray: " << t << std::endl;


	start();
	for (size_t i = 0; i < n; ++i)
	{
		vector.push_back(i);
	}
	t = stop();
	std::cout << "\tVector: " << t << std::endl;

	vector.clear();
	vector.shrink_to_fit();
	vector.reserve(n);
	start();
	for (size_t i = 0; i < n; ++i)
	{
		vector.push_back(i);
	}
	t = stop();
	std::cout << "\tVector reserved memory: " << t << std::endl;

	start();
	for (size_t i = 0; i < n; ++i)
	{
		deq.push_back(i);
	}
	t = stop();
	std::cout << "\tDeque: " << t << std::endl;

	start();
	for (size_t i = 0; i < n; ++i)
	{
		list.push_back(i);
	}
	t = stop();
	std::cout << "\tList: " << t << std::endl;

	start();
	for (size_t i = 0; i < n; ++i)
	{
		set.insert(i);
	}
	t = stop();
	std::cout << "\tSet: " << t << std::endl;

	start();
	for (size_t i = 0; i < n; ++i)
	{
		map.insert(std::make_pair(i, i+100));
	}
	t = stop();
	std::cout << "\tMap: " << t << std::endl;

	start();
	for (size_t i = 0; i < n; ++i)
	{
		u_set.insert(i);
	}
	t = stop();
	std::cout << "\tU_Set: " << t << std::endl;

	start();
	for (size_t i = 0; i < n; ++i)
	{
		u_map.insert(std::make_pair(i, i+100));
	}
	t = stop();
	std::cout << "\tU_Map: " << t << std::endl;

//-----------get one value

	std::cout << "Search time:" << std::endl;

	int a = 0;
	int temp;
	std::set<int>::iterator it1;
	std::map<int,int>::iterator it2;
	std::unordered_set<int>::iterator it3;
	std::unordered_map<int,int>::iterator it4;

	start();
	for (size_t i = 0; i < n/10; ++i)
	{
		a = rand()%(n-1);
		temp = (*arr)[a];
	}
	t = stop();
	std::cout << "\tArray: " << t << std::endl;

	start();
	for (size_t i = 0; i < n; ++i)
	{
		a = rand()%(n-1);
		temp = vector[a];
	}
	t = stop();
	std::cout << "\tVector: " << t << std::endl;

	start();
	for (size_t i = 0; i < n; ++i)
	{
		a = rand()%(n-1);
		temp = deq[a];
	}
	t = stop();
	std::cout << "\tDeque: " << t << std::endl;

	start();
	for (size_t i = 0; i < n; ++i)
	{
		a = rand()%(n-1);
		it1 = set.find(a);
	}
	t = stop();
	std::cout << "\tSet: " << t << std::endl;

	start();
	for (size_t i = 0; i < n; ++i)
	{
		a = rand()%(n-1);
		it3 = u_set.find(a);
	}
	t = stop();
	std::cout << "\tSet: " << t << std::endl;

	start();
	for (size_t i = 0; i < n; ++i)
	{
		a = rand()%(n-1);
		it4 = u_map.find(a);
	}
	t = stop();
	std::cout << "\tMap: " << t << std::endl;

//----------delete elements
	std::cout << "Delete time:" << std::endl;

	start();
	for (size_t i = 0; i < n; ++i)
	{
		vector.pop_back();
	}
	t = stop();
	std::cout << "\tVector: " << t << std::endl;

	start();
	for (size_t i = 0; i < n; ++i)
	{
		deq.pop_back();
	}
	t = stop();
	std::cout << "\tDeque: " << t << std::endl;

	start();
	for (size_t i = 0; i < n; ++i)
	{
		list.pop_back();
	}
	t = stop();
	std::cout << "\tList: " << t << std::endl;

	start();
	for (size_t i = 0; i < n; ++i)
	{
		set.erase(i);
	}
	t = stop();
	std::cout << "\tSet: " << t << std::endl;

	start();
	for (size_t i = 0; i < n; ++i)
	{
		map.erase(i);
	}
	t = stop();
	std::cout << "\tMap: " << t << std::endl;

	start();
	for (size_t i = 0; i < n; ++i)
	{
		u_set.erase(i);
	}
	t = stop();
	std::cout << "\tU_Set: " << t << std::endl;

	start();
	for (size_t i = 0; i < n; ++i)
	{
		u_map.erase(i);
	}
	t = stop();
	std::cout << "\tU_Map: " << t << std::endl;

	delete arr;
	return 0;
}
