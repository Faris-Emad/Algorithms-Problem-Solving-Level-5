#pragma once
#include <iostream>
using namespace std;

template <class T>
class clsDynamicArray {
private:
    int _Size = 0;

public:
    T* OriginalArray;

    clsDynamicArray(int size = 0) {
        if (size < 0) size = 0;
        _Size = size;
        OriginalArray = new T[_Size];
    }

    ~clsDynamicArray() {
        delete[] OriginalArray;
    }

    bool SetItem(int index, T value) {
        if (index >= _Size || index < 0) return false;
        OriginalArray[index] = value;
        return true;
    }

    int Size() {
        return _Size;
    }

    bool IsEmpty() {
        return (_Size == 0);
    }

    void Print() {
        for (int i = 0; i < _Size; i++) {
            cout << OriginalArray[i] << " ";
        }
        cout << endl;
    }

    void Resize(int NewSize) {
        if (NewSize < 0) NewSize = 0;
        T* TempArray = new T[NewSize];
        int elementsToCopy = (NewSize < _Size) ? NewSize : _Size;
        for (int i = 0; i < elementsToCopy; i++) {
            TempArray[i] = OriginalArray[i];
        }
        for (int i = elementsToCopy; i < NewSize; i++) {
            TempArray[i] = 0; 
        }
        _Size = NewSize;
        delete[] OriginalArray;
        OriginalArray = TempArray;
    }

    T GetItem(int index) {
        return OriginalArray[index];
    }

    void Reverse() {
        T* TempArray = new T[_Size];
        for (int i = _Size - 1; i >= 0; --i) {
            TempArray[i] = OriginalArray[_Size - 1 - i];
        }
        delete[] OriginalArray;
        OriginalArray = TempArray;
    }

    void Clear() {
        _Size = 0;
        delete[] OriginalArray;
        OriginalArray = new T[0];
    }

    void DeleteItemAt(int index) {
        if (index < 0 || index >= _Size) return;
        for (int i = index; i < _Size - 1; i++) {
            OriginalArray[i] = OriginalArray[i + 1];
        }
        --_Size; 
    }

    void DeleteFirstItem() {
        DeleteItemAt(0);
    }

    void DeleteLastItem() {
        DeleteItemAt(_Size - 1);
    }

    int Find(T value) {
        for(int i = 0; i < _Size; i++) {
            if(value == OriginalArray[i])
                return i;
        }
        return -1;
    }

    bool DeleteItem(T value) {
        int index = Find(value);
        if(index != -1) {
            DeleteItemAt(index);
            return true;
        }
        return false;
    }

    void InsertAt(int index, T value) {
        if (index < 0 || index > _Size) return; 
        Resize(_Size + 1);
        for (int i = _Size - 1; i > index; i--) {
            OriginalArray[i] = OriginalArray[i - 1];
        }
        OriginalArray[index] = value;
    }

    void InsertAtBeginning(T value) {
        InsertAt(0, value);
    }

    void InsertBefore(int index, T value) {
        InsertAt(index, value);
    }

    void InsertAfter(int index, T value) {
        InsertAt(index + 1, value);
    }

    void InsertAtEnd(T value) {
        InsertAt(_Size, value);
    }

    bool UpdateItem(int index, T value) {
        return SetItem(index, value);
    }
};
