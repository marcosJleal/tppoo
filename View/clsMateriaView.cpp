#include "clsMateriaView.h"

void clsMateriaView::menu()
{
    bool salir=false;
    while(!salir)
    {
        char op;
        system("cls");
        cout<<"*------------------------MATERIA-------------------------*"<<endl;
        cout<<"* A - Nueva materia                                      *"<<endl;
        cout<<"* B - Asignar alumno a materia                           *"<<endl;
        cout<<"* C - Listar materias                                    *"<<endl;
        cout<<"* D - Buscar materia                                     *"<<endl;
        cout<<"* E - Listar alumnos por materia                         *"<<endl;
        cout<<"* F - Eliminar materia                                   *"<<endl;
        cout<<"* G - Modificar materia                                  *"<<endl;
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
            clsMateriaBL bl;
            insertar();
        }
        break;
        case 'b':
        case 'B':
            {
                clsMateriaXAlumnoView v;
                v.insertar();

            }break;
        case 'c':
        case 'C':
        {
            listar();
            system("pause");
        }
        break;
        case 'd':
        case 'D':
            {
                clsMateriaView v;
                v.buscarMateria();
                system("pause");

            }break;
           case 'e':
        case 'E':
            {
                clsMateriaXAlumnoView v;
                v.listarAxM();
                system("pause");

            }break;
        case 'f':
        case 'F':
        {
            eliminar();

        }
        break;
        case 'g':
        case 'G':
        {
            modificar();


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

void clsMateriaView::insertar()
{
    char nombre[50];
    char profesor[50];
    clsMateriaDTO dto;
    clsMateriaBL bl;
    clsValidacion val,val2;
    system("cls");
    cout<<"-----------NUEVA MATERIA----------------"<<endl;
    val.ValidarRequerido("Ingrese un nombre: ",nombre,50);
    val2.ValidarRequerido("Ingrese el profesor: ",profesor,50);
    dto.SetNombre(nombre);
    dto.SetProfesor(profesor);
    bl.Insertar(dto);

    system("cls");


}
void clsMateriaView::listar()
{


    clsMateriaBL bl;
    int c=bl.Count();
    clsMateriaDTO *lista;
    lista=(clsMateriaDTO*)malloc(sizeof(clsMateriaDTO)*c);
    bl.Listar(lista);
    cout<<"-------------------------------MATERIAS------------------------------------------------------------------"<<endl;
    cout<<left<<"|"<<setw(30)<<"Materia"<<"|"<<setw(30)<<"Profesor"<<"|"<<"Id"<<endl;
    cout<<"---------------------------------------------------------------------------------------------------------"<<endl;


    for(int i=0; i<c; i++)
    {
        char nombre[50];
        char profesor[50];
        lista[i].GetNombre(nombre);
        lista[i].GetProfesor(profesor);
        int id=lista[i].GetId();

        cout<<left<<"|"<<setw(30)<<nombre<<"|"<<setw(30)<<profesor<<"|"<<id<<endl;
        cout<<"---------------------------------------------------------------------------------------------------------"<<endl;
    }
}

void clsMateriaView::eliminar()
{
    clsMateriaBL bl;
    int id;
    cout<<"-----------NUEVA MATERIA----------------"<<endl;
    cout<<"Ingresar el id de la materia que desea eliminar: ";
    cin>>id;

    bl.Eliminar(id);
}

void clsMateriaView::modificar()
{
    clsMateriaBL bl;
    clsMateriaDTO dto;
    int id;
    char nombre[50],profesor[50];
    cout<<"-----------MODIFICAR MATERIA----------------"<<endl;
    cout<<"Ingrese el id de la materia que desea modificar: ";
    cin>>id;
    cin.ignore();
    cout<<"Ingrese el nuevo nombre: ";
    cin.getline(nombre,50);
    cout<<"Ingrese el nuevo nombre del profesor: ";
    cin.getline(profesor,50);
    dto.SetId(id);
    dto.SetNombre(nombre);
    dto.SetProfesor(profesor);
    bl.Modificar(dto);




}

void clsMateriaView::buscarMateria()
{


    clsMateriaBL bl;
    char cond[50];
    cout<<"Igrese el nombre de la materia que desea buscar: ";
    cin.getline(cond,50);
    int c=bl.BuscarSubCount(cond);
    clsMateriaDTO *lista;
    lista=(clsMateriaDTO*)malloc(sizeof(clsMateriaDTO)*c);
    bl.BuscarSub(lista,cond);
    cout<<"-------------------------------MATERIAS------------------------------------------------------------------"<<endl;
    cout<<left<<"|"<<setw(30)<<"Materia"<<"|"<<setw(30)<<"Profesor"<<"|"<<"Id"<<endl;
    cout<<"---------------------------------------------------------------------------------------------------------"<<endl;


    for(int i=0; i<c; i++)
    {
        char nombre[50];
        char profesor[50];
        lista[i].GetNombre(nombre);
        lista[i].GetProfesor(profesor);
        int id=lista[i].GetId();

        cout<<left<<"|"<<setw(30)<<nombre<<"|"<<setw(30)<<profesor<<"|"<<id<<endl;
        cout<<"---------------------------------------------------------------------------------------------------------"<<endl;
    }
}



