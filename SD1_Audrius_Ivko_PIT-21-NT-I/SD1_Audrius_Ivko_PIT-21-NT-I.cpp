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



using namespace std;



class student {
private:
	string id_name;
	string id_surname;
	vector<double>paz;
	double nd1;
	double nd2;
	double nd3;
	double exam;
	bool nd_passed();
public:
	//numatytasis konstruktorius
	student() : id_surname("no surname"), id_name("no name"), paz(0), exam(0) {}
	
	// konstruktorius su  parametrais

	student(string new_id_name, string new_id_surname, vector<double>new_nd, double new_exam) :id_name(new_id_name), id_surname(new_id_surname), paz(new_nd), exam(new_exam) {}

	void set_data(string, string, vector<double>, double);
	void print();
	double final_grade();


	friend class multiply;

	//cin / cout - perdengimas
	friend ostream& operator<<(ostream& output, const student& set_data) {
		output << set_data.id_name<< set_data.id_surname << set_data.nd1 << set_data.nd2 << set_data.nd3 << set_data.exam;
		return output;
	}

	friend istream& operator>>(istream& input, student& set_data) {
		char ch = '?';
		cout << "Studento rezultatai bus ivedami rankiniu budu soauskit 1.\n Generuojami atsitiktine tvarka skauskit 2: ";
	
		cout << "Iveskite studento varda:";
				input >> set_data.id_name;
		
			return input;


		};

		
		//input >> set_data.id_name >> set_data.id_surname >> set_data.nd1 >> set_data.nd2 >> set_data.nd3 >> set_data.exam;
		

	



	// ~student() {};
};

class multiply {
public:
	static student  student_is(student f1, student f2, student f3, student f4, student f5, student f6) {
		student r1, r2, r3, r4, r5, r6;
		r1.id_name = f1.id_name;
		r2.id_surname = f2.id_surname;
		r3.nd1 = f3.nd1;
		r4.nd2 = f4.nd2;
		r5.nd3 = f5.nd3;
		r6.exam = f6.exam;


	}

};



int main() {

	

	




	char ch = '?';
	int option;
	int in_mean = 0;
	int in_median = 0;
	cout << "Studento rezultatai bus ivedami rankiniu budu (y/n): ";
	cin >> ch;
	if (ch == 'y') {


	};

	cout << "\nRezultatu pateikimo pasirinkimas:" << endl;
	cout << "\n\t1. Pagal vidurki;" << endl;
	cout << "\t2. Pagal mediana;" << endl;
	cout << "\t3. Pagal madiana ir vidurki;" << endl;
	cout << "\t4. Nutraukt darba spauskite ""n""." << endl;
	cout << "\nIveskite pasirinkimo reiksme:";
	cin >> option;
	if (ch == 'n') {
		return 0;
	};
	if (option == 1) {


	};
	if (option == 2) {
		cin >> option;

		student median;
		median.print();

	};
	if (option == 3) {
		cin >> option;
	};
	if (option < 1 || option > 3 && ch != 'n') {
		cout << "\n\tTokio pasirinkimo nera!!!\n\nIveskite is naujo pasirinkima:\n";
	};



	return 0;
};

void student::set_data(string p1, string p2, vector<double>p3, double p4) {
	id_name = p1;
	id_surname = p2;
	vector<double>paz; paz.size();


}
