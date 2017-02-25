#include"Head.h"

int main(){
	Text *pF;//указатель на первый эллемент список структур
	InitText(&pF);
	int n = 0;
	string WordFind;
	string Word;
	char buf[128];
	cout << "Enter word: ";
	cin >> buf;
	WordFind = buf;
	while (n < 1){
		cout << "Enter n: ";
		cin >> n;
		cin.clear();
		cin.sync();
	}
	ifstream file;
	file.open("Text.txt", ios::in);
	if (!file) {
		cout << "File error - can't open to read data!";
		cin.sync();
		cin.get();
		return 2;
	}
	while (1) {					//Чтение файла и добавление слов в список
		if (file.eof()) break;
		file >> buf;
		Word = buf;
		Text *Wor = new Text;
		Wor->Wor = Word;
		AddWord(&pF, Wor);
	}
	file.close();
	Check(pF, WordFind, n);
	DeleteText(&pF);
	system("pause");
	return 0;
}
