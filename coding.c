#include <string.h>
#include <stdlib.h>
#include <stdio.h>
//1. 파일 읽기 2. 매직넘버 찾기 3. 출력하기
int main(int argc, char *argv[]){
    
    FILE *binary;

    binary=fopen(argv[1], "rb"); //바이너리 열기
    if(binary==NULL){
        printf("no file");
        return 1;
    }
    fseek(binary, 0, SEEK_END);// 파일 포인터를 파일의 끝으로 이동시킴
    int size=ftell(binary);// 파일 포인터의 현재위치를 얻음
    fseek(binary, 0, SEEK_SET); //파일 포인터를 파일의 처음으로 이동

    unsigned char *p=malloc(sizeof(unsigned char)*size);

    int success=fread(p, 1, size, binary);//파일 읽기
    if(success==0){
        printf("reading error");
        exit(1);
    }
    char signiture[100];
    if(p[0]==0xff&&p[1]==0xd8&&p[2]==0xff&&p[3]==0xe0||p[0]==0xff&&p[1]==0xd8&&p[2]==0xff&&p[3]==0xe8)strcpy(signiture, "JPEG");

    if(p[0]==0x25&&p[1]==0x50&&p[2]==0x44&&p[3]==0x46&&p[4]==0x2d&&p[5]==0x31&&p[6]==0x2e)strcpy(signiture, "pdf");
    
    if(p[0]==0x50&&p[1]==0x4b&&p[2]==0x03&&p[3]==0x04){
        if(p[5]==0x00&&p[6]==0x06&&p[7]==0x00)strcpy(signiture, "docx");
        else{
            strcpy(signiture, "zip");
        }
    }
    
    printf("%s", signiture);
    return 0;
}