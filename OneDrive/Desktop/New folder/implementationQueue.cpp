#include <bits/stdc++.h>
class Queue
{
public:
    int *arr;
    int size;
    int qfront;
    int rear;
    Queue()
    {
        size = 10001;
        arr = new int[size];
        qfront = 0;
        rear = 0;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty()
    {
        return qfront == rear;
    }

    void enqueue(int data)
    {
        if (rear == size)
        {
            return;
        }
        else
        {
            arr[rear] = data;
            rear++;
        }
        return;
    }

    int dequeue()
    {
        if (qfront == rear)
            return -1;
        int ans = arr[qfront];
        arr[qfront] = -1;
        qfront++;
        if (qfront == rear)
        {
            qfront = 0;
            rear = 0;
        }
        return ans;
    }

    int front()
    {
        if (qfront == rear)
            return -1;
        return arr[qfront];
    }
};