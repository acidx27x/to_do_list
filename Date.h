#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <exception>

class Date
{
private:
	uint16_t day;
	uint16_t month;
	uint16_t year;
	std::string date_str;

	void add_date();

	friend class Task;
	friend std::ostream& operator<< (std::ostream& out, const Date& date);
public:
	Date() { day = 0, month = 0, year = 0; date_str = ""; }
	Date(uint16_t day_, uint16_t month_, uint16_t year_);
	Date(std::string date_str_) : date_str(date_str_), day(0), month(0), year(0) {}
	void str_num_date();
};
