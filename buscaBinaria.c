#include <stdio.h>
#include <string.h>
#include <locale.h>

typedef struct _Endereco Endereco;

struct _Endereco
{
	char logradouro[72];
	char bairro[72];
	char cidade[72];
	char uf[72];
	char sigla[2];
	char cep[8];
	char lixo[2];
};


int main(int argc, char**argv) {
    FILE *f = fopen ("cep_ordenado.dat", "r");
    long tamanho, posicao, primeiro, ultimo, meio;
    Endereco e;
	int qt;


    setlocale(LC_ALL, "Portuguese_Brazil");

    	if(argc != 2){
		fprintf(stderr, "USO: %s [CEP]", argv[0]);
		return 1;
	}

    fseek(f,0,SEEK_END);
    tamanho = ftell(f);
    primeiro = 0;
    ultimo = (tamanho/sizeof(Endereco))-1;
    int c =0;
    rewind(f);


    while (strncmp(argv[1],e.cep,8)!=0){
        meio = (primeiro + ultimo)/2;
        c++;


        fseek(f, sizeof(Endereco) * meio, SEEK_SET);
        fread(&e, sizeof(Endereco), 1, f);
        
            if (strncmp(argv[1],e.cep,8)>0){
                primeiro = meio + 1;
            }else if (strncmp(argv[1],e.cep,8)<0){
                ultimo = meio - 1;
            } if (strncmp(argv[1],e.cep,8)==0){
                printf("\n%.72s\n%.72s\n%.72s\n%.72s\n%.2s\n%.8s\n",e.logradouro,e.bairro,e.cidade,e.uf,e.sigla,e.cep);
			    break;
            }

            if (c>20){
                printf("CEP não encontrado");
                break;
            }
    }
    printf("Total Lido: %d\n", c);

}