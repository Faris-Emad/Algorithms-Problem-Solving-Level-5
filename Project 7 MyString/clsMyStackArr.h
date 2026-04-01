#pragma once
#include <iostream>
#include "clsDynamicArray.h"
using namespace std;


template <class T>
class clsMyStackArr {
private:
    clsDynamicArray<T> MyDynamicArray;

public:
    void push(T Value) {
        MyDynamicArray.InsertAtEnd(Value);
    }

    void pop() {
        MyDynamicArray.DeleteLastItem();
    }

    T Top() {
        return MyDynamicArray.GetItem(MyDynamicArray.Size() - 1);
    }

    T Bottom() {
        return MyDynamicArray.GetItem(0);
    }

    int Size() {
        return MyDynamicArray.Size();
    }

    void Print() {
        MyDynamicArray.Print();
    }

    void Clear() {
        MyDynamicArray.Clear();
    }

    void Reverse() {
        MyDynamicArray.Reverse();
    }

    void UpdateItem(int Index, T Value) {
        MyDynamicArray.UpdateItem(Index, Value);
    }

    void InsertAtFront(T Value) {
        MyDynamicArray.InsertAtBeginning(Value);
    }

    void InsertAtBack(T Value) {
        MyDynamicArray.InsertAtEnd(Value);
    }
    T GetItem(int index) {
        return MyDynamicArray.GetItem(index);
    }

    void InsertAfter(int Index, T Value) {
        MyDynamicArray.InsertAfter(Index, Value);
    }
};


