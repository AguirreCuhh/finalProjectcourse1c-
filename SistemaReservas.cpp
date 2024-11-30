//
// Created by Fernando Aguirre Higuera on 27/11/24.
//

#include "SistemaReservas.h"
#include <iostream>
#include <stdexcept>

SistemaReservas::SistemaReservas() {}

SistemaReservas::~SistemaReservas() {}

bool SistemaReservas::existeUsuario(const std::string& email) const {
    for (const auto& usuario : usuarios) {
        if (usuario.getEmail() == email) {
            return true;
        }
    }
    return false;
}

void SistemaReservas::registrarUsuario(const Usuario& usuario) {
    if (existeUsuario(usuario.getEmail())) {
        std::cout << "El usuario con correo " << usuario.getEmail() << " ya está registrado.\n";
        return;
    }
    usuarios.push_back(usuario);
    std::cout << "Usuario registrado exitosamente: " << usuario.getNombre() << "\n";
}

void SistemaReservas::agregarVuelo(const Vuelo& vuelo) {
    vuelos.push_back(vuelo);
}

void SistemaReservas::buscarVuelosPorFecha(const std::string& fecha) const {
    for (const auto& vuelo : vuelos) {
        if (vuelo.getAsientosDisponibles() > 0) {
            vuelo.mostrarDetalles();
        }
    }
}

void SistemaReservas::realizarReserva(const std::string& correo, const std::string& numeroVuelo, int cantidadPasajeros) {
    Usuario usuario = obtenerUsuarioPorCorreo(correo);
    Vuelo* vuelo = nullptr;
    for (auto& v : vuelos) {
        if (v.getNumeroVuelo() == numeroVuelo) {
            vuelo = &v;
            break;
        }
    }

    if (!vuelo || vuelo->getAsientosDisponibles() < cantidadPasajeros) {
        throw std::runtime_error("No hay suficientes asientos disponibles o el vuelo no existe.");
    }

    std::cout << "Asientos disponibles:\n";
    vuelo->mostrarAsientos();

    for (int i = 0; i < cantidadPasajeros; ++i) {
        int asiento;
        std::cout << "Seleccione el asiento " << i + 1 << ": ";
        std::cin >> asiento;
        if (!vuelo->reservarAsiento(asiento)) {
            std::cout << "Asiento inválido o ya ocupado. Intente de nuevo.\n";
            --i;
        }
    }

    // Verificar si el usuario tiene más de 50,000 km acumulados y aplicar descuento
    double precioBase = vuelo->getPrecio() * cantidadPasajeros;
    double descuento = (usuario.getKilometrosAcumulados() > 50000) ? 0.40 : 0.0;
    double precioTotal = precioBase * (1.0 - descuento);

    if (descuento > 0.0) {
        std::cout << "Descuento del 40% aplicado. Precio original: $" << precioBase
                  << ", Precio con descuento: $" << precioTotal << "\n";
    }

    reservas.emplace_back("R" + std::to_string(reservas.size() + 1), usuario, *vuelo, cantidadPasajeros, precioTotal);
    std::cout << "Reserva realizada con éxito.\n";
}

Usuario SistemaReservas::obtenerUsuarioPorCorreo(const std::string& correo) const {
    for (const auto& usuario : usuarios) {
        if (usuario.getEmail() == correo) {
            return usuario;
        }
    }
    throw std::runtime_error("Usuario no encontrado.");
}

void SistemaReservas::mostrarReservas() const {
    for (const auto& reserva : reservas) {
        reserva.mostrarDetalles();
    }
}

void SistemaReservas::cancelarReserva(const std::string& idReserva) {
    for (auto& reserva : reservas) {
        if (reserva.getIdReserva() == idReserva) {
            reserva.cancelarReserva();
            std::cout << "Reserva cancelada.\n";
            return;
        }
    }
    std::cout << "No se encontró la reserva.\n";
}
