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

            // Establece el siguiente nodo.
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
    
    unsigned int size() const {
        return sz;
    }

//verifica si la lista esta vacia
    bool empty() const {
        return first == nullptr;
    }

    void push(const T& elem){
    Node *n = newNode(elem);
        if (empty()){
            first = n;
            last = n;
            sz++;
        } else {
            n -> setNext(first);
            first = n;
            sz++;
        }
        }

    }

};

main(){
}