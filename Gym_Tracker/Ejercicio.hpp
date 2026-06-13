//
//  Ejercicio.hpp
//  Ejercicio
//
//  Created by Arturo Sebastian García Soto on 09/06/26.
//
// Abstract base class. All my exercise types will inherit from here.
// I'm just defining the general data like ID, name, and duration.
#pragma once
#include <string>

class Ejercicio {
protected:
    int id;
    std::string nombre;
    int duracionMinutos;
    int nivelEsfuerzo;

public:
    Ejercicio(int id_param, std::string nombre_param, int duracion_param, int nivel_param);
    virtual ~Ejercicio() = default;

    int getID() const;
    std::string getNombre() const;
    int getDuracion() const;
    int getNivel() const;

    virtual void mostrarDetalles() const = 0;
};
