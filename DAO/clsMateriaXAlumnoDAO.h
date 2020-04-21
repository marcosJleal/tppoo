#ifndef CLSMATERIAXALUMNODAO_H
#define CLSMATERIAXALUMNODAO_H
#include <cstdio>
#include "../DTO/clsMateriaXAlumnoDTO.h"

char const ARCHIVO_MATERIASXALUMNO[]="ARCHIVO_MATERIASXALUMNO.DAT";


class clsMateriaXAlumnoDAO
{
    public:
        void insertar(clsMateriaXAlumnoDTO);
        void eliminar(int,int);
        void listar (clsMateriaXAlumnoDTO*);
        int Count();


};

#endif // CLSMATERIAXALUMNODAO_H
