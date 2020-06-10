#include <cstddef>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Node
{
    public:
        int val;
        Node* next;
        Node (int val): val(val), next(NULL) {};
        Node (int val, Node* next): val(val), next(next) {};
        bool haveNext()
        {
            return this -> next != NULL;
        }
};

class MyLinkedList {
public:
    Node* head;
    /** Initialize your data structure here. */
    MyLinkedList() {
        head = NULL;
    }
    
    void print_list()
    {
        Node* n = head; 
        while (n != NULL)
        {
            cout << n -> val << " ";
            n = n -> next;
        }
            
        cout << "\n";
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        int con = 0;
        Node* n = this -> head;
        while (n -> haveNext() && con != index)
        {
            n = n -> next;
            con ++;
        }
        if (n == NULL) return -1;
        
        if (con == index)
            return n -> val;
        
        return -1;   
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        Node* new_head = new Node(val, this -> head);
        head = new_head;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        Node* n = this -> head;
        while (n -> haveNext())
        {
            n = n -> next;
        }
        Node* new_tail = new Node(val);
        n -> next = new_tail;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if (index == 0)
        {
            addAtHead(val);
            return;
        }
            
        int con = 0;
        Node* n = this -> head;
        while (n != NULL && ++con != index)
        {
            n = n -> next;
        }
        
        if (con != index) return;
        
        Node* new_node;
        if (n -> haveNext())
            new_node = new Node(val, n -> next);
        
        else
            new_node = new Node(val);
        
        n -> next = new_node;
        
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        int con = 0;
        Node* n = this -> head;
        if (index == 0)
        {
            if (this -> head -> haveNext())
                this -> head = this -> head -> next;
            else 
                this -> head = NULL;
            return;
        }
        
        while (n!= NULL && ++con != index)
        {
            n = n -> next;
        }
        
        if (con != index || n -> next == NULL) return;
        
        else if (n -> next -> next != NULL)    
            n -> next = n -> next -> next;
        
        else
            n -> next = NULL;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */


