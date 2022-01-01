//Made by Dương Quang Huy - TEAM 6
#include <fstream>
#include <iostream>
#include <string>
#include <ctime>
#include <Windows.h>
#include <conio.h>
#include <thread>
#include <chrono>
#include <cstdlib>
#include <iomanip>
using namespace std;

struct Xephang
{
    string Ten;
	int Diem{};
};

void Ranking(Xephang a[], int& n);
void TaoPlayerFile(string&);
void TruocXuLy(Xephang a[], int& n, string Ten, int& change);
void SauXuLy(Xephang a[], int& n, string Ten, int& change);
bool CheckTen(Xephang a[], int& n, string Ten);
void gotoxy(short x, short y); //Lấy từ hàm chức năng
void SapXepScoreBoard(Xephang a[], int n);

//const int N = 100;

//int main()
//{
//   
//
//
//    Ranking(arr, n);
//
//    return 0;
//}



void Ranking(Xephang a[], int& n)
{
	short c = 10;
	gotoxy(50, 5);
    cout << "~=================================~" << endl;
	gotoxy(52, 6);
    cout << "         Bang xep hang          " << endl;
	gotoxy(50, 7);
    cout << "~=================================~" << endl;
	cout << endl;

	gotoxy(54, 9); cout << "TEN";
	gotoxy(76, 9); cout << "DIEM";

    for (int i = 0; i < n; i++)
    {
		SapXepScoreBoard(a, n);
		gotoxy(54, c); cout << a[i].Ten;
		gotoxy(76, c); cout << a[i].Diem;
		c++;
    }
	cout << endl;
}

void SapXepScoreBoard(Xephang a[], int n)
{
	string temp; int tam{};
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i].Diem < a[j].Diem)
			{
				tam = a[i].Diem;
				a[i].Diem = a[j].Diem;
				a[j].Diem = tam;
				temp = a[i].Ten;
				a[i].Ten = a[j].Ten;
				a[j].Ten = temp;
			}
		}
	}
}

void TruocXuLy(Xephang a[], int& n, string Ten, int& change)
{
	change = 50;
	string temp;
	ifstream input;
	input.open("Scoreboard.txt");
	input >> n;
	input.ignore();
	for (int i = 0; i < n; i++)
	{
		getline(input, temp);
		a[i].Ten = temp;
		//cout << a[i].Ten << endl; TEST ONLY!!!
		getline(input, temp);
		a[i].Diem = stoi(temp);
		//cout << a[i].Diem << endl; TEST ONLY!!!
		//count++;
	}
	/*count += 1;
	cout << count << endl;*/

	for (int i = 0; i < n; i++)
	{
		if (Ten == a[i].Ten)
		{
			change = a[i].Diem;
		}
	}

	input.close();
}

void SauXuLy(Xephang a[], int& n, string Ten, int& change)
{
	ofstream output;
	output.open("Scoreboard.txt");
	for (int i = 0; i < n; i++)
	{
		if (Ten == a[i].Ten)
		{
			a[i].Diem = change;
		}
	}

	if (CheckTen(a, n, Ten) == false)
	{
		n++;
		for (int i = n - 1; i >= 0; i--)
		{
			a[i].Ten = Ten;
			a[i].Diem = change;
			break;
		}
	}
	
	output << n << endl;

	/*output << count;
	output << endl;*/

	for (int i = 0; i < n; i++)
	{
		output << a[i].Ten << endl;
		//cout << a[i].Ten << endl;
		output << a[i].Diem << endl;
		//cout << a[i].Diem << endl;
	}

	output.close();
}

bool CheckTen(Xephang a[], int& n, string Ten)
{
	for (int i = 0; i < n; i++)
	{
		if (a[i].Ten == Ten)
			return true;
	}

	return false;
}

////void gotoxy(short x, short y)
//{
//	static HANDLE h = NULL;
//	if (!h)
//		h = GetStdHandle(STD_OUTPUT_HANDLE);
//	COORD c = { x, y };
//	SetConsoleCursorPosition(h, c);
//}