//
// Created by Fernando Aguirre Higuera on 27/11/24.
//

#ifndef SISTEMARESERVAS_H
#define SISTEMARESERVAS_H

#include <vector>
#include "Usuario.h"
#include "Vuelo.h"
#include "Reserva.h"

class SistemaReservas {
private:
    std::vector<Usuario> usuarios;
    std::vector<Vuelo> vuelos;
    std::vector<Reserva> reservas;

    bool existeUsuario(const std::string& email) const;

public:
    SistemaReservas();
    ~SistemaReservas();

    void registrarUsuario(const Usuario& usuario);
    void agregarVuelo(const Vuelo& vuelo);
    void buscarVuelosPorFecha(const std::string& fecha) const;
    void realizarReserva(const std::string& correo, const std::string& numeroVuelo, int cantidadPasajeros);
    void cancelarReserva(const std::string& idReserva);
    void mostrarReservas() const;
    Usuario obtenerUsuarioPorCorreo(const std::string& correo) const;

};

#endif // SISTEMARESERVAS_H
