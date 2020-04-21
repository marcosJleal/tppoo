#include "clsMateriaXAlumnoView.h"

void BuscarMateria(char *cad,int id)
{
    clsMateriaDTO reg;
    FILE *p;
    p=fopen(ARCHIVO_MATERIAS,"rb");
    if(p!=NULL)
    {
        while(fread(&reg,sizeof(clsMateriaDTO),1,p))
        {
            if(reg.GetId()==id&&!reg.GetEliminado())
            {
                reg.GetNombre(cad);
                break;
            }
        }
        fclose(p);
    }
}
void buscarAlumno(char *cad,int legajo)
{
    clsAlumnoDTO reg;
    FILE *p;
    p=fopen(ARCHIVO_ALUMNOS,"rb");
    if(p!=NULL)
    {
        while(fread(&reg,sizeof(clsAlumnoDTO),1,p))
        {
            if(legajo==reg.GetLegajo()&&!reg.GetEliminado())
            {
                reg.GetNombre(cad);
                break;
            }
        }
    }
    fclose(p);
}


void clsMateriaXAlumnoView::insertar()
{

    int legajo, idMateria;
    cout<<"*---------------ASIGNAR ALUMNO A MATERIA-----------------*"<<endl;
    clsMateriaXAlumnoDTO dto;
    clsMateriaXAlumnoBL bl;
    cout<<"Ingrese el legajo del alumno: ";
    cin>>legajo;
    cout<<"Ingrese el id de la materia a la que desea asignar al alumno de legajo "<<legajo<<" :";
    cin>>idMateria;
    dto.SetId_Materia(idMateria);
    dto.SetLegajo(legajo);
    bl.insertar(dto);

}

void clsMateriaXAlumnoView::eliminar()
{
    cout<<"*---------------BAJA DE ALUMNO A MATERIA-----------------*"<<endl;
    int legajo,id;
    cout<<"Ingrese el id de la materia que desea dar baja a un alumno: ";
    cin>>id;
    cout<<"Ingrese el legajo del alumno que desea dar baja a la materia "<<id<<" :";
    cin>>legajo;
    clsMateriaXAlumnoBL bl;
    bl.eliminar(legajo,id);

}

void clsMateriaXAlumnoView::listarAxM()
{
    int id;
    system("cls");
    cout<<"Ingresee el id de la materia que desea listar alumnos: ";
    cin>>id;
    system("cls");
    clsMateriaXAlumnoBL bl;
    clsAlumnoBL b;
    clsAlumnoDTO *lista2;
    int d=b.Count();
    int c=bl.Count();

    clsMateriaXAlumnoDTO *lista;
    lista=(clsMateriaXAlumnoDTO*)malloc(sizeof(clsMateriaXAlumnoDTO)*c);
    bl.listar(lista);
    lista2=(clsAlumnoDTO*)malloc(sizeof(clsAlumnoDTO)*d);
    b.Listar(lista2);
    cout<<"---------------------LISTADO DE ALUMNOS POR MATERIA------------------------------------------------------"<<endl;
    cout<<left<<"|"<<setw(30)<<"Alumno"<<"|"<<setw(30)<<"Legajo"<<"|"<<"Materia"<<endl;
    cout<<"---------------------------------------------------------------------------------------------------------"<<endl;

    for(int x=0; x<c; x++)
    {
        if(lista[x].GetId_Materia()==id&&!lista[x].GetEliminado())
        {
            for(int y=0; y<d; y++)
            {
                if(lista2[y].GetLegajo()==lista[x].GetLegajo())
                {
                    char nombre[50],materia[50];
                    int leg;
                    lista2[y].GetNombre(nombre);
                    leg=lista2[y].GetLegajo();
                    BuscarMateria(materia,id);
                    cout<<left<<"|"<<setw(30)<<nombre<<"|"<<setw(30)<<leg<<"|"<<setw(30)<<materia<<endl;
                    cout<<"---------------------------------------------------------------------------------------------------------"<<endl;



                }
            }
        }
    }
    free(lista2);
    free(lista);
}

void clsMateriaXAlumnoView::listarMxA()
{

    system("cls");
    int leg;
    cout<<"Ingrese el legajo del alumno el cual desea conocer sus materias: ";
    cin>>leg;
    system("cls");

    cout<<"---------------------LISTADO DE MATERIAS POR ALUMNO------------------------------------------------------"<<endl;
    cout<<left<<"|"<<setw(30)<<"Materias"<<"|"<<setw(30)<<"Profesor"<<"|"<<"Alumno"<<endl;
    cout<<"---------------------------------------------------------------------------------------------------------"<<endl;

    clsMateriaBL b;
    clsMateriaXAlumnoBL bl;
    int c=bl.Count();
    int d=b.Count();
    clsMateriaXAlumnoDTO *lista;
    clsMateriaDTO *lista2;
    lista=(clsMateriaXAlumnoDTO*)malloc(sizeof(clsMateriaXAlumnoDTO)*c);
    lista2=(clsMateriaDTO*)malloc(sizeof(clsMateriaDTO)*d);
    bl.listar(lista);
    b.Listar(lista2);
    for(int x=0; x<c; x++)
    {
        if(lista[x].GetLegajo()==leg&&!lista[x].GetEliminado())
        {
            for(int y=0; y<d; y++)
            {
                if(lista[x].GetId_Materia()==lista2[y].GetId())
                {
                    char materia[50],profe[50],alumno[50];
                    lista2[y].GetNombre(materia);
                    lista2[y].GetProfesor(profe);
                    buscarAlumno(alumno,leg);
                    cout<<left<<"|"<<setw(30)<<materia<<"|"<<setw(30)<<profe<<"|"<<alumno<<endl;
                    cout<<"---------------------------------------------------------------------------------------------------------"<<endl;


                }
            }
        }

    }
    free(lista);
    free(lista2);

}




