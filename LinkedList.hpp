#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <string>
#include <stdexcept>
#include "ChainLink.hpp"

struct Node {
    public:
    ChainLink data;
    Node *next;

    Node() {
        data = ChainLink("Gray");
        next = nullptr;
    }   

    Node (ChainLink data) {
        this->data = data;
        this->next = nullptr;
    }
};

class LinkedList {
    Node *head;

    private:
    int size() {
        int size = 0;
        Node *current = head;
        while (current != NULL) {
            size++;
            current = current->next;
        }
        return size;
    }

    public:
    LinkedList() {
        head = nullptr;
    }

    void insertAtTail(ChainLink data) {
        Node *newNode = new Node(data);
        
        if (head == NULL) {
            head = newNode;
            return;
        } else {
            Node *current = head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    ChainLink get(int index) {
        if (index < 0 || index >= size()) {
            throw std::out_of_range("Index is Invalid!");
        }

        Node *current = head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        return current->data;
    }
};

#endif // LINKEDLIST_H