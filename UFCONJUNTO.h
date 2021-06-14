//---------------------------------------------------------------------------
#ifndef UFCONJUNTOH
#define UFCONJUNTOH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Grids.hpp>
#include "UCONJUNTO.h"
#include <Buttons.hpp>
#include "Ujuego.h"
#include "Umeza.h"
#include <Menus.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
    TStringGrid *StringGrid1 ;
    TBitBtn *Biclodr;
    TStringGrid *ja;
    TStringGrid *jb;
    TMainMenu *MainMenu1;
    TMenuItem *JUGAR1;
    TLabel *Label1;
    TLabel *Label2;
    TLabel *Label3;
    TLabel *Label4;
    TStringGrid *tablero;
    TLabel *Label5;
    TGroupBox *GroupBox1;
    TButton *IZQ_INSERTAR_F_AD;
    TButton *ROBAR_MAZO;
    TLabel *Label10;
    TButton *DER_INSERTAR_F_AT;
    TButton *paso;
    TBitBtn *uno;
    TBitBtn *dos;
    TBitBtn *tres;
    TBitBtn *cuatro;
    TRadioGroup *RadioGroup1;
    TLabel *Label6;
    TPanel *Panel1;
    TPanel *Panel2;
    TEdit *Edit1;
    TEdit *Edit2;
    TLabel *Label7;
    TLabel *Label8;
    TImage *Image1;
    TImage *Image2;
    TTimer *robarJUGADOR;
    TTimer *robarfichamaquina;
    TButton *Button1;
    TBitBtn *q;
    TTimer *animacion;
    TLabel *Label11;
    TLabel *Label12;
    TLabel *Label13;
    TLabel *Label14;
    TButton *Button2;
    TButton *Button3;
        TButton *Button4;
    void __fastcall vaciarClick(TObject *Sender);
    void __fastcall JUGAR1Click(TObject *Sender);

    void __fastcall FormCreate(TObject *Sender);

    void __fastcall IZQ_INSERTAR_F_ADClick(TObject *Sender);
    void __fastcall ROBAR_MAZOClick(TObject *Sender);



    void __fastcall DER_INSERTAR_F_ATClick(TObject *Sender);
    void __fastcall pasoClick(TObject *Sender);





    void __fastcall robarJUGADORTimer(TObject *Sender);
    void __fastcall robarfichamaquinaTimer(TObject *Sender);
    void __fastcall Button1Click(TObject *Sender);
    
    void __fastcall animacionTimer(TObject *Sender);
    void __fastcall Button2Click(TObject *Sender);
    void __fastcall Button3Click(TObject *Sender);
        void __fastcall Button4Click(TObject *Sender);
private:	// User declarations

public:		// User declarations
     // conjunto vect;
      fichas fi;
      mesa tabla;
      void activar_botom();
      void desactivar_botom();
      void mostrarfigurade(int &f, int &c);
      void mostrarfiguraiz(int &f, int &c);
      void Mostrar_m();
      void Mostrar_ja();
      void Mostrar_jb();
      void GANADORJUGADORB();
      void GANADORJUGADORA();
    //  void robarfichamaquina(bool ok_maq);
      void robarfichajugador(bool ok_maq);
      void juegamaquina();
      void MostrarTableroAdelante(int f,int c);
      void MostrarTableroAtras(int f,int c);
      bool ok,continua  ;

    __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
