/*
 * Source.cpp
 *
 *  Created on: 7 февр. 2020 г.
 *      Author: dmitry.kozlov
 */

#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <sys/stat.h>


class Phone_book
{
	Phone_book(){}
	~Phone_book(){}


};

int main()
{
	srand(1234);

	std::unordered_multimap<std::string, std::string> mapa;
	std::ifstream inf("../data/data.txt");

	if (!inf)
	{
		std::cout << "1";
		exit(1);
	}

	int t;
	std::string tel;

	while(inf)
	{
		std::string input;

		t = 100000000 + rand()%900000000;
		tel = "+7" + std::to_string(t);

		inf >> input;
		mapa.insert(std::make_pair(input, tel));
	}

	for (auto a: mapa)
	{
		std::cout << a.first << "\t" << a.second << "\n";
	}
	inf.close();

	struct stat fi;
	stat("../data/data.txt",&fi);
	printf("file size: %d", fi.st_size);


	std::ofstream outf("../data/data.txt");

	if (!outf)
	{
		std::cout << "2";
		exit(2);
	}
	for (auto a: mapa)
	{
		outf << a.first << "\t" << a.second << "\n";
	}
return 0;
}





