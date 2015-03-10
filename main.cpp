#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>


std::string &ltrim(std::string &s)
{
        s.erase(s.begin(), std::find_if(s.begin(), s.end(), std::not1(std::ptr_fun<int, int>(std::isspace))));
        return s;
}

// trim from end
std::string &rtrim(std::string &s)
{
        s.erase(std::find_if(s.rbegin(), s.rend(), std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
        return s;
}

// trim from both ends
std::string &trim(std::string &s)
{
        return ltrim(rtrim(s));
}


std::vector<int>			*split_line(std::string line, std::string delimiter, int size)
{
	std::vector<int>		*ret = new std::vector<int>();
	int						idx;
	int						i = 0;

	line = trim(line);

	while (i < size && (idx = line.find(delimiter)))
	{
		ret->push_back(atoi(line.substr(0, idx).c_str()));
		if (i < (size - 1))
			line = line.substr(idx, line.length() - idx);
		line = trim(line);
		i++;
	}
	return ret;
}

int main ()
{
	std::string				name;
	int						size = 0;

	std::vector<std::vector<int> *>		array;

	std::getline (std::cin, name);
	std::getline (std::cin, name);

	size = std::atoi(name.c_str());

	for (int i = 0; i < size; i++)
	{
		std::getline (std::cin, name);
		array.push_back(split_line(name, " ", size));
	}

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			std::cout << array.at(i)->at(j);
			if (j < (size - 1))
				std::cout << " ";
		}
		std::cout << std::endl;
	}

	return (0);
}