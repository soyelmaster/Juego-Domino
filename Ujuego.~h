//---------------------------------------------------------------------------
#ifndef UjuegoH
#define UjuegoH
#include "UCONJUNTO.h"
//#include "Umeza.h"

//---------------------------------------------------------------------------
class fichas
{
    conjunto  fich_ja, fich_jb, fich_m;
    bool sw;
    int cont_a ,    cont_b,  cont_m;
    public:
       fichas();
       void repartir();
     //void repartir_jb();
       bool Vacio_m();
       bool Vacio_ja();
       bool Vacio_jb();
       void iniciar_dom(int &f,int &c,bool &ok);
       int contador_a();
       int contador_b();
       int contador_m();
       void colocarfichas(int &f,int &c );
       bool pertenece_m(int f, int c);
       bool pertenece_jb(int f, int c);
       bool pertenece_ja(int f, int c);
       void Eliminar_m (int f,int c);
       void Eliminar_ja(int f,int c);
       void Eliminar_jb(int f,int c);
       void Insertar_ja(int f,int c);
       void Insertar_jb(int f,int c);
       void Insertar_m(int f,int c);
       bool esta();
       void repartir_ja();
       void repartir_jb();
       void repartir_m();
};
#endif
