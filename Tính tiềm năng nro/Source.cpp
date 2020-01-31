#include <iostream>
#include <string>
#include <Windows.h>
#include <conio.h>
using namespace std;

void gotoxy(int x, int y);
string stringFormat(int num);
/*
{chiSo} = {1, 2, 3}
1. Trai dat
2. Namec
3. XayDa
*/
/*
{luaChon} = {1, 2}
1. Hp
2. Mp
*/
int tinhTiemNangHp(int chiSo, int hanhTinh, int luaChon) {
	int S = 0, chiSoKhoiDau;
	string loaiChiSo;
	if (luaChon == chiSo)
		chiSoKhoiDau = 200;
	else
		chiSoKhoiDau = 100;
	for (int i = chiSoKhoiDau; i < chiSo; i += 20)
		S += (1000 + i);
	return S;
}

/*
{chiSo} = {1, 2, 3}
1. Trai dat
2. Namec
3. XayDa
*/
int tinhTiemNangSucDanh(int chiSo, int hanhTinh) {
	int S = 0, chiSoKhoiDau;
	if (chiSo == 3)
		chiSoKhoiDau = 15;
	else
		chiSoKhoiDau = 12;
	for (int i = chiSoKhoiDau; i < chiSo; i++)
		S += i * 100;
	return S;
}

int tinhTiemNangGiap(int chiSo) {
	int S = 500000;
	for (int i = 0; i < chiSo; i++)
		S += i * 100000;
	return S;
}

int menu(string hanhTinhString) {
	int luachon;
	system("cls");
	cout << "\n\n\tHanh tinh: " << hanhTinhString;
	cout << "\n\n\n\n\t\t=================Lua chon tinh tiem nang=================\n\n\n\n";
	cout << "\n\t1. tinh tiem nang hp\n";
	cout << "\n\t2. tinh tiem nang mp\n";
	cout << "\n\t3. tinh tiem nang suc danh\n";
	cout << "\n\t4. tinh tiem nang giap\n";
	cout << "\n\tNhap vao lua chon: ";
	return _getch() - '0';
}

int main() {
	int luaChon, chiSo;
	int hanhTinh;
	string hanhTinhString;
	while (true) {
		cout << "\n\n\tNhap vao hanh tinh:\n";
		cout << "\n\t- (1): Trai dat";
		cout << "\n\t- (2): Namec";
		cout << "\n\t- (3): XayDa";
		gotoxy(28, 2);
		cout << (hanhTinh = _getch() - '0');
		if (hanhTinh >= 1 && hanhTinh <= 3) {
			break;
		}
		gotoxy(0, 8);
		cout << "\tNhap sai nhap lai.";
		_getch();
		system("cls");
	}
	switch (hanhTinh)
	{
	case 1:
		hanhTinhString = "Trai dat";
		break;
	case 2:
		hanhTinhString = "Namec";
		break;
	case 3:
		hanhTinhString = "XayDa";

	}
	while (true)
	{
		cout << (luaChon = menu(hanhTinhString));
		if (luaChon <= 4 && luaChon >= 1) {
			cout << "\n\n\tNhap vao so luong chi so: ";
			cin >> chiSo;
			if (luaChon == 1 && luaChon == 2) {
				cout << "\n\n\tChi so gan nhat co the la: " << (chiSo /= 20);
			}
			cout << "\n\n\tSo luong tiem nang can thiet de tang ";
		}
		switch (luaChon)
		{
		case 1:
			cout << "hp la: " << stringFormat(tinhTiemNangHp(chiSo, hanhTinh, luaChon));
			break;
		case 2:
			cout << "mp la: " << stringFormat(tinhTiemNangHp(chiSo, hanhTinh, luaChon));
			break;
		case 3:
			cout << "suc danh la: " << stringFormat(tinhTiemNangSucDanh(chiSo, hanhTinh));
			break;
		case 4:
			cout << "giap la: " << stringFormat(tinhTiemNangGiap(chiSo));
			break;
		case 0:
			exit(0);
		default:
			cout << "nhap sai nhap lai";
			break;
		}
		_getch();
	}
}

void gotoxy(int x, int y)
{
	static HANDLE h = NULL;
	if (!h)
		h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD c = { x, y };
	SetConsoleCursorPosition(h, c);
}

string stringFormat(int num)
{
	string numWithCommas = to_string(num);
	int insertPosition = numWithCommas.length() - 3;
	while (insertPosition > 0) {
		numWithCommas.insert(insertPosition, ",");
		insertPosition -= 3;
	}
	return numWithCommas;
}