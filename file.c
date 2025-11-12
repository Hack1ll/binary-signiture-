char var(unsigned char *p){
    char signiture[100];

    if(p[0]==0xff&&p[1]==0xd8&&p[2]==0xff&&p[3]==0xe0||p[0]==0xff&&p[1]==0xd8&&p[2]==0xff&&p[3]==0xe8)strcpy(signiture, "JPEG");
    if(p[0]==0x47&&p[1]==0x49&&p[2]==0x46&&p[3]==0x38&&p[5]==0x61){
           if(p[4]==0x37||p[4]==0x39)
        strcpy(signiture, "GIF");
    }
    if(p[0]==0x89&&p[1]==0x50&&p[2]==0x4e&&p[3]==0x47&&p[4]==0x0d&&p[5]==0x0a&&p[6]==0x1a&&p[7]==0x0a)strcpy(signiture, "png");
    if(p[0]==0x25&&p[1]==0x50&&p[2]==0x44&&p[3]==0x46&&p[4]==0x2d&&p[5]==0x31&&p[6]==0x2e)strcpy(signiture, "pdf");
    
    if(p[0]==0x50&&p[1]==0x4b&&p[2]==0x03&&p[3]==0x04){
        if(p[5]==0x00&&p[6]==0x06&&p[7]==0x00)strcpy(signiture, "docx");
        else{
            strcpy(signiture, "zip");
        }
    }
    
    if(p[0]==0x52&&p[1]==0x61&&p[2]==0x72&&p[3]==0x21&&p[4]==0x1a&&p[5]==0x07)strcpy(signiture, "rar");
return signiture;
}
