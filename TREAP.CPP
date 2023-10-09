/*
Un Treap es una estructura de datos que combina propiedades de dos estructuras diferentes:
 un árbol binario de búsqueda (BST) y una cola de prioridad (heap). Esta estructura de datos se utiliza 
 principalmente para mantener un conjunto de elementos y permitir operaciones de inserción, eliminación y
  búsqueda en tiempo logarítmico en promedio. Aquí tienes todo lo que debes saber sobre la estructura Treap:

Estructura de un nodo Treap:

Cada nodo en un Treap contiene dos valores: un valor de clave y una prioridad.
El valor de clave se utiliza para organizar los elementos en un orden específico (generalmente, de acuerdo con 
las propiedades de un BST).
La prioridad se utiliza para mantener la propiedad de heap, 
donde los nodos tienen prioridades asignadas de acuerdo con una distribución aleatoria y cumplen las propiedades 
de un árbol binario.
Propiedades del Treap:

La propiedad BST asegura que todos los nodos en el subárbol izquierdo de un nodo dado tengan claves
 menores que la clave del nodo y que todos los nodos en el subárbol derecho tengan claves mayores.
La propiedad de heap asegura que la prioridad de cualquier nodo sea mayor o igual que las prioridades 
de sus hijos.
Dado que las prioridades se asignan de manera aleatoria, la estructura Treap combina las propiedades
 de un BST y un heap con probabilidades.
Operaciones fundamentales:

Inserción: Para insertar un nuevo elemento en el Treap, se crea un nuevo nodo con la clave y 
la prioridad correspondientes. Luego, se inserta el nodo como lo harías en un BST basado en claves y se ajusta
 la estructura para cumplir la propiedad de heap utilizando rotaciones.
Eliminación: Para eliminar un elemento del Treap, se busca el nodo con la clave deseada en el BST
 y se elimina. Luego, se ajusta la estructura para cumplir la propiedad de heap mediante rotaciones.
Búsqueda: La búsqueda en un Treap se realiza de la misma manera que en un BST, utilizando comparaciones de claves.
Eficiencia:

En promedio, las operaciones de inserción, eliminación y búsqueda en un Treap tienen 
una complejidad de tiempo de O(log N), donde N es el número de elementos en la estructura.
Sin embargo, en el peor caso, la complejidad de tiempo puede ser O(N) si las prioridades
 se asignan de manera que el Treap se convierte en una estructura lineal.
Aplicaciones:

Los Treaps son útiles en situaciones donde es necesario mantener un conjunto de elementos
 y realizar operaciones de búsqueda, inserción y eliminación eficientes.
Se utilizan en aplicaciones como la implementación de conjuntos ordenados, colas de prioridad
 y en algoritmos probabilísticos.
En resumen, un Treap es una estructura de datos versátil que combina las propiedades de un árbol 
binario de búsqueda y una cola de prioridad para mantener un conjunto de elementos de manera eficiente.
 Su rendimiento promedio es excelente, pero es importante tener en cuenta el factor aleatorio en la 
 asignación de prioridades para evitar casos extremos.*/

 
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

struct TreapNode {
    int key;
    int priority;
    TreapNode* left;
    TreapNode* right;

    TreapNode(int k) : key(k), priority(rand()), left(nullptr), right(nullptr) {}
};

class Treap {
public:
    Treap() : root(nullptr) {
        srand(time(0));
    }

    void insert(int key) {
        root = _insert(root, key);
    }

    void remove(int key) {
        root = _remove(root, key);
    }

    void inorder() {
        _inorder(root);
    }

private:
    TreapNode* root;

    TreapNode* _rotateRight(TreapNode* y) {
        TreapNode* x = y->left;
        y->left = x->right;
        x->right = y;
        return x;
    }

    TreapNode* _rotateLeft(TreapNode* x) {
        TreapNode* y = x->right;
        x->right = y->left;
        y->left = x;
        return y;
    }

    TreapNode* _insert(TreapNode* root, int key) {
        if (!root) {
            return new TreapNode(key);
        }

        if (key <= root->key) {
            root->left = _insert(root->left, key);
            if (root->left->priority > root->priority) {
                root = _rotateRight(root);
            }
        } else {
            root->right = _insert(root->right, key);
            if (root->right->priority > root->priority) {
                root = _rotateLeft(root);
            }
        }

        return root;
    }

    TreapNode* _remove(TreapNode* root, int key) {
        if (!root) {
            return root;
        }

        if (key < root->key) {
            root->left = _remove(root->left, key);
        } else if (key > root->key) {
            root->right = _remove(root->right, key);
        } else {
            if (!root->left) {
                TreapNode* temp = root->right;
                delete root;
                root = temp;
            } else if (!root->right) {
                TreapNode* temp = root->left;
                delete root;
                root = temp;
            } else {
                if (root->left->priority > root->right->priority) {
                    root = _rotateRight(root);
                    root->right = _remove(root->right, key);
                } else {
                    root = _rotateLeft(root);
                    root->left = _remove(root->left, key);
                }
            }
        }

        return root;
    }

    void _inorder(TreapNode* root) {
        if (root) {
            _inorder(root->left);
            cout << "Key: " << root->key << ", Priority: " << root->priority << endl;
            _inorder(root->right);
        }
    }
};

int main() {
    Treap treap;
    int keys[] = {50, 30, 70, 20, 40, 60, 80};

    for (int key : keys) {
        treap.insert(key);
    }

    cout << "Inorder Traversal:" << endl;
    treap.inorder();

    treap.remove(20);
    treap.remove(40);

    cout << "\nAfter deleting 20 and 40:" << endl;
    treap.inorder();

    return 0;
}
