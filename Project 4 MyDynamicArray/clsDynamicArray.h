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

    void PrintList() {
        for (int i = 0; i < _Size; i++) { // Ensure all elements are printed
            cout << OriginalArray[i] << " ";
        }
        cout << endl;
    }

    void Resize(int NewSize) {
        if (NewSize < 0) NewSize = 0;

        T* TempArray = new T[NewSize];

        // Determine how many elements to copy
        int elementsToCopy = (NewSize < _Size) ? NewSize : _Size;

        for (int i = 0; i < elementsToCopy; i++) {
            TempArray[i] = OriginalArray[i]; // Copy values
        }

        // Initialize new positions if size increased (to avoid random values)
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
        for (int i = _Size - 1; i >=  0 ; --i) {
            TempArray[i] = OriginalArray[_Size- 1 - i]; // Copy values
        }
        delete[] OriginalArray;
        OriginalArray = TempArray;
        
    }
    void Clear() {
        int _Size = 0;
        T* TempArray = new T[0];
        delete[] OriginalArray;
        OriginalArray = TempArray;
    }

    // void DeleteItemAt(int index) {
    //     if (index < 0 || index >= _Size) return;
    //     T* TempArray = new T[_Size - 1];
    //     for (int i = 0; i < _Size - 1; i++) {
    //         if(i < index) {
    //             TempArray[i] = OriginalArray[i];
    //         } else {
    //             TempArray[i] = OriginalArray[i + 1];
    //         }
    //     }
    //     delete[] OriginalArray;
    //     OriginalArray = TempArray;
    //     --_Size;
    // }
    void DeleteItemAt(int index) {
        if (index < 0 || index >= _Size) return;

        // Shift elements to the left starting from the deleted index
        for (int i = index; i < _Size - 1; i++) {
            OriginalArray[i] = OriginalArray[i + 1];
        }

        --_Size; 
        // No new/delete needed! The memory stays allocated for future use.
    }
    void DeleteFirstItem() {
        DeleteItemAt(0);
    }
    void DeleteLastItem() {
        DeleteItemAt(_Size - 1);
    }
    int Find(T value) {
        for(int i =0; i < _Size; i++) {
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
    
};
