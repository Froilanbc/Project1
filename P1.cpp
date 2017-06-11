// Librerias 
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>

// Namespaces
using namespace std;

// Crear clases contenidas
struct TPoint
{
    string nombre;         //nombre del punto
    string tipo;                //gasolinera, cajero, restaurante,etc.
    float x;                    //coordenada x
    float y;                    //coordenada y
    char c;                     //estado
};

//Creamos la clase
class CMapa
{
    string nombreArchivo;
    string ciudad;
    vector <TPoint> listaPuntos;
    
public:
    //Declaración de constructores
    CMapa ()
    {
        ciudad = "Lima";
        nombreArchivo = "datos.txt";
    }
    CMapa (string ciudad, string nombre )
    {
        this->ciudad = ciudad;
        this->nombreArchivo = nombreArchivo;
    }
    
    //Métodos de procesamiento
    //Se crea el archivo
    void grabarArchivo()
    {
        ofstream archivo(nombreArchivo);
        archivo << "Nombre, posición x, posición y" << endl;
        for (auto punto: listaPuntos)
            archivo << punto.nombre << ", " << punto.x << ", " << punto.y << endl;
            archivo.close();
    }
    
    //Opción 1
    void agregar( string nombre, string tipo, float x, float y, char c)
    {
        listaPuntos.push_back({nombre,tipo,x,y,c});
        grabarArchivo();
    }
    
    //Eliminar punto
    void eliminar(string nombre)
    {
        for (int i = 0; i <100 ; i++) 
        {
            if(listaPuntos[i].nombre == nombre)
            listaPuntos.erase(listaPuntos.begin()+i);
        }
        grabarArchivo();
    }
        
    //Lista
    void listarPuntos()
    {
        for (auto punto : listaPuntos) 
        {
            cout<<"Punto(x,y): "<<punto.nombre<<" ("<<punto.x<<", "<<punto.y<<") ";
            grabarArchivo();
        }
    }
    
    //Listar puntos ubicados a menos de 10 metros
    void listarpuntoscercanos()
    {
        string a;
        cout<<"Ingrese nombre: "; cin>>a;
        cout<<"La lista de los puntos ubicados a 10 metros son: "<<endl; 
        for (auto punto : listaPuntos)
        {
            if ( punto.nombre==a)
            for (auto punto1 : listaPuntos) 
            {
                float distancia;
                distancia = sqrt( pow(punto.x-punto1.x,2)+pow(punto.y-punto1.y,2));
                if ( distancia < 10 && distancia!=0)
                cout<< punto1.nombre << " ("<< punto1.x << ", "<<punto1.y<<" )"<<endl;
            }
        }
        
    }
    
};

//Se crea el MENÚ
int menu()
{
    int opcion = 0;
    
    do
    {
        system("clear");
        // Saludo
        cout << "¡Bienvenido a TuMapa! Este programa te ayudará a ubicar lugares como restaurantes, cajeros, paraderos y agregar tus lugares preferidos. " << endl;
        cout << "MENÚ" << endl;
        cout << string (4, '-') << endl << endl;
        
        cout << "1. Agregar una nueva posición" << endl;
        cout << "2. Eliminar una posición por nombre" << endl;
        cout << "3. Listar 100 primeros puntos" << endl;
        cout << "4. Listar los puntos ubicados a menos de 10 metros" << endl;
        cout << "5. Calcular la distancia promedio entre cada punto" << endl;
        cout << "6. Determinar la distancia entre los puntos más lejanos" << endl;
        cout << "7. Determinar la distancia más corta entre los puntos" << endl;
        cout << "8. Listar tipo de lugar" << endl;
        cout << "9. Distancia entre tu posición y la posición dónde quieres ir" << endl;
        
        cout << "0. Para salir" << endl << endl;
        cout << "Opción: ";
        cin >> opcion;
    } 
    
    while (opcion < 0 || opcion > 9);
    return opcion;
}

int main()
{
    CMapa mapa;         //Mapa de Lima
    int opcion=0;
    string nombre;
    string tipo;
    float x,y;
    char c;
    
    do
    {
        opcion = menu();        //Opción menu
        
        //Switch de opciones
        switch(opcion)
        {
        case 1:     //Agregar puntos
            system("clear");
            cout<<"Ingrese el nombre: "; cin>>nombre; 
            cout<<"Ingrese el tipo: "; cin>>tipo;
            cout<<"Ingrese el valor de las abscisas(x): ";cin>>x;
            cout<<"Ingrese el valor de las ordenadas(y):";cin>>y;
            cout<<"Ingrese el estado ( A=abierto, C=cerrado, D=desocupado ): ";cin>>c;
            mapa.agregar(nombre,tipo,x,y,c);
            break;
            
        case 2:     //Eliminar punto
            system("clear");
            cout<<"Ingrese el nombre del punto a borrar: "; cin>>nombre;
            mapa.eliminar(nombre);
            break;
            
        case 3:     //Lista de puntos
            system("clear");
            mapa.listarPuntos();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get();
            break;
          
        case 4:
            system("clear");
            mapa.listarpuntoscercanos();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get();
            break;
            
        }
    }
    while(opcion!=0);
    
    return 0;
}








