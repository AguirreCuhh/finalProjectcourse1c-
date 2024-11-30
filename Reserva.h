//
// Created by Fernando Aguirre Higuera on 27/11/24.
//

#ifndef RESERVA_H
#define RESERVA_H

#include <string>
#include "Usuario.h"
#include "Vuelo.h"

class Reserva {
private:
    std::string idReserva;
    Usuario usuario;
    Vuelo vuelo;
    int cantidadPasajeros;
    double precioTotal;
    std::string estado;

public:
    Reserva(const std::string& idReserva, const Usuario& usuario, const Vuelo& vuelo, int cantidadPasajeros, double precioTotal);

    std::string getIdReserva() const { return idReserva; }
    void cancelarReserva() { estado = "Cancelada"; }
    void mostrarDetalles() const;
};

#endif // RESERVA_H

