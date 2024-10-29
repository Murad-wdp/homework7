#include <iostream>
#include <string>
using namespace std;

class SingleLinkedList {
    class Node {
    public:
        Node* next;
        string data;
        Node(const string& data) {
            this->data = data;
            this->next = nullptr;
        }
    };

    Node* head = nullptr;

public:
    void AddBegin(const string data) {
        Node* node = new Node(data);
        node->next = head;
        head = node;
    };

    void AddEnd(const string& data) {
        Node* node = new Node(data);
        if (head == nullptr) {
            head = node;
            return;
        }
        Node* tail = head;
        while (tail->next != nullptr) {
            tail = tail->next;
        }
        tail->next = node;
    };

    void DeleteBegin() {
        if (head == nullptr) return;
        Node* temp = head;
        head = head->next;
        delete temp;
    };

    void DeleteEnd() {
        if (head == nullptr) return;

        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }

        Node* current = head;
        while (current->next->next != nullptr) {
            current = current->next;
        }

        delete current->next;
        current->next = nullptr;
    };

    void DeleteByValue(const string& value) {
        if (head == nullptr) return;

        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* current = head;
        while (current->next != nullptr && current->next->data != value) {
            current = current->next;
        }

        if (current->next != nullptr) {
            Node* temp = current->next;
            current->next = current->next->next;
            delete temp;
        }
    };

    void Print() {
        Node* copy_head = head;
        while (copy_head != nullptr) {
            cout << copy_head->data << endl;
            copy_head = copy_head->next;
        }
    }
};

int main() {
    SingleLinkedList list;

   
    list.AddEnd("Apple");
    list.AddEnd("Banana");
   

    cout << "Current List:" << endl;
    list.Print();

    
    list.DeleteBegin();
    cout << "\nAfter deleting the first element:" << endl;
    list.Print();

   
    list.DeleteEnd();
    cout << "\nAfter deleting the last element:" << endl;
    list.Print();

    list.DeleteByValue("Banana");
    cout << "\nAfter deleting 'Banana':" << endl;
    list.Print();

   
    list.DeleteByValue("Grapes");
    cout << "\nAfter trying to delete 'Grapes' (not in list):" << endl;
    list.Print();

    return 0;
}
