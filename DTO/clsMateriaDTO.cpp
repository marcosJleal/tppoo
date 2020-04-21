#include "clsMateriaDTO.h"

clsMateriaDTO::clsMateriaDTO()
{
    this->Eliminado=false;

}

void clsMateriaDTO::Copy(clsMateriaDTO dto)
{
    char nombre[50], profesor[50];
    this->Id=dto.GetId();
    dto.GetNombre(nombre);
    strcpy(this->Nombre,nombre);
    dto.GetProfesor(profesor);
    strcpy(this->Profesor,profesor);

}
