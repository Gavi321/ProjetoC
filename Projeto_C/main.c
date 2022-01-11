#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "funcs.h"

int main(int argc, const char *argv[])
{
	int o;
	int *log;
	int items = library_users(users);
  	struct Utilizador * temp = malloc(sizeof(struct Utilizador) * items);

	printf("Bem vindo!\n\nMenu:\n1. Login\n2. Exportar Clientes\n3. Importar Clientes\n4. Listar Clientes\n0. Sair\nOpcao: ");
	scanf("%d", &o);

	switch(o)
	{
		case 0:
			system("cls");
			exit(0);
			break;
		case 1:
			system("cls");
			log = login(); //printf("%d", userID);
			int userID = *log;

			if(*(log + 1) == 1)
			{
				printf("Menu:\n1. Informacoes Cliente\n2. Ver Carteiras\n0. Sair\nOpcao: ");
				scanf("%d", &o);

				switch(o)
				{
					case 0:
						system("cls");
						exit(0);
						break;
					case 1:
						system("cls");
						//printf("%d", userID);
						showUser(userID);
						break;
					case 2:
						system("cls");
						showCarteiras(userID);
						break;
				}
			}
			break;
		case 2:
			system("cls");
			items = library_users(user_array);
			write_users(items);
			break;
		case 3:
			system("cls");
			items = read_users();
  			printf("%d users lidos\n",items);

			break;
		case 4:
			system("cls");
			list_users();
			break;
	}
	free(temp);
}

