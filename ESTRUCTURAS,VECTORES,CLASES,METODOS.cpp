#include <iostream>
#include <string>
#include <vector>
#include <cassert>
using namespace std;
/**
 * 
 * waste(retorna cuantas posiciones hay sin utilizar)
 * pop_back(elimina el ultimo)
 * push_front(int e:agrega e como primer elemento)
 * pop_front(elimina el primer elemento)
 * insert(p,desplaza e insertando e en la posicion p) corre los demas
 * remove(p, elimina en la posicion)
 * shrink_to_fit(el vector se acomoda a la memoria)
 * at (p,e, at intercambia, no reemplaza como insert) sobreescribe
 * insert(posicion p,const vector & v)
 * 
 * Arreglos:
 * 1) Almacenan una secuencia de elementos del mismo tipo.
 * 2) De tamaño fijo: una vez declarados su capacidad no se puede ampliar.
 * 3) Acceso a elementos por su posición es constante.
 *
 * Vectores (arreglos dinámicos):
 * 1) Almacenan una secuencia de elementos del mismo tipo.
 * 2) Dinámicos: se acomodan a la cantidad de elementos que el usuario
 *      de la estructura quiera.
 * 3) Acceso a elementos por su posición es constante.
 *
 * Operaciones:
 * 1) Construcción
 * 2) acceso por posición
 * 3) Inserción por el final
 * 4) Eliminar elemento al final
 * 5) Acceder al tamaño
 * 6) ...
 *
 */


template <typename T>

class Vector {
private:
  unsigned int capacity; //capacidad maxima del vector
  unsigned int sz; //cantidad de elementos que hay en el vector
  T *storage; //se utiliza para almacenar los elementos en el vector, normalmente apunta a la posicion inicial del vector

public:
  Vector() {
    capacity = 5;
    sz = 0;
    storage = new T[capacity];
  }

  
 
  Vector(unsigned int count, const T& value){
    capacity = count;
    sz = count;
    storage = new T[capacity];
    for(unsigned int i = 0; i < count; i++){
      storage[i] = value;
    }  
  }   
  unsigned int size(){ 
    return sz; 
    }



private:  
  void resize() {
    cout << "con resize, for the push_back" << endl;

    int newcapacity = sz * 2;
    T *newstorage = new T[newcapacity];
    for (int i = 0; i < sz; i++) {
      newstorage[i] = storage[i];
    }
    delete[] storage;
    storage = newstorage;
    capacity = newcapacity;
  }

  void resize2(int SizeVector) {
    cout << "con resize2, only one for the insert " << endl;
    int newcapacity = size() + SizeVector;
    T *newstorage = new T[newcapacity];
    for (int i = 0; i < sz; i++) {
      newstorage[i] = storage[i];
    }
    delete[] storage;
    storage = newstorage;
    capacity = newcapacity;
  }

public:
  void push_back(const T& e) {
    if(sz == capacity) {
      resize();
    }
    storage[sz] = e;
    return sz++;
  }

  void print() {
    if (size() == 0) {
      cout << "<>" << endl;
    } 
    else {
      cout << "<";
      for (int i = 0; i < size(); i++) {
        cout << " " << storage[i];
      }
        cout << ">" << endl;
    }
  }

  T waste(){
    int n;
    if(sz <= capacity){
      n = capacity - sz;
        cout << "waste:  "<<n;
    }
    return n;
  }



  void pop_back(){
    if(size() > 0){
      sz--;
    }
    else{
      cout <<"Vector vacio"<<endl;
    }
   }

  void push_front(int e){
    if(size() == capacity){
      resize();
    }
    for(int i = 1;i<size();i++){
        storage [i] = storage [i+1];
    }
    storage [0] = e;
    sz--;

  }


  void pop_front(){
    for (int i = 0; i < sz - 1; i++) {
      storage[i] = storage[i + 1];
    }
    sz--;
  }




  void insert(int *p, int e){
    int positioninvector = 3;
    *p = storage[positioninvector];
    if(capacity <= size()){
      //resize2();
    }
    for (int i = size(); i > *p; i--) {
        storage[i] = storage[i - 1];
    }
    storage[*p] = e;
    sz++;
  }


  void remove(int *p){
    int positioninvector = 0;
    p = &positioninvector;
    
    for (positioninvector;positioninvector < sz;positioninvector++){
      storage[*p] = storage[*p+1];
    }
    sz--;
    }


  //con storage y utilizando el delete[], crea un new storage, copiamos elementos, delete y reasiganmos size y capacity.
  void shrink_to_fit(){
    int newcapacity = sz;
    int *newstorage = new int[newcapacity];
    if (capacity > size()){

      for (int i = 0; i < sz; i++) {
        newstorage[i] = storage[i];
      }
        delete[] storage;
        storage = newstorage;
        capacity = newcapacity;
    }
  }


  const T& at(unsigned int pos) const //se utiliza para encontrar sin modificar 
  {
    return storage[pos];


  }

  T& at(unsigned int pos)//se utiliza para modificar
  {
    return storage[pos];
  }


//se hace el resize con la cantidad de elementos a ingresar
  void insertUsingOtherVector(int *p,const vector <int> &v){
    resize2(v.size());
    for(int i = 0; i<v.size() ;i++){
      insert(p,v[i]);
    }

  }
  


};

int main(){


  Vector <int> b;
  //Vector a insertar en el metodo InstertUsingOtherVector
  vector<int> InsertElement = {4, 5, 7, 9, 1, 3, 7, 6, 5, 4};

    //PUNTERO USADO COMO PARAMETRO EN ALGUNAS FUNCIONES
  int *p;
  for(unsigned i = 0;i<7; i++){
    b.push_back(i);
  }

  //b.pop_back();
  //b.push_back(5);
  //b.pop_front();
  //b.push_front();
  //b.insert(p,98);
  //b.remove(p);
  //b.shrink_to_fit();
  //b.insertUsingOtherVector(p,InsertElement);
  //b.at(6) = 32; modifica en la posicion 6, con el 32
  //const int& Element = b.at(6); //accede a el elemento en la posicion 6
  b.print();
  //b.waste();
}



