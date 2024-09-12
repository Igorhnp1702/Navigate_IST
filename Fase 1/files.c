#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "structs.h"
#include "files.h"


const char *extension_in = ".1maps";
const char *extension_out = ".sol1maps";

char* malloc_str(size_t str_len){

    char* string = (char*)malloc(str_len);

    if (string == NULL) {
        exit(0);      
    }

    return string;
}

char* change_filenames_extension(const char* FileName, char* New_FileName, size_t FileName_len, size_t Extension_len){

    if (FileName_len >= Extension_len &&
        strcmp(FileName + FileName_len - Extension_len, extension_in) == 0) {
        strcpy(New_FileName, FileName);
        New_FileName[FileName_len - Extension_len] = '\0'; // Remove Old Extension
        strcat(New_FileName, extension_out);               // Add New Extension

    }
    else {
        free(New_FileName);
        New_FileName = NULL;
        exit(0);
    }

    return New_FileName;

}

FILE* Open_Read_File(char* filename){
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        free(filename);
        filename = NULL;
        exit(0);
    }
    return file;
}

FILE* Open_Write_File(char* filename){

    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        free(filename);
        filename = NULL;
        exit(0);
    }
    return file;
}


Files open_files(char* Input_Filename){


    size_t Input_Filename_len = strlen(Input_Filename);
    size_t extension_in_len = strlen(extension_in);
    size_t Output_Filename_len = Input_Filename_len - extension_in_len + strlen(extension_out) + 1;

    char* Output_Filename = malloc_str(Output_Filename_len);

    Output_Filename = change_filenames_extension(Input_Filename, Output_Filename, Input_Filename_len, extension_in_len);

    Files File = (Files) malloc( sizeof(struct _files) );
    File->Input = Open_Read_File(Input_Filename);
    File->Output = Open_Write_File(Output_Filename);
    
    free(Output_Filename);


    return File;
}