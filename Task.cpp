#include "Task.h"
#include "func.h"

void Task::new_element()
{
	std::string task_name = "";
	std::string new_task = "";
	std::list<std::string> tasks;
	std::pair<std::string, std::list<std::string>> task_list;

	std::cout << std::setfill('-') << std::setw(15) << " " << std::endl;
	std::cout << " Enter the task_name(break to quit): ";
	getline(std::cin >> std::ws, task_name);
	if (to_upper(task_name) == "BREAK") return;
	std::cout << " Enter tasks for " << task_name << "(next to quit): ";

	while (true) 
	{
		getline(std::cin >> std::ws, new_task);
		if (to_upper(new_task) == "NEXT") {
			date.add_date();
			task_list = std::make_pair(task_name, tasks);
			task_date.push_back(std::make_pair(task_list, date));
			return;
		}
		tasks.push_back(new_task);
		std::cout << "             ";
	}
	std::cout << std::setfill('-') << std::setw(15) << " " << std::endl << std::endl;
}

void Task::add_task_to_element()
{
	std::cout << std::endl << " Enter the task_name: ";
	std::string task_name = "";
	getline(std::cin >> std::ws, task_name);

	for (auto& t_d : task_date)
	{
		if (t_d.first.first == task_name)
		{
			std::cout << " Enter new task for " << task_name << ": ";
			std::string task = "";
			getline(std::cin >> std::ws, task);
			t_d.first.second.push_back(task);
			return;
		}
	}
	std::cout << " There is no such " << task_name << ".";
}

void Task::delete_element()
{
	std::cout << " Enter the task_name to delete: ";
	std::string task_name = "";
	getline(std::cin >> std::ws, task_name);

	auto it = task_date.begin();
	for (auto& t_d : task_date)
	{
		if (t_d.first.first == task_name)
		{
			std::cout << std::endl << " Deleted element: " << std::endl;
			std::cout << " " << std::setfill(' ') << std::setw(18) << t_d.first.first << ": ";
			for (const auto& item : t_d.first.second)
				std::cout << "[" << item << "]" << " ";
			std::cout << std::endl << std::setfill(' ') << std::setw(6) << " " << " Deadline date: " << t_d.second << std::endl;
			task_date.erase(it);
			return;
		}
		else
			++it;
	}
	std::cout << std::endl << " Element with " << task_name << " name is not found." << std::endl;
}

void Task::delete_task_from_element()
{
	std::cout << " Enter the task_name: ";
	std::string task_name = "";
	getline(std::cin >> std::ws, task_name);
	std::cout << "\n Enter the task to delete: ";
	std::string task = "";
	getline(std::cin >> std::ws, task);

	for (auto& t_d : task_date)
	{
		if (t_d.first.first == task_name)
		{
			auto it2 = t_d.first.second.begin();
			for (auto& item : t_d.first.second)
			{
				if (item == task)
				{
					t_d.first.second.erase(it2);
					return;
				}
				else
					++it2;
			}
			std::cout << std::endl << " There is no such " << task << "." << std::endl;
			return;
		}
		else
			continue;
	}
	std::cout << std::endl << " Element with " << task_name << " name is not found." << std::endl;
}

void Task::delete_all_elements()
{
	std::cout << std::endl << " Are you sure you want to delete all elements(Y/N): ";
	char command = '0';
	std::cin >> command;
	if (toupper(command) == 'Y')
	{
		task_date.erase(task_date.begin(), task_date.end());
		std::cout << std::endl << " All elements are deleted." << std::endl;
	}
	else
		return;
}

void Task::change_deadline()
{
	std::cout << " Enter the task_name: ";
	std::string task_name = "";
	getline(std::cin >> std::ws, task_name);

	for (auto& t_d : task_date)
	{
		if (t_d.first.first == task_name)
		{
			t_d.second.add_date();
			return;
		}
	}
	std::cout << std::endl << " Element with " << task_name << " name is not found." << std::endl;
}
