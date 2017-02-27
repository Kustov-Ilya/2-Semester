#include <iostream>
#include <string>
#include <fstream>

class Text
{
public:
	Text(){}
	Text(std::string &str)
		:Wor(str){}
	~Text(){}
	void BreakString(std::string &str);
	void AddWord(std::string &str);
	bool FindAndOut(std::string &str, int n);
	void Delete();
private:
	std::string Wor;
	Text *next;
	Text *prev;
};
std::string GetWordFind();
bool SpecChar(const char sim);
std::string ReadString(std::fstream & file);
int GetN();

void Text::BreakString(std::string &str){
	size_t End = str.length()+1;
	size_t Poz = 0;
	size_t EndPoz = 0;
	while (EndPoz != End){
		if (SpecChar(str[EndPoz])){
			AddWord(str.substr(Poz, EndPoz - Poz));
			Poz = EndPoz + 1;
		}
		EndPoz++;
	}
}

void Text::AddWord(std::string &str){
	if (str == "") return;
	if (this->Wor == ""){
		this->Wor = str;
		return;
	}
	Text *now = this;
	while (now->next!= nullptr) now=now->next;
	now->next = new Text(str);
	(now->next)->prev = now;
}

bool Text::FindAndOut(std::string &str, int n){
	bool Che = false;
	Text *FindWor = this;
	while (FindWor != NULL){			//Поиск str слов в структуре. При нахождении
		if (FindWor->Wor == str){		//нахождение и вывод интервала n
				int k = n;
				Text *Now = FindWor;
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
		FindWor = FindWor->next;
		}
		if (Che == true) return true;
		return false;
}

void Text::Delete(){
	Text *now = this;
	while (now->next != nullptr)
	{
		now = now->next;
		delete now->prev;
	}
	
	delete now;
}


bool SpecChar(const char sim){
	if (sim == ' ' || sim == '!' || sim == '"' ||sim == '#' || 
		sim == '$' || sim == '%' ||sim == '&' || sim == '(' || 
		sim == ')' ||sim == '*' || sim == '+' || sim == ',' ||
		sim == '-' || sim == '.' || sim == '/' ||sim == '_' || 
		sim == '?' || sim == '=' ||sim == '[' || sim == ':' || 
		sim == ';' ||sim == ']' || sim == '{' || sim == '}' || 
		sim == '^' || sim == '`' || sim == '~' || sim == '\0' || 
		sim == '\n' || sim == '\t' || sim == '\\' || sim == '\'' || 
		sim == '\v')return true;
	return false;
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
		Text *TextS = new Text();
		TextS->BreakString(ReadString(file));
		Check += TextS->FindAndOut(WordFind, n);
		TextS->Delete();
	}
	if (Check == 0) std::cout << "Word don't found" << std::endl;
	file.close();
	system("pause");
	return 0;
}
