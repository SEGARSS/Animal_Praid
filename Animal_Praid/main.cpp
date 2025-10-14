#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <fstream>

/*
* ����� ��� �����

������ / ���
�������
���
������


����� �������
����....

���� ������ - ��������

insert - ��������
search - �����
delete - �������

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
		std::cout << "������� �������: ";
		std::cin >> cod;
		std::cin.ignore();

		if (cod == "insert")
		{
			std::cout << "������� ������ ������: ";
			std::string nickname;
			std::cin >> nickname;

			std::cout << "������� ������� ������: ";
			std::cin >> dog.age;

			std::cout << "������� ��� ������: ";
			std::cin >> dog.weight;

			std::cout << "������� ������ ������: ";
			std::cin >> dog.breed;

			Shelter[nickname] = dog;

			std::ofstream f(history_name, std::ios::app);
			f << "insert ������ ������ " << nickname << ", ������� " << dog.age << " ���" << ", ��� " << dog.weight << " ��" << ", ������ " << dog.breed << std::endl;
			f.close();
		}
		else if (cod == "search")
		{
			std::cout << "������� ������ ������: ";
			std::string nickname;
			std::cin >> nickname;

			if (Shelter.contains(nickname) == true)
			{
				std::cout << "������� ������ - : " << nickname << ", ������� " << dog.age << " ���" << ", ��� " << dog.weight << " ��" << ", ������ " << dog.breed << std::endl;

				std::ofstream f(history_name, std::ios::app);
				f << "search ����� ������ " << nickname << ", ������� " << dog.age << " ���" << ", ��� " << dog.weight << " ��" << ", ������ " << dog.breed << std::endl;
				f.close();
			}
			else
			{
				std::cout << "����� ���� ���" << std::endl;

				std::ofstream f(history_name, std::ios::app);
				f << "search ����� ���� ��� " << std::endl;
			}			
		}
		else if (cod == "delete")
		{
			std::cout << "������� ������ ������: ";
			std::string nickname;
			std::cin >> nickname;

			if (Shelter.contains(nickname))
			{
				Shelter.erase(nickname); // ������� �� ���� ��������
				std::cout << "������� ������ �� ����." << std::endl;

				std::ofstream f(history_name, std::ios::app);
				f << "delete - ������� ������ �� ����. " << std::endl;
				f.close();
			}
			else
			{
				std::cout << "������, ����� ������ ���." << std::endl;
				std::ofstream f(history_name, std::ios::app);
				f << "������, ����� ������ ���." << std::endl;
				f.close();
			}
		}
		else if (cod == "exit")
		{
			break;
		}
		else
		{
			std::cout << "�������� �������!\n";
			continue;
		}

	}

	// �������� ���� ����������
	std::ofstream o_sprav(sprav);
	for (auto& item : Shelter)
	{
		o_sprav << item.first << std::endl;
		o_sprav << dog.age << " " << dog.weight << " " << dog.breed << std::endl;
	}
	o_sprav.close();

	return 0;
}