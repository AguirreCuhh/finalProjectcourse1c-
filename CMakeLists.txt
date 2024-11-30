cmake_minimum_required(VERSION 3.29)
project(proyectoFinal)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(proyectoFinal
    main.cpp
    Reserva.cpp
    Reserva.h
    SistemaReservas.cpp
    SistemaReservas.h
    Usuario.cpp
    Usuario.h
    Vuelo.cpp
    Vuelo.h)
