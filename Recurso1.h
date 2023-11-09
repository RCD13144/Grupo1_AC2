//
// Created by belen on 08/11/2023.
//
#ifndef GRUPO1_AC2_RECURSO1_H
#define GRUPO1_AC2_RECURSO1_H

#include <string>
#include <sstream>
using namespace std;

class Usuario{
private:
    string nombre, apellido;
    bool cargo;
    int numUsuario;
    int id;
public:
    Usuario(string n, string a, int numU, int id){
        Usuario::nombre = n;
        Usuario::apellido = a;
        Usuario::numUsuario = numU;
        Usuario::id = id;
    }
    Usuario(){}
    string getNombre(){
        return nombre;
    }
    string getApellido(){
        return apellido;
    }
    int getNumUsuario(){
        return numUsuario;
    }
    int getId(){
        return id;
    }
    bool getCargo(){
        return cargo;
    }
    void setCargo(bool cargo){
        Usuario::cargo = cargo;
    }
    string conocerCargo(){

    }
    string toString(bool cargo){
        stringstream  ss;
        ss<<getNumUsuario();
        string numUAString = ss.str();
        ss<<getId();
        string idAString = ss.str();
        string valor;
        if (cargo=true){
            valor = "Profesor";
        }
        else{
            valor =  "Alumno";
        }
        return "["+valor+"("+nombre + ", "+apellido+", "+numUAString+", "+idAString+")]";
    }
};
class Alumno;
class Profesor : public Usuario{
private:
    int control;
    Alumno* listaAlumnos[8];
public:
    Profesor() : Usuario(){
    }
    Profesor(string n, string a, int numU, int id) : Usuario(n,a,numU,id){
        Profesor::control = 0;
    }
    void addAlumno(Alumno* a){
        listaAlumnos[control] = a;
        control++;
    }
    void verAlumnos(){
        for(int i=0;i<8;i++){
            cout<<listaAlumnos[i]<<endl;
        }
    }
};
class Alumno : public Usuario{
private:
    Profesor profesor;
public:
    Alumno() : Usuario(){
    }
    Alumno(string n, string a, int numU, Profesor p, int id): Usuario(n,a,numU, id){
    }
};
class RegistroYLogin : public Usuario{
private:
    Usuario listaUsuario[10];
    int control;
public:
    RegistroYLogin(){
        for(int i=0;i<10;i++){
            listaUsuario[i] = {};
        }
    }
    void addUsuario(Usuario u){
        listaUsuario[control] = u;
        control++;
    }
    void leerUsuarios(bool cargo){
        for (int i = 0; i < 10; i++) {
            if (i < control) {
                cout<<listaUsuario[i].toString(cargo)<<endl;
            } else {
                cout<<"Vacio"<< endl;
            }
        }
    }
};
#endif //GRUPO1_AC2_RECURSO1_H
