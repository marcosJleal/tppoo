#ifndef CLSMATERIADTO_H
#define CLSMATERIADTO_H
#include <cstring>

class clsMateriaDTO
{
    public:
        clsMateriaDTO();

        int GetId() { return Id; }
        void SetId(int val) { Id = val; }
        void GetNombre(char* val) {strcpy(val, Nombre);  }
        void SetNombre(char* val) { strcpy(Nombre,val); }
        void GetProfesor(char* val) { strcpy(val, Profesor); }
        void SetProfesor(char* val) { strcpy(Profesor,val);}
        bool GetEliminado() { return Eliminado; }
        void SetEliminado(bool val) { Eliminado = val; }
        void Copy(clsMateriaDTO);


    private:
        int Id;
        char Nombre[50];
        char Profesor[50];
        bool Eliminado;
};

#endif // CLSMATERIADTO_H
