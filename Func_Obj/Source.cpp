#include <iostream>

#include <string>
#include <vector>
#include <map>
#include<set>
#include <algorithm>
#include <numeric>
#include<cmath>

enum Grade
{
	F = 1,
	D,
	C,
	B,
	A
};

struct Student
{
	std::string FIO;
	std::string Group;
	std::map<std::string, Grade> Grades;
};

std::vector<Student> LoadStudents()
{
	return {
		{
			"Anna", "G7",
			{
				{ "math", Grade::A },
				{ "cs", Grade::A },
				{ "english", Grade::A },
				{ "dutch", Grade::B },
			}
		},
		{
			"Petr", "G7",
			{
				{ "math", Grade::A },
				{ "cs", Grade::B },
				{ "dutch", Grade::C },
			}
		},
		{
			"Vova", "G1",
			{
				{ "math", Grade::F },
				{ "english", Grade::F },
			}
		},
		{
			"Vasya", "G3",
			{
				{ "math", Grade::F },
				{ "english", Grade::F },
				{ "cs", Grade::B },
				{ "dutch", Grade::C },
			}
		},
		{
			"Anton", "G4",
			{
				{ "math", Grade::F },
				{ "english", Grade::F },
				{ "dutch", Grade::C },
				{ "cs", Grade::C },
			}
		},
		{
			"Masha", "G2",
			{
				{ "math", Grade::A },
			}
		},
		{
			"Sasha", "G6",
			{
				{ "english", Grade::F },
				{ "russian", Grade::F },
				{ "dutch", Grade::F },
			}
		},
		{
			"Jeka", "G2",
			{
				{ "english", Grade::A },
			}
		},
		{
			"Sveta", "G3",
			{
			}
		}
	};
}

struct FindStudentGroup
{
	std::string neededGroup;
	bool operator()(const Student& s) const
	{
		return s.Group == neededGroup;
	}
};

struct PrinterStudent
{
	void operator()(const Student& s) const
	{
		std::cout << s.FIO << " studies in " << s.Group << std::endl;
	}
};


struct GradeEqual
{
	Grade grade = Grade::A;

	bool operator()(const std::pair<std::string, Grade> & el) const
	{
		return el.second == grade;
	}
};

struct TheBestMath{
	std::string fio;
	int grade=0;

	void operator()(Student& rhs){
		auto it = rhs.Grades.find("math");
		if (it != rhs.Grades.end()) {
			if (rhs.Grades.at("math")>grade) {
				fio = rhs.FIO;
				grade = rhs.Grades.at("math");
			}
		}
	}
};

struct BadSrGrade{
	std::string fio;
	float SrGrade=5;
	void operator()(Student& rhs){
		int sum = 0;
		size_t k = 0;
		for (auto it = rhs.Grades.begin(); it != rhs.Grades.end(); ++it){
			sum += it->second;
			k++;
		}
		if (k!=0&& SrGrade > sum / k) {
			fio= rhs.FIO;
			SrGrade = sum / k;
		}
	}
};

struct BigestNumOfObj{
	std::string fio;
	int Num=0;
	bool fl = true;
	void operator()(Student& rhs){
		if (rhs.Grades.size() > Num) {
			fio = rhs.FIO;
			Num = rhs.Grades.size();
		}
	}
};

struct MarkOfDutch{
	std::string Obj = "dutch";
	void operator()(Student &rhs){
		auto it = rhs.Grades.find(Obj);
		if (it != rhs.Grades.end()) {
			std::cout << rhs.FIO << " has mark " << it->second << std::endl;
		}
		else {
			std::cout << rhs.FIO << " hasn't mark " <<  std::endl;
		}
	}
};

struct FindGroup{
	std::multimap<std::string, Student> MAP;
	
	void operator()(Student& rhs){
		MAP.insert(std::make_pair(rhs.Group, rhs));
	}
};

struct MathAndCS {
	std::vector<Student> SET;
	void operator()(Student &rhs) {
		auto it1 = rhs.Grades.find("math");
		auto it2 = rhs.Grades.find("cs");
		if (it1 != rhs.Grades.end() && it2 != rhs.Grades.end())
			if (it1->second == Grade::B&&it2->second == Grade::A)
				SET.push_back(rhs);
	}
};

struct GreatSubject 
{
	std::string Str = "Russian literature";
	void operator()(Student &rhs) {
		float sum = 0;
		int rez;
		size_t k = 0;
		Grade foo;
		for (auto it = rhs.Grades.begin(); it != rhs.Grades.end(); ++it) {
			sum += it->second;
			k++;
		}
		if (k != 0) {
			sum /= k;
			rez = ceil(sum);
			rhs.Grades.insert(std::pair<std::string, Grade>(Str, foo));
		}
		else {
			rez = rand() % 5 + 1; //Zero is not set, will be random
		}
		foo = static_cast<Grade>(rez);
		rhs.Grades.insert(std::pair<std::string, Grade>(Str, foo));
	}
};

int main()
{
	std::vector<Student> students = LoadStudents();

	// find students from G1
	FindStudentGroup finderObj;
	finderObj.neededGroup = "G1";
	auto it = std::find_if(students.begin(), students.end(), finderObj);
	if (it != students.end())
		std::cout << it->FIO << std::endl;


	// find students from G7
	it = std::find_if(students.begin(), students.end(), FindStudentGroup{ "G7" });
	if (it != students.end())
		std::cout << it->FIO << std::endl;


	// print info about all students
	std::for_each(students.begin(), students.end(), PrinterStudent());


	// count of grades eq 'A' of the student from G7
	auto cnt = std::count_if(it->Grades.begin(), it->Grades.end(), GradeEqual{});
	std::cout << cnt << std::endl;

	// count of grades eq 'B' of the student from G7
	auto cnt2 = std::count_if(it->Grades.begin(), it->Grades.end(),
		// lambda
		[](const std::pair<std::string, Grade> & el)
	{
		return el.second == Grade::B;
	});

	std::cout << cnt2 << std::endl;

	std::cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << std::endl;

	auto math = std::for_each(students.begin(), students.end(), TheBestMath());

	std::cout << math.fio << std::endl;

	auto BadGr = std::for_each(students.begin(), students.end(), BadSrGrade());

	std::cout << BadGr.fio << std::endl;

	auto Um = std::for_each(students.begin(), students.end(), BigestNumOfObj());

	std::cout << Um.fio << std::endl;

	std::for_each(students.begin(), students.end(), MarkOfDutch());

	auto Sor = std::for_each(students.begin(), students.end(), FindGroup());

	auto MaCS = std::for_each(students.begin(), students.end(), MathAndCS());

	std::for_each(students.begin(), students.end(), GreatSubject());

	system("pause");

	return 0;
}