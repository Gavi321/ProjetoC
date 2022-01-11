#include <stdio.h>
#include <string.h>
#include <windows.h>

struct Carteira{
    int id;
    float valor;
    char descritivo[50];
};



struct Utilizador{
    int nCliente;
    int tipo;   //cliente  = 0 | gestor = 1
    //int logado;
    char username[20];
    char password[20];
    char nome[50];
    char morada[50];
    int nContribuinte;
    int nIdentificacao;
    int nPassaporte;
    int IBAN;
    struct Carteira carteira[3];
};



//struct Utilizador users[5];

int main()
{
}