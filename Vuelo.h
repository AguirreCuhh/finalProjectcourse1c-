//
// Created by Fernando Aguirre Higuera on 27/11/24.
//

#ifndef VUELO_H
#define VUELO_H

#include <string>
#include <iostream>
#include <vector>

class Vuelo {
private:
    std::string numeroVuelo;
    std::string nombreAerolinea;
    double precio;
    double duracion;
    std::string fecha;
    std::vector<bool> asientos;

public:
    Vuelo(const std::string& numeroVuelo, const std::string& aerolinea, double precio, double duracion, const std::string& fecha, int asientosDisponibles);

    std::string getNumeroVuelo() const;
    double getPrecio() const;
    int getAsientosDisponibles() const;
    void mostrarDetalles() const;
    void mostrarAsientos() const;
    bool reservarAsiento(int asiento);
};

#endif // VUELO_H
