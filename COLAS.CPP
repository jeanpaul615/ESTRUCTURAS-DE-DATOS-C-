#include <iostream>

template<typename T>
class List {
private:
    // Clase interna que representa un nodo en la lista enlazada.
    class Node {
    public:
        T data;
        Node* next;

        Node(const T& elem) : data(elem), next(nullptr) {}
    }; 

    Node* front; // Puntero al frente de la lista
    Node* back;  // Puntero al final de la lista

public:
    // Constructor por defecto de la lista.
    List() : front(nullptr), back(nullptr) {}

    // Clase interna que representa una cola en la lista enlazada.
    class Queue {
    private:
        List<T> storage;
    public:
        // Constructor por defecto de la cola.
        Queue() : storage() {}
        
    List() {
        first = nullptr; //Constructor inicializa la lista vacia
        last = nullptr;
        sz = 0;
    }
    
    List(const List& other) {
        first = nullptr;
        last = nullptr;
        sz = 0;

        Node* current = other.first;
        while (current != nullptr) {
            push_back(current->getData());
            current = current->getNext();
        }
    }

    ~List(){
        Node* actual = first;
        while(actual != nullptr){
            Node* temporal = actual;
            first = first -> getNext();
            delete temporal;

            }

    }
    
    unsigned int size() const {
        return sz;
    }

//verifica si la lista esta vacia
    bool empty() const {
        return first == nullptr;
    }
    }
};