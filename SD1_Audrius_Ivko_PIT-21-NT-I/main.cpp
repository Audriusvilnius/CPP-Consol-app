#include "Header.h"


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
	
	
	double setDataMean(vector<int>, double);
	double setDataMedian(vector<int>, double);
	double setDataGrade(double, double);
	//void startMenu(vector<int>insert);

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
		int menuIndex = 0;

		cout << "\n\tIveskite pasirinktimo numeri: ";
		cin >> menuIndex;
			while (menuIndex > 4 || menuIndex < 1) {
				cout << "\tTokio pasirinkimo nera iveskite tinkama numeri: ";
				cin >> menuIndex;
			};
		system("CLS");
		switch (menuIndex) {
		case 1:
			cout << "\n\tIvedimas bus atliekamas rankiniu budu: " << endl;
			cout << "\n\tIveskite studento varda:\t";
			input >> set_data.id_name;
			cout << "\n\tIveskite studento pavarde:\t";
			input >> set_data.id_surname;
			cout << "\n\tIveskite egzamino rezultata:\t";
			input >> set_data.exam;
			cout << "\n\tIveskite namu darbu rezultata:\t";

			break;
		case 2:
			cout << "Impuptojama is failo";
			break;
		case 3:
			cout << "Atsitiktiniu pazymiu generavimas";
		case 4:
			cout << "Nutraukti";
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
			cout << " ----------------------------------------------------------------"<< endl;
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

		/*cout << "\nIveskite studento varda:";
				input >> set_data.id_name;
				cout << "\nIveskite studento pavarde: ";
				input >> set_data.id_surname;
				cout << "\nEgzaminno rezultatas:";
				input >> set_data.exam;
				cout << "\nIvedinekite namu darbu pazymius,\n baigt ivedima iveskit neigiama reiksme";
				for(int i=0;ndv<0;i++ ){
					cin >> ndv;
					vector<int>nd;
					
					set_data.nd.push_back(ndv);
				};*/
		
			return input;
		}
	 ~student() {};
};

int main() {

	vector<student>list;
	
	vector<double> temprez{ 6,7,8,9,5,7,6,9 };
	student temp("Petras", "Petraitis", temprez, 6);
	list.push_back(temp);
	for (double i = 0; i < list.size(); i++) {
		cin >> list[i];
		cout << list[i];
	}

	
};

	

	double student::setDataMean(vector<int>new_nd, double new_exam) {

		vector<int>nd = new_nd;
		exam = new_exam;
		double mean = 0;
		int sum = 0;

		while (!nd.size())
		{
			sum = sum + nd.back();
		}
		mean = sum / nd.size() * 1.0;

		return mean;

	}

	double student::setDataMedian( vector<int>new_nd, double new_exam) {

		vector<int>nd = new_nd;
		exam = new_exam;
		double median = 0;

		int size = nd.size();

		sort(nd.begin(), nd.end());

		if (size % 2 != 0) {
			median = nd.at(size / 2);
		}
		median = (nd.at(size - 1 )/ 2 + nd.at(size / 2)) / 2.0;

		return median;

	}

	double student::setDataGrade(double median, double exam) {
		
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
