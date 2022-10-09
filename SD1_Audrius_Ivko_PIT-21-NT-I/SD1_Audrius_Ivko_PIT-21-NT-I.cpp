#include <iostream>
#include <cmath>
#include <string>



using namespace std;

//-----------------------------------------------------------------------------

// Class prototype

class student {
private:
    string id_name;
    string id_surname;
    int nd1;
    int nd2;
    int nd3;
    int exam;
    bool nd_passed();
public:
    void set(string, string, int, int, int, int);
    void print();
    int final_grade();
};

// All methods are implemented below the main function

//-----------------------------------------------------------------------------

int main() {
    student stud;

    stud.set("Audrius", "Ivko", 4, 9, 7, 8);
    stud.print();
}

//-----------------------------------------------------------------------------

// Implemetations of methods of class student

void student::set(string p1, string p2, int p3, int p4, int p5, int p6) {
    id_name = p1;
    id_surname = p2;

    if (p3 >= 0 && p3 <= 10) {
        nd1 = p3;
    }
    else {
        nd1 = 0;
        cout << "nd1 grade is incorrect!" << endl;

    }
    if (p4 >= 0 && p4 <= 10) {
        nd2 = p4;
    }
    else {
        nd2 = 0;
        cout << "nd2 grade is incorrect!" << endl;

    }
    if (p5 >= 0 && p5 <= 10) {
        nd3 = p5;
    }
    else {
        nd3 = 0;
        cout << "nd3 grade is incorrect!" << endl;

    }
    if (p6 >= 0 && p6 <= 10) {
        exam = p6;
    }
    else {
        exam = 0;
        cout << "Exam grade is incorrect!" << endl;

    }
}
void student::print() {
    cout << id_name << "\t| " << id_surname << "\t|";

    if (nd1 == 0) cout << "N/A" << "\t| ";
    else cout << nd1 << "\t| ";

    if (nd2 == 0) cout << "N/A" << "\t| ";
    else cout << nd2 << "\t| ";

    if (nd3 == 0) cout << "N/A" << "\t| ";
    else cout << nd3 << "\t| ";

    if (exam == 0) cout << "N/A" << "\t| ";
    else cout << exam << "\t| ";

    int fg = final_grade();
    if (fg == 0) cout << "N/A";
    else cout << fg;

    cout << endl;
}

bool student::nd_passed() {
    int k = 0;
    if (nd1 > 4) k++;
    if (nd2 > 4) k++;
    if (nd3 > 4) k++;

    if (k >= 2) return 1;
    else return 0;
}

int student::final_grade() {
    if ((nd_passed() == 1) && (exam > 4)) {
        return round((nd1 + nd2 + nd3) / 3.0 * 0.4 + exam * 0.6);
    }
    else {
        cout << "Final grade cannot be formed!" << endl;
        return 0;
    }
}



