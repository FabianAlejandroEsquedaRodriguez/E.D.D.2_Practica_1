/*
Integrantes del equipo:
-> Domínguez Martínez, Edder Emmanuel. 
-> Esqueda Rodríguez, Fabián Alejandro.
-> Godoy Rodríguez, Berenice.
-> Gómez Jiménez, Ángel Armando.
-> Gómez Ramírez, Eduardo Fabián

Sección: D05
Calendario: 2021-A 
*/
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>

using namespace std;

void mostrar_linea(int, const char * const, double);

int main(){
    system("color F1");
    size_t op = 0;
    int cuenta;
    char nombre[30];
    double saldo;

    //Desde aqui se abre el archivo solo una vez, dentro del do while no, 
    //porque sino, se abriría y cerrara en cada vuelta
    ifstream ArchivoClientesEntrada; //archivo lógico

    ArchivoClientesEntrada.open("clientes.txt",ios::in);
    
    if(!ArchivoClientesEntrada){
        cerr << "No se pudo abrir el archivo"<<endl;
        exit(1);
    }

    do{
        cout<<"\t\t\tMENU-INVESTIGACION DE CREDITOS"<<endl<<endl;

        cout<<"1) Mostrar cuentas con saldo en ceros"<<endl;
        cout<<"2) Mostrar cuentas con saldo acreedor(-)"<<endl;
        cout<<"3) Mostrar cuentas con saldo deudor(+)"<<endl;
        cout<<"4) Salir"<<endl<<endl;

        cout<<"Elige una opcion: ";
        cin>>op;

        system("cls");

        if(op == 1){
            cout<<"\t\t\tCUENTAS CON SALDO EN CEROS"<<endl<<endl;
            cout <<left<<setw(10)<<"CUENTA"<<setw(13)<<"NOMBRE"<<"SALDO"<<endl<<fixed<<showpoint;

            while(ArchivoClientesEntrada>>cuenta>>nombre>>saldo){
                if(saldo == 0.0){
                    mostrar_linea(cuenta, nombre, saldo);
                }
            }
        }

        else if(op == 2){
            cout<<"\t\t\tCUENTAS CON SALDO EN ACREEDOR(-)"<<endl<<endl;
            cout <<left<<setw(10)<<"CUENTA"<<setw(13)<<"NOMBRE"<<"SALDO"<<endl<<fixed<<showpoint;

            while(ArchivoClientesEntrada>>cuenta>>nombre>>saldo){
                if(saldo < 0){
                    mostrar_linea(cuenta, nombre, saldo);
                }
            }
        }

        else if(op == 3){
            cout<<"\t\t\tCUENTAS CON SALDO EN DEUDOR(+)"<<endl<<endl;
            cout <<left<<setw(10)<<"CUENTA"<<setw(13)<<"NOMBRE"<<"SALDO"<<endl<<fixed<<showpoint;

            while(ArchivoClientesEntrada>>cuenta>>nombre>>saldo){
                if(saldo > 0){
                    mostrar_linea(cuenta, nombre, saldo);
                }
            }
        }

        else{
            break;
        }
        
        ArchivoClientesEntrada.clear();
        ArchivoClientesEntrada.seekg(0, ios::beg);//Para que me regrese al incio del archivo (desde el inicio del archivo, mueve el puntero 0 bytes)

        cout<<"\n\n\n";
        system("pause"); system("cls");

    }while(op != 4); //Fin del do while

    ArchivoClientesEntrada.close();
    return 0;

}//Fin del main

//mostrar cada registro del archivo
void mostrar_linea(int cuenta,const char * const nombre, double saldo){
  cout<< left << setw(10)<< cuenta << setw(13)<< nombre <<setw(7)<< setprecision(2)<<right<<saldo<<endl;
}
