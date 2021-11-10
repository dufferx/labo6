#include <stdlib.h>
#include <iostream>

using namespace std;

struct nodo
{
    int nFil, nCol;
    nodo *sigCol, *sigFil;
    int dato;
};

class HojaCalc
{
private:
    int totFil; 
    int totCol; 
    nodo *pHE;  

public:
    HojaCalc(int, int); 
    void insNodo(void);
    void imprimir(void);
    void sumarFila(int);
    void sumarColu(int);
};


HojaCalc::HojaCalc(int totFil, int totCol)
{
    nodo *nuevo, *s;
    int i;

   
    pHE = new nodo;

    this->totFil = totFil;
    this->totCol = totCol;
    pHE->nFil = 0;
    pHE->nCol = 0;
    pHE->sigCol = pHE;
    pHE->sigFil = pHE;
    pHE->dato = 0;

  
    s = pHE;
    for (i = 1; i <= totCol; i++)
    {
        nuevo = new nodo;
        s->sigCol = nuevo;
        nuevo->dato = 0;
        nuevo->nCol = i;
        nuevo->nFil = 0;
        nuevo->sigFil = nuevo;
        s = s->sigCol;
    };
    nuevo->sigCol = pHE;


    s = pHE;
    for (i = 1; i <= totFil; i++)
    {
        nuevo = new nodo;
        s->sigFil = nuevo;
        nuevo->dato = 0;
        nuevo->nFil = i;
        nuevo->nCol = 0;
        nuevo->sigCol = nuevo;
        s = s->sigFil;
    }
    nuevo->sigFil = pHE;
}

void HojaCalc::insNodo(void)
{
    int fila, columna;

    cout << "Inserción de nodos en la hoja electrónica." << endl;
    cout << "Finalice introduciendo ceros:" << endl
         << endl;
    do
    {
        cout << "Fila: ";
        cin >> fila;
        cout << "Columna: ";
        cin >> columna;

        if (fila >= 1 && fila <= totFil && columna >= 1 && columna <= totCol)
        {
            nodo *nuevo = new nodo;

            cout << "Entero a almacenar: ";
            cin >> nuevo->dato;
            nuevo->nFil = fila;
            nuevo->nCol = columna;

            nodo *pFil = pHE;
            nodo *pCol = pHE;
            int i;

            for (i = 1; i <= fila; i++) 
                pFil = pFil->sigFil;
            while ((pFil->sigCol->nCol < columna) && (pFil->sigCol->nCol != 0)) 
                pFil = pFil->sigCol;

           
            for (i = 1; i <= columna; i++) 
                pCol = pCol->sigCol;
            while ((pCol->sigFil->nFil < fila) && (pCol->sigFil->nFil != 0))
                pCol = pCol->sigFil;

          
            nuevo->sigCol = pFil->sigCol;
            pFil->sigCol = nuevo;

            nuevo->sigFil = pCol->sigFil;
            pCol->sigFil = nuevo;
            cout << "El nodo se ha insertado" << endl
                 << endl;
        }
        else
            cout << "Hubicación no válida para nuevo dato" << endl
                 << endl;
    } while (fila != 0 || columna != 0);
}



void HojaCalc::imprimir(void)
{
    cout << "Para cada nodo se muestra: fila, columna, dato." << endl;
    cout << "La hoja electrónica es:" << endl;
    nodo *s = pHE;
    int i;

    do
    {
        do
        {
            cout << s->nFil << ',' << s->nCol << ',' << s->dato << '\t';
            s = s->sigCol;
        } while (s->nCol != 0);
        cout << endl;
        s = s->sigFil;
    } while (s->nFil != 0);
}
void HojaCalc::sumarFila(int fila){
     nodo *s = pHE;
   do{
       if(s->nFil == fila){
           int sum = 0;
           do{
               sum += s->dato;
               s=s->sigCol;
           }while(s->nCol != 0);
           cout <<"Suma de la fila "<<fila<<": "<< sum << endl;
           break;
       }
       s =s->sigFil;
   }while(s->nFil != 0);
}

void HojaCalc::sumarColu(int columna){
     nodo *s = pHE;
   do{
       if(s->nCol == columna){
           int sum = 0;
           do{
               sum += s->dato;
               s=s->sigFil;
           }while(s->nFil != 0);
           cout <<"Suma de la columna "<<columna<<": "<< sum << endl;
           break;
       }
       s =s->sigCol;
   }while(s->nCol != 0);
}

int main(void)
{
    nodo *s;
    int totalfilas, totalcolum, fil, col, i;


    cout << "Para inicializar la hoja de cclculo proporcione la" << endl;
    cout << "cantidad de filas y columnas que contendra:" << endl
         << endl;
    cout << "Total de filas: ";
    cin >> totalfilas;
    cout << "Total de columnas: ";
    cin >> totalcolum;

    HojaCalc hojaCalculo(totalfilas, totalcolum);

    hojaCalculo.imprimir();


    hojaCalculo.insNodo();
    int colum=0, fila=0;
    cout<<"Que fila desea sumar? "<<endl;
    cin>>fila;
    cout<<"Que columna desea sumar? "<<endl;
    cin>>colum;
  
    hojaCalculo.imprimir();
    hojaCalculo.sumarFila(fila);
    hojaCalculo.sumarColu(colum);

    cout << endl
         << endl;
    return 0;
}