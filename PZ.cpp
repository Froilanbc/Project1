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
    void agregar()
    {
        string nombre, tipo;
        float x, y;
        char c;
        cout<<"Ingrese el nombre: "; cin>>nombre; 
        cout<<"Ingrese el tipo : "; cin>>tipo;
        cout<<"Ingrese el valor de las abscisas(x): ";cin>>x;
        cout<<"Ingrese el valor de las ordenadas(y):";cin>>y;
        cout<<"Ingrese el estado ( A=abierto, C=cerrado, D=desocupado ): ";cin>>c;
        listaPuntos.push_back({nombre,tipo,x,y,c});
        grabarArchivo();
    }
    
    //Eliminar punto
    void eliminar()
    {
        string nombre;
        for (int i = 0; i <listaPuntos.size() ; i++) 
        {
            cout<<"Ingrese el nombre del punto a borrar: "; cin>>nombre;
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
            if ( listaPuntos.size() < 100)
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
                if ( distancia < 100 && distancia!=0 )
                cout<< punto1.nombre << " ("<< punto1.x << ", "<<punto1.y<<" )"<<endl;
            }
        }
        grabarArchivo();
    }
    
    
    
    //  Distancia promedio entre puntos
    void distanciapromedio()
    {
        vector <float> distancias;
        float d, suma, promedio;
        for (int i = 0; i < listaPuntos.size(); i++) 
        for (int j = i+1; j < listaPuntos.size()-i; j++) 
        {
            d=sqrt(pow(listaPuntos[i].x-listaPuntos[j].x , 2) + pow(listaPuntos[i].y - listaPuntos[j].y , 2 ));
            distancias.push_back(d);
        }
        for (int i = 0; i < distancias.size(); i++) 
        {
            suma+=distancias[i];
        }
        promedio=suma/distancias.size();
    }
    
    
    
    //Determinar la distancia entre puntos mas lejanos
    void mayorDistancia()
    {
        for (int i = 0; i <listaPuntos.size() ; i++) 
        {
            cout<<listaPuntos[i].nombre;
        }
    }
    
    //Determinar la distancia entre puntos mas cercanos
    void menorDistancia()
    {
        
    }
    
    //Lista tipo de lugar
    void tipoLugar()
    {
        string a;
        cout<<"Ingrese tipo: "; cin>>a;
        cout<<"La lista de los tipos de lugares son: "; 
        for (auto punto : listaPuntos)
        {
            if ( punto.tipo==a)
            cout<< punto.nombre << " ("<< punto.x << ", "<<punto.y<<" )"<<endl;
        }
    }
    
    //Lugar de destino
    void lugarDestino()
    {
        string a,b;
        cout<<"Ingrese el lugar en donde esta:"; cin>>a;
        cout<<"Ingrese el lugar de destino: "; cin>>b;
        for (auto punto : listaPuntos) 
        {
            if(punto.nombre==a)
            for (auto punto1 : listaPuntos) 
            {
                if(punto1.nombre==b)
                {
                    float distancia;
                    distancia = sqrt( pow(punto.x-punto1.x,2)+pow(punto.y-punto1.y,2));
                    cout<<"La distancia al lugar de destino es: "<<distancia;
                }
            }
        }
        grabarArchivo();
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
        cout << "5. Calcular la distancia promedio entre cada punto" << endl;           //entre todos los puntos
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
    
    do
    {
        opcion = menu();        //Opción menu
        
        //Switch de opciones
        switch(opcion)
        {
        case 1:     //Agregar puntos
            system("clear");
            mapa.agregar();
            break;
            
        case 2:     //Eliminar punto
            system("clear");
            mapa.eliminar();
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
            
        case 5:
            system("clear");
            mapa.distanciapromedio();
            break;
        
        case 6:
            system("clear");
            mapa.mayorDistancia();
            break;
        
        case 7:
            system("clear");
            mapa.menorDistancia();
        
        case 8:
            system("clear");
            mapa.tipoLugar();
            break;
            
        case 9:
            system("clear");
            mapa.lugarDestino();
            break;
        }
    }
    while(opcion!=0);
    
    return 0;
}








