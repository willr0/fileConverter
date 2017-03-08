//main.c
//willroller

#include <stdio.h>
#include <string.h>
#include "prototypes.h"


int main(int argc, const char * argv[]) {
    FILE *fi, *fo;
    
    //error check
    if(argc!=4){
        //statistics -s flag
        if(strcmp(argv[1],"-s")==0){
            if((fi=fopen(argv[2],"rb"))==NULL){
                fprintf(stderr,"ERROR opening input file\n");
                return 0;
            }
            binToStats(fi);
        }
        else{
            printf("ERROR Required flag: -t -b -s\n");
            return 0;
        }
    }
    //text to binary -t flag
    else if(strcmp(argv[1],"-t")==0){
        //check files
        if((fi=fopen(argv[2],"r"))==NULL){
            fprintf(stderr,"ERROR opening input file\n");
            return 0;
        }
        if((fo=fopen(argv[3],"wb"))==NULL){
            fprintf(stderr,"ERROR opening output file\n");
            return 0;
        }
        textToBin(fi, fo);
    }
    //binary to text -b flag
    else if(strcmp(argv[1],"-b")==0){
        if((fi=fopen(argv[2],"rb"))==NULL){
            fprintf(stderr,"ERROR opening input file\n");
            return 0;
        }
        if((fo=fopen(argv[3],"w"))==NULL){
            fprintf(stderr,"ERROR opening output file\n");
            return 0;
        }
        binToText(fi, fo);
    }
    else{
        printf("ERROR Required flag: -t -b -s\n");
        return 0;
    }
    fclose(fi);                                         //close fi
    fclose(fo);                                         //close fo
    return 0;
}
