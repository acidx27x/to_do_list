#pragma once
#include "Task.h"
#include "func.h"
#include <vector>
#include <fstream>


class DB
{
private:
	Task task;

public:
	void add_elements();
	void add_task_to_exist();
	void delete_element();
	void delete_task_from_element();
	void delete_all_elements();
	void change_deadline();
	void print() const;

	void save_db();
	void open_db();
};