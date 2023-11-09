/*
 * Este archivo contiene las clases usadas para el juego de numeros aleatorios
 */
#include <random>
#ifndef GRUPO1_AC2_RECURSO5_H
#define GRUPO1_AC2_RECURSO5_H
using namespace std;
/**
 * Esta clase contiene los metodos y atributos de Juego
 */
class Juego{
    /**
     * Clase que genera un numero aleatorio del 1 al 100 y pide al usuario que lo adivine
     */
private:
    /**
     * Atributos de la clase Juego
     * @param numero_a_adivinar Numero aleatorio del 1 al 100.
     * @param nIntentos Numero de intentos que le toma al usuario adivinar el numero
     * @param num Numero que introduce el usuario
     */
    int numero_a_adivinar, nIntentos, num;
public:
    /**
     * Metodo constructor de Juego
     * Se genera un numero aleatorio del 1 al 100
     * Se inicia el numero de intentos a 0
     */
    Juego(){
        numero_a_adivinar = rand() % 100 + 1;
        nIntentos = 0;
    }
    /**
     * Metodo en el que se lleva a cabo el juego.
     */
    void menuJuego(){
        bool acertado = false;
        while(acertado == false){
            cout<< "Adivina un numero entre 1 y 100"<< endl;
            cin>> num;
            nIntentos++;

            if(num < numero_a_adivinar){
                cout<< "El numero es mayor. Prueba otra vez. "<< endl;
            }
            else if(num > numero_a_adivinar){
                cout<< "El numero es menor. Prueba otra vez. "<< endl;
            }
            else{
                cout<< "Has acertado el numero!! Enhorabuena."<< endl;
                cout << "Has hecho: " << Juego::nIntentos << " intentos!" << endl;
                acertado = true;
            }
        }
    }
};
#endif //GRUPO1_AC2_RECURSO5_H
