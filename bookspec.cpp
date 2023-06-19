#include <iostream>
#include <string>
using namespace std;

class BOOK
{

        int BOOK_NO;
        string TITLE;
        float PRICE;
        float TOTAL_COST(int N){
            return N * PRICE;
        };
    public :
        INPUT()
        {
            cout << "In INPUT():" << endl;
            cout << "Enter Book Title: ";
            getline(cin, TITLE);
            cout << "Enter Book Number: ";
            cin >> BOOK_NO;
            cout << "Enter price per copy: ";
            cin >> PRICE;
        }
        PURCHASE()
        {
            int N;
            cout << "In PURCHASE():" << endl;
            cout << "Enter number of copies to purchase: ";
            cin >> N;
            cout << "Total cost: " << TOTAL_COST(N) ;
        }
};



int main()
{
    BOOK obj;
    obj.INPUT();
    obj.PURCHASE();
    return 0;
}
