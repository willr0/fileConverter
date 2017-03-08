//binToText.c
//willroller

#include <stdio.h>
#include <string.h>
#define MAX 256

int binToText(FILE *fi, FILE *fo){
    int length, id;
    float gpa;
    unsigned char l;
    char fn[MAX], ln[MAX];
    
    //find file size
    fseek(fi,0,SEEK_END);
    long b=ftell(fi);
    rewind(fi);
    
    //loop until end of file
    while(ftell(fi)!=b){
        fread(&l, sizeof(char), 1, fi);                         //read first byte for length of first name
        length=l;                                               //store length
        fread(&fn[0], sizeof(char), length, fi);                //read name from length bytes
        fn[length]='\0';                                        //terminate string
        fread(&l, sizeof(char), 1, fi);                         //read next byte for length of last name
        length=l;                                               //store length
        fread(&ln[0], sizeof(char), length, fi);                //read name from length bytes
        ln[length]='\0';                                        //terminate string
        fread(&id, 4, 1, fi);                                   //read id from next 4 bytes
        fread(&gpa, 4, 1, fi);                                  //read gpa from next 4 bytes
        fprintf(fo, "%s %s %i %1.1f\n", fn, ln, id, gpa);       //print data
    }
    return 0;
}
