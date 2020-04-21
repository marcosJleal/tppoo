#ifndef CLSVALIDACION_H
#define CLSVALIDACION_H
#include <iostream>
#include <cstring>
#include <cstdio>
#include <stdlib.h>
#include "../DTO/clsMateriaDTO.h"
#include "../DTO/clsAlumnoDTO.h"
#include "../DTO/clsMateriaXAlumnoDTO.h"
#include "../DAO/clsMateriaDAO.h"
#include "../DAO/clsAlumnoDAO.h"
#include "../DAO/clsMateriaXAlumnoDAO.h"



using namespace std;


class clsValidacion
{
    public:
        void ValidarRequerido(char*,char*,int);
        bool ExisteAlumno(char*);
        bool ExisteMateria(char*);
        bool ExisteAlumnoEnMateria(int,int);


};

#endif // CLSVALIDACION_H
