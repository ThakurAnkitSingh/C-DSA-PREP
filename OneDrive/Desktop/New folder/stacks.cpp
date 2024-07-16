#include <bits/stdc++.h>
using namespace std;

class Stack
{
public:
    int top;
    int *arr;
    int size;
    Stack(int size)
    {
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int data)
    {
        if (size - top > 1)
        {
            top++;
            arr[top] = data;
        }
        else
        {
            cout << "Stack Overflow" << endl;
        }
    }

    void pop()
    {
        if (top > -1)
        {
            top--;
        }
        else
        {
            cout << "Stack Underflow" << endl;
        }
    }

    int peek()
    {
        if (top >= 0)
        {
            return arr[top];
        }
        else
        {
            return -1;
        }
    }

    bool empty()
    {
        if (top == -1)
        {
            return true;
        }
        else
        {
            cout << "Stack Empty" << endl;
            return false;
        }
    }

};

int
main()
{
    Stack st(5);
    st.push(1);
    st.push(2);
    st.push(3);

    st.pop();
    st.pop();
    st.pop();
    st.peek();
    cout << st.peek() << endl;
    st.empty();
    cout << st.empty() << endl;
    return 0;
}