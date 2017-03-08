//textToBin.c
//willroller

#include <stdio.h>
#include <string.h>
#define MAX 256

int textToBin(FILE *fi, FILE *fo){
    int id, ll, fl;
    float gpa;
    char inLine[512], fn[MAX], ln[MAX], l1, l2;
    
    while(fgets(inLine, 512, fi)){
        sscanf(inLine, "%s %s %d %11f", fn, ln, &id, &gpa);
        fl=strlen(fn);                                          //first name length
        ll=strlen(ln);                                          //last name length
        l1=fl;
        l2=ll;
        fwrite(&l1, sizeof(char), 1, fo);                       //write length to first byte
        fwrite(&fn[0], sizeof(char), fl, fo);                   //write name to next fl bytes
        fwrite(&l2, sizeof(char), 1, fo);                       //write length to next byte
        fwrite(&ln[0], sizeof(char), ll, fo);                   //write name to next ll bytes
        fwrite(&id, 4, 1, fo);                                  //write id to 4 bytes
        fwrite(&gpa, 4, 1, fo);                                 //write gpa to 4 bytes
    }
    return 0;
}
