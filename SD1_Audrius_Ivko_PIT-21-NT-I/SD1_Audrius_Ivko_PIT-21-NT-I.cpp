#pragma once
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <stdlib.h>

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
using	std::istream



class student {
private:
	string id_name;
	string id_surname;
	vector<int>nd;
	double exam;
public:
	double mean;
	double median;

	//numatytasis konstruktorius vector
	student() {
		id_surname = "no surname";
		id_name = "no name";
		vector<int>nd = { 0 };
		exam = 0;
		mean = 0;
		median = 0;
	}

	// konstruktorius su  parametrais vektorio nuskaitymui
	student(string new_id_name, string new_id_surname, vector<int>new_nd, double new_exam) {
		id_name = new_id_name;
		id_surname = new_id_surname;
		vector<int>nd = { new_nd };
		exam = new_exam;
	}
	void startMenu(vector<student>insert);

	void setDataGrade(string, string, vector<int>, double);
	void setDataMean(string, string, vector<int>, double);
	void setDataMedian(string, string, vector<int>, double);
	
	void printMean();
	void printMedian();
	void printAllm();

	//cin / cout - perdengimas
	friend istream& operator>>(istream &input, student &set_data) {
		
				int index = 0;
				input >> ndv;
					while (ndv > -1) {
						vector<int>nd;
						input >> ndv;
						nd.push_back(ndv);
					};
	
			return input;
		}

	friend ostream& operator<<(ostream& output, const student& setMeanMedian) {
		output << "-------------------------------------------------------------------------------------------------" << endl;
		output << "|\tVardas" << setw(20) << "|\tPavarde" << setw(20) << "|\tVidurkis" << setw(20) << "|\tMedianas\t|" << endl;
		output << "-------------------------------------------------------------------------------------------------" << endl;
		output << setMeanMedian.id_name << setw(20) << setMeanMedian.id_surname << setw(20) << setMeanMedian.mean << setw(20) << setMeanMedian.median << endl;
		return output;
	}

	 ~student() {};
};

int main() {
	vector<student>insert;
	startMenu(insert);
	system("pause");



	//vector<student> list;
	//vector<int> nd  { 6,7,8,9,5,7,6,9 };
	//student temp( "Petras", "Petraitis", nd, 6);
	//list.push_back(temp);
	
	return 0;
};

	void student::setDataGrade(string new_id_name, string new_id_surname, vector<int>new_nd, double new_exam) {

		id_name = new_id_name;
		id_surname = new_id_surname;
		vector<int>nd = new_nd;
		exam = new_exam;
		double mean = 0;
		int sum = 0;

		mean = sum / nd.size() * 1.0;

		//return ((mean * 0.4) + (exam * 0.6));
	}
		
	void student::setDataMean(string new_id_name, string new_id_surname, vector<int>new_nd, double new_exam) {

		id_name = new_id_name;
		id_surname = new_id_surname;
		vector<int>nd = new_nd;
		exam = new_exam;
		double mean = 0;
		int sum = 0;

		while (!nd.size())
		{
			sum = sum + nd.back();
		}
		mean = sum / nd.size() * 1.0;

		//return mean;

	}

	void student::setDataMedian(string new_id_name, string new_id_surname, vector<int>new_nd, double new_exam) {

		id_name = new_id_name;
		id_surname = new_id_surname;
		vector<int>nd = new_nd;
		exam = new_exam;
		double median = 0;

		int size = nd.size();

		sort(nd.begin(), nd.end());

		if (size % 2 != 0) {
			median = nd.at(size / 2);
		}
		median = (nd.at(size - 1) / 2 + nd.at(size / 2)) / 2.0;

		//return median;

	}

	void student::startMenu(vector<student>insert) {

			cout << " ----------------------------------------------------------------"; << endl;
			cout << "|                                                                |"; << endl;
			cout << "|   Pasirinkimu sarasas duomenu ivesties / isvesties variantams  |"; << endl;
			cout << "|                                                                |"; << endl;
			cout << " ----------------------------------------------------------------"; << endl;
			cout << "| 1. Studento rezultatai bus ivedami rankiniu budu;              |"; << endl;
			cout << "| 2. Importuojami is duomenu failo;                              |"; << endl;
			cout << "| 3. Generuojami is atsitiktiu skaiciu;                          |"; << endl;
			cout << "| 4. Nutraukti darba.                                            |"; << endl;
			cout << " ----------------------------------------------------------------"; << endl;
		
		int menuIndex = 0;
		switch (menuIndex) {
		case 1:
			cout << "Ivedimas rankiniu budu";
			break;
		case 2:
			cout << "Impuptojama is failo";
			break;
		case 3:
			cout << "Atsitiktiniu pazymiu generavimas"; 
		case 4:
			cout << "Nutraukti";
			break;	
			cout << " ----------------------------------------------------------------"; << endl;
			cout << "|                                                                |"; << endl;
			cout << "|   Pasirinkimu sarasas duomenu ivesties / isvesties variantams  |"; << endl;
			cout << "|                                                                |"; << endl;
			cout << " ----------------------------------------------------------------"; << endl;
			cout << "| 5. Pateikti galutini iverti vadovaujantis vidurkiu;            |"; << endl;
			cout << "| 6. Pateikti galutini iverti vadovaujantis medianu;             |"; << endl;
			cout << " ----------------------------------------------------------------"; << endl;
		case 5:
			cout << "Vadovaujantis vidurkiu";
			break;
		case 6:
			cout << "Vadovaujantis medianu";
			break;
			cout << " ----------------------------------------------------------------"; << endl;
			cout << "|                                                                |"; << endl;
			cout << "|   Pasirinkimu sarasas duomenu ivesties / isvesties variantams  |"; << endl;
			cout << "|                                                                |"; << endl;
			cout << " ----------------------------------------------------------------"; << endl;
			cout << "| 7. Duomenu sarasu isvedimas i ekrana;                          |"; << endl;
			cout << "| 8. Duomenu sarasu isaugojimas faile;                           |"; << endl;
			cout << " ----------------------------------------------------------------"; << endl;
		case 7:
			cout << "Duomenu isvedimas i ekrana";
			break;
		case 8:
			cout << "Duomenu isaugojimas faile";
			break;
		}
		
	}

	void student::printMean() {
		cout << id_surname << setw(17) << "" << id_name << setw(17) << mean << endl;;

	}

	void student::printMedian() {

		cout << id_surname << setw(17) << "" << id_name << setw(17) << median << endl;

	}
	void student::printAllm() {
		cout << id_surname << setw(17) << "" << id_name << setw(17) << mean << setw(17) << exam << endl;

	}
