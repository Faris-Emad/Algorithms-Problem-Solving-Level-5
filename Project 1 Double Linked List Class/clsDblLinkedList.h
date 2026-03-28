/*
    this is my solution befor i see  the doctor's solution
        #pragma once
        #include <iostream>
        #include <string>
        using namespace std;


        template <typename T>
        class Node{
            public:
                T value;
                Node* next;
                Node* prev;
        };
        template <typename T>
        class clsDblLinkedList {
            private:
                Node<T>* head = NULL;
            public:
                
                void InsertAtBeginning( T Value) {
                    /*
                            1-Create a new node with the desired value.
                            2-Set the next pointer of the new node to the current head of the list.
                            3-Set the previous pointer of the current head to the new node.
                            4-Set the new node as the new head of the list.
                    
                    Node<T>* new_node = new Node<T>();

                    //insert the date
                    new_node->value = Value;
                    new_node->next = head;
                    new_node->prev = NULL;

                    if(head != NULL)
                        head->prev = new_node;

                    head = new_node;
                }
                void InsertAfter(Node<T>* current,T value) {

                    /*  1 - Create a new node with the desired value.
                        2-Set the next pointer of the new node to the next node of the current node.
                        3-Set the previous pointer of the new node to the current node.
                        4-Set the next pointer of the current node to the new node.
                        5-Set the previous pointer of the next node to the new node(if it exists).
                    
                
                    if (current == NULL) return;
                    Node<T>* newNode = new Node<T>();
                    newNode->value = value;
                    newNode->next = current->next;
                    newNode->prev = current;

                    if (current->next != NULL) {
                        current->next->prev = newNode;
                    }
                    current->next = newNode;
                }
                void InsertAtEnd(T Value) {
                    Node<T>* new_node = new Node<T>();
                    new_node->value = Value;
                    new_node->next = NULL;

                    if(head == NULL) {
                        head = new_node;
                        return;
                    }

                    Node<T>* LastNode = head;
                    while (LastNode->next != NULL) {
                        LastNode = LastNode->next;
                    }
                    
                    LastNode->next = new_node;
                    new_node->prev = LastNode;
                    return;
                }
                
                void DeleteNode(Node<T>* &NodeToDelete) {
                    /*
                        1-Set the next pointer of the previous node to the next pointer of the current node.
                        2-Set the previous pointer of the next node to the previous pointer of the current node.
                        3-Delete the current node.
                    
                    if(head == NULL || NodeToDelete == NULL)
                        return;
                    if (head == NodeToDelete) {
                        head = NodeToDelete->next;
                    }
                    if (NodeToDelete->next != NULL) {
                        NodeToDelete->next->prev = NodeToDelete->prev;
                    }
                    if (NodeToDelete->prev != NULL) {
                        NodeToDelete->prev->next = NodeToDelete->next;
                    }
                    delete NodeToDelete;
                }

                void DeleteFirstNode() {
                    /*
                        1-Store a reference to the head node in a temporary variable.
                        2-Update the head pointer to point to the next node in the list.
                        3-Set the previous pointer of the new head to NULL.
                        4-Delete the temporary reference to the old head node.
                    
                    if(head == NULL) return;
                    Node<T>* Current = head;
                    head = head->next;
                    if (head != NULL) {
                        head->prev = NULL;
                    }
                    delete Current;
                }

                void DeleteLastNode(){
                    /*
                        1-Traverse the list to find the last node.
                        2-Set the next pointer of the second-to-last node to NULL.
                        3-Delete the last node.
                    
                    if (head == NULL) {
                        return;
                    }
                    if (head->next == NULL) {
                        delete head;
                        head = NULL;
                        return;
                    }
                    Node<T>* current = head;
                    //we need to find the node before the last node.
                    while (current->next->next != NULL) {
                        current = current->next;
                    }
                    Node<T>* temp = current->next;
                    current->next = NULL;
                    delete temp;
                    
                    
                }


                Node<T>* Find(T value) {
                    Node<T>* current = head; 
                    while(current != NULL) {
                        if(current->value == value) {
                            return current;
                        } 
                        current = current->next;
                    }
                    return NULL;
                }

                void PrintList() {
                    Node<T>* current = head; 
                    while (current != NULL) {
                        cout << current->value << " ";
                        current = current->next;
                    }
                }

        };

*/

#pragma once
#include <iostream>
using namespace std;


template <class T>
class clsDblLinkedList
{

public:

    class Node
    {

    public:
        T value;
        Node* next;
        Node* prev;
    };

    Node* head = NULL;

    void InsertAtBeginning(T value)
    {

        /*
            1-Create a new node with the desired value.
            2-Set the next pointer of the new node to the current head of the list.
            3-Set the previous pointer of the current head to the new node.
            4-Set the new node as the new head of the list.
        */

        Node* newNode = new Node();
        newNode->value = value;
        newNode->next = head;
        newNode->prev = NULL;

        if (head != NULL) {
            head->prev = newNode;
        }
        head = newNode;
       

    }

    // Print the linked list
    void PrintList()

    {
        Node* Current = head;

        while (Current != NULL) {
            cout << Current->value << " ";
            Current = Current->next;
        }
        cout << "\n";
       

    }

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

    void InsertAfter(Node* current, T value) {


        /*  1 - Create a new node with the desired value.
             2-Set the next pointer of the new node to the next node of the current node.
             3-Set the previous pointer of the new node to the current node.
             4-Set the next pointer of the current node to the new node.
             5-Set the previous pointer of the next node to the new node(if it exists).
        */

        Node* newNode = new Node();
        newNode->value = value;
        newNode->next = current->next;
        newNode->prev = current;

        if (current->next != NULL) {
            current->next->prev = newNode;
        }
        current->next = newNode;
     

    }

    void InsertAtEnd(T value) {

        /*
            1-Create a new node with the desired value.
            2-Traverse the list to find the last node.
            3-Set the next pointer of the last node to the new node.
            4-Set the previous pointer of the new node to the last node.
        */


        Node* newNode = new Node();
        newNode->value = value;
        newNode->next = NULL;
        if (head == NULL) {
            newNode->prev = NULL;
            head = newNode;
        }
        else {
            Node* current = head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = newNode;
            newNode->prev = current;
        }
     

    }

    void DeleteNode(Node*& NodeToDelete) {

        /*
            1-Set the next pointer of the previous node to the next pointer of the current node.
            2-Set the previous pointer of the next node to the previous pointer of the current node.
            3-Delete the current node.
        */
        if (head == NULL || NodeToDelete == NULL) {
            return;
        }
        if (head == NodeToDelete) {
            head = NodeToDelete->next;
        }
        if (NodeToDelete->next != NULL) {
            NodeToDelete->next->prev = NodeToDelete->prev;
        }
        if (NodeToDelete->prev != NULL) {
            NodeToDelete->prev->next = NodeToDelete->next;
        }
        delete NodeToDelete;

    
    }

    void DeleteFirstNode()
    {

        /*
            1-Store a reference to the head node in a temporary variable.
            2-Update the head pointer to point to the next node in the list.
            3-Set the previous pointer of the new head to NULL.
            4-Delete the temporary reference to the old head node.
        */

        if (head == NULL) {
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        delete temp;
    
    }

    void DeleteLastNode() {

        /*
            1-Traverse the list to find the last node.
            2-Set the next pointer of the second-to-last node to NULL.
            3-Delete the last node.
        */

        if (head == NULL) {
            return;
        }

        if (head->next == NULL) {
            delete head;
            head = NULL;
            return;
        }

        Node* current = head;
        // we need to find the node before last node.
        while (current->next->next != NULL)
        {
            current = current->next;
        }

        Node* temp = current->next;
        current->next = NULL;
        delete temp;
       
    }

};

