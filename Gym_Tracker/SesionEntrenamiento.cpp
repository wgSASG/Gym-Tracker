//
//  SesionEntrenamiento.cpp
//  Ejercicio
//
//  Created by Arturo Sebastian García Soto on 09/06/26.
//
// Logic to add exercises to today's list and show the summary.

#include "SesionEntrenamiento.hpp"
#include <iostream>

SesionEntrenamiento::SesionEntrenamiento(std::string fecha_param) {
    fecha = fecha_param;
}

void SesionEntrenamiento::agregarEjercicio(std::unique_ptr<Ejercicio> nuevoEjercicio) {
    listaEjercicios.push_back(std::move(nuevoEjercicio));
}

void SesionEntrenamiento::mostrarSesion() const {
    std::cout << "\n========================================" << std::endl;
    std::cout << "  SESSION DATE: " << fecha << std::endl;
    std::cout << "========================================" << std::endl;
    
    for (int i = 0; i < listaEjercicios.size(); i++) {
        listaEjercicios[i]->mostrarDetalles();
        std::cout << "----------------------------------------" << std::endl;
    }
}

int SesionEntrenamiento::getDuracionTotal() const {
    int total = 0;
    for (int i = 0; i < listaEjercicios.size(); i++) {
        total = total + listaEjercicios[i]->getDuracion();
    }
    return total;
}

// El cambio está aquí: Suma el total de esta sesión al acumulador que recibe
int SesionEntrenamiento::operator+(int minutos_base) const {
    return this->getDuracionTotal() + minutos_base;
}
