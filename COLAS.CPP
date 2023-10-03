#include <iostream>
using namespace std;

template <typename T>
class List {
private:
    class Node {
    public:
        T data;
        Node* next;

        Node(const T& value) : data(value), next(nullptr) {}

         void setNext(Node* n) {
            next = n;
        }

        // Obtiene el siguiente nodo.
        Node* getNext() { 
            return next; 
        }

        // Obtiene el valor de data.
        const T& getData() { 
            return data; 
        }
    };

public:
    class Queue {
    private:
        Node* first;  // Puntero al frente de la cola
        Node* last;   // Puntero al final de la cola
        unsigned int sz;

    public:
        Queue() : first(nullptr), last(nullptr) {}

        ~Queue() {
            while (!empty()) {
                dequeue();
            }
        }


        void enqueue(const T& value) {
            Node* newNode = new Node(value);
            if (empty()) {
                first = last = newNode;
            } else {
                last->next = newNode;
                last = newNode;
            }
        }

        void dequeue() {
            if (!empty()) {
                Node* temp = first
                ;
                first= first->next;
                delete temp;
                if (first== nullptr) {
                    last = nullptr;
                }
            }
        }

        bool empty() const {
            return first == nullptr;
        }

        size_t size() const {
            size_t count = 0;
            Node* current = first;
            while (current != nullptr) {
                count++;
                current = current->next;
            }
            return count;
        }

        void print()const {
        if(empty()) {
            cout << "<>" << endl;
        }
         else {
            Node* n = first;
            cout << "<";
            while(n != nullptr) {
                cout << " " << n-> getData();
                n = n->getNext();
            }
            cout << ">" << endl;
        }
    }

    const T& front() const {
    if (empty()) {
        cout << "La cola esta vacia" << endl;
    }
    return first->getData();
    }
    };
};

int main() {
    List <int>::Queue myQueue; 

    myQueue.enqueue(1);
    myQueue.enqueue(2);
    myQueue.enqueue(3);
    //const int& f = myQueue.front();
    myQueue.print();
    return 0;
}
