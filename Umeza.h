//---------------------------------------------------------------------------
#ifndef UmezaH
#define UmezaH
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#define max 28
//const max=28;
struct par
{int x, y;};
class mesa  // meza seria una bicola
{
       par V[max+1];
       int p; //Frente  ;
       int u; //Atras;
       int cant;

    public:
         mesa();
         bool vacia();
         bool llena();
         bool Mostrar(int i,int &X,int &Y);
         void intercambiar(int &X,int &Y);
         void insertarAdelanteMesa(int X,int Y);
         void insertarAtrasMesa(int X,int Y);
         void ponerFichaMesa(int X,int Y, bool &ok, bool &lado);
         void sacarFichaMesa(int &X,int &Y);
         bool pertenece(int X,int Y);
         bool perteneceDer(int X,int Y);
         bool igualA_y(int X);
         bool perteneceIzq(int X,int Y);
         bool igualA_x(int Y);
         void PrimeraFicha(int &X,int &Y);
         void UltimaFicha(int &X,int &Y);
         int cantidad();
         int mostrarfichay(int pos);
         int mostrarfichax(int pos);
   };

#endif


