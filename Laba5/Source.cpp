// Лабораторная работа № 5 - Кузнечик и n-угольник
// Кузнечик скачет по вершинам восьмиугольника ABVDEFGH, каждый раз перемещаясь в одну из соседних вершин.
// Необходимо рассчитать :
// 1.	сколькими способами он может попасть из вершины А в С за n прыжков;
// 2.	сколькими способами он может попасть из вершины А в С за n прыжков, при условии, что кузнечику нельзя прыгать в вершину E;
// 3.	рассчитать вероятность того, что кузнечик будет жив через n секунд, при условии, что путь кузнечика начинается в вершине А, а в вершине Е находится мина и каждую секунду кузнечик делает очередной прыжок.
// Также необходимо рассчитать все случае при условии, что начальная и конечная вершины, а также количество вершин и вершину, в которой находится мина, задается пользователем.

#include <iostream> // ввод/вывод в консоль
#include <string> // для строк
#include <vector> // для массива перевода чисел в символы
#include <Windows.h> // для вывода цвета

const int NotUsed = system("color 70");

int good_ways = 0; // подсчет количества "удачных" путей
int bad_ways = 0; // подсчета количества "неудачных" путей
std::string s; // для вывода пути кузнечика

void SetColor(int text, int bg) //Функция смены цвета
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((bg << 4) | text));
}

int checkdigit() // проверка числа на корректность ввода (отрицательные значения также не принимает)
{
	while (true)
	{
		int value;
		// вводим число, которое хотим представить в двоичной форме
		std::cin >> value; // число целое
		if (std::cin.fail()) // ecли предыдущее извелечение оказлось неудачным,
		{
			std::cin.clear(); // то возвращаем cin в обычный режим работы
			std::cin.ignore(32767, '\n'); // и удаляем из буфера значения предыдущего ввода 
			std::cout << "Недопустимое заданное число. Введите число правильно" << '\n';
		}
		else
		{
			if (value < 0)
			{
				std::cin.clear(); // то возвращаем cin в обычный режим работы
				std::cin.ignore(32767, '\n'); // и удаляем из буфера значения предыдущего ввода 
				std::cout << "Недопустимое отрицательное число. Введите число положительное" << '\n';
			}
			else
			{
				std::cin.ignore(32767, '\n'); // удаляем из буфера значения предыдущего ввода 
				return value;
			}
		}
	}
}

int checkparam() // функция проверки выбранного действия
{
	char value[256]; // переменная, которая хранит выбранное значение
	std::cin >> value; // вводим выбранное значение 
	if (strlen(value) == 1) // проверяем количество введенных символов. Если много, то просим ввести еще раз, иначе проверям дальше
	{
		switch (value[0]) // проверям, взяв первый символ переменной value
		{
		case 'y': // если соглашаемся
			return 1;
			break;
		case 'n': // если отказываемся
			return 0;
			break;
		default: // если число не подходит ни к одному из
			std::cout << "Значение введено неверно. Введите заново" << std::endl;
			checkparam();
			break;
		}
	}
	else // если введено символов больше необходимого
	{
		std::cout << "Необходимо ввести один символ. Попробуйте ввести заново" << std::endl;
		checkparam();
	}
}

void digit_to_latter(int digit) // добавление символа в зависимости от значения вершины
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

void digit_to_char(int digit) // добавление символа в зависимости от значения вершины
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

void revers_char(int digit) // Для ввода пути n-значного значения
{
	std::vector<int> arr; // инициализируем массив
	if (digit == 0) // если лидирующий ноль
	{
		arr.push_back(0); // добавляем 0
	}
	while (digit != 0) // пока число не 0, разбираем по разрядам и добавляем в массив
	{
		arr.push_back(digit % 10);
		digit = digit / 10;

	}
	for (int i = arr.size() - 1; i >= 0; i--) // выводим обратный массив через символы
	{
		digit_to_char(arr[i]);
	}
}

void X_to_Y(int position, int final_vertex, int number_of_steps, int number_of_angles, int vivod, int zadan) // функция для просчета количество путей из точки x в точку y за n шагов
{
	int del_part; // удаляем в строке прошлую вершину
	if (position == -1) // если меньше 0
		position = number_of_angles - 1; // максимальный индекс n-угольника
	if (position == number_of_angles) // если больше максимального индекса n-угольника
		position = 0; // минимальный индекс n-угольника
	if (zadan) // в зависимости от задания выводим буквы или цифры
	{	// вывод индексов 
		del_part = 3;
		s.push_back('x'); 
		revers_char(position);
		s.push_back('>');
	}
	else // вывод букв
	{
		del_part = 2;
		digit_to_latter(position);
		s.push_back('>');
	}
	if (position != final_vertex and number_of_steps > 0) // если шаги еще есть и позиция не является конечной
	{
		X_to_Y(position - 1, final_vertex, number_of_steps - 1, number_of_angles, vivod, zadan); // рекурсия на шаг назад
		X_to_Y(position + 1, final_vertex, number_of_steps - 1, number_of_angles, vivod, zadan); // рекурсия на шаг вперед
		s.erase(s.size() - 1); // удаляем старый путь вершины
		s.erase(s.rfind('>') + 1); // удаляем старый путь вершины
	}
	else if (position == final_vertex and number_of_steps > 0) //если шаги еще есть и позиция является конечной
	{
		X_to_Y(position - 1, final_vertex, number_of_steps - 1, number_of_angles, vivod, zadan); // рекурсия на шаг назад
		X_to_Y(position + 1, final_vertex, number_of_steps - 1, number_of_angles, vivod, zadan); // рекурсия на шаг вперед
		s.erase(s.size() - 1); // удаляем старый путь вершины
		s.erase(s.rfind('>') + 1); // удаляем старый путь вершины
	}
	else if (position == final_vertex and number_of_steps == 0) // если шаги закончились и конечная точка достигнута
	{
		good_ways++; // добавляем количество удачных путей
		s.erase(s.size() - 1); // удаляем >
		std::cout << s; // выводим путь
		s.erase(s.rfind('>') + 1); // удаляем вершину
		if (vivod) // если выводим все пути
			std::cout << " - удачный путь " << std::endl; // помечаем данный путь как удачный
		else
			std::cout << std::endl; // просто ищем другой удачный
	}
	else // если шаги не закончились или конечная точка не достигнута
	{
		if (vivod) // если выводим все пути
		{
			s.erase(s.size() - 1); // удаляем >
			std::cout << s << std::endl; // выводим путь
			s.erase(s.rfind('>') + 1); // удаляем вершину
		}
		else
		{
			s.erase(s.size() - 1);
			s.erase(s.rfind('>') + 1); // удаляем > и вершину
		}
		return;
	}
}

void X_to_Y_not_Q(int position, int final_vertex, int number_of_steps, int q_rock, int number_of_angles, int vivod, int zadan) // функция для просчета количество путей из точки x в точку y за n шагов без захода в точку q
{ 
	int del_part; // удаляем в строке прошлую вершину
	if (position == -1) // если меньше 0
		position = number_of_angles - 1; // максимальный индекс n-угольника
	if (position == number_of_angles) // если больше максимального индекса n-угольника
		position = 0; // минимальный индекс n-угольника
	if (zadan) // в зависимости от задания выводим буквы или цифры
	{	// вывод индексов 
		del_part = 3;
		s.push_back('x');
		revers_char(position);
		s.push_back('>');
	}
	else // вывод букв
	{	
		del_part = 2;
		digit_to_latter(position);
		s.push_back('>');
	}
	if (position == q_rock) // если достигли точки, через которую нельзя идти
	{
		s.erase(s.size() - 1);
		s.erase(s.rfind('>') + 1); //удаляем вершину
		return;
	}
	else if (position != final_vertex and number_of_steps > 0)  // если шаги еще есть и позиция не является конечной
	{
		X_to_Y_not_Q(position - 1, final_vertex, number_of_steps - 1, q_rock, number_of_angles, vivod, zadan); // рекурсия на шаг назад
		X_to_Y_not_Q(position + 1, final_vertex, number_of_steps - 1, q_rock, number_of_angles, vivod, zadan); // рекурсия на шаг вперед
		s.erase(s.size() - 1);
		s.erase(s.rfind('>') + 1); // удаляем старый путь вершины
	}
	else if (position == final_vertex and number_of_steps > 0) //если шаги еще есть и позиция является конечной
	{
		X_to_Y_not_Q(position - 1, final_vertex, number_of_steps - 1, q_rock, number_of_angles, vivod, zadan); // рекурсия на шаг назад
		X_to_Y_not_Q(position + 1, final_vertex, number_of_steps - 1, q_rock, number_of_angles, vivod, zadan); // рекурсия на шаг вперед
		s.erase(s.size() - 1);
		s.erase(s.rfind('>') + 1);  // удаляем старый путь вершины
	}
	else if (position == final_vertex and number_of_steps == 0) // если шаги закончились и конечная точка достигнута
	{
		good_ways++; // добавляем количество удачных путей
		s.erase(s.size() - 1); // удаляем >
		std::cout << s; // выводим путь
		s.erase(s.rfind('>') + 1); // удаляем вершину
		if (vivod) // если выводим все пути
			std::cout << " - удачный путь " << std::endl; // помечаем данный путь как удачный
		else
			std::cout << std::endl; // просто ищем другой удачный
	}
	else
	{
		if (vivod) // если выводим все пути
		{
			s.erase(s.size() - 1); // удаляем >
			std::cout << s << std::endl; // выводим путь
			s.erase(s.rfind('>') + 1); // удаляем вершину
		}
		else
		{
			s.erase(s.size() - 1); // удаляем >
			s.erase(s.rfind('>') + 1); // удаляем > и вершину
		}
		return;
	}
}

void X_to_bomb(int position, int bomb, int number_of_steps, int number_of_angles) // функция для расчета удачных и неудачных путей через n секунд, когда в одной из вершин мина
{
	if (position == -1) // если меньше 0
		position = number_of_angles - 1; // максимальный индекс n-угольника
	if (position == number_of_angles) // если больше максимального индекса n-угольника
		position = 0; // минимальный индекс n-угольника

	if (position == bomb and number_of_steps > 0) // если достигли мины и шаги еще есть
	{
		bad_ways++; // добавляем неудачный путь
		return;
	}
	else if (position != bomb and number_of_steps > 0) // если не достигли мины и шаги еще есть
	{
		X_to_bomb(position - 1, bomb, number_of_steps - 1, number_of_angles); // рекурсия на шаг назад
		X_to_bomb(position + 1, bomb, number_of_steps - 1, number_of_angles); // рекурсия на шаг вперед
	}
	else if (position != bomb and number_of_steps == 0) // если не достигли мины и шагов уже нет 
	{
		good_ways++; // добавляем удачный путь
		return;
	}
	else
		return;
}

void vvod(int &first_vertex, int &last_vertex, int &number_of_steps, int &number_of_angles, int param) // функция для оптимизации приема переменных
{
	std::cout << "Введите индекс начальной позиции: ";
	first_vertex = checkdigit();
	if (!param) // для вывода задания с миной 
	{
		std::cout << "Введите индекс конечной позиции: ";
		last_vertex = checkdigit();
		std::cout << "Введите количество шагов: ";
		number_of_steps = checkdigit();
	}
	else
	{
		std::cout << "Введите индекс позиции, в которой находится мина: ";
		last_vertex = checkdigit();
		std::cout << "Введите время, которое кузнечик должен продержаться: ";
		number_of_steps = checkdigit();
	}
	std::cout << "Введите количество вершин n-угольника: ";
	number_of_angles = checkdigit();
}


int main()
{
	setlocale(0, ""); // локализация
	int number_of_steps; // количество шагов
	int vidod; // для вывода всех путей или только удачных
	int first_vertex; // начальная позиция кузнечика
	int last_vertex; // конечная позиция, которую должен достигнуть кузнечик
	int number_of_angles; // количество углов в n-угольнике
	int q_rock; // индекс, через который не проходит кузнечик

	// Задание 1 - по заданным значениям
	std::cout << "Задание 1 - Количество путей от А до С за n шагов" << std::endl;
	std::cout << "Введите количество шагов: ";
	number_of_steps = checkdigit();
	std::cout << "Необходимо ли выводить все пути? (y/n): ";
	vidod = checkparam();
	std::cout << "пути от А до С за " << number_of_steps << " шагов" << std::endl;
	X_to_Y(0, 2, number_of_steps, 8, vidod, 0);
	std::cout << "Количество хороших путей: " << good_ways << std::endl;


	// Задание 2 - по заданным значениям
	good_ways = 0;
	std::cout << std::endl << "Задание 2 - Пути от А до С без захода в вершину Е за n шагов" << std::endl;
	std::cout << "Введите количество шагов: ";
	number_of_steps = checkdigit();
	std::cout << "Необходимо ли выводить все пути? (y/n): ";
	vidod = checkparam();
	X_to_Y_not_Q(0, 2, number_of_steps, 4, 8, vidod, 0);
	std::cout << "Количество хороших путей: " << good_ways << std::endl;


	// Задание 3 - по заданным значениям
	good_ways = 0;
	std::cout << std::endl << "Задание 3 - Подсчет вероятности выживания кузнечика через n секунд" << std::endl;
	std::cout << "Введите количество секунд: ";
	number_of_steps = checkdigit();
	X_to_bomb(0, 4, number_of_steps, 8);
	std::cout << "Не выживает в " << bad_ways << " случаях" << std::endl;
	std::cout << "Выживает в " << good_ways <<" случаях" << std::endl;
	std::cout << "Вероятность того, что кузнечик будет жить через " << number_of_steps << " секунд равна " << 1.0 - (float(bad_ways)/float(good_ways)) << std::endl;


	// Задание 1* - по значениям пользователя
	good_ways = 0;
	std::cout << std::endl << "Задание 1* - Количество путей от X до Y за n шагов" << std::endl;
	vvod(first_vertex, last_vertex, number_of_steps, number_of_angles, 0);
	std::cout << "Необходимо ли выводить все пути? (y/n): ";
	vidod = checkparam();
	X_to_Y(first_vertex, last_vertex, number_of_steps, number_of_angles, vidod, 1);
	std::cout << "Количество хороших путей: " << good_ways << std::endl;

	// Задание 2* - по значениям пользователя
	good_ways = 0;
	std::cout << std::endl << "Задание 2* - Пути от X до Y без захода в вершину Q за n шагов" << std::endl;
	vvod(first_vertex, last_vertex, number_of_steps, number_of_angles, 0);
	std::cout << "Введите вершину, в которую нельзя прыгать: ";
	q_rock = checkdigit();
	std::cout << "Необходимо ли выводить все пути? (y/n): ";
	vidod = checkparam();
	X_to_Y_not_Q(first_vertex, last_vertex, number_of_steps, q_rock, number_of_angles, vidod, 1);
	std::cout << "Количество хороших путей: " << good_ways << std::endl;
	

	// Задание 3* - по значениям пользователя
	std::cout << std::endl << "Задание 3* - Подсчет вероятности выживания кузнечика через n секунд" << std::endl;
	good_ways = 0;
	bad_ways = 0;
	vvod(first_vertex, last_vertex, number_of_steps, number_of_angles, 1);
	X_to_bomb(first_vertex, last_vertex, number_of_steps, number_of_angles);
	std::cout << "Не выживает в " << bad_ways << " случаях" << std::endl;
	std::cout << "Выживает в " << good_ways << " случаях" << std::endl;
	std::cout << "Вероятность того, что кузнечик будет жить через " << number_of_steps << " секунд равна " << 1.0 - (float(bad_ways) / float(good_ways)) << std::endl;

	return 0;
}