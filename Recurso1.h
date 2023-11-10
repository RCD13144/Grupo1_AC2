//
// Created by belen on 08/11/2023.
//
#ifndef GRUPO1_AC2_RECURSO1_H
#define GRUPO1_AC2_RECURSO1_H

#include <string>
#include <sstream>
using namespace std;

class Usuario{
public:
    enum TipoUsuario { PROFESOR, ALUMNO };
private:
    string nombre, apellido;
    bool cargo;
    int numUsuario;
    int id;
    TipoUsuario tipoUsuario;
public:
    Usuario(string n, string a, int numU, int id, TipoUsuario tu){
        Usuario::nombre = n;
        Usuario::apellido = a;
        Usuario::numUsuario = numU;
        Usuario::id = id;
        Usuario::tipoUsuario = tu;
    }
    Usuario(){}
    string getNombre(){
        return nombre;
    }
    TipoUsuario getTipoUsuario() const {
        return cargo ? PROFESOR : ALUMNO;
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
    string toString(){
        stringstream  ss;
        ss<<getNumUsuario();
        string numUAString = ss.str();
        ss<<getId();
        string idAString = ss.str();
        string valor;

        return "[("+nombre + ", "+apellido+", "+numUAString+", "+idAString+")]";
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
    Profesor(string n, string a, int numU, int id, TipoUsuario tu) : Usuario(n,a,numU,id, tu){
        Profesor::control = 0;
    }
    void addAlumno(Alumno* a){
        listaAlumnos[control] = a;
        control++;
    }
    void verAlumnos(){
        for(int i=0;i<8;i++){
            cout<< listaAlumnos[i]<<endl;
        }
    }
    string toString(){
        return "Profesor = [nombre = " + getNombre() + ", apellido = " + getApellido() + ", numUsuario = " + to_string(getNumUsuario()) + ", id = " + to_string(getId()) + "]";
    }
};
class Alumno : public Usuario{
private:
    Profesor profesor;
public:
    Alumno() : Usuario(){
    }
    Alumno(string n, string a, int numU, Profesor p, int id, TipoUsuario tu): Usuario(n,a,numU, id, tu){
        profesor = p;
    }
    string toString(){
        return "Alumno = [nombre = " + getNombre() + ", apellido = " + getApellido() + ", numUsuario = " + to_string(getNumUsuario()) + ", " + profesor.toString() + ", id = " +to_string(getId())+ "]";
    }
};
class RegistroYLogin : public Usuario{
private:
    Usuario listaUsuario[10];
    Profesor p;
    Alumno a;
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
    void leerUsuarios(bool cargo) {
        for (int i = 0; i < control; i++) {
            cout << listaUsuario[i].toString() << endl;
        }
    }
    void leerUsuarios(){
        for (int i = 0; i < control; i++) {
            cout<<listaUsuario[i].toString()<<endl;
        }
    }
    void iniciarSesion(int contrasena){
        for(int i=0;i<control;i++){
            if(listaUsuario[i].getId()==contrasena){
                if (listaUsuario[i].getTipoUsuario() == Usuario::PROFESOR) {

                }else{

                }
            }
        }
    }
};

#endif //GRUPO1_AC2_RECURSO1_H
