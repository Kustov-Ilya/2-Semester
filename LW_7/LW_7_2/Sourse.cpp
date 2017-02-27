#include <iostream>
#include <string>
#include <fstream>

struct Words
{
	std::string Word;
	Words * prev;
	Words * next;
};

class Text
{
public:
	Text(){}
	~Text(){
		while (Wor != nullptr) {
			Words * tmp = Wor->next;
			delete Wor;
			Wor = tmp;
		}
	}
	void BreakString(std::string &str);
	void AddWord(std::string &str);
	bool FindAndOut(std::string &str, int n);
private:
	Words *Wor;
};
std::string GetWordFind();
bool SpecChar(const char sim);
std::string ReadString(std::fstream & file);
int GetN();

void Text::BreakString(std::string &str){
	size_t End = str.length() + 1;
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
	if (Wor == nullptr){

		Wor = new Words;
		Wor->Word = str;
		Wor->next = nullptr;
		Wor->prev = nullptr;
		return;
	}
	Words *Now = Wor;
	while (Now->next != nullptr) Now = Now->next;
	Now->next = new Words;
	Now->next->Word = str;
	Now->next->next = nullptr;
	(Now->next)->prev = Now;
}

bool Text::FindAndOut(std::string &str, int n){
	bool Che = false;
	while (this->Wor != nullptr){
		if (this->Wor->Word == str){
			int k = n;
			int i = 0;
			Words *Now = Wor;
			while (i<k && Now->prev != nullptr){
				Now = Now->prev;
				i++;
			}
			k += i;
			int t = 0;
			while (t <= k && Now != nullptr){
				std::cout << "  " << Now->Word;
				Now = Now->next;
				if (t == i) std::cout << "(!!!)";
				t++;
			}
			std::cout << std::endl;
			Che = true;
		}
		this->Wor = this->Wor->next;
	}
	if (Che == true) return true;
	return false;
}

bool SpecChar(const char sim){
	if (sim == ' ' || sim == '!' || sim == '"' || sim == '#' ||
		sim == '$' || sim == '%' || sim == '&' || sim == '(' ||
		sim == ')' || sim == '*' || sim == '+' || sim == ',' ||
		sim == '-' || sim == '.' || sim == '/' || sim == '_' ||
		sim == '?' || sim == '=' || sim == '[' || sim == ':' ||
		sim == ';' || sim == ']' || sim == '{' || sim == '}' ||
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
	int n = -1;
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
	}
	if (Check == 0) std::cout << "Word don't found" << std::endl;
	file.close();
	system("pause");
	return 0;
}
