//
//  TrackerApp.cpp
//  Ejercicio
//
//  Created by Arturo Sebastian García Soto on 09/06/26.
//
// All my user interaction is right here.

#include "TrackerApp.hpp"
#include "Fuerza.hpp"
#include "Carrera.hpp"
#include <iostream>
#include <stdexcept>

TrackerApp::TrackerApp() {}

void TrackerApp::iniciarMenu() {
    char opcion = ' ';
    
    while (opcion != 'X' && opcion != 'x') {
        std::cout << "\n=================================" << std::endl;
        std::cout << "       GYM TRACKER SYSTEM        " << std::endl;
        std::cout << "=================================" << std::endl;
        std::cout << "A - Log new session" << std::endl;
        std::cout << "B - View full history" << std::endl;
        // Cambio en el texto del menú:
        std::cout << "C - Calculate total time of ALL sessions (Test + operator)" << std::endl;
        std::cout << "X - Exit" << std::endl;
        std::cout << "Choose an option: ";
        std::cin >> opcion;

        if (opcion == 'A' || opcion == 'a') {
            try {
                registrarEntrenamiento();
            }
            catch (const std::invalid_argument& e) {
                std::cout << "\n[VALIDATION ERROR]: " << e.what() << std::endl;
                std::cout << "Session was not saved. Please try again." << std::endl;
            }
        }
        else if (opcion == 'B' || opcion == 'b') {
            mostrarHistorial();
        }
        else if (opcion == 'C' || opcion == 'c') {
            probarSumaSesiones();
        }
        else if (opcion != 'X' && opcion != 'x') {
            std::cout << "Invalid option. Try again." << std::endl;
        }
    }
    std::cout << "Closing system... Have a great workout!" << std::endl;
}

void TrackerApp::registrarEntrenamiento() {
    std::string fecha;
    std::cout << "\nEnter date (example: 12/06/2026): ";
    std::cin >> fecha;
    
    SesionEntrenamiento nuevaSesion(fecha);
    
    char tipoEx;
    std::cout << "What type of exercise did you do? (F = Strength / C = Cardio): ";
    std::cin >> tipoEx;
    
    if (tipoEx == 'F' || tipoEx == 'f') {
        int id, dur, niv, series, reps;
        float peso;
        char enfoque;
        
        std::cout << "Exercise ID (number): "; std::cin >> id;
        
        std::cout << "Duration (minutes): "; std::cin >> dur;
        if (dur <= 0) throw std::invalid_argument("Duration must be greater than 0.");
        
        std::cout << "Effort level (1-10): "; std::cin >> niv;
        std::cout << "Focus (U=Upper, L=Lower, P=Push, S=Pull): "; std::cin >> enfoque;
        std::cout << "Sets: "; std::cin >> series;
        std::cout << "Reps: "; std::cin >> reps;
        
        std::cout << "Weight (kg): "; std::cin >> peso;
        if (peso < 0) throw std::invalid_argument("Weight cannot be negative.");
        
        nuevaSesion.agregarEjercicio(std::make_unique<Fuerza>(id, "Weights", dur, niv, enfoque, series, reps, peso));
        std::cout << "Strength exercise logged!\n";
    }
    else if (tipoEx == 'C' || tipoEx == 'c') {
        int id, dur, niv;
        float dist, ritmo;
        
        std::cout << "Exercise ID (number): "; std::cin >> id;
        
        std::cout << "Duration (minutes): "; std::cin >> dur;
        if (dur <= 0) throw std::invalid_argument("Duration must be greater than 0.");
        
        std::cout << "Effort level (1-10): "; std::cin >> niv;
        
        std::cout << "Distance (km): "; std::cin >> dist;
        if (dist <= 0) throw std::invalid_argument("Distance must be greater than 0.");
        
        std::cout << "Pace (min/km): "; std::cin >> ritmo;
        
        nuevaSesion.agregarEjercicio(std::make_unique<Carrera>(id, "Running", dur, niv, dist, ritmo));
        std::cout << "Cardio exercise logged!\n";
    }

    historial.push_back(std::move(nuevaSesion));
}

void TrackerApp::mostrarHistorial() {
    if (historial.empty()) {
        std::cout << "\nHistory is empty. Log something first!" << std::endl;
        return;
    }
    
    for (int i = 0; i < historial.size(); i++) {
        historial[i].mostrarSesion();
    }
}

void TrackerApp::probarSumaSesiones() {
    if (historial.empty()) {
        std::cout << "\nHistory is empty. Cannot calculate total time." << std::endl;
        return;
    }
    
    int totalMinutos = 0;
    

    for (int i = 0; i < historial.size(); i++) {
        totalMinutos = historial[i] + totalMinutos;
    }
    
    std::cout << "\n========================================" << std::endl;
    std::cout << " TOTAL TIME ACCUMULATED: " << totalMinutos << " minutes" << std::endl;
    std::cout << "========================================" << std::endl;
}
