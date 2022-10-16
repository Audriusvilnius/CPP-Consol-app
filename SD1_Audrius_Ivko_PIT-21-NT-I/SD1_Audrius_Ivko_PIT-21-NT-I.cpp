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
using   std::ifstream;
using   std::ofstream;

using namespace std;



class student {
private:
    string id_name;
    string id_surname;
    double nd1;
    double nd2;
    double nd3;
    double exam;
    bool nd_passed();
public:
    
    student(): id_surname("no surname"), id_name("no name"), nd1(0), nd2(0), nd3(0), exam(0) {}//numatytasis konstruktorius

    void set_data(string, string, double, double, double, double);
    void print();
    double final_grade();
      
};

  
int main() {
    int input_type = 0;
    string id_name, id_surname;
    double nd1, nd2, nd3, exam;
    student stud, stud1, sutudinput;

    cout << "Duomenys ivedimas bus atliekamas is domenu failo spauskit 1, duomenis ivedami is klaviaturos spauskite 2: "; cin >> input_type;
    

    if (input_type == 1) {
cout << "Pavarde" << setw(7) << "Vardas" << setw(7) << "Galotini (Vid.)" << endl;
        stud.set_data("Pavardenis ", "Vaderins", 9.8, 10, 7, 8);
        stud1.set_data("Pavardenis ", "Vaderins", 7, 8, 9, 10);
        stud.print();
        stud1.print();
    }
    if (input_type == 2) {
        
        cout << "Iveskite studento varda: "; cin >> id_name;
        cout << "Iveskite studento pavarde: "; cin >> id_surname;
        cout << "Iveskite atsiskatymo ND1 ivertinima: "; cin >> nd1;
        cout << "Iveskite atsiskatymo ND2 ivertinima: "; cin >> nd2;
        cout << "Iveskite atsiskatymo ND3 ivertinima: "; cin >> nd3;
        cout << "Iveskite ekzamino ivertinima: "; cin >> exam;
cout << "Pavarde" << setw(7) << "Vardas" << setw(7) << "Galotini (Vid.)" << endl;
        sutudinput.set_data(id_surname, id_name, nd1, nd2, nd3, exam);
        sutudinput.print();
        //cin.get();
    }
 
 };
    
     
void student::set_data(string p1, string p2, double p3, double p4, double p5, double p6) {
    id_name = p2;
    id_surname = p1;

    if (p3 >= 0 && p3 <= 10) {
        nd1 = p3;
    }
    else {
        nd1 = 0;
        cout << "ND1 neteisingas ivertis!" << endl;

    }
    if (p4 >= 0 && p4 <= 10) {
        nd2 = p4;
    }
    else {
        nd2 = 0;
        cout << "ND2 neteisingas ivertis!" << endl;

    }
    if (p5 >= 0 && p5 <= 10) {
        nd3 = p5;
    }
    else {
        nd3 = 0;
        cout << "ND3 neteisingas ivertis!" << endl;

    }
    if (p6 >= 0 && p6 <= 10) {
        exam = p6;
    }
    else {
        exam = 0;
        cout << "Egzamino ivertis neteisingas!" << endl;

    }
}
void student::print() {
   
    cout << id_surname  << "\t| " << id_name << "\t|";

    if (nd1 == 0) cout << "N/A" << "\t| ";
    else cout << fixed << setprecision(2) << nd1 << "\t| ";

    if (nd2 == 0) cout << "N/A" << "\t| ";
    else cout << nd2 << "\t| ";

    if (nd3 == 0) cout << "N/A" << "\t| ";
    else cout << nd3 << "\t| ";

    if (exam == 0) cout << "N/A" << "\t| ";
    else cout << exam << "\t| ";

    double fg = final_grade();
    if (fg == 0) cout << "N/A";
    else cout << fg;

    cout << endl;
}

bool student::nd_passed() {
    int k = 0;
    if (nd1 > 4) k++;
    if (nd2 > 4) k++;
    if (nd3 > 4) k++;
    if (k == 3) return 1;
    else return 0;
}

double student::final_grade() {
    if ((nd_passed() ) && (exam > 4)) {
        return ((nd1 + nd2 + nd3) / 3.0 * 0.4 + exam * 0.6);
    }
    else {
        cout << "Galutinis rezultatas nefirmuojamas" << endl;
        return 0;
    }
}



