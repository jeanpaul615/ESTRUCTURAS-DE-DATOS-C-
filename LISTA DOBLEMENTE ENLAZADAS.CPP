//para acceder al next(getNext) y para asignarle algo setNext(Node *n);
#include <iostream>

using namespace std;

template<typename T>
class List {
private:
    // Clase interna que representa un nodo en la lista enlazada.
    class Node {
    private:
        T data;       // Almacena el valor de tipo T en el nodo.
        Node* next;   // Puntero al siguiente nodo.
        Node* prev;   // Puntero al nodo anterior.

    public:
        // Constructor por defecto del nodo.
        Node() { 
            data = T();  // Inicializa data con un valor por defecto de tipo T.
            next = nullptr;  // Inicializa el puntero next como nulo.
            prev = nullptr;
        }


        // Constructor que acepta un valor de tipo T.
        Node(const T& d) {
            data = d;   // Asigna el valor proporcionado a data.
            next = nullptr;  // Inicializa el puntero next como nulo.
        }

        // Establece el nodo anterior.
        void setPrev(Node *n){
            prev = n;
        }

        Node* getPrev(){
            return prev;
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


    };

    Node* first;           // Puntero al primer nodo de la lista.
    Node* last;            // Puntero al último nodo de la lista.
    unsigned int sz;       // Tamaño de la lista (cantidad de elementos).

public:
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

    void push_back(const T& elem) {
        Node *n = new Node(elem);
        if(empty()) {
            first = n;
            last = n;
            sz++;
        } else {
            n -> setPrev(last);
            last -> setNext(n);
            last = n;
        }
        sz++;
    }

    void push_front(const T& elem){
        Node* n = new Node(elem);
        if(empty()){
            first = n;
            last = n;
            sz++;
        }
        else{
            n-> setNext(first);
            first -> setPrev(n);
            first = n;
        }
    }

    //Elimina el ultimo elemento
    void pop_back(){
        if(empty()){
            cout << "La lista esta vacia"<<endl;
        }
        if(first == last){
          delete last;
          first = nullptr;
          last = nullptr;
          sz = 0;
          return;
        }        
        Node* actual = last -> getPrev();
        delete last;
        last = actual;
        last -> setNext(nullptr);
      }

      //Elimina el primer elemento
      void pop_front(){
        if (first == last or empty()){
          delete first;
          first = nullptr;
          last = nullptr;
          sz = 0;
          return;
        }
            Node* actual = first -> getNext();
            delete first;
            first = actual;
            first -> setPrev(nullptr);
            sz--;
      }

      void insert(T p,T e){
        Node* actual = new Node(e);
        if (p < 0 || p > sz) { // Verifica si la posición está fuera de rango.
        cout << "Posición fuera de rango."; 
        return; 
        }   
        if(empty())//si esta vacia agrega el elemento a insertar
        {
            first = actual;
            last = actual;
            sz++;
            return;
        }

        Node* current = first;
        Node* prev = nullptr;

        for(int currentPosition = 0;currentPosition < p;currentPosition++)// Recorre la lista hasta llegar a la posición deseada.
        {
          prev = current; // Actualiza el puntero del nodo anterior
          current = current -> getNext();// Avanza al siguiente nodo
        }
        prev -> setNext(actual);// El siguiente del nodo anterior apunta al nuevo nodo
        actual -> setNext(current);// El siguiente del nuevo nodo apunta al nodo actual
        sz++;
      }

      const T &at(unsigned int p)const{
      if (p < 0 || p >= sz) {
        cout << "Posición fuera de rango." <<endl;
      }
       Node* current = first;
      for(int currentPosition = 0; currentPosition < p-1;currentPosition++){
        current = current -> getNext();
      }
      return current ->getData();
      }

      void remove(unsigned int p){
        Node* current = first;
        Node* prev = nullptr;

        if(p==0){
          first = first -> getNext();
          delete current;
          sz--;
          return;
        }

        if (p < 0 || p >= sz) {
          cout << "Posición fuera de rango." <<endl;
          return;
        }
        int currentPosition = 0;
        for(currentPosition; currentPosition < p-1;currentPosition++){
          prev = current;
          current = current -> getNext();
        }
        if(currentPosition = p && current != nullptr){
          prev -> setNext(current -> getNext());// Actualiza el puntero next del nodo previo para omitir el nodo actual
          delete current;
          sz--;
          return;
        } 
        else{
          cout << "posicion fuera de rango."<<endl;
          return;

        }
      }


    /*void insert(unsigned int p, List <T>& list){
        Node *actual;
        if (p < 0 || p > sz) { // Verifica si la posición está fuera de rango.
        cout << "Posición fuera de rango."; 
        return; 
        }   
        if(empty())//si esta vacia agrega el elemento a insertar
        {
            first = actual;
            last = actual;
            sz++;
            return;
        }
        if(p<list.size()/2){
            
            for(int i = 0; i < p; i++){
                actual = actual -> getNext();

            }
            Node* prevNode = actual->getPrev();
                list.last->setNext(actual);
                list.first->setPrev(prevNode);
                prevNode->setNext(list.first);
                actual->setPrev(list.last);
                sz = sz + list.sz;
                list.first = nullptr;
                list.last = nullptr;
                list.sz=0;
        }
        if(p>list.size()/2){
            
            for(int i = 0; i < p; i++){
                actual = actual -> getPrev();

            }
                Node* prevNode = actual->getPrev();
                list.last->setNext(actual);
                list.first->setPrev(prevNode);
                prevNode->setNext(list.first);
                actual->setPrev(list.last);
                sz = sz + list.sz;
                list.first = nullptr;
                list.last = nullptr;
                list.sz=0;
        }

    }*/
    void print() const {
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

};


int main() {
    List<double> x;
    List<double> InsertElement;
InsertElement.push_front(1);
InsertElement.push_front(1);
InsertElement.push_front(1);
InsertElement.push_front(1);
InsertElement.push_front(1);
InsertElement.push_front(1);
    //cout << x.empty() << endl;
    //cout << x.size() << endl;
    for(int i = 0;i<5;i++){
        x.push_back(i);
    }
    //x.push_front(1.1);
    
    /*const double& Element = x.at(5);
    cout << Element;*/
    //x.insert(2,5);
    //x.remove(5);
    InsertElement.print();
} 
//QUEDA FALTANDO LA FUNCION INSERTLIST();

/*tiempo -> complejidad temporal -> cuanto tarda mi programa?
*espacial -> complejidad espacial -> cuanta memoria ocupa?
*el peor caso = O
*el promedio =  θ
*el mejor = Ω

*T(n) = 7 + T(n-2)+ T(n-1)
implementar potenciacion, con division de potencias*/