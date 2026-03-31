#pragma once
#include <iostream>
#include "clsDblLinkedList.h"
using namespace std;

template <class T> 
class clsMyQueue {
private:
    // Encapsulation: Keep the linked list private so the user is forced 
    // to strictly follow Queue FIFO rules (push, pop, etc.)
    clsDblLinkedList<T> MydblLinkedList;

public:
    
    // Adds an element to the back of the queue (Enqueue)
    void push(T value) {
        MydblLinkedList.InsertAtEnd(value);
    }
    
    // Removes the element at the front of the queue (Dequeue)
    // Note: Standard C++ STL uses 'void' for pop(). To get the value, use front().
    void pop() {
        MydblLinkedList.DeleteFirstNode();
    }
    
    // Returns the value of the front element without removing it (Peek)
    T front() {
        if (MydblLinkedList.IsEmpty()) {
            cout << "Queue is empty\n";
            return T(); // Safe return for generic types
        }
        return MydblLinkedList.GetItem(0);
    }
    
    // Prints the entire queue from front to back
    void Print() {
        MydblLinkedList.PrintList();
    }
    
    // Returns the number of elements in the queue
    int Size() {
        return MydblLinkedList.Size(); // Fix: Added missing semicolon
    }
    
    // Returns the value of the last element in the queue
    T back() {
        if (MydblLinkedList.IsEmpty()) {
            cout << "Queue is empty\n";
            return T();
        }
        // Fix: The last element is at index (Size - 1), not Size.
        return MydblLinkedList.GetItem(Size() - 1);
    }

    // Checks if the queue has no elements
    bool IsEmpty() {
        return MydblLinkedList.IsEmpty();
    }
    T GetItem(T value) {
        return MydblLinkedList.GetItem(value);
    }
    void Reverse() {
        MydblLinkedList.Reverse();
    }
    bool UpdateItem(int Index, T NewValue) {
        return MydblLinkedList.UpdateItem(Index, NewValue);
    }
    bool InsertAfter(int Index, T value) {
        return MydblLinkedList.InsertAfter(Index, value);
    }
    void InsertAtFront(T value) {
        MydblLinkedList.InsertAtBeginning(value);
    }
    void InsertAtBack(T value) {
        MydblLinkedList.InsertAtEnd(value);
    }
    void Clear() {
        MydblLinkedList.Clear();
    }


};