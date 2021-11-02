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
			cout << "Назовите меня" << endl;
			getline(cin, Ai_name);
			ofstream Ai_name_save;
			Ai_name_save.open("Ai_name_and_my_name.txt");
			Ai_name_save << Ai_name;
			Ai_name_save.close();
			cout << "Введите ваше имя" << endl;
			getline(cin, my_name);
			ofstream my_name_save;
			my_name_save.open("Ai_name_and_my_name.txt");
			my_name_save << my_name;
			my_name_save.close();
			cout << "Здравствуйте" << " " << my_name << ", " << "меня зовут" << " " << Ai_name << endl;
		} //Сохрание названия и имени
		else {
			cout << "Здравствуйте" << " " << my_name << endl;
		}
		getline(cin, my_word);
		while (my_word != "ПОКА" && my_word != "GOOD BYE" && my_word != "СПАТЬ") {
			if (my_word != "") {}
			else {
				getline(cin, my_word);
			}
			if (my_word != Ai_name) {
				cout << "Чем я могу помочь?" << endl;
			}
			else {
				cout << "Чем я могу помочь?" << endl;
			}
			getline(cin, my_word);
			toUpperCase(my_word);
			//cout << my_word;
			pos_Please = my_word.find("ПОЖАЛУЙСТА");//Находим слово "Пожалуйста"
			pos_Thanks = my_word.find("СПАСИБО");//Находим слово "Спасибо"
			if (pos_Please > -1 && pos_Please != 0) {
				my_word.erase(pos_Please - 1, 11);//Удаляем слово "Пожалуйста"
			}
			else if (pos_Thanks > -1 && pos_Thanks != 0) {
				my_word.erase(pos_Thanks - 1, 8);//Удаляем слово "Спасибо"
			}
			else if (pos_Please == 0) {
				my_word.erase(pos_Please, 11);
			}
			else if (pos_Thanks == 0) {
				my_word.erase(pos_Thanks, 8);
			}
			if (my_word == "ОТКРОЙ ДИСК D") {
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
			else if (my_word == "ОТКРОЙ ДИСК E") {
				ShellExecuteA(NULL, "open", "e:", NULL, NULL, SW_RESTORE);
			}
			else if (my_word == "ОТКРОЙ ДИСК C") {
				ShellExecuteA(NULL, "open", "c:", NULL, NULL, SW_RESTORE);
			}
			else if (my_word == "ОТКРОЙ ПАПКУ С ИГРАМИ") {
				ShellExecuteA(NULL, "open", "d:\\Новая папка\\Игры ", NULL, NULL, SW_RESTORE);
			}
			else if (my_word == "ОТКРОЙ НОВУЮ ПАПКУ НА ДИСКЕ D") {
				ShellExecuteA(NULL, "open", "d:\\Новая папка ", NULL, NULL, SW_RESTORE);
			}
			else if (my_word == "ОТКРОЙ ПАПКУ МАЙКРОСОФТ") {
				ShellExecuteA(NULL, "open", "d:\\Новая папка\\майкрасофт ", NULL, NULL, SW_RESTORE);
			}
			else if (my_word == "ОТКРОЙ ФОТОШОП") {
				ShellExecuteA(NULL, "open", "d:\\program\\Adobe Photoshop 2020\\photoshop.exe ", NULL, NULL, SW_RESTORE);
			}
			else if (my_word == "СОЗДАЙ ФАЙЛ В ФОТОШОПЕ") {
				ShellExecuteA(NULL, "open", "new file photo.ahk", NULL, NULL, SW_RESTORE);
			}
			else if (my_word == "ЗАКРОЙ ФОТОШОП") {
				system("TASKKILL /F /IM photoshop.exe 1>NULL");
			}
			else if (my_word == "ОТКРОЙ БРАУЗЕР") {
				ShellExecuteA(NULL, "open", "c:\\Users\\DelsinRowe\\AppData\\Local\\Programs\\Opera GX\\launcher.exe ", NULL, NULL, SW_RESTORE);
			}
			else if (my_word == "ЗАКРОЙ БРАУЗЕР") {
				system("TASKKILL /F /IM opera.exe 1>NULL");
			}
			//else if (my_word == "")
			else if (my_word == "НИЧЕМ") {
				system("PAUSE");
			}
			if (my_word != "ПОКА" && my_word != "GOOD BYE" && my_word != "СПАТЬ") {
				my_word = "";
			}
		}
	}
	catch(int main){
		int msgboxID = MessageBox(
        NULL,
        (LPCWSTR)L"Ля!\n Ошибка.\n Ну, бывает.\n 1-ое. Либо обновление\n 2-ое. Создатель немного затупил, и все исправит\n",
        (LPCWSTR)L"Ой!",
        MB_ICONERROR | MB_OK
		);
		//MB_OK(MB_ICONERROR,"Ля!\n Ошибка.\n Ну, бывает.\n 1-ое. Либо обновление\n 2-ое. Создатель немного затупил, и все исправит\n");
		/*cout << "Ля!" << endl;
		Sleep(2000);
		cout << "Ошибка." << endl;
		Sleep(2000);
		cout << "Ну, бывает." << endl;
		Sleep(2000);
		cout << "1-ое. Либо обновление." << endl;
		Sleep(2000);
		cout << "2-ое. Если это не обновление, тогда создатель немного затупил, и все исправит).";*/
	}
	return 0;
}
