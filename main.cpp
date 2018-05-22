#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;
char cuvant[100];

struct tranzitie {
    char litera;
    char stare[20];
} tranz[20];
void inserare_sir(char cuv[100],int poz,char subsir[20])
{
    char sir[100];
    sir[0]=NULL;
    int i;
    if(poz==0)
    {
        strcpy(sir,subsir);
        strcat(sir,cuv+1);
        strcpy(cuv,sir);
    }
    else
    {
    for(i=0;i<poz;i++)
        sir[i]=cuv[i];
        sir[poz]=NULL;
        strcat(sir,subsir);
        strcat(sir,cuv+poz+1);
        strcpy(cuv,sir);
    }
}

void GIC(char cuv[100], int total_tranzitii,int &OK) {
    int i,poz=-1; char lit_mare;
    char copiecuv[100];
    for(i=0;i<strlen(cuv);i++)
        if(cuv[i]>='A' && cuv[i]<='Z')
    {
        lit_mare=cuv[i];
        poz=i; i=strlen(cuv);
    }
    if(poz==-1 && strcmp(cuv,cuvant)==0)
     OK=1;
    else
    {
    for (i = 0; i < total_tranzitii; i++)
        if (tranz[i].litera == lit_mare && strlen(cuv)<=strlen(cuvant)+1)
        {
              strcpy(copiecuv,cuv);
              if(strcmp(tranz[i].stare,"#")!=0)
            inserare_sir(copiecuv,poz,tranz[i].stare);
            else strcpy(copiecuv+poz,copiecuv+poz+1);
            GIC(copiecuv,total_tranzitii,OK);
        }
    }
}
int main() {
    int total_tranzitii, nrfin;
    int i, OK = 0;
    ifstream f("gramatica");
    f >> total_tranzitii;
    for (i = 0; i < total_tranzitii; i++) {
        f>>tranz[i].litera;
        f.get();
        f>>tranz[i].stare;
        f.get();
    }
    char cuv[100];
    cuv[0]='S';
    cuv[1]=NULL;
   cout << "Introduceti cuvantul:" << endl;
    cin >> cuvant;

    cout << endl;
    GIC(cuv,total_tranzitii,OK);
    if(OK==0)
        cout<<"cuvant neacceptat";
    else
        cout<<"cuvant acceptat";
    return 0;
}
