#include "clsMateriaDAO.h"

void clsMateriaDAO::Insertar (clsMateriaDTO dto)
{

    FILE *p;
    p=fopen(ARCHIVO_MATERIAS,"ab");
    if(p!=NULL)
    {
        fwrite(&dto,sizeof(clsMateriaDTO),1,p);
        fclose(p);
    }
}
void clsMateriaDAO::Eliminar(int id)
{
    clsMateriaDTO dto;
    int pos=0;
    FILE  * p;
    p=fopen(ARCHIVO_MATERIAS,"rb+");
    if(p!=NULL)
    {
        while(fread(&dto,sizeof(clsMateriaDTO),1,p))
        {
            if(dto.GetId()==id && !dto.GetEliminado())
            {
                dto.SetEliminado(true);
                fseek(p,sizeof(clsMateriaDTO)*pos,SEEK_SET);
                fwrite(&dto,sizeof(clsMateriaDTO),1,p);
                break;

            }
            pos++;
        }

        fclose(p);
    }
}
void clsMateriaDAO::Modificar(clsMateriaDTO dto)
{
    clsMateriaDTO dto_arch;
    int pos=0;
    FILE * p;
    p=fopen(ARCHIVO_MATERIAS,"rb+");
    if(p!=NULL)
    {
        while(fread(&dto_arch,sizeof(clsMateriaDTO),1,p))
        {
            if(dto_arch.GetId()==dto.GetId() && !dto_arch.GetEliminado())
            {

                fseek(p,sizeof(clsMateriaDTO)*pos,SEEK_SET);
                fwrite(&dto,sizeof(clsMateriaDTO),1,p);
                break;

            }
            pos++;
        }

        fclose(p);

    }
}
void clsMateriaDAO::Listar(clsMateriaDTO* dto)
{
    int pos=0;
    clsMateriaDTO dto_archivo;
    FILE *p;
    p=fopen(ARCHIVO_MATERIAS,"rb");
    if(p!=NULL)
    {
        while(fread(&dto_archivo,sizeof(clsMateriaDTO),1,p))
        {
            if(!dto_archivo.GetEliminado())
            {
                dto[pos].Copy(dto_archivo);
                pos++;
            }
        }
        fclose(p);

    }
}
int clsMateriaDAO::Count()
{
    int cont=0;
    clsMateriaDTO dto;
    FILE *p;
    p=fopen(ARCHIVO_MATERIAS,"rb");
    if(p!=NULL)
    {
        while(fread(&dto,sizeof(clsMateriaDTO),1,p))
        {
            if(!dto.GetEliminado())
            {
                cont++;
            }
        }
        fclose(p);

    }
    return cont;

}

void clsMateriaDAO::BuscarSub(clsMateriaDTO* dto,char *sub)
{
    int pos=0;
    clsMateriaDTO dto_archivo;
    clsCadenaHelper cad;
    char nombre[50];
    FILE *p;
    p=fopen(ARCHIVO_MATERIAS,"rb");
    if(p!=NULL)
    {
        while(fread(&dto_archivo,sizeof(clsMateriaDTO),1,p))
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
int clsMateriaDAO::BuscarSubCount(char* cond)
{
    int cont=0;
    clsMateriaDTO dto;
    clsCadenaHelper cad;
    char nombre[50];
    FILE *p;
    p=fopen(ARCHIVO_MATERIAS,"rb");
    if(p!=NULL)
    {
        while(fread(&dto,sizeof(clsMateriaDTO),1,p))
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


