#include <stdlib.h>
#include <stdio.h>
#include "Funcoes.h"
#define ORDEM 3 // Ordem do kernel

PGM* LerPGM(char*entrada)
/*Recebe o nome do arquivo como entrada, realiza a leitura da imagem e
retorna uma inst�ncia alocada de forma din�mica da estrutura
de dados PGM.*/
{
    FILE *arq;
    PGM* img;
    img=(PGM*)malloc(sizeof(PGM));
    int i,j;    //Contadores.
    char a,b;   //Variaveis criadas apenas para armazenar "P2" lida do arquivo.
    //Inicializando o ponteiro arq que aponta para o arquivo:
    arq=fopen(entrada,"r");
    if (arq==NULL)
        exit(1);
    fscanf(arq,"%c %c",&a,&b); // Lendo "P2"
    //Lendo o n�mero de linhas, colunas, e o tamanho ma�ximo dos elementos da matriz:
    fscanf(arq,"%d %d %hhu",&img->c,&img->l,&img->maximo);
    //Alocando mem�ria para a matriz que armazena os pixels da imagem:
    img->imagem = alocacao(img->l,img->c);
    //Lendo os valores do arquivo e salvando em img->imagem:
    for(i=0;i<img->l;i++)
    {
        for(j=0;j<img->c;j++)
        {
            img->imagem[i][j]=0;
            fscanf(arq,"%hhu",&img->imagem[i][j]);
        }
    }
    fclose(arq);
    return (img);
}/* LerPGM */

void Convolucao(PGM* img, char** kernel,PGM* saida)
//Realiza a convolu��o de img pelo kernel e armazena o resutlado em saida.
{
    PGM* img_aumentada;
    int a,b,aux1,aux2,i,j,soma;
    /*
    'a' e 'b' s�o vari�veis utilizadas como contadores utilizados para percorrer a matriz
    de pixels.
    'aux1' e 'aux2' s�o vari�veis utilizadas para salvar a posi��o na matriz que ir� receber
    o pixel convolu�do.
    'i' e 'j' s�o contadores para percorrer o kernel.
    'soma' guarda o somat�rio da convolu��o em cada pixel.
    */
    //Alocando a Estrutura e recebendo os dados que necess�rios para percorrer a matriz de pixels:
    img_aumentada=(PGM*)malloc(sizeof(PGM));
    img_aumentada->l=img->l+2;
    img_aumentada->c=img->c+2;
    img_aumentada->maximo=img->maximo;
    //Aloca mem�ria para matriz de pixels que possui as linhas e colunas externas dobradas.
    img_aumentada->imagem=alocacao(img_aumentada->l,img_aumentada->c);
    /*Atribuindo  os valores para matriz_aumentada que � formada
    pela matriz original com as linhas e colunas externas dobradas:*/
    for (i=0;i<img->l;i++)
    {
        for(j=0;j<img->c;j++)
        {
            img_aumentada->imagem[i+1][j+1]=img->imagem[i][j];
        }
    }
    for(j=1;j<img_aumentada->c-1;j++)
    {
        img_aumentada->imagem[0][j]=img_aumentada->imagem[1][j];
        img_aumentada->imagem[img_aumentada->l-1][j]=img_aumentada->imagem[img_aumentada->l-2][j];
    }
    for(i=0;i<img_aumentada->l;i++)
    {
        img_aumentada->imagem[i][0]=img_aumentada->imagem[i][1];
        img_aumentada->imagem[i][img_aumentada->c-1]=img_aumentada->imagem[i][img_aumentada->c-2];
    }
    //Alocando mem�ria para para a vari�vel do tipo PGM* que armazena a matriz convolu�da:
    saida->l=img->l;
    saida->c=img->c;
    saida->maximo=img->maximo;
    saida->imagem = alocacao(saida->l,saida->c);
    //Realizando a Convolu��o:
    for(a=0;a<saida->l;a++)
    {
        for(b=0;b<saida->c;b++)
        {
            soma=0;
            aux1=a;
            for(i=2;i>=0;i--)
            {
                aux2=b;
                for(j=2;j>=0;j--)
                {
                    soma = soma+(img_aumentada->imagem[aux1][aux2])*(kernel[i][j]);
                    aux2++;
                }
                aux1++;
            }
            if(soma<0)
                soma=0;
            else if(soma>255)
                soma=255;
            saida->imagem[a][b]=soma;
        }
    }
    liberarPGM(img_aumentada);  //Liberando Mem�ria da matriz aumentada utilizada na convolu��o.
}/* Convolu��o */

//FUN��O REALIZA ALOCA��O DIN�MICA DE MATRIZES
unsigned char** alocacao(int lines, int columns)    //Recebe a quantidade de Linhas e Colunas como Par�metro
{
    int i; //Vari�vel Auxiliar para percorrer as linhas  da matriz
    unsigned char **m;
    m=(unsigned char**)malloc(lines*sizeof(unsigned char*)); //Aloca um Vetor de Ponteiros
    if(m==NULL)
    {
        printf("\n ERRO,MEMORIA N�O ALOCADA!\n\a");
        exit(1);
    }
    for (i = 0; i < lines; i++)//Percorre as linhas do Vetor de Ponteiros
    {
        //Aloca um Vetor de unsigned char para cada posi��o do Vetor de Ponteiros.
        m[i] = (unsigned char*) malloc(columns*sizeof(unsigned char));
        if(m[i]==NULL)
        {
            printf("\n ERRO,MEMORIA N�O ALOCADA!\n\a");
            exit(1);
        }
    }
    return m; //Retorna o Ponteiro para a Matriz Alocada
}/* alocacao */

void SalvarPGM(PGM* img, char* saida)
{
    int i,j;    //Utilizados como contadores;
    //Inicializando o ponteiro arq que aponta para o arquivo:
    FILE* arq=fopen(saida,"w");
    if (arq==NULL)
    {
        printf("Arquivo nao encontrado.\n");
        exit(1);
    }
    //Escrevendo no arquivo as caracter�sticas da matriz de pixels.
    fprintf(arq,"P2");
    fprintf(arq,"\n");
    fprintf(arq,"%d %d %hhu ",img->l,img->c,img->maximo);
    fprintf(arq,"\n");
    //Escrevendo no arquivo a matriz de pixels.
    for(i=0;i<img->l;i++)
    {
        for(j=0;j<img->c;j++)
        {
            fprintf(arq,"%hhu ",img->imagem[i][j]);
        }
        fprintf(arq,"\n");
    }
    fclose(arq);
}/* SalvarPGM */

void liberarPGM(PGM* img)   //Fun��o que libera a mem�ria alocada para a Estrutura e para todas as vari�veis que ela possui.
{
    int aux;    //contador para percorrer as linhas da matriz de pixels.
    for (aux=0;aux<img->l;aux++)
    {
        free(img->imagem[aux]);
    }
    free (img->imagem);
    free (img);
}/* liberarPGM */

char** GeraKernel()     //Fun��o que gera o kernel que faz a derivada da imagem.
{
    char**kernel;
    int i;      //Utilizado como contador;
    kernel=(char**)malloc(ORDEM*sizeof(unsigned char*));    //Aloca um Vetor de Ponteiros
    if(kernel==NULL)
    {
        printf("\n ERRO,MEMORIA N�O ALOCADA!\n\a");
        exit(1);
    }
    for (i = 0; i < ORDEM; i++)    //Percorre as linhas do Vetor de Ponteiros
    {
       kernel[i] = (char*) malloc(ORDEM*sizeof(char));  //Aloca um Vetor de Inteiros para cada posi��o do Vetor de Ponteiros.
    }
    for(i=0;i<3;i++)
    {
        kernel[i][0]=-1;
        kernel[i][1]=0;
        kernel[i][2]=1;
    }
    return(kernel);
}

void liberarKernel(char** kernel)   //Fun��o que libera mem�ria alocada para o kernel.
{
    int aux;    //contador para percorrer as linhas do kernel.
    for (aux=0;aux<ORDEM;aux++)    //ORDEM � uma contante com o n�mero de linhas e colunas da matriz kernel que � 3.
    {
        free(kernel[aux]);
    }
    free (kernel);
}
