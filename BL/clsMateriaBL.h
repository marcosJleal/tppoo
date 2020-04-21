#ifndef CLSMATERIABL_H
#define CLSMATERIABL_H
#include "../DAO/clsMateriaDAO.h"
#include "../DTO/clsMateriaDTO.h"

class clsMateriaBL
{
public:
    void Insertar (clsMateriaDTO);
    void Eliminar(int);
    void Modificar(clsMateriaDTO);
    void Listar(clsMateriaDTO*);
    int Count();
    void BuscarSub(clsMateriaDTO*, char*);
    int BuscarSubCount(char *);



private:
};

#endif // CLSMATERIABL_H
