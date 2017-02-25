#include"Head.h"

int InitText(Text **Head){
	(*Head) = NULL;
	return 1;
}

int AddWord(Text **Head, Text *word){
	if (*Head == NULL) {		//Проверка на наличие первого слова
		*Head = word;
		(*Head)->next = NULL;
		(*Head)->prev = NULL;
		return 1;
	}
	Text *tmp = word;
	Text *Prev = *Head;
	while (Prev->next != NULL)
	{
		Prev = Prev->next;
	}
	Prev->next = tmp;
	tmp->next = NULL;
	tmp->prev = Prev;
	return 1;
}

void DeleteText(Text **Head){
	Text *Current;
	while (*Head != NULL)
	{
		Current = *Head;
		*Head = Current->next;
		delete Current;
	}
}

void Check(Text *Head, const string str, const int n){
	bool Che = false;
	while (Head != NULL){			//Поиск str слов в структуре. При нахождении
		if (Head->Wor == str){		//нахождение и вывод интервала n
			int k = n;
			Text *Now = Head;
			int i = 0;
			while (i<k && Now->prev != NULL){
				Now = Now->prev;
				i++;
			}
			k += i;
			int t = 0;
			while (t <= k && Now != NULL){
				cout << " " << Now->Wor;
				Now = Now->next;
				if (t == i) cout << "(!!!)"; //Выделение слова, которое нашли
				t++;
			}
			cout << endl;
			Che = true;
		}
		Head = Head->next;
	}
	if (Che == false) cout << " Word not found" << endl;
}
