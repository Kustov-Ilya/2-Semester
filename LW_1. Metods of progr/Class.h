#include <iostream>
#include <string>
#include <fstream>
#define FILE_1 1
#define FILE_2 2

using namespace std;

//Cтруктура номеров строк, которые не повтораются
struct StrNum{			
	int Data;
	StrNum* next;
};

//Структура строк первого и второго файла. pH - указатель 
//на последний элемент списка номеров строк
struct String
{
	StrNum *pH;
	StrNum StN;
	char *Str;
	int Nom1;
	int Nom2;
	String* next;
};

//Инициализация списка строк
void initList(String **Head);

//Инициализация списка номеров строк
void initList(StrNum **Head);

//Добавление элемента в списки строк и номеров строк 
//(используется при объявлении нового элемента списка строк)
void AddElem(String **Head, String *elem, int q);

//Добавление элемента в список номеров строк
void AddElemNum(StrNum **Head, int q);

//Очищение списков структур
int freeList(String ** Head);

//Функция проверки на наличие строки в списке
//Если строка находится, то вызывается AddElemNum 
//для данной строки
bool Find(String *Head, char *s, int t, int q);

//Функция поиска строк, которых нет в другой файле
//и вывод их в консоль
bool check(String *Head);
