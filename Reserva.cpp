//
// Created by Fernando Aguirre Higuera on 27/11/24.
//
#include "Reserva.h"
#include <iostream>

Reserva::Reserva(const std::string& idReserva, const Usuario& usuario, const Vuelo& vuelo, int cantidadPasajeros, double precioTotal)
    : idReserva(idReserva), usuario(usuario), vuelo(vuelo), cantidadPasajeros(cantidadPasajeros), precioTotal(precioTotal), estado("Activa") {}

void Reserva::mostrarDetalles() const {
    std::cout << "Reserva: " << idReserva << " | Usuario: " << usuario.getNombre()
              << " | Vuelo: " << vuelo.getNumeroVuelo()
              << " | Pasajeros: " << cantidadPasajeros << " | Precio total: $" << precioTotal
              << " | Estado: " << estado << "\n";
}
