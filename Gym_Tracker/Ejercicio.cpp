//
//  Ejercicio.cpp
//  Ejercicio
//
//  Created by Arturo Sebastian García Soto on 09/06/26.
//
// Implementing the constructor and basic getters for my Ejercicio class.

#include "Ejercicio.hpp"

Ejercicio::Ejercicio(int id_param, std::string nombre_param, int duracion_param, int nivel_param) {
    id = id_param;
    nombre = nombre_param;
    duracionMinutos = duracion_param;
    nivelEsfuerzo = nivel_param;
}

int Ejercicio::getID() const { return id; }
std::string Ejercicio::getNombre() const { return nombre; }
int Ejercicio::getDuracion() const { return duracionMinutos; }
int Ejercicio::getNivel() const { return nivelEsfuerzo; }
