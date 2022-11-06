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
#include <string>
#include <random>
#include <chrono>
#include <time.h>


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
using	std::getline;
using	std::ifstream;

#include "Header.h"



class student {
private:
	string id_name;
	string id_surname;
	vector<float>nd;
	float exam;
	float mean;
	float median;
	float gradeMean;
	float gradeMedian;
public:

	//numatytasis konstruktorius vector
	student() {
		id_surname = "no surname";
		id_name = "no name";
		vector<float>nd{ 0 };
		exam = 0;
		mean = 0;
		median = 0;
		gradeMean = 0;
		gradeMedian = 0;
	}
	// konstruktorius su  parametrais
	student(string new_id_name, string new_id_surname, vector<float>new_nd, float new_exam, float new_gradeMean, float gradeMedian) {
		id_name = new_id_name;
		id_surname = new_id_surname;
		nd = new_nd;
		exam = new_exam;
	}

	// kopijavimo konstruktorius
	student(const student& original) {
		id_name = original.id_name;
		id_surname = original.id_surname;
		nd = original.nd;
		exam = original.exam;
		gradeMean = original.gradeMean;
		gradeMedian = original.gradeMedian;
	}

	void setDataMean();
	void setDataMedian();
	float setDataGradeMean(float, float);
	float setDataGradeMedian(float, float);

	void printMean();
	void printMedian();
	void printAllMean();
	void printAllMedian();

	//cin / cout - perdengimas
	friend istream& operator>>(istream& input, student& set_data) {
		int rez = 0;
		int option;
		int ndqty = 0;
		char n;
		int count = 0;
		cout << " ----------------------------------------------------------------" << endl;
		cout << "| 1. Duomenis bus ivedam rankiniu budu;                          |" << endl;
		cout << "| 2. Duomeis bus generuojami is atsitiktiu skaiciu.              |" << endl;
		cout << " ----------------------------------------------------------------" << endl;
		cout << "\nIveskite pasirinkimo numeri: ";
		cin >> option;
		for (;;) {
			if (option < 1 || option > 3) {
				cout << "\nTokio pasirinkimo nera, patikslinkit pasirinkima: ";
				cin >> option;
			}
			else {
				break;
			}
		}
		if (option == 1) {
			cout << "Ivedimas bus atliekamas rankiniu budu: " << endl;
			cout << "\nIveskite studento varda: ";
			input >> set_data.id_name;
			cout << "Iveskite studento pavarde: ";
			input >> set_data.id_surname;
			cout << "Iveskite namu darbu rezultatus: \n" << endl;
			for (;;) {
				count++;
				cout << count << ". Namu darbo ivertinimas : ";
				input >> rez;
				set_data.nd.push_back(rez);
				cout << "\tTest ivedima (y/n): ";
				cin >> n;
				if (n != 'y') {
					break;
				}
			}
			cout << "\nIveskite ekzamino rezultata: ";
			input >> set_data.exam;
		}
		if (option == 2) {
			int exam = 0;
			srand(time(NULL));
			cout << "Ivedimas bus atliekamas is atsitiktiniu skaiciu nuo 0 iki 10: " << endl;
			cout << "\nIveskite studento varda: ";
			input >> set_data.id_name;
			cout << "Iveskite studento pavarde: ";
			input >> set_data.id_surname;
			cout << "\nNamu darbu ir egzamino rezultatu generavimas. ";
			cout << "\nIveskite namu darbu kieki: ";
			cin >> ndqty;
			for (int i = 0; i < ndqty; i++) {
				count++;
				cout <<"\n"<< count << "" << setw(3) << ". Namu darbo ivertinimas : ";
				rez = rand() % 11;
				cout << rez;
				set_data.nd.push_back(rez);
			}
			exam = rand() % 11;
			set_data.exam = exam;
			cout << "\nEkzamino rezultats: ";
			cout << exam << endl;
		}
		set_data.setDataMean();
		set_data.setDataMedian();
		set_data.setDataGradeMean(set_data.mean, set_data.exam);
		set_data.setDataGradeMedian(set_data.median, set_data.exam);
		//	/* Function test
		//	cout << set_data.gradeMean << "gradeMean"<<endl;
		//	cout << set_data.gradeMedian << "gradeMedian"<<endl;
		//	cout << set_data.median << endl;
		//	cout << set_data.mean << endl;*/

		return input;
	}

	friend ostream& operator<<(ostream& output, const student& set_data) {
		int otion = 0;
		output << " ----------------------------------------------------------------" << endl;
		output << "|                                                                |" << endl;
		output << "|   Pasirinkimu sarasas duomenu ivesties / isvesties variantams  |" << endl;
		output << "|                                                                |" << endl;
		output << " ----------------------------------------------------------------" << endl;
		output << "| 1. Pateikti namu darbu iverciu vidurki;                        |" << endl;
		output << "| 2. Pateikti namu darbu iverciu mediana;                        |" << endl;
		output << "| 3. Pateikti galutini iverti vadovaujantis vidurkiu;            |" << endl;
		output << "| 4. Pateikti galutini iverti vadovaujantis medianu;             |" << endl;
		output << "| 5. Pateikti galutini iverti vadovaujantis medianu;             |" << endl;
		output << " ----------------------------------------------------------------" << endl;
		output << "Pasirinkite varianta: ";
		cin >> otion;
		while (otion > 5 || otion < 1) {
			cout << "Tokio pasirinkimo nera iveskite tinkama numeri : ";
			cin >> otion;
		};
		system("CLS");
		output << "-----------------------------------------------------------------" << endl;
		output << "|" << setw(10)<<"Vardas" << setw(6) << "|" << setw(10)<< "Pavarde" << setw(6) << "|" << setw(10)<< "Vidurkis" << setw(6) << "|" << setw(10)<<"Medianas"<< setw(6)<<"|" << endl;
		output << "-----------------------------------------------------------------" << endl;
		if (otion == 1) {
			output << set_data.id_name << setw(10) << set_data.id_surname << setw(10) << set_data.median << endl;
		}
		if (otion == 2) {
			output << set_data.id_name << setw(20) << set_data.id_surname << setw(20) << "" << setw(20) << set_data.mean << endl;
		}
		if (otion == 3) {
			output << set_data.id_name << setw(20) << set_data.id_surname << setw(20) << set_data.gradeMean << setw(20) << set_data.gradeMedian << endl;
		}
		if (otion == 4) {
			output << set_data.id_name << setw(20) << set_data.id_surname << setw(20) << "" << setw(20) << set_data.gradeMedian << endl;
		}
		if (otion == 5) {
			output << set_data.id_name << setw(20) << set_data.id_surname << setw(20) << set_data.gradeMean << endl;
		}

		return output;
	}

	~student() {};
};

//int mainMenu1();

int main() {

	vector<student> list;
	vector<float> nd;

	//int row;
	//vector<std::string> lines;
	//ifstream infile("indata.txt");

	//std::string line;
	//while (std::getline(infile, line)) {
	//	lines.push_back(line);
	//	std::cout << lines.back() << std::endl;
	//	
	//}
	//sort(line.begin(), line.end());
	//row =  lines.size();
	//cout << "dydis" << row;
	//infile.close();

	int menuIndex = 0;
	char n;
	cout << " ----------------------------------------------------------------" << endl;
	cout << "|                                                                |" << endl;
	cout << "|   Pasirinkimu sarasas duomenu ivesties / isvesties variantams  |" << endl;
	cout << "|                                                                |" << endl;
	cout << " ----------------------------------------------------------------" << endl;
	cout << "| 1. Studento rezultatai bus ivedami rankiniu budu,              |" << endl;
	cout << "|    arba generuojami is atsitiktiniu skaiciu                    |" << endl;
	cout << "| 2. Impuptojama is duomenu failo:                               |" << endl;
	cout << "| 3. Nutraukti darba.                                            |" << endl;
	cout << " ----------------------------------------------------------------" << endl;
	cout << "Iveskite pasirinkimo numeri: ";
	cin >> menuIndex;
	while (menuIndex > 3 || menuIndex < 1) {
		cout << "Tokio pasirinkimo nera iveskite tinkama numeri : ";
		cin >> menuIndex;
	};
	system("CLS");

	//menuIndex = mainMenu1();
	//menuIndex = mainMenu2();
	/*startMenu = menuOption.mainMenu2();
	startMenu = menuOption.mainMenu3();
	startMenu = menuOption.mainMenu4();*/
	//student getObject;
	switch (menuIndex) {
	case 1:
		for (;;) {
			student getObject;
			cin >> getObject;
			cout << "\nDuomenys ivesti ir isaugoti.\nPratest duomenu suvedima (y/n): ";
			cin >> n;
			if (n != 'y') {
				list.push_back(getObject);
				cout << getObject;

			}
			else {
				list.push_back(getObject);
				cin >> getObject;
			}
			list.push_back(getObject);
			////		TEST INPUT DATA
			//getObject.printMedian();
			//getObject.printMean();
			//getObject.printAllMean();
			//getObject.printAllMedian();
			//system("CLS");
			getObject.~student();
		}
		system("CLS");
		/*cout << " ----------------------------------------------------------------" << endl;
		cout << "|                                                                |" << endl;
		cout << "|   Pasirinkimu sarasas duomenu ivesties / isvesties variantams  |" << endl;
		cout << "|                                                                |" << endl;
		cout << " ----------------------------------------------------------------" << endl;
		cout << "| a. Pateikti namu darbu iverciu vidurki;                        |" << endl;
		cout << "| b. Pateikti namu darbu iverciu mediana;                        |" << endl;
		cout << "| c. Pateikti galutini iverti vadovaujantis vidurkiu;            |" << endl;
		cout << "| d. Pateikti galutini iverti vadovaujantis medianu;             |" << endl;
		cout << " ----------------------------------------------------------------" << endl;
		cout << "Pasirinkite varianta: ";
		cin >> n;
		for (;;) {
			if (n == 'a' || n == 'b' || n == 'c' || n == 'd') {
				break;
			}
			cout << "Tokio pasirinkimo nera.\n Iveskite isnaujo: ";
			cin >> n;
		}*/
		//system("CLS");
		//if (n == 'a') {
		//	for (auto& a : list)
		//	{
		//		a.printMedian();
		//	};
		//}
		//if (n == 'a') {
		//	for (auto& a : list)
		//	{
		//		a.printMean();
		//	};
		//}
		//if (n == 'a') {
		//	for (auto& a : list)
		//	{
		//		a.printAllMean();
		//	};
		//}
		//if (n == 'a') {
		//	for (auto& a : list)
		//	{
		//		a.printAllMedian();
		//	};
		//}
		//

	case 2:
		cout << "Impuptojama is failo duomenu failo:";
		break;
	case 3:return 0;

	}
	system("pause");
};

//int mainMenu1() {
//	int menuIndex = 0;
//	cout << " ----------------------------------------------------------------" << endl;
//	cout << "|                                                                |" << endl;
//	cout << "|   Pasirinkimu sarasas duomenu ivesties / isvesties variantams  |" << endl;
//	cout << "|                                                                |" << endl;
//	cout << " ----------------------------------------------------------------" << endl;
//	cout << "| 1. Studento rezultatai bus ivedami rankiniu budu,              |" << endl;
//	cout << "|    arba generuojami is atsitiktiniu skaiciu                    |" << endl;
//	cout << "| 2. Impuptojama is duomenu failo:                               |" << endl;
//	cout << "| 3. Nutraukti darba.                                            |" << endl;
//	cout << " ----------------------------------------------------------------" << endl;
//	cout << "Iveskite pasirinkimo numeri: ";
//	cin >> menuIndex;
//	while (menuIndex > 4 || menuIndex < 1) {
//		cout << "Tokio pasirinkimo nera iveskite tinkama numeri : ";
//		cin >> menuIndex;
//	};
//	system("CLS");
//	return menuIndex;
//
//}

void student::setDataMean() {
	mean = 0;
	float sum = 0;

	for (auto& a : nd)
	{
		sum = sum + a;
	}
	mean = sum / nd.size();
}

void student::setDataMedian() {

	median = 0;

	int size = nd.size();

	sort(nd.begin(), nd.end());

	if (size % 2 != 0) {
		median = nd.at(size / 2);
	}
	else {
		median = (nd.at(size / 2 - 1) + nd.at(size / 2)) / 2;
	}

}

float student::setDataGradeMean(float new_mean, float new_exam) {

	gradeMean = ((mean * 0.4) + (exam * 0.6));
	/* //		Test output data
	cout << "test mean " << gradeMean << endl;
	*/
	return gradeMean;

}
float student::setDataGradeMedian(float new_median, float new_exam) {

	gradeMedian = ((median * 0.4) + (exam * 0.6));
	/* //		Test output data
	cout << "test Median " << gradeMedian << endl;
	*/
	return gradeMedian;

}

void student::printMean() {
	setDataMean();

	cout << left << id_surname << setw(15) << left << id_name << setw(15) << mean << endl;
	//string eilute = id_surname + " " + id_name + " " + std::to_string (mean) + "\n";
	//return eilute;
}

void student::printMedian() {
	setDataMedian();

	cout << left << id_surname << setw(15) << left << id_name << setw(15) << "" << setw(18) << median << endl;
}

void student::printAllMean() {
	//setDataMean();

	cout << left << id_surname << left << setw(15) << id_name << setw(15) << gradeMean << setw(15) << endl;
}
void student::printAllMedian() {
	//setDataMedian();

	cout << left << id_surname << left << setw(15) << left << id_name << setw(15) << "" << setw(15) << gradeMedian << endl;
}


