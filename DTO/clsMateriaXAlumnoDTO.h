#ifndef CLSMATERIAXALUMNODTO_H
#define CLSMATERIAXALUMNODTO_H


class clsMateriaXAlumnoDTO
{
    public:
        clsMateriaXAlumnoDTO();
        int GetId_Materia(){return id_Materia;}
        void SetId_Materia(int val){id_Materia=val;}
        int GetLegajo(){return legajo;}
        void SetLegajo(int val){legajo=val;}
        bool GetEliminado(){return eliminado;}
        void SetEliminado(bool val){eliminado=val;}

        void Copy(clsMateriaXAlumnoDTO);


    private:
        int id_Materia;
        int legajo;
        bool eliminado;
};

#endif // CLSMATERIAXALUMNODTO_H
