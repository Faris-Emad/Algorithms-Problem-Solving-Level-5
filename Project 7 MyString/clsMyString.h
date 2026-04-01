#pragma once
#include <iostream>
#include <string>
#include "clsMyStackArr.h" // استخدم الكلاس بتاعك!

using namespace std;

class clsMyString {
private:
    string _Value;
    clsMyStackArr<string> _UndoStack;
    clsMyStackArr<string> _RedoStack;

public:
    // Constructor
    clsMyString(string value = "") {
        _Value = value;
    }

    // Property Set: هنا بنخزن الحالة قبل التغيير
    void set_Value(string newValue) {
        _UndoStack.push(_Value); // خزن القيمة القديمة
        _Value = newValue;
        _RedoStack.Clear();      // لو غيرت يدوي، الـ Redo بيتمسح
    }

        string get_Value() {
            return _Value;
        }
    
    #ifdef _MSC_VER
        __declspec(property(get = get_Value, put = set_Value)) string Value;
    #else
        string Value() const {
            return _Value;
        }
    
        void Value(const string& newValue) {
            set_Value(newValue);
        }
    #endif
    
        void Undo() {
        if (_UndoStack.Size() > 0) {
            _RedoStack.push(_Value);     // شيل الحالية في الـ Redo
            _Value = _UndoStack.Top();   // رجع القديمة من الـ Undo
            _UndoStack.pop();            // امسحها من الـ Undo
        }
    }

    void Redo() {
        if (_RedoStack.Size() > 0) {
            _UndoStack.push(_Value);     // شيل الحالية في الـ Undo
            _Value = _RedoStack.Top();   // رجع اللي اتمسحت من الـ Redo
            _RedoStack.pop();            // امسحها من الـ Redo
        }
    }
};