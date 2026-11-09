//
// Created by Usuario on 08/11/2026.
//

#ifndef AVLDRAFT_NODO_H
#define AVLDRAFT_NODO_H
#include "Elemento.h"

struct Nodo {
    Nodo * izq;
    Elemento e;
    Nodo * der;
};

Nodo * nuevoNodo( Nodo * izq, Elemento e,  Nodo * der);
void impNodo(const Nodo & nodo);

void plantar(Nodo *&r,Elemento e);

void impArbol(Nodo *r);

int altura( Nodo *r);
Nodo * mayorNodo(Nodo *r);
Nodo * menorNodo(Nodo *r);
Nodo * predecesor(Nodo *r, Nodo *k);
void balancearArbol(Nodo *&r);

#endif //AVLDRAFT_NODO_H
