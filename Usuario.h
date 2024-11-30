//
// Created by Fernando Aguirre Higuera on 27/11/24.
//

#ifndef USUARIO_H
#define USUARIO_H

#include <string>

class Usuario {
private:
    std::string nombre;
    std::string email;
    std::string contrasena;
    int kilometrosAcumulados;

public:
    Usuario(const std::string& nombre, const std::string& email, const std::string& contrasena, int kilometrosAcumulados = 0);
    Usuario() : nombre(""), email(""), contrasena(""), kilometrosAcumulados(0) {} // Constructor predeterminado
    std::string getNombre() const { return nombre; }
    std::string getEmail() const { return email; }

    bool iniciarSesion(const std::string& correo, const std::string& contrasena) const;
    void acumularKilometros(double km);
    bool verificarDescuento() const { return kilometrosAcumulados > 50000; }
    int getKilometrosAcumulados() const {
        return kilometrosAcumulados;
    }
};

#endif // USUARIO_H
