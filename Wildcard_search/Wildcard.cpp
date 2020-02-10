
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>


using MapN = std::map<std::string, std::vector<std::string>>;
using MapT = std::map<std::string, std::string>;

using IteratorN = MapN::iterator;
using IteratorT = MapT::iterator;

class Tel_book
{
public:
	Tel_book(const char* p) : path(p)
	{
		inf.open(path);

		if (!inf)
		{
			std::cerr << "Could not be opened file!" << std::endl;
			exit(1);
		}

		std::string buff;
		std::stringstream s;
		while (inf)
		{
			getline(inf, buff);
			s.write(buff.c_str(), buff.length());
			
			if (s.str() == "")
				break;
			
			std::string buff_n, buff_t;
			s >> buff_n;
			s >> buff_t;
			//std::cout << "n = " << buff_n << "\t" << "t = " << buff_t << "\n";

			std::pair<IteratorT, bool> t_new;
			std::pair<IteratorN, bool> n_new;

			t_new = tel.insert(std::make_pair(buff_t, "")); // try to insert tel

			if (t_new.second) // if new telefone
			{
				std::vector<std::string> v = { buff_t };
				
				n_new = sure_name.insert(std::make_pair(buff_n, v));  // try to insert name

				t_new.first->second = buff_n; // add name pos

				if (!n_new.second)  // if tel exist
				{
					n_new.first->second.push_back(buff_t); // push tel pos
				}
				else  // if new name
				{
					// nothing
				}
			}
			else // if tel exist
			{
				// nothing
			}


			s.str(std::string());
			s.clear();
		}

		// fill index
		int i = 0, ii = 0;
		char k0;
		std::string k1;
		for (IteratorN k = sure_name.begin(); k != sure_name.end(); ++k)
		{
			if (k == sure_name.begin())
			{
				idx2.insert(std::make_pair(k->first.substr(0,2), std::make_pair(0, 0)));
				idx1.insert(std::make_pair(k->first[0], std::make_pair(0, 0)));
				k1 = k->first.substr(0, 2);
				k0 = k->first[0];
				++i;
			}
			else
			{	
				if (k->first[0] != k0)
				{
					(--idx1.end())->second.second = i - 1;
					k0 = k->first[0];
					idx1.insert(std::make_pair(k0, std::make_pair(i, 0)));
				}
				if (k->first.substr(0, 2) != k1 || k->first[0] != k0)
				{
					(--idx2.end())->second.second = ii - 1;
					k1 = k->first.substr(0, 2);
					idx2.insert(std::make_pair(k1, std::make_pair(ii, 0)));
					++i;
				}
			}
			++ii;
		}
		(--idx2.end())->second.second = ii;
		(--idx1.end())->second.second = i;
	}

	Tel_book() : Tel_book("../../data/data.txt")
	{

	}

	Tel_book(const Tel_book&) = delete;

	~Tel_book()
	{
		inf.close();
	}

	int showAll()
	{
		if (!sure_name.size())
		{
			std::cout << "Tel book is empty!";
			return -1;
		}

		for (auto person : sure_name)
		{
			std::cout << "\n" << person.first << "\n";
			for (auto var : person.second)
			{
				std::cout << "\t" << var << "\n";
			}
		}

		return 0;
	}

	int search(const std::string& str)
	{
		std::stringstream s(str);
		std::string buff;

		if (str == "")
			return -1;
		s >> buff;

		if (buff[0] == '+')
		{
			IteratorT t = tel.find(buff);
			if (t != tel.end())
				std::cout << "\n" << t->first + "\t" + t->second;
			else
				std::cout << "Not found\n";
		}
			
		else
		{
			IteratorN n = sure_name.find(buff);
			if (n != sure_name.end())
			{
				std::cout << "\n" << n->first;
				for (auto a : n->second)
					std::cout << "\n\t" << a;
			}
			else
				std::cout << "Not found\n";
			
		}

		return 0;
	}

	int wildcard(const std::string& str)
	{
		std::stringstream s(str);
		std::string buff;
		s.write(buff.c_str(), buff.length());

		if (s.str() == "")
			return -1;

		std::string buff_n, buff_t;
		s >> buff_n;
		s >> buff_t;

		if (buff_n == "*" && buff_t != "" && buff_t != "*")
		{
			if (buff_t.find('*') != -1)
				for (auto a : tel)
					if (buff_t.substr(0, buff_t.size() - 1) == a.first.substr(0, buff_t.size() - 1))
						std::cout << '\n' << a.first << '\t' << a.second;
			return 0;
		}

		if (buff_n.size() == 2)
		{
			auto a = idx1.find(buff_n[0]);
			if (a != idx1.end())
			{
				auto start = sure_name.begin();
				auto end = sure_name.begin();
				auto idx2_start = idx2.begin();
				auto idx2_end = idx2.begin();
				std::advance(idx2_start, a->second.first);
				std::advance(idx2_end, a->second.second);
				std::advance(start, idx2_start->second.first);
				std::advance(end, idx2_end->second.second);

				++end;
				while(start != end)
				{
					//std::cout << start->first << '\n';
					for (auto t : start->second)
					{
						if (buff_t != "" && buff_t != "*")
						{
							if (buff_t.find('*') != -1)
								if (buff_t.substr(0, buff_t.size() - 1) == t.substr(0, buff_t.size() - 1))
									std::cout << start->first << "\t" << t << "\n";
								else 
								{
								
								}
							else // if (buff_t.find('*') != -1)
							{
								if (buff_t == t)
									std::cout << start->first << "\t" << t << "\n";
							}
						}
						else
						{
							std::cout << start->first << "\t" << t << "\n";
						}
					}
					start++;
				}
			}
			else
			{
				std::cout << "Not found\n";
				return -1;
			}
		return 0;
		}

		auto a = idx1.find(buff_n[0]);
		if (a != idx1.end())
		{
			auto start = sure_name.begin();
			auto end = sure_name.begin();
			auto idx2_start = idx2.begin();
			auto idx2_end = idx2.begin();
			std::advance(idx2_start, a->second.first);
			std::advance(idx2_end, a->second.second);
			
			auto val = buff_n.substr(0, 2);
			auto b = std::find_if(idx2_start, idx2_end, 
				[val](const std::pair<std::string, std::pair<int, int>>& t) -> bool {
				return t.first == val;
				}
			);

			std::advance(start, b->second.first);
			std::advance(end, b->second.second);

			++end;
			while (start != end)
			{
				//std::cout << start->first << '\n';
				for (auto t : start->second)
				{
					if (buff_t != "" && buff_t != "*")
					{
						if (buff_t.find('*') != -1)
							if (buff_t.substr(0, buff_t.size() - 1) == t.substr(0, buff_t.size() - 1))
								std::cout << start->first << "\t" << t << "\n";
							else
							{

							}
						else // if (buff_t.find('*') != -1)
						{
							if (buff_t == t)
								std::cout << start->first << "\t" << t << "\n";
						}
					}
					else
					{
						std::cout << start->first << "\t" << t << "\n";
					}
				}
				start++;
			}
		}
		else
		{
			std::cout << "Not found\n";
			return -1;
		}


		return 0;
	}

private:
	const char* path;
	std::ifstream inf;

	MapN sure_name;
	MapT tel;

	std::map<std::string, std::pair<int, int>> idx2; // index level 2
	std::map<char, std::pair<int, int>> idx1; // index level 1
};

int main()
{

	Tel_book tel_book;

	char q;
	while (true)
	{
		std::cout << "\nPress 0 for show all tel book\nPress 1 for search\nPress q for exit\n";
		std::cin.get(q);
		std::cin.ignore(std::cin.rdbuf()->in_avail(), '\n');
		
		std::string search_buff;
		switch (q)
		{
		case 'q':
			return 0;
			break;
		case '0':
			tel_book.showAll();
			break;
		case '1':
			std::cout << "Insert request in format [Name[*]] [+7Tel[*]]\n";
			std::getline(std::cin, search_buff);
			if (search_buff.find('*') == -1)
				tel_book.search(search_buff);
			else
				tel_book.wildcard(search_buff);
			break;
		default:
			break;
		}
	}
	
	

	return 0;
}
