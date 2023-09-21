#include <iostream>

template<typename T>
class List {
private:
    // Clase interna que representa un nodo en la lista enlazada.
    class Node {
    public:
        T data;
        Node* next;

        Node(const T& item) : data(item), next(nullptr) {}
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
    };
};