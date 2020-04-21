#ifndef CLSMATERIAXALUMNOBL_H
#define CLSMATERIAXALUMNOBL_H
#include "../DAO/clsMateriaXAlumnoDAO.h"
#include "../DTO/clsMateriaXAlumnoDTO.h"


class clsMateriaXAlumnoBL
{
    public:
        void insertar(clsMateriaXAlumnoDTO);
        void eliminar(int,int);
        void listar(clsMateriaXAlumnoDTO*);
        int Count();

};

#endif // CLSMATERIAXALUMNOBL_H
