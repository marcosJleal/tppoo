#include "clsMateriaXAlumnoBL.h"

void clsMateriaXAlumnoBL::insertar(clsMateriaXAlumnoDTO dto)
{
    clsMateriaXAlumnoDAO dao;
    dao.insertar(dto);

}
 void clsMateriaXAlumnoBL::eliminar(int legajo,int id)
{
    clsMateriaXAlumnoDAO dao;
    dao.eliminar(legajo,id);

}
void clsMateriaXAlumnoBL::listar(clsMateriaXAlumnoDTO* dto)
{
    clsMateriaXAlumnoDAO dao;
    dao.listar(dto);


}

int clsMateriaXAlumnoBL::Count()
{
    clsMateriaXAlumnoDAO dao;
    dao.Count();

}
