//
//  SesionEntrenamiento.hpp
//  Ejercicio
//
//  Created by Arturo Sebastian García Soto on 09/06/26.
//
// This is the "box" where I keep all the exercises I did in a single day.
// I'm using a vector of unique_ptr to apply polymorphism without leaking memory.

#pragma once
#include <string>
#include <vector>
#include <memory>
#include "Ejercicio.hpp"

class SesionEntrenamiento {
private:
    std::string fecha;
    std::vector<std::unique_ptr<Ejercicio>> listaEjercicios;

public:
    SesionEntrenamiento(std::string fecha_param);

    void agregarEjercicio(std::unique_ptr<Ejercicio> nuevoEjercicio);
    void mostrarSesion() const;
    int getDuracionTotal() const;
    
    // El cambio está aquí: Ahora sumamos la sesión con un acumulador entero
    int operator+(int minutos_base) const;
};
