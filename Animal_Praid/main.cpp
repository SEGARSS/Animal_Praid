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


//-------------------------------------------------------------------------------------------------
class Dog
{
public:
	Dog()
	{
	}

	// Метод для записи в файл
	void record(std::ofstream& ofs) const 
	{
		ofs << age << std::endl;
		ofs << weight << std::endl;
		ofs << breed << std::endl;
	}

	// Метод для чтения из файла
	void reading(std::ifstream& ifs) 
	{
		ifs >> age;
		ifs >> weight;
		ifs.ignore(); 
		std::getline(ifs, breed);
	}

	int age;
	int weight;
	std::string breed;

	std::map<std::string, class Dog> Shelter;
};
//-------------------------------------------------------------------------------------------------
int main()
{
	setlocale(LC_ALL, "ru");

	Dog dog;
	std::string cod;

	std::string history_name = "history.txt";
	std::string sprav = "sprav.txt";

	// Чтение из файла
	std::ifstream i_sprav(sprav);
	if (i_sprav.is_open()) 
	{
		while (!i_sprav.eof()) 
		{
			std::string nickname;
			std::getline(i_sprav, nickname);

			if (nickname.empty()) 
			{
				continue;
			}

			dog.reading(i_sprav);
			dog.Shelter[nickname] = dog;
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

			dog.Shelter[nickname] = dog;

			std::cout << "Добавлена. " << std::endl;

			std::ofstream f(history_name, std::ios::app);
			f << "insert - добалена собак, кличка - " << nickname << ", возраст " << dog.age << " лет" << ", вес " << dog.weight << " кг" << ", порода " << dog.breed << std::endl;
			f.close();
		}
		else if (cod == "search")
		{
			std::cout << "Введите кличку собаки: ";
			std::string nickname;
			std::cin >> nickname;

			if (dog.Shelter.contains(nickname) == true)
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

			if (dog.Shelter.contains(nickname))
			{
				dog.Shelter.erase(nickname); // удаляет из мапы значение
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
			std::cout << "Программа закрыта.\n";
			std::ofstream f(history_name, std::ios::app);
			f << "Закрытие программы." << std::endl;
			f.close();
			break;
		}
		else
		{
			std::cout << "Неверная команда!\n";
			std::ofstream f(history_name, std::ios::app);
			f << "Была введенна не верная команда." << std::endl;
			f.close();
			continue;
		}
	}

	// записать весь справочник
	std::ofstream o_sprav(sprav);
	for (const auto& item : dog.Shelter) 
	{
		o_sprav << item.first << std::endl;// записываем кличку
		item.second.record(o_sprav);   // записываем данные собаки
	}
	o_sprav.close();

	return 0;
}