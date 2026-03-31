#pragma once
#include <iostream>
using namespace std;

template <class T>
class clsDblLinkedList
{
private:
    int _Size = 0;

public:
    class Node
    {
    public:
        T value;
        Node* next;
        Node* prev;
    };

    Node* head = NULL;
    Node* tail = NULL;

    // Insert a new node at the beginning of the list
    void InsertAtBeginning(T value)
    {
        /*
            1. Create a new node.
            2. Set its next to current head, and prev to NULL.
            3. Link the old head's prev to the new node.
            4. Update the head pointer.
            5. If the list was empty, tail should also point to this new node.
        */
        Node* newNode = new Node();
        newNode->value = value;
        newNode->next = head;
        newNode->prev = NULL;

        if (head != NULL) {
            head->prev = newNode;
        } else {
            // Fix: Handle the tail pointer when inserting the first element
            tail = newNode;
        }
        
        head = newNode;
        _Size++;
    }

    // Print all elements in the list
    void PrintList() {
        Node* Current = head;
        while (Current != NULL) {
            cout << Current->value << " ";
            Current = Current->next;
        }
        cout << "\n";
    }

    // Find a node by its value and return a pointer to it
    Node* Find(T Value)
    {
        Node* Current = head;
        while (Current != NULL) {
            if (Current->value == Value)
                return Current;
            Current = Current->next;
        }
        return NULL;
    }

    // Insert a new node after a specific given node
    void InsertAfter(Node* current, T value) {
        /* 1. Create a new node.
            2. Link new node to the nodes before and after it.
            3. Update the surrounding nodes to point to the new node.
            4. Update the tail if the new node is added at the very end.
        */
        if (current == NULL) return; // Guard against NULL pointers

        Node* newNode = new Node();
        newNode->value = value;
        newNode->next = current->next;
        newNode->prev = current;

        if (current->next != NULL) {
            current->next->prev = newNode;
        } else {
            // Fix: If inserted after the last node, update the tail
            tail = newNode;
        }
        
        current->next = newNode;
        _Size++;
    }

    // Insert after a specific index
    bool InsertAfter(int Index, T value) {
        Node* current = GetNode(Index);

        if (current == NULL) {
            return false; // Index is invalid
        }

        InsertAfter(current, value);
        return true;
    }

    // Insert a new node at the end of the list (Optimized using tail pointer - O(1))
    void InsertAtEnd(T value) {
        Node* newNode = new Node();
        newNode->value = value;
        newNode->next = NULL;

        if (head == NULL) { // If the list is empty
            newNode->prev = NULL;
            head = newNode;
            tail = newNode; // Head and tail point to the same single node
        } else { // If the list already has elements
            tail->next = newNode; // Link current last node to the new node
            newNode->prev = tail; // Link new node back to the old last node
            tail = newNode;       // Move tail to the new last node
        }
        _Size++;
    }

    // Delete a specific node safely
    void DeleteNode(Node*& NodeToDelete) {
        if (head == NULL || NodeToDelete == NULL) {
            return;
        }

        if (head == NodeToDelete) {
            head = NodeToDelete->next;
        }
        
        // Fix: Update the tail pointer if the last node is being deleted
        if (tail == NodeToDelete) {
            tail = NodeToDelete->prev;
        }

        if (NodeToDelete->next != NULL) {
            NodeToDelete->next->prev = NodeToDelete->prev;
        }
        
        if (NodeToDelete->prev != NULL) {
            NodeToDelete->prev->next = NodeToDelete->next;
        }
        
        delete NodeToDelete;
        _Size--;    
    }

    // Delete the first node in the list
    void DeleteFirstNode()
    {
        if (head == NULL) {
            return;
        }
        
        Node* temp = head;
        head = head->next;
        
        if (head != NULL) {
            head->prev = NULL;
        } else {
            // Fix: If the list becomes empty, tail must be set to NULL to avoid dangling pointer
            tail = NULL;
        }
        
        delete temp;
        _Size--;
    }

    // Delete the last node in the list (Optimized using tail pointer - O(1))
    void DeleteLastNode() {
        if (head == NULL) {
            return;
        }

        if (head->next == NULL) { // Only one node in the list
            delete head;
            head = NULL;
            tail = NULL; // Fix: Prevent dangling tail
            _Size--;
            return;
        }

        // Optimized deletion using the tail pointer instead of traversing the whole list
        Node* temp = tail;
        tail = tail->prev;
        tail->next = NULL;
        delete temp;
        _Size--;
    }

    // Return the current size of the list
    int Size() {
        return _Size;
    }

    // Check if the list is empty
    bool IsEmpty() {
        return (_Size == 0);
    }

    // Clear all elements from the list
    void Clear() {
        while (head != NULL) {
            DeleteFirstNode();
        }
    }

    // Reverse the doubly linked list
    void Reverse() {
        Node* current = head;
        Node* temp = NULL;
        
        // The current head will become the new tail after reversal
        tail = head;

        while (current != NULL) {
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;
            current = current->prev; // Move to the next node (which is now prev)
        }

        // Update the head pointer to the new first node
        if (temp != NULL) {
            head = temp->prev;
        }
    }

    // Get a node pointer by its index
    Node* GetNode(int Index) {
        if (Index < 0 || Index >= _Size) {
            return NULL;
        }

        Node* current = head;
        for (int i = 0; i < Index; i++) {
            current = current->next;
        }
        
        return current;
    }

    // Get the value of a node by its index
    T GetItem(int Index) {
        Node *Item = GetNode(Index);
        
        if(Item == NULL) {
            // Fix: Return the default constructor of type T instead of NULL.
            // This prevents compilation errors if T is an object, and logic errors if T is an int.
            return T(); 
        } else {
            return Item->value; 
        }
    }

    // Update the value of a specific node
    bool UpdateItem(int Index, T NewValue) {
        Node *Item = GetNode(Index);

        if(Item == NULL) return false;

        Item->value = NewValue;
        return true;
    }
};