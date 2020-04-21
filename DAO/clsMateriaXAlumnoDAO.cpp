#include "clsMateriaXAlumnoDAO.h"


void clsMateriaXAlumnoDAO::insertar(clsMateriaXAlumnoDTO dto)
{
    FILE *p;
    p=fopen(ARCHIVO_MATERIASXALUMNO,"ab");
    if(p!=NULL)
    {
        fwrite(&dto,sizeof(clsMateriaXAlumnoDTO),1,p);
        fclose(p);
    }
}
void clsMateriaXAlumnoDAO::eliminar(int legajo,int id)
{
    clsMateriaXAlumnoDTO reg;
    FILE *p;
    p=fopen(ARCHIVO_MATERIASXALUMNO,"rb+");
    while(fread(&reg,sizeof(clsMateriaXAlumnoDTO),1,p))
    {
        if(reg.GetLegajo()==legajo&&reg.GetId_Materia()==id)
        {
            reg.SetEliminado(true);
            break;
        }

    }
    fclose(p);

}
void clsMateriaXAlumnoDAO::listar (clsMateriaXAlumnoDTO* dto)
{
    int pos=0;
    clsMateriaXAlumnoDTO dto_arch;
    FILE *p;
    p=fopen(ARCHIVO_MATERIASXALUMNO,"rb");
    if(p!=NULL)
    {
        while(fread(&dto_arch,sizeof(clsMateriaXAlumnoDTO),1,p))
        {
            if(!dto_arch.GetEliminado())
            {
                dto[pos].Copy(dto_arch);
                pos++;
            }
        }
        fclose(p);

    }
    }

    int clsMateriaXAlumnoDAO::Count()
    {
        clsMateriaXAlumnoDTO dto;
        int pos=0;
        FILE *p;
        p=fopen(ARCHIVO_MATERIASXALUMNO,"rb");
        while(fread(&dto,sizeof(clsMateriaXAlumnoDTO),1,p))
        {
            if(!dto.GetEliminado())
                pos++;
        }
        fclose(p);
        return pos;


    }
