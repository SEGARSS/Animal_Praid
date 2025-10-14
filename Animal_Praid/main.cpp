#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <fstream>

/*
* приют для собак

кличка / имя
возраст
вес
порода


класс животно
поля....

мапа кличка - животное

insert - добавить
search - найти
delete - удалить

*/

std::map<std::string, class Dog> Shelter;
//-------------------------------------------------------------------------------------------------
class Dog
{
public:
	Dog()
	{
	}

	int age;
	int weight;
	std::string breed;
};
//-------------------------------------------------------------------------------------------------
int main()
{
	setlocale(LC_ALL, "ru");

	Dog dog;	

	std::string cod;

	std::string history_name = "history.txt";
	std::string sprav = "sprav.txt";

	std::ifstream i_sprav(sprav);
	if (i_sprav.is_open())
	{
		while (i_sprav.eof() == false)
		{
			std::string nickname;

			std::getline(i_sprav, nickname);

			if (nickname == "")
			{
				continue;
			}

			Shelter[nickname] = dog;
		}
	}
	i_sprav.close();

	while (true)
	{
		std::cout << "Введите команду: ";
		std::cin >> cod;
		std::cin.ignore();

		if (cod == "insert")
		{
			std::cout << "Введите кличку собаки: ";
			std::string nickname;
			std::cin >> nickname;

			std::cout << "Введите возраст собаки: ";
			std::cin >> dog.age;

			std::cout << "Введите вес собаки: ";
			std::cin >> dog.weight;

			std::cout << "Введите породу собаки: ";
			std::cin >> dog.breed;

			Shelter[nickname] = dog;

			std::ofstream f(history_name, std::ios::app);
			f << "insert кличка собаки " << nickname << ", возраст " << dog.age << " лет" << ", вес " << dog.weight << " кг" << ", порода " << dog.breed << std::endl;
			f.close();
		}
		else if (cod == "search")
		{
			std::cout << "Введите кличку собаки: ";
			std::string nickname;
			std::cin >> nickname;

			if (Shelter.contains(nickname) == true)
			{
				std::cout << "Найдена собака - : " << nickname << ", возраст " << dog.age << " лет" << ", вес " << dog.weight << " кг" << ", порода " << dog.breed << std::endl;

				std::ofstream f(history_name, std::ios::app);
				f << "search нашли собаку " << nickname << ", возраст " << dog.age << " лет" << ", вес " << dog.weight << " кг" << ", порода " << dog.breed << std::endl;
				f.close();
			}
			else
			{
				std::cout << "такой саби нет" << std::endl;

				std::ofstream f(history_name, std::ios::app);
				f << "search такой саби нет " << std::endl;
			}			
		}
		else if (cod == "delete")
		{
			std::cout << "Введите кличку собаки: ";
			std::string nickname;
			std::cin >> nickname;

			if (Shelter.contains(nickname))
			{
				Shelter.erase(nickname); // удаляет из мапы значение
				std::cout << "Удалена собака из базы." << std::endl;

				std::ofstream f(history_name, std::ios::app);
				f << "delete - Удалена собака из базы. " << std::endl;
				f.close();
			}
			else
			{
				std::cout << "Ошибка, такой собаки нет." << std::endl;
				std::ofstream f(history_name, std::ios::app);
				f << "Ошибка, такой собаки нет." << std::endl;
				f.close();
			}
		}
		else if (cod == "exit")
		{
			break;
		}
		else
		{
			std::cout << "Неверная команда!\n";
			continue;
		}

	}

	// записать весь справочник
	std::ofstream o_sprav(sprav);
	for (auto& item : Shelter)
	{
		o_sprav << item.first << std::endl;
		o_sprav << dog.age << " " << dog.weight << " " << dog.breed << std::endl;
	}
	o_sprav.close();

	return 0;
}