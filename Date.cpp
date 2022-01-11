#include "Date.h"


Date::Date(uint16_t day_, uint16_t month_, uint16_t year_)
{
	year = year_;
	if (month_ >= 1 && month_ <= 12) 
		month = month_;
	else 
	{
		throw std::runtime_error("Month value is invalid: " + std::to_string(month_));
		return;
	}
	if (day_ >= 1 && day_ <= 31) 
		day = day_;
	else 
	{
		throw std::runtime_error("Day value is invalid: " + std::to_string(day_));
		return;
	}
}

void Date::add_date() {
	while (true) 
	{
		std::cout << "\n Enter deadline date: ";
		std::string line = "";
		std::istringstream date_stream;
		getline(std::cin >> std::ws, line);
		date_stream.str(line);
		uint16_t day_ = 0, month_ = 0, year_ = 0;
		try 
		{
			date_stream >> day_;
			if (date_stream.peek() != '-') 
			{
				throw std::runtime_error("Wrong date format: " + line);
			}
			else 
			{
				date_stream.ignore(1);
			}

			date_stream >> month_;
			if (date_stream.peek() != '-') 
			{
				throw std::runtime_error("Wrong date format: " + line);
			}
			else 
			{
				date_stream.ignore(1);
			}

			date_stream >> year_;

			this->Date::Date(day_, month_, year_);
			return;
		}
		catch (std::exception& exp) 
		{
			std::cout << exp.what();
			continue;
		}
	}
}

void Date::str_num_date()
{
	std::string num = "";
	uint16_t counter = 0, day_ = 0, month_ = 0, year_ = 0;
	for (const auto& ch : date_str)
	{
		if (ch == '-')
		{
			++counter;
			if (counter == 1)
			{
				day_ = std::stoi(num);
				num.clear();
				continue;
			}
			if (counter == 2)
			{
				month_ = std::stoi(num);
				num.clear();
				continue;
			}
		}
		num += ch;
	}
	year_ = std::stoi(num);
	this->Date::Date(day_, month_, year_);
}

std::ostream& operator<< (std::ostream& out, const Date& date)
{
	out << std::to_string(date.day) + "-" + std::to_string(date.month) + "-" + std::to_string(date.year);
	return out;
}
