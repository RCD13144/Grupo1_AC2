//
// Created by belen on 08/11/2023.
//

#ifndef GRUPO1_AC2_RECURSO1_H
#define GRUPO1_AC2_RECURSO1_H

#include <string>

using namespace std;
class Profesor;
class Alumno{
private:
    string nombre, apellido1, expediente;
    int claseAlumno;
    bool asignacion;
public:
    Alumno(){
        Alumno::nombre = "";
        Alumno::apellido1 = "";
        Alumno::expediente = "";
        Alumno::claseAlumno = 0;
    }
    Alumno(string n, string apel, string exp, int cl){
        Alumno::nombre = n;
        Alumno::apellido1 = apel;
        Alumno::expediente = exp;
        Alumno::claseAlumno = cl;
    }
    string toString(){
        return "Alumno[" + nombre+", "+apellido1+", "+expediente+", "+claseAlumno<<"]";
    }
    void asingarProfesor(Alumno a){
        asignacion = true;
    }
};
class Profesor{
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
