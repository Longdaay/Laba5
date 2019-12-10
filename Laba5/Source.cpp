// ������������ ������ � 5 - �������� � n-��������
// �������� ������ �� �������� ��������������� ABVDEFGH, ������ ��� ����������� � ���� �� �������� ������.
// ���������� ���������� :
// 1.	��������� ��������� �� ����� ������� �� ������� � � � �� n �������;
// 2.	��������� ��������� �� ����� ������� �� ������� � � � �� n �������, ��� �������, ��� ��������� ������ ������� � ������� E;
// 3.	���������� ����������� ����, ��� �������� ����� ��� ����� n ������, ��� �������, ��� ���� ��������� ���������� � ������� �, � � ������� � ��������� ���� � ������ ������� �������� ������ ��������� ������.
// ����� ���������� ���������� ��� ������ ��� �������, ��� ��������� � �������� �������, � ����� ���������� ������ � �������, � ������� ��������� ����, �������� �������������.

#include <iostream> // ����/����� � �������
#include <string> // ��� �����
#include <vector> // ��� ������� �������� ����� � �������
#include <Windows.h> // ��� ������ �����

const int NotUsed = system("color 70");

int good_ways = 0; // ������� ���������� "�������" �����
int bad_ways = 0; // �������� ���������� "���������" �����
std::string s; // ��� ������ ���� ���������

void SetColor(int text, int bg) //������� ����� �����
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((bg << 4) | text));
}

int checkdigit() // �������� ����� �� ������������ ����� (������������� �������� ����� �� ���������)
{
	while (true)
	{
		int value;
		// ������ �����, ������� ����� ����������� � �������� �����
		std::cin >> value; // ����� �����
		if (std::cin.fail()) // ec�� ���������� ����������� �������� ���������,
		{
			std::cin.clear(); // �� ���������� cin � ������� ����� ������
			std::cin.ignore(32767, '\n'); // � ������� �� ������ �������� ����������� ����� 
			std::cout << "������������ �������� �����. ������� ����� ���������" << '\n';
		}
		else
		{
			if (value < 0)
			{
				std::cin.clear(); // �� ���������� cin � ������� ����� ������
				std::cin.ignore(32767, '\n'); // � ������� �� ������ �������� ����������� ����� 
				std::cout << "������������ ������������� �����. ������� ����� �������������" << '\n';
			}
			else
			{
				std::cin.ignore(32767, '\n'); // ������� �� ������ �������� ����������� ����� 
				return value;
			}
		}
	}
}

int checkparam() // ������� �������� ���������� ��������
{
	char value[256]; // ����������, ������� ������ ��������� ��������
	std::cin >> value; // ������ ��������� �������� 
	if (strlen(value) == 1) // ��������� ���������� ��������� ��������. ���� �����, �� ������ ������ ��� ���, ����� �������� ������
	{
		switch (value[0]) // ��������, ���� ������ ������ ���������� value
		{
		case 'y': // ���� �����������
			return 1;
			break;
		case 'n': // ���� ������������
			return 0;
			break;
		default: // ���� ����� �� �������� �� � ������ ��
			std::cout << "�������� ������� �������. ������� ������" << std::endl;
			checkparam();
			break;
		}
	}
	else // ���� ������� �������� ������ ������������
	{
		std::cout << "���������� ������ ���� ������. ���������� ������ ������" << std::endl;
		checkparam();
	}
}

void digit_to_latter(int digit) // ���������� ������� � ����������� �� �������� �������
{
	switch (digit)
	{
	case 0: s.push_back('A'); break;
	case 1: s.push_back('B'); break;
	case 2: s.push_back('C'); break;
	case 3: s.push_back('D'); break;
	case 4: s.push_back('E'); break;
	case 5: s.push_back('F'); break;
	case 6: s.push_back('G'); break;
	case 7: s.push_back('H'); break;
	default:
		break;
	}
}

void digit_to_char(int digit) // ���������� ������� � ����������� �� �������� �������
{
	switch (digit)
	{
	case 0: s.push_back('0'); break;
	case 1: s.push_back('1'); break;
	case 2: s.push_back('2'); break;
	case 3: s.push_back('3'); break;
	case 4: s.push_back('4'); break;
	case 5: s.push_back('5'); break;
	case 6: s.push_back('6'); break;
	case 7: s.push_back('7'); break;
	case 8: s.push_back('8'); break;
	case 9: s.push_back('9'); break;
	default:
		break;
	}
}

void revers_char(int digit) // ��� ����� ���� n-�������� ��������
{
	std::vector<int> arr; // �������������� ������
	if (digit == 0) // ���� ���������� ����
	{
		arr.push_back(0); // ��������� 0
	}
	while (digit != 0) // ���� ����� �� 0, ��������� �� �������� � ��������� � ������
	{
		arr.push_back(digit % 10);
		digit = digit / 10;

	}
	for (int i = arr.size() - 1; i >= 0; i--) // ������� �������� ������ ����� �������
	{
		digit_to_char(arr[i]);
	}
}

void X_to_Y(int position, int final_vertex, int number_of_steps, int number_of_angles, int vivod, int zadan) // ������� ��� �������� ���������� ����� �� ����� x � ����� y �� n �����
{
	int del_part; // ������� � ������ ������� �������
	if (position == -1) // ���� ������ 0
		position = number_of_angles - 1; // ������������ ������ n-���������
	if (position == number_of_angles) // ���� ������ ������������� ������� n-���������
		position = 0; // ����������� ������ n-���������
	if (zadan) // � ����������� �� ������� ������� ����� ��� �����
	{	// ����� �������� 
		del_part = 3;
		s.push_back('x'); 
		revers_char(position);
		s.push_back('>');
	}
	else // ����� ����
	{
		del_part = 2;
		digit_to_latter(position);
		s.push_back('>');
	}
	if (position != final_vertex and number_of_steps > 0) // ���� ���� ��� ���� � ������� �� �������� ��������
	{
		X_to_Y(position - 1, final_vertex, number_of_steps - 1, number_of_angles, vivod, zadan); // �������� �� ��� �����
		X_to_Y(position + 1, final_vertex, number_of_steps - 1, number_of_angles, vivod, zadan); // �������� �� ��� ������
		s.erase(s.size() - 1); // ������� ������ ���� �������
		s.erase(s.rfind('>') + 1); // ������� ������ ���� �������
	}
	else if (position == final_vertex and number_of_steps > 0) //���� ���� ��� ���� � ������� �������� ��������
	{
		X_to_Y(position - 1, final_vertex, number_of_steps - 1, number_of_angles, vivod, zadan); // �������� �� ��� �����
		X_to_Y(position + 1, final_vertex, number_of_steps - 1, number_of_angles, vivod, zadan); // �������� �� ��� ������
		s.erase(s.size() - 1); // ������� ������ ���� �������
		s.erase(s.rfind('>') + 1); // ������� ������ ���� �������
	}
	else if (position == final_vertex and number_of_steps == 0) // ���� ���� ����������� � �������� ����� ����������
	{
		good_ways++; // ��������� ���������� ������� �����
		s.erase(s.size() - 1); // ������� >
		std::cout << s; // ������� ����
		s.erase(s.rfind('>') + 1); // ������� �������
		if (vivod) // ���� ������� ��� ����
			std::cout << " - ������� ���� " << std::endl; // �������� ������ ���� ��� �������
		else
			std::cout << std::endl; // ������ ���� ������ �������
	}
	else // ���� ���� �� ����������� ��� �������� ����� �� ����������
	{
		if (vivod) // ���� ������� ��� ����
		{
			s.erase(s.size() - 1); // ������� >
			std::cout << s << std::endl; // ������� ����
			s.erase(s.rfind('>') + 1); // ������� �������
		}
		else
		{
			s.erase(s.size() - 1);
			s.erase(s.rfind('>') + 1); // ������� > � �������
		}
		return;
	}
}

void X_to_Y_not_Q(int position, int final_vertex, int number_of_steps, int q_rock, int number_of_angles, int vivod, int zadan) // ������� ��� �������� ���������� ����� �� ����� x � ����� y �� n ����� ��� ������ � ����� q
{ 
	int del_part; // ������� � ������ ������� �������
	if (position == -1) // ���� ������ 0
		position = number_of_angles - 1; // ������������ ������ n-���������
	if (position == number_of_angles) // ���� ������ ������������� ������� n-���������
		position = 0; // ����������� ������ n-���������
	if (zadan) // � ����������� �� ������� ������� ����� ��� �����
	{	// ����� �������� 
		del_part = 3;
		s.push_back('x');
		revers_char(position);
		s.push_back('>');
	}
	else // ����� ����
	{	
		del_part = 2;
		digit_to_latter(position);
		s.push_back('>');
	}
	if (position == q_rock) // ���� �������� �����, ����� ������� ������ ����
	{
		s.erase(s.size() - 1);
		s.erase(s.rfind('>') + 1); //������� �������
		return;
	}
	else if (position != final_vertex and number_of_steps > 0)  // ���� ���� ��� ���� � ������� �� �������� ��������
	{
		X_to_Y_not_Q(position - 1, final_vertex, number_of_steps - 1, q_rock, number_of_angles, vivod, zadan); // �������� �� ��� �����
		X_to_Y_not_Q(position + 1, final_vertex, number_of_steps - 1, q_rock, number_of_angles, vivod, zadan); // �������� �� ��� ������
		s.erase(s.size() - 1);
		s.erase(s.rfind('>') + 1); // ������� ������ ���� �������
	}
	else if (position == final_vertex and number_of_steps > 0) //���� ���� ��� ���� � ������� �������� ��������
	{
		X_to_Y_not_Q(position - 1, final_vertex, number_of_steps - 1, q_rock, number_of_angles, vivod, zadan); // �������� �� ��� �����
		X_to_Y_not_Q(position + 1, final_vertex, number_of_steps - 1, q_rock, number_of_angles, vivod, zadan); // �������� �� ��� ������
		s.erase(s.size() - 1);
		s.erase(s.rfind('>') + 1);  // ������� ������ ���� �������
	}
	else if (position == final_vertex and number_of_steps == 0) // ���� ���� ����������� � �������� ����� ����������
	{
		good_ways++; // ��������� ���������� ������� �����
		s.erase(s.size() - 1); // ������� >
		std::cout << s; // ������� ����
		s.erase(s.rfind('>') + 1); // ������� �������
		if (vivod) // ���� ������� ��� ����
			std::cout << " - ������� ���� " << std::endl; // �������� ������ ���� ��� �������
		else
			std::cout << std::endl; // ������ ���� ������ �������
	}
	else
	{
		if (vivod) // ���� ������� ��� ����
		{
			s.erase(s.size() - 1); // ������� >
			std::cout << s << std::endl; // ������� ����
			s.erase(s.rfind('>') + 1); // ������� �������
		}
		else
		{
			s.erase(s.size() - 1); // ������� >
			s.erase(s.rfind('>') + 1); // ������� > � �������
		}
		return;
	}
}

void X_to_bomb(int position, int bomb, int number_of_steps, int number_of_angles) // ������� ��� ������� ������� � ��������� ����� ����� n ������, ����� � ����� �� ������ ����
{
	if (position == -1) // ���� ������ 0
		position = number_of_angles - 1; // ������������ ������ n-���������
	if (position == number_of_angles) // ���� ������ ������������� ������� n-���������
		position = 0; // ����������� ������ n-���������

	if (position == bomb and number_of_steps > 0) // ���� �������� ���� � ���� ��� ����
	{
		bad_ways++; // ��������� ��������� ����
		return;
	}
	else if (position != bomb and number_of_steps > 0) // ���� �� �������� ���� � ���� ��� ����
	{
		X_to_bomb(position - 1, bomb, number_of_steps - 1, number_of_angles); // �������� �� ��� �����
		X_to_bomb(position + 1, bomb, number_of_steps - 1, number_of_angles); // �������� �� ��� ������
	}
	else if (position != bomb and number_of_steps == 0) // ���� �� �������� ���� � ����� ��� ��� 
	{
		good_ways++; // ��������� ������� ����
		return;
	}
	else
		return;
}

void vvod(int &first_vertex, int &last_vertex, int &number_of_steps, int &number_of_angles, int param) // ������� ��� ����������� ������ ����������
{
	std::cout << "������� ������ ��������� �������: ";
	first_vertex = checkdigit();
	if (!param) // ��� ������ ������� � ����� 
	{
		std::cout << "������� ������ �������� �������: ";
		last_vertex = checkdigit();
		std::cout << "������� ���������� �����: ";
		number_of_steps = checkdigit();
	}
	else
	{
		std::cout << "������� ������ �������, � ������� ��������� ����: ";
		last_vertex = checkdigit();
		std::cout << "������� �����, ������� �������� ������ ������������: ";
		number_of_steps = checkdigit();
	}
	std::cout << "������� ���������� ������ n-���������: ";
	number_of_angles = checkdigit();
}


int main()
{
	setlocale(0, ""); // �����������
	int number_of_steps; // ���������� �����
	int vidod; // ��� ������ ���� ����� ��� ������ �������
	int first_vertex; // ��������� ������� ���������
	int last_vertex; // �������� �������, ������� ������ ���������� ��������
	int number_of_angles; // ���������� ����� � n-���������
	int q_rock; // ������, ����� ������� �� �������� ��������

	// ������� 1 - �� �������� ���������
	std::cout << "������� 1 - ���������� ����� �� � �� � �� n �����" << std::endl;
	std::cout << "������� ���������� �����: ";
	number_of_steps = checkdigit();
	std::cout << "���������� �� �������� ��� ����? (y/n): ";
	vidod = checkparam();
	std::cout << "���� �� � �� � �� " << number_of_steps << " �����" << std::endl;
	X_to_Y(0, 2, number_of_steps, 8, vidod, 0);
	std::cout << "���������� ������� �����: " << good_ways << std::endl;


	// ������� 2 - �� �������� ���������
	good_ways = 0;
	std::cout << std::endl << "������� 2 - ���� �� � �� � ��� ������ � ������� � �� n �����" << std::endl;
	std::cout << "������� ���������� �����: ";
	number_of_steps = checkdigit();
	std::cout << "���������� �� �������� ��� ����? (y/n): ";
	vidod = checkparam();
	X_to_Y_not_Q(0, 2, number_of_steps, 4, 8, vidod, 0);
	std::cout << "���������� ������� �����: " << good_ways << std::endl;


	// ������� 3 - �� �������� ���������
	good_ways = 0;
	std::cout << std::endl << "������� 3 - ������� ����������� ��������� ��������� ����� n ������" << std::endl;
	std::cout << "������� ���������� ������: ";
	number_of_steps = checkdigit();
	X_to_bomb(0, 4, number_of_steps, 8);
	std::cout << "�� �������� � " << bad_ways << " �������" << std::endl;
	std::cout << "�������� � " << good_ways <<" �������" << std::endl;
	std::cout << "����������� ����, ��� �������� ����� ���� ����� " << number_of_steps << " ������ ����� " << 1.0 - (float(bad_ways)/float(good_ways)) << std::endl;


	// ������� 1* - �� ��������� ������������
	good_ways = 0;
	std::cout << std::endl << "������� 1* - ���������� ����� �� X �� Y �� n �����" << std::endl;
	vvod(first_vertex, last_vertex, number_of_steps, number_of_angles, 0);
	std::cout << "���������� �� �������� ��� ����? (y/n): ";
	vidod = checkparam();
	X_to_Y(first_vertex, last_vertex, number_of_steps, number_of_angles, vidod, 1);
	std::cout << "���������� ������� �����: " << good_ways << std::endl;

	// ������� 2* - �� ��������� ������������
	good_ways = 0;
	std::cout << std::endl << "������� 2* - ���� �� X �� Y ��� ������ � ������� Q �� n �����" << std::endl;
	vvod(first_vertex, last_vertex, number_of_steps, number_of_angles, 0);
	std::cout << "������� �������, � ������� ������ �������: ";
	q_rock = checkdigit();
	std::cout << "���������� �� �������� ��� ����? (y/n): ";
	vidod = checkparam();
	X_to_Y_not_Q(first_vertex, last_vertex, number_of_steps, q_rock, number_of_angles, vidod, 1);
	std::cout << "���������� ������� �����: " << good_ways << std::endl;
	

	// ������� 3* - �� ��������� ������������
	std::cout << std::endl << "������� 3* - ������� ����������� ��������� ��������� ����� n ������" << std::endl;
	good_ways = 0;
	bad_ways = 0;
	vvod(first_vertex, last_vertex, number_of_steps, number_of_angles, 1);
	X_to_bomb(first_vertex, last_vertex, number_of_steps, number_of_angles);
	std::cout << "�� �������� � " << bad_ways << " �������" << std::endl;
	std::cout << "�������� � " << good_ways << " �������" << std::endl;
	std::cout << "����������� ����, ��� �������� ����� ���� ����� " << number_of_steps << " ������ ����� " << 1.0 - (float(bad_ways) / float(good_ways)) << std::endl;

	return 0;
}