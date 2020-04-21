#ifndef CLSALUMNOBL_H
#define CLSALUMNOBL_H
#include "../DAO/clsAlumnoDAO.h"
#include "../DTO/clsAlumnoDTO.h"

class clsAlumnoBL
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

#endif // CLSALUMNOBL_H
