#include <iostream>
#include <string>

using namespace std;

int main(){
	int n = 0, k=0;
	char buf[128];
	bool check = false;
	int len;
	char delim = '\n';
	while (n < 1){
		cout << "Enter number of strings: ";
		cin >> n;
		cin.clear();
		cin.sync();
	}
	string *str = new string[5*sizeof(string)];
	while (k < n){					//Чтение строк и добавление их в массив
		cout << k+1 <<": ";
		cin.getline(buf, delim);
		str[k] = buf;
		k++;
	}
	k = 0;
	while (k < n) {					//Проверка на палиндром и вывод результата
		len = str[k].size();
		for (int i = 0; i < (len / 2); i++)
		{
			if (str[k][i] == str[k][len - 1 - i])
			{
				check = true;
			}else{
				check = false;
				break;
			}
		}
		if (check == true)
		{
			cout << str[k] << "  is palindrom" << endl;
		}
		else
		{
			cout << str[k] << "  is'n palindrom" << endl;
		}
		k++;
	}
	system("pause");
	return 0;
}
