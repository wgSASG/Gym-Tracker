//
//   Sobreescritura (override) del método virtual     void mostrarDetalles() const override;  Carrera.cpp
//  Ejercicio
//
//  Created by Arturo Sebastian García Soto on 09/06/26.
//
// Constructor for the run and overriding the mostrarDetalles method so I can print my kilometers and time on the screen.

#include "Carrera.hpp"
#include <iostream>

Carrera::Carrera(int id_param, std::string nombre_param, int duracion_param, int nivel_param, float distancia_param, float ritmo_param) : Ejercicio(id_param, nombre_param, duracion_param, nivel_param) {
    distanciaKm = distancia_param;
    ritmoMinKm = ritmo_param;
}

void Carrera::mostrarDetalles() const {
    std::cout << "--- Run Exercise ---" << std::endl;
    std::cout << "ID: " << id << " | Type: " << nombre << std::endl;
    std::cout << "Distance: " << distanciaKm << " km | Pace: " << ritmoMinKm << " min/km" << std::endl;
    std::cout << "Duration: " << duracionMinutos << " min | Effort: " << nivelEsfuerzo << "/10" << std::endl;
}
