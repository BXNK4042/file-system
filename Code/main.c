#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void create_file(const char *filename, const char *content){
    FILE *pointer = fopen(filename, "w");
    if (pointer == NULL){
        printf("Error to create file");
        return;
    }
    
    fprintf(pointer, "%s", content);
    printf(("File '%s' created successfully.\n"), filename);
}

void write_file(const char *filename, const char *content) {
    FILE *pointer = fopen(filename, "a");
    if (pointer == NULL) {
        perror("Error opening file for writing");
        return;
    }
    fprintf(pointer, "%s", content);
    fclose(pointer);
    printf("Data written to '%s'.\n", filename);
}

void read_file(const char *filename) {
    FILE *pointer = fopen(filename, "r");
    if (pointer == NULL) {
        perror("Error reading file");
        return;
    }
    char buffer[1024];
    printf("Content of '%s':\n", filename);
    while (fgets(buffer, sizeof(buffer), pointer)) {
        printf("%s", buffer);
    }
    fclose(pointer);
    printf("\n");
}

int main() {
    char filename[128];
    char content[1024];

    printf("Enter filename: ");
    fgets(filename, sizeof(filename), stdin);
    filename[strcspn(filename, "\n")] = 0;
    printf("Enter content: ");
    fgets(content, sizeof(content), stdin);
    create_file(filename, content);

    /*printf("Enter filename: ");
    fgets(filename, sizeof(filename), stdin);
    filename[strcspn(filename, "\n")] = 0;
    printf("Enter content to append: ");
    fgets(content, sizeof(content), stdin);
    write_file(filename, content);*/

    /*printf("Enter filename: ");
    fgets(filename, sizeof(filename), stdin);
    filename[strcspn(filename, "\n")] = 0;
    read_file(filename);*/
}