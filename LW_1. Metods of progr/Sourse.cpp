#include"Class.h"

int main(){
	int q = 0;
	char buf[128];
	String *pF;           //Указатель на последний элемент списка строк
	initList(&pF);
	ifstream file;
	file.open("Text1.txt", ios::in);
	if (!file) {
		cout << "File error - can't open to read data!";
		cin.sync(); 
		cin.get(); 
		return 2;
	}
	while (1) {           //Чтение перового файла
		char *s;
		if (file.eof()) break;
		file.getline(buf, sizeof(buf));
		q++;
		s = (char *)malloc(strlen(buf) + 1);
		strcpy_s(s, strlen(buf) + 1, buf);
		if (Find(pF, s, FILE_1, q) != 1){
			String *p = new String;
			p->Nom1 = 1;
			p->Nom2 = 0;
			p->Str = (char *)malloc(strlen(s) + 1);
			strcpy_s(p->Str, strlen(s) + 1, s);
			AddElem(&pF, p, q);
		}
		free(s);
	}
	file.close();
	q = 0;
	file.open("Text2.txt", ios::in);
	if (!file) {
		cout << "File error - can't open to read data!";
		cin.sync();
		cin.get();
		return 2;
	}
	while (1) {               //Чтение второго файла
		char *s;
		if (file.eof()) break;
		q++;
		file.getline(buf, sizeof(buf));
		s = (char *)malloc(strlen(buf) + 1);
		strcpy_s(s, strlen(buf) + 1, buf);
		if (Find(pF, s, FILE_2, q) != 1){
			String *p = new String;
			p->Nom1 = 0;
			p->Nom2 = 1;
			p->Str = (char *)malloc(strlen(s) + 1);
			strcpy_s(p->Str, strlen(s) + 1, s);
			AddElem(&pF, p, q);
		}
		free(s);
	}
	file.close();
	check(pF);
	freeList(&pF);
	system("pause");
	return 0;
}
