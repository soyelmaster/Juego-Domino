//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "Ujuego.h"
#include <stdlib.h>
#include <time.h>
#include "UCONJUNTO.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
fichas::fichas()
{
   sw=false;

   for (int f=0; f<=6; f++)
     for (int c=0; c<=6; c++)
         if ((f<=c)&&(cont_m<=27))
            {
              Eliminar_ja(f,c);
              Eliminar_jb(f,c);
              Eliminar_m(f,c);
             }
   cont_m =0;
   cont_a =0;
   cont_b =0;

}
//**************************

bool fichas ::Vacio_m()
{
  return ( fich_m.vacio());
}

//***********************
int fichas :: contador_m()
{
   return cont_m;
}
//*************************
int fichas ::contador_a()
{
   return cont_a;
}
//**************************

bool fichas ::Vacio_ja()
{
  return ( fich_ja.vacio());
}
//**************************
bool fichas ::Vacio_jb()
{
  return ( fich_jb.vacio());
}
//**************************
int fichas ::contador_b()
{
   return cont_b;
}
/********************************************/
void fichas :: repartir()
{
  fichas();
  repartir_ja();
  repartir_jb();
  repartir_m();

} // fin procedure

//********************************
void fichas :: repartir_jb()
{
 bool perte;
  int f,c;
   while (contador_b() <= 5)
   {
      colocarfichas(f,c);
      perte =pertenece_ja(f,c);
      perte =pertenece_jb(f,c);
     if ((f<=c)&& (f<=6) && (c<=6) &&
        (!pertenece_ja(f,c))&&
        (!pertenece_jb(f,c)))
                  Insertar_jb(f,c); // inserta ficha a jugador usuario
      else
      if ((f<=c) && (f<=6) && (c<=6) && (!pertenece_jb(f,c) ))
          Eliminar_jb(f,c) ;
   } // fin mientras
} // fin procedure


//*************************************************
 void fichas :: repartir_ja()
{
 bool perte;
  int f,c;
   while (contador_a() <= 5)
   {
      colocarfichas(f,c);
     if ((f<=c) && (f<=6) && (c<=6) && (!pertenece_ja(f,c) ))
          Insertar_ja(f,c); // inserta ficha a jugador usuario
      else
         if ((f<=c) && (f<=6) && (c<=6) && (!pertenece_ja(f,c) ))
            Eliminar_ja(f,c);


   } // fin mientras
} // fin procedure

//*************************************************
//********************************
void fichas :: repartir_m()
{
 bool perte;

      for (int f=0; f<=6; f++)
        for (int c=0; c<=6; c++)
         { perte= pertenece_ja(f,c);
           perte= pertenece_jb(f,c);
           if ((f<=c)&& (f<=6) && (c<=6) &&
              ((!pertenece_ja(f,c)) &&
              (!pertenece_jb(f,c)) ))

            {
               Insertar_m(f,c); // inserta ficha a jugador usuario
            }//fin si
          } // for c
       /*  int f=0; int c=3;
         Insertar_m(f,c);
         Eliminar_jb(f,c);*/
     } // fin procedure


//*************************************************

bool fichas :: pertenece_m(int f, int c)
{
   return (fich_m.pertenece(f,c));
}

//*************************************************
bool fichas :: pertenece_ja(int f, int c)
{
   return (fich_ja.pertenece(f,c));
}

//*************************************************
bool fichas :: pertenece_jb(int f, int c)
{
   return (fich_jb.pertenece(f,c));
}
/*************************************************/
void fichas:: Eliminar_m(int f,int c)
{
 if (fich_m.pertenece(f,c))
    {
      fich_m.eliminar(f,c);
      cont_m--;
     }
}
/*************************************************/
void fichas::Eliminar_ja(int f,int c)
{
   if (fich_ja.pertenece(f,c))
    {
       fich_ja.eliminar(f,c);
       cont_a--;
    }
}
/*************************************************/
void fichas::Eliminar_jb(int f,int c)
{
   if (fich_jb.pertenece(f,c))
    {
      fich_jb.eliminar(f,c);
       cont_b--;
    }
}
/*************************************************/
void fichas::Insertar_ja(int f,int c)
{

        fich_ja.insertar(f,c);
        cont_a++;

}
/*************************************************/
void fichas::Insertar_jb(int f,int c)
{
            fich_jb.insertar(f,c);
            cont_b++;

}
/*************************************************/
void fichas::Insertar_m(int f,int c)
{
            fich_m.insertar(f,c);
            cont_m++;

}
//*******************************
void fichas::iniciar_dom(int &f,int& c ,bool &ok_inicio)
{
  // bool ok_inicio;
   int ja,jb;
   ja=fich_ja.mayor();//sacara la ficha mayor del jugador a
   jb=fich_jb.mayor();
   if (ja > jb)
     {  f=ja;
        c=ja;
        //Eliminar_jb(f,c);
        Eliminar_ja(f,c);
        //Eliminar_m(f,c);
        ok_inicio = true; // activa una badera para que juegue la maquina

     }
   else
     { if (ja < jb)
       {
          f=jb;
          c=jb;
           Eliminar_jb(f,c);
          // Eliminar_ja(f,c);
           //Eliminar_m(f,c);
           ok_inicio = false; // activa una badera para que juegue el usuario

         }  //fi si a<b
       }
}

//****************************************************
void fichas::colocarfichas(int &f,int &c )
{
  f = random((6+1) + 0);
  c = random((6+1) + 0);
  randomize;
}
//*************************************************/


