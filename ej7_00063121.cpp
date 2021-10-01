// Ejercicio opcional al 7 de ordenes de pupusas.
#include <iostream>
#include <string>

using namespace std;


struct Nodo{

    int cantidad_pupusas;
    string tipo_pupusas;
    string si_coca;
    string ingredientes;
    
    Nodo *sig; 

};


class Orden
{
private:
    /* data */
    Nodo *pInicio;

public:

    Orden();
    ~Orden();
    Orden(int, string, string, string);
    // void insertNodo();
    void insInicio(int, string, string, string);
    void mostrarLista();
  
};


Orden::Orden(void)
{
    pInicio = NULL; 
}

Orden::Orden(int cantidad_pupusas, string tipo_pupusas, string si_coca, string ingredientes){

    pInicio = NULL; 
    insInicio(cantidad_pupusas, tipo_pupusas, si_coca, ingredientes);
}


Orden::~Orden(){

    Nodo *p;
    while (pInicio)
    {
        p = pInicio;
        pInicio = pInicio -> sig;
        delete p;

    }
}


void Orden::insInicio(int c, string tipo, string coca, string ing)
{
    Nodo *nuevo, *saltarin;
    nuevo = new Nodo;

    nuevo -> cantidad_pupusas = c;
    nuevo ->tipo_pupusas = tipo;
    nuevo -> si_coca = coca;
    nuevo -> ingredientes = ing;

    nuevo -> sig = pInicio;
    pInicio = nuevo;
    
}


void Orden::mostrarLista()
{
    cout << "---- Datos de su orden: ---- " << endl;
    Nodo *saltarin;
    saltarin = pInicio;
    
    while (saltarin != NULL)
    {
        cout << saltarin -> cantidad_pupusas << " Pupusas de " << saltarin -> tipo_pupusas << "." << endl;
        cout << saltarin -> si_coca << " quiere una Coca-cola en su orden." << endl;
        cout << "Los ingredientes de sus pupusas serian: " << saltarin -> ingredientes << "." << endl;
        saltarin = saltarin -> sig; 

    }
    
}


int menu(){

    int opcion = 0;
    cout << endl;
    cout << "1) Crear una nueva orden." << endl;
    cout << "2) Mostrar su orden de nuevo para verificar." << endl;
    cout << "3) Terminar." << endl;
    cout << "Opcion: ";
    cin >> opcion; cin.ignore();
    cout << endl;
    return opcion;
}


int main(void)
{
    /* code */
    Orden orden1;

    int nump = 0;
    string tipo = "", coca = "", ingr = "";
    bool continuar = true;

    cout << endl;
    cout << " ------- Bienvenido a nuestro servicio de orden -------" << endl << endl;
    cout << "Nuestras especialidades en pupusas son: " << endl << endl;
    cout << "Frijol con Queso [F/Q], Revueltas [R], Queso [Q], Queso con Loroco [Q/L]" << endl << endl;


    do
    {
        /* code */
        switch (menu())
        {
        case 1:
            /* code */

            cout << "Cantidad de pupusas a ordenar: ";
            cin >> nump; cin.ignore();

            cout << "Sus pupusas se harian con masa de [Arroz/Maiz]: ";
            getline(cin,tipo);

            cout << "Acompaña una Coca-Cola a su orden [Si/No]: " ;
            getline(cin,coca);

            cout << "Ingredientes de sus pupusas(revisar menu): ";
            getline(cin,ingr);

            orden1.insInicio(nump, tipo, coca, ingr);
            cout << endl;
            orden1.mostrarLista();
            break;
        
         

        case 2:
            
            orden1.mostrarLista();
            break;

        case 3:
        
            continuar = false;
            break;
        
        default:
            break;
        }
    } while (continuar);

    return 0;

}