//
// Created by belen on 06/11/2023.
//

#ifndef GRUPO1_AC2_RECURSO3_H
#define GRUPO1_AC2_RECURSO3_H
#include <iostream>
using namespace std;
/**
 * Declaracion de la clase de plantilla Matriz, contiene los metodos y atributos de Matriz
 */
template<typename T> class Matriz{
private:
    /**
    * Atributos de la clase Matriz
    * @param nFilas Numero de filas de la matriz
    * @param nColumnas Numero de columnas de la matriz
    */
    int nFilas;
    int nColumnas;

public:
    T matriz[5][5];
    /**
     * Metodo constructor de Matriz
     * Se inicia la matriz a 0
     */
    Matriz(){
        for (int i = 0; i < 5; ++i) {
            for (int j = 0; j < 5 ; ++j) {
                matriz[i][j] = 0;
            }
        }
    }
    /**
     * Metodo en el que se lleva a cabo el llenado de la matriz
     */
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
    /**
     * Getters y setters para el numero de filas y columnas de la matriz
     * @return numero de filas y columnas
     */
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
    /**
     * @param m Array 5x5 para establecer la matriz
     */
    void setMatriz(T m[5][5]){
        for (int i = 0; i < 5; ++i) {
            for (int j = 0; j < 5; ++j) {
                matriz[i][j] = m[i][j];
            }
        }
    }
    /**
     * Muestra la matriz
     */
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
/**
 * Declaracion de la clase de plantilla Calculadora, contiene los metodos y atributos de Calculadora
 */
template<typename T>class Calculadora{
public:
    Calculadora(){
    }
    /**
     * @param operador1 Primer operando
     * @param operador2 Segundo operando
     * @return Suma de operador1 y operador2
     */
    T sumar(T operador1, T operador2){
        return operador1+operador2;
    }
    /**
     * @param operador1 Primer operando
     * @param operador2 Segundo operando
     * @return Resta entre operador1 y operador2
     */
    T restar(T operador1, T operador2) {
        return operador1 - operador2;
    }
    /**
     * @param operador1 Primer operando
     * @param operador2 Segundo operando
     * @return Producto entre operador1 y operador2
     */
    T multiplicar(T operador1, T operador2){
        return operador1 * operador2;
    }
    /**
     * @param operador1 Primer operando
     * @param operador2 Segundo operando
     * @return Resultado de dividir operador1 y operador2
     */
    T dividir(T operador1, T operador2){
        return operador1/operador2;
    }
    // Operaciones de matriz
    /**
     * @param m1 Primera matriz
     * @param m2 Segunda matriz
     * @return Matriz resultante tras sumar m1 y m2
     */
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
    /**
     * @param m1 Primera matriz
     * @param m2 Segunda matriz
     * @return Matriz resultante tras restar m2 de m1
     */
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
    /**
     * @param m1 Primera matriz
     * @param m2 Segunda matriz
     * @return Matriz resultante tras multiplicar m1 y m2
     */
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
    /**
     * @param m1 Matriz
     * @param n Divisor
     * @return Matriz resultante tras dividir m1 por un escalar 'n'
     */

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
    /**
     * @param m1 Matriz
     * @param n Divisor
     * @return Matriz resultante tras multiplicar m1 por un escalar 'n'
     */

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
