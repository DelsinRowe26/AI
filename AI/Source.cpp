#include <iostream>
#include <string>
#include <Windows.h>
#include <cstdlib>
#include <fstream>
#include <ShellAPI.h>
#include <winuser.h>
#include <locale>
#include <algorithm>
#include <fileapi.h>
//#include <SDL.h>
using namespace std;
void  toUpperCase(string& my_word)
{
	transform(my_word.begin(), my_word.end(), my_word.begin(), ::toupper);
}
int main() {
	setlocale(LC_ALL, "RUS");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	string my_word, my_name, Ai_name;
	LPCSTR filename;
	ifstream Ai_name_save, my_name_save;
	int pos_Please, pos_Thanks;
	try {
		Ai_name_save.open("Ai_name_and_my_name.txt");
		Ai_name_save >> Ai_name;
		my_name_save.open("Ai_name_and_my_name.txt");
		my_name_save >> my_name;
		if (Ai_name == "" && my_name == "") {
			cout << "�������� ����" << endl;
			getline(cin, Ai_name);
			ofstream Ai_name_save;
			Ai_name_save.open("Ai_name_and_my_name.txt");
			Ai_name_save << Ai_name;
			Ai_name_save.close();
			cout << "������� ���� ���" << endl;
			getline(cin, my_name);
			ofstream my_name_save;
			my_name_save.open("Ai_name_and_my_name.txt");
			my_name_save << my_name;
			my_name_save.close();
			cout << "������������" << " " << my_name << ", " << "���� �����" << " " << Ai_name << endl;
		} //�������� �������� � �����
		else {
			cout << "������������" << " " << my_name << endl;
		}
		getline(cin, my_word);
		while (my_word != "����" && my_word != "GOOD BYE" && my_word != "�����") {
			if (my_word != "") {}
			else {
				getline(cin, my_word);
			}
			if (my_word != Ai_name) {
				cout << "��� � ���� ������?" << endl;
			}
			else {
				cout << "��� � ���� ������?" << endl;
			}
			getline(cin, my_word);
			toUpperCase(my_word);
			//cout << my_word;
			pos_Please = my_word.find("����������");//������� ����� "����������"
			pos_Thanks = my_word.find("�������");//������� ����� "�������"
			if (pos_Please > -1 && pos_Please != 0) {
				my_word.erase(pos_Please - 1, 11);//������� ����� "����������"
			}
			else if (pos_Thanks > -1 && pos_Thanks != 0) {
				my_word.erase(pos_Thanks - 1, 8);//������� ����� "�������"
			}
			else if (pos_Please == 0) {
				my_word.erase(pos_Please, 11);
			}
			else if (pos_Thanks == 0) {
				my_word.erase(pos_Thanks, 8);
			}
			if (my_word == "������ ���� D") {
				filename = "D:";
				DWORD GetFullPathNameA(
					LPCSTR filename,
					DWORD path,
					LPSTR lpBuffer,
					LPSTR lpFilePart
				);
				//cout << GetFullPathNameA;
				ShellExecuteA(NULL, "open", "d:", NULL, NULL, SW_RESTORE);
			}
			else if (my_word == "������ ���� E") {
				ShellExecuteA(NULL, "open", "e:", NULL, NULL, SW_RESTORE);
			}
			else if (my_word == "������ ���� C") {
				ShellExecuteA(NULL, "open", "c:", NULL, NULL, SW_RESTORE);
			}
			else if (my_word == "������ ����� � ������") {
				ShellExecuteA(NULL, "open", "d:\\����� �����\\���� ", NULL, NULL, SW_RESTORE);
			}
			else if (my_word == "������ ����� ����� �� ����� D") {
				ShellExecuteA(NULL, "open", "d:\\����� ����� ", NULL, NULL, SW_RESTORE);
			}
			else if (my_word == "������ ����� ����������") {
				ShellExecuteA(NULL, "open", "d:\\����� �����\\���������� ", NULL, NULL, SW_RESTORE);
			}
			else if (my_word == "������ �������") {
				ShellExecuteA(NULL, "open", "d:\\program\\Adobe Photoshop 2020\\photoshop.exe ", NULL, NULL, SW_RESTORE);
			}
			else if (my_word == "������ ���� � ��������") {
				ShellExecuteA(NULL, "open", "new file photo.ahk", NULL, NULL, SW_RESTORE);
			}
			else if (my_word == "������ �������") {
				system("TASKKILL /F /IM photoshop.exe 1>NULL");
			}
			else if (my_word == "������ �������") {
				ShellExecuteA(NULL, "open", "c:\\Users\\DelsinRowe\\AppData\\Local\\Programs\\Opera GX\\launcher.exe ", NULL, NULL, SW_RESTORE);
			}
			else if (my_word == "������ �������") {
				system("TASKKILL /F /IM opera.exe 1>NULL");
			}
			//else if (my_word == "")
			else if (my_word == "�����") {
				system("PAUSE");
			}
			if (my_word != "����" && my_word != "GOOD BYE" && my_word != "�����") {
				my_word = "";
			}
		}
	}
	catch(int main){
		int msgboxID = MessageBox(
        NULL,
        (LPCWSTR)L"��!\n ������.\n ��, ������.\n 1-��. ���� ����������\n 2-��. ��������� ������� �������, � ��� ��������\n",
        (LPCWSTR)L"��!",
        MB_ICONERROR | MB_OK
		);
		//MB_OK(MB_ICONERROR,"��!\n ������.\n ��, ������.\n 1-��. ���� ����������\n 2-��. ��������� ������� �������, � ��� ��������\n");
		/*cout << "��!" << endl;
		Sleep(2000);
		cout << "������." << endl;
		Sleep(2000);
		cout << "��, ������." << endl;
		Sleep(2000);
		cout << "1-��. ���� ����������." << endl;
		Sleep(2000);
		cout << "2-��. ���� ��� �� ����������, ����� ��������� ������� �������, � ��� ��������).";*/
	}
	return 0;
}
