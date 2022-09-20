#include <stdio.h>

struct File{
    int id;
    char name[64];
    int size;
    char data[1024];

    char full_path[4096];
};

struct Directory{
    struct File *files[256];
    struct Directory *directories[8];
    int nf;
    int nd;
    char path[2048];
};

void add_to_file(struct File* file, const char* str);

void append_to_file(struct File* file, const char* str);

void pwd_file(struct File* file);

void add_file(struct File* file, struct Directory* dir);

void add_directory(struct Directory* dir1, struct Directory* dir2);

int main()
{
    struct Directory root = {.nf=0, .nd = 0, .path = "/"};
    struct Directory home = {.nf=0, .nd = 0, .path = "/home"};
    struct Directory bin = {.nf=0, .nd = 0, .path = "/bin"};
    add_directory(&root,&home);
    add_directory(&root,&bin);

    struct File bash = {.full_path="/bin/bash", .name="bash", .id = 0};
    add_file(&bash, &bin);

    struct File ex3_1 = {.full_path="/home/ex3_1.c", .name="ex3_1.c", .id = 1};
    add_to_file(&ex3_1,"int printf(const char * format, ...);");
    struct File ex3_2 = {.full_path="/home/ex3_2.c", .name="ex3_2.c", .id = 2};
    add_to_file(&ex3_2,"\\//This is a comment in C language");
    add_file(&ex3_1, &home);
    add_file(&ex3_2, &home);

    add_to_file(&bash, "Bourne Again Shell!!");
    append_to_file(&ex3_1, "int main(){fprintf(\"Hello World!\")}");

    pwd_file(&ex3_1);
    pwd_file(&ex3_2);
    pwd_file(&bash);
    return 0;
}

void add_to_file(struct File* file, const char* str){
    int index = 0;
    while (*(str+index)!='\0' && index!=1024){
        file->data[index] = *(str+index);
        index++;
    }

    if (index==1024) {
        file->size = index-1;
        file->data[index - 1] = '\0';
    }
    else {
        file->size = index;
        file->data[index] = '\0';
    }
}

void append_to_file(struct File* file, const char* str){
    int index1 = 0;
    int index2 = file->size;
    while (*(str+index1)!='\0' && index2!=1024){
        file->data[index2] = *(str+index1);
        index1++;
        index2++;
    }

    if (index2==1024) {
        file->size = index2-1;
        file->data[index2 - 1] = '\0';
    }
    else {
        file->size += index1;
        file->data[index2] = '\0';
    }
}

void pwd_file(struct File* file){
    printf("%s\n", file->full_path);
}

void add_file(struct File* file, struct Directory* dir){
    if (dir->nf != 256){
        dir->files[dir->nf++] = file;
    }
}

void add_directory(struct Directory* dir1, struct Directory* dir2){
    if (dir1->nd != 8){
        dir1->directories[dir1->nd++] = dir2;
    }
}