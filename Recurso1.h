//
// Created by belen on 08/11/2023.
//
#ifndef GRUPO1_AC2_RECURSO1_H
#define GRUPO1_AC2_RECURSO1_H

#include <string>
#include <sstream>
#include <fstream>
using namespace std;
class Documento{
private:
    string titulo;
public:
    Documento(){
    }
    Documento(string t){
        titulo = t;
    }
    string getTitulo(){
        return titulo;
    }
    bool equals(Documento doc){
        return titulo == doc.getTitulo();
    }
};
template <typename T> class ListaObjetos{
    /**
     * Clase que sirve para albergar una serie de objetos de cualquier tipo
     */
private:
    /**
     * Atributos de ListaObjetos
     * @param listaObjetos Array donde albergaremos un maximo de 10 elementos
     * @param puntero numero que apunta a la primera posicion vacia
     */
    T listaObjetos[10];
    int puntero;
public:
    /**
     * Metodo constructor de la clase ListaObjetos
     */
    ListaObjetos(){
        ListaObjetos::puntero = 0;
    }
    /**
     * Metodo que permite buscar un elemento en la lista
     * @param e Elemento que se quiere buscar en la lista
     * @return Indice del elemento si se encuentra. Si no se encuentra devuelve -1
     */
    int buscarElemento(T e){
        bool encontrado = false;
        for (int i = 0; i < 10; ++i) {
            if(e == ListaObjetos::listaObjetos[i]){
                encontrado = true;
                return i;
            }
        }
        if (encontrado == false){
            return -1;
        }
    }
    /**
     * Metodo que permite introducir un elemento en la lista
     * @param e Elemento que se quiere meter a la lista
     */
    void introducirElemento(T e){
        if(puntero >= 10){
            cout << "Lista llena" << endl;
        }
        else{
            listaObjetos[puntero] = e;
            puntero++;
        }
    }
    /**
     * Metodo que permite extraer un elemento de la lista
     * @param e Elemento que se quiere extraer
     * @return Elemento que se buscaba
     */
    T extraerElemento(T e){
        T aux;
        int busqueda = buscarElemento(e);
        if(busqueda == -1){
            cout << "No se ha encontrado el elemento" << endl;
        }
        else{
            aux = listaObjetos[busqueda];
            for (int i = busqueda; i < puntero ; ++i) {
                listaObjetos[i] = listaObjetos[i+1];
            }
            puntero--;
            return aux;
        }
    }
    T extraerElemento(int indice){
        T aux;
        if(indice >= 10){
            cout << "No se ha encontrado el elemento" << endl;
        }
        else if(indice < 0){
            cout << "No se ha encontrado el elemento" << endl;
        }
        else{
            aux = listaObjetos[indice];
            for (int i = indice; i < puntero ; ++i) {
                listaObjetos[i] = listaObjetos[i+1];
            }
            puntero--;
            return aux;
        }
    }
    T getElemento(int indice){
        if(indice >= 10){
            cout << "No se ha encontrado el elemento" << endl;
        }
        else if(indice < 0){
            cout << "No se ha encontrado el elemento" << endl;
        }
        else{
            return listaObjetos[indice];
        }
    }
    /**
     * Metodo que permite ver la lista
     */
    void verLista(){
        cout << "[";
        for (int i = 0; i < puntero ; ++i) {
            cout << listaObjetos[i] << ", ";
        }
        cout << "]" << endl;
    }
};
template <typename T> class Dinarray{
    /**
     * Clase que representa un array cuya dimension la determina el usuario
     */
private:
    /**
     * Atributos de Dinarray
     * @param p Puntero de cualquier tipo que apunta al nuestro array
     * @param tamanio Tamaño del array
     */
    T* p;
    int tamanio;
public:
    /**
     * Metodo constructor de Dinarray
     * @param n Tamaño del array
     */
    Dinarray(int n){
        p = new T[n];
        tamanio = n;
    }
    /**
     * Metodo destructor de Dinarray
     */
    ~Dinarray(){
        for (int i = 0; i < tamanio; ++i) {
            p[i].~T();
        }
        delete[] p;
        cout << "Se ha destruido el Dinarray" << endl;
    }
    /**
     * Metodo que devuleve el elemento del indice
     * @param indice posicion de la cual se quiere saber el valor
     * @return Objeto que esta en la posicion que se ha determinado
     */
    T cogerElemento(int indice){
        if (indice > tamanio){
            cout << "Indice incorrecto" << endl;
        }
        else{
            return p[indice];
        }
    }
    /**
     * Metodo que permite establecer un elemento en el array
     * @param e Elemento a establecer
     * @param indice Posicion donde se quiere establecer el elemento
     */
    void establecerElemento(T e, int indice){
        if(indice > tamanio){
            cout << "Indice incorrecto" << endl;
        }
        else{
            p[indice] = e;
        }
    }

};
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
class Alumno : public Usuario{
private:
    Documento mochilaVirtual[10];
    int control;
    bool tieneProfesor;
public:
    Alumno() : Usuario(){
    }
    Alumno(string n, string a, int numU, int id): Usuario(n,a,numU, id){
        control = 0;
        tieneProfesor =  false;
    }
    void nuevaActividad(Documento doc){
        mochilaVirtual[control] = doc;
        control ++;
    };
    int buscarActividad(Documento doc){
        bool encontrado = false;
        for (int i = 0; i < control; ++i) {
            if (doc.equals(mochilaVirtual[i])){
                encontrado = true;
                return i;
            }
        }
        if (encontrado == false){
            return -1;
        }
    }
    Documento extraerActividad(Documento doc){
        int pos = buscarActividad(doc);
        Documento aux;
        if(pos == -1){
            throw "ERROR: Elemento inexistente";
        }
        else{
            aux = mochilaVirtual[pos];
            for (int i = pos; i < control ; ++i) {
                mochilaVirtual[i] = mochilaVirtual[i+1];
            }
            return aux;
        }
    }
    bool hasProfesor(){
        return tieneProfesor;
    }
    void setTieneProfesor(bool b){
        tieneProfesor = b;
    }
    string toString(){
        return "Alumno = [nombre = " + getNombre() + ", apellido = " + getApellido() + ", numUsuario = " + to_string(getNumUsuario()) +  ", id = " +to_string(getId())+ "]";
    }
    bool operator==(Alumno otro){
        return (getNombre() == otro.getNombre() &&
                getApellido() == otro.getApellido() &&
                getNumUsuario() == otro.getNumUsuario() &&
                getId() == otro.getId());
    }
};
class Profesor : public Usuario{
private:
    int control;
    int tamanoClase;
    Dinarray<Alumno>* pdin;
public:
    Profesor() : Usuario(){
    }
    Profesor(string n, string a, int numU, int id, int tamClase) : Usuario(n,a,numU,id){
        Profesor::control = 0;
        Profesor::tamanoClase = tamClase;
        pdin = new Dinarray<Alumno>(tamanoClase);
    }
    void addAlumno(Alumno a){
        if(a.hasProfesor() == true){
            cout << "El alumno ya tiene un profesor" << endl;
        }
        else{
            if(control >= tamanoClase) {
                cout<<"No se pueden aniadir mas alumnos a esta clase"<<endl;
            }
            else{
                a.setTieneProfesor(true);
                pdin->establecerElemento(a, control);
                control++;
            }
        }
    }
    void verAlumnos(){
        for(int i=0;i<control;i++){
            cout<< pdin->cogerElemento(i).toString() <<endl;
        }
    }
    string toString(){
        return "Profesor = [nombre = " + getNombre() + ", apellido = " + getApellido() + ", numUsuario = " + to_string(getNumUsuario()) + ", id = " + to_string(getId()) + "]";
    }
    bool operator ==(Profesor otro){
        return (getNombre() == otro.getNombre() &&
                getApellido() == otro.getApellido() &&
                getNumUsuario() == otro.getNumUsuario() &&
                getId() == otro.getId());
    }
};

class RegistroYLogin : public Usuario{
private:
    ListaObjetos<Profesor> listaProfesores;
    ListaObjetos<Alumno> listaAlumno;
    Profesor p;
    Alumno a;
    int control1;
    int control2;
public:
    RegistroYLogin(){
        control1 = 0;
        control2 = 0;
    }
    void addProfesor(Profesor u){
        listaProfesores.introducirElemento(u);
        control1++;
    }
    void addAlumno(Alumno u){
        listaAlumno.introducirElemento(u);
        control2++;
    }
    void leerProfesores(){
        for (int i = 0; i < control1; i++) {
            cout<<listaProfesores.getElemento(i).toString()<<endl;
        }
    }
    void leerAlumnos(){
        for (int i = 0; i < control2; i++) {
            cout<<listaAlumno.getElemento(i).toString()<<endl;
        }
    }
    Profesor extraerProfesor(Profesor prof){
        control1--;
        return listaProfesores.extraerElemento(prof);
    }
    Alumno extaerAlumno(Alumno alum){
        control2--;
        return listaAlumno.extraerElemento(alum);
    }
    Profesor iniciarSesionProfesor(int contrasena){
        bool coincide = false;
        for(int i=0;i<control1;i++){
            if (listaProfesores.getElemento(i).getId() == contrasena){
                coincide = true;
                return listaProfesores.getElemento(i);
            }
        }
        if (coincide == false){
            cout << "Contraseña incorrecta" << endl;
        }
    }
    Alumno iniciarSesionAlumno(int contrasena){
        bool coincide = false;
        for(int i=0;i<control2;i++){
            if (listaAlumno.getElemento(i).getId() == contrasena){
                coincide = true;
                return listaAlumno.getElemento(i);
            }
        }
        if (coincide == false){
            cout << "Contraseña incorrecta" << endl;
        }
    }
};

#endif //GRUPO1_AC2_RECURSO1_H