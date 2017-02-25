#include <iostream>
#include <string>
#include <fstream>
using namespace std;

//Cтруктура слов файла
struct Text{
	string Wor;
	Text *next;
	Text *prev;
};

//Инициализания списка
int InitText(Text **Head);

//Добавление слова в список
int AddWord(Text **Head, Text *word);


//Поиск и вывод слова str в контексте интервала n
void Check(Text *Head, const string str, const int n);

//Удаление списка структур
void DeleteText(Text **Head);
