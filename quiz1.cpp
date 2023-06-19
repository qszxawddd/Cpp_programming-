#include <iostream>
using namespace std;

template <typename T>
class List {
public:
    List() : head_(NULL) { }
    virtual void add(T n) {
        Link *p = new Link(n, head_);
        head_ = p;
    }

    void print_head() {
        if (head_ != NULL) {
            cout << "head: " << head_->val << endl;
        }
    }

    void printList() {
        Link *current = head_;
        while (current != NULL) {
            cout << current->val;
            if (current->next != NULL) {
                cout << ", ";
            }
            current = current->next;
        }
        cout << endl;
    }


private:
    struct Link {
        int val;
        Link *next;
        Link(int n, Link* nxt) : val(n), next(nxt) { }
    };

    Link *head_;
};

int main() {
    List<double> nums;
    int i, data, count;
    cin >> count;
    for (i = 0; i < count; i++) {
        cin >> data;
        nums.add(data);
    }
    nums.print_head();
    nums.printList();
    return 0;
}
