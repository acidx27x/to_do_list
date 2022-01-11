#include "DB.h"

#define DEBUG 
int main()
{
#ifdef DEBUG
	DB* db = new DB();
	
	db->open_db();
	while (true)
	{
		std::string command = "";
		std::cout << "\n\n Enter the command('show' to see the menu): ";
		getline(std::cin >> std::ws, command);
		if (to_upper(command) == "SHOW") {
			std::cout << " ------------------------------------\n";
			std::cout << " Print todolist                  ...1\n";
			std::cout << " Add new element                 ...2\n";
			std::cout << " Add new task in element         ...3\n";
			std::cout << " Delete element                  ...4\n";
			std::cout << " Delete task from element        ...5\n";
			std::cout << " Delete all elements             ...6\n";
			std::cout << " New deadline                    ...7\n";
			std::cout << " Save todolist and exit          ...8\n";
			std::cout << " ------------------------------------\n\n";
			continue;
		}
		try
		{
			if (std::stoi(command)) {
				//uint16_t fun_n = 0;
				//std::cout << " Enter the number: ";
				//std::cin >> fun_n;
				switch (std::stoi(command))
				{
				case 1:
					std::cout << " --------------------------------------------------\n";
					db->print();
					break;
				case 2:
					std::cout << " --------------------------------------------------\n";
					db->add_elements();
					break;
				case 3:
					std::cout << " --------------------------------------------------\n";
					db->add_task_to_exist();
					break;
				case 4:
					std::cout << " --------------------------------------------------\n";
					db->delete_element();
					break;
				case 5:
					std::cout << " --------------------------------------------------\n";
					db->delete_task_from_element();
					break;
				case 6:
					std::cout << " --------------------------------------------------\n";
					db->delete_all_elements();
					break;
				case 7:
					std::cout << " --------------------------------------------------\n";
					db->change_deadline();
					break;
				case 8:
					std::cout << " --------------------------------------------------\n";
					std::cout << " Todolist is saved\n";
					std::cout << " --------------------------------------------------\n";
					db->save_db();
					delete db;
					return 0;
				default:
					std::cout << " --------------------------------------------------\n";
					std::cout << " Wrong number\n";
					break;
				}
			}
		}
		catch (std::exception& exp)
		{
			std::cout << "\n" << exp.what() << "\n";
		}
		
	}
#else
	std::cout << " Enter str: ";
	std::string str = "";
	std::cin >> str;
	std::cout << "\n" << std::stoi(str) << "\n";
	return 1;
#endif
}