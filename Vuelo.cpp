//
// Created by Fernando Aguirre Higuera on 27/11/24.
//

#include "Vuelo.h"

Vuelo::Vuelo(const std::string& numeroVuelo, const std::string& nombreAerolinea, double precio, double duracion, const std::string& fecha, int asientosDisponibles)
    : numeroVuelo(numeroVuelo), nombreAerolinea(nombreAerolinea), precio(precio), duracion(duracion), fecha(fecha), asientos(asientosDisponibles, false) {}

std::string Vuelo::getNumeroVuelo() const {
    return numeroVuelo;
}

double Vuelo::getPrecio() const {
    return precio;
}

int Vuelo::getAsientosDisponibles() const {
    return std::count(asientos.begin(), asientos.end(), false);
}

void Vuelo::mostrarDetalles() const {
    std::cout << "Vuelo: " << numeroVuelo << " | Aerolínea: " << nombreAerolinea
              << " | Precio: $" << precio << " | Duración: " << duracion
              << " horas | Fecha: " << fecha << " | Asientos disponibles: " << getAsientosDisponibles() << "\n";
}

void Vuelo::mostrarAsientos() const {
    std::cout << "Estado de los asientos:\n";
    for (size_t i = 0; i < asientos.size(); ++i) {
        std::cout << "Asiento " << i + 1 << ": " << (asientos[i] ? "Ocupado" : "Disponible") << "\n";
    }
}

bool Vuelo::reservarAsiento(int asiento) {
    if (asiento < 1 || asiento > asientos.size() || asientos[asiento - 1]) {
        return false;
    }
    asientos[asiento - 1] = true;
    return true;
}
