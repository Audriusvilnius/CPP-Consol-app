#include <iomanip>
#include <cmath>
#include <string>
#include <vector>
#include <fstream>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
#include <istream>
#include <list>

using	std::cout;
using	std::cin;
using	std::endl;
using	std::setw;
using	std::setprecision;
using	std::fixed;
using	std::left;
using	std::right;
using	std::string;
using	std::vector;
using	std::ostream;
using	std::istream;
using	std::sort;

#include "Header.h"



class student {
private:
	string id_name;
	string id_surname;
	vector<float>nd;
	float exam;
public:
	vector<student>list;
	float mean;
	float median;
	float grade;



	//numatytasis konstruktorius vector
	student() {
		id_surname = "no surname";
		id_name = "no name";
		vector<float>nd { 0 };
		exam = 0;
		mean = 0;
		median = 0;
		grade = 0;
	}
	// konstruktorius su  parametrais
	student(string new_id_name, string new_id_surname, vector<float>new_nd, float new_exam) {
		id_name = new_id_name;
		id_surname = new_id_surname;
		nd = new_nd;
		exam = new_exam;
	}
	
	// kopijavimo konstruktorius
	student(const student 	&original) {
		id_name = original.id_name;
		id_surname = original.id_surname;
		nd = original.nd;
		exam = original.exam;
	}

	
	
	float setDataMean(string, string, vector<float>, float);
	float setDataMedian(vector<float>, float);
	float setDataGrade(float, float);
	
	float mainMenu1();
	//int mainMenu2();
	//int mainMenu3();
	//int mainMenu4();

	//void vecFunc(vector<float>, float);

	void printMean();
	void printMedian();
	void printAllm();

	//cin / cout - perdengimas
	

	friend istream& operator>>(istream& input, student& set_data) {	
		int rez = 0;
		char n;
		int count = 0;
		cout << "\tIveskite studento varda: ";
		input >> set_data.id_name;
		cout << "\tIveskite studento pavarde: ";
		input >> set_data.id_surname;
		cout << "\t\tIveskite namu darbu rezultatus:\n"<<endl;  
		for (;;){
			count++;
			cout << "\t\t\t" << count << ". Namu darbo ivertinimas : ";
			set_data.nd.push_back(rez);
			input >> rez;
			cout << "\t\t\t Test ivedima (y/n): ";
			cin >> n;
			if (n != 'y') {
				break;
			}
			}
		cout << "\n\t\tIveskite ekzamino rezultata:\t";
		input >> set_data.exam;
			return input;
		}
	
	 friend ostream& operator<<(ostream& output, const student& set_data) {
		 output << "-------------------------------------------------------------------------------------------------" << endl;
		 output << "|\tVardas" << setw(20) << "|\tPavarde" << setw(20) << "|\tVidurkis" << setw(20) << "|\tMedianas\t|" << endl;
		 output << "-------------------------------------------------------------------------------------------------" << endl;
		 output << set_data.id_name << setw(20) << set_data.id_surname << setw(20) << set_data.mean << setw(20) << set_data.median << endl;
		 return output;
	 }
	 ~student() {};
};


int main() {
	
	vector<student> list;
	vector<float> nd;
	
	student getObject;
	int menuIndex = 0;
	char n;
	menuIndex = getObject.mainMenu1();
	/*startMenu = menuOption.mainMenu2();
	startMenu = menuOption.mainMenu3();
	startMenu = menuOption.mainMenu4();*/
	
	switch (menuIndex) {
	case 1:
		for (;;) {
			cout << "\nIvedimas bus atliekamas rankiniu budu: " << endl;
			cin >> getObject;
			system("CLS");
			list.push_back(getObject);
			cout << "\nDuomenys ivesti, pratest duomenu suvedima (y/n): ";
			cin >> n;
			if (n != 'y') {
				break;
			}
			nd.clear();
		}
		system("CLS");
		cout << " ----------------------------------------------------------------" << endl;
		cout << "|                                                                |" << endl;
		cout << "|   Pasirinkimu sarasas duomenu ivesties / isvesties variantams  |" << endl;
		cout << "|                                                                |" << endl;
		cout << " ----------------------------------------------------------------" << endl;
		cout << "| a. Pateikti galutini iverti vadovaujantis vidurkiu;            |" << endl;
		cout << "| b. Pateikti galutini iverti vadovaujantis medianu;             |" << endl;
		cout << " ----------------------------------------------------------------" << endl;
		system("CLS");
		for (int i = 0; i < list.size(); i++) {
			list[i].printAllm();
			list[i].printMedian();
			list[i].printMean();
		};
		
	
		//cin >> n;
		//while (n == 'a' || n == 'b') {
		//	cout << " Tokio pasirinkimo nera, iveskit pasirinkima: ";
		//	cin >> n;
		//}
	
		break;
	case 2:
		cout << "Impuptojama is failo duomenu failo:";

		break;
	case 3:
		cout << "Atsitiktiniu pazymiu generavimas";
	case 4:
		break;
		cout << "Vadovaujantis medianu";
	case 5:

		cout << "Vadovaujantis medianu";
		break;
	case 6:
		cout << "Vadovaujantis medianu";
		break;
		cout << " ----------------------------------------------------------------" << endl;
		cout << "|                                                                |" << endl;
		cout << "|   Pasirinkimu sarasas duomenu ivesties / isvesties variantams  |" << endl;
		cout << "|                                                                |" << endl;
		cout << " ----------------------------------------------------------------" << endl;
		cout << "| 7. Duomenu sarasu isvedimas i ekrana;                          |" << endl;
		cout << "| 8. Duomenu sarasu isaugojimas faile;                           |" << endl;
		cout << " ----------------------------------------------------------------" << endl;
	case 7:
		cout << "Duomenu isvedimas i ekrana";
		break;
	case 8:
		cout << "Duomenu isaugojimas faile";
		break;
	}
	


	system("pause");
};

	float student::mainMenu1() {
		int menuIndex = 0;
		cout << " ----------------------------------------------------------------" << endl;
		cout << "|                                                                |" << endl;
		cout << "|   Pasirinkimu sarasas duomenu ivesties / isvesties variantams  |" << endl;
		cout << "|                                                                |" << endl;
		cout << " ----------------------------------------------------------------" << endl;
		cout << "| 1. Studento rezultatai bus ivedami rankiniu budu;              |" << endl;
		cout << "| 2. Importuojami is duomenu failo;                              |" << endl;
		cout << "| 3. Generuojami is atsitiktiu skaiciu;                          |" << endl;
		cout << "| 4. Nutraukti darba.                                            |" << endl;
		cout << " ----------------------------------------------------------------" << endl;
		cout << "\n\tIveskite pasirinkimo numeri: ";
		cin >> menuIndex;
		while (menuIndex > 4 || menuIndex < 1) {
			cout << "\tTokio pasirinkimo nera iveskite tinkama numeri: ";
			cin >> menuIndex;
		};
		system("CLS");
		return menuIndex;

		}

	

	float student::setDataMean(string new_name, string new_idname, vector<float> new_nd, float new_exam) {

		nd = new_nd;
		exam = new_exam;
		float mean = 0;
		int sum = 0;

		while (!nd.size())
		{
			sum = sum + nd.back();
		}
		mean = sum / nd.size() * 1.0;

		return mean;

	}


	float student::setDataMedian( vector<float> new_nd, float new_exam) {

		nd = new_nd;
		exam = new_exam;
		float median = 0;

		int size = nd.size();

		sort(nd.begin(), nd.end());

		if (size % 2 != 0) {
			median = nd.at(size / 2);
		}
		median = (nd.at(size - 1 )/ 2 + nd.at(size / 2)) / 2.0;

		return median;

	}

	float student::setDataGrade(float new_mean, float nwe_exam) {
		float grade;
		grade = ((mean * 0.4) + (exam * 0.6));
		return grade;

	}


	
	

	void student::printMean() {
		
		cout << id_surname << setw(17) << "" << id_name << setw(17) << mean << endl;

	}
	void student::printMedian() {

		cout << id_surname << setw(17) << "" << id_name << setw(17) <<"" << setw(17) << median << endl;

	}
	void student::printAllm() {
		cout << id_surname << setw(17) << "" << id_name << setw(17) << exam << setw(17) << grade << endl;

	}


