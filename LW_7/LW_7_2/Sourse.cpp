#include <iostream>
#include <string>
#include <fstream>

struct Text{
	std::string Wor;
	Text *next;
	Text *prev;
};

int AddWord(Text **Head, std::string str){
	if (*Head == nullptr){
		*Head = new Text;
		(*Head)->Wor = str;
		(*Head)->next = nullptr;
		(*Head)->prev = nullptr;
		return 1;
	}
	Text *Now= *Head;
	while (Now->next!=nullptr)
	{
		Now = Now->next;
	}
	Text *tmp = new Text;
	Now->next = tmp;
	tmp->Wor = str;
	tmp->prev = Now;
	tmp->next = nullptr;
	return 1;
}

Text *BreakString(std::string str){
	size_t End = str.length()-1;
	size_t Poz = 0;
	size_t EndPoz = 0;
	Text *pH = nullptr;
	while (EndPoz <= End){
		EndPoz = str.find(' ', Poz);
		AddWord(&pH, str.substr(Poz, EndPoz - Poz));
		Poz = EndPoz+1;
	}
	return pH;
}

void Clear(Text**Head){
	while(*Head!=nullptr){
		Text *tmp = *Head;
		(*Head) = (*Head)->next;
		delete tmp;
	}
}

int FindAndOut(Text *Head, const std::string str, const int n){
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
				std::cout << "  " << Now->Wor;
				Now = Now->next;
				if (t == i) std::cout << "(!!!)"; //Выделение слова, которое нашли
				t++;
			}
			std::cout << std::endl;
			Che = true;
		}
		Head = Head->next;
	}
	if (Che == true) return 1;
	return 0;
}

std::string ReadString(std::fstream & file){
	std::string line;
	std::getline(file, line);
	return line;
}

int GetN(){
	int n=-1;
	while (n < 0){
		std::cout << "Enter n: ";
		std::cin >> n;
		std::cin.clear();
		std::cin.sync();
	}
	return n;
}

std::string GetWordFind(){
	std::string WordFind;
	std::cout << "Enter word: ";
	std::cin >> WordFind;
	return WordFind;
}

int main(){
	std::fstream file("Text.txt", std::ios::in);
	if (!file.is_open()) return 0;
	std::string WordFind = GetWordFind();
	int n = GetN();
	int Check = 0;
	while (!file.eof()){
		Text *pF = BreakString(ReadString(file));
		Check += FindAndOut(pF, WordFind, n);
		Clear(&pF);
	}
	if (Check == 0) std::cout << "Word don't found" << std::endl;
	file.close();
	system("pause");
	return 0;
}
