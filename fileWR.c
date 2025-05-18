#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

// 写文件
void write_file(const char *filename, const char *data) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Failed to open file for writing.\n");
        return;
    }
    fprintf(fp, "%s", data);
    fclose(fp);
}

// 读文件
char *read_file(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Failed to open file for reading.\n");
}
    char *data = (char *)malloc(1024);
    while (fgets(data, 1024, fp) != NULL) {
        printf("%s", data);
    }
    int ret = fclose(fp);
    assert(ret == 0);
    if (ret != 0) {
        printf("Failed to close file.\n");
    }
    return data;
}

int main() {
    const char *filename = "E:\\src\\c_pointer\\test.txt";
    const char *data = "Hello, World! \n";
    write_file(filename, data);
    char *read_data = read_file(filename);
    printf("Read data from file: %s\n", read_data);
    free(read_data);
    return 0;
}