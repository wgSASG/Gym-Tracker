//
//  Fuerza.cpp
//  Ejercicio
//
//  Created by Arturo Sebastian García Soto on 09/06/26.
//
// Here I initialize my data and pass the basics to the parent class.
// I also formatted it so it prints nicely on the console.

#include "Fuerza.hpp"
#include <iostream>

Fuerza::Fuerza(int id_param, std::string nombre_param, int duracion_param, int nivel_param, char enfoque_param, int series_param, int repes_param, float peso_param) : Ejercicio(id_param, nombre_param, duracion_param, nivel_param) {
    enfoque = enfoque_param;
    series = series_param;
    repeticiones = repes_param;
    pesoKg = peso_param;
}

void Fuerza::mostrarDetalles() const {
    std::cout << "--- Strength Exercise ---" << std::endl;
    std::cout << "ID: " << id << " | Name: " << nombre << std::endl;
    std::cout << "Focus: " << enfoque << " | Sets: " << series << " | Reps: " << repeticiones << " | Weight: " << pesoKg << " kg" << std::endl;
    std::cout << "Duration: " << duracionMinutos << " min | Effort: " << nivelEsfuerzo << "/10" << std::endl;
}
