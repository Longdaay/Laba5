#include <iostream>
#include <string>
#include <vector>

using namespace std;
int good_ways = 0;
int bad_ways = 0;
string s;

void F1(int digit, int n, int v)
{
	if (digit == -1)
		digit = 7;
	if (digit == 8)
		digit = 0;
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
	s.push_back('>');
	if (digit != 2 and n > 0)
	{
		F1(digit - 1, n - 1, v);
		F1(digit + 1, n - 1, v);
		s.erase(s.size() - 2);
	}
	else if (digit == 2 and n > 0)
	{
		F1(digit - 1, n - 1, v);
		F1(digit + 1, n - 1, v);
		s.erase(s.size() - 2);
	}
	else if (digit == 2 and n == 0)
	{
		good_ways++;
		s.erase(s.size() - 1);
		cout << s;
		s.erase(s.size() - 1);
		if (v)
			cout << " - удачный путь " << endl;
		else
			cout << endl;
	}
	else
	{
		if (v)
		{
			s.erase(s.size() - 1);
			cout << s << endl;
			s.erase(s.size() - 1);
		}
		else
			s.erase(s.size() - 2);
		return;
	}
}
void F2(int digit, int n, int v)
{
	if (digit == -1)
		digit = 7;
	if (digit == 8)
		digit = 0;
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
	s.push_back('>');
	if (digit == 3)
	{
		s.erase(s.size() - 2);
		return;
	}
	else if (digit != 2 and n > 0)
	{
		F2(digit - 1, n - 1, v);
		F2(digit + 1, n - 1, v);
		s.erase(s.size() - 2);
	}
	else if (digit == 2 and n > 0)
	{
		F2(digit - 1, n - 1, v);
		F2(digit + 1, n - 1, v);
		s.erase(s.size() - 2);
	}
	else if (digit == 2 and n == 0)
	{
		good_ways++;
		s.erase(s.size() - 1);
		cout << s;
		s.erase(s.size() - 1);
		if (v)
			cout << " - удачный путь " << endl;
		else
			cout << endl;
	}
	else
	{
		if (v)
		{
			s.erase(s.size() - 1);
			cout << s << endl;
			s.erase(s.size() - 1);
		}
		else
			s.erase(s.size() - 2);
		return;
	}
}

void F3(int digit, int n)
{
	if (digit == -1)
		digit = 7;
	if (digit == 8)
		digit = 0;

	if (digit == 4 and n > 0)
	{
		bad_ways++;
		return;
	}
	else if (digit != 4 and n > 0)
	{
		F3(digit - 1, n - 1);
		F3(digit + 1, n - 1);
	}
	else if (digit != 4 and n == 0)
	{
		good_ways++;
		return;
	}
	else
		return;
}

void digit_to_char(int digit)
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

void F4(int digit, int y, int n, int k, int v)
{
	if (digit == -1)
		digit = k - 1;
	if (digit == k)
		digit = 0;
	s.push_back('x');
	digit_to_char(digit);
	s.push_back('>');
	if (digit != y and n > 0)
	{
		F4(digit - 1, y, n - 1, k, v);
		F4(digit + 1, y, n - 1, k, v);
		s.erase(s.size() - 3);
	}
	else if (digit == y and n > 0)
	{
		F4(digit - 1, y, n - 1, k, v);
		F4(digit + 1, y, n - 1, k, v);
		s.erase(s.size() - 3);
	}
	else if (digit == y and n == 0)
	{
		good_ways++;
		s.erase(s.size() - 1);
		cout << s;
		s.erase(s.size() - 2);
		if (v)
			cout << " - удачный путь " << endl;
		else
			cout << endl;
	}
	else
	{
		if (v)
		{
			s.erase(s.size() - 1);
			cout << s << endl;
			s.erase(s.size() - 2);
		}
		else
			s.erase(s.size() - 3);
		return;
	}
}

void F5(int digit, int y, int n, int q, int k, int v)
{
	if (digit == -1)
		digit = k - 1;
	if (digit == k)
		digit = 0;
	s.push_back('x');
	digit_to_char(digit);
	s.push_back('>');
	if (digit == q)
	{
		s.erase(s.size() - 3);
		return;
	}
	else if (digit != y and n > 0)
	{
		F5(digit - 1, y, n - 1, q, k, v);
		F5(digit + 1, y, n - 1, q, k, v);
		s.erase(s.size() - 3);
	}
	else if (digit == y and n > 0)
	{
		F5(digit - 1, y, n - 1, q, k, v);
		F5(digit + 1, y, n - 1, q, k, v);
		s.erase(s.size() - 3);
	}
	else if (digit == y and n == 0)
	{
		good_ways++;
		s.erase(s.size() - 1);
		cout << s;
		s.erase(s.size() - 2);
		if (v)
			cout << " - удачный путь " << endl;
		else
			cout << endl;
	}
	else
	{
		if (v)
		{
			s.erase(s.size() - 1);
			cout << s << endl;
			s.erase(s.size() - 2);
		}
		else
			s.erase(s.size() - 3);
		return;
	}
}

void F6(int digit, int y, int n, int k)
{
	if (digit == -1)
		digit = k - 1;
	if (digit == k)
		digit = 0;

	if (digit == y and n > 0)
	{
		bad_ways++;
		return;
	}
	else if (digit != y and n > 0)
	{
		F6(digit - 1, y, n - 1, k);
		F6(digit + 1, y, n - 1, k);
	}
	else if (digit != y and n == 0)
	{
		good_ways++;
		return;
	}
	else
		return;
}


int main()
{
	setlocale(0, "");
	int m;
	int v;
	int x = 0; // нач
	int y = 4; // конец
	int k = 8; // n-угольник
	int q = 3; // через нее не проходит кузнец

	cout << "Введите количество шагов: ";
	cin >> m;
	cout << "Необходимо ли выводить все пути? (1/0): ";
	cin >> v;
	cout << "пути от А до С за " << m << " шагов" << endl;
	F1(0, m, v);
	cout << "Количество хороших путей: " << good_ways << endl;

	good_ways = 0;
	cout << endl << "Пути от А до С без захода в вершину Е за " << m << " шагов" << endl;
	F2(0, m, v);
	cout << "Количество хороших путей: " << good_ways << endl;

	good_ways = 0;
	cout << "Введите количество секунд: ";
	cin >> m;
	F3(0, m);
	cout << "Не выживает в " << bad_ways << " случаях" << endl;
	cout << "Выживает в " << good_ways <<" случаях" << endl;
	cout << "Вероятность того, что кузнечик будет жить через " << m << " секунд равна " << 1.0 - (float(bad_ways)/float(good_ways)) << endl;

	good_ways = 0;

	cout << "Введите начальную позицию: ";
	cin >> x;
	cout << "Введите конечную позицию: ";
	cin >> y;
	cout << "Введите количество шагов: ";
	cin >> m;
	cout << "Введите n n-угольника: ";
	cin >> k;
	F4(x, y, m, k, v);
	cout << "Количество хороших путей: " << good_ways << endl;

	good_ways = 0;
	cout << "Введите вершину, в которую нельзя прыгать: ";
	cin >> m;

	F5(x, y, m, q, k, v);
	cout << "Количество хороших путей: " << good_ways << endl;
	
	good_ways = 0;
	bad_ways = 0;
	F6(x, y, m, k);
	cout << "Не выживает в " << bad_ways << " случаях" << endl;
	cout << "Выживает в " << good_ways << " случаях" << endl;
	cout << "Вероятность того, что кузнечик будет жить через " << m << " секунд равна " << 1.0 - (float(bad_ways) / float(good_ways)) << endl;

	return 0;
}