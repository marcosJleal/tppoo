#ifndef CLSMATERIAXALUMNOVIEW_H
#define CLSMATERIAXALUMNOVIEW_H
#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include "../DTO/clsMateriaXAlumnoDTO.h"
#include "../DTO/clsAlumnoDTO.h"
#include "../DAO/clsMateriaXAlumnoDAO.h"
#include "../BL/clsMateriaXAlumnoBL.h"
#include"../BL/clsMateriaBL.h"
#include "../BL/clsAlumnoBL.h"
#include "../DTO/clsAlumnoDTO.h"
#include "../Helpers/clsValidacion.h"

using namespace std;



class clsMateriaXAlumnoView
{
    public:
        void menu();
        void insertar();
        void eliminar();
        void listarAxM();
        void listarMxA();


};

#endif // CLSMATERIAXALUMNOVIEW_H
