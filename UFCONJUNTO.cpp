//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "UFCONJUNTO.h"
#include <time.h>




//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
int m;
TForm1 *Form1;
//-----------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{

}

//-----------------------------------------------------
void TForm1::activar_botom()
{
   IZQ_INSERTAR_F_AD->Enabled=true;
   DER_INSERTAR_F_AT->Enabled=true;
   ROBAR_MAZO->Enabled=true;
}
//-----------------------------------------------------
void TForm1::desactivar_botom()
{
   IZQ_INSERTAR_F_AD->Enabled=false;
   DER_INSERTAR_F_AT->Enabled=false;
   ROBAR_MAZO->Enabled=false;
}
//*****************************************

//******************************************
void TForm1::juegamaquina()
{
 int f,c;
 bool ok_maq=false;
 bool lado,si = false;
 lado=false; f=0;c=0;
  if  ( fi.Vacio_jb())
     GANADORJUGADORB();

 while((f<=c)&& (f<=6))
 { c=0;
   while(c<=6)
   {   si= fi.pertenece_jb(f,c);
     if (si)
     {
       int x,y;
       tabla.PrimeraFicha(x,y);
       int X,Y;
       tabla.UltimaFicha(X,Y);
       tabla.ponerFichaMesa(f,c,ok_maq,lado);
       if (ok_maq==true) //  la maquina puso ficha en mesa
        {
          fi.Eliminar_jb(f,c);
          Mostrar_jb();
          if ((ok_maq==true)&&(lado==true))// ficha pert adelante
           {
             if (x==c)
                  {MostrarTableroAdelante(f,c);mostrarfiguraiz(f,c);}
             else
                {MostrarTableroAdelante(c,f);mostrarfiguraiz(c,f);}
             activar_botom();
             c=7; f=7;
            } // fin true del si ficha pert Adelante
          else
          if ((ok_maq==true)&&(lado==false))//ficha pert Atras
          {
             if (Y==f)
                 {MostrarTableroAtras(f,c); mostrarfigurade(f,c);}
             else
                { MostrarTableroAtras(c,f); mostrarfigurade(c,f);}
               activar_botom();
               c=7; f=7;
           }
           ShowMessage(" <<< Le toca al jugador >>>");
        }  //fin ok true
     } //fin del pertenece
        c++;
    }  //fin de mientras c
    f++;
 } //fin de mientras  f
  if ((ok_maq==true) && (fi.Vacio_jb()))
     { GANADORJUGADORB(); }
  if(ok_maq==false)
     {
          ShowMessage(" <<< Espera Esta Robando La Maquina >>>");
          desactivar_botom();
          robarfichamaquina->Enabled=true;
      }
    else
       robarfichamaquina->Enabled=false;

   Mostrar_jb();
 }

 /****************************************************/

void __fastcall TForm1::robarfichamaquinaTimer(TObject *Sender)
{
   int f,c;
   fi.colocarfichas(f,c);
   if (fi.Vacio_m())
  {
      ShowMessage("<<<< Paso No Hay Ficha Para Robar >>>");
      ShowMessage("<<<< Le Toca Al Jugador >>>");
      activar_botom();
      robarfichamaquina->Enabled=false;
  }
 else
   if ((fi.pertenece_m(f,c)) && (fi.contador_m()!=0))
   {
       fi.Insertar_jb(f,c);
       Mostrar_jb();
       fi.Eliminar_m(f,c);
       Mostrar_m();
       robarfichamaquina->Enabled=false;
       juegamaquina();

    }

}   // fin fin
//---------------------------------------------------------------------------

//********************************************
void TForm1::robarfichajugador(bool ok_maq)
{
   int f,c;
   bool lado;
   int cant=fi.contador_m();
   if((ok_maq==false)&&(cant>0)) // MAQUINA NO PUDO PONER NINGUNA DE SUS FICHAS EN MESA
   {
     f=0;
     c=0;
     while((f<=c)&& (f<=6))
      { c = 0;
        while(c<=6)
        {
          if(fi.pertenece_m(f,c))// MAQUINA TIENE QUE ROBAR FICHA DEL MAZO
          {
           int x,y;
           tabla.PrimeraFicha(x,y);
           int X,Y;
           tabla.UltimaFicha(X,Y);
           fi.Eliminar_m(f,c);
           fi.Insertar_ja(f,c);     // inserta al usuario
           Mostrar_m();
           Mostrar_ja();
           tabla.ponerFichaMesa(f,c,ok_maq,lado);
           if (ok_maq==true)//  MAQUINA ROBO DEL MAZO E INSERTO A MESA
              fi.Eliminar_ja(f,c);
           if ((ok_maq==true)&& (lado==true))
            {
              if (x==c)
                 {MostrarTableroAdelante(f,c);mostrarfiguraiz(f,c);}
               else
                 {MostrarTableroAdelante(c,f);mostrarfiguraiz(c,f); }
              f=7; c=7;
              activar_botom();
            }
           else
           if ((ok_maq==true)&& (lado==false))
           {
             if (Y==f)
                 {MostrarTableroAtras(f,c);mostrarfigurade(f,c);}
             else
                 {MostrarTableroAtras(c,f); mostrarfigurade(c,f);}
             f=7; c=7;
             activar_botom();
           }
         }/* fin si  pertnece*/
        c++;
       }// fin mientras c
      f++;
    }/* fin mientras f */
  } // fin si
 if ((ok_maq==true) && (fi.Vacio_ja()))
     { GANADORJUGADORA();   }
 if ((ok_maq==false) && (cant<=0))
      {
        ShowMessage("<<< MAQUINA P A S O  >>>> " );
        activar_botom();
      }
}

//----------------------------
void __fastcall TForm1::vaciarClick(TObject *Sender)
{
  for (int i =0; i<=28; i++)
    StringGrid1->Cells[28-i][0] = IntToStr(0);
}
//---------------------------------------------------------------------------


void __fastcall TForm1::JUGAR1Click(TObject *Sender)
{
  int f,c,n; bool ok_maq,lado,ok_inicio;
  f=0; c=3;
  animacion->Enabled=true;
  fi.repartir();

  fi.iniciar_dom(f,c,ok_inicio);
  tablero->Cells[ tablero->Col][0] =IntToStr(f)+","+IntToStr(c);
  tablero->Col++;
  Mostrar_m();
  Mostrar_ja();
  Mostrar_jb();
  tabla.ponerFichaMesa(f,c,ok_maq,lado);
  n=tabla.cantidad();
  Label10->Caption = IntToStr(n);
  Label3->Caption = IntToStr(fi.contador_m()) ;
  Label1->Caption = IntToStr(fi.contador_a()) ;
  Label2->Caption = IntToStr(fi.contador_b()) ;
  IZQ_INSERTAR_F_AD->Enabled=true;
  DER_INSERTAR_F_AT->Enabled=true;
  mostrarfiguraiz(f,c);
  mostrarfigurade(f,c);
    if (ok_inicio)
     {   ShowMessage (" Inicio el jugador ");
         juegamaquina();
         ROBAR_MAZO->Enabled=true;
     }
     else
         ShowMessage (" Inicio la maquina  ");
 Mostrar_m();
  Mostrar_ja();
  Mostrar_jb();
}

//---------------------------------------------------------------------------
 void TForm1::mostrarfiguraiz(int &f, int &c)
 {
   uno->Glyph->LoadFromFile(IntToStr(f)+".bmp");
   dos->Glyph->LoadFromFile(IntToStr(c)+".bmp");
 }
//*************************************
 void TForm1::mostrarfigurade(int &f, int &c)
 {
   tres->Glyph->LoadFromFile(IntToStr(f)+".bmp");
   cuatro->Glyph->LoadFromFile(IntToStr(c)+".bmp");
 }
//*************************************

void TForm1::Mostrar_m()
{
 int cont=0;
    for (int f=0; f<=6; f++)
          for (int c=0; c<=6; c++)
            {
              if (f<=c)
              {
                 bool  pert=fi.pertenece_m(f,c);
                 if (pert)
                  { int pos= ((f*(7+(7-f+1))/2)+c-f);
                    StringGrid1->Cells[pos][0] =  IntToStr(f)+","+IntToStr(c);
                    cont++;
                  }
                 else
                 {  int pos= ((f*(7+(7-f+1))/2)+c-f);
                    StringGrid1->Cells[pos][0] = " ";
                 }
              }//fin si
              }
      Label3->Caption = IntToStr(cont)+" "+IntToStr(fi.contador_m()) ;
}
/*****************************************************/
void TForm1::Mostrar_ja()
{
   int cont=0;
    for (int f=0; f<=6; f++)
       for (int c=0; c<=6; c++)
        {
           if (f<=c)
              {
                 bool  pert=fi.pertenece_ja(f,c);
                 if (pert)
                  { int pos= ((f*(7+(7-f+1))/2)+c-f);
                    ja->Cells[pos][0] = IntToStr(f)+","+IntToStr(c);
                    cont++;
                  }
                 else
                 {  int pos= ((f*(7+(7-f+1))/2)+c-f);
                    ja->Cells[pos][0] = " ";
                 }
              }//fin si
        }
      Label2->Caption = IntToStr(cont) ;
}
/*********************************************/
void TForm1::Mostrar_jb()
{
   int cont=0;
    for (int f=0; f<=6; f++)
       for (int c=0; c<=6; c++)
        {
           if (f<=c)
              {
                 bool  pert=fi.pertenece_jb(f,c);
                 if (pert)
                  { int pos= ((f*(7+(7-f+1))/2)+c-f);
                    jb->Cells[pos][0] = IntToStr(f)+","+IntToStr(c);
                    cont++;
                  }
                 else
                 {  int pos= ((f*(7+(7-f+1))/2)+c-f);
                    jb->Cells[pos][0] = " ";
                 }
              }//fin si
        }
      Label1->Caption = IntToStr(cont) ;
      if (cont==0)
         GANADORJUGADORB();

}
/**************************************************/
void __fastcall TForm1::FormCreate(TObject *Sender)
{
   ok=false;
   m=0;
   Mostrar_m();
   animacion->Enabled=false;
}
//---------------------------------------------------------------------------
void TForm1::MostrarTableroAdelante(int f,int c)
{
   if ((f>=0)&&(f<=6)&&(c>=0)&&(c<=6))
     {
        int n;
        tablero->Col++;
        for ( int i = tablero->Col;i>0;i--)
            tablero->Cells[i][0] = tablero->Cells[i-1][0];
        tablero->Cells[0][0]=IntToStr(f)+","+IntToStr(c);
        n= tabla.cantidad();
        Label10->Caption = IntToStr(n) ;
        fi.Eliminar_m(f,c);
        fi.Eliminar_ja(f,c);
        fi.Eliminar_jb(f,c);
        Mostrar_ja();
        Mostrar_jb();
        Mostrar_m();
      }
}
/************************************************/
void TForm1::MostrarTableroAtras(int f,int c)
{
    if ((f>=0)&&(f<=6)&&(c>=0)&&(c<=6))
         {
             int n;
             n=tabla.cantidad();
             Label10->Caption = IntToStr(n) ;
             tablero->Cells[tablero->Col][0]=IntToStr(f)+","+IntToStr(c);
             tablero->Col++;
             fi.Eliminar_m(f,c);
             fi.Eliminar_ja(f,c);
             fi.Eliminar_jb(f,c);
             Mostrar_ja();
             Mostrar_jb();
             Mostrar_m();
         }
  }
/*********************************************************/
void __fastcall TForm1::IZQ_INSERTAR_F_ADClick(TObject *Sender)
{
   int f,c;
   f=StrToInt(Edit1->Text);
   c=StrToInt(Edit2->Text);
   if ((Edit1->Text == "")||(Edit2->Text == ""))
   {
      ShowMessage("Debe insertar valores en los edit's del jugador");
      return ;
   }
   else
   {
     if (tabla.llena())
         ShowMessage("Bicola: error Bicola Llena");
      else
        if ((f>=0)&&(f<=6)&&(c>=0)&&(c<=6)&&(f<=c)
           &&(fi.pertenece_ja(f,c))
           &&(tabla.perteneceIzq(f,c))
           &&(!tabla.pertenece(f,c)))
         {
          if (tabla.igualA_x(c))
             {
               fi.Eliminar_ja(f,c);
               Mostrar_ja();
               tabla.insertarAdelanteMesa(f,c);
               MostrarTableroAdelante(f,c);
               mostrarfiguraiz(f,c);
               if (fi.Vacio_ja())
                    GANADORJUGADORA();
               ShowMessage("le toca a la maquina");
               juegamaquina();
             }
             else
             {
               fi.Eliminar_ja(f,c);
               Mostrar_ja();
               tabla.intercambiar(f,c);
               tabla.insertarAdelanteMesa(f,c);
               MostrarTableroAdelante(f,c);
               mostrarfiguraiz(f,c);
                if (fi.Vacio_ja())
                 { GANADORJUGADORA();   }
              //  desactivar_botom();
                ShowMessage("juega la maquina");
                juegamaquina();
             }
       }
   }

}

//---------------------------------------------------------------------------

void __fastcall TForm1::ROBAR_MAZOClick(TObject *Sender)
{
  robarJUGADOR->Enabled=true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::DER_INSERTAR_F_ATClick(TObject *Sender)
{
   int f,c;
   f=StrToInt(Edit1->Text);
   c=StrToInt(Edit2->Text);
 //  ja=fi.pertenece_ja(f,c);
 //  td=tabla.perteneceDer(f,c);
 //  tp=tabla.pertenece(f,c);
   if (tabla.llena())
       ShowMessage("Bicola: error Bicola Llena");
     else
       if ((f>=0)&&(f<=6)&&(c>=0)&&(c<=6)&&(f<=c)
             &&(fi.pertenece_ja(f,c))
             &&(tabla.perteneceDer(f,c))
             &&(!tabla.pertenece(f,c)))
       {
         if (tabla.igualA_y(f))
             {
               fi.Eliminar_m(f,c);
               fi.Eliminar_ja(f,c);
               fi.Eliminar_jb(f,c);
               Mostrar_m();
               Mostrar_ja();
               //Mostrar_jb();
               tabla.insertarAtrasMesa(f,c);
               MostrarTableroAtras(f,c);
             //  desactivar_botom();
               mostrarfigurade(f,c);
                if (fi.Vacio_ja())
                 { GANADORJUGADORA();   }
               ShowMessage("le toca a la maquina");
               juegamaquina();
             }
             else
             {
               fi.Eliminar_m(f,c);
               fi.Eliminar_ja(f,c);
               fi.Eliminar_jb(f,c);
               Mostrar_m();
               Mostrar_ja();
               Mostrar_jb();
               tabla.intercambiar(f,c);
               tabla.insertarAtrasMesa(f,c);
               MostrarTableroAtras(f,c);
               mostrarfigurade(f,c);
                if (fi.Vacio_ja())
                 { GANADORJUGADORA();
                  }
               ShowMessage("<<< Le Toca A La Maquina >>>>");
               juegamaquina();
             }
         }
}
//---------------------------------------------------------------------------
void TForm1:: GANADORJUGADORA()
{
      ShowMessage("<<<<< GAAAANNNOOOO EL JUGADOR >>>>>");
      ShowMessage("<<<< !!!!Termino Se Va Ha Cerrar El Programa !!!!>>>> ");
      Application->Terminate();
  }
//*********************************
void TForm1:: GANADORJUGADORB()
{
      ShowMessage("<<<<< GAAAANNNOOOO LA MAAAQUINA >>>>>");
      ShowMessage("<<<< !!!!Termino Se Va Ha Cerrar El Programa !!!!>>>> ");
      Application->Terminate();
 }
//************************
void __fastcall TForm1::pasoClick(TObject *Sender)
{
   int cant=fi.contador_m();
   if (cant>0)
      ShowMessage("No puede hay ficha en el mazo");
    else
      juegamaquina();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::robarJUGADORTimer(TObject *Sender)
{
  int f,c;
  fi.colocarfichas(f,c);
  if ((fi.pertenece_m(f,c)))// && (fi.contador_m()>0))
   {
       fi.Eliminar_m(f,c);
       //fi.Eliminar_m(f,c};
       fi.Insertar_ja(f,c);
       Mostrar_ja();
       Mostrar_m();
       robarJUGADOR->Enabled=false;
    }
}
//---------------------------------------------------------------------------



void __fastcall TForm1::Button1Click(TObject *Sender)
{
       int f=StrToInt(Edit1->Text);
       int c=StrToInt(Edit2->Text);

       if (fi.pertenece_jb(f,c))
        { ShowMessage("pertenece");
         fi.Eliminar_jb(f,c);}
       else
        ShowMessage(" no pertenece");


}
//---------------------------------------------------------------------------


void __fastcall TForm1::animacionTimer(TObject *Sender)
{
if (m==0)
     {  q->Glyph->LoadFromFile("a.bmp"); m++;}
 else
   if (m==1)
      {q->Glyph->LoadFromFile("b.bmp");  m++;}
   else
   { q->Glyph->LoadFromFile("c.bmp"); m=m-m;}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
       int f=StrToInt(Edit1->Text);
       int c=StrToInt(Edit2->Text);

       if (fi.pertenece_m(f,c))
        { ShowMessage("pertenece"); }
       else
       {   ShowMessage(" no pertenece");
          fi.Insertar_m(f,c) ;}

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
         int f=StrToInt(Edit1->Text);
       int c=StrToInt(Edit2->Text);

       if (fi.pertenece_ja(f,c))
        { ShowMessage("pertenece");}
       else
        ShowMessage(" no pertenece");
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button4Click(TObject *Sender)
{
ShowMessage("Rosa Maria Justiniano,Felipe Suarez y Miguel Angel Mendoza");        
}
//---------------------------------------------------------------------------

