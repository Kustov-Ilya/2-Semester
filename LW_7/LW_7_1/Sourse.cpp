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

int main(){
	bool check;
	int n = 0;
	string str;
	char delim = '\n';
	while (n < 1){
		cout << "Enter number of strings: ";
		cin >> n;
		cin.clear();
		cin.sync();
	}
	for (int i = 0; i < n; i++){
		cout << i + 1 << ": ";
		cin >> str;
		check = Palindrom(str);
		Print(str, check);
	}
	system("pause");
	return 0;
}
