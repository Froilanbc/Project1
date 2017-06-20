#include <iostream>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <cstdlib>

using namespace std;

//estructura
struct TPoint
{
    string nombre;
    string tipo;
    float x;
    float y;
    char estado;
};

//clase 
class CMapa
{
    string nombreArchivo;
    string ciudad;
    vector<TPoint>lista;
    
public:
    
    //constructores
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
    
    //metodos de procesamiento
    
    //crear el archivo
    void grabarArchivo()
    {
        ofstream archivo(nombreArchivo);
        archivo<<"Nombre, Tipo, Posicion X, Posicion Y, Estado"<<endl;
        for (auto dato: lista) 
        {
            archivo<<dato.nombre<<", "<<dato.tipo<<", "<<dato.x<<", "<<dato.y<<" ,"<<dato.estado<<endl;
        }
        archivo.close();
    }
    
    //agregar punto (opcion 1)
    void agregar()
    {
        string nombre, tipo;
        float x,y;
        char estado;
        cout<<"Ingrese el nombre del punto: "; cin>>nombre;
        cout<<"Ingrese el tipo de lugar: "; cin>>tipo;
        cout<<"Ingrese el valor de x: "; cin>>x;
        cout<<" Ingrese el valor de y: "; cin>>y;
        cout<<" Ingrese el estado del lugar ( A=abierto, C=cerrado, D=desocupado ): "; cin>>estado;
        lista.push_back({nombre, tipo, x, y, estado});
        lista.push_back(TPoint{"UTEC","Universidad",20,18,'A'});
        lista.push_back(TPoint{"METRO","Supermercado",35,8,'A'});
        lista.push_back(TPoint{"MIFARMA","Farmacia",18,89,'A'});
        lista.push_back(TPoint{"PUCP","Universidad",89,64,'A'});
        lista.push_back(TPoint{"PETROPERU","Grifo",5,13,'A'});
        lista.push_back(TPoint{"FUSEN","Chifa",33,56,'A'});
        lista.push_back(TPoint{"PIURANO","Restaurant",75,19,'A'});
        lista.push_back(TPoint{"RUSTICA","Discoteca",36,11,'A'});
        lista.push_back(TPoint{"GOUPH","Bar",77,52,'A'});
        lista.push_back(TPoint{"ESTADIO_NACIONAL","Estadio",9,14,'A'});
        lista.push_back(TPoint{"HUACHIPA","Zoologico",103,93,'A'});
        lista.push_back(TPoint{"BCP","Banco",45,15,'A'});
        lista.push_back(TPoint{"BBVA","Banco",73,17,'A'});
        lista.push_back(TPoint{"HORNERO","restaurant",12,35,'A'});
        grabarArchivo();
    }
    
    //eliminar punto (opcion 2)
    void eliminar()
    {
        string nombre;
        cout<<"Ingrese el nombre del punto a eliminar: "; cin>>nombre;
        for (int i=lista.size()-1 ; i>=0; i--)
        {
            if (lista[i].nombre == nombre)
            lista.erase(lista.begin()+i);
        }
        grabarArchivo();
    }
    
    //lista de puntos (opcion 3)
    void listar()
    {
        lista.push_back(TPoint{"UTEC","Universidad",20,18,'A'});
        lista.push_back(TPoint{"METRO","Supermercado",35,8,'A'});
        lista.push_back(TPoint{"MIFARMA","Farmacia",18,89,'A'});
        lista.push_back(TPoint{"PUCP","Universidad",89,64,'A'});
        lista.push_back(TPoint{"PETROPERU","Grifo",5,13,'A'});
        lista.push_back(TPoint{"FUSEN","Chifa",33,56,'A'});
        lista.push_back(TPoint{"PIURANO","Restaurant",75,19,'A'});
        lista.push_back(TPoint{"RUSTICA","Discoteca",36,11,'A'});
        lista.push_back(TPoint{"GOUPH","Bar",77,52,'A'});
        lista.push_back(TPoint{"ESTADIO_NACIONAL","Estadio",9,14,'A'});
        lista.push_back(TPoint{"HUACHIPA","Zoologico",103,93,'A'});
        lista.push_back(TPoint{"BCP","Banco",45,15,'A'});
        lista.push_back(TPoint{"BBVA","Banco",73,17,'A'});
        lista.push_back(TPoint{"HORNERO","restaurant",12,35,'A'});
        for (auto dato : lista) 
        {
            cout<<"Punto: "<<dato.nombre<<", "<<dato.tipo<<" ("<<dato.x<<", "<<dato.y<<") "<<dato.estado<<endl;
        }
    }
    
    void listaDePuntosCercanos()
    {
        string nombre;
        cout<<"Ingrese el nombre del lugar: "; cin>>nombre;
        cout<<"La lista de los puntos ubicados a menos de 100 metros son: "<<endl; 
        for (auto dato : lista)
        {
            if ( dato.nombre==nombre)
            for (auto dato1 : lista) 
            {
                float d;
                d = sqrt( pow(dato.x-dato1.x,2)+pow(dato.y-dato1.y,2));
                if ( d < 100 && d !=0 )
                cout<<"Punto:" <<dato1.nombre<<", "<<dato1.tipo<<" ("<<dato1.x<<", "<<dato1.y<<") "<<dato1.estado<<endl;
            }
        }
        grabarArchivo();
    }
    
    void distanciaPromedioEntrePuntos()
    {
        float total = 0.0;
        float promedio = 0.0;
        for (auto dato : lista)
        {
            for (auto dato1 : lista) 
            {
                total+=sqrt( pow(dato.x-dato1.x,2)+pow(dato.y-dato1.y,2));
            }
        }
        int a;
        a=lista.size();
        promedio = total / (a*(a-1));
        cout<< "El distancia promedio entre los puntos es: "<< promedio;
    }
    
    void mayorDistancia()
    {
        float d=0.0;
        for (auto dato : lista) 
        {
            for (auto dato1 : lista) 
            {
                d= sqrt( pow(dato.x-dato1.x,2)+pow(dato.y-dato1.y,2));
                if(d==max({d}))
                break;
            }
        }
        cout<<"La maxima distancia es: "<<max({d});
    }   
    
    void menorDistancia()
    {
        float d=0.0;
        for (auto dato : lista) 
        {
            for (auto dato1 : lista) 
            {
                d= sqrt( pow(dato.x-dato1.x,2)+pow(dato.y-dato1.y,2));
                if(d==min({d}))
                break;
            }
        }
        cout<<"La mínima distancia es: "<<min({d});
    }
    
    void tipoDeLugar()
    {
        string tipo;
        cout<<"Ingrese el tipo de lugar: "; cin>>tipo;
        cout<< "La lista de "<<tipo<<"(s)(es)"<<" es : "<<endl;
        for (auto dato : lista) 
        {
            if( dato.tipo == tipo )
            cout<<"Punto: "<<dato.nombre<<" ("<<dato.x<<", "<<dato.y<<") "<<dato.estado<<endl;
        }
    }
    
    void lugarDeDestino()
    {
        float d=0.0;
        string nombre;
        cout<<"Ingrese el lugar donde se encuentra: "; cin>>nombre;
        string nombre1;
        cout<<"Ingrese el lugar de destino: "; cin>>nombre1;
        for (auto dato : lista) 
        {
            for (auto dato1 : lista) 
            {
                if ( dato.nombre==nombre && dato1.nombre ==nombre1 )
                d=sqrt( pow(dato.x-dato1.x,2)+pow(dato.y-dato1.y,2));
            }
        }
        cout<<"La distancia al lugar de destino es: "<<d;
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
    
    vector<TPoint>lista;
    lista.push_back(TPoint{"UTEC","Universidad",20,18,'A'});
    lista.push_back(TPoint{"METRO","Supermercado",35,8,'A'});
    lista.push_back(TPoint{"MIFARMA","Farmacia",18,89,'A'});
    lista.push_back(TPoint{"PUCP","Universidad",89,64,'A'});
    lista.push_back(TPoint{"PETROPERU","Grifo",5,13,'A'});
    lista.push_back(TPoint{"FUSEN","Chifa",33,56,'A'});
    lista.push_back(TPoint{"PIURANO","Restaurant",75,19,'A'});
    lista.push_back(TPoint{"RUSTICA","Discoteca",36,11,'A'});
    lista.push_back(TPoint{"GOUPH","Bar",77,52,'A'});
    lista.push_back(TPoint{"ESTADIO_NACIONAL","Estadio",9,14,'A'});
    lista.push_back(TPoint{"HUACHIPA","Zoologico",103,93,'A'});
    lista.push_back(TPoint{"BCP","Banco",45,15,'A'});
    lista.push_back(TPoint{"BBVA","Banco",73,17,'A'});
    lista.push_back(TPoint{"HORNERO","restaurant",12,35,'A'});
    
    
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
            mapa.listar();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get();
            break;
          
        case 4:
            system("clear");
            mapa.listaDePuntosCercanos();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get();
            break;
            
        case 5:
            system("clear");
            mapa.distanciaPromedioEntrePuntos();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get();
            break;
            
        case 6:    
            system("clear");
            mapa.mayorDistancia();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get();
            break;
        
        case 7:    
            system("clear");
            mapa.menorDistancia();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get();
            break;
            
        case 8:
            system("clear");
            mapa.tipoDeLugar();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get();
            break;
        
        case 9:
            system("clear");
            mapa.lugarDeDestino();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get();
            break;
        }
    }
    while(opcion!=0);
    
    return 0;
}



