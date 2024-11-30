//
// Created by Fernando Aguirre Higuera on 27/11/24.
//

#include "Usuario.h"

Usuario::Usuario(const std::string& nombre, const std::string& email, const std::string& contrasena, int kilometrosAcumulados)
    : nombre(nombre), email(email), contrasena(contrasena), kilometrosAcumulados(kilometrosAcumulados) {}



bool Usuario::iniciarSesion(const std::string& correo, const std::string& contrasena) const {
    return this->email == correo && this->contrasena == contrasena;
}



void Usuario::acumularKilometros(double km) {
    kilometrosAcumulados += km;
}



