#include <iostream>
#include <string>
using namespace std;

bool Palindrom(string &str){
	int len = str.size();
	for (int i = 0; i < (len / 2); i++)
	{
		if (str[i] == str[len - 1 - i])
		{
			return true;
		}
		else{
			return false;
			break;
		}
	}
}

void Print(string str, bool check){
	if (check)
	{
		cout << str << "  is palindrom" << endl;
	}
	else
	{
		cout << str << "  is'n palindrom" << endl;
	}
}

int GetN(){
	int n = 0;
	while (n < 1){
		cout << "Enter number of strings: ";
		cin >> n;
		cin.clear();
		cin.sync();
	}
	return n;
}

int main(){
	int n = GetN();
	for (int i = 0; i < n; i++){
		cout << i + 1 << ": ";
		string str;
		cin >> str;
		bool check = Palindrom(str);
		Print(str, check);
	}
	system("pause");
	return 0;
}
