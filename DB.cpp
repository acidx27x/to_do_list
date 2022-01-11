#include "DB.h"



void DB::add_elements()
{
	task.new_element();
}

void DB::add_task_to_exist()
{
	task.add_task_to_element();
}

void DB::delete_element()
{
	task.delete_element();
}

void DB::delete_task_from_element()
{
	task.delete_task_from_element();
}

void DB::delete_all_elements()
{
	task.delete_all_elements();
}

void DB::change_deadline()
{
	task.change_deadline();
}

void DB::print() const
{
	uint16_t counter = 0;
	std::cout << std::endl << std::endl << " TO_DO_LIST " << std::endl;
	std::cout << std::setfill('-') << std::setw(25) << " " << std::endl;
	for (const auto& t_d : task.task_date)
	{
		std::cout << " " << ++counter << std::setfill(' ') << std::setw(18) << t_d.first.first << ": ";
		for (const auto& item : t_d.first.second)
			std::cout << "[" << item << "]" << " ";
		std::cout << std::endl << std::setfill(' ') << std::setw(6) << " " << " Deadline date: " <<  t_d.second;
		if (counter < task.task_date.size())
			std::cout << std::endl << "-----" << std::endl;
		else
			std::cout << std::endl;
	}
	std::cout << std::setfill('-') << std::setw(25) << " " << std::endl;
}

void DB::save_db()
{
	std::ofstream out("todolist.txt");
	out << "TODOLIST" << std::endl;
	uint16_t counter = 0;
	if (out.is_open())
	{
		for (const auto& t_d : task.task_date)
		{
			++counter;
			out << "Task_name" << std::endl;
			out << t_d.first.first << std::endl;
			out << "Tasks_date" << std::endl;
			for (const auto& item : t_d.first.second)
			{
				out << item << ";";
			}
			out << std::endl << "Date" << std::endl << t_d.second;
			if (counter < task.task_date.size())
				out << std::endl;
		}
		out.close();
		return;
	}
	else
	{
		std::cout << std::endl << " Smt went wrong with file." << std::endl;
		return;
	}
}

void DB::open_db()
{
	try
	{
		std::ifstream in;
		in.open("todolist.txt");
		if (in.is_open())
		{
			std::string tdl = "";
			getline(in, tdl);
			while (!in.eof())
			{
				std::string Task_Header = "";
				getline(in, Task_Header);
				std::string task_name = "";
				getline(in, task_name);

				std::string Tasks_Header = "";
				getline(in, Tasks_Header);
				std::string tasks = "";
				getline(in, tasks);

				std::string Date_Header = "";
				getline(in, Date_Header);
				std::string date = "";
				getline(in, date);
				Date date_(date);
				date_.str_num_date();

				auto task_list = std::make_pair(task_name, split(tasks, ';'));
				task.task_date.push_back(std::make_pair(task_list, date_));
			}
		}
		else
		{
			std::cout << std::endl << " There is no file to read, smt went wrong." << std::endl;
			return;
		}
	}
	catch (std::exception& exp)
	{
		std::cout << exp.what() << std::endl;
		std::cout << " There are some invalid data, can`t add it to DB." << std::endl;
	}
}