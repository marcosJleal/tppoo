#include "clsAlumnoDTO.h"

clsAlumnoDTO::clsAlumnoDTO()
{
   this->eliminado=false;
}
void clsAlumnoDTO::Copy(clsAlumnoDTO dto)
{
    char Nombre[50];
    this->legajo=dto.GetLegajo();
    dto.GetNombre(Nombre);
    strcpy(this->nombre,Nombre);
    this->anio_nac=dto.GetAnio_Nac();
    this->mes_nac=dto.GetMes_Nac();
    this->dia_nac=dto.GetDia_Nac();

}
