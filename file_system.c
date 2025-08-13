#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>  // For listing files
#include <unistd.h>  // For access()

// Create or overwrite file
void create_file(const char *filename, const char *content) {
    FILE *fp = fopen(filename, "w");
    if (!fp) { perror("Error creating file"); return; }
    fprintf(fp, "%s", content);
    fclose(fp);
    printf("File '%s' created successfully.\n", filename);
}

// Append to file
void write_file(const char *filename, const char *content) {
    FILE *fp = fopen(filename, "a");
    if (!fp) { perror("Error opening file"); return; }
    fprintf(fp, "%s", content);
    fclose(fp);
    printf("Data appended to '%s'.\n", filename);
}

// Read file
void read_file(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (!fp) { perror("Error reading file"); return; }
    char buffer[256];
    printf("\n--- Content of '%s' ---\n", filename);
    while (fgets(buffer, sizeof(buffer), fp)) {
        printf("%s", buffer);
    }
    fclose(fp);
    printf("\n-----------------------\n");
}

// Delete file
void delete_file(const char *filename) {
    if (remove(filename) == 0) {
        printf("File '%s' deleted.\n", filename);
    } else {
        perror("Error deleting file");
    }
}

// Open file in default program
void open_file(const char *filename) {
    if (access(filename, F_OK) != 0) {
        printf("File '%s' does not exist.\n", filename);
        return;
    }
    char command[200];
    snprintf(command, sizeof(command), "xdg-open \"%s\" > /dev/null 2>&1 &", filename);
    system(command);
    printf("Opened '%s' in default program.\n", filename);
}

// List all files in current directory
void list_files() {
    DIR *d;
    struct dirent *dir;
    d = opendir(".");
    if (!d) { perror("Error opening directory"); return; }
    printf("\n--- Files in current directory ---\n");
    while ((dir = readdir(d)) != NULL) {
        if (dir->d_type == DT_REG) { // Only show regular files
            printf("%s\n", dir->d_name);
        }
    }
    closedir(d);
    printf("----------------------------------\n");
}

int main() {
    int choice;
    char filename[100];
    char content[256];

    while (1) {
        printf("\n===== Simple File Manager =====\n");
        printf("1. Create File\n");
        printf("2. Write to File (Append)\n");
        printf("3. Read File\n");
        printf("4. Delete File\n");
        printf("5. Open File\n");
        printf("6. List Files\n");
        printf("7. Exit\n");
        printf("Choose: ");
        scanf("%d", &choice);
        getchar(); // Clear input buffer

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
                printf("Enter filename: ");
                fgets(filename, sizeof(filename), stdin);
                filename[strcspn(filename, "\n")] = 0;
                open_file(filename);
                break;
            case 6:
                list_files();
                break;
            case 7:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option.\n");
        }
    }
}
