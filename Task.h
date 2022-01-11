#pragma once
#include "Date.h"
#include <map>
#include <list>
#include <iomanip>
#include <vector>
using Map = std::pair<std::string, std::list<std::string>>;

class Task {
private:
	std::list<std::pair<Map, Date>> task_date;
	void new_element();
	void add_task_to_element();
	void delete_element();
	void delete_task_from_element();
	void delete_all_elements();
	void change_deadline();

	Date date;
	friend class DB;
};