#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int is_file(char* path);
char* get_file_path(char* path, char* source);
int copy_file(char* source, char* destination);
