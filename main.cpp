#include "SistemaReservas.h"
#include <iostream>

int main() {
    SistemaReservas sistema;

    // Datos iniciales de ejemplo
    Usuario usuario1("Juan Perez", "juan@gmail.com", "1234");
    Usuario usuario2("Maria Lopez", "maria@gmail.com", "5678");
    Usuario usuario3("Luis Gómez", "luis@gmail.com", "abcd");

    usuario1.acumularKilometros(30000); // Usuario con menos de 50,000 km
    usuario2.acumularKilometros(45000); // Usuario con menos de 50,000 km
    usuario3.acumularKilometros(60000); // Usuario con más de 50,000 km

    sistema.registrarUsuario(usuario1);
    sistema.registrarUsuario(usuario2);
    sistema.registrarUsuario(usuario3);

    Vuelo vuelo1("V123", "Aerolínea X", 150.0, 2.5, "2024-11-25", 100);
    Vuelo vuelo2("V456", "Aerolínea Y", 200.0, 3.0, "2024-11-26", 80);
    Vuelo vuelo3("V789", "Aerolínea Z", 180.0, 4.0, "2024-11-27", 1); // Vuelo sin asientos disponibles

    sistema.agregarVuelo(vuelo1);
    sistema.agregarVuelo(vuelo2);
    sistema.agregarVuelo(vuelo3);

    // Autenticación
    Usuario usuarioLogueado;
    bool autenticado = false;
    int opcionInicio;

    do {
        std::cout << "\n--- Sistema de Reservas ---\n";
        std::cout << "1. Iniciar sesión\n";
        std::cout << "2. Registrar nuevo usuario\n";
        std::cout << "0. Salir\n";
        std::cout << "Seleccione una opción: ";
        std::cin >> opcionInicio;

        switch (opcionInicio) {
        case 1: {
            std::string correo, contrasena;
            std::cout << "Ingrese su correo electrónico: ";
            std::cin >> correo;
            std::cout << "Ingrese su contraseña: ";
            std::cin >> contrasena;

            try {
                usuarioLogueado = sistema.obtenerUsuarioPorCorreo(correo);
                if (usuarioLogueado.iniciarSesion(correo, contrasena)) {
                    autenticado = true;
                    std::cout << "Inicio de sesión exitoso. ¡Bienvenido, " << usuarioLogueado.getNombre() << "!\n";
                } else {
                    std::cout << "Credenciales incorrectas. Intente de nuevo.\n";
                }
            } catch (const std::exception& e) {
                std::cout << "Error: " << e.what() << "\n";
            }
            break;
        }
        case 2: {
            std::string nombre, correo, contrasena;
            std::cout << "Ingrese su nombre: ";
            std::cin.ignore(); // Limpiar el buffer de entrada
            std::getline(std::cin, nombre);
            std::cout << "Ingrese su correo electrónico: ";
            std::cin >> correo;
            std::cout << "Ingrese su contraseña: ";
            std::cin >> contrasena;

            Usuario nuevoUsuario(nombre, correo, contrasena);
            sistema.registrarUsuario(nuevoUsuario); // Maneja la validación internamente
            break;
        }
        case 0:
            std::cout << "Saliendo del sistema...\n";
            break;
        default:
            std::cout << "Opción inválida. Intente de nuevo.\n";
        }
    } while (!autenticado && opcionInicio != 0);

    if (!autenticado) {
        return 0;
    }

    // Menú principal
    int opcion;
    do {
        std::cout << "\n--- Menú Principal ---\n";
        std::cout << "1. Buscar vuelos por fecha\n";
        std::cout << "2. Realizar una reserva\n";
        std::cout << "3. Mostrar todas las reservas\n";
        std::cout << "4. Cancelar una reserva\n";
        std::cout << "0. Salir\n";
        std::cout << "Seleccione una opción: ";
        std::cin >> opcion;

        switch (opcion) {
        case 1: {
            std::string fecha;
            std::cout << "Ingrese la fecha (YYYY-MM-DD): ";
            std::cin >> fecha;
            sistema.buscarVuelosPorFecha(fecha);
            break;
        }
        case 2: {
            std::string numeroVuelo;
            int cantidadPasajeros;
            std::cout << "Ingrese el número de vuelo: ";
            std::cin >> numeroVuelo;
            std::cout << "Ingrese la cantidad de pasajeros: ";
            std::cin >> cantidadPasajeros;
            sistema.realizarReserva(usuarioLogueado.getEmail(), numeroVuelo, cantidadPasajeros);
            break;
        }
        case 3: {
            sistema.mostrarReservas();
            break;
        }
        case 4: {
            std::string idReserva;
            std::cout << "Ingrese el ID de la reserva que desea cancelar: ";
            std::cin >> idReserva;
            sistema.cancelarReserva(idReserva);
            break;
        }
        case 0:
            std::cout << "Saliendo del sistema...\n";
            break;
        default:
            std::cout << "Opción inválida. Intente de nuevo.\n";
        }
    } while (opcion != 0);

    return 0;
}
