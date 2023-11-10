#include <iostream>
#include "Recurso1.h"
#include "Recurso3.h"
#include "Recurso5.h"
#include <random>
using namespace std;
void menuCalculadora();
void menuRegistroEInicio();
void menuJuego();
int main() {
    menuRegistroEInicio();
    return 0;
}
void menuJuego(){
    Juego juego = Juego();
    juego.menuJuego();
}
/**
 * Menus para recurso 1
 */

void menuGeneral(){
    int decision;
    bool salir = false;
    cout << "Que quieres hacer" << endl;
    cout << "1. Gestionar usuarios" << endl;
    cout << "2. Calculadora Avanzada" << endl;
    cout << "3. Juego" << endl;
    cout << "4. Salir del programa" << endl;
    cin >> decision;
    while(!salir) {
        switch (decision) {
            case 1:
                break;
            case 2:
                menuCalculadora();
                break;
            case 3:
                menuJuego();
                break;
            case 4:
                salir = true;
                break;
            default:
                cout << "Opcion incorrecta" << endl;
                break;
        }
    }
}

void menuRegistroEInicio(){
    int decisionLogin;
    bool seguir2;
    cout<<"Que quieres hacer?"<<endl;
    cout<<"1. Registrar nuevos usuarios"<<endl;
    cout<<"2. Iniciar sesion como un alumno"<<endl;
    cout<<"3. Iniciar sesion como un profesor"<<endl;
    cout<<"4. Salir"<<endl;
    cin>>decisionLogin;
    string nombre;
    string apellido;
    int numUsuario;
    int numAlumnos;
    srand(time(0));
    int id = rand() % 1000 + 1;
    int contrasena;
    Profesor p = Profesor(nombre, apellido, numUsuario,id,numAlumnos);
    Profesor* pp = &p;
    Alumno a = Alumno(nombre, apellido, numUsuario, id);
    Alumno* pa = &a;
    RegistroYLogin ryl = RegistroYLogin();
    RegistroYLogin* pryl = &ryl;
    while(seguir2) {
        switch (decisionLogin) {
            case 1:
                int decision;
                cin >> decision;
                cout << "Quien eres?" << endl;
                cout << "1. Profesor" << endl;
                cout << "2. Alumno" << endl;
                cout << "3. Volver" <<endl;
                switch (decision) {
                    case 1:
                        cout << "Introduce tu nombre" << endl;
                        cin >> nombre;
                        cout << "Introduce tu apellido" << endl;
                        cin >> apellido;
                        cout << "Introduce tu numero de usuario" << endl;
                        cin >> numUsuario;
                        cout<<"Cuantos alumnos va a haber en tu clase"<<endl;
                        cin>>numAlumnos;
                        p = Profesor(nombre, apellido, numUsuario, id, numAlumnos);
                        break;
                    case 2:
                        cout << "Introduce tu nombre" << endl;
                        cin >> nombre;
                        cout << "Introduce tu apellido" << endl;
                        cin >> apellido;
                        cout << "Introduce tu numero de usuario" << endl;
                        cin >> numUsuario;
                        a = Alumno(nombre, apellido, numUsuario, id);
                        break;
                    case 3:
                        seguir2 = false;
                        break;
                    default:
                        cout<<"Opcion erronea"<<endl;
                        break;
                }
                break;
            case 2:
                cout<<"Introduce tu id"<<endl;
                cin>>contrasena;
                pryl->iniciarSesionAlumno(contrasena);
                cout<<"Quieres meterle una actividad?"<<endl;
                break;
            case 3:

                break;
            case 4:
                break;
            default:
                cout << "Opcion erronea" << endl;
                break;
        }
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
