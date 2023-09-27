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
    public:
        // Constructor por defecto del nodo.
        Node() { 
            data = T();  // Inicializa data con un valor por defecto de tipo T.
            next = nullptr;  // Inicializa el puntero next como nulo.
        }
        
        // Constructor que acepta un valor de tipo T.
        Node(const T& d) {
            data = d;   // Asigna el valor proporcionado a data.
            next = nullptr;  // Inicializa el puntero next como nulo.
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
    unsigned int size() const {
        return sz;
    }

//verifica si la lista esta vacia
    bool empty() const {
        return first == nullptr;
    }

    void push_back(const T& elem) {
        Node* n = new Node(elem);
        if(empty()) {
            first = n;
            last = n;
            sz++;
        } else {
            last->setNext(n);
            last = n;
            sz++;
        }
    }

    void push_front(const T& elem){
        Node* n = new Node(elem);
        if(empty()){
            first = n;
            last = n;
            sz++;
        }
        else{
            n -> setNext(first);
            first = n;
            sz++;
        }
    }

    //Elimina el ultimo elemento
    void pop_back(){
        if(empty()){
            cout << "La lista esta vacia"<<endl;
        }
        if(first == last){
          cout << "1 ELEMENTO";
          delete last;
          first = nullptr;
          last = nullptr;
          sz = 0;
          return;
        }        
        Node* actual = first;
        while (actual->getNext() != last){
          //se accede al penultimo nodo en la lista
          actual = actual -> getNext();
        }
        //elimina el ultimo nodo y ajusta el penultimo nodo.
        delete last;
        last = actual;
        last ->setNext(nullptr);
        sz--;
      }

      //Elimina el primer elemento
      void pop_front(){
        if (first = last){
          delete first;
          first = nullptr;
          last = nullptr;
          sz = 0;
          return;
        }
        if (empty()){
          cout << "La lista esta vacia";
          return;
        }
        Node* actual = first;
        first = first -> getNext();
        delete actual;
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

void swap(unsigned int pos1, unsigned int pos2) {
    if (pos1 == pos2 || pos1 >= sz || pos2 >= sz) {
        // No se puede intercambiar si las posiciones son iguales o están fuera de rango.
        return;
    }

    Node* prev1 = nullptr;
    Node* current1 = first;
    for (unsigned int i = 0; i < pos1; i++) {
        prev1 = current1;
        current1 = current1->getNext();
    }

    Node* prev2 = nullptr;
    Node* current2 = first;
    for (unsigned int i = 0; i < pos2; i++) {
        prev2 = current2;
        current2 = current2->getNext();
    }

    // Actualiza los punteros next para intercambiar los nodos
    if (prev1) {
        prev1->setNext(current2);
    } else {
        first = current2;
    }

    if (prev2) {
        prev2->setNext(current1);
    } else {
        first = current1;
    }

    Node* temp = current1->getNext();
    current1->setNext(current2->getNext());
    current2->setNext(temp);
  }
`




};


int main() {
    List<double> x;
    //List<double> InsertElement = {4.5 , 3.2};

    //cout << x.empty() << endl;
    //cout << x.size() << endl;
    for(int i  = 0; i<6;i++){
        x.push_back(i);
    }
    //x.push_front(1.1);
    //x.pop_back();
    //x.pop_front();
    //x.insert(1, 8);
    /*const double& Element = x.at(5);
    cout << Element;*/
    //x.insert(2,5);
    //x.remove(5);
    x.swap(2, 4);
    x.print();
} 
//QUEDA FALTANDO LA FUNCION INSERTLIST();

/*tiempo -> complejidad temporal -> cuanto tarda mi programa?
*espacial -> complejidad espacial -> cuanta memoria ocupa?
*el peor caso = O
*el promedio =  θ
*el mejor = Ω

*T(n) = 7 + T(n-2)+ T(n-1)
implementar potenciacion, con division de potencias*/