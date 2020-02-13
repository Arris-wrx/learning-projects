
#include <iostream>
#include <fstream>
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
#include <limits.h>

constexpr size_t n = 1'000'000;
//---------------prod
struct Prod1
{
	size_t id;
	double price;

	Prod1()
	{

	}

	Prod1(size_t i, double d) : id(i), price(d)
	{

	}
	
	Prod1(const Prod1 &p) : id(p.id), price(p.price)
	{

	}
};

bool operator< (const Prod1& p1, const Prod1& p2)
{
	return p1.id < p2.id;
}

bool operator== (const Prod1& p1, const Prod1& p2)
{
	return p1.id == p2.id && p1.price == p2.price;
}

template<> struct std::hash<Prod1> {
	size_t operator() (const Prod1& arg) const {
		return arg.id;
	}
};


struct Prod
{
	size_t id;
	double price;

	Prod()
	{

	}

	Prod(size_t i, double d) : id(i), price(d)
	{

	}
	
	Prod(const Prod &p) : id(p.id), price(p.price)
	{

	}
};

bool operator< (const Prod& p1, const Prod& p2)
{
	return p1.id < p2.id;
}

bool operator== (const Prod& p1, const Prod& p2)
{
	return p1.id == p2.id && p1.price == p2.price;
}

template<> struct std::hash<Prod> {
	size_t operator() (const Prod& arg) const {
		size_t h1 = hash<size_t>{}(arg.id);
		size_t h2 = hash<double>{}(arg.price);

		return h1 ^ (h2 >> 1) ^ (h2 << (sizeof(size_t)*CHAR_BIT - 1));
	}
};

//--------------timer

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
	
	std::ofstream outf ("../../data/time1.txt");
	
	std::cout << "Hello!" << std::endl;
	outf << "Hello!" << std::endl;
//-----------declare variables
	double t = 0;
	//auto arr = new std::array<Prod, n>; 
	
	Prod P = { 0, 0 };
	Prod1 P1 = { 0, 0 };
	
	//std::vector<Prod> vector;
	//std::deque<Prod> deq;
	//std::list<Prod> list;
	//std::set<Prod> set;
	//std::map<Prod, int> map;
	std::unordered_set<Prod> u_set;
	std::unordered_map<Prod, int> u_map;
	std::unordered_set<Prod1> u_set1;
	std::unordered_map<Prod1, int> u_map1;

	srand(1234);
//-----insert elements

/*	std::cout << "Insert time" << std::endl;

	start();
	for (size_t i = 0; i < n; ++i)
	{
		P = { i, (double)i * 100 / INT_MAX };
		arr->at(i) = P;
	}
	t = stop();
	std::cout << "\tArray: " << t << std::endl;


	start();
	for (size_t i = 0; i < n; ++i)
	{
		P = { i, (double)i * 100 / INT_MAX };
		vector.push_back(P);
	}
	t = stop();
	std::cout << "\tVector: " << t << std::endl;

	vector.clear();
	vector.shrink_to_fit();
	vector.reserve(n);
	start();
	for (size_t i = 0; i < n; ++i)
	{
		P = { i, (double)i * 100 / INT_MAX };
		vector.push_back(P);
	}
	t = stop();
	std::cout << "\tVector reserved memory: " << t << std::endl;

	start();
	for (size_t i = 0; i < n; ++i)
	{
		P = { i, (double)i * 100 / INT_MAX };
		deq.push_back(P);
	}
	t = stop();
	std::cout << "\tDeque: " << t << std::endl;

	start();
	for (size_t i = 0; i < n; ++i)
	{
		P = { i, (double)i * 100 / INT_MAX };
		list.push_back(P);
	}
	t = stop();
	std::cout << "\tList: " << t << std::endl;

	start();
	for (size_t i = 0; i < n; ++i)
	{
		P = { i, (double)i * 100 / INT_MAX };
		set.insert(P);
	}
	t = stop();
	std::cout << "\tSet: " << t << std::endl;

	start();
	for (size_t i = 0; i < n; ++i)
	{
		P = { i, (double)i * 100 / INT_MAX };
		map.insert(std::make_pair(P, i+100));
	}
	t = stop();
	std::cout << "\tMap: " << t << std::endl;
*/
	start();
	for (size_t i = 0; i < n; ++i)
	{
		P = { i, (double)i * 100 / INT_MAX };
		u_set.insert(P);
	}
	t = stop();
	std::cout << "\tU_Set: " << t << std::endl;
	outf << "\tU_Set: " << t << std::endl;

	start();
	for (size_t i = 0; i < n; ++i)
	{
		P = { i, (double)i * 100 / INT_MAX };
		u_map.insert(std::make_pair(P, i+100));
	}
	t = stop();
	std::cout << "\tU_Map: " << t << std::endl;
	outf << "\tU_Map: " << t << std::endl;
	
	start();
	for (size_t i = 0; i < n; ++i)
	{
		P1 = { i, (double)i * 100 / INT_MAX };
		u_set1.insert(P1);
	}
	t = stop();
	std::cout << "\tU_Set1: " << t << std::endl;
	outf << "\tU_Set1: " << t << std::endl;

	start();
	for (size_t i = 0; i < n; ++i)
	{
		P1 = { i, (double)i * 100 / INT_MAX };
		u_map1.insert(std::make_pair(P1, i+100));
	}
	t = stop();
	std::cout << "\tU_Map1: " << t << std::endl;
	outf << "\tU_Map1: " << t << std::endl;

//-----------get one value

	std::cout << "Search time:" << std::endl;
	outf << "Search time:" << std::endl;

	size_t a = 0;
/*	Prod temp;
	std::set<Prod>::iterator it1;
	std::map<Prod,int>::iterator it2;
	std::unordered_set<Prod>::iterator it3;
	std::unordered_map<Prod,int>::iterator it4;
*/
/*	start();
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
		P = { a, (double)a * 100 / INT_MAX };
		it1 = set.find(P);
	}
	t = stop();
	std::cout << "\tSet: " << t << std::endl;

	start();
	for (size_t i = 0; i < n; ++i)
	{
		a = rand() % (n - 1);
		P = { a, (double)a * 100 / INT_MAX };
		it2 = map.find(P);
	}
	t = stop();
	std::cout << "\tMap: " << t << std::endl;
*/
	
	start();
	for (size_t i = 0; i < n; ++i)
	{
		a = rand()%(n-1);
		P = { a, (double)a * 100 / INT_MAX };
	auto it3 = u_set.find(P);
	}
	t = stop();
	std::cout << "\tU_Set: " << t << std::endl;
	outf << "\tU_Set: " << t << std::endl;

	start();
	for (size_t i = 0; i < n; ++i)
	{
		a = rand()%(n-1);
		P = { a, (double)a * 100 / INT_MAX };
		auto it4 = u_map.find(P);
	}
	t = stop();
	std::cout << "\tU_Map: " << t << std::endl;
	outf << "\tU_Map: " << t << std::endl;
	
	
	start();
	for (size_t i = 0; i < n; ++i)
	{
		a = rand()%(n-1);
		P1 = { a, (double)a * 100 / INT_MAX };
	auto it5 = u_set1.find(P1);
	}
	t = stop();
	std::cout << "\tU_Set1: " << t << std::endl;
	outf << "\tU_Set1: " << t << std::endl;

	start();
	for (size_t i = 0; i < n; ++i)
	{
		a = rand()%(n-1);
		P1 = { a, (double)a * 100 / INT_MAX };
		auto it6 = u_map1.find(P1);
	}
	t = stop();
	std::cout << "\tU_Map1: " << t << std::endl;
	outf << "\tU_Map1: " << t << std::endl;

//----------delete elements
	std::cout << "Delete time:" << std::endl;
	outf << "Delete time:" << std::endl;

/*	start();
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
		P = { i, (double)i * 100 / INT_MAX };
		set.erase(P);
	}
	t = stop();
	std::cout << "\tSet: " << t << std::endl;

	start();
	for (size_t i = 0; i < n; ++i)
	{
		P = { i, (double)i * 100 / INT_MAX };
		map.erase(P);
	}
	t = stop();
	std::cout << "\tMap: " << t << std::endl;
*/

	start();
	for (size_t i = 0; i < n; ++i)
	{
		P = { i, (double)i * 100 / INT_MAX };
		u_set.erase(P);
	}
	t = stop();
	std::cout << "\tU_Set: " << t << std::endl;
	outf << "\tU_Set: " << t << std::endl;

	start();
	for (size_t i = 0; i < n; ++i)
	{
		P = { i, (double)i * 100 / INT_MAX };
		u_map.erase(P);
	}
	t = stop();
	std::cout << "\tU_Map: " << t << std::endl;
	outf << "\tU_Map: " << t << std::endl;
	
	
		start();
	for (size_t i = 0; i < n; ++i)
	{
		P1 = { i, (double)i * 100 / INT_MAX };
		u_set1.erase(P1);
	}
	t = stop();
	std::cout << "\tU_Set1: " << t << std::endl;
	outf << "\tU_Set1: " << t << std::endl;

	start();
	for (size_t i = 0; i < n; ++i)
	{
		P1 = { i, (double)i * 100 / INT_MAX };
		u_map1.erase(P1);
	}
	t = stop();
	std::cout << "\tU_Map1: " << t << std::endl;
	outf << "\tU_Map1: " << t << std::endl;

	outf.close();
	//delete arr;
	return 0;
}
