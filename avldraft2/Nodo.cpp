//
// Created by Usuario on 08/11/2026.
//

#include "Nodo.h"

Nodo * nuevoNodo( Nodo * izq, Elemento e,  Nodo * der) {
    return new Nodo{izq,e,der};
}

void impNodo(const Nodo & nodo) {
    impElemento(nodo.e);
}

void plantar(Nodo *&r,Elemento e) {
    if (r==nullptr) r = new Nodo{nullptr,e,nullptr};
    else if ( r->e.valor < e.valor ) plantar(r->der,e);
    else if ( r->e.valor > e.valor ) plantar(r->izq,e);
    else return;
}

void impArbol(Nodo *r) {
    //PID En preorden
    if (r==nullptr) return;
    impNodo(*r);
    impArbol(r->izq);
    impArbol(r->der);
}

int altura( Nodo *r) {
    if ( r==nullptr ) return -1;
    return 1 + max( altura(r->izq), altura(r->der) );
}

Nodo * mayorNodo(Nodo *r) {
    if (r->der==nullptr) return r;
    return mayorNodo(r->der);
}

Nodo * menorNodo(Nodo *r) {
    if (r->izq==nullptr) return r;
    return menorNodo(r->izq);
}

Nodo * predecesor(Nodo *r, Nodo *k) {
    if (r->der and r->der==k)
        return r;
    if (r->izq and r->izq==k)
        return r;
    return r->e.valor < k->e.valor ? predecesor(r->der,k) : predecesor(r->izq,k);
}

int factor(Nodo *r) {
    return abs(altura(r->der) - altura(r->izq));
}

void balancearArbol(Nodo *&r) {
    if (factor(r)<=1) return;
    if ( altura(r->der) > altura(r->izq) ) {
        Nodo * menor = menorNodo(r->der);
        Nodo * pred = predecesor( r, menor );
        menor->izq = r;
        menor->der = r->der;
        r = menor;
    }else {
        Nodo * mayor = mayorNodo(r->izq);
        Nodo * pred = predecesor(r, mayor);
        mayor->der = r;
        mayor->izq = r->izq;
        r = mayor;
    }
    balancearArbol(r);
}
