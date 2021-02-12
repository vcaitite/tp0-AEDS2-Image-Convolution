#include <stdlib.h>
#include <stdio.h>
#include "Funcoes.h"

int main(int argc, char*argv[])
{
    char**kernel;
    PGM* img=NULL;
    PGM* saida=NULL;
    img = LerPGM(argv[1]); //A função recebe como parâmetro o nome do arquivo;
    saida=(PGM*)malloc(sizeof(PGM));
    kernel=GeraKernel();
    Convolucao(img,kernel,saida);
    SalvarPGM(saida,argv[2]); //Em argv[2] deve estar com o nome da nova imagem gerada.
    //liberação de memórias:
    liberarPGM(img);
    liberarPGM(saida);
    liberarKernel(kernel);
    return 0;
}

