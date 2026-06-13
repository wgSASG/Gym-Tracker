//
//  Fuerza.hpp
//  Ejercicio
//
//  Created by Arturo Sebastian García Soto on 09/06/26.
//
// Class to track my weightlifting routines (inherits from Ejercicio).
// I added specific variables like sets, reps, and kilos lifted.
#pragma once
#include "Ejercicio.hpp"
#include <iostream>

class Fuerza final : public Ejercicio {
private:
    char enfoque;
    int series;
    int repeticiones;
    float pesoKg;

public:
    Fuerza(int id_param, std::string nombre_param, int duracion_param, int nivel_param, char enfoque_param, int series_param, int repes_param, float peso_param);
    void mostrarDetalles() const override;
};
