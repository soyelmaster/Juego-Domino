//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "UCONJUNTO.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
conjunto::conjunto()
{
  for (int i=0; i<=3;i++)
       z[i] =char(0);
}

void conjunto::insertar(int f, int c)
{
     if ((f<=c)&&(!pertenece(f,c)))
      {
        int pos= ((f*(7+(7-f+1))/2)+c-f);
        int indice = int(pos/8);
        int NroBit = pos%8;
         byte y=1;
         y = y << NroBit;
         z[indice] = z[indice] |y;
      }
}

void conjunto :: eliminar(int f, int c)
{
   if (f<=c)
     {
       int pos = ((f*(7+(7-f+1))/2)+c-f);
       int indice = int(pos/8);
       int NroBit = pos%8;
       byte y =1;
       y = y <<NroBit;
       y = ~y;
       z[indice] = z[indice] & y;
     }
}

bool conjunto :: pertenece(int f, int c)
{
   if ( f <= c)
   {
     int pos= ((f*(7+(7-f+1))/2)+c-f);
     int indice = int(pos/8);
     int NroBit = pos%8;
     byte y=1;
     y = z[indice] << (7 - NroBit);
     y = y >> 7;
     return (y!=0);
   }
   else
     return false;
}
/********************************/
int conjunto:: mayor()
{
   bool may=false;
   int ma=6;
   while ((ma>=0)&&(!may))
   {
       if((pertenece(ma,ma)))
           may=true;
       else
          ma--;
   }
   if (may)
       return (ma);
   else
       return (-1);



}

bool conjunto:: vacio()
{
  int cantidad=0;
  for ( int i=0 ; i<=3 ; i++)
      if ( z[i] ==0)
           cantidad++;
  return ( cantidad == 4 );
}
