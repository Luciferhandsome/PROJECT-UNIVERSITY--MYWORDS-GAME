//Made by Bùi Thanh Tùng - TEAM 6
#include <fstream>
#include <iostream>
#include<string>
#include<ctime>
#include<Windows.h>
#include<conio.h>
#include<thread>
#include <chrono>
#include <cstdlib>
#define N 100  
#pragma warning(disable : 4996)

using namespace std;


void HELP1(string& helpword, int& k, int& dem11, int& dem22, string hint, char& level);
void fileques(string word, string answer, string name);
void updateflieplayer(string word, string name);
void xuatmang(string a[], int j, string name);
void xuatmang1(string a[], int j, string name);
string nhapten(string name);
bool check(int[], int, int);


//int main()
//{
//	srand(time(NULL)); char DoKho;
//	cout << "Chon do kho cua cau (De an 'D', Trung Binh an 'T', Kho an 'K'): "; cin >> DoKho;
//	if (DoKho == 'D')
//	{
//		::system("cls");
//		CauHoiDe("Text.txt");
//	}
//	//::system("pause"); // Hiện đang bị xung đột chương trinh với hàm nào đó chưa rõ nên k dùng
//	return 0;
//}


void HELP1(string& helpword, int& k, int& dem11, int& dem22, string hint, char& level)
{
	int t[N];


	int n{};
	int dem = 0;
	string helpword11{};
	char* c = new char[helpword.size() + 1]; // ép kiểu từ string sang char để sử dụng ở phần trợ giúp ( dùng string rất khó để mở ngẫu nhiên 1 kí tự nên tôi dùng char )
	strcpy(c, helpword.c_str());// sao chép từ của số câu chữ từ mảng string sang char

	int hihi = 0;
	int vitrimoi{};
	string  helpnew;
	int dem2 = 0;
	int d;

	for (int i = 0; i < strlen(c); i++) // đếm xem có bao nhiêu kí tự
	{
		dem++;
	}

	// lấy ngẫu nhiên 1 kí tự 

	int vitrikitu1{}; // dùng để lấy vị trí kí tự 
	int f;
	int dem1 = 0;
	int count{};
	int DEM{};
	string  word(helpword.length(), '_');
	int z = 0;
	int kituchophep{};
	int kitumatdiem{};
	if (level == 'D')
	{
		kituchophep = 1;
		kitumatdiem = 1;
		count = 1;
		DEM = 1;

	}
	if (level == 'T')
	{
		kituchophep = 2;
		kitumatdiem = 1;
		count = 2;
		DEM = 1;
	}
	if (level == 'K')
	{
		kituchophep = 3;
		kitumatdiem = 2;
		count = 3;
		DEM = 2;
	}

	do
	{
		cout << "Ban con " << count << " quyen duoc lat ki tu cho phep" << endl;
		cout << "Ban co muon lat ki tu cho phep? (Co = 1/Khong = 0) (Luu y neu ban lua chon khong lat ki tu cho phep thi ban cung se mat quyen lat ki tu cam) : ";
		cin >> f;


		switch (f)

		{
		case 0:
		{

			dem1 += kituchophep;

			goto X;
			break;
		}
		case 1:

			system("cls");
			count--;
			cout << hint << endl;

			for (int i = 0; i <= dem; i++) // dùng để xác định kí tự và vị trí
			{
				int randomwordhelp = rand() % dem;
				if (check(t, z, randomwordhelp) == false)
				{
					helpword11 = c[randomwordhelp];
					vitrikitu1 = randomwordhelp;
					dem1++;
					dem11++;
					t[z++] = randomwordhelp;
					word = word.replace(vitrikitu1, 1, helpword11); /// thay thế  kí tự _  bằng kí tự ngẫu nhiên ở vòng lặp bên trên
					cout << word << endl;
					break;
				}

			}
			break;
		}

	} while (dem1 != kituchophep);


	do
	{

		cout << "Ban con " << DEM << " quyen lat ki tu cam" << endl;
		cout << "Ban co muon lat ki tu cam? (Co = 1/Khong = 0) : "; // phần này thêm phần trừ điểm vào nhé 
		cin >> d;


		switch (d)

		{
		case 0:
		{
			cout << "Ban da lua chon khong lat ki tu cam" << endl;
			goto X;
			break;
		}
		case 1:

			system("cls");
			int check1 = 0;
			DEM--;
			cout << hint << endl;
			cout << word << endl;
			for (int i = 0; i < dem; i++)
			{

				do
				{
					cout << "Ban muon lat ki tu so may? ( phai lon hon bang 0 (ki tu dau tien duoc tinh la 0) va nho hon " << dem << " (luu y khong duoc trung voi ki tu truoc do) : ";
					cin >> check1;
				} while (check1 - 1 > dem && check(t, z, check1 - 1) == true);

				if (check(t, z, check1 - 1) == true)
				{
					system("cls");
					cout << hint << endl;
					cout << word << endl;
					cout << "Vui long nhap lai vi tri " << check1 << " da trung voi vi tri truoc do " << endl;
				}
				if (check(t, z, check1 - 1) == false)
				{
					system("cls");
					cout << hint << endl;
					break;
				}
			}
			int kitu = check1 - 1;
			for (int j = 0; j <= dem; j++) // dùng để xác định kí tự và vị trí
			{
				if (kitu == j)
				{
					if (check(t, z, j) == false)
					{
						helpnew = c[j];
						vitrimoi = j;
						word = word.replace(vitrimoi, 1, helpnew); /// thay thế  kí tự _  bằng kí tự ngẫu nhiên ở vòng lặp bên trên
						cout << word << endl;
						dem2++;
						dem22++;
						break;
					}
				}
			}
			break;
		}
	} while (dem2 != kitumatdiem);


	if (hihi == 1)
	{
	X: cout << "Ban da lua chon khong lat ki tu" << endl;
	}

}

bool check(int a[], int z, int  n)
{
	for (z = 0; z < 10; z++)
	{
		if (a[z] == n)
		{
			return 1;
		}
	}
	return 0;

}

// ý tưởng của phần trợ giúp ở đây chính là : phần tử đầu tiên tôi sẽ random ngẫu nhiên, còn từ phần tử thứ 2 trở đi là
//tôi sẽ tạo 1 hàm trống không , 1 hàm thêm phần tử vào hàm đó , và hàm check xem liệu cái kí tự đó có bị trùng với kí tự đã
//lật không đó là những hàm add và check .


