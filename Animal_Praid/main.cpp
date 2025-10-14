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
			f << "insert ������ ������ " << nickname << ", ������� " << dog.age << ", ��� " << dog.weight << ", ������ " << dog.breed << std::endl;
			f.close();
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

	return 0;
}