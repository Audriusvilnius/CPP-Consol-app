#include "Header.h"
#include "global.h"
#include "student.h"


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
	vector<student> dataV;
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
		cout << "| 5. Sarasu generavimas, greicio matavimas is atsitiktinius duomenu       |" << endl;
		cout << "| 6. Panaikinti suvestus duomenis                                         |" << endl;
		cout << "| 0. Nutraukti darba.                                                     |" << endl;
		cout << "--------------------------------------------------------------------------" << endl;
		cout << "Iveskite pasirinkimo numeri: ";
		cin >> mIndex;

		while (mIndex > 6 || mIndex < 0)
		{
			cout << "Tokio pasirinkimo nera iveskite tinkama numeri : ";
			cin >> mIndex;
		};
		if (mIndex == 0)
		{
			return 0;
		}
		system("CLS");
		if (mIndex < 5)
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
		if (mIndex == 5)
		{
			option = 3;
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
			dataV.push_back(getObj);
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
				system("pause");
				student getObj(id_naTemp, id_suTemp, nd, exTemp);
				cin >> getObj;
				nd.clear();
				dataV.push_back(getObj);
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
				dataV.push_back(getObj);
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
			sort(dataV.begin(), dataV.end(),
				[](const student& x, student& y)
				{
					return x.get_name() < y.get_name();
				});

			for (auto& a : dataV) {
				cout << a;
			}

		}

		if (mIndex == 5) {
			dataV.clear();
			cout << "Programos greitoveikos matavimas." << endl;
			cout << "Matuojama atskirai kiekvieno <T> tipo konteinerio greitoveika." << endl;
			cout << "1. Kuriamas atsitiktiniu duomenu sarasas, kuriamai objektai ir atliekami skaiciavimai;" << endl;
			cout << "2. Saras <T> Vector konteineris skaidomas i dvi dalis pagal pozimi, 5 balu vidurkio ir virs 5 balu vidurkio" << endl;
			cout << "duomenys talpinami i sesis <T> tipo konteinerius. Vector, Deque ir List, kiekvieno po du;" << endl;
			cout << "3. Rusiavimas <T> tipo Vector, Deque ir List konteineriu pagal balo vidurki;" << endl;
			cout << "4. Kiekvienas tipas irasys duomenis i fala, greitoveika matuojama tik Vector tipo konteinerio;" << endl;
			cout << "5. Generuojamas atsitiktinis studento: Vardas, Pavarde" << endl;
			cout << "6. Generuojamas atsitiktinis egzamino balas" << endl;
			cout << "7. Iveskite studentu kieki: ";
			cin >> stqty;
			cout << "8. Iveskite namu darbu kieki: ";
			cin >> ndqty;
			system("CLS");
			cout << "\nVyksta duomenu apdorojimas....\n" << endl;
			auto start_Rnd = std::chrono::high_resolution_clock::now();
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
				dataV.push_back(getObj);
				getObj.~student();
			}
			auto start_List_sort = std::chrono::high_resolution_clock::now();

			sort(dataV.begin(), dataV.end(),
				[](const student& x, student& y)
				{
					return x.get_gradeMean() < y.get_gradeMean();
				});

			auto end_list_sort = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> sortL = end_list_sort - start_List_sort;

			auto end_Rnd = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> rnd = end_Rnd - start_Rnd;

			vector<student>V_dataUp;
			vector<student>V_dataLess;

			auto start_Vec_split = std::chrono::high_resolution_clock::now();

			partition_copy(dataV.begin(), dataV.end(), back_inserter(V_dataUp), back_inserter(V_dataLess), [](student& x) {return x.get_gradeMean() >= 5; });

			auto end_Vec_split = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> spliV = end_Vec_split - start_Vec_split;

			auto start_Vec_sort = std::chrono::high_resolution_clock::now();

			/*cout << "\n\nDuomenu skaidymas ir filtravimas is Vector tipo konteinerio" << endl;*/

			sort(V_dataUp.begin(), V_dataUp.end(),
				[](const student& x, student& y)
				{
					return x.get_gradeMean() < y.get_gradeMean();
				});
			/*prtint_Up();
			/*for (auto& a : V_dataUp) {cout << a;}*/


			sort(V_dataLess.begin(), V_dataLess.end(),
				[](const student& x, student& y)
				{
					return x.get_gradeMean() > y.get_gradeMean();
				});
			/*prtint_Less();
			for (auto& a : V_dataLess) {cout << a;}*/

			auto end_Vec_sort = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> sortV = end_Vec_sort - start_Vec_sort;

			option = 7;
			auto start_Vec_stream = std::chrono::high_resolution_clock::now();

			ofstream outlessvf("out_data_less.txt");
			outlessvf << "Vardas" << "\t" << "Pavarde" << "\t" << "Vidurkis >= 5" << "\n";
			for (auto& a : V_dataLess) {
				outlessvf << a;
			}
			outlessvf.close();

			ofstream outupvf("out_data_up.txt");
			outupvf << "Vardas" << "\t" << "Pavarde" << "\t" << "Vidurkis < 5" << "\n";
			for (auto& a : V_dataUp) {
				outupvf << a;
			}
			outupvf.close();

			auto end_Vec_stream = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> streamV = end_Vec_stream - start_Vec_stream;

			option = 3;
			/*system("pause");
			system("CLS");

			cout << "\n\nDuomenu skaidymas ir filtravimas is Deque tipo konteinerio" << endl;*/
			deque<student>D_dataUp;
			deque<student>D_dataLess;

			auto start_Deq_split = std::chrono::high_resolution_clock::now();

			partition_copy(dataV.begin(), dataV.end(), back_inserter(D_dataUp), back_inserter(D_dataLess), [](student& x) {return x.get_gradeMean() >= 5; });

			auto end_Deq_split = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> splitD = end_Deq_split - start_Deq_split;

			auto start_Deq_sort = std::chrono::high_resolution_clock::now();

			sort(D_dataUp.begin(), D_dataUp.end(),
				[](const student& x, student& y)
				{
					return x.get_gradeMean() < y.get_gradeMean();
				});


			/*prtint_Up();
			/*for (auto& a : D_dataUp) {cout << a;}*/

			sort(D_dataLess.begin(), D_dataLess.end(),
				[](const student& x, student& y)
				{
					return x.get_gradeMean() > y.get_gradeMean();
				});

			auto end_Deq_sort = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> sortD = end_Deq_sort - start_Deq_sort;

			/*prtint_Less();
			for (auto& a : D_dataLess) {cout << a;}*/

			option = 7;
			ofstream outlessdf("out_data_less.txt");
			outlessdf << "Vardas" << "\t" << "Pavarde" << "\t" << "Vidurkis >= 5" << "\n";
			for (auto& a : D_dataUp) {
				outupvf << a;
			}
			outlessdf.close();

			ofstream outupdf("out_data_up.txt");
			outupdf << "Vardas" << "\t" << "Pavarde" << "\t" << "Vidurkis < 5" << "\n";
			for (auto& a : D_dataLess) {
				outupvf << a;
			}
			outupdf.close();

			/*system("pause");
			system("CLS");*/

			/*cout << "\n\nDuomenu kopijavimas is dvieju Vector tipo konteineriu i List tipo konteineris, duomenys jau atfiltruoti" << endl;*/
			option = 3;

			list<student> L_dataUp;
			list<student> L_dataLess;

			auto start_List_split = std::chrono::high_resolution_clock::now();

			partition_copy(dataV.begin(), dataV.end(), back_inserter(L_dataUp), back_inserter(L_dataLess), [](student& x) {return x.get_gradeMean() >= 5; });

			auto end_List_split = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> splitL = end_List_split - start_List_split;

			//L_dataUp.sort();
			//L_dataLess.sort();

			/*L_dataUp.sort([](const student& x, const student& y)
				{
					if (x.get_gradeMean() == y.get_gradeMean())
					return x < y;
					return x.get_gradeMean() < y.get_gradeMean();
				});*/


				//copy(V_dataUp.begin(), V_dataUp.end(), back_inserter(L_dataUp));
				//copy(V_dataLess.begin(), V_dataLess.end(),back_inserter(L_dataLess));

				/*prtint_Less();
				for (const student& i : L_dataUp) {
					cout << i;
				}*/


				/*prtint_Up();
				for (const student& i : L_dataLess) {
					cout << i;
				}*/

			option = 7;

			ofstream outlesslf("out_data_less.txt");
			outlesslf << "Vardas" << "\t" << "Pavarde" << "\t" << "Vidurkis >= 5 list\n";
			for (const student& i : L_dataUp)
			{
				outlesslf << i;
			}
			outlesslf.close();

			ofstream outuplf("out_data_up.txt");
			outuplf << "Vardas" << "\t" << "Pavarde" << "\t" << "Vidurkis < 5" << "\n";
			for (const student& i : L_dataLess)
			{
				outuplf << i;
			}
			outuplf.close();

			V_dataUp.clear();
			V_dataLess.clear();
			D_dataLess.clear();
			D_dataLess.clear();
			L_dataUp.clear();
			L_dataLess.clear();
			dataV.clear();

			system("CLS");

			cout << "Matuojama atskirai kiekvieno <T> tipo konteinerio greitoveika." << endl;
			cout << "1. Kuriamas atsitiktiniu duomenu sarasas, kuriamai objektai ir atliekami skaiciavimai;" << endl;
			cout << "2. Saras <T> Vector konteineris skaidomas i dvi dalis pagal pozimi, 5 balu vidurkio ir virs 5 balu vidurkio" << endl;
			cout << "duomenys talpinami i sesis <T> tipo konteinerius. Vector, Deque ir List, kiekvienom po du;" << endl;
			cout << "3. Rusiavimas <T> tipo Vector, Deque ir List konteineriu pagal balo vidurki;" << endl;
			cout << "4. Kiekvienas tipas irasys duomenis i fala, greitoveika matuojama tik Vector tipo konteinerio;" << endl;
			cout << "5. Generuojamas atsitiktinis studento: Vardas, Pavarde" << endl;
			cout << "6. Generuojamas atsitiktinis egzamino balas" << endl;
			cout << "7. Studentu kieki: " << stqty << endl;
			cout << "8. Namu darbu kieki: " << ndqty << endl;
			cout << "\nProgramos greitoveikos matavimao rezultatai:" << endl;

			cout << "\nVector tipo objektu failo generavimas, is " << stqty << " eiluciu ir " << ndqty + 3 << " stulpeliu laikas: " << rnd.count() << " s/n" << endl;
			cout << "\nVector tipo failo rusiavimas, is " << stqty << " objektu " << sortL.count() << " s/n" << endl;
			cout << "\nVectort tipo duomenu konteinerio dalinimas pagal pozimi, is " << stqty << " objektu trukme: " << spliV.count() << " s/n" << endl;
			cout << "Deque tipo duomenu konteinerio dalinimas pagal pozimi, is " << stqty << " objektu trukme: " << splitD.count() << " s/n" << endl;
			cout << "List tipo duomenu konteinerio dalinimas pagal pozimi, is " << stqty << " objektu trukme: " << splitL.count() << " s/n" << endl;

			cout << "\nVectort tipo duomenu konteinerio rusiavimas pagal pozimy, is " << stqty << " objektu trukme: " << sortV.count() << " s/n" << endl;
			cout << "Deque tipo duomenu konteinerio rusiavimas pagal pozimy, is " << stqty << " objektu trukme: " << sortD.count() << " s/n" << endl;
			cout << "List tipo duomenu konteinerio rusiavimas pagal pozimy atliktas Vector konteineryje, is " << stqty << " objektu trukme: " << sortL.count() << " s/n" << endl << endl;
			cout << "\nVector tipo duo menu irasymas i faila is " << stqty << " objektu trukme: " << streamV.count() << " s/n" << endl << endl;

			system("pause");
			system("CLS");

		}
		if (mIndex == 6) {
			dataV.clear();
			system("CLS");
			cout << "\n\tDuomenis sekmingai istrinti" << endl << endl;
			system("pause");
			system("CLS");
		}
	}
};
