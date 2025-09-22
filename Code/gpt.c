#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void create_file(const char *filename, const char *content) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        perror("Error creating file");
        return;
    }
    fprintf(fp, "%s", content);
    fclose(fp);
    printf("File '%s' created successfully.\n", filename);
}

void write_file(const char *filename, const char *content) {
    FILE *fp = fopen(filename, "a");
    if (fp == NULL) {
        perror("Error opening file for writing");
        return;
    }
    fprintf(fp, "%s", content);
    fclose(fp);
    printf("Data written to '%s'.\n", filename);
}

void read_file(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error reading file");
        return;
    }
    char buffer[256];
    printf("Content of '%s':\n", filename);
    while (fgets(buffer, sizeof(buffer), fp)) {
        printf("%s", buffer);
    }
    fclose(fp);
    printf("\n");
}

void delete_file(const char *filename) {
    if (remove(filename) == 0) {
        printf("File '%s' deleted successfully.\n", filename);
    } else {
        perror("Error deleting file");
    }
}

int main() {
    int choice;
    char filename[100];
    char content[256];

    while (1) {
        printf("\n===== Simple File System =====\n");
        printf("1. Create File\n");
        printf("2. Write to File\n");
        printf("3. Read File\n");
        printf("4. Delete File\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                printf("Enter filename: ");
                fgets(filename, sizeof(filename), stdin);
                filename[strcspn(filename, "\n")] = 0;
                printf("Enter content: ");
                fgets(content, sizeof(content), stdin);
                create_file(filename, content);
                break;
            case 2:
                printf("Enter filename: ");
                fgets(filename, sizeof(filename), stdin);
                filename[strcspn(filename, "\n")] = 0;
                printf("Enter content to append: ");
                fgets(content, sizeof(content), stdin);
                write_file(filename, content);
                break;
            case 3:
                printf("Enter filename: ");
                fgets(filename, sizeof(filename), stdin);
                filename[strcspn(filename, "\n")] = 0;
                read_file(filename);
                break;
            case 4:
                printf("Enter filename: ");
                fgets(filename, sizeof(filename), stdin);
                filename[strcspn(filename, "\n")] = 0;
                delete_file(filename);
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid option. Try again.\n");
        }
    }
}
