#ifndef CLSALUMNODTO_H
#define CLSALUMNODTO_H
#include<cstring>



class clsAlumnoDTO
{
    public:
        clsAlumnoDTO();
        int GetLegajo(){return legajo;}
        void SetLegajo(int val){legajo=val;}
        void GetNombre(char *val){strcpy(val,nombre);}
        void SetNombre(char *val){strcpy(nombre,val);}
        int GetDia_Nac(){return dia_nac;}
        void SetDia_Nac(int val){dia_nac=val;}
        int GetMes_Nac(){return mes_nac;}
        void SetMes_Nac(int val){mes_nac=val;}
        int GetAnio_Nac(){return anio_nac;}
        void SetAnio_Nac(int val){anio_nac=val;}
        bool GetEliminado(){return eliminado;}
        void SetEliminado(bool val){eliminado=val;}
        void Copy(clsAlumnoDTO val);





    private:
        int legajo;
        char nombre[50];
        int dia_nac;
        int mes_nac;
        int anio_nac;
        bool eliminado;
};

#endif // CLSALUMNODTO_H
