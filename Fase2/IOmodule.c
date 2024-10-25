/******************************************************************************
 * Implementation of the input/output interface
 * 
 * Authors:
 * 
 *  Igor Paruque ist1102901
 *  Mónica Ferreira ist1106520
 ******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "IOmodule.h"


char *extension_in = ".maps";
char *extension_out = ".solmaps";

char* malloc_str(size_t str_len){

    char* string = (char*)malloc(str_len); // NULL will be checked outside of the function

    return string;
}

int check_ext(char *filename, char *extension)
{
    char *aux;
    int argsize = 0, extsize = 0, start = 0, result = 0, i;
    
    extsize = strlen(extension);
    argsize = strlen(filename);
    start = argsize - extsize;

    if((aux = (char*)calloc(extsize+1, sizeof(char))) == NULL){
        exit(0);
    }

    for(i = 0; i < extsize; i++){
        aux[i] = filename[i+start];
    }

    if (strcmp(aux, extension) != 0){
        free(aux);
        return result + 1;
    }
                    
    else{
        free(aux);
        return result;
    }    
}

void change_filenames_extension(const char* FileName, char** New_FileName, size_t FileName_len, size_t Extension_len){

    strcpy(*New_FileName, FileName);                      // Move into the new block of memory
    (*New_FileName)[FileName_len - Extension_len] = '\0'; // Remove Old Extension
    strcat(*New_FileName, extension_out);                 // Add New Extension
   
    return;
}

FILE* Open_Read_File(char* filename){
    FILE* file = fopen(filename, "r");    // NULL will be checked outside of the function
    return file;
}

FILE* Open_Write_File(char* filename){

    FILE* file = fopen(filename, "w");    // NULL will be checked outside of the function           
    return file;
}


Files* open_files(char* Input_Filename){    
    
    Files *Fileblock = NULL;

    /* If the right extension is found */
    if(check_ext(Input_Filename, extension_in) == 0){

        size_t Input_Filename_len = strlen(Input_Filename);
        size_t extension_in_len = strlen(extension_in);

        // the "+ 1" is for the null character
        size_t Output_Filename_len = Input_Filename_len - extension_in_len + strlen(extension_out) + 1;

        if((Fileblock = (Files*)calloc(1, sizeof(Files))) == NULL){
            exit(0);
        }
        
        if((Fileblock->Input = Open_Read_File(Input_Filename)) == NULL){
        
            free(Fileblock);
            exit(0);
        }

        if((Fileblock->outfile_str = malloc_str(Output_Filename_len)) == NULL){

            fclose(Fileblock->Input);
            free(Fileblock);
            exit(0);
        }

        change_filenames_extension(Input_Filename, &(Fileblock->outfile_str), Input_Filename_len, extension_in_len);
                
        if((Fileblock->Output = Open_Write_File(Fileblock->outfile_str)) == NULL){

            fclose(Fileblock->Input);
            free(Fileblock->outfile_str);
            free(Fileblock);
            exit(0);
        }
    }

    /* Else the pointer will be null (wrong extension) and the program should terminate */
    return Fileblock;    
}

void close_files(Files **fblock){
    fclose((*fblock)->Input);
    fclose((*fblock)->Output);
}