//
// Created by belen on 08/11/2023.
//

#ifndef GRUPO1_AC2_RECURSO1_H
#define GRUPO1_AC2_RECURSO1_H
#include <string>
using namespace std;
class Usuario{
private:
    string nombre, apellido;
    int numUsuario;
public:
    Usuario(string n, string a, int numU){
        Usuario::nombre = n;
        Usuario::apellido = a;
        Usuario::numUsuario = numU;
    }
};


class Alumno : public Usuario{
private:
    int claseAlumno;
public:
    Alumno() : Usuario(){

    }
    Alumno(int clase): Usuario(){
    }
    string toString(){
        //return "Alumno[" + nombre+", "+apellido1+", "+expediente+", "+claseAlumno<<"]";
    }
    void asingarProfesor(Alumno a){
    }
};
class Profesor : Usuario{
private:
    Alumno lista[8];
    int control;
public:
    Profesor() {
        Profesor::control = 0;
    }
    void anadirALista(Alumno a){
        lista[control] = a;
        control++;
    }
    void verLista(){
        for(int i=0;i<8;i++){
            cout<<lista[i].toString()<<endl;
        }
    }
};
#endif //GRUPO1_AC2_RECURSO1_H
