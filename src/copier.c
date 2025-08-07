#include "copier.h"

#define MAX_PATH_SIZE 100
#define MAX_LINE_SIZE 1001

int is_file(char* path){
    while (*path != '\0'){
        if (*path == '.'){
            return 1;
        }
        path++;
    }

    return 0;
}

char* get_file_path(char* path, char* source){
    int is_file_path = is_file(path);
    if (is_file_path){
        return path;
    } else {
        char* name_path = malloc(sizeof(char*) * MAX_PATH_SIZE);
        char* source_name = strtok(source, "/");
        while (source_name != NULL){
            if (is_file(source_name)){
                break;
            }
            source_name = strtok(NULL, "/");
        }

        strcpy(name_path, path);
        strcat(name_path, "/");
        strcat(name_path, source_name);
        
        return name_path;
    } 
}

int copy_file(char* source, char* destination){
    if (source == NULL || destination == NULL){
        fprintf(stderr, "either source or destination was passed as a NULL pointer\n");
        return -1;
    } 
    
    FILE* src = fopen(source, "r+");
    
    if (src == NULL){
        fprintf(stderr, "cannot open source file of name %s\n", source);
        return -1;
    } 
    

    char* dst_name = get_file_path(destination, source);
    FILE* dst = fopen(dst_name, "w"); 
    
    if (dst == NULL){
        fprintf(stderr, "file of name %s could not be created\n", dst_name);
        return -1;
    }
    
    char buffer[MAX_LINE_SIZE];
    int bytes_read = 1;

    while (bytes_read > 0){
        bytes_read = fread(buffer, 1, sizeof(buffer) - 1, src);
        buffer[bytes_read] = '\0';        
        
        unsigned int len = fwrite(buffer, sizeof(char), strlen(buffer), dst);

        if (len != strlen(buffer)){
            fprintf(stderr, "copy failed");
        }
    }

    fclose(src);
    fclose(dst);

    return 1;
}

int main(int argc, char **argv){
    if (argc != 3){
        fprintf(stderr, "%d arguments passed, 2 were expected\n", argc - 1);
        return 0;
    } 
    char src[MAX_PATH_SIZE];
    char dst[MAX_PATH_SIZE];

    strncpy(src, argv[1], MAX_PATH_SIZE);
    strncpy(dst, argv[2], MAX_PATH_SIZE);

    copy_file(src, dst);
    return 0;
}
