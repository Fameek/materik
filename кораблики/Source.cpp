#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std; 

int main()
{
	setlocale(LC_ALL, "Russian"); // ����� �����
	srand(time(0)); //���������� ���� ���� ����� ����
	int r[90][60]; 

	for (int x = 0; x < 90; x++)
	{
		for (int y = 0; y < 60; y++)
		{
			r[x][y] = 0;
		}
	}

	int x, y, k = 0;
	int e = 0; //c���
	int n = 0; //����
	x = rand() % 10 + 10; 
	y = rand() % 70 + 40;
	r[x][y] = 1;

	for (int x = 0; x < 90; x++)
	{
		for (int y = 0; y < 60; y++)
		{
			if (r[x][y] == 0)
			{
				n++;
			}
			else e++;
		}
	}
	int t = rand() % 5200;//������������ ���� ��� �� ��������, �������� ���� ����
	for (; (e + t) < n;)
	{
		e = 0;
		n = 0;
		for (int x = 0; x < 90; x++)
		{
			for (int y = 0; y < 60; y++)
			{
				if (r[x][y] == 1)
				{
					int o, a = 0;
					o = rand() % 3 - 1;//������� �� -1 �� 1
					a = rand() % 5 - 2;//-2 2 ���� ����������� ����
					if (x + o == 0 || x + o == 89 || y + a == 2 || y + a == 57 || y + a == 0 || y + a == 58 || y + a == 1 || y + a == 59 || y + a == 60 || y + a == 3)// ���� �� �������� 
					{

					}
					else r[x + o][y + a] = 1;
				}
			}
		}
		for (int x = 0; x < 90; x++)
		{
			for (int y = 0; y < 60; y++)
			{
				if (r[x][y] == 0)
				{
					n++;
				}
				else e++;
			}
		}
	}

	for (int x = 0; x < 90; x++)
	{
		for (int y = 0; y < 60; y++)//���������� � ������� ��������
		{
			if (r[x][y] == 0) 
			{
				cout << " ";
			}
			else cout << "*";
		}
		cout << "\n";
	}

	cout << "\n" << "����������� ����: " << n << "\n" << "����������� ����:" << e << "\n" << "����� ���������" << "\n";

	return 0;
}