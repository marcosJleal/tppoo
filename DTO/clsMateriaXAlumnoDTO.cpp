#include "clsMateriaXAlumnoDTO.h"

clsMateriaXAlumnoDTO::clsMateriaXAlumnoDTO()
{
   this->eliminado=false;
}

void clsMateriaXAlumnoDTO::Copy(clsMateriaXAlumnoDTO dto)
{
    this->id_Materia=dto.GetId_Materia();
    this->legajo=dto.GetLegajo();
}
