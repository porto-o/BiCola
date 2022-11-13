#include <stdlib.h>
#include <stdio.h>

typedef struct NodoBi
{
    Elem dato;
    struct NodoBi *izq;
    struct NodoBi *der;
} * ApNodoBi;

typedef struct BiNodo
{
    ApNodoBi izq;
    ApNodoBi der;
} * BiCola;

BiCola nuevaBi()
{
    BiCola t = (BiCola)malloc(sizeof(struct BiNodo));
    t->izq = t->der = NULL;
    return t;
}

int esNuevaBi(BiCola q) { return (q->izq == NULL) && (q->der == NULL); }

BiCola formIzq(Elem e, BiCola q)
{
    ApNodoBi t = (ApNodoBi)malloc(sizeof(struct NodoBi));
    t->dato = e;
    t->izq = NULL;
    t->der = NULL;
    if (esNuevaBi(q))
        q->izq = q->der = t;
    else
    {
        t->der = q->izq;
        q->izq->izq = t;
        q->izq = t;
    }
    return q;
}

BiCola formDer(BiCola q, Elem e)
{
    ApNodoBi t = (ApNodoBi)malloc(sizeof(struct NodoBi));
    t->dato = e;
    t->izq = NULL;
    t->der = NULL;
    if (esNuevaBi(q))
        q->izq = q->der = t;
    else
    {
        t->izq = q->der;
        q->der->der = t;
        q->der = t;
    }
    return q;
}
Elem izquierdo(BiCola q) { return q->izq->dato; };

Elem derecho(BiCola q) { return q->der->dato; };

BiCola desfIzq(BiCola q)
{
    ApNodoBi t = q->izq;
    if (q->izq == q->der)
        q->izq = q->der = NULL;
    else
    {
        q->izq = q->izq->der;
        q->izq->izq = NULL;
    }
    free(t);
    return q;
}

BiCola desfDer(BiCola q)
{
    ApNodoBi t = q->der;
    if (q->izq == q->der)
        q->izq = q->der = NULL;
    else
    {
        q->der = q->der->izq;
        q->der->der = NULL;
    }
    free(t);
    return q;
}