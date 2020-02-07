
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>

class Tel_book
{
	Tel_book()
	{
		std::cout << "Construct";
		inf.open(path);

		if (!inf)
		{
			std::cerr << "Could not be opened file!" << std::endl;
			exit(1);
		}

		std::string buff;
		std::stringstream s;
		while(inf)
		{
			getline(inf, buff);
			s.write(buff.c_str(), buff.length());
			std::string buff1, buff2;
			s >> buff1;
			s >> buff2;
			std::cout << "f = " << buff1 << "\t" << "t = " << buff2 << "\n";
		}
	};
	Tel_book(const Tel_book&) = delete;

	~Tel_book()
	{
		inf.close();
	}

private:
	const char* path = "../data/data.txt";
	std::ifstream inf;

	std::map<std::string, std::map<std::string, int>::iterator> sure_name;
	std::map<std::string, std::map<std::string, int>::iterator> tel;
};

int main()
{

	std::cout << "1";
	Tel_book tel_book();

	int a;
	std::cin >> a;

	return 0;
}





