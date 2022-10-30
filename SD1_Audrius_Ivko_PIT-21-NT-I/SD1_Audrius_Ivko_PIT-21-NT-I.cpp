#pragma once
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <vector>
#include <fstream>

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
	// konstruktorius su  parametrais
	student(string new_id_name, string new_id_surname, vector<double>new_nd, double new_exam) {
		id_name = new_id_name;
		id_surname = new_id_surname;
		vector<double>nd = { new_nd };
		exam = new_exam;
	}
	//void startMenu(vector<student>insert);

	void setDataGrade(string, string, vector<int>, double);
	void setDataMean(string, string, vector<int>, double);
	void setDataMedian(string, string, vector<int>, double);

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
		char ch = '?'; 	
		double ndv=0;
		cout << "Studento rezultatai bus ivedami rankiniu budu spauskit (y/n): ";
		cin >> ch;
		cout << "\nGeneruojami atsitiktine tvarka skauskit (y/n): "<<endl;
		cin >> ch;
		cout << "\nPateikimas galutinis pazimio skaiciavimas pagal vidurki spauskite (y/n): " << endl;
		cin >> ch;
		cout << "\nPateikimas galutinis pazimio skaiciavimas pagal mediana spauskite 4" << endl;
		cout << "\nPateikimas galutinis pazimio skaiciavimas pagal vidurki ir mediana spauskite 5" <<endl;
	
		cout << "\nIveskite studento varda:";
				input >> set_data.id_name;
				cout << "\nIveskite studento pavarde: ";
				input >> set_data.id_surname;
				cout << "\nEgzaminno rezultatas:";
				input >> set_data.exam;
				cout << "\nIvedinekite namu darbu pazymius,\n baigt ivedima iveskit neigiama reiksme";
				for(int i=0;ndv<0;i++ ){
					cin >> ndv;
					vector<double>nd;
					
					set_data.nd.push_back(ndv);
				};
		
			return input;
		};
	 ~student() {};
};

int main() {


	


	student data1, data2, data3; 
	data1.setDataAll("Vardas1", "Pavarde1", { 6,7,8,9 }, 8);
	data2.setDataMean("Vardas2", "Pavarde2", { 6,7,8,9 }, 8);
	data3.setDataMedian("Vardas3", "Pavarde4", { 6,7,8,9 }, 8);
	

	vector<student> list;
	vector<double> temprez  { 6,7,8,9,5,7,6,9 };
	student temp("Petras", "Petraitis",temprez,6 );
	list.push_back(temp);
	for (double i = 0; i < list.size(); i++) {
		cin >> list[i];
		cout << list[i];
	}

	
	

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


	void student::printMean() {
		cout << id_surname << setw(17) << "" << id_name << setw(17) << mean << endl;

	}
	void student::printMedian() {

		cout << id_surname << setw(17) << "" << id_name << setw(17) << median << endl;

	}
	void student::printAllm() {
		cout << id_surname << setw(17) << "" << id_name << setw(17) << mean << setw(17) << exam << endl;

	}
