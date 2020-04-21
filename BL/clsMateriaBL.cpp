#include "clsMateriaBL.h"

void clsMateriaBL::Insertar (clsMateriaDTO dto)
{
    clsMateriaDAO dao;
    int id=dao.Count();

    dto.SetId(id);
    dto.SetEliminado(false);
    dao.Insertar(dto);


}
void clsMateriaBL::Eliminar(int id)
{
    clsMateriaDAO dao;
    dao.Eliminar(id);

}
void clsMateriaBL::Modificar(clsMateriaDTO dto)
{
    clsMateriaDAO dao;
    dao.Modificar(dto);
}
void clsMateriaBL::Listar(clsMateriaDTO *lista)
{
    clsMateriaDAO dao;
    dao.Listar(lista);

}
int clsMateriaBL::Count()
{
    clsMateriaDAO dao;
    return dao.Count();

}
void clsMateriaBL::BuscarSub(clsMateriaDTO*lista, char*cond)
{
    clsMateriaDAO dao;
    dao.BuscarSub(lista,cond);
}
int clsMateriaBL::BuscarSubCount(char *cond)
{
    clsMateriaDAO dao;
    return dao.BuscarSubCount(cond);

}

