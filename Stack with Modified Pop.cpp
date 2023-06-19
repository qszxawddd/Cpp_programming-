#include <iostream>
#include <cstdlib>
using namespace std;

struct Node {
    string stu_no;
    int math;
    int english;
    int computer;
    Node *next;
};

class stack {
    private:
        Node *top;
         // the conventional way
    public:
        stack() {
            this->top = NULL;
            cout << " # The stack is generated. " << endl;
        }
        ~stack() {
            cout << " # The stack is deleted." << endl;
        }
        void push(string s, int m, int e, int c);
        void pop();
        void display();
};

void stack::push(string s, int m, int e, int c)
{
    Node *new_node = new Node;
    new_node->stu_no = s;
    new_node->math = m;
    new_node->english = e;
    new_node->computer = c;
    new_node->next = this->top;
    this->top = new_node;
}

void stack::pop()
{
     if (this->top == NULL) {
        cout << "List is empty!" << endl;
        return;
    }

    float math_sum = 0, eng_sum = 0, cs_sum = 0;
    int count = 0;
    // 计算剩余学生的平均分
    Node *cur = top;

    while (cur != NULL) {
        math_sum += cur->math;
        eng_sum += cur->english;
        cs_sum += cur->computer;
        ++count;
        cur = cur->next;
    }
    cout << "math avg: " << math_sum / count << endl;
    cout << "english avg: " << eng_sum / count << endl;
    cout << "computer avg :" << cs_sum / count << endl;

    Node *tmp;
    cout << top->stu_no << " is removed." << endl;
    tmp = top;
    top = top->next;
    delete tmp;

}

void stack::display()
{
    if (top == NULL) {
        cout << "List is empty!" << endl;
        return;
    }

    Node *cur = top;
    while (cur != NULL) {
        cout << cur->stu_no << " " << cur->math << " " << cur->english << " " << cur->computer << endl;
        cur = cur->next;
    }
    cout << endl;
}

int main() {
    stack st;
    string stu_no;
    int math, eng, cs;
    char c;

    cout << "push an item: ";
    cin >> stu_no >> math >> eng >> cs;
    st.push(stu_no, math, eng, cs);

    cout << "push an item: ";
    cin >> stu_no >> math >> eng >> cs;
    st.push(stu_no, math, eng, cs);

    cout << "push an item: ";
    cin >> stu_no >> math >> eng >> cs;
    st.push(stu_no, math, eng, cs);

    //show the stack content
    st.display();

    cout << "Press any key to continue..." << endl;
    cin.ignore(1);

    // pop an item
    cout << "pop out an item: ";
    cin.ignore(1);
    st.pop();

    //show the stack content
    st.display();
    // pop an item
    cout << "pop out an item: ";
    cin.ignore(1);

    st.pop();
    //show the stack content
    st.display();
    // pop an item

    cout << "pop out an item: ";
    cin.ignore(1);
    st.pop();
    st.display();
    return 0;
}
