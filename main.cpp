//Made by Trần Minh Nhật - TEAM 6
#include <fstream>
#include <iostream>
#include <string>
#include <ctime>
#include <Windows.h>
#include <conio.h>
#include <thread>
#include <chrono>
#include <cstdlib>
#include "../Các Chức Năng/CacChucNang.cpp" //Hàm đếm ngược lấy từ đây. Có thêm 1 số hàm chức năng (CacChucNang.cpp)
#include "../Trợ Giúp/TroGiup.cpp" //Lấy hàm trợ giúp ra từ đây (TroGiup.cpp)
#include "../File/File.cpp" //Lấy hàm xử lí file ra từ đây (File.cpp)
#pragma warning(disable : 4996)

using namespace std;

//Lưu ý, có một số hàm không được khai báo và hiện thực tại file này mà được hoàn thành ở các file chức năng khác sau đó được include qua file main để sử dụng


void CauHoi(const char* file, char&, int&, int&, string Name); //Hàm dành riêng cho câu hỏi dễ
void aSangA(string& a); //hàm chuyển từ kí tự thường sang hoa
bool CheckDapAn(string&, string&); //Hàm để check đáp án
int tinhdiem(string word, string answer, int dem11, int dem22, char level, int&);
void TakeData(string Data[], int&, string);
bool Check(string a[], string n, int count);
bool NameCheck(string file);



int main()
{
	srand(time(NULL)); char DoKho, luachon; string Name;
	int n{}, Diem{};
	Xephang a[30], FileArr[100]; int m{};
	string line;

	//Duoi day la phan huong dan mot so luu y cho nguoi choi 
	cout << "                ===>> LUU Y TRUOC KHI CHOI VUI LONG BAT FULLSCREEN <<===" << endl;
	cout << endl;
	cout << "===> DE BAT FULLSCREEN VUI LONG AN VAO DAU VUONG TREN GOC PHAI MAN HINH" << endl;
	cout << "===> TRONG QUA TRINH CHOI SE CO MOT SO LUU Y SAU:" << endl;
	cout << "Luu y 1: Size chu va Font chu co the bi thay doi trong qua trinh choi" << endl;
	cout << "Luu y 2: Screen co the bi thay doi kich thuoc trong qua trinh choi, ban vui long thu nho va bat Fullscreen lai mot lan nua" << endl;
	cout << "Luu y 3: Tro choi se co nhac xuyen suot qua trinh choi, neu ban cam thay khong thoai mai, mong ban thong cam" << endl;
	cout << endl;
	cout << "===>>> NEU BAN DA DOC XONG VUI LONG AN MOT KI TU BAT KI DE TIEP TUC" << endl;
	cout << endl;
	::system("pause");
	::system("cls");


	MYWORD(); //Hàm loading bắt đầu trò chơi

	//Úm ba la...
	
	//Dưới đây là một số luật chơi
	cout << "                 ~~~~~ DUOI DAY LA MOT SO LUAT CHOI BAN CAN LUU Y ~~~~~" << endl;
	cout << "==>> MY WORDS CO TONG CONG 3 CAP DO: DE, TRUNG BINH VA KHO" << endl;
	cout << "==>> LUAT CHOI CUA MOI CAP DO SE DUOC LIET KE MOI KHI BAN CHON XONG CAP DO" << endl;
	cout << "==>> TRUOC KHI CHOI BAN VUI LONG NHAP TEN, NEU TRUOC DAY BAN DA TUNG CHOI MY WORDS, CHUNG TOI SE LAY DU LIEU CHOI CU CUA BAN DE BAN CHOI TIEP, NEU BAN LA NGUOI MOI CHOI, DIEM KHOI TAO CUA BAN SE LA 50 DIEM" << endl;
	cout << endl;
	cout << "~~~  NEU BAN DA SAN SANG HAY AN MOT KI TU BAT KI DE TIEP TUC  ~~~" << endl;
	::system("pause");
	::system("cls");

	cout << "Vui long nhap vao ten cua ban (Luu y khong duoc su dung khoang trang) : ";
	getline(cin, Name);

	TruocXuLy(FileArr, m, Name, Diem); //Hàm lấy check và lấy dữ liệu từ Scoreboard.txt

	if (CheckTen(FileArr, m, Name) == true)
	{
		cout << "Chao mung nguoi choi " << Name << " da tro lai voi MY WORDS" << endl;
		cout << "Diem cua ban sau tran chien voi nhung o chu truoc do la: " << Diem << endl;
		cout << "Co 15 tu muc do De, 12 tu muc do Trung Binh, 10 tu muc do Kho da duoc load xuong" << endl;
		cout << "Luu y, nhung tu ban da tung choi va tra loi dung thi se khong duoc choi lai" << endl;
	}
	else
	{
		cout << "Chao mung linh moi " << Name << " da tham gia tro choi MY WORDS" << endl;
		cout << "Diem khoi tao cua ban la: " << Diem << ", san sang cho tran chien voi nhung o chu nao" << endl;
		cout << "Co 15 tu muc do De, 12 tu muc do Trung Binh, 10 tu muc do Kho da duoc load xuong" << endl;
	}

	cout << "~~~~ HAY AN MOT KI TU DE BAT DAU TRAN CHIEN VOI NHUNG O CHU ~~~~" << endl;
	::system("pause");
	::system("cls");
	//cout << Diem << endl; TEST ONLY!!!

	

	cout << "Vui long chon do kho cua man choi (De = 'D', Trung Binh = 'T', Kho = 'K') : "; cin >> DoKho;
	if (DoKho == 'D')
	{
		cout << "A. DOI VOI CAP DO DE:" << endl;
		cout << "=> Cac o chu se co tu 3 - 8 ki tu, may se chon ngau nhien 1 tu de ban choi" << endl;
		cout << "=> Ban se co 1 quyen lat ki tu cho phep va 1 quyen lat ki tu cam" << endl;
		cout << "=> Moi lan lat ki tu cam ban se bi tru 3 diem" << endl;
		cout << "=> Neu ban khong lat ki tu cho phep, ban duoc cong 10 diem neu tra loi dung" << endl;
		cout << "=> Neu ban lat ki tu cho phep, ban duoc cong 5 diem neu tra loi dung" << endl;
		cout << "=> Neu ban tra loi sai, ban se bi tru 2 diem" << endl;
		::system("pause");
		::system("cls");
		CauHoi("De.txt", DoKho, n, Diem, Name);
		::system("pause");
		goto X;
	}
	else if (DoKho == 'T')
	{
		cout << "B. DOI VOI CAP DO TRUNG BINH:" << endl;
		cout << "=> Cac o chu se co tu 9 - 15 ki tu, may se chon ngau nhien 1 tu de ban choi" << endl;
		cout << "=> Ban se co 2 quyen lat ki tu cho phep va 1 quyen lat ki tu cam" << endl;
		cout << "=> Moi lan lat ki tu cam ban se bi tru 5 diem" << endl;
		cout << "=> Neu ban khong lat ki tu cho phep, ban duoc cong 15 diem neu tra loi dung" << endl;
		cout << "=> Neu ban lat ki tu cho phep, ban duoc cong 8 diem neu tra loi dung" << endl;
		cout << "=> Neu ban tra loi sai, ban se bi tru 5 diem" << endl;
		::system("pause");
		::system("cls");
		CauHoi("TrungBinh.txt", DoKho, n, Diem, Name);
		::system("pause");
		goto X;
	}
	else if (DoKho == 'K')
	{
		cout << "C. DOI VOI CAP DO KHO:" << endl;
		cout << "=> Cac o chu se co tu 15 - 30 ki tu, may se chon ngau nhien 1 tu de ban choi" << endl;
		cout << "=> Ban se co 3 quyen lat ki tu cho phep va 2 quyen lat ki tu cam" << endl;
		cout << "=> Moi lan lat ki tu cam ban se bi tru 8 diem" << endl;
		cout << "=> Neu ban khong lat ki tu cho phep, ban duoc cong 20 diem neu tra loi dung" << endl;
		cout << "=> Neu ban lat ki tu cho phep, ban duoc cong 10 diem neu tra loi dung" << endl;
		cout << "=> Neu ban tra loi sai, ban se bi tru 7 diem" << endl;
		::system("pause");
		::system("cls");
		CauHoi("Kho.txt", DoKho, n, Diem, Name);
		::system("pause");
		goto X;
	}


	do 
	{
	X:
		::system("cls");
		cout << "Ban co muon tiep tuc choi khong? (Co = 'C'/Khong = 'K') : ";
		cin >> luachon;
		switch (luachon) 
		{
		case 'C':
			cout << "Vui long chon do kho cua man choi (De = 'D', Trung Binh = 'T', Kho = 'K') : "; cin >> DoKho;
			if (DoKho == 'D')
			{
				cout << "A. DOI VOI CAP DO DE:" << endl;
				cout << "=> Cac o chu se co tu 3 - 8 ki tu, may se chon ngau nhien 1 tu de ban choi" << endl;
				cout << "=> Ban se co 1 quyen lat ki tu cho phep va 1 quyen lat ki tu cam" << endl;
				cout << "=> Moi lan lat ki tu cam ban se bi tru 3 diem" << endl;
				cout << "=> Neu ban khong lat ki tu cho phep, ban duoc cong 10 diem neu tra loi dung" << endl;
				cout << "=> Neu ban lat ki tu cho phep, ban duoc cong 5 diem neu tra loi dung" << endl;
				cout << "=> Neu ban tra loi sai, ban se bi tru 2 diem" << endl;
				::system("pause");
				::system("cls");
				CauHoi("De.txt", DoKho, n, Diem, Name);
				::system("pause");
			}
			else if (DoKho == 'T')
			{
				cout << "B. DOI VOI CAP DO TRUNG BINH:" << endl;
				cout << "=> Cac o chu se co tu 9 - 15 ki tu, may se chon ngau nhien 1 tu de ban choi" << endl;
				cout << "=> Ban se co 2 quyen lat ki tu cho phep va 1 quyen lat ki tu cam" << endl;
				cout << "=> Moi lan lat ki tu cam ban se bi tru 5 diem" << endl;
				cout << "=> Neu ban khong lat ki tu cho phep, ban duoc cong 15 diem neu tra loi dung" << endl;
				cout << "=> Neu ban lat ki tu cho phep, ban duoc cong 8 diem neu tra loi dung" << endl;
				cout << "=> Neu ban tra loi sai, ban se bi tru 5 diem" << endl;
				::system("pause");
				::system("cls");
				CauHoi("TrungBinh.txt", DoKho, n, Diem, Name);
				::system("pause");
			}
			else if (DoKho == 'K')
			{
				cout << "C. DOI VOI CAP DO KHO:" << endl;
				cout << "=> Cac o chu se co tu 15 - 30 ki tu, may se chon ngau nhien 1 tu de ban choi" << endl;
				cout << "=> Ban se co 3 quyen lat ki tu cho phep va 2 quyen lat ki tu cam" << endl;
				cout << "=> Moi lan lat ki tu cam ban se bi tru 8 diem" << endl;
				cout << "=> Neu ban khong lat ki tu cho phep, ban duoc cong 20 diem neu tra loi dung" << endl;
				cout << "=> Neu ban lat ki tu cho phep, ban duoc cong 10 diem neu tra loi dung" << endl;
				cout << "=> Neu ban tra loi sai, ban se bi tru 7 diem" << endl;
				::system("pause");
				::system("cls");
				CauHoi("Kho.txt", DoKho, n, Diem, Name);
				::system("pause");
			}
			break;
		case 'K':cout << "Cam on ban da tham gia game, tam biet va hen gap lai" << endl; break;
		default: cout << "Khong ton tai lua chon " << luachon << ", vui long chon lai" << endl;
		}
	} while (luachon != 'K');

	SauXuLy(FileArr, m, Name, Diem);
	cout << "  ~~~  DUOI DAY LA BANG XEP HANG CAC NGUOI CHOI  ~~~" << endl;
	cout << endl;
	Ranking(FileArr, m);

	::system("pause");
	return 0;
}


void CauHoi(const char* file, char& DoKho, int& n, int& Diem, string Name)
{
	ifstream FileWord; //Khởi tạo biến đọc từ file 
	string RandomLine[100], Data[100], RandomWord[100], RandomHint[100],line{}, word{}, hint{}, answer{};
	int dem11 = 0, dem22 = 0, count(0); long RandomNum{};



	//cout << count << endl; TEST ONLY!!!

	FileWord.open(file); //Mở file De.txt trong phần debug, sử dụng biến FileWord để đọc dữ liệu
	FileWord >> n; //Truyền vào số câu
	FileWord.ignore();

	//Dưới đây là phần lấy dữ liệu ngẫu nhiên từ file ra để bắt đầu phân tích
	for (int i = 0; i < n; i++)
	{
		getline(FileWord, RandomLine[i]); //Gán những dòng trong file cho mảng RandomLine[]
		//cout << RandomLine[i] << endl; // TEST ONLY!!!
		RandomWord[i] = RandomLine[i].substr(0, RandomLine[i].find(";"));
		//cout << RandomWord[i] << endl; //TEST ONLY!!!
		RandomHint[i] = RandomLine[i].substr(RandomLine[i].find(";") + 1, RandomLine[i].length() - 1);
	}

	if (NameCheck(nhapten(Name)) == false)
	{    //Khu vực chống trùng câu hỏi
		TakeData(Data, count, Name);

		int i = 0;

		for (i; i < count; i++)
		{
			RandomNum = rand() % n; // lấy 1 số ngẫu nhiên từ 0 -> n - 1 (trong file có n dòng)

			if (Check(Data, RandomWord[RandomNum], count) == false)
			{
				break;
			}
		}
	}

	word = RandomWord[RandomNum];
	hint = RandomHint[RandomNum];
	
	
	//cout << word << endl; //TEST ONLY!!!
	FileWord.close(); //Đóng file Demo.txt
	int k;
	string word_(word.length(), '_'); // thay thế toàn bộ kí tự của biến word thành '_' và gán cho biến word_
	cout << hint << endl << word_ << endl;

	//Dưới đây là dành cho người chơi trả lời:
	if (DoKho == 'D')
	{
		HELP1(word, k, dem11, dem22, hint, DoKho); //Hàm trợ giúp
		cout << endl;

		cout << "Ban co 10 giay de suy nghi dap an" << endl;
		Sleep(500); //Dừng khoảng chừng là 2s để người chơi kịp đọc 
		doan_dap_an_muc_de(); // đếm ngược 10s
		cout << endl;

		nhap_dap_an_muc_de(answer); //Nhập vào đáp án và đếm ngược 5s (đồng thời)
		//Sleep(10000); //TEST ONLY!!!
		//::system("cls"); //TEST ONLY!!!
	}
	else if (DoKho == 'T')
	{
		HELP1(word, k, dem11, dem22, hint, DoKho); //Hàm trợ giúp phần tr bình
		cout << endl;

		cout << "Ban co 15 giay de suy nghi dap an" << endl;
		Sleep(500); //Dừng khoảng chừng là 2s để người chơi kịp đọc 
		doan_dap_an_muc_tb(); // đếm ngược 15s
		cout << endl;

		nhap_dap_an_muc_tb(answer); //Nhập vào đáp án và đếm ngược 7s (đồng thời)
		//Sleep(10000); //TEST ONLY!!!
		//::system("cls"); //TEST ONLY!!!
	}
	else if (DoKho == 'K')
	{
		HELP1(word, k, dem11, dem22, hint, DoKho); //Hàm trợ giúp phần khó
		cout << endl;

		cout << "Ban co 20 giay de suy nghi dap an" << endl;
		Sleep(500); //Dừng khoảng chừng là 2s để người chơi kịp đọc 
		doan_dap_an_muc_kho(); // đếm ngược 20s
		cout << endl;

		nhap_dap_an_muc_kho(answer); //Nhập vào đáp án và đếm ngược 9s (đồng thời)
		//Sleep(10000); //TEST ONLY!!!
		//::system("cls"); //TEST ONLY!!!
	}
	else cout << "Khong ton tai do kho tren, vui long nhap lai" << endl;

	aSangA(answer); //Hàm dùng để chuyển đáp án qua chữ in hoa

	if (answer.length() != 0)
	{
		if (CheckDapAn(answer, word) == true)
		{
			cout << "Chuc mung ban, " << word << " la dap an chinh xac" << endl;
			fileques(word, answer, Name);
		}
		else
			cout << "Rat tiec dap an cua ban khong chinh xac, dap an chinh xac la: " << word << endl;
	}
	else
		cout << "Rat tiec ban da khong doan duoc dap an, dap an chinh xac la: " << word << endl;

	::system("pause");
	VeDe(answer);
	VeTrungBinh(answer);
	VeKho(answer);

	cout << "Ban da su dung " << dem11 << " quyen lat ki tu cho phep va " << dem22 << " quyen lat ki tu cam" << endl;
	cout << "Diem cua ban sau man choi vua roi la : " << tinhdiem(word, answer, dem11, dem22, DoKho, Diem) << endl;

	
}

void aSangA(string& a)
{
	for (size_t i = 0; i < a.size(); i++)
	{
		if (a[i] >= 'a' && a[i] <= 'z')
			a[i] -= 32;
	}
}

bool CheckDapAn(string& answer, string& word)
{

	int comp = answer.compare(word);
	if (comp == 0)
		return true;
	else 
		return false;

}

int tinhdiem(string word, string answer, int dem11, int dem22, char level, int& diem)
{
	if (level == 'D')
	{
		if (CheckDapAn(answer, word) == true)
		{
			if (dem11 > 0)
			{
				if (dem22 > 0)
				{
					diem = diem - (dem22 * 3);
				}
				diem += 5;
			}
			else
			{
				diem += 10;
			}
		}
		else
		{
			if (dem22 > 0)
			{
				diem = diem - (dem22 * 3);
			}
			diem -= 2;
		}
	}
	else if (level == 'T')
	{
		if (CheckDapAn(answer, word) == true)
		{
			if (dem11 > 0)
			{
				if (dem22 > 0)
				{
					diem = diem - (dem22 * 5);
				}
				diem += 8;
			}
			else
			{
				diem += 15;
			}
		}
		else
		{
			if (dem22 > 0)
			{
				diem = diem - (dem22 * 5);
			}
			diem -= 4;
		}
	}
	else if (level == 'K')
	{
		if (CheckDapAn(answer, word) == true)
		{
			if (dem11 > 0)
			{
				//diem += 10;
				if (dem22 >= 1)
				{
					diem = diem - (dem22 * 8);
				}
				diem += 10;
			}
			else
			{
				diem += 20;
			}
		}
		else
		{
			if (dem22 > 0)
			{
				diem = diem - (dem22 * 8);
			}
			diem -= 6;
		}
	}
	return diem;
}

void fileques(string word, string answer, string name)// nếu người chơi trả lời đúng sẽ lưu lại kí tự vào file 
{

		// check xem file có trống hay không 
		// + nếu trống thi ghi kí tự đàu tiền vào .
		// +  nếu không thì viết kí tự và xác định vị trí cần viết rồi thay đổi biến đếm số lượng ô chữ trong câu  ++ ;


		int ochu = 0;

		fstream PlayerWord;
		PlayerWord.open(nhapten(name), ios_base::in);
		
		
		if (PlayerWord.fail())
		{
			fstream playerWord;
			playerWord.open(nhapten(name), ios_base::out);
			ochu++;
			playerWord << ochu << endl;
			playerWord << word << endl;
			playerWord << 0 << endl;
			playerWord << 0 << endl;
			playerWord.close();
			PlayerWord.close();
		}
		else
		{
			//  ton tai roi thi update 
			updateflieplayer(word, name);
		}

		//PlayerWord.close();
		


			/*fstream playerWord;
			playerWord.open(nhapten(name), ios_base::out | ios::app);
			playerWord << word << endl;
			playerWord.close();*/
			

	

}

void updateflieplayer(string word, string name)// nếu người chơi đã từng chơi trước đó sẽ update lại số ô chữ người chơi đã chơi
{
	string ochu[100];
	string ochude[100];
	string ochukho[100];
	string ochuTB[100];
	int j = 0;
	int k = 0;
	int f = 0;
	int count = 0;

	string wordFile[100];

	//  đọc từng kí tự và xác định vị trí 
	// xác định số câu đã chơi ở mỗi mức độ bằng độ dài từ 
	// 
	fstream FilePlayer;
	FilePlayer.open(nhapten(name), ios_base::in);
	while (!FilePlayer.eof())
	{
		getline(FilePlayer, wordFile[count]);

		ochu[count] = wordFile[count];

		count++;
	}
	FilePlayer.close();
	ochu[count++] = word; // thêm câu vừa trả lơi vào file 
	for (int i = 0; i < count; i++)
	{
		if (ochu[i].length() - 1 >= 9 && ochu[i].length() - 1 <= 15)
		{
			//j++;
			ochuTB[j] = ochu[i];
			j++;
		}

	}
	for (int i = 0; i <= count; i++)
	{
		if (ochu[i].length() - 1 >= 15 && ochu[i].length() - 1 <= 30)
		{
			//k++;
			ochukho[k] = ochu[i];
			k++;
		}

	}
	for (int i = 0; i <= count; i++)
	{
		if (ochu[i].length() - 1 >= 3 && ochu[i].length() - 1 <= 8)
		{
			//f++;
			ochude[f] = ochu[i];
			f++;
		}

	}

	xuatmang(ochude, f, name);
	xuatmang1(ochuTB, j, name);
	xuatmang1(ochukho, k, name);

} // 

string nhapten(string name) //  nếu muốn tạo player file thì dùng hàm này 
{

	return name + ".txt";
}

void xuatmang(string a[], int j, string name)
{
	fstream file1;
	file1.open(nhapten(name), ios_base::out);
	for (int i = 0; i <= j; i++)
	{
		if (i == 0)
		{
			file1 << j << endl;

		}
		file1 << a[i] << endl;
	}
	file1.close();
} // ghi file vào cấp độ dễ

void xuatmang1(string a[], int j, string name)
{
	fstream file1;
	file1.open(nhapten(name), ios_base::out | ios_base::app);
	for (int i = 0; i <= j; i++)
	{
		if (i == 0)
		{
			file1 << j << endl;

		}
		file1 << a[i] << endl;
	}
	file1.close();
}// ghi file vào 2 cấp độ còn lại

void TakeData(string Data[], int& count, string name)
{
	ifstream input;
	input.open(nhapten(name));
	while (!input.eof())
	{
		getline(input, Data[count]);
		count++;
	}
	input.close();
}

bool Check(string a[], string n, int count)
{
	for (int z = 0; z <= count; z++)
	{
		if (a[z] == n)
		{
			return 1;
		}
	}
	return 0;

}

bool NameCheck(string file)
{
	ifstream input;
	input.open(file);
	if (input.fail())
	{
		return true; //người chơi mới
	}
	return false;
}