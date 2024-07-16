#include <bits/stdc++.h> 


// If we do this problem by two types like n/k divides and allocate each array side to each stacks but the disadvantage of this is Space is not optimised.


class NStack
{
    int *arr;
    int *next;
    int *top;
    int n, s;
    int freespot;
public:
    // Initialize your data structure.
    

    NStack(int N, int S)
    {
        // Write your code here.
        n=N;
        s=S;
        arr = new int[s];
        top = new int[n];
        next = new int[s];

        // Initialise the top with -1;

        for(int i=0; i<n; i++){
            top[i] = -1;
        }

        for(int i=0; i<s; i++){
            next[i] = i+1;
        }

        next[s-1] = -1;

        freespot = 0;
    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m)
    {
        if(freespot == -1){
            return false;
        }

        // Find index

        int index = freespot;

        // Update freespot;

        freespot = next[index];

        // insert the values int he array

        arr[index] = x;

        // Update the next

        next[index] = top[m-1];


        // Update the top

        top[m-1] = index;

        return true; 
    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m)
    {
        if(top[m-1] == -1){
            return -1;
        }

        int index = top[m-1];
        top[m-1] = next[index];
        next[index] = freespot;
        freespot = index;
        return arr[index];
    }
};