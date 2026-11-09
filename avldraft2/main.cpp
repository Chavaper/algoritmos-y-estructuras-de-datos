#include <iostream>
#include <vector>

#include "Nodo.h"

enum{CLAVE, IZQ, DER};

int esbst(vector<vector<int>> &arbol,int i) {
    if ( arbol[i][IZQ]==0 and arbol[i][DER]==0 ) return 1;
    vector<int> raiz = arbol[i];

    int bstIzq=0, bstDer=0;
    if (raiz[IZQ]==0)
        bstIzq=1;
    else{
        vector<int> nodoIzq= arbol[raiz[IZQ] - 1];
        if (raiz[CLAVE] <= nodoIzq[CLAVE] ) return 0;
        bstIzq = esbst(arbol,raiz[IZQ]-1);
    }

    if (raiz[DER]==0)
        bstDer=1;
    else {
        vector<int> nodoDer = arbol[raiz[DER] - 1];
        if (raiz[CLAVE] >= nodoDer[CLAVE] ) return 0;
        bstDer = esbst(arbol,raiz[DER]-1);
    }
    return bstIzq==1 and bstDer==1;
}

int leerArbo() {
    int nodos;
    cin >> nodos;
    vector arbol( nodos, vector<int>(3) );
    for (auto &nodo: arbol) {
        int k, numizq, numder;
        cin >> nodo[CLAVE] >> nodo[IZQ] >> nodo[DER];
    }
    int bst = esbst(arbol,0);
    return bst;
}

int main() {
    Nodo * r = nullptr;
    plantar(r,Elemento{100});
    plantar(r,Elemento{70});
    plantar(r,Elemento{200});
    plantar(r,Elemento{180});
    plantar(r,Elemento{300});
    plantar(r,Elemento{400});

    impArbol(r); cout<<endl;
    balancearArbol(r);

    impArbol(r); cout<<endl;

    return 0;
}