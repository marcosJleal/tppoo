#ifndef CLSMATERIADAO_H
#define CLSMATERIADAO_H
#include <cstdio>
#include "../DTO/clsMateriaDTO.h"
#include "../Helpers/clsCadenaHelper.h"

char const ARCHIVO_MATERIAS[]="ARCHIVO_MATERIAS.DAT";
class clsMateriaDAO
{
    public:
      void Insertar (clsMateriaDTO);
      void Eliminar(int);
      void Modificar(clsMateriaDTO);
      void Listar(clsMateriaDTO*);
      int Count();
      void BuscarSub(clsMateriaDTO*, char*);
      int BuscarSubCount(char *);



};

#endif // CLSMATERIADAO_H
