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
			f << "insert кличка собаки " << nickname << ", возраст " << dog.age << ", вес " << dog.weight << ", порода " << dog.breed << std::endl;
			f.close();
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

	return 0;
}