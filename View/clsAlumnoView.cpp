#include "clsAlumnoView.h"
#include <cstring>

void clsAlumnoView::menu()
{
    bool salir=false;
    while(!salir)
    {
        char op;
        system("cls");
        cout<<"*------------------------ALUMNOS-------------------------*"<<endl;
        cout<<"* A - Nuevo alumno                                       *"<<endl;
        cout<<"* B - Listar alumnos                                     *"<<endl;
        cout<<"* C - Buscar alumno                                      *"<<endl;
        cout<<"* D - Listar materias por alumno                         *"<<endl;
        cout<<"* E - Eliminar alumno                                    *"<<endl;
        cout<<"* F - Modificar alumno                                   *"<<endl;
        cout<<"* S - Salir                                              *"<<endl;
        cout<<"*--------------------------------------------------------*"<<endl;
        cout<<"Ingrese una opcion: ";
        cin>>op;
        cin.ignore();
        switch(op)
        {
        case 'a':
        case 'A':
        {
            Insertar();
        }
        break;
        case 'b':
        case 'B':
        {
            Listar();
            system("pause");
        }
        break;
        case 'c':
        case 'C':
            {
                clsAlumnoView v;
                v.buscarAlumno();
                system("pause");
            }break;
        case 'd':
        case 'D':
            {
                clsMateriaXAlumnoView v;
                v.listarMxA();
                system("pause");

            }break;
        case 'e':
        case 'E':
        {
            Eliminar();

        }
        break;
        case 'f':
        case 'F':
        {
            Modificar();

        }
        break;
        case 's':
        case 'S':
        {
            salir=true;
        }
        break;
        default:
            cout<<"ERROR.";
            break;

        }

    }

}
void clsAlumnoView::Insertar ()
{
    cout<<"*--------------------NUEVO ALUMNO------------------------*"<<endl;
    clsAlumnoDTO dto;
    int dia,mes,anio;
    clsAlumnoBL bl;
    clsValidacion val;
    char nombre[50];
   val.ValidarRequerido("Ingrese el nombre del alumno: ",nombre,50);
    cout<<"Ingrese dia de nacimiento: ";
    cin>>dia;
    cout<<"Ingrese mes de nacimiento: ";
    cin>>mes;
    cout<<"Ingrese año de nacimiento: ";
    cin>>anio;
    dto.SetNombre(nombre);
    dto.SetDia_Nac(dia);
    dto.SetMes_Nac(mes);
    dto.SetAnio_Nac(anio);

    bl.Insertar(dto);

}
void clsAlumnoView::Eliminar()
{
    clsAlumnoBL bl;
    int legajo;
    cout<<"*--------------------ELIMINAR ALUMNO---------------------*"<<endl;
    cout<<"Ingrese el legajo del alumno que desea eliminar: ";
    cin>>legajo;
    bl.Eliminar(legajo);

}
void clsAlumnoView::Modificar()
{
    clsAlumnoDTO dto;
    cout<<"*--------------------MODIFICAR ALUMNO--------------------*"<<endl;
    int dia,mes,anio,legajo;
    clsAlumnoBL bl;
    char nombre[50];
    cout<<"Ingrese el legajo del alumno que desea modificar: ";
    cin>>legajo;
    cin.ignore();
    cout<<"Ingrese el nuevo nombre del alumno: ";
    cin.getline(nombre,50);
    cout<<"Ingrese dia de nacimiento: ";
    cin>>dia;
    cout<<"Ingrese mes de nacimiento: ";
    cin>>mes;
    cout<<"Ingrese año de nacimiento: ";
    cin>>anio;
    dto.SetNombre(nombre);
    dto.SetDia_Nac(dia);
    dto.SetMes_Nac(mes);
    dto.SetAnio_Nac(anio);
    dto.SetLegajo(legajo);
    bl.Modificar(dto);

}
void clsAlumnoView::Listar()
{
    clsAlumnoBL bl;
    int c=bl.Count();
    clsAlumnoDTO *lista;
    lista=(clsAlumnoDTO*)malloc(sizeof(clsAlumnoDTO)*c);
    bl.Listar(lista);
    cout<<"-------------------------------ALUMNOS-------------------------------------------------------------------"<<endl;
    cout<<left<<"|"<<setw(30)<<"Alumno"<<"|"<<setw(30)<<"Legajo"<<"|"<<"Fecha de nacimiento"<<endl;
    cout<<"---------------------------------------------------------------------------------------------------------"<<endl;

    for(int i=0; i<c; i++)
    {
        char nombre[50];
        lista[i].GetNombre(nombre);
        int legajo=lista[i].GetLegajo();
        int dia=lista[i].GetDia_Nac();
        int mes=lista[i].GetMes_Nac();
        int anio=lista[i].GetAnio_Nac();
        cout<<left<<"|"<<setw(30)<<nombre<<"|"<<setw(30)<<legajo<<"|"<<dia<<"-"<<mes<<"-"<<anio<<endl;
        cout<<"---------------------------------------------------------------------------------------------------------"<<endl;
    }

}


void clsAlumnoView::buscarAlumno()
{


    clsAlumnoBL bl;
    char cond[50];
    cout<<"Igrese el nombre de la materia que desea buscar: ";
    cin.getline(cond,50);
    int c=bl.BuscarSubCount(cond);
    clsAlumnoDTO *lista;
    lista=(clsAlumnoDTO*)malloc(sizeof(clsAlumnoDTO)*c);
    bl.BuscarSub(lista,cond);
  cout<<"-------------------------------ALUMNOS-------------------------------------------------------------------"<<endl;
    cout<<left<<"|"<<setw(30)<<"Alumno"<<"|"<<setw(30)<<"Legajo"<<"|"<<"Fecha de nacimiento"<<endl;
    cout<<"---------------------------------------------------------------------------------------------------------"<<endl;

    for(int i=0; i<c; i++)
    {
        char nombre[50];
        lista[i].GetNombre(nombre);
        int legajo=lista[i].GetLegajo();
        int dia=lista[i].GetDia_Nac();
        int mes=lista[i].GetMes_Nac();
        int anio=lista[i].GetAnio_Nac();
        cout<<left<<"|"<<setw(30)<<nombre<<"|"<<setw(30)<<legajo<<"|"<<dia<<"-"<<mes<<"-"<<anio<<endl;
        cout<<"---------------------------------------------------------------------------------------------------------"<<endl;
    }



}


