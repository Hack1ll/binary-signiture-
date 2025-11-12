#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "file.h"

//1. 파일 읽기 2. 매직넘버 찾기 3. 출력하기
int main(int argc, char *argv[]){
    if(argc<2){
        printf("write your binary name");
        return 1;
    }
    FILE *binary;

    binary=fopen(argv[1], "rb"); //바이너리 열기
    if(binary==NULL){
        printf("no file");
        return 1;
    }
    fseek(binary, 0, SEEK_END);// 파일 포인터를 파일의 끝으로 이동시킴
    long size=ftell(binary);// 파일 포인터의 현재위치를 얻음
    fseek(binary, 0, SEEK_SET); //파일 포인터를 파일의 처음으로 이동

    unsigned char *p=malloc(sizeof(unsigned char)*size);

    int success=fread(p, 1, size, binary);//파일 읽기
    if(success==0){
        printf("reading error");
        exit(1);
    }
    fclose(binary);

    const char *signiture=var(p);

    
    printf("%s", signiture);
    
    free(p);
    return 0;
}
