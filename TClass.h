#include<iostream>
#include <string>

//HaSoPr-hardware and software protection
class THaSoPr{
private:
	std::string Name;
	std::size_t Nomber;
public:


	//����������
	~THaSoPr();


	//����������� �� ���������
	THaSoPr();


	//���������������� �����������
	THaSoPr(const std::string & nName, const std::size_t & nNomber);


	//������� ������ 
	void Print();


	//�������, ����������� ����� �� ��� �� ������������ ��� ��������� ������
	bool Check(const std::size_t & nNomber);
};
