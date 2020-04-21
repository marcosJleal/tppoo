#include "clsAlumnoDAO.h"

void clsAlumnoDAO::Insertar (clsAlumnoDTO dto)
{
    FILE *p;
    p=fopen(ARCHIVO_ALUMNOS,"ab");
    if(p!=NULL)
    {
        fwrite(&dto,sizeof(clsAlumnoDTO),1,p);
        fclose(p);
    }

}
void clsAlumnoDAO::Eliminar(int legajo)
{
    clsAlumnoDTO dto;

    FILE *p;
    p=fopen(ARCHIVO_ALUMNOS,"rb+");
    if(p!=NULL)
    {
        int pos=0;
        while(fread(&dto,sizeof(clsAlumnoDTO),1,p))
        {
            if(dto.GetLegajo()==legajo&&!dto.GetEliminado())
            {
                dto.SetEliminado(true);
                fseek(p,sizeof(clsAlumnoDTO)*pos,SEEK_SET);
                fwrite(&dto,sizeof(clsAlumnoDTO),1,p);
                break;
            }
            pos++;
        }
    }
    fclose(p);

}
void clsAlumnoDAO::Modificar(clsAlumnoDTO dto)
{
    clsAlumnoDTO dto_arch;
    FILE*p;
    int pos=0;
    p=fopen(ARCHIVO_ALUMNOS,"rb+");
    if(p!=NULL)
    {
        while(fread(&dto_arch,sizeof(clsAlumnoDTO),1,p))
        {
            if(dto_arch.GetLegajo()==dto.GetLegajo()&&!dto_arch.GetEliminado())
            {
                fseek(p,sizeof(clsAlumnoDTO)*pos,SEEK_SET);
                fwrite(&dto,sizeof(clsAlumnoDTO),1,p);
                break;
            }
            pos++;
        }
        fclose(p);
    }

}
void clsAlumnoDAO::Listar(clsAlumnoDTO*dto)
{
    int pos=0;
    clsAlumnoDTO dto_arch;
    FILE*p;
    p=fopen(ARCHIVO_ALUMNOS,"rb");
    if(p!=NULL)
    {
        while(fread(&dto_arch,sizeof(clsAlumnoDTO),1,p))
        {
            if(!dto_arch.GetEliminado())
            {
                dto[pos].Copy(dto_arch);
                pos++;

            }
        }
    }
    fclose(p);


}
int clsAlumnoDAO::Count()
{
    clsAlumnoDTO dto;
    int cont=0;
    FILE*p;
    p=fopen(ARCHIVO_ALUMNOS,"rb");
    if(p!=NULL)
    {
        while(fread(&dto,sizeof(clsAlumnoDTO),1,p))
        {
            if(!dto.GetEliminado())
            {
                cont++;
            }

        }
    }
    fclose(p);
    return cont;
}

void clsAlumnoDAO::BuscarSub(clsAlumnoDTO* dto,char *sub)
{
    int pos=0;
    clsAlumnoDTO dto_archivo;
    clsCadenaHelper cad;
    char nombre[50];
    FILE *p;
    p=fopen(ARCHIVO_ALUMNOS,"rb");
    if(p!=NULL)
    {
        while(fread(&dto_archivo,sizeof(clsAlumnoDTO),1,p))
        {
            dto_archivo.GetNombre(nombre);
            if(!dto_archivo.GetEliminado()&& cad.strSub(nombre,sub)>=0)
            {
                dto[pos].Copy(dto_archivo);
                pos++;
            }
        }
        fclose(p);

    }
}
int clsAlumnoDAO::BuscarSubCount(char* cond)
{
    int cont=0;
    clsAlumnoDTO dto;
    clsCadenaHelper cad;
    char nombre[50];
    FILE *p;
    p=fopen(ARCHIVO_ALUMNOS,"rb");
    if(p!=NULL)
    {
        while(fread(&dto,sizeof(clsAlumnoDTO),1,p))
        {
            dto.GetNombre(nombre);
            if(!dto.GetEliminado()&&cad.strSub(nombre,cond)>=0)
            {
                cont++;
            }
        }
        fclose(p);

    }
    return cont;

}



