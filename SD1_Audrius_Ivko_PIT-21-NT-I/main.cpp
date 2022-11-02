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
	float mean;
	float median;


	//numatytasis konstruktorius vector
	student() {
		id_surname = "no surname";
		id_name = "no name";
		vector<float>nd { 0 };
		exam = 0;
		mean = 0;
		median = 0;
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
	
	
	float setDataMean(vector<float>, float);
	float setDataMedian(vector<float>, float);
	float setDataGrade(float, float);
	
	int mainMenu1();
	int mainMenu2();
	int mainMenu3();
	int mainMenu4();

	//void vecFunc(vector<float>, float);

	void printMean();
	void printMedian();
	void printAllm();

	//cin / cout - perdengimas
	friend ostream& operator<<(ostream& output, const student& set_data) {
		output << "-------------------------------------------------------------------------------------------------" << endl;
		output << "|\tVardas" << setw(20) << "|\tPavarde" << setw(20) << "|\tVidurkis" << setw(20) <<"|\tMedianas\t|" << endl;
		output << "-------------------------------------------------------------------------------------------------" << endl;
		output << set_data.id_name << setw(20) << set_data.id_surname << setw(20) <<set_data.mean << setw(20) << set_data.median << endl;
		return output;
	}

	friend istream& operator>>(istream& input, student& set_data) {	
		int temp = 0;
		char no = 'n';
		int count = 0;
		input >> set_data.id_name;
		cout << "\n\tIveskite studento pavarde: ";
		input >> set_data.id_surname;
		cout << "\n\tIveskite namu darbu rezultata:\t";
		cout << "\n\tNutraukt -9:\t";    
		while ( temp != -9)
		{
			count++;
			cout << "\n\tNamu darbu Nr:" << count << " ivertinimas: ";
			set_data.nd.push_back(temp);
			input >> temp;
		}
		cout << "\n\tIveskite ekzamino rezultata:\t";
		input >> set_data.exam;

			return input;
		}
	 ~student() {};
};
	//void svecFunc(vector<float>, float)
	//{

	//	nd.push_back(30);

	//}

int main() {
	
	
	vector<student> list;
	vector<int> nd;
	
	student getObject;
	int menuIndex = 0;
	menuIndex = getObject.mainMenu1();
	/*startMenu = menuOption.mainMenu2();
	startMenu = menuOption.mainMenu3();
	startMenu = menuOption.mainMenu4();*/
	
	switch (menuIndex) {
	case 1:
		cout << "\n\tIvedimas bus atliekamas rankiniu budu: " << endl;
		cout << "\n\tIveskite studento varda: ";
		cin >> getObject;
		system("CLS");
		cout << " ----------------------------------------------------------------" << endl;
		cout << "|                                                                |" << endl;
		cout << "|   Pasirinkimu sarasas duomenu ivesties / isvesties variantams  |" << endl;
		cout << "|                                                                |" << endl;
		cout << " ----------------------------------------------------------------" << endl;
		cout << "| a. Pateikti galutini iverti vadovaujantis vidurkiu;            |" << endl;
		cout << "| b. Pateikti galutini iverti vadovaujantis medianu;             |" << endl;
		cout << " ----------------------------------------------------------------" << endl;
		char subMenu1;
		cin >> subMenu1;
		break;
	case 2:
		cout << "Impuptojama is failo duomenu failo:";

		break;
	case 3:
		cout << "Atsitiktiniu pazymiu generavimas";
	case 4:
		break;
		cout << " ----------------------------------------------------------------" << endl;
		cout << "|                                                                |" << endl;
		cout << "|   Pasirinkimu sarasas duomenu ivesties / isvesties variantams  |" << endl;
		cout << "|                                                                |" << endl;
		cout << " ----------------------------------------------------------------" << endl;
		cout << "| 5. Pateikti galutini iverti vadovaujantis vidurkiu;            |" << endl;
		cout << "| 6. Pateikti galutini iverti vadovaujantis medianu;             |" << endl;
		cout << " ----------------------------------------------------------------" << endl;
	case 5:

		cout << "Vadovaujantis vidurkiu";
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

	int student::mainMenu1() {
		int menuIndex = 0;
		cout << "\t ----------------------------------------------------------------" << endl;
		cout << "\t|                                                                |" << endl;
		cout << "\t|   Pasirinkimu sarasas duomenu ivesties / isvesties variantams  |" << endl;
		cout << "\t|                                                                |" << endl;
		cout << "\t ----------------------------------------------------------------" << endl;
		cout << "\t| 1. Studento rezultatai bus ivedami rankiniu budu;              |" << endl;
		cout << "\t| 2. Importuojami is duomenu failo;                              |" << endl;
		cout << "\t| 3. Generuojami is atsitiktiu skaiciu;                          |" << endl;
		cout << "\t| 4. Nutraukti darba.                                            |" << endl;
		cout << "\t ----------------------------------------------------------------" << endl;
		cout << "\n\tIveskite pasirinkimo numeri: ";
		cin >> menuIndex;
		while (menuIndex > 4 || menuIndex < 1) {
			cout << "\tTokio pasirinkimo nera iveskite tinkama numeri: ";
			cin >> menuIndex;
		};
		system("CLS");
		return menuIndex;

		}

	

	float student::setDataMean(vector<float> new_nd, float new_exam) {

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

	float student::setDataGrade(float median, float exam) {
		
		return ((mean * 0.4) + (exam * 0.6));

	}


	
	

	void student::printMean() {
		cout << id_surname << setw(17) << "" << id_name << setw(17) << mean << endl;

	}
	void student::printMedian() {

		cout << id_surname << setw(17) << "" << id_name << setw(17) << median << endl;

	}
	void student::printAllm() {
		cout << id_surname << setw(17) << "" << id_name << setw(17) << mean << setw(17) << exam << endl;

	}


