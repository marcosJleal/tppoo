#include "clsAlumnoBL.h"

 void clsAlumnoBL::Insertar (clsAlumnoDTO dto)
 {
     clsAlumnoDAO dao;
     int c=Count();
     dto.SetLegajo(c);
     dao.Insertar(dto);

 }
    void clsAlumnoBL::Eliminar(int legajo)
    {
        clsAlumnoDAO dao;
        dao.Eliminar(legajo);

    }
    void clsAlumnoBL::Modificar(clsAlumnoDTO dto)
    {
        clsAlumnoDAO dao;
        dao.Modificar(dto);

    }
    void clsAlumnoBL::Listar(clsAlumnoDTO*dto)
    {
        clsAlumnoDAO dao;
        dao.Listar(dto);

    }
    int clsAlumnoBL::Count()
    {
        clsAlumnoDAO dao;
        return dao.Count();

    }

    void clsAlumnoBL::BuscarSub(clsAlumnoDTO*lista, char*cond)
{
    clsAlumnoDAO dao;
    dao.BuscarSub(lista,cond);
}

int clsAlumnoBL::BuscarSubCount(char *cond)
{
    clsAlumnoDAO dao;
    return dao.BuscarSubCount(cond);

}


