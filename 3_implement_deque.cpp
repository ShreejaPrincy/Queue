//Time Complexity: All operations → O(1)

//Space Complexity: O(n) (due to array implementation of deque)

//mycode

#include <bits/stdc++.h> 
class Deque
{   
    int *arr;
    int rear;
    int front;
    int size;

public:
    // Initialize your data structure.
    Deque(int n)
    {
        arr=new int[n];
        size=n;
        rear=-1;
        front=-1;
    }

    // Pushes 'X' in the front of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushFront(int x)
    {   if(front==(rear+1)%size)   return false;
        if(front==-1&&rear==-1){
            front=0;
            rear=0;
            arr[front]=x;
        }
        else{
            front=(front-1+size)%size;          //*
            arr[front]=x;
        }
        return true;
    }

    // Pushes 'X' in the back of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushRear(int x)
    {
        if(isFull())   return false;
        if(front==-1&&rear==-1){
            front=0;
            rear=0;
            arr[rear]=x;
        }
        else{
            rear=(rear+1)%size;
            arr[rear]=x;
        }
        return true;
    }

    // Pops an element from the front of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popFront()
    {
        if(isEmpty())   return -1;

        int ans = arr[front];
        if(front==rear){
            front=-1;
            rear=-1;
        }
        else
            front=(front+1)%size;
        return ans;
    }

    // Pops an element from the back of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popRear()
    {
        if(isEmpty())   return -1;
        
        int ans = arr[rear];
        if(front==rear){
            front=-1;
            rear=-1;
        }
        else
            rear=(rear-1+size)%size;          //*
        return ans;
    }

    // Returns the first element of the deque. If the deque is empty, it returns -1.
    int getFront()
    {   
        if(isEmpty())   return -1;
        return arr[front];
    }

    // Returns the last element of the deque. If the deque is empty, it returns -1.
    int getRear()
    {
        if(isEmpty())   return -1;
        return arr[rear];
    }

    // Returns true if the deque is empty. Otherwise returns false.
    bool isEmpty()
    {
        if(front==rear&&front==-1)  return true;
        return false;
    }

    // Returns true if the deque is full. Otherwise returns false.
    bool isFull()
    {
        if(front==(rear+1)%size)   return true;
        return false;
    }
};


