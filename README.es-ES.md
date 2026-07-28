****
### Declaración
He integrado la mayoría de los problemas de algoritmos de `Guía de Revisión de Estructuras de Datos Wangdao 2021` y `Notas de Alta Puntuación de Estructuras de Datos Tianqin 2019` con fines de aprendizaje, proporcionando las soluciones y ejemplos correspondientes.
No se garantiza que todas las soluciones sean correctas y sin errores; se proporcionan únicamente como referencia para el aprendizaje. No utilizar para fines comerciales. En caso de infracción de derechos, por favor contacte para su eliminación.
Si consideras que este repositorio te ha sido útil, ¡no dudes en darle una estrella (star)!!! ¡Gracias!!!

### Índice
* [1. Estructuras de Datos Wangdao](#1-------)
  + [1.1 Configuración del Entorno](#11-----)
  + [1.2 data_struct/wangdao](#12-data-struct-wangdao)
  + [1.3 Resumen de Ejercicios](#13------)
    - [1.3.1 Listas Lineales](#131----)
    - [1.3.2 Pilas y Colas](#132-----)
    - [1.3.3 Árboles Binarios](#133----)
    - [1.3.4 Ordenamiento](#134---)
  + [1.4 Referencias](#14---)
* [2. Notas de Alta Puntuación Tianqin 2019](#2-------2019)
* [3. Essential C++](#3-essential-c--)
* [4. Práctica Categorizada de LeetCode (Sin tiempo por el momento)](#4-leetcode-------------)
   - [`Arreglos`](#----)
****
#### 1. Estructuras de Datos Wangdao
##### 1.1 Configuración del Entorno
+ Versión del compilador
```bash
g++ --version

g++ (Ubuntu 5.4.0-6ubuntu1~16.04.9) 5.4.0 20160609
Copyright (C) 2015 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
```
##### 1.2 data_struct/wangdao
+ Compilación
```c
g++ -o ch02.o ch02.cpp ch02_linear_table/*.cpp
g++ -o ch03.o ch03.cpp ch03_stack_queue/*.cpp
g++ -o ch05.o ch05.cpp ch05_tree/*.cpp
g++ -o ch08.o ch08.cpp ch08_sort/*.cpp -std=c++11
```
+ Estructura de Directorios
```
├── README.md
├── ch02.cpp
├── ch02_linear_table (Listas secuenciales, Listas enlazadas simples)
│   ├── LinkList.cpp
│   ├── LinkList.hpp
│   ├── SqList.cpp
│   ├── SqList.hpp
│   ├── exercises.cpp
│   └── exercises.hpp
├── ch03.cpp
├── ch03_stack_queue (Pilas, Colas)
│   ├── SqQueue.cpp
│   ├── SqQueue.hpp
│   ├── SqStack.cpp
│   ├── SqStack.hpp
│   ├── exercises.cpp
│   └── exercises.hpp
├── ch05.cpp
├── ch05_tree (Árboles binarios, Árboles binarios de búsqueda, Árboles, Bosques)
│   ├── BiTree.cpp
│   ├── BiTree.hpp
│   ├── BinarySearchTree.cpp
│   ├── BinarySearchTree.hpp
│   ├── ThreadTree.cpp
│   ├── ThreadTree.h
│   ├── Tree.cpp
│   ├── Tree.hpp
│   ├── exercises.cpp
│   └── exercises.hpp
├── ch08.cpp
├── ch08_sort (Inserción, Intercambio, Selección, Mezcla)
    ├── exercises.cpp
    ├── exercises.hpp
    ├── sort.cpp
    └── sort.hpp
```
##### 1.3 Resumen de Ejercicios
###### 1.3.1 Listas Lineales
> Ver detalles en: data_struct/wangdao/ch02_linear_table/exercises.hpp

+ Ejercicio 2.2 Implementación secuencial de listas lineales p19-p21
```c
void Reverse(SqList &L);                                // 2. Invertir todos los elementos de la lista secuencial L
void Reverse(ElemType A[], int m, int n, int size);     // 8. Intercambiar posiciones en una lista secuencial de arreglos
                                                        // 10. Desplazar circularmente a la izquierda p (0<p<n) posiciones la secuencia en R
void del_x_2(SqList &L,ElemType x);                     // 3. Eliminar todos los elementos de valor x en la lista lineal
bool Delete_Same(SqList& L);                            // 6. Eliminar elementos duplicados de una lista secuencial ordenada
bool Del_s_t(SqList &L, ElemType s, ElemType t);        // 4. Eliminar elementos entre s y t (s<t) de una lista secuencial ordenada
bool Del_s_t2(SqList &L, ElemType s, ElemType t);       // 5. Eliminar elementos entre s y t (s<t) de una lista secuencial
bool Merge(SqList A, SqList B, SqList &C);              // 7. Combinar dos listas secuenciales ordenadas en una nueva lista ordenada
void SearchExcgIst(ElemType A[], int n, ElemType x);    // 9. Buscar elemento x en una lista lineal ordenada ascendentemente
int MSearch(int A[],int B[],int n);                     // 11. Encontrar la mediana de dos secuencias A y B.
double MSearch1(int A[], int m, int B[],int n);
int MSearch2(int A[],int B[],int n);                    /** ❌ */
bool Del_Min(SqList &L, ElemType &value);               // 1. Eliminar el elemento con el valor mínimo de la lista secuencial
int Majority (int A[], int n);                          // 12. Encontrar el elemento mayoritario del arreglo A
int findMissMin(int A[] , int n);                       // 13. Encontrar el entero positivo más pequeño que no aparece en el arreglo
```

+ Ejercicio 2.2 Representación encadenada de listas lineales p40-p44
```c
LinkList Search_Lst_Common(LinkList L1, LinkList L2);   // 8. Algoritmo para encontrar el nodo común entre dos listas simples.
LNode* find_addr(LNode *strl , LNode *str2);            // 22. Encontrar la posición inicial del sufijo común de dos listas apuntadas por str1 y str2
int Search_k(LinkList list, int k);                     // 21. Buscar el nodo en la k-ésima posición desde el final (k es entero positivo)
LNode* FindLoopStart(LNode *head);                      // 24. Determinar si una lista tiene un ciclo; si es así, encontrar y retornar el punto de entrada, sino retornar NULL.
void change_list(LNode*&h);                             // 25. Convertir lista simple {a1,a2,··· ,an} en {a1,an,a2,an-1,a3,an-2,···}
void Del_X_1(LinkList &L, ElemType x);                  // 1. Algoritmo recursivo para eliminar todos los nodos con valor x en una lista simple sin nodo cabeza.
void Del_X_2(LinkList &L, ElemType x);                  // 2. Eliminar todos los nodos con valor x en una lista simple con nodo cabeza
void RangeDelete(LinkList &L, int min, int max);        // 7. Eliminar elementos entre dos valores dados (pasados como parámetros)
void Del_Same(LinkList &L);                             // 12. Eliminar duplicados de una lista simple ordenada ascendentemente
LinkList Delete_Min(LinkList &L);                       // 4. Eliminar el nodo con valor mínimo en una lista simple con nodo cabeza
void MinDelete(LinkList &head);                         // 9. Imprimir datos de nodos de lista simple en orden creciente y liberar el espacio de memoria
void Del_All(LinkList &L);                              // 19. Buscar y eliminar repetidamente el nodo con valor mínimo hasta que la lista esté vacía, luego eliminar nodo cabeza.
void R_Print(LinkList L);                               // 3. Imprimir valores de una lista simple con nodo cabeza desde el final hacia el inicio
LinkList Reverse_1(LinkList &L);                        // 5. Invertir in-place una lista simple con nodo cabeza
void Sort(LinkList &L);                                 // 6. Ordenar ascendentemente los elementos de una lista simple con nodo cabeza.
LinkList DisCreat_1(LinkList &A);                       // 10. Dividir una lista simple A con nodo cabeza en dos listas A y B con nodo cabeza
LinkList DisCreat_2(LinkList &A);                       // 11. Dividir lista simple A en A={a1,a2,··· , an,}, B={bn,bn-1,...,b2,b1}
LinkList MergeList(LinkList La,LinkList Lb);            // 13. Combinar dos listas simples ordenadas ascendentemente en una sola lista descendente
LinkList Get_Common(LinkList A, LinkList B);            // 14. Crear lista simple C con elementos comunes de dos listas simples ordenadas ascendentemente (con nodo cabeza)
void Union(LinkList &la, LinkList &lb);                 // 15. Intersección de dos listas simples ordenadas A y B, almacenando el resultado en A.
int Symmetry(DLinkList L);                              // 17. Determinar si una lista doblemente encadenada circular con nodo cabeza es simétrica.
LinkList Link(LinkList &h1 , LinkList &h2);             // 18. Enlazar lista circular h2 a lista circular h1, manteniendo la propiedad de lista circular.
DLinkList Locate(DLinkList &L,ElemType x);              // 20. Algoritmo de operación Locate(L,x) en una lista doble no circular
int Pattern(LinkList A,LinkList B);                     // 16. Determinar si la secuencia B es una subsecuencia continua de la secuencia A
void func(LNode* &h, int n);                            // 23. Para nodos con el mismo valor absoluto en la lista, conservar solo la primera aparición y eliminar el resto
```

###### 1.3.2 Pilas y Colas
> Ver detalles en: data_struct/wangdao/ch03_stack_queue/exercises.hpp

+ Ejercicio 3.1 Pilas p71
```c
int dc(LNode<char> *L, int n);                                  // 4. Determinar si los n caracteres de la lista son simétricos centralmente
typedef struct sstk{                                            // 5. Pila compartida
    int top[2];
    ElemType data[MaxStackSize];
};
int push(ElemType i, ElemType x);
int pop (ElemType i);
```

+ Ejercicio 3.2 Colas
```c
typedef struct tqueue{                                          // 1. Algoritmos de enqueue y dequeue con un campo de bandera tag
    ElemType data[MaxStackSize];
    int front,rear,tag;
};
int tEnQueue(tqueue &s, ElemType x);
int tDeQueue(tqueue &s, ElemType &x);
void Inverse(SqQueue<ElemType> &Q, SqStack<ElemType> &S);       // 2. Algoritmo para invertir los elementos de una cola Q usando una pila S vacía.
typedef struct SSQueue{                                         // 3. Simular una cola utilizando dos pilas S1, S2
    SqStack<ElemType> S1,S2;
};
int EnSSQueue(SSQueue &q, ElemType x);
int DeSSQueue(SSQueue &q, ElemType &x);
int SSQueueEmpty(SSQueue q);
```

+ 3.3 Aplicaciones de Pilas y Colas p96-97
```c
bool BracketsCheck(char *str);                                 // 1. Verificar si los paréntesis de una expresión están emparejados
double p(int n,double x);                                      // 2. Implementación no recursiva de una función recursiva utilizando una pila
```

###### 1.3.3 Árboles Binarios
> Ver detalles en: data_struct/wangdao/ch05_tree/exercises.hpp

+ Ejercicio 5.3 Recorrido de Árbol Binario y Árbol Binario de Índice (p149-p151)
```c
void InvertLevel(BiTree T);                             // 4. Algoritmo de recorrido por niveles de abajo hacia arriba y de derecha a izquierda.
int Btdepth(BiTree T);                                  // 5. Altura de un árbol binario de forma no recursiva.
int BtdepthR(BiTree T);
BiTNode* BiTreePreinCreate(ElemType *A, int l1, int h1, // 6. Construir árbol binario dado el recorrido preorden e inorden (valores únicos)
                           ElemType *B, int l2, int h2);
bool IsComplete(BiTree T);                              // 7. Determinar si un árbol binario es un árbol binario completo.
int DsonNodes (BiTree T);                               // 8. Contar el número de nodos con dos hijos en un árbol binario dado.
int DsonNodes1 (BiTree T);
void swap(BiTree T);                                    // 9. Intercambiar los subárboles izquierdo y derecho de todos los nodos.
void swap1(BiTree T);
ElemType PreNode(BiTree T, int k);                      // 10. Obtener el valor del k-ésimo nodo (1<= k <= total de nodos) en el recorrido preorden.
void SearchDeleteXTree(BiTree T, ElemType x);           // 11. Para cada nodo con valor x, eliminar el subárbol que tiene como raíz y liberar el espacio.
void Search (BiTree T , ElemType x);                    // 12. Buscar nodo con valor x e imprimir todos sus ancestros
bool SearchR (BiTree T , ElemType x);
BiTree Ancestor(BiTree ROOT, BiTNode *p, BiTNode *q);   // 13. Encontrar el ancestro común más cercano r de p y q.
BiTree AncestorR(BiTree T, BiTNode *p, BiTNode *q);
int BTWidth(BiTree T);                                  // 14. Ancho de un árbol binario no vacío (máximo número de nodos en un nivel).
void PreToPost(ElemType pre[],int l1, int h1,           // 15. Dado el preorden de un árbol binario lleno, obtener el postorden.
               ElemType post[],int l2,int h2);
BiTNode* LeafToLinikedList(BiTNode* T);                 // 16. Conectar los nodos hoja de un árbol binario en una lista simple de izquierda a derecha.
bool Similar(BiTree T1, BiTree T2);                     // 17. Determinar si dos árboles binarios son similares.
ThreadNode* InPostPre(ThreadNode* T , ThreadNode* p);   // 18. Algoritmo para encontrar el predecesor en postorden de un nodo dado en un árbol binario enhebrado inorden.
int wpl(BiTree T);                                      // 19. Longitud de camino ponderada (WPL) de un árbol binario.
void BtreeToExp(BiTree T, int depth);                   // 20. Convertir un árbol de expresión (árbol binario) a una expresión infija equivalente.
```

+ Ejercicio 5.4 Árboles y Bosques (p176-p177)
```c
int leaves(CSTree T);                                   // 5. Contar nodos hoja de un bosque almacenado mediante representación hijo-hermano.
void createCSTree_Degree(                               // 7. Construir la lista hijo-hermano de un árbol dada la secuencia de niveles y el grado de cada nodo.
    CSTree&T, ElemType e[], int degree[], int n);
int Height (CSTree bt);                                 // 6. Algoritmo recursivo para obtener la profundidad de un árbol usando estructura hijo-hermano.
```

+ Ejercicio 5.5 Aplicaciones de Árboles y Árboles Binarios (p195-p196)
```c
bool JudgeBST(BSTree bt);                               // 6. Algoritmo para determinar si un árbol binario dado es un árbol binario de búsqueda (BST).
 
int level(BSTree bst, BSTNode *p);                      // 7. Algoritmo para encontrar el nivel de un nodo específico en un BST.
int levelR(BSTree bst, BSTNode *p);
                                                        /** ★★☆ */
bool Judge_AVL(BSTree bst, int &depth);                 // 8. Algoritmo para determinar si un árbol binario es un árbol binario balanceado (AVL) usando recorrido.
int MinBST(BSTree bst);                                 // 9. Algoritmo para encontrar las claves mínima y máxima en un BST.
int MaxBST(BSTree bst);
void OutPut(BSTNode *bt, int key);                      // 10. Imprimir en orden decreciente todas las claves no menores a k en un BST.
BSTNode *Search_Small(BSTNode*t , int k );              // 12. Buscar el k-ésimo (1<=k<=n) elemento más pequeño en un BST y retornar el puntero al nodo.
```

+ Resumen p206-p207
```
void DelLeafNode(BiTree bt);                            // 6. Eliminar todos los nodos hoja de un árbol binario. (Recorrido por niveles => ver Ejercicio 5.3_11)
int GetLevel(BiTree bt,BiTNode *p);                     // 7. Calcular el nivel del nodo *p. (Recorrido por niveles => ver Ejercicio 5.3_5)
```

###### 1.3.4 Ordenamiento
> Ver detalles en: data_struct/wangdao/ch08_sort/exercises.hpp

+ 8.3 Ordenamiento por Intercambio p323-p324
```c
void BubbleSort(ElemType A[], int n);                   // 2. Algoritmo de ordenamiento burbuja bidireccional
void move(ElemType A[], int n);                         // 3. Algoritmo para mover todos los impares antes que los pares
void move2(ElemType A[], int n);
int Partition2(ElemType A[], int low, int high);        // 4. Reimplementar la partición de Quicksort eligiendo el pivote aleatoriamente.
int kth_elem(ElemType A[] , int low, int high, int k);  // 5. Encontrar el k-ésimo elemento más pequeño en un arreglo
int setPartition(ElemType A[], int n);                  // 6. Dividir A en dos subconjuntos disjuntos tal que |n_1-n_2| sea mínimo y |S_1-S_2| sea máximo
int PartitionN(ElemType A[],int n);                     // 4. (8.6) Arreglo {K_1,K_2，...，K_n}, colocar K_n en su posición correcta tras ordenar
void Flag_A_rrange(ElemType A[],int n);                 // 7. Problema de la bandera holandesa
```

+ 8.4 Ordenamiento por Selección p335
```c
void selectSort(LNode<ElemType> *&L);                   // 4. Ordenamiento por selección simple sobre una secuencia de claves representada por lista simple.
bool IsMinHeap(ElemType A[], int len);                  // 5. Algoritmo para determinar si una secuencia de datos constituye un heap min (min-heap).
```

+ 8.6 Comparación y Aplicación de Algoritmos de Ordenamiento Interno
```c
void Insert_Sort(ElemType A[] , int m, int n);          // 2. Los primeros m elementos están ordenados ascendentemente y los últimos n también; diseñar algoritmo para ordenar toda la lista.
```

##### 1.4 Referencias
[1][Guía de Revisión de Estructuras de Datos Wangdao 2021](http://www.cskaoyan.com/)
[2][C++ Funciones/Estructuras/Plantillas de Clase](https://zhuanlan.zhihu.com/p/37669989)


#### 2. Notas de Alta Puntuación Tianqin 2019
- [x] Capítulo 2 Listas Lineales
    - [x] Definición y operaciones básicas de listas secuenciales
    - [x] Definición y operaciones básicas de listas simples
    - [x] Definición y operaciones básicas de listas dobles
    - [x] Conjunto de ejercicios de listas lineales

- [x] Capítulo 3 Pilas y Colas
    - [x] Estructura de almacenamiento y algoritmos de pilas
    - [x] Estructura de almacenamiento y algoritmos de colas
    - [x] Ejercicios de colas y pilas

- [x] Capítulo 6 Árboles y Árboles Binarios
    - [x] Estructura de almacenamiento y operaciones básicas de árboles binarios
    - [x] Recorrido recursivo de árboles binarios
    - [x] Recorrido no recursivo de árboles binarios
    - [x] Árbol binario de índice
    - [x] Árboles, Bosques, Árboles Binarios
    - [x] Ejercicios de árboles binarios

- [x] Capítulo 8 Ordenamiento Interno
    - [x] Tipo Inserción
        - [x] Ordenamiento por inserción directa
        - [x] Ordenamiento por inserción binaria
        - [x] Ordenamiento Shell
    - [x] Tipo Intercambio
        - [x] Ordenamiento burbuja
        - [x] Ordenamiento rápido (Quicksort)
    - [x] Tipo Selección
        - [x] Ordenamiento por selección simple
        - [x] Ajuste de heap máximo
    - [x] Tipo Selección
        - [x] Ordenamiento por selección simple
        - [x] Ordenamiento por heap (Heapsort)
    - [x] Ordenamiento por Mezcla (Mergesort)
        - [x] Ordenamiento por mezcla binaria

- [x] Capítulo 9 Búsqueda
    - [x] Búsqueda secuencial
    - [x] Búsqueda binaria
    - [x] Árbol binario de búsqueda
    - [x] Árbol binario de búsqueda balanceado (AVL)

#### 3. Essential C++
- [x] Capítulo 1 Fundamentos de Programación en C++
```c++
extern void example_01_06();        // p7
extern void example_01_07();        // p33
extern void ex_01_01();             // p7
extern void ex_01_02();             // p7
extern void ex_01_05();             // p33
extern void ex_01_06();             // p33
extern void ex_01_07();             // p34
```
- [x] Capítulo 2 Estilo de Programación Orientado a Procesos
```c++
extern bool example_02_01(int pos, int &elem);      // p36
extern void example_02_02();                        // p45 Paso por valor, puntero y referencia
extern const vector<int>* example_02_03(int size);  // p54 Objetos estáticos locales
extern bool example_02_04(int pos, int& elems);     // p55 Funciones inline
```

#### 4. Práctica Categorizada de LeetCode (Sin tiempo por el momento)
> lc: leetcode, preguntas de entrevista (smo): Sword to Offer
###### `Arreglos`

| No. | Nombre del Problema | Método |
|:--- | :---  | :---  |
| 167 | Two Sum II - Input Array Is Sorted | Dos punteros |
| Entrevista 57 | Dos números que suman s | Dos punteros |
| 977 | Squares of a Sorted Array | Dos punteros |
| 88 | Merge Sorted Array | Dos punteros |
| 26 | Remove Duplicates from Sorted Array | Dos punteros |
| 283 | Move Zeroes | Dos punteros |
| Entrevista 03 | Número duplicado en arreglo | Hash |
| Entrevista 04 | Búsqueda en arreglo bidimensional | Dos punteros |
| Entrevista 06 | Imprimir lista enlazada del final al principio | Dos punteros |
| Entrevista 21 | Reordenar arreglo: impares antes que pares | Dos punteros |
| Entrevista 39 | Número que aparece más de la mitad de veces | |
| Entrevista 63 | Máxima ganancia de acciones | Método de torneo (擂台法) |
