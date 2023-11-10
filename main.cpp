#include <iostream>
#include "Recurso1.h"
#include "Recurso3.h"
#include <random>
using namespace std;
void menuCalculadora();
void menuGestionEstudiantes();
int main() {
    int decision;
    bool seguir = true;
    while(seguir) {
        cout << "Que quieres hacer" << endl;
        cout << "1. Gestionar estudiantes" << endl;
        cout << "2. Mochila de material digital" << endl;
        cout << "3. Calculadora Avanzada" << endl;
        cout << "4. Dar de alta o baja algun usuario" << endl;
        cout << "5. Juego" << endl;
        cout << "6. Salir del programa" << endl;
        cin >> decision;
        switch (decision) {
            case 1:
                menuGestionEstudiantes();
                break;
            case 2:
                break;
            case 3:
                menuCalculadora();
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                seguir = false;
                break;
            default:
                break;
        }
        return 0;
    }
}
/**
 * Menus para recurso 1
 */
void menuRegistrarse() {
    bool seguir2 = true;
    RegistroYLogin cyl = RegistroYLogin();
    RegistroYLogin* pcyl = &cyl;
    string nombre, apellido;
    int numU;
    bool cargo;
    int id;

    while (seguir2) {
        int decisionCargo;
        cout << "Que cargo vas a ostentar?" << endl;
        cout << "1. Profesor" << endl;
        cout << "2. Alumno" << endl;
        cout << "3. Salir" << endl;
        cin >> decisionCargo;


        switch (decisionCargo) {
            case 1:
                id = rand() % 1000 + 1;
                cargo = true;
                cout << "Introduce tu nombre" << endl;
                cin >> nombre;
                cout << "Introduce tu apellido" << endl;
                cin >> apellido;
                cout << "Introduce tu numero de usuario" << endl;
                cin >> numU;
                cout << "Tu id es el siguiente: " << id << ". Guardalo para iniciar sesion" << endl;
                pcyl->addUsuario(Profesor(nombre, apellido, numU, id));
                pcyl->leerUsuarios();
                break;
            case 2:
                id = rand() % 1000 + 1;
                cargo = false;
                cout << "Introduce tu nombre" << endl;
                cin >> nombre;
                cout << "Introduce tu apellido" << endl;
                cin >> apellido;
                cout << "Introduce tu numero de usuario" << endl;
                cin >> numU;
                cout << "Tu id es el siguiente: " << id << " Guardalo para iniciar sesion" << endl;
                pcyl->addUsuario(Alumno(nombre, apellido, numU, Profesor("", "", 0, 0), id));
                pcyl->leerUsuarios();
                break;
            case 3:
                seguir2 = false;
                break;
            default:
                cout << "Opcion erronea" << endl;
                break;
        }
    }
}
void menuIniciarSesion(){
    RegistroYLogin ryl = RegistroYLogin();
    RegistroYLogin* ryl1 = &ryl;
    int contrasena;
    cout<<"Introduce tu id para iniciar sesion"<<endl;
    cin>>contrasena;
    ryl1->iniciarSesion(contrasena);

}

void menuGestionEstudiantes(){
    int decisionLogin;
    cout<<"Que quieres hacer?"<<endl;
    cout<<"1. Registrarse"<<endl;
    cout<<"2. Iniciar sesion"<<endl;
    cin>>decisionLogin;
    switch(decisionLogin){
        case 1:
            menuRegistrarse();
            break;
        case 2:
            menuIniciarSesion();
            break;
        default:
            cout<<"Opcion erronea"<<endl;
            break;
    }

}

/**
 * Menus para recurso 3
 */
void menuCalcEnteros(){
    int decisionOperacion;
    bool salir = false;
    Calculadora<int> calcInt = Calculadora<int>();
    int operador1;
    int operador2;
    Matriz<int> m1 = Matriz<int>();
    Matriz<int> m2 = Matriz<int>();
    int nFilas1;
    int nColumnas1;
    int nFilas2;
    int nColumnas2;
    while(!salir){
        cout << "Calculadora de enteros" << endl;
        cout << "1) Suma de numeros" << endl;
        cout << "2) Resta de numeros" << endl;
        cout << "3) Multiplicacion de numeros" << endl;
        cout << "4) Division de numeros" << endl;
        cout << "5) Suma de matrices" << endl;
        cout << "6) Resta de matrices" << endl;
        cout << "7) Multiplicacion de matrices" << endl;
        cout << "8) Division de matriz y un numero" << endl;
        cout << "9) Multiplicacion de matriz y un numero" << endl;
        cout << "10) Salir" << endl;
        cin >> decisionOperacion;
        switch (decisionOperacion) {
            case 1:
                cout << "Introduzca el primer valor" << endl;
                cin >> operador1;
                cout << "Introduzca el segundo valor" << endl;
                cin >> operador2;
                cout << calcInt.sumar(operador1, operador2) << endl;
                break;
            case 2:
                cout << "Introduzca el primer valor" << endl;
                cin >> operador1;
                cout << "Introduzca el segundo valor" << endl;
                cin >> operador2;
                cout << calcInt.restar(operador1, operador2) << endl;
                break;
            case 3:
                cout << "Introduzca el primer valor" << endl;
                cin >> operador1;
                cout << "Introduzca el segundo valor" << endl;
                cin >> operador2;
                cout << calcInt.multiplicar(operador1, operador2) << endl;
                break;
            case 4:
                cout << "Introduzca el primer valor" << endl;
                cin >> operador1;
                cout << "Introduzca el segundo valor" << endl;
                cin >> operador2;
                cout << calcInt.dividir(operador1, operador2) << endl;
                break;
            case 5:
                cout << "Matriz 1" << endl;
                cout << "Introduzca el numero de filas de la matriz 1" << endl;
                cin >> nFilas1;
                cout << "Introduzca el numero de columnas de la matriz 1" << endl;
                cin >> nColumnas1;
                try{
                    m1.llenarMatriz(nFilas1,nColumnas1);
                }
                catch (const char* mensaje) {
                    cerr << mensaje << endl;
                }
                m1.verMatriz();
                cout << "Matriz 2" << endl;
                cout << "Introduzca el numero de filas de la matriz 2" << endl;
                cin >> nFilas2;
                cout << "Introduzca el numero de columnas de la matriz 2" << endl;
                cin >> nColumnas2;
                try{
                    m2.llenarMatriz(nFilas2, nColumnas2);
                }
                catch (const char* mensaje) {
                    cerr << mensaje << endl;
                }
                m2.verMatriz();
                calcInt.sumar(m1, m2).verMatriz();
                break;
            case 6:
                cout << "Matriz 1" << endl;
                cout << "Introduzca el numero de filas de la matriz 1" << endl;
                cin >> nFilas1;
                cout << "Introduzca el numero de columnas de la matriz 1" << endl;
                cin >> nColumnas1;
                try{
                    m1.llenarMatriz(nFilas1,nColumnas1);
                }
                catch (const char* mensaje) {
                    cerr << mensaje << endl;
                }
                m1.verMatriz();
                cout << "Matriz 2" << endl;
                cout << "Introduzca el numero de filas de la matriz 2" << endl;
                cin >> nFilas2;
                cout << "Introduzca el numero de columnas de la matriz 2" << endl;
                cin >> nColumnas2;
                try{
                    m2.llenarMatriz(nFilas2, nColumnas2);
                }
                catch (const char* mensaje) {
                    cerr << mensaje << endl;
                }
                m2.verMatriz();
                calcInt.restar(m1, m2).verMatriz();
                break;
            case 7:
                cout << "Matriz 1" << endl;
                cout << "Introduzca el numero de filas de la matriz 1" << endl;
                cin >> nFilas1;
                cout << "Introduzca el numero de columnas de la matriz 1" << endl;
                cin >> nColumnas1;
                try{
                    m1.llenarMatriz(nFilas1,nColumnas1);
                }
                catch (const char* mensaje) {
                    cerr << mensaje << endl;
                }
                m1.verMatriz();
                cout << "Matriz 2" << endl;
                cout << "Introduzca el numero de filas de la matriz 2" << endl;
                cin >> nFilas2;
                cout << "Introduzca el numero de columnas de la matriz 2" << endl;
                cin >> nColumnas2;
                try{
                    m2.llenarMatriz(nFilas2, nColumnas2);
                }
                catch (const char* mensaje) {
                    cerr << mensaje << endl;
                }
                m2.verMatriz();
                calcInt.multiplicar(m1, m2).verMatriz();
                break;
            case 8:
                cout << "Matriz 1" << endl;
                cout << "Introduzca el numero de filas de la matriz 1" << endl;
                cin >> nFilas1;
                cout << "Introduzca el numero de columnas de la matriz 1" << endl;
                cin >> nColumnas1;
                try{
                    m1.llenarMatriz(nFilas1,nColumnas1);
                }
                catch (const char* mensaje) {
                    cerr << mensaje << endl;
                }
                m1.verMatriz();
                cout << "Introduzca el numero" << endl;
                cin >> operador1;
                calcInt.dividir(m1, operador1).verMatriz();
                break;
            case 9:
                cout << "Matriz 1" << endl;
                cout << "Introduzca el numero de filas de la matriz 1" << endl;
                cin >> nFilas1;
                cout << "Introduzca el numero de columnas de la matriz 1" << endl;
                cin >> nColumnas1;
                try{
                    m1.llenarMatriz(nFilas1,nColumnas1);
                }
                catch (const char* mensaje) {
                    cerr << mensaje << endl;
                }
                m1.verMatriz();
                cout << "Introduzca el numero" << endl;
                cin >> operador1;
                calcInt.multiplicar(m1,operador1).verMatriz();
                break;
            case 10:
                salir = true;
            default:
                cout << "Opcion invalida" << endl;
        }
    }
}
void menuCalcDouble(){
    bool salir = false;
    int decisionOperacion;
    Calculadora<double> calcDouble = Calculadora<double>();
    double operador1;
    double operador2;
    Matriz<double> m1 = Matriz<double>();
    Matriz<double> m2 = Matriz<double>();
    int nFilas1;
    int nColumnas1;
    int nFilas2;
    int nColumnas2;
    while(!salir){
        cout << "Calculadora de Double" << endl;
        cout << "1) Suma de numeros" << endl;
        cout << "2) Resta de numeros" << endl;
        cout << "3) Multiplicacion de numeros" << endl;
        cout << "4) Division de numeros" << endl;
        cout << "5) Suma de matrices" << endl;
        cout << "6) Resta de matrices" << endl;
        cout << "7) Multiplicacion de matrices" << endl;
        cout << "8) Division de matriz y un numero" << endl;
        cout << "9) Multiplicacion de matriz y un numero" << endl;
        cin >> decisionOperacion;
        switch (decisionOperacion) {
            case 1:
                cout << "Introduzca el primer valor" << endl;
                cin >> operador1;
                cout << "Introduzca el segundo valor" << endl;
                cin >> operador2;
                cout << calcDouble.sumar(operador1, operador2) << endl;
                break;
            case 2:
                cout <<"Introduzca el primer valor" << endl;
                cin >> operador1;
                cout << "Introduzca el segundo valor" << endl;
                cin >> operador2;
                cout << calcDouble.restar(operador1, operador2) << endl;
                break;
            case 3:
                cout << "Introduzca el primer valor" << endl;
                cin >> operador1;
                cout << "Introduzca el segundo valor" << endl;
                cin >> operador2;
                cout << calcDouble.multiplicar(operador1, operador2) << endl;
                break;
            case 4:
                cout << "Introduzca el primer valor" << endl;
                cin >> operador1;
                cout << "Introduzca el segundo valor" << endl;
                cin >> operador2;
                cout << calcDouble.dividir(operador1, operador2) << endl;
                break;
            case 5:
                cout << "Matriz 1" << endl;
                cout << "Introduzca el numero de filas de la matriz 1" << endl;
                cin >> nFilas1;
                cout << "Introduzca el numero de columnas de la matriz 1" << endl;
                cin >> nColumnas1;
                try{
                    m1.llenarMatriz(nFilas1,nColumnas1);
                }
                catch (const char* mensaje) {
                    cerr << mensaje << endl;
                }
                m1.verMatriz();
                cout << "Matriz 2" << endl;
                cout << "Introduzca el numero de filas de la matriz 2" << endl;
                cin >> nFilas2;
                cout << "Introduzca el numero de columnas de la matriz 2" << endl;
                cin >> nColumnas2;
                try{
                    m2.llenarMatriz(nFilas2, nColumnas2);
                }
                catch (const char* mensaje) {
                    cerr << mensaje << endl;
                }
                m2.verMatriz();
                calcDouble.sumar(m1, m2).verMatriz();
                break;
            case 6:
                cout << "Matriz 1" << endl;
                cout << "Introduzca el numero de filas de la matriz 1" << endl;
                cin >> nFilas1;
                cout << "Introduzca el numero de columnas de la matriz 1" << endl;
                cin >> nColumnas1;
                try{
                    m1.llenarMatriz(nFilas1,nColumnas1);
                }
                catch (const char* mensaje) {
                    cerr << mensaje << endl;
                }
                m1.verMatriz();
                cout << "Matriz 2" << endl;
                cout << "Introduzca el numero de filas de la matriz 2" << endl;
                cin >> nFilas2;
                cout << "Introduzca el numero de columnas de la matriz 2" << endl;
                cin >> nColumnas2;
                try{
                    m2.llenarMatriz(nFilas2, nColumnas2);
                }
                catch (const char* mensaje) {
                    cerr << mensaje << endl;
                }
                m2.verMatriz();
                calcDouble.restar(m1, m2).verMatriz();
                break;
            case 7:
                cout << "Matriz 1" << endl;
                cout << "Introduzca el numero de filas de la matriz 1" << endl;
                cin >> nFilas1;
                cout << "Introduzca el numero de columnas de la matriz 1" << endl;
                cin >> nColumnas1;
                try{
                    m1.llenarMatriz(nFilas1,nColumnas1);
                }
                catch (const char* mensaje) {
                    cerr << mensaje << endl;
                }
                m1.verMatriz();
                cout << "Matriz 2" << endl;
                cout << "Introduzca el numero de filas de la matriz 2" << endl;
                cin >> nFilas2;
                cout << "Introduzca el numero de columnas de la matriz 2" << endl;
                cin >> nColumnas2;
                try{
                    m2.llenarMatriz(nFilas2, nColumnas2);
                }
                catch (const char* mensaje) {
                    cerr << mensaje << endl;
                }
                m2.verMatriz();
                calcDouble.multiplicar(m1, m2).verMatriz();
                break;
            case 8:
                cout << "Matriz 1" << endl;
                cout << "Introduzca el numero de filas de la matriz 1" << endl;
                cin >> nFilas1;
                cout << "Introduzca el numero de columnas de la matriz 1" << endl;
                cin >> nColumnas1;
                try{
                    m1.llenarMatriz(nFilas1,nColumnas1);
                }
                catch (const char* mensaje) {
                    cerr << mensaje << endl;
                }
                m1.verMatriz();
                cout << "Introduzca el numero" << endl;
                cin >> operador1;
                calcDouble.dividir(m1, operador1).verMatriz();
                break;
            case 9:
                cout << "Matriz 1" << endl;
                cout << "Introduzca el numero de filas de la matriz 1" << endl;
                cin >> nFilas1;
                cout << "Introduzca el numero de columnas de la matriz 1" << endl;
                cin >> nColumnas1;
                try{
                    m1.llenarMatriz(nFilas1,nColumnas1);
                }
                catch (const char* mensaje) {
                    cerr << mensaje << endl;
                }
                m1.verMatriz();
                cout << "Introduzca el numero" << endl;
                cin >> operador1;
                calcDouble.multiplicar(m1,operador1).verMatriz();
                break;
            case 10:
                salir = true;
            default:
                cout << "Opcion invalida" << endl;
        }
    }
}
void menuCalculadora(){
    int decisionTipo;
    bool salir = false;
    while(!salir){
        cout << "Bienvenido a la calculadora!" << endl;
        cout << "Con que datos quiere operar?" << endl;
        cout << "1) Tipo entero" << endl;
        cout << "2) Tipo double" << endl;
        cout << "3) Salir";
        cin >> decisionTipo;
        switch (decisionTipo) {
            case 1:
                menuCalcEnteros();
                break;
            case 2:
                menuCalcDouble();
                break;
            case 3:
                salir = true;
                break;
            default:
                cout << "Opcion no valida" << endl;
        }
    }

}

