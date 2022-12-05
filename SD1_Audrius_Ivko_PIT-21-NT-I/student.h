#include "Header.h"


class student {
	string id_name;
	string id_surname;
	vector<float>nd;
	list<float>dataL;
	float exam;
	float mean;
	float median;
	float gradeMean;
	float gradeMedian;
public:
	void Set_name(string a) {
		id_name = a;
	}
	string get_name() const {
		return id_name;
	}

	student();
	student(string s_id_name, string s_id_surname, float s_gradeMean, float s_gradeMedian);
	student(string new_id_name, string new_id_surname, vector<float>new_nd, float new_exam);
	student(string new_id_name, string new_id_surname, list<float>a_dataL);
	student(const student& original);

	void setDataMean();
	void setDataMedian();
	float setDataGradeMean();
	float setDataGradeMedian();
	friend istream& operator>>(istream& input, student& set_data);
	friend ostream& operator<<(ostream& output, const student& set_data);
	~student() {};
};

void prtintrez();
float checknd(float nd);
float checkex(float ex);