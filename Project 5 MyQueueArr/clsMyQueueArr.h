#pragma once
#include <iostream>
#include "clsDynamicArray.h"
using namespace std;


template <class T>
class clsMyQueueArr {
private:
    clsDynamicArray <T> MyDynamicArray;
public:
    void push(T value) {
        MyDynamicArray.InsertAtEnd(value);
    }
    void Print(){
        MyDynamicArray.Print();
    }
    int Size() {
       return MyDynamicArray.Size();
    }
    T front(){
        return MyDynamicArray.GetItem(0);
    }
    T back(){
        return MyDynamicArray.GetItem(Size() - 1);
    }
    void pop() {
        MyDynamicArray.DeleteFirstItem();
    }
    T GetItem(int index) {
        return MyDynamicArray.GetItem(index);
    }
    void Reverse() {
        MyDynamicArray.Reverse();
    }
    void UpdateItem(int index, T value) {
        MyDynamicArray.UpdateItem(index, value);
    }
    void InsertAfter(int index, T value) {
        MyDynamicArray.InsertAfter(index, value);
    }
    void InsertAtFront(T value) {
        MyDynamicArray.InsertAtBeginning(value);
    }
    void InsertAtBack(T value) {
        MyDynamicArray.InsertAtEnd(value);
    }
    void Clear() {
        MyDynamicArray.Clear();
    }
};

