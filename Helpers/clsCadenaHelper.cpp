#include "clsCadenaHelper.h"
#include <iostream>
using namespace std;
void clsCadenaHelper::strToUpper(char *cad)
{
    int pos=0;
    while(cad[pos]!='\0')
    {
        if (cad[pos]>= 97 && cad[pos]<= 122)
        {

            cad[pos]-=32;

        }

        pos++;
    }


}
int    clsCadenaHelper::strSub(char *cad,char *sub)
{
    char cadena[50],subcadena[50];
    strcpy(cadena,cad);
    strcpy(subcadena,sub);
    strToUpper(cadena);
    strToUpper(subcadena);
    int tam=strlen(subcadena);
    int i=0;
    while(cadena[i]!='\0')
    {
        int aux=i;
        int s=0;
        while(subcadena[s]==cadena[aux]&&subcadena[s]!='\0)')
        {
         s++;
         aux++;

        }
        if(s==tam)return i;
        i++;
    }

    return -1;
}
