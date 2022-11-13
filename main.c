#include "Elem.h"
#include "BiCola.h"

BiCola rotarDer(BiCola);
BiCola rotarIzq(BiCola);
void impColaIzq(BiCola);
void impColaDer(BiCola);

void main()
{

    BiCola bi = nuevaBi();
    int i;

    for (i = 1; i <= 10; i++)
    {
        bi = formDer(bi, i);
    }

    impColaIzq(bi);
    printf("\n");
    impColaDer(bi);
    printf("\n-----\n");

    rotarDer(bi); // 3,1,2
    impColaIzq(bi);
    printf("\n");
    impColaDer(bi);

    printf("\n-----\n");

    rotarIzq(bi);
    impColaIzq(bi);
    printf("\n");
    impColaDer(bi);
}

BiCola rotarDer(BiCola b)
{
    b = formIzq(derecho(b), b);
    b = desfDer(b);
    return b;
}

BiCola rotarIzq(BiCola b)
{
    b = formDer(b, izquierdo(b));
    b = desfIzq(b);
    return b;
}

void impColaIzq(BiCola b)
{
    BiCola t = nuevaBi();
    while (!esNuevaBi(b))
    {
        ImpElem(izquierdo(b));
        t = formDer(t, izquierdo(b));
        b = desfIzq(b);
    }
    while (!esNuevaBi(t))
    {
        b = formDer(b, izquierdo(t));
        t = desfIzq(t);
    }
}

void impColaDer(BiCola q){
     BiCola t=nuevaBi();
     while(!esNuevaBi(q)){
         ImpElem(derecho(q));
         t=formIzq(derecho(q),t);
         q=desfDer(q);
     }
     while(!esNuevaBi(t)){
         q=formIzq(derecho(t),q);
         t=desfDer(t);
     }
};
