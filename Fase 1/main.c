/******************************************************************************
 * Ficheiro da função principal do projeto Navigate_IST
 * 
 * Autores:
 * 
 *  Igor Paruque ist1102901
 *  Mónica Ferreira ist1106520
 ******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "structs.h"
#include "IOmodule.h"
#include "prob_utils.h"

int main (int argc, char* argv[]){

    /*Verifica o número de argumentos*/
    if(argc !=2){
        return 0;
    }

    /* Tenta abrir os ficheiros de entrada e de saída */
    Files fblock = open_files(argv[1]);

    if(fblock == NULL){
        exit(0);
    }

    /* Resolução de problemas */
    

    while(){
        read_problem();
        switch(){
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
        }
        free_problem();
    }

    /* Prepara para fechar o programa */
    close_files(fblock);

    return 0;
}