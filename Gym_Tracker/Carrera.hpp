//
//  Carrera.hpp
//  Ejercicio
//
//  Created by Arturo Sebastian García Soto on 09/06/26.
//
// Class for my running sessions (also inherits from Ejercicio).
// It only needs the distance in km and my running pace.
#pragma once
#include "Ejercicio.hpp"
#include <iostream>

class Carrera final : public Ejercicio {
private:
    float distanciaKm;
    float ritmoMinKm;

public:
    Carrera(int id_param, std::string nombre_param, int duracion_param, int nivel_param, float distancia_param, float ritmo_param);
    void mostrarDetalles() const override;
};
