#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

typedef struct { //struct que relaciona dados de dependentes de um socio
char nome[20];
int idade;
} Depend;


typedef struct { //struct que relaciona dados de um socio
int id;
char nome[20];
int idade;
int qtdDep;
int qntAulas;
Depend dep[3];
bool natacao;
bool futsal;
bool tenis;
} Associado;

void menu();//exibe o menu para o usuario

void opc1(int *qntSocio, Associado socio[], int *alunosNat, int *alunosFut, int *alunosTen, int *maisAulas);//opcao1 do menu <cadastro de usuarios>
void opc2(int qntSocio, int *qntDepTotal, Associado socio[]);//opcao2 do menu <cadastro de dependentes>
void opc3(int qntSocio, Associado socio[]);//opcao3 do menu <listagem de socios>
void opc4(int qntSocio, Associado socio[]);//opcao4 do menu <listagem de socios por esporte>
void opc5(int qntSocio, Associado socio[]);//opcao5 do menu <pesquisa de socios>
void opc6(int qntSocio, int qntDepTotal, Associado socio[], int alunosNat, int alunosFut, int alunosTen, int maisAulas);//opcao6 do menu <relatorio geral>

void buscaId(int qntSocio, Associado socio[]);// busca por identificaçao de socios
void buscaNome(int qntSocio, Associado socio[]);//busca por nome de socios
void buscaIdade(int qntSocio, Associado socio[]);//busca por idade dos socios

int verifcIdade(int idade); //verifica se idades sao numeros positivos
char verificChar(char confirm);//verifica se os caracteres respondem os valores desejados
float mensalidades(int qntSocio, Associado socio);//calcula a mensalidade do socio

int main()
{
    int opcMenu, qntSocio, qntDepTotal, alunosNat, alunosFut, alunosTen, maisAulas;
    Associado socio[200];
    qntSocio=0;
    qntDepTotal=0;
    alunosNat=0;
    alunosFut=0;
    alunosTen=0;
    maisAulas=0;

    printf("Bom dia! eu sou um programa focado na gerencia de um clube esportivo!\n");
    printf("possuo as seguintes funcoes:\n");
    menu();
    printf("digite a opcao desejada:\n");
    scanf("%d", &opcMenu);
    do{
        switch(opcMenu){
            case 1: //cadastro de usuarios
                opc1(&qntSocio, socio, &alunosNat, &alunosFut, &alunosTen, &maisAulas);
                menu();
                printf("digite a opcao desejada:\n");
                scanf("%d", &opcMenu);
                break;
            case 2: //cadastro de dependentes
                opc2(qntSocio, &qntDepTotal, socio);
                menu();
                printf("digite a opcao desejada:\n");
                scanf("%d", &opcMenu);
                break;
            case 3: //listagem de socios
                opc3(qntSocio, socio);
                menu();
                printf("digite a opcao desejada:\n");
                scanf("%d", &opcMenu);
                break;
            case 4: //listagem de socios por esporte
            	opc4(qntSocio, socio);
                menu();
                printf("digite a opcao desejada:\n");
                scanf("%d", &opcMenu);
                break;
            case 5: //pesquisa de socios
                opc5(qntSocio, socio);
                menu();
                printf("digite a opcao desejada:\n");
                scanf("%d", &opcMenu);
                break;
            case 6: //relatorio geral
                opc6(qntSocio, qntDepTotal, socio, alunosNat, alunosFut, alunosTen, maisAulas);
                menu();
                printf("digite a opcao desejada:\n");
                scanf("%d", &opcMenu);
                break;
            case 7:
				//encerra programa
                break;
            default:
                system("clear||cls");
                printf("ainda nao possuo essa funcao!\a\n");
                menu();
                printf("qual opcao voce deseja?\n");
                scanf("%d", &opcMenu);
        }
    }while(opcMenu!=7);
    system("clear||cls");
    printf("ate mais! tenha um otimo dia!\n");

	return 0;
}
void menu(){ //exibe o menu para o usuario
    printf("------------------------------------------------------------------------------------\n");
    printf("|1- cadastrar associado <adiciona um novo associado ao banco de dados>             |\n");
    printf("|2- cadastrar dependente <adiciona um dependente a um socio ja cadastrado>         |\n");
    printf("|3- listar associados <mostra ao usuario os associados cadastrados>                |\n");
    printf("|4- listar associados por modalidade <mostra os socios que praticam uma modalidade>|\n");
    printf("|5- pesquisar associado <busca associados por nome, matricula ou idade>            |\n");
    printf("|6- gerar relatorio de associados <mostra um relatotio com informacoes dos socios> |\n");
    printf("|7- finalizar programa <encerra o programa>                                        |\n");
    printf("------------------------------------------------------------------------------------\n");
}

void opc1(int *qntSocio, Associado socio[], int *alunosNat, int *alunosFut, int *alunosTen, int *maisAulas){ //opcao1 do menu <cadastro de usuarios>
    system("clear||cls");

    char confirm;

    printf("para cadastrar um novo associado voce vai precisar de:\n");
    printf("-nome do associado <no maximo 20 caracteres>\n");
    printf("-idade do socio\n");
    printf("-atividades que ele frequenta\n");

    printf("insira o nome dele, por favor:\n");
    scanf(" %[^\n]s", socio[*qntSocio].nome);

    printf("quantos anos ele possui?\n");
    scanf("%d", &socio[*qntSocio].idade);
    socio[*qntSocio].idade = verifcIdade(socio[*qntSocio].idade);

    socio[*qntSocio].qntAulas=0;

    printf("ele pratica natacao?(s/n)\n");
    scanf(" %c", &confirm);
    confirm=verificChar(confirm);
    if(confirm=='s'||confirm=='S'){
        socio[*qntSocio].natacao=true;
        (socio[*qntSocio].qntAulas)++;
        (*alunosNat)++;
    }else{
        socio[*qntSocio].natacao=false;
    }

    printf("ele pratica futsal?(s/n)\n");
    scanf(" %c", &confirm);
    confirm=verificChar(confirm);
    if(confirm=='s'||confirm=='S'){
        socio[*qntSocio].futsal=true;
        (socio[*qntSocio].qntAulas)++;
        (*alunosFut)++;
    }else{
        socio[*qntSocio].futsal=false;
    }

    printf("ele pratica tenis?(s/n)\n");
    scanf(" %c", &confirm);
    confirm=verificChar(confirm);
    if(confirm=='s'||confirm=='S'){
        socio[*qntSocio].tenis=true;
        (socio[*qntSocio].qntAulas)++;
        (*alunosTen)++;
    }else{
        socio[*qntSocio].tenis=false;
    }

    if((*maisAulas)<socio[*qntSocio].qntAulas){
        (*maisAulas)=socio[*qntSocio].qntAulas;
    }

    socio[*qntSocio].qtdDep=0;
    (*qntSocio)++;



    socio[(*qntSocio)-1].id= (*qntSocio)*10;

    system("clear||cls");

    printf("o cadastro do socio %s esta pronto e sua id e %d!\n", socio[(*qntSocio)-1].nome, socio[(*qntSocio)-1].id);
}
void opc2(int qntSocio, int *qntDepTotal, Associado socio[]){ //opcao2 do menu <cadastro de dependentes>
    system("clear||cls");

    char confirm;
    int buscaId, qntDep, idadeDep, i;


    printf("para cadastrar dependentes, o socio ja precisa estar cadastrado!\n");
    printf("por favor, digite a id do socio:\n");
    scanf("%d", &buscaId);

    while((buscaId/10)>qntSocio || buscaId%10!=0){
        printf("id invalida! tente novamente!\n");
        scanf("%d", &buscaId);
    }

    buscaId= buscaId/10 - 1; // converter a id para posicao do vetor

    printf("o socio %s ja possui %d dependentes!\n", socio[buscaId].nome, socio[buscaId].qtdDep);
    do{
        qntDep = socio[buscaId].qtdDep;

        if(socio[buscaId].qtdDep==3){
            printf("o socio ja possui a quantidade maxima de dependentes!\n");
            break;
        }

        printf("por favor digite o nome do novo dependente:\n");
        scanf(" %[^\n]s", socio[buscaId].dep[qntDep].nome);

        printf("quantos anos ele tem?\n");
        scanf("%d", &socio[buscaId].dep[qntDep].idade);
        idadeDep = socio[buscaId].dep[qntDep].idade;
        socio[buscaId].dep[qntDep].idade = verifcIdade(idadeDep);

        socio[buscaId].qtdDep++;
        qntDep++;
        (*qntDepTotal)++;

        printf("quer cadastrar mais algum dependente? (s/n)\n");
        scanf(" %c", &confirm);
        confirm = verificChar(confirm);

        system("clear||cls");


    }while(confirm!='n' && confirm!='N');

    printf("esses sao os dependentes cadastrados ate o momento:\n");
    printf("nome - idade\n");
    for (i=0;i<qntDep; i++){

        printf("%s - %d\n", socio[buscaId].dep[i].nome, socio[buscaId].dep[i].idade);

    }
}
void opc3(int qntSocio, Associado socio[]){ //opcao3 do menu <listagem de socios>
    system("clear||cls");

    int i;
    char futsal[7], tenis[7], natacao[7];
    char sim[] = "faz";
    char nao[] = "nao faz";

    printf("foram cadastrados %d socios\n", qntSocio);
    printf("esses sao os associados cadastrados e as atividades que realizam:\n");
    printf("Id - Nome - Idade - quantidade de dependentes - Natacao - Futsal - Tenis\n");

    for(i=0;i<=qntSocio-1; i++){

        if(socio[i].natacao==true){
            strcpy(natacao,sim);
        }else{
            strcpy(natacao,nao);
        }

        if(socio[i].futsal==true){
            strcpy(futsal,sim);
        }else{
            strcpy(futsal,nao);
        }

        if(socio[i].tenis==true){
            strcpy(tenis,sim);
        }else{
            strcpy(tenis,nao);
        }


        printf("%d - %s - %d - %d - %s natacao - %s futsal - %s tenis\n", (socio[i].id),(socio[i].nome),(socio[i].idade),(socio[i].qtdDep),(natacao),(futsal),(tenis));
    }
}
void opc4(int qntSocio, Associado socio[]){ //opcao4 do menu <listagem de socios por esporte>

    system("clear||cls");

	int esporte, i;

	printf("qual a atividade que deseja buscar?\n");
	printf("1- natacao\n");
	printf("2- futsal\n");
	printf("3- tenis\n");
	printf("digite o codigo relativo a atividade escolhida\n");
	scanf("%d", &esporte);
	switch(esporte){
		case 1:

            system("clear||cls");

			printf("esses sao os associados que fazem natacao:\n");
			printf("id - nome\n");

			for(i=0;i<qntSocio; i++){

				if(socio[i].natacao==true){
					printf("%d - %s\n", socio[i].id, socio[i].nome);

				}
			}
			break;
		case 2:

            system("clear||cls");

            printf("esses sao os associados que fazem futsal:\n");
			printf("id - nome\n");

			for(i=0;i<qntSocio; i++){

				if(socio[i].futsal==true){
					printf("%d - %s\n", socio[i].id, socio[i].nome);

				}
			}
			break;
		case 3:

            system("clear||cls");

            printf("esses sao os associados que fazem tenis:\n");
			printf("id - nome\n");

			for(i=0;i<qntSocio; i++){

				if(socio[i].tenis==true){
					printf("%d - %s\n", socio[i].id, socio[i].nome);

				}
			}
			break;
		default:

			system("clear||cls");

			printf("opcao invalida!\n");
	}

}
void opc5(int qntSocio, Associado socio[]){ //opcao5 do menu <pesquisa de socios>

    system("clear||cls");

    int buscaSocio;

    printf("para pesquisar um associado vou precisar de alduma das 3 informacoes a baixo:\n");
    printf("1- id\n");
    printf("2- nome\n");
    printf("3- idade\n");

    printf("gostaria de pesquisar usando qual informacao?\n");
    printf("(digite o codigo numerico desejado)\n");
    scanf("%d", &buscaSocio);
    switch(buscaSocio){
        case 1:

            system("clear||cls");

            buscaId(qntSocio, socio);

            break;
        case 2:

            system("clear||cls");

            buscaNome(qntSocio, socio);

            break;
        case 3:

            system("clear||cls");

            buscaIdade(qntSocio, socio);

            break;
        default:

            system("clear||cls");

            printf("opcao invalida!");
    }
}
void opc6(int qntSocio, int qntDepTotal, Associado socio[], int alunosNat, int alunosFut, int alunosTen, int maisAulas){ //opcao6 do menu <relatorio geral>

    system("clear||cls");

    int i;
    float mensalidadeTotal, mediaMensal, maiorMensalidade;
    mensalidadeTotal=0;
    maiorMensalidade=0;

    for(i=0; i<qntSocio; i++){

        mensalidadeTotal+=mensalidades(qntSocio, socio[i]);

        if(mensalidades(qntSocio,socio[i])>maiorMensalidade){

            maiorMensalidade=mensalidades(qntSocio,socio[i]);

        }

    }

    mediaMensal=mensalidadeTotal/qntSocio;

    printf("esse e o relatorio geral do clube!\n");
    printf("-Quantidade total de socios: %d\n", qntSocio);
    printf("-Quantidade total de dependentes: %d\n", qntDepTotal);
    printf("-Quantidade de socios que fazem natacao: %d\n", alunosNat);
    printf("-Quantidade de socios que fazem futsal: %d\n", alunosFut);
    printf("-Quantidade de socios que fazem tenis: %d\n", alunosTen);
    printf("-Valor total das mensalidades dos socios: $%.2f\n", mensalidadeTotal);
    printf("-Valor medio das mensalidades dos socios: $%.2f\n", mediaMensal);
    printf("-Valor da mensalidade mais cara: $%.2f\n", maiorMensalidade);
    printf("-Socios que praticam mais aulas:\n");
    printf("\tid - nome\n");
    for(i=0; i<qntSocio; i++){

        if(maisAulas==socio[i].qntAulas){
            printf("\t%d - %s\n", socio[i].id, socio[i].nome);
        }

    }
}

void buscaId(int qntSocio, Associado socio[]){ // busca por identificaçao de socios

    int buscaId, i, achado;
    float mensalidade;
    achado = 0;

    printf("qual o id do socio desejado?\n");
    scanf("%d", &buscaId);

    printf("id - nome - idade - quantidade de dependentes - total de aulas -  mensalidade\n");

    for(i=0; i<qntSocio; i++){

        if(buscaId== socio[i].id){
        mensalidade = mensalidades(qntSocio, socio[i]);

        printf("%d - %s - %d - %d - %d - $%.2f\n", socio[i].id,socio[i].nome, socio[i].idade, socio[i].qtdDep, socio[i].qntAulas, mensalidade);
        achado++;
        }

    }

    if(achado==0){

        printf("socio nao encontrado!\n");

    }
}
void buscaNome(int qntSocio, Associado socio[]){ //busca por nome de socios
    int i, achado;
    float mensalidade;
    char buscaNome[20];
    achado = 0;

    printf("qual o nome do socio desejado?\n");
    scanf(" %[^\n]s", buscaNome);

    printf("id - nome - idade - quantidade de dependentes - total de aulas -  mensalidade\n");

    for(i=0; i<qntSocio; i++){

        if(strcmp(socio[i].nome,buscaNome)==0){
            mensalidade = mensalidades(qntSocio, socio[i]);

            printf("%d - %s - %d - %d - %d - $%.2f\n", socio[i].id,socio[i].nome, socio[i].idade, socio[i].qtdDep, socio[i].qntAulas, mensalidade);
            achado++;
        }

    }

    if(achado==0){

        printf("socio nao encontrado!\n");

    }
}
void buscaIdade(int qntSocio, Associado socio[]){ //busca por idade dos socios
    int i, achado, buscaIdade;
    float mensalidade;
    achado = 0;

    printf("qual a idade do socio desejado?\n");
    scanf("%d", &buscaIdade);

    printf("id - nome - idade - quantidade de dependentes - total de aulas -  mensalidade\n");

    for(i=0; i<qntSocio; i++){

        if(buscaIdade==socio[i].idade){
            mensalidade = mensalidades(qntSocio, socio[i]);

            printf("%d - %s - %d - %d - %d - $%.2f\n", socio[i].id,socio[i].nome, socio[i].idade, socio[i].qtdDep, socio[i].qntAulas, mensalidade);
            achado++;
        }

    }

    if(achado==0){

        printf("socio nao encontrado!\n");

    }
}

int verifcIdade(int idadeVerific){ //verifica se idades sao numeros positivos
    while(idadeVerific<=0){
        printf("idade invalida, digite uma idade positiva:\n");
        scanf(" %d", &idadeVerific);
    }
    return idadeVerific;
}
char verificChar(char confirm){ //verifica se os caracteres respondem os valores desejados
    while(confirm!='s'&& confirm!='S'&&confirm!='n'&& confirm!='N'){
        printf("resposta invalida, digite (s/S) para sim, (n/N) para nao\n");
        scanf(" %c", &confirm);
    }
    return confirm;
}
float mensalidades(int qntSocio, Associado socio){ //calcula a mensalidade do socio

    float mensal;
    mensal=0;

    mensal= 100 +50*(socio.qtdDep) + 30*(socio.qntAulas);
    return mensal;

}
