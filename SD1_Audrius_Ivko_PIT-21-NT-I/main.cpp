#include "Header.h"
#include "student.h"
#include "global.h"

int option = 0;

int main()
{
	int rez = 0;
	int ndqty;
	int stqty;
	int count = 0;
	int mIndex = 1;
	float exTemp = -1;
	char n = 'z';
	string s;
	string temp;
	string id_naTemp;
	string id_suTemp;
	int temp_nd;
	vector<student> list;
	vector<float> nd;
	srand(time(NULL));

	cout << "--------------------------------------------------------------------------" << endl;
	cout << "|                                                                         |" << endl;
	cout << "|                  Studentu pazymiu apdorojimo programa                   |" << endl;
	cout << "|                                                                         |" << endl;
	cout << "--------------------------------------------------------------------------" << endl;
	while (mIndex != 0)
	{
		cout << "--------------------------------------------------------------------------" << endl;
		cout << "|               Ivest naujus duomenis / Papildyt esamus                   |" << endl;
		cout << "--------------------------------------------------------------------------" << endl;
		cout << "| 1. Pridet student duomenis rankiniu budu;                               |" << endl;
		cout << "| 2. Pridet generuojant atsitiktinius pazymius namu darbu ir egzamono;    |" << endl;
		cout << "| 3. Pridet duomenis nuskaitytus is failo;                                |" << endl;
		cout << "| 4. Savestu duomenu rusiavimas pagal varda ir spausdinimas               |" << endl;
		cout << "| 5. Panaikinti suvestus duomenis                                         |" << endl;
		cout << "| 6. Atsitiktiniu pazymiu issaugijimas i faila                            |" << endl;
		cout << "| 0. Nutraukti darba.                                                     |" << endl;
		cout << "--------------------------------------------------------------------------" << endl;
		cout << "Iveskite pasirinkimo numeri: ";
		cin >> mIndex;

		while (mIndex > 5 || mIndex < 0)
		{
			cout << "Tokio pasirinkimo nera iveskite tinkama numeri : ";
			cin >> mIndex;
		};
		if (mIndex == 0)
		{
			return 0;
		}
		system("CLS");
		if (mIndex != 5)
		{
			cout << "--------------------------------------------------------------------------" << endl;
			cout << "|                                                                         |" << endl;
			cout << "|   Rezultato pateikimo pasirinkimas                                      |" << endl;
			cout << "|                                                                         |" << endl;
			cout << "--------------------------------------------------------------------------" << endl;
			cout << "| 1. Pateikti namu darbu iverciu vidurki;                                 |" << endl;
			cout << "| 2. Pateikti namu darbu iverciu mediana;                                 |" << endl;
			cout << "| 3. Pateikti galutini iverti vadovaujantis vidurkiu;                     |" << endl;
			cout << "| 4. Pateikti galutini iverti vadovaujantis medianu;                      |" << endl;
			cout << "| 5. Pateikti galutinius iverti vadovaujantis vidurkiu ir medianu;        |" << endl;
			cout << "| 0. Nutraukti darba.                                                     |" << endl;
			cout << "--------------------------------------------------------------------------" << endl;
			cout << "Pasirinkite varianta: ";
			cin >> option;
			while (option > 5 || option < 0)
			{
				cout << "Tokio pasirinkimo nera iveskite tinkama numeri : ";
				cin >> option;
			};
			if (mIndex == 0)
			{
				return 0;
			}
		}
		system("CLS");
		if (mIndex == 1)
		{
			count = 1;
			cout << "\nIveskite studento varda: ";
			cin >> id_naTemp;
			cout << "Iveskite studento pavarde: ";
			cin >> id_suTemp;
			while (n != 'n')
			{
				cout << "Iveskite namu darbo vertinima: ";
				cin >> rez;
				try
				{
					checknd(rez);
					nd.push_back(rez);
					cout << "Test ivedima(y / n) :";
					cin >> n;
				}
				catch (runtime_error& e)
				{
					cout << "\n\t\tDemesio !!!  " << e.what();
				}
			}
			n = 'z';
			while (exTemp > 10 || exTemp < 0)
			{
				cout << "\nIveskite ekzamino rezultata: ";
				cin >> exTemp;
				try
				{
					checkex(exTemp);
				}
				catch (runtime_error& e)
				{
					cout << "\n\t\tDemesio !!!  " << e.what();
				}
			}
			prtintrez();
			student getObj(id_naTemp, id_suTemp, nd, exTemp);
			cin >> getObj;
			nd.clear();
			list.push_back(getObj);
			cout << getObj;
			getObj.~student();
			exTemp = -1;
			system("pause");
			system("CLS");
		}
		if (mIndex == 2)
		{
			cout << "Ivedimas bus atliekamas is atsitiktiniu skaiciu nuo 0 iki 10: " << endl;
			cout << "\nIveskite studentu kieki: ";
			cin >> stqty;
			cout << "\nIveskite namu darbu kieki: ";
			cin >> ndqty;
			prtintrez();
			for (int i = 1; i < stqty + 1; i++) {
				string name = "Vardas";
				string surname = "Pavarde";
				name += to_string(i);
				surname += to_string(i);
				id_naTemp = name;
				id_suTemp = surname;
				for (int i = 0; i < ndqty; i++)
				{
					rez = rand() % 11;
					nd.push_back(rez);
				}
				exTemp = rand() % 11;
				student getObj(id_naTemp, id_suTemp, nd, exTemp);
				cin >> getObj;
				nd.clear();
				list.push_back(getObj);
				cout << getObj;
				getObj.~student();
			}
			system("pause");
			system("CLS");
		}
		if (mIndex == 3)
		{
			system("CLS");
			prtintrez();
			ifstream ins("kursiokai.txt");
			getline(ins, s);
			while (ins)
			{
				getline(ins, s);
				if (!ins) break;
				istringstream sts(s);
				sts >> id_naTemp >> id_suTemp;
				while (sts)
				{
					sts >> rez;
					nd.push_back(rez);
				}
				exTemp = nd.at(nd.size() - 1);
				nd.pop_back();
				student getObj(id_naTemp, id_suTemp, nd, exTemp);
				cin >> getObj;
				nd.clear();
				list.push_back(getObj);
				cout << getObj;
				getObj.~student();
			}
			ins.close();

			system("pause");
			system("CLS");
		}
		if (mIndex == 4)
		{
			prtintrez();
			sort(list.begin(), list.end(),
				[](const student& x, student& y)
				{
					return x.get_name() < y.get_name();
				});
			for (int i = 0; i < list.size(); ++i)
			{
				cout << list.at(i);
			};
			system("pause");
			system("CLS");
		}
		if (mIndex == 5) {
			list.clear();
			system("CLS");
			cout << "\n\tDuomenis sekmingai istrinti" << endl << endl;
			system("pause");
			system("CLS");
		}
		if (mIndex == 6)
		{
			cout << "Ivedimas bus atliekamas is atsitiktiniu skaiciu nuo 0 iki 10: " << endl;
			cout << "\nIveskite studentu kieki: ";
			cin >> stqty;
			cout << "\nIveskite namu darbu kieki: ";
			cin >> ndqty;
			prtintrez();
			for (int i = 1; i < stqty + 1; i++) {
				string name = "Vardas";
				string surname = "Pavarde";
				name += to_string(i);
				surname += to_string(i);
				id_naTemp = name;
				id_suTemp = surname;
				for (int i = 0; i < ndqty; i++)
				{
					rez = rand() % 11;
					nd.push_back(rez);
				}
				exTemp = rand() % 11;

			}
			system("pause");
			system("CLS");
		}
		
	}
};
