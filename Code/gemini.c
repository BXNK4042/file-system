#include <stdio.h>
#include <string.h>
#include <unistd.h> // For the unlink() function to delete files

// Function to create a new, empty file
void create_file(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error creating file: %s\n", filename);
        return;
    }
    printf("File created: %s\n", filename);
    fclose(file);
}

// Function to write data to a file
void write_to_file(const char *filename, const char *data) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file for writing: %s\n", filename);
        return;
    }
    fprintf(file, "%s", data);
    printf("Data written to file.\n");
    fclose(file);
}

// Function to read data from a file
void read_from_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    char buffer[100];

    if (file == NULL) {
        printf("Error opening file for reading: %s\n", filename);
        return;
    }

    if (fscanf(file, "%s", buffer) != EOF) {
        printf("Read from file: %s\n", buffer);
    } else {
        printf("File is empty or read error occurred.\n");
    }

    fclose(file);
}

// Function to delete a file
void delete_file(const char *filename) {
    if (unlink(filename) == 0) {
        printf("File deleted successfully: %s\n", filename);
    } else {
        printf("Error deleting file: %s\n", filename);
    }
}

int main() {
    const char *filename = "beginner_ops.txt";
    const char *data = "Hello, file system!";

    // 1. Create the file
    create_file(filename);

    // 2. Write data to the file
    write_to_file(filename, data);

    // 3. Read data from the file
    read_from_file(filename);

    // 4. Delete the file
    delete_file(filename);

    return 0;
}