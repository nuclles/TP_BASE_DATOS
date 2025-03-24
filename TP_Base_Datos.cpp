#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#include <cstdlib>



using namespace std;
class Tabla_Datos;
struct Datos{
	int clave;
	Tabla_Datos* dir;
	string valor;
};

class Tabla_Datos{	

private:
	int clave;
	string valor;
	Tabla_Datos *dir;
	
public:
	Tabla_Datos(){
		this->clave=0;
		this->valor="";
		this->dir=nullptr;
	}
	 Tabla_Datos ( Datos _datos){
		this->clave=_datos.clave;
		this->valor=_datos.valor;
		this->dir=_datos.dir;
	}
	int get_clave(){
		return clave;
	}
	string get_valor(){
		return valor;
	}
	Tabla_Datos* get_dir(){
		return dir;
	}
   
};

class Tabla_Indice{
private:
	int TI_clave;
	Tabla_Datos *TI_dir;

public:
	Tabla_Indice(){
	this->TI_clave=0;
	this->TI_dir=nullptr;
	}
	Tabla_Indice(Datos _datos){
		this->TI_clave=_datos.clave;
		this->TI_dir=_datos.dir;
	}
	int get_TI_clave(){
		return TI_clave;
	}
	Tabla_Datos* get_TI_dir(){
		return TI_dir;
	}
	
};

class Gestor{
private:
	vector<Tabla_Datos> TD;
	vector<Tabla_Indice> TI;
	int contador;
	size_t TD_maxTamanio;
	size_t TI_maxTamanio;
public:

string Consultar(int Clave_Usuario){
		auto I=find_if(TD.begin(), TD.end(),
					   [Clave_Usuario](Tabla_Datos &td) {
						   return td.get_clave() == Clave_Usuario;
					   });
		if (I!= TD.end()){
			return I->get_valor();}
			
		else{
			return "Clave no encontrada";
			}
	
	}
void Start(){
		//TD.resize(30);
		//TI.resize(3);
	contador=0;
	TD_maxTamanio=30;
	TI_maxTamanio=3;
}
void Insertar(int _clave, string _valor){
	if (contador >=30){
		cout<<"No hay mas lugar en el vector"<<endl;
		return;
	}
	Datos aux;
	aux.clave=_clave;
	aux.valor=_valor;
	aux.dir=NULL;

	cout<<"\nEL tamanio del vector de datos actualmente es de :"<<TD.size()<<endl;
	cout<<"EL tamanio del vector de indices actualmente es de :"<<TI.size()<<endl<<endl;
	
	TD.push_back(Tabla_Datos(aux));
	
	if((contador %4 ==0) && (contador<20)){
		

		aux.dir=&TD[contador];
		if(aux.dir==nullptr){
			cout<<"ERROR -> NO EXISTE";
			return;
		}
		TI.push_back(Tabla_Indice(aux));
		cout<<"Se agrego la clave "<<_clave<<" en la posicion "<<TI.size()-1<<endl;
	}
	if ((contador >= 20)){
		cout<<endl<<"Se guardo en el overflow"<<endl;
	}
	contador++;
	}
};

void prueba_consulta(Gestor &pepe) {
	
	int n;
	cout << "Clave a buscar: ";
	cin >> n;
	
	cout << pepe.Consultar(n) << endl;
}


#include <iostream>
using namespace std;

void Menu() {
    cout << "\n###### MENU ######" << endl;
    cout << "1. Ingresar clave" << endl;
    cout << "2. Consultar clave" << endl;
	cout<<"3. Mostrar menu"<<endl;
    cout << "4. Salir" << endl;
    cout << "Elige una opcion: "<<endl;
}

int main() {
    Gestor BD;
    BD.Start();
    
    int opcion;
        Menu();
	do{
        cin >> opcion;
        switch (opcion) {
            case 1: {
                int clave;
                string valor;
                cout << "Ingrese clave: ";
                cin >> clave;
                cout << "Ingrese valor: ";
                cin.ignore();  // Evita problemas con getline
                getline(cin, valor);
                BD.Insertar(clave, valor);
				cout<<"\nOpcion: "<<endl;break;
            }
            case 2:
                prueba_consulta(BD);
				cout<<"\nOpcion: "<<endl;break;
			case 3:Menu();break;
            case 4:
                cout << "Saliendo del programa" << endl;break;
            default:
                cout << "Opción inválida" << endl;
        }
    } while (opcion != 4);

    return 0;
}