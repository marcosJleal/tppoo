#ifndef CLSALUMNOVIEW_H
#define CLSALUMNOVIEW_H
#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include "../DTO/clsAlumnoDTO.h"
#include "../DAO/clsAlumnoDAO.h"
#include "../BL/clsAlumnoBL.h"
#include "../View/clsMateriaXAlumnoView.h"
#include "../Helpers/clsCadenaHelper.h"
#include "../Helpers/clsValidacion.h"

using namespace std;

class clsAlumnoView
{
public:
    void Insertar ();
    void Eliminar();
    void Modificar();
    void Listar();
    void menu();
     void buscarAlumno();

};

#endif // CLSALUMNOVIEW_H
