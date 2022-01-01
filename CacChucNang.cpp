//Made by Phạm Nguyễn Gia Hưng - TEAM 6
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
#include<playsoundapi.h>
#include<windef.h>
#pragma comment(lib, "winmm.lib")

using namespace std;

void doan_dap_an_muc_de(); //Hàm dùng để đếm ngược của mức dễ
void doan_dap_an_muc_tb(); //Hàm đếm ngược của mức tr bình
void doan_dap_an_muc_kho(); //Hàm đếm ngược của mức khó
void nhap_dap_an_muc_de(string& answer); //Hàm dùng để nhập đáp án trong vòng 5s
void nhap_dap_an_muc_tb(string& answer); //Hàm dùng để nhập đáp án trong vòng 7s
void nhap_dap_an_muc_kho(string& answer); //Hàm dùng để nhập đáp án trong vòng 9s
void thanhloading();
void stART();
void gotoxy(short x, short y);
std::string timedLineInput(std::chrono::milliseconds waitDuration, size_t maxLen = 60, bool showTimer = true,
	DWORD sleepDurationPerFrame = 30);
void TextColor(int color);
void SetColor(WORD color);
void setFontSize(int FontSize);
void SetBGColor(WORD color);
void aSangA(string& a);
void MYWORD();
void VeDe(string answer);
void VeTrungBinh(string answer);
void VeKho(string answer);


//int main()
//{
//	//Phần test và đồng bộ sẽ được thực hiện ở file main.cpp
//	return 0;
//}


void doan_dap_an_muc_de()
{
	int n = 10;
	cout << "COUNTDOWN!!!!, SUY NGHI NAO!!" << endl;
	do
	{

		cout << "00:10";
		cout << "\b\b\b\b\b";
		if (n < 10)
			cout << "00:0" << n << "\b"; Sleep(1050); cout << "\b\b\b\b\b";
		n = n--;

	} while (n >= 0);

	cout << endl;
	Sleep(500);

}

void doan_dap_an_muc_tb()
{
	int n = 15;
	cout << "COUNTDOWN!!!!, SUY NGHI NAO!!" << endl;
	do
	{

		if (n >= 10) 
		{
			cout << "\b\b\b\b\b";
			cout << "00:" << n << "\b"; //Sleep(400);
		}
		if (n < 10)
			cout << "00:0" << n << "\b"; Sleep(1050); cout << "\b\b\b\b\b";
		n = n--;

	} while (n >= 0);

	cout << endl;
	Sleep(500);

}

void doan_dap_an_muc_kho()
{
	int n = 20;
	cout << "COUNTDOWN!!!!, SUY NGHI NAO!!" << endl;
	do
	{

		if (n >= 10) 
		{
			cout << "\b\b\b\b\b";
			cout << "00:" << n << "\b"; //Sleep(200);
		}
		if (n < 10)
			cout << "00:0" << n << "\b"; Sleep(1050); cout << "\b\b\b\b\b";
		n = n--;

	} while (n >= 0);

	cout << endl;
	Sleep(500);

}

void nhap_dap_an_muc_de(string& answer)
{
	cout << "Vui long nhap dap an trong vong 5 giay" << endl;
	answer = timedLineInput(std::chrono::seconds(5), 10);
	if (answer == "") ///nếu người dùng ko nhập gì hết thì answer sẽ la khoản trắng tức người dùng chưa nhập kịp thời tuy nhiên sẽ bị chương trình sẽ bị hiểu sai nếu ngưới dùng nhấn spacebar
		cout << "OOPSSS TIME IS UPPPP!!!!" << endl;
	else
		cout << "Cau tra loi cua ban la: " << answer << endl;

}

void VeDe(string answer)
{
	aSangA(answer);
	system("cls");//// cho nay tui dung de xoa trong qua trinh test cho dễ nhìn
	setFontSize(14);
	if (answer == "BITCOIN") {
		ifstream file;
		file.open("bitcoin.txt", ios_base::in);
		string line;
		while (!file.eof())
		{
			getline(file, line);
			cout << line << endl;
			Sleep(100);

		}
		Sleep(9000);
		system("cls");
	}
	if (answer == "HANOI") {
		cout << " DAY LA THAP RUA O HA NOI";
		Sleep(3000);
		ifstream file;
		file.open("HANOI.txt", ios_base::in);
		string line;
		while (!file.eof())
		{
			getline(file, line);
			cout << line << endl;
			Sleep(100);
		}
		Sleep(9000);
		system("cls");
	}
	if (answer == "LOKI") {
		cout << " DAY LA LOKI" << endl;
		ifstream file;
		file.open("loKKI.txt", ios_base::in);
		string line;
		while (!file.eof())
		{
			getline(file, line);
			cout << line << endl;
			Sleep(100);

		}
		Sleep(9000);
		system("cls");
	}
	if (answer == "LMHT") {
		cout << " DAY LA LMHT" << endl;
		ifstream file;
		file.open("LOL.txt", ios_base::in);
		string line;
		while (!file.eof())
		{
			getline(file, line);
			cout << line << endl;
			Sleep(100);

		}
		Sleep(9000);
		system("cls");
	}
	if (answer == "IPHONE") {
		cout << " DAY LA IPHONE " << endl;
		ifstream file;
		file.open("iphone.txt", ios_base::in);
		string line;
		while (!file.eof())
		{
			getline(file, line);
			cout << line << endl;
			Sleep(100);
		}
		Sleep(9000);
		system("cls");
	}
	if (answer == "ITEC") {
		cout << " DAY LA ICON CUA LOP ITEC " << endl;
		ifstream file;
		file.open("itec.txt", ios_base::in);
		string line;
		while (!file.eof())
		{
			getline(file, line);
			cout << line << endl;
			Sleep(100);
		}
		Sleep(9000);
		system("cls");
	}
	if (answer == "LAPTOP") {
		cout << " DAY LA LAPTOP " << endl;
		ifstream file;
		file.open("lap.txt", ios_base::in);
		string line;
		while (!file.eof())
		{
			getline(file, line);
			cout << line << endl;
			Sleep(100);
		}
		Sleep(9000);
		system("cls");
	}
	if (answer == "CALCULUS") {
		cout << " DAY LA kI HIEU CALCULUS " << endl;
		ifstream file;
		file.open("cal.txt", ios_base::in);
		string line;
		while (!file.eof())
		{
			getline(file, line);
			cout << line << endl;
			Sleep(100);
		}
		Sleep(9000);
		system("cls");
	}
	if (answer == "CHAI") {
		cout << " DAY LA CAI  CHAI " << endl;
		ifstream file;
		file.open("chai.txt", ios_base::in);
		string line;
		while (!file.eof())
		{
			getline(file, line);
			cout << line << endl;
			Sleep(100);
		}
		Sleep(9000);
		system("cls");
	}
	if (answer == "CONAN") {
		cout << " DAY LA CONAN " << endl;
		setFontSize(7);
		ifstream file;
		file.open("conan.txt", ios_base::in);
		string line;
		while (!file.eof())
		{
			getline(file, line);
			cout << line << endl;
			Sleep(100);
		}
		Sleep(9000);
		system("cls");
	}
	if (answer == "NOBITA") {
		cout << " DAY LA NOBITA " << endl;
		setFontSize(7);
		ifstream file;
		file.open("nobita.txt", ios_base::in);
		string line;
		while (!file.eof())
		{
			getline(file, line);
			cout << line << endl;
			Sleep(100);
		}
		Sleep(9000);
		system("cls");
	}
	if (answer == "QUATRUNG") {
		cout << " DAY LA QUA TRUNG GA " << endl;
		setFontSize(7);
		ifstream file;
		file.open("trung.txt", ios_base::in);
		string line;
		while (!file.eof())
		{
			getline(file, line);
			cout << line << endl;
			Sleep(100);
		}
		Sleep(9000);
		system("cls");
	}
	if (answer == "IPAD") {
		cout << " DAY LA IPAD " << endl;
		ifstream file;
		file.open("ipad.txt", ios_base::in);
		string line;
		while (!file.eof())
		{
			getline(file, line);
			cout << line << endl;
			Sleep(100);
		}
		Sleep(9000);
		system("cls");
	}
	if (answer == "NIKE") {
		cout << " DAY LA NIKE " << endl;
		ifstream file;
		file.open("nike.txt", ios_base::in);
		string line;
		while (!file.eof())
		{
			getline(file, line);
			cout << line << endl;
			Sleep(100);
		}
		Sleep(9000);
		system("cls");
	}
	if (answer == "SACH") {
		cout << " DAY LA QUYEN SACH " << endl;
		setFontSize(12);
		ifstream file;
		file.open("sach.txt", ios_base::in);
		string line;
		while (!file.eof())
		{
			getline(file, line);
			cout << line << endl;
			Sleep(100);
		}
		Sleep(9000);
		system("cls");
	}
	setFontSize(18);
}

void nhap_dap_an_muc_tb(string& answer)
{
	cout << "Vui long nhap dap an trong vong 7 giay" << endl;
	answer = timedLineInput(std::chrono::seconds(7), 20);
	if (answer == "") ///nếu người dùng ko nhập gì hết thì answer sẽ la khoản trắng tức người dùng chưa nhập kịp thời tuy nhiên sẽ bị chương trình sẽ bị hiểu sai nếu ngưới dùng nhấn spacebar
		cout << "OOPSSS TIME IS UPPP!!!" << endl;
	else
		cout << "Cau tra loi cua ban la: " << answer << endl;
}

void VeTrungBinh(string answer)
{
	aSangA(answer);
	system("cls");//// cho nay tui dung de xoa trong qua trinh test cho dễ nhìn
	if (answer == "NGUYENTATTHANH") {
		cout << " DAY LA NGUYEN TAT THANH " << endl; Sleep(2000);
		setFontSize(5);
		ifstream file;
		file.open("Nguyen Tat Thanh.txt", ios_base::in);
		string line;
		while (!file.eof())
		{
			getline(file, line);
			cout << line << endl;
			Sleep(100);
		}
		Sleep(9000);
		system("cls");
	}
	if (answer == "MAYTINHCAMTAY") {
		cout << " DAY LA MAY TINH CAM TAY " << endl; Sleep(2000);
		setFontSize(5);
		ifstream file;
		file.open("maytinh.txt", ios_base::in);
		string line;
		while (!file.eof())
		{
			getline(file, line);
			cout << line << endl;
			Sleep(100);
		}
		Sleep(9000);
		system("cls");
	}
	if (answer == "TUDIENBACHKHOA") {
		cout << " DAY LA TU DIEN BACH KHOA " << endl; Sleep(2000);
		setFontSize(10);
		ifstream file;
		file.open("tudien.txt", ios_base::in);
		string line;
		while (!file.eof())
		{
			getline(file, line);
			cout << line << endl;
			Sleep(100);
		}
		Sleep(9000);
		system("cls");
	}
	if (answer == "KHOAHOCTUNHIEN") {
		cout << " DAY LA LOGO TRUONG NHA QUI DI:))))))))))))) " << endl; Sleep(2000);
		setFontSize(5);
		ifstream file;
		file.open("logo.txt", ios_base::in);
		string line;
		while (!file.eof())
		{
			getline(file, line);
			cout << line << endl;
			Sleep(100);
		}
		Sleep(9000);
		system("cls");
	}
	if (answer == "LETHANHTRONG") {
		cout << " DAY LA THAY YEU QUY CUA CHUNG TA " << endl; Sleep(2000);
		setFontSize(5);
		ifstream file;
		file.open("LTT.txt", ios_base::in);
		string line;
		while (!file.eof())
		{
			getline(file, line);
			cout << line << endl;
			Sleep(100);
		}
		Sleep(9000);
		system("cls");
	}
	if (answer == "PHUNUVIETNAM") {
		cout << " Du biet ngay 20/10 da qua kha la lau roi, minh xin chuc cac ban nu van luon xinh dep va manh khoe nha   ";/////cac bro edit loi chuc cho tui
		setFontSize(5);
		ifstream file;
		file.open("Bohoa.txt", ios_base::in);
		string line;
		while (!file.eof())
		{
			getline(file, line);
			cout << line << endl;
			Sleep(100);
		}
		Sleep(9000);
		system("cls");
	}
	if (answer == "GIADODIENTHOAI") {
		cout << " DAY LA GIA DO DIEN THOAI " << endl; Sleep(2000);
		setFontSize(5);
		ifstream file;
		file.open("gia.txt", ios_base::in);
		string line;
		while (!file.eof())
		{
			getline(file, line);
			cout << line << endl;
			Sleep(100);
		}
		Sleep(9000);
		system("cls");
	}
	if (answer == "MOHINHLAPRAP") {
		cout << " DAY LA MO HINH LAP RAP " << endl; Sleep(2000);
		setFontSize(5);
		ifstream file;
		file.open("mohinh.txt", ios_base::in);
		string line;
		while (!file.eof())
		{
			getline(file, line);
			cout << line << endl;
			Sleep(100);
		}
		Sleep(9000);
		system("cls");
	}

	if (answer == "HOPBUTCHIMAU") {
		cout << " DAY LA HOP BUT CHI MAU " << endl; Sleep(2000);
		setFontSize(7);
		ifstream file;
		file.open("butchimau.txt", ios_base::in);
		string line;
		while (!file.eof())
		{
			getline(file, line);
			cout << line << endl;
			Sleep(100);
		}
		Sleep(9000);
		system("cls");
	}
	if (answer == "MERCEDESBENZ") {
		cout << " DAY LA LOGO CUA HANG XE DO" << endl; Sleep(2000);
		setFontSize(5);
		ifstream file;
		file.open("mer.txt", ios_base::in);
		string line;
		while (!file.eof())
		{
			getline(file, line);
			cout << line << endl;
			Sleep(100);
		}
		Sleep(9000);
		system("cls");
	}
	if (answer == "GOOGLECHROME") {
		cout << " DAY LA GIA SU YEU THICH CUA CAC BAN:>>" << endl; Sleep(2000);
		setFontSize(5);
		ifstream file;
		file.open("chrome.txt", ios_base::in);
		string line;
		while (!file.eof())
		{
			getline(file, line);
			cout << line << endl;
			Sleep(100);
		}
		Sleep(9000);
		system("cls");
	}
	if (answer == "SAINTNICHOLAS") {
		cout << " DAY LA NGUYEN BAN CUA ONG GIA NOEL" << endl; Sleep(2000);
		setFontSize(5);
		ifstream file;
		file.open("santa.txt", ios_base::in);
		string line;
		while (!file.eof())
		{
			getline(file, line);
			cout << line << endl;
			Sleep(100);
		}
		Sleep(9000);
		system("cls");
	}
	setFontSize(18);

}

void nhap_dap_an_muc_kho(string& answer)
{
	cout << "Vui long nhap dap an trong vong 9 giay" << endl;
	answer = timedLineInput(std::chrono::seconds(9), 30);
	if (answer == "") ///nếu người dùng ko nhập gì hết thì answer sẽ la khoản trắng tức người dùng chưa nhập kịp thời tuy nhiên sẽ bị chương trình sẽ bị hiểu sai nếu ngưới dùng nhấn spacebar
		cout << "OOPSSS TIME IS UPPP!!!" << endl;
	else
		cout << "Cau tra loi cua ban la: " << answer << endl;
}

void VeKho(string answer)
{
	aSangA(answer);
	system("cls");//// cho nay tui dung de xoa trong qua trinh test cho dễ nhìn
	if (answer == "TOITAIGIOIBANCUNGTHE") {
		cout << " DAY LA QUYEN SACH DO " << endl; Sleep(2000);
		setFontSize(5);
		ifstream file;
		file.open("Toitaigioi.txt", ios_base::in);
		string line;
		while (!file.eof())
		{
			getline(file, line);
			cout << line << endl;
			Sleep(10);
		}
		Sleep(9000);
		system("cls");
	}
	if (answer == "LIENMINHHUYENTHOAITOCCHIEN") {
		cout << " DAY LA Gi THi CAC BAN BIET ROI" << endl; Sleep(2000);
		setFontSize(5);
		ifstream file;
		file.open("LMHT.txt", ios_base::in);
		string line;
		while (!file.eof())
		{
			getline(file, line);
			cout << line << endl;
			Sleep(10);
		}
		Sleep(9000);
		system("cls");
	}
	if (answer == "HOWTOTRAINYOURDRAGON") {
		cout << " SUN TAT CUA CAC BAN DAY  " << endl; Sleep(2000);
		setFontSize(5);
		ifstream file;
		file.open("rong.txt", ios_base::in);
		string line;
		while (!file.eof())
		{
			getline(file, line);
			cout << line << endl;
			Sleep(10);
		}
		Sleep(9000);
		system("cls");
	}
	if (answer == "CALLOFDUTYWARZONE") {
		cout << " DOI NAO  " << endl; Sleep(2000);
		setFontSize(5);
		ifstream file;
		file.open("CONFUSE.txt", ios_base::in);
		string line;
		while (!file.eof())
		{
			getline(file, line);
			cout << line << endl;
			Sleep(10);
		}
		Sleep(9000);
		system("cls");
	}
	if (answer == "MISSIONIMPOSSIBLE") {
		cout << " NO PIC AVAILABLE  " << endl; Sleep(2000);
		setFontSize(5);

		ifstream file;
		file.open("CONFUSE.txt", ios_base::in);
		string line;
		while (!file.eof())
		{
			getline(file, line);
			cout << line << endl;
			Sleep(10);
		}
		Sleep(9000);
		system("cls");
	}
	if (answer == "TATNHIENLADEPTRAIROI") {
		cout << " KO THAC MAC NHA  " << endl; Sleep(2000);
		setFontSize(5);

		ifstream file;
		file.open("CONFUSE.txt", ios_base::in);
		string line;
		while (!file.eof())
		{
			getline(file, line);
			cout << line << endl;
			Sleep(10);
		}
		Sleep(9000);
		system("cls");
	}
	if (answer == "VIDEOASSISTANTREFEREE") {
		cout << " CHIU LUON NHA  " << endl; Sleep(2000);
		setFontSize(5);

		ifstream file;
		file.open("CONFUSE.txt", ios_base::in);
		string line;
		while (!file.eof())
		{
			getline(file, line);
			cout << line << endl;
			Sleep(10);
		}
		Sleep(9000);
		system("cls");
	}
	if (answer == "SIEUNHANDIENQUANGDO") {
		cout << " CHIU LUON NHA  " << endl; Sleep(2000);
		setFontSize(5);

		ifstream file;
		file.open("CONFUSE.txt", ios_base::in);
		string line;
		while (!file.eof())
		{
			getline(file, line);
			cout << line << endl;
			Sleep(10);
		}
		Sleep(9000);
		system("cls");
	}
	if (answer == "DAUTRUONGDANHVONGMUADONG") {
		cout << " HONG BIET VE " << endl; Sleep(2000);
		setFontSize(5);

		ifstream file;
		file.open("CONFUSE.txt", ios_base::in);
		string line;
		while (!file.eof())
		{
			getline(file, line);
			cout << line << endl;
			Sleep(10);
		}
		Sleep(9000);
		system("cls");
	}
	if (answer == "QUANGTRUONGTHOIDAI") {
		cout << " CHIU LUON aaaaa " << endl; Sleep(2000);
		setFontSize(5);

		ifstream file;
		file.open("CONFUSE.txt", ios_base::in);
		string line;
		while (!file.eof())
		{
			getline(file, line);
			cout << line << endl;
			Sleep(10);
		}
		Sleep(9000);
		system("cls");
	}
	setFontSize(18);
}

void thanhloading()
{
	int z = 1; gotoxy(12, 25);
	cout << "LOADING: ";

	TextColor(52);
	do
	{
		int randnum = rand() % (8 + 1 - 4) + 4;
		int h = rand() % (2000 + 1 - 500);

		cout << "####### " << z << "%" << "\b\b\b\b"; Sleep(h);
		z = z + randnum;
	} while (z <= 99);
	cout << "##### 100%"; Sleep(1500);

	TextColor(7);
}

void stART()
{

	gotoxy(55, 5);
	cout << "CHAO MUNG DEN VOI GAME MY WORDS (BY ITEC DEVELOPERS)"; Sleep(1000);

	while (!_kbhit())
	{
		gotoxy(70, 15);

		cout << "Press To Start"; Sleep(800);
		cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
		cout << "              "; Sleep(800);

	}
	gotoxy(70, 20);

	//SetColor(40);
	TextColor(3);
	cout << "PLEASE STAND BY....." << endl;
	TextColor(7);

	thanhloading();

	::system("cls");
}

void gotoxy(short x, short y)
{
	static HANDLE h = NULL;
	if (!h)
		h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD c = { x, y };
	SetConsoleCursorPosition(h, c);
}

std::string timedLineInput(std::chrono::milliseconds waitDuration, size_t maxLen, bool showTimer,
	DWORD sleepDurationPerFrame) 
{
	std::string buff;
	size_t cursorIndex = 0;
	using namespace std::chrono;
	const auto deadline = steady_clock::now() + waitDuration;
	bool dirty = true;
	for (;; Sleep(sleepDurationPerFrame)) 
	{
		if (steady_clock::now() >= deadline) 
		{ // time's up
			if (showTimer) std::cout << "\r" << std::fixed << std::setprecision(2) << std::setw(5) << 0.0;
			break;
		}
		if (showTimer) dirty = true;
		if (_kbhit()) 
		{
			dirty = true;
			int ch = _getch();
			if (ch == '\r' || ch == '\n') break; // break at \r or \n
			if (ch == '\b') 
			{                    // backspace
				if (!buff.empty()) 
				{             // there is character to delete
					buff.erase(--cursorIndex, 1);
					printf("\b \b"); // delete last character on screen (a hack)
				}
			}
			else if (ch == 0xE0) 
			{ // DEL, arrow keys, ... emits 2 characters 0xE0
				ch = _getch();       // and this character
				if (ch == 0x53) 
				{    // DEL
					if (!buff.empty()) 
					{
						if (cursorIndex == buff.size()) 
						{
							buff.erase(--cursorIndex);
							printf("\b \b");
						}
						else 
						{
							buff.erase(cursorIndex, 1);
						}
					}
				}
				else if (ch == 0x4b) 
				{ // left arrow
					if (cursorIndex > 0) cursorIndex--;
				}
				else if (ch == 0x4d) 
				{ // right arrow
					if (cursorIndex < buff.size()) cursorIndex++;
				}
				else if (ch == 0x47) 
				{ // Home
					cursorIndex = 0;
				}
				else if (ch == 0x4f) 
				{ // End
					cursorIndex = buff.size();
				}
			}
			else if (buff.size() < maxLen) 
			{
				buff.insert(cursorIndex++, 1, ch);
			}
		}
		if (dirty) 
		{
			std::cout << "\r" << std::string(10 + maxLen, ' ') << '\r'; // clear line
			if (showTimer) 
			{
				const duration<double> timeLeft = deadline - steady_clock::now();
				std::cout << std::fixed << std::setprecision(2) << std::setw(5) << timeLeft.count() << "s    ";
			}
			std::cout << buff;
			std::cout << std::string(buff.size() - cursorIndex, '\b');
			std::cout << std::flush;
		}
		dirty = false;
	}
	std::cout << "\n";
	return buff;
}

void SetColor(WORD color)
{
	HANDLE hConsoleOutput;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

	WORD wAttributes = screen_buffer_info.wAttributes;
	color &= 0x000f;
	wAttributes |= color;

	SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}

void setFontSize(int FontSize)
{
	CONSOLE_FONT_INFOEX info = { 0 };
	info.cbSize = sizeof(info);
	info.dwFontSize.Y = FontSize; // leave X as zero
	info.FontWeight = FW_NORMAL;

	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), NULL, &info);
}

void TextColor(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void SetBGColor(WORD color)
{
	HANDLE hConsoleOutput;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

	WORD wAttributes = screen_buffer_info.wAttributes;
	color &= 0x000f;
	color <<= 4;
	wAttributes &= 0xff0f;
	wAttributes |= color;

	SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}

void MYWORD()
{
	gotoxy(55, 0);

	PlaySound(TEXT("Bài 4.d.wav"), NULL, SND_FILENAME | SND_ASYNC);
	SetColor(15);
	TextColor(10);
	cout << "#       # #   #    #         #  #######  # # #   # ###    " << endl;
	SetColor(1);
	gotoxy(55, 1);

	cout << "# #   # #  # #      #   #   #   #     #  # # #   #    #   " << endl;
	gotoxy(55, 2);
	cout << "#   #   #   #        #  #  #    #     #  #  *    #    #   " << endl;
	gotoxy(55, 3);
	cout << "#       #   #         #   #     #######  #    *  # ###      " << endl;

	Sleep(1000);
	//setFontSize(14);
	SetColor(15);
	TextColor(15);
	stART();

	system("cls");

	TextColor(7);

}
