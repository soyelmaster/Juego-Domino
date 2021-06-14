//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Umeza.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)

mesa::mesa()
{
   p = 0;
   u = max;
   cant = 0;
   for(int i= 0; i<=28; i++)
   {  V[i].x=77; V[i].y=77;     }
}
//******************************************
int mesa :: mostrarfichax(int pos)
{
  if (pos<=cant)
      return (V[pos].x);
  else return -1;
}
//****************
int mesa :: mostrarfichay(int pos)
{
  if (pos<=cant)
   return(V[pos].y);
  else return -1;
}
//*******************************************
bool mesa::vacia()
{  return ( cant==0 );   }
//*****************************************
bool mesa::llena()
{ return ( cant==(max+1) ); }
//***************************************
void mesa::intercambiar(int &a, int &b)
{ int aux;
      aux=a;
      a  =b;
      b  =aux;
}
bool mesa::Mostrar(int pos,int &X, int &Y)
{
   return ((X==V[pos].x) & (Y=V[pos].y));
}

//*********************************************
void mesa::insertarAdelanteMesa(int X, int Y)
{
   if (llena())
        throw ("bicola::insertar:Error bicola llena");
   else
    {
      if ( p == 0 )
         p = max;
      else
         p=(p-1) % (max+1);
      V[p].x=X;
      V[p].y=Y;
      cant=cant+1;//cantidad =1
   }
}
//******************************************
void mesa::insertarAtrasMesa(int X,int Y)
{
    if (llena())
        throw ("bicola::insertar:Error bicola llena");
    else
     {
      if (u == max)
          u = 0;
       else
           u = (u+1) % (max+1);
       V[u].x = X;
       V[u].y = Y;
       cant=cant+1;//incrementa cantidad
      }
}
//******************************************
void mesa::PrimeraFicha(int &X,int &Y)
{
  X=V[p].x;
  Y=V[p].y;
}
//******************************************
void mesa::UltimaFicha(int &X,int &Y)
{
    X=V[u].x;
    Y=V[u].y;
}
//***********************************************
void mesa::ponerFichaMesa(int X,int Y,bool &ok,bool &lado)
{
  if (llena())
    throw ("bicola::PonerFicha:Error bicola llena");
  if (vacia())
       insertarAdelanteMesa(X,Y);
  else  //tiene por lo menos una ficha
   {
     if (perteneceIzq(X,Y)&&(!pertenece(X,Y)))
        {
         if (igualA_x(Y))
             insertarAdelanteMesa(X,Y);
          else
            {
               intercambiar(X,Y);
               insertarAdelanteMesa(X,Y);
            }
          lado=true;//inserto al lado izquierdo
          ok=true;//devuelve true si la ficha a sido insertada
        }
      else
      {
        if ((perteneceDer(X,Y))&&(!pertenece(X,Y)))
          {
           if ( igualA_y(X) )
                  insertarAtrasMesa(X,Y);
            else
              {
                intercambiar(X,Y);
                insertarAtrasMesa(X,Y);
              }
            ok=true;
            lado=false;//devuelve true si la ficha a sido insertada
          }
     }
   }
}
//***********************************************
int mesa :: cantidad()
{
  return(cant);
}
//*********************************
bool mesa::pertenece(int X,int Y)
{
 int i=0;
 bool sw=false;
 int cant=cantidad();
 while(i<=29 && (!sw))
   {
   if (((V[i].x==X)&&(V[i].y==Y))||((V[i].x==Y)&&(V[i].y==X)))
       sw = true;
     i++;
   }
   return (sw);
}
bool mesa::perteneceDer(int X,int Y)
{
  int sfx= V[u].y;
  return  ((sfx == X) || (sfx == Y));
}
bool mesa::igualA_y(int X)
{  return ( V[u].y == X );   }

bool mesa::igualA_x(int X)
{  return ( V[p].x == X );        }

bool mesa::perteneceIzq(int X,int Y)
{
  int say= V[p].x;
  return(say == X || say == Y);
}











