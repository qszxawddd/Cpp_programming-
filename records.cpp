#include <iostream>

using namespace std;

int SIZE = 0;

class Record {
protected:
    int count;
    int *list;
public:
    Record() = default;
    //Record() { cout << "Record() is called" << endl; }
    Record(int size) {
        int i;
        count = size;
        cout << "Please enter " << count << " numbers: " << endl;
        list = new int[count]();
        for (i=0; i<count; i++) {
            cin >> list[i];
        }
    }
    ~Record() = default;
    int get_record(int);
};

int Record::get_record(int position) {
    return list[position];
}

class StudentRecord:  public Record {
public:
    StudentRecord(int size) {
        int i;
        count = size;
        cout << "Please enter " << count << " student IDs: " << endl;
        list = new int[count]();
        for (i=0; i<count; i++) {
            cin >> list[i];
        }
    }
    ~StudentRecord() {
        if (list != NULL) {
            delete [] list;
            cout << "~StudentRecord() is called." << endl;
        }
    }
};

int main()
{
    int count;
    int check;
    cout << "Enter number of records: " << endl;
    cin >> count;
    StudentRecord r(count);
    cout << "Which one to inspect? " << endl;
    cin >> check;
    cout << "The " << check << " record is " << r.get_record(check-1) << endl;
    return 0;
}

