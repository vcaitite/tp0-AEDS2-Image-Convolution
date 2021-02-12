#include <stdlib.h>
#include <stdio.h>
#include "Funcoes.h"

int main(int argc, char*argv[])
{
    char**kernel;
    PGM* img=NULL;
    PGM* saida=NULL;
    img = LerPGM(argv[1]); //A fun��o recebe como par�metro o nome do arquivo;
    saida=(PGM*)malloc(sizeof(PGM));
    kernel=GeraKernel();
    Convolucao(img,kernel,saida);
    SalvarPGM(saida,argv[2]); //Em argv[2] deve estar com o nome da nova imagem gerada.
    //libera��o de mem�rias:
    liberarPGM(img);
    liberarPGM(saida);
    liberarKernel(kernel);
    return 0;
}

