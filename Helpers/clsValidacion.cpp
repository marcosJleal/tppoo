#include "clsValidacion.h"

void  clsValidacion::ValidarRequerido(char *texto,char *out,int tam)
{
    bool reintentar;
    do
    {
        reintentar=true;
        int i=0;
        cout<<texto;
        cin.getline(out,tam);
        while(out[i]!='\0')
        {
            if((out[i]>='a'&&out[i]<='z')||(out[i]>='A'&&out[i]<='Z'))
            {
                reintentar=false;
            }
            i++;
        }
        while(out[i]!='\0')
        {
            if(out[i]>='0'&&out[i]<='9')reintentar=true;
            i++;
        }


    }
    while(reintentar);

}

