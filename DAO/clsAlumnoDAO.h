#ifndef CLSALUMNODAO_H
#define CLSALUMNODAO_H
#include <cstdio>

#include "../DTO/clsAlumnoDTO.h"
#include "../Helpers/clsCadenaHelper.h"

const char ARCHIVO_ALUMNOS[]="ARCHIVO_ALUMNOS.DAT";

class clsAlumnoDAO
{
public:
    void Insertar (clsAlumnoDTO);
    void Eliminar(int);
    void Modificar(clsAlumnoDTO);
    void Listar(clsAlumnoDTO*);
    int Count();
    void BuscarSub(clsAlumnoDTO*, char*);
      int BuscarSubCount(char *);


};

#endif // CLSALUMNODAO_H
