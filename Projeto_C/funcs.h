#include <windows.h>

struct Carteira{
	int id;
	float valor;
	char descritivo[50];
};

struct Carteira carteiras[15];

struct Utilizador{
	int nCliente;
	int tipo;	//cliente  = 0 | gestor = 1
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

struct Utilizador users[5];

int library_users(struct Utilizador users[])
{
  users[0].nCliente = 1;
  users[0].tipo = 0;
  strcpy(users[0].username, "user");
  strcpy(users[0].password, "user");
  strcpy(users[0].nome, "Diogo");
  strcpy(users[0].morada, "Avenida Francisco Araujo Gomes n 208");
  users[0].nContribuinte = 123456789;
  users[0].nIdentificacao = 242415;
  users[0].nPassaporte = 44556554;
  users[0].IBAN = 44556554;
  
  users[0].carteira[0].id = 1;
  users[0].carteira[0].valor = 122.20;
  users[0].carteira[1].id = 2;
  users[0].carteira[1].valor = 36.60;
  users[0].carteira[2].id = 3;
  users[0].carteira[2].valor = 97.10;
  //strcpy(users[0].carteira->descritivo,"");

  users[1].nCliente = 2;
  users[1].tipo = 1;
  strcpy(users[1].username, "admin");
  strcpy(users[1].password, "admin");
  strcpy(users[1].nome, "Joao");
  strcpy(users[1].morada, "Arcozelo Barcelos");
  users[1].nContribuinte = 987654321;
  users[1].nIdentificacao = 362515;
  users[1].nPassaporte = 6181915;
  users[1].IBAN = 44556554;
  
  users[1].carteira[0].id = 1;
  users[1].carteira[0].valor = 174.20;
  users[1].carteira[1].id = 2;
  users[1].carteira[1].valor = 142.60;
  users[1].carteira[2].id = 3;
  users[1].carteira[2].valor = 67.10;
  //strcpy(users[1].carteira->descritivo,"");
  
  return 2; // return the no. of filled items
}

int c;
int i;
int j;
int struct_data[150];
int acceptable[] = {32,34,44,48,49,50,51,52,53,54,55,56,57,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,97,98,99,100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119,120,121,122,126};
struct Utilizador user_array[5];

int struct_data_size = sizeof struct_data / sizeof struct_data[0];
int acceptable_size = sizeof acceptable / sizeof acceptable[0];
int carteira_size = sizeof carteiras / sizeof carteiras[0];
int users_size = sizeof users / sizeof users[0];

int *login()
{
	int tentativas = 1;
	char username[20];
	char password[20];
	int i;
	int user;
	static int log[2];

	//printf("size. %d\n", size);;

	while(tentativas <= 3)	
	{
		if(log[1] != 1)
		{
			printf("username: ");
			scanf("%s", &username);
			printf("password: ");
			scanf("%s", &password);

			for(i=0; i< 10 /* ou sizeUsers*/ ; i++)
			{	
				//printf("ncliente: %d", users[i].nCliente);
				if(strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0)
				{	
					printf("logado!\n\n");
					log[0] = users[i].nCliente;
					log[1] = 1;
					//printf("%d", log[1]);
					Sleep(1200);
					system("cls");
					break;break;
				}
			}

			if(log[1] == 0)
			{
				printf("credenciais erradas!\n");
				tentativas++;
				if(tentativas > 3)
				{
					printf("chegou ao numero maximo de tentativas!\n");
					exit(0);
				}
			}
		}else{
			break;
		}
	}
	return log;
}

void showUser(int n)
{
	n--;
	char userTipo[20];

	if(users[n].tipo == 0){
		strcpy(userTipo, "cliente");
	}else{
		strcpy(userTipo, "gestor de clientes");}

	printf("Numero do Cliente: %d\n", users[n].nCliente);
	printf("Tipo de utilizador: %s\n", userTipo);
	
	if(users[n].tipo == 1){
			printf("Username: %s\n", users[n].username);
			printf("Password: %s\n", users[n].password);}

	printf("Nome: %s\n", users[n].nome);
	printf("Morada: %s\n", users[n].morada);
	printf("Numero de Contribuinte: %d\n", users[n].nContribuinte);
	printf("Numero de Passaporte: %d\n", users[n].nPassaporte);
	printf("Numero de IBAN: %d\n", users[n].IBAN);
}

void showCarteiras(int n)
{
	n--;
	int i = 0;
	//printf("%d", sizeCarteiras);

	for(i=0; i< 3 /*sizeCarteiras dá lixo*/; i++)
	{
		//printf("%d ", i);
		//printf("%d\n",users[n].carteira[i].id);

		if(users[n].carteira[i].id > 0)
		{
			printf("Carteira id: %d\n", users[n].carteira[i].id);
			printf("Valor total: %.2f\n\n", users[n].carteira[i].valor);
	 	}
	}
}

void write_users()
{
  int items = library_users(user_array);
  FILE* ptr = fopen("dados.dat","wb");
  if(! ptr) return; // TODO: better error handling
  fwrite( users, sizeof(struct Utilizador), items, ptr);
  fclose(ptr);
}

int read_users()
{
  FILE* ptr = fopen("dados.dat","rb");
  if( !ptr ) return 0;
  int n = 0;
  for (n=0; !feof(ptr); ++n)
  {
    if ( fread(&users[n],sizeof(struct Utilizador),1,ptr) != 1) break;
  }

  fclose(ptr);
  return n;
}

void list_users()
{
	int items = library_users(users);

	for(i=0; i < items; i++)
	{
		printf("Numero de cliente: %d\n", users[i].nCliente);
		printf("Tipo: %d\n", users[i].tipo);
		printf("Username: %s\n", users[i].username);
		printf("Password: %s\n", users[i].password);
		printf("Nome: %s\n", users[i].nome);
		printf("Morada: %d\n", users[i].morada);
		printf("Numero de Contribuinte: %d\n", users[i].nContribuinte);
		printf("Numero de Identificacao: %d\n", users[i].nIdentificacao);
		printf("Numero de Passaporte: %d\n", users[i].nPassaporte);
		printf("Numero de IBAN: %d\n", users[i].IBAN);
		
		for(int n=0; n < 3; n++)
		{
			printf("Id da carteira %d: %d\n", n+1, users[i].carteira[n].id);
			printf("Valor da carteira %d: %.2f\n", n+1, users[i].carteira[n].valor);
		}
		printf("\n");
	}
}

void readPrintStructCSV()
{
    FILE *file;
    file = fopen("dados.csv", "r");

    if(file)
    {
        while((c = getc(file)) != EOF)
        {
            struct_data[i] = c;
            i++;
        }
        fclose(file);
    }

    //printf("%d\n", acceptable_size);
    //printf("%d\n", struct_data_size);

    for(i=0; i< struct_data_size; i++)
    {
        //printf("n do caracter lido: %d\n", i);
        for(j=0; j< acceptable_size; j++)
        {
            //printf("n do caracter permitido: %d\n", j);
            if(struct_data[i] == acceptable[j])
            {
                putchar(struct_data[i]);
            }
        }
    }
}
