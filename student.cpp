#include <iostream>
using namespace std;

class student {
	private:
		int studentID;
		string name;
		float eng, math, phy, total;
		void grades() {
			cout << total;
		}
		void avg_grade(){
            cout << total / 3;
		}
	public:
		void Takedata(){
			cout << "In Takedata(): " << endl;
			cout << "Enter studentID: ";
			cin >> student::studentID;
			cout << "Enter student name: ";
			cin >> student::name;
			cout << "Enter grades in English, Math, and Physics: ";
			cin >> student::eng >> student::math >> student::phy;
			total = eng+math+phy;
		}


		void Showdata(){
			cout << "In Showdata(): " << endl;
			cout << "StudentID: " << student::studentID << endl;
			cout << "Student Name: " << student::name << endl;
			cout << "English: " << student::eng << endl;
			cout << "Math: " << student::math << endl;
			cout << "Physics: " << student::phy << endl;
			cout << "Total: ";
			student::grades();
			cout << endl << "Avg: ";
			avg_grade();
		}
		int PassOrFail(){
            if(total / 3 >= 60){
                cout << endl << "Pass";
            }
            else cout << endl << "Fail";
        }
};
int main(){
	student obj;
	obj.Takedata();
	obj.Showdata();
	obj.PassOrFail();
	return 0;
}

