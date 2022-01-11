#pragma once
#include <string>

inline std::string to_upper(const std::string& str) 
{
	std::string out = "";
	for (const auto& item : str) {
		out += std::toupper(item);
	}
	return out;
}

inline std::list<std::string> split(const std::string& str, const char& ch) 
{
	std::list<std::string> out_list;
	std::string out_string = "";
	for (const auto& item : str) 
	{
		if (item == ch) 
		{
			out_list.push_back(out_string);
			out_string = "";
			continue;
		}
		else 
			out_string += item;
	}
	return out_list;
}