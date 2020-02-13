
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
#include <random>
#include <algorithm>

constexpr size_t n = 5'000'000;

using time_s = std::chrono::high_resolution_clock;
using second = std::chrono::duration<double, std::ratio<1>>;

std::chrono::time_point<time_s> timer;

void start()
{
	timer = time_s::now();
}

auto stop()
{
	return std::chrono::duration_cast<second>(time_s::now() - timer).count();
}

int main()
{

	std::ofstream outf("../../data/time.txt");

	std::cout << "Hello!" << std::endl;

	//-----------declare variables
	double t = 0; int m = 100;
	auto seq_arr = new std::array<int, n>;
	auto rand_arr = new std::array<int, n>;
	std::vector<int> seq_vector;
	std::vector<int> rand_vector;
	std::deque<int> seq_deq;
	std::deque<int> rand_deq;
	std::list<int> list;
	std::set<int> set;
	std::map<int, int> map;
	std::multiset<int> m_set;
	std::multimap<int, int> m_map;
	std::unordered_set<int> u_set;
	std::unordered_map<int, int> u_map;
	std::unordered_multiset<int> u_m_set;
	std::unordered_multimap<int, int> u_m_map;

	srand(1234);
	//------initialize start array

	auto init_arr = new std::array<int, n>;
	for (size_t i = 0; i < n; ++i)
	{
		init_arr->at(i) = i;
	}
	std::random_device rd;
	std::mt19937 g(rd());

	std::shuffle(init_arr->begin(), init_arr->end(), g);

	//-----insert elements

	std::cout << "Insert time" << std::endl;
	outf << "Insert time" << std::endl;
	// array
	start();
	for (size_t i = 0; i < n; ++i)
	{
		seq_arr->at(i) = i;
	}
	t = stop();
	std::cout << "\tSequential Array: " << t << std::endl;
	outf << "\tSequential Array: " << t << std::endl;

	start();
	for (size_t i = 0; i < n; ++i)
	{
		rand_arr->at(i) = init_arr->at(i);
	}
	t = stop();
	std::cout << "\tRandom Array: " << t << std::endl;
	outf << "\tRandom Array: " << t << std::endl;

	// vector
	start();
	for (size_t i = 0; i < n; ++i)
	{
		seq_vector.push_back(i);
	}
	t = stop();
	std::cout << "\tSequential Vector: " << t << std::endl;
	outf << "\tSequential Vector: " << t << std::endl;

	start();
	for (size_t i = 0; i < n; ++i)
	{
		rand_vector.push_back(init_arr->at(i));
	}
	t = stop();
	std::cout << "\tRandom Vector: " << t << std::endl;
	outf << "\tRandom Vector: " << t << std::endl;

	seq_vector.clear();
	seq_vector.shrink_to_fit();
	seq_vector.reserve(n);
	start();
	for (size_t i = 0; i < n; ++i)
	{
		seq_vector.push_back(i);
	}
	t = stop();
	std::cout << "\tVector reserved memory: " << t << std::endl;
	outf << "\tVector reserved memory: " << t << std::endl;

	// deque
	start();
	for (size_t i = 0; i < n; ++i)
	{
		seq_deq.push_back(i);
	}
	t = stop();
	std::cout << "\tSequential Deque: " << t << std::endl;
	outf << "\tSequential Deque: " << t << std::endl;

	start();
	for (size_t i = 0; i < n; ++i)
	{
		rand_deq.push_back(init_arr->at(i));
	}
	t = stop();
	std::cout << "\tRandom Deque: " << t << std::endl;
	outf << "\tRandom Deque: " << t << std::endl;

	// list
	start();
	for (size_t i = 0; i < n; ++i)
	{
		list.push_back(init_arr->at(i));
	}
	t = stop();
	std::cout << "\tList: " << t << std::endl;
	outf << "\tList: " << t << std::endl;

	// set & multiset
	start();
	for (size_t i = 0; i < n; ++i)
	{
		set.insert(init_arr->at(i));
	}
	t = stop();
	std::cout << "\tSet: " << t << std::endl;
	outf << "\tSet: " << t << std::endl;

	start();
	for (size_t i = 0; i < n; ++i)
	{
		m_set.insert(init_arr->at(i));
	}
	t = stop();
	std::cout << "\tM_Set: " << t << std::endl;
	outf << "\tM_Set: " << t << std::endl;

	// map & multimap
	start();
	for (size_t i = 0; i < n; ++i)
	{
		map.insert(std::make_pair(init_arr->at(i), i + m));
	}
	t = stop();
	std::cout << "\tMap: " << t << std::endl;
	outf << "\tMap: " << t << std::endl;

	start();
	for (size_t i = 0; i < n; ++i)
	{
		m_map.insert(std::make_pair(init_arr->at(i), i + m));
	}
	t = stop();
	std::cout << "\tM_Map: " << t << std::endl;
	outf << "\tM_Map: " << t << std::endl;

	// unordered_set
	start();
	for (size_t i = 0; i < n; ++i)
	{
		u_set.insert(init_arr->at(i));
	}
	t = stop();
	std::cout << "\tU_Set: " << t << std::endl;
	outf << "\tU_Set: " << t << std::endl;

	start();
	for (size_t i = 0; i < n; ++i)
	{
		u_m_set.insert(init_arr->at(i));
	}
	t = stop();
	std::cout << "\tU_M_Set: " << t << std::endl;
	outf << "\tU_M_Set: " << t << std::endl;

	// unordered_map
	start();
	for (size_t i = 0; i < n; ++i)
	{
		u_map.insert(std::make_pair(init_arr->at(i), i + m));
	}
	t = stop();
	std::cout << "\tU_Map: " << t << std::endl;
	outf << "\tU_Map: " << t << std::endl;

	start();
	for (size_t i = 0; i < n; ++i)
	{
		u_m_map.insert(std::make_pair(init_arr->at(i), i + m));
	}
	t = stop();
	std::cout << "\tU_M_Map: " << t << std::endl;
	outf << "\tU_M_Map: " << t << std::endl;

	//-----------find one value

	std::cout << "Search time:" << std::endl;
	outf << "Search time:" << std::endl;

	int a = 0;

	// array
	start();
	for (size_t i = 0; i < n / m; ++i)
	{
		std::find(rand_arr->begin(), rand_arr->end(), init_arr->at(i));
	}
	t = stop();
	std::cout << "\tFind in Random Array: " << t << std::endl;
	outf << "\tFind in Random Array: " << t << std::endl;

	start();
	for (size_t i = 0; i < n / m; ++i)
	{
		std::binary_search(seq_arr->begin(), seq_arr->end(), init_arr->at(i));
	}
	t = stop();
	std::cout << "\tBinary_search in Sorted Array: " << t << std::endl;
	outf << "\tBinary_search in Sorted Array: " << t << std::endl;

	// vector
	start();
	for (size_t i = 0; i < n / m; ++i)
	{
		std::find(rand_vector.begin(), rand_vector.end(), init_arr->at(i));
	}
	t = stop();
	std::cout << "\tFind in Random Vector: " << t << std::endl;
	outf << "\tFind in Random Vector: " << t << std::endl;

	start();
	for (size_t i = 0; i < n / m; ++i)
	{
		std::binary_search(seq_vector.begin(), seq_vector.end(), init_arr->at(i));;
	}
	t = stop();
	std::cout << "\tBinary_search in Sorted Vector: " << t << std::endl;
	outf << "\tBinary_search in Sorted Vector: " << t << std::endl;

	// deque
	start();
	for (size_t i = 0; i < n / m; ++i)
	{
		std::find(rand_deq.begin(), rand_deq.end(), init_arr->at(i));
	}
	t = stop();
	std::cout << "\tFind in Random Deque: " << t << std::endl;
	outf << "\tFind in Random Deque: " << t << std::endl;

	start();
	for (size_t i = 0; i < n / m; ++i)
	{
		std::binary_search(seq_deq.begin(), seq_deq.end(), init_arr->at(i));
	}
	t = stop();
	std::cout << "\tFind in Sorted Deque: " << t << std::endl;
	outf << "\tFind in sorted Deque: " << t << std::endl;

	// list
	start();
	for (size_t i = 0; i < n / m; ++i)
	{
		std::find(list.begin(), list.end(), init_arr->at(i));
	}
	t = stop();
	std::cout << "\tFind in Random List: " << t << std::endl;
	outf << "\tFind in Random List: " << t << std::endl;

	// set
	start();
	for (size_t i = 0; i < n / m; ++i)
	{
		set.find(init_arr->at(i));
	}
	t = stop();
	std::cout << "\tBinary_search in Set: " << t << std::endl;
	outf << "\tBinary_search in Set: " << t << std::endl;

	start();
	for (size_t i = 0; i < n / m; ++i)
	{
		m_set.find(init_arr->at(i));
	}
	t = stop();
	std::cout << "\tBinary_search in M_Set: " << t << std::endl;
	outf << "\tBinary_search in M_Set: " << t << std::endl;


	// map
	start();
	for (size_t i = 0; i < n / m; ++i)
	{
		map.find(init_arr->at(i));
	}
	t = stop();
	std::cout << "\tBinary_search in Map: " << t << std::endl;
	outf << "\tBinary_search in Map: " << t << std::endl;

	start();
	for (size_t i = 0; i < n / m; ++i)
	{
		m_map.find(init_arr->at(i));
	}
	t = stop();
	std::cout << "\tBinary_search in M_Map: " << t << std::endl;
	outf << "\tBinary_search in M_Map: " << t << std::endl;

	// u_set
	start();
	for (size_t i = 0; i < n / m; ++i)
	{
		u_set.find(init_arr->at(i));
	}
	t = stop();
	std::cout << "\tFind in U_Set: " << t << std::endl;
	outf << "\tFind in U_Set: " << t << std::endl;

	start();
	for (size_t i = 0; i < n / m; ++i)
	{
		u_m_set.find(init_arr->at(i));
	}
	t = stop();
	std::cout << "\tFind in U_M_Set: " << t << std::endl;
	outf << "\tFind in U_M_Set: " << t << std::endl;

	// u_map
	start();
	for (size_t i = 0; i < n / m; ++i)
	{
		u_map.find(init_arr->at(i));
	}
	t = stop();
	std::cout << "\tFind in U_Map: " << t << std::endl;
	outf << "\tFind in U_Map: " << t << std::endl;

	start();
	for (size_t i = 0; i < n / m; ++i)
	{
		u_m_map.find(init_arr->at(i));
	}
	t = stop();
	std::cout << "\tFind in U_M_Map: " << t << std::endl;
	outf << "\tFind in U_M_Map: " << t << std::endl;

	//----------delete elements

	std::cout << "Delete time:" << std::endl;
	outf << "Delete time:" << std::endl;
	// array
	delete rand_arr;
	delete seq_arr;

	std::cout << "Array do not access deleting" << std::endl;
	outf << "Array do not access deleting" << std::endl;
	
	// vector
	start();
	for (size_t i = 0; i < n; ++i)
	{
		rand_vector.erase(rand_vector.begin() + (rand() % (n - i)));
	}
	t = stop();
	std::cout << "\tRandom Vector: " << t << std::endl;
	outf << "\tRandom Vector: " << t << std::endl;

	start();
	for (auto it = seq_vector.begin() + n/2; it != seq_vector.end();)
	{
		it = seq_vector.erase(it != seq_vector.begin() ? it - 1 : it);
	}
	t = stop();
	std::cout << "\tSequential Vector: " << t << std::endl;
	outf << "\tSequential Vector: " << t << std::endl;

	// deque
	start();
	for (size_t i = 0; i < n; ++i)
	{
		rand_deq.erase(rand_deq.begin() + +(rand() % (n - i)));
	}
	t = stop();
	std::cout << "\tRandom Deque: " << t << std::endl;
	outf << "\tRandom Deque: " << t << std::endl;

	start();
	for (auto it = seq_deq.begin() + n/2; it != seq_deq.end();)
	{
		//seq_deq.erase(seq_deq.begin() + (n-i)/2);
		it = seq_deq.erase(it != seq_deq.begin() ? it - 1 : it);
	}
	t = stop();
	std::cout << "\tSequential Deque: " << t << std::endl;
	outf << "\tSequential Deque: " << t << std::endl;
	
	// list
	start();
	auto it_list = list.begin();
	std::advance(it_list, n/2);
	for ( ; it_list != list.end(); )
	{		
		it_list = list.erase(it_list != list.begin() ? --it_list : it_list);
	}
	t = stop();
	std::cout << "\tList: " << t << '\t' << std::endl;
	outf << "\tList: " << t << std::endl;

	//set
	start();
	auto it_set = set.begin();
	std::advance(it_set, n/2);
	for ( ; it_set != set.end(); )
	{
		it_set = set.erase(it_set != set.begin() ? --it_set : it_set);
	}
	t = stop();
	std::cout << "\tSet: " << t << std::endl;
	outf << "\tSet: " << t << std::endl;

	start();
	auto it_mset = m_set.begin();
	std::advance(it_mset, n/2);
	for ( ; it_mset != m_set.end(); )
	{
		it_mset = m_set.erase(it_mset != m_set.begin() ? --it_mset : it_mset);
	}
	t = stop();
	std::cout << "\tM_Set: " << t << std::endl;
	outf << "\tM_Set: " << t << std::endl;

	// map
	start();
	auto it_map = map.begin();
	std::advance(it_map, n/2);
	for ( ; it_map != map.end(); )
	{
		it_map = map.erase(it_map != map.begin() ? --it_map : it_map);
	}
	t = stop();
	std::cout << "\tMap: " << t << std::endl;
	outf << "\tMap: " << t << std::endl;

	start();
	auto it_mmap = m_map.begin();
	std::advance(it_mmap, n/2);
	for ( ; it_mmap != m_map.end(); )
	{
		it_mmap = m_map.erase(it_mmap != m_map.begin() ? --it_mmap : it_mmap);
	}
	t = stop();
	std::cout << "\tM_Map: " << t << std::endl;
	outf << "\tM_Map: " << t << std::endl;

	// u_set
	start();
	for (size_t i = 0; i < n; ++i)
	{
		auto it = u_set.begin();
		std::advance(it, (n - i) / 2);
		u_set.erase(it);
	}
	t = stop();
	std::cout << "\tU_Set: " << t << std::endl;
	outf << "\tU_Set: " << t << std::endl;

	start();
	for (size_t i = 0; i < n; ++i)
	{
		auto it = u_m_set.begin();
		std::advance(it, (n - i) / 2);
		u_m_set.erase(it);
	}
	t = stop();
	std::cout << "\tM_U_Set: " << t << std::endl;
	outf << "\tM_U_Set: " << t << std::endl;

	// map
	start();
	for (size_t i = 0; i < n; ++i)
	{
		auto it = u_map.begin();
		std::advance(it, (n - i) / 2);
		u_map.erase(it);
	}
	t = stop();
	std::cout << "\tU_Map: " << t << std::endl;
	outf << "\tU_Map: " << t << std::endl;

	start();
	for (size_t i = 0; i < n; ++i)
	{
		auto it = u_m_map.begin();
		std::advance(it, (n - i) / 2);
		u_m_map.erase(it);
	}
	t = stop();
	std::cout << "\tM_U_Map: " << t << std::endl;
	outf << "\tM_U_Map: " << t << std::endl;


	outf.close();
	return 0;
}
