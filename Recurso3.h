//
// Created by belen on 06/11/2023.
//

#ifndef GRUPO1_AC2_RECURSO3_H
#define GRUPO1_AC2_RECURSO3_H
#include <iostream>
using namespace std;
template<typename T> class Matriz{
private:
    int nFilas;
    int nColumnas;
public:
    T matriz[5][5];
    Matriz(){
        for (int i = 0; i < 5; ++i) {
            for (int j = 0; j < 5 ; ++j) {
                matriz[i][j] = 0;
            }
        }
    }
    void llenarMatriz(int nFil, int nCol){
        T aux;
        if(nFil > 5 || nCol > 5){
            throw "ERROR: Las dimensiones exceden las predeterminadas";
        }
        else{
            setNFilas(nFil);
            setNColumnas(nCol);
            cout << "El tamaño introducido es: " << nFil << " x " << nCol << endl;
            for (int i = 0; i < nFil; ++i) {
                for (int j = 0; j < nCol; ++j) {
                    cout << "Introduzca el valor de la posicion " << "["<< i <<"]"<<"[" << j <<"]" << endl;
                    cin >> aux;
                    matriz[i][j] = aux;
                }
            }
        }
    }
    int getNFilas(){
        return nFilas;
    }
    int getNColumnas(){
        return nColumnas;
    }
    void setNFilas(int n){
        nFilas = n;
    }
    void setNColumnas(int n){
        nColumnas = n;
    }
    void setMatriz(T m[5][5]){
        for (int i = 0; i < 5; ++i) {
            for (int j = 0; j < 5; ++j) {
                matriz[i][j] = m[i][j];
            }
        }
    }
    void verMatriz(){
        for (int i = 0; i < 5; ++i) {
            cout << "" << endl;
            for (int j = 0; j < 5; ++j) {
                cout << matriz[i][j] << ",";
            }
        }
        cout << "" << endl;
    }
};
template<typename T>class Calculadora{
public:
    Calculadora(){
    }
    T sumar(T operador1, T operador2){
        return operador1+operador2;
    }
    T restar(T operador1, T operador2){
        return operador1 - operador2;
    }
    T multiplicar(T operador1, T operador2){
        return operador1 * operador2;
    }
    T dividir(T operador1, T operador2){
        return operador1/operador2;
    }
    Matriz<T> sumar(Matriz<T> m1, Matriz<T> m2){
        T arrayResult[5][5];
        Matriz<T> result;
        for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
                arrayResult[i][j] = m1.matriz[i][j] + m2.matriz[i][j];
            }
        }
        result.setMatriz(arrayResult);
        return result;
    }
    Matriz<T> restar(Matriz<T> m1, Matriz<T> m2){
        T arrayResult[5][5];
        Matriz<T> result;
        for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
                arrayResult[i][j] = m1.matriz[i][j] - m2.matriz[i][j];
            }
        }
        result.setMatriz(arrayResult);
        return result;
    }
    Matriz<T> multiplicar(Matriz<T> m1, Matriz<T> m2){
        T arrayResult[5][5];
        Matriz<T> result;
        for (int i = 0; i < 5; ++i) {
            for (int j = 0; j < 5; ++j) {
                arrayResult[i][j] = 0;
            }
        }
        if(m1.getNColumnas() == m2.getNFilas()){
            for (int i = 0; i < m1.getNFilas(); ++i) {
                for (int j = 0; j < m2.getNColumnas(); ++j) {
                    for (int k = 0; k < m1.getNColumnas(); ++k) {
                        arrayResult[i][j] += m1.matriz[i][k] * m2.matriz[k][j];
                    }
                }
            }
            result.setMatriz(arrayResult);
            return result;
        }
        else{
            throw "ERROR: No son iguales las columnas de M1 que las filas de M2";
        }
    }
    Matriz<T> dividir(Matriz<T> m1, T n){
        Matriz<T> result;
        T arrayResult[5][5];
        if (n == 0){
            throw "ERROR: No se puede dividir entre cero";
        }
        else{
            for (int i = 0; i < m1.getNFilas(); ++i) {
                for (int j = 0; j < m1.getNColumnas(); ++j) {
                    arrayResult[i][j] = m1.matriz[i][j] / n;
                }
            }
            result.setMatriz(arrayResult);
            return result;
        }
    }
    Matriz<T> multiplicar(Matriz<T> m1, T n){
        Matriz<T> result;
        T arrayResult[5][5];
        for (int i = 0; i < 5; ++i) {
            for (int j = 0; j < 5; ++j) {
                arrayResult[i][j] = m1.matriz[i][j] * n;
            }
        }
        result.setMatriz(arrayResult);
        return result;
    }
};

#endif //GRUPO1_AC2_RECURSO3_H
