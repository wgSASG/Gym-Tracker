//
//  TrackerApp.hpp
//  Ejercicio
//
//  Created by Arturo Sebastian García Soto on 09/06/26.
//
// My main manager class. It's the engine of the program.
// It saves my full history of all sessions in a vector.

#pragma once
#include <vector>
#include "SesionEntrenamiento.hpp"

class TrackerApp {
private:
    std::vector<SesionEntrenamiento> historial;

public:
    TrackerApp();
    void iniciarMenu();

private:
    void registrarEntrenamiento();
    void mostrarHistorial();
    void probarSumaSesiones();
};
