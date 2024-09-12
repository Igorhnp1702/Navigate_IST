#ifndef __files__
#define __files__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "structs.h"


char* malloc_str(size_t str_len);
char* change_filenames_extension(const char* FileName, char* New_FileName, size_t FileName_len, size_t Extension_len);
FILE* Open_Read_File(char* filename);
FILE* Open_Write_File(char* filename);
Files open_files(char* Input_Filename);

#endif

