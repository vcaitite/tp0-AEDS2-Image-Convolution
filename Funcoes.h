#ifndef _ARQUIVO_H_
#define _ARQUIVO_H_

typedef struct {
    int c;                  //Número de colunas da imagem
    int l;                  //Número de linhas da imagem
    unsigned char maximo;   //Valor máximo para cada pixel
    unsigned char **imagem; //variável para armazenar os pixels da imagem (matriz)
}PGM;

PGM*LerPGM(char*entrada);
/*-------------------------------------------------------------------------------------
Protótipo:PGM*LerPGM(char*entrada)
Função: Lê os dados de um arquivo(.pgm) e os salva em uma variável do tipo PGM.
Entrada: A função recebe somente o nome do arquivo da qual ela irá ler os dados.
Saída: Retorna o endereço da variável onde foram armazenados os dados lidos do arquivo.
--------------------------------------------------------------------------------------*/

void Convolucao(PGM* img, char** kernel,PGM* saida);
/*--------------------------------------------------------------------------------------
Protótipo: void Convolucao(PGM* img, char** kernel,PGM* saida)
Função: Essa função realiza a operação de convolução da imagem com o kernel recebidos como
parâmetro e salva o resultado em *saida(cujo o endereço é recebido pela função).
Entrada: Os parâmetros recebidos são uma estrutura PGM contendo a imagem de entrada, o
kernel(do tipo char) que realiza a convolução e PGM* saida onde salvará a matriz convoluída.
Saída: Por se tratar de uma função void ela não retorna nada porém ao seu final teremos como
resultado a imagem convoluída salva por ponteiro.
---------------------------------------------------------------------------------------*/

unsigned char** alocacao(int lines, int columns);
/*--------------------------------------------------------------------------------------
Protótipo: unsigned char** alocacao(int lines, int columns)
Função: Realiza alocação dinâmica de matrizes.
Entrada: Recebe o número de linhas e colunas da matriz a ser desalocada.
Saída: Retorna um endereço para onde a memória foi alocada.
---------------------------------------------------------------------------------------*/

void SalvarPGM(PGM* img, char* saida);
/*--------------------------------------------------------------------------------------
Protótipo: void SalvarPGM(PGM* img, char* saida)
Função: Escreve a imagem contida em img em um arquivo no formato PGM com o nome descrito
na variável saida
Entrada: Recebe PGM*img que cotém os dados da imagem a ser salva em um arquivo.pgm e recebe
também o nome que esse arquivo deve ter.
Saída: A função não retorna nada, ela apenas salva a imagem em um arquivo.
---------------------------------------------------------------------------------------*/

void liberarPGM(PGM* img);
/*--------------------------------------------------------------------------------------
Protótipo: void liberarPGM(PGM* img)
Função: Libera a memória alocada para a Estrutura e para todas as variáveis que ela possui.
Entrada: Recebe a estrutura a qual se deseja desalocar a memória.
Saída: A função não retorna nada por se tratar de um void.
---------------------------------------------------------------------------------------*/

char** GeraKernel();
/*--------------------------------------------------------------------------------------
Protótipo: char** GeraKernel()
Função: Essa função aloca a memória necessária e ainda gera o kernel utilizado para realizar
a derivada de imagens.
Entrada: A função não recebe nada
Saída: Retorna um endereço ende está o kernel necessário para a convolução.
---------------------------------------------------------------------------------------*/

void liberarKernel(char** kernel);
/*--------------------------------------------------------------------------------------
Protótipo: void liberarKernel(char** kernel)
Função: Libera a memoria da matriz kernel passada como parâmetro.
Entrada: Recebe um ponteiro para a matriz kernel a ter sua memória desalocada.
Saída: A função não retorna nada.
---------------------------------------------------------------------------------------*/

#endif // _ARQUIVO_H_
