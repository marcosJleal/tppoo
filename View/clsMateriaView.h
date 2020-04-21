#ifndef CLSMATERIAVIEW_H
#define CLSMATERIAVIEW_H
#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include "../DTO/clsMateriaDTO.h"
#include "../DAO/clsMateriaDAO.h"
#include "../BL/clsMateriaBL.h"
#include "../Helpers/clsCadenaHelper.h"
#include "../Helpers/clsValidacion.h"
#include "clsMateriaXAlumnoView.h"

using namespace std;


class clsMateriaView
{
    public:
        void menu();
        void insertar();
        void listar();
        void eliminar();
        void modificar();
        void buscarMateria();

};

#endif // CLSMATERIAVIEW_H
