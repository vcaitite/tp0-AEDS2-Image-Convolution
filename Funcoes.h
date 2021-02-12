#ifndef _ARQUIVO_H_
#define _ARQUIVO_H_

typedef struct {
    int c;                  //N�mero de colunas da imagem
    int l;                  //N�mero de linhas da imagem
    unsigned char maximo;   //Valor m�ximo para cada pixel
    unsigned char **imagem; //vari�vel para armazenar os pixels da imagem (matriz)
}PGM;

PGM*LerPGM(char*entrada);
/*-------------------------------------------------------------------------------------
Prot�tipo:PGM*LerPGM(char*entrada)
Fun��o: L� os dados de um arquivo(.pgm) e os salva em uma vari�vel do tipo PGM.
Entrada: A fun��o recebe somente o nome do arquivo da qual ela ir� ler os dados.
Sa�da: Retorna o endere�o da vari�vel onde foram armazenados os dados lidos do arquivo.
--------------------------------------------------------------------------------------*/

void Convolucao(PGM* img, char** kernel,PGM* saida);
/*--------------------------------------------------------------------------------------
Prot�tipo: void Convolucao(PGM* img, char** kernel,PGM* saida)
Fun��o: Essa fun��o realiza a opera��o de convolu��o da imagem com o kernel recebidos como
par�metro e salva o resultado em *saida(cujo o endere�o � recebido pela fun��o).
Entrada: Os par�metros recebidos s�o uma estrutura PGM contendo a imagem de entrada, o
kernel(do tipo char) que realiza a convolu��o e PGM* saida onde salvar� a matriz convolu�da.
Sa�da: Por se tratar de uma fun��o void ela n�o retorna nada por�m ao seu final teremos como
resultado a imagem convolu�da salva por ponteiro.
---------------------------------------------------------------------------------------*/

unsigned char** alocacao(int lines, int columns);
/*--------------------------------------------------------------------------------------
Prot�tipo: unsigned char** alocacao(int lines, int columns)
Fun��o: Realiza aloca��o din�mica de matrizes.
Entrada: Recebe o n�mero de linhas e colunas da matriz a ser desalocada.
Sa�da: Retorna um endere�o para onde a mem�ria foi alocada.
---------------------------------------------------------------------------------------*/

void SalvarPGM(PGM* img, char* saida);
/*--------------------------------------------------------------------------------------
Prot�tipo: void SalvarPGM(PGM* img, char* saida)
Fun��o: Escreve a imagem contida em img em um arquivo no formato PGM com o nome descrito
na vari�vel saida
Entrada: Recebe PGM*img que cot�m os dados da imagem a ser salva em um arquivo.pgm e recebe
tamb�m o nome que esse arquivo deve ter.
Sa�da: A fun��o n�o retorna nada, ela apenas salva a imagem em um arquivo.
---------------------------------------------------------------------------------------*/

void liberarPGM(PGM* img);
/*--------------------------------------------------------------------------------------
Prot�tipo: void liberarPGM(PGM* img)
Fun��o: Libera a mem�ria alocada para a Estrutura e para todas as vari�veis que ela possui.
Entrada: Recebe a estrutura a qual se deseja desalocar a mem�ria.
Sa�da: A fun��o n�o retorna nada por se tratar de um void.
---------------------------------------------------------------------------------------*/

char** GeraKernel();
/*--------------------------------------------------------------------------------------
Prot�tipo: char** GeraKernel()
Fun��o: Essa fun��o aloca a mem�ria necess�ria e ainda gera o kernel utilizado para realizar
a derivada de imagens.
Entrada: A fun��o n�o recebe nada
Sa�da: Retorna um endere�o ende est� o kernel necess�rio para a convolu��o.
---------------------------------------------------------------------------------------*/

void liberarKernel(char** kernel);
/*--------------------------------------------------------------------------------------
Prot�tipo: void liberarKernel(char** kernel)
Fun��o: Libera a memoria da matriz kernel passada como par�metro.
Entrada: Recebe um ponteiro para a matriz kernel a ter sua mem�ria desalocada.
Sa�da: A fun��o n�o retorna nada.
---------------------------------------------------------------------------------------*/

#endif // _ARQUIVO_H_
