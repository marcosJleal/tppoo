#include "clsMainView.h"

void clsMainView::menu()
{
    bool salir=false;
    while(!salir)
    {
        char op;
        system("cls");
        cout<<"*--------------------------------------------------------*"<<endl;
        cout<<"* M - Materias                                           *"<<endl;
        cout<<"* A - Alumnos                                            *"<<endl;
        cout<<"* S - Salir                                              *"<<endl;
        cout<<"*--------------------------------------------------------*"<<endl;
        cout<<"Ingrese una opcion: ";
        cin>>op;
        cin.ignore();
        switch(op)
        {
        case 'm':
        case 'M':
        {
            clsMateriaView vw;
            vw.menu();
        }
        break;
        case 'a':
        case 'A':
        {
            clsAlumnoView v;
            v.menu();
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
