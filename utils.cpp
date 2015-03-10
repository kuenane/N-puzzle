
#include <algorithm> 
#include <functional> 
#include <cctype>
#include <locale>

#include <abstract_vm.hpp>
#include <AbstractVM.hpp>

bool						isStringBlank(const char *s)
{
	for (int i = 0; s[i] != '\0'; i++)
	{
		if (!isblank((int)s[i]))
			return (false);
	}
	return (true);
}

// trim from start
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

bool				isInt(std::string str, std::string max)
{
	bool			neg = false;
	std::string		buf = std::string(max);
	size_t			i = -1;

	if (str[0] == '-')
	{
		neg = true;
		str = str.substr(1, str.length() - 1);
	}

	if (str.length() == 1 && str[0] == '0')
		return (true);

	while (str[0] == '0')
		str = str.substr(1, str.length() - 1);

	if (str.empty())
		return (false);

	if (str.length() < buf.length())
	{
		while (++i < str.length())
		{
			if (!isdigit(str[i]))
				throw AbstractVM::LexicalError();
		}
		return (true);
	}
	else if (str.length() == buf.length())
	{
		while (++i < buf.length())
		{
			if (!isdigit(str[i]))
				throw AbstractVM::LexicalError();
			if ( i < buf.length() - 1 && ( str[i] > buf[i] ) )
			{
				if (neg)
					throw AbstractVM::Underflow();
				else
					throw AbstractVM::Overflow();

			}
			if ( i < buf.length() - 1 && ( str[i] < buf[i] ) )
				return (true);
			if (i == buf.length() - 1)
			{
				if ((!neg && ( str[i] > buf[i] )) || (neg && ( str[i] > buf[i] + 1 )))
				{
					if (neg)
						throw AbstractVM::Underflow();
					else
						throw AbstractVM::Overflow();
				}
			}
		}
		return (true);
	}
	if (neg)
		throw AbstractVM::Underflow();
	else
		throw AbstractVM::Overflow();

}

bool				isFloat(std::string str)
{
	int				i = 0;

	if (str[i] == '-')
		i++;

	if (!isdigit(str[i]))
		throw AbstractVM::LexicalError();
	while (isdigit(str[i]))
		i++;
	if (str[i] == '\0')
		return (true);
	else if (str[i] == '.' && isdigit(str[i + 1]))
	{
		i++;
		while (isdigit(str[i]))
			i++;
		if (str[i] == '\0')
			return (true);
		else
			throw AbstractVM::LexicalError();
	}
	else
	{
		return (false);
	}
}

std::string				trim_zeros(std::string number)
{
	int			i = 0;
	while (i < (static_cast<int>(number.length()) - 1) && number[i] == '0')
		i++;

	if (i != 0)
		number = number.substr(i, number.length() - i);

	i = number.length();
	while (i > 0 && number[i] == '0')
		i--;

	if (i != (static_cast<int>(number.length()) - 1))
		number = number.substr(0, number.length() - (number.length() - i));

	return (number);
}
