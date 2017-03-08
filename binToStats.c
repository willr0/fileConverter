//binToStats.c
//willroller

#include <stdio.h>
#include <string.h>
#define MAX 256

int binToStats(FILE* fi){
    int id, maxId=0, minId=999, l1, l2, maxLen=0, minLen=512;
    char maxF[MAX], maxL[MAX], minF[MAX], minL[MAX], fn[MAX], ln[MAX];
    float gpa, maxGpa=0.0, minGpa=4.0;
    unsigned char i;
    
    fseek(fi, 0, SEEK_END);
    long b = ftell(fi);
    rewind(fi);
    
    while(ftell(fi)!=b){
        fread(&i, sizeof(char), 1, fi);            //read first byte - l1
        l1=i;
        fread(&fn[0], sizeof(char), l1, fi);         //read first name, store in b
        fn[l1]='\0';
        fread(&i, sizeof(char), 1, fi);            //read next byte - l2
        l2=i;
        fread(&ln[0], sizeof(char), l2, fi);        //read last name, store in b
        ln[l2]='\0';
        if(l1+l2>maxLen){                           //test name against max/min
            strcpy(maxF, fn);
            strcpy(maxL, ln);
            maxLen=l1+l2;
        }
        if(l1+l2<minLen){
            strcpy(minF, fn);
            strcpy(minL, ln);
            minLen=l1+l2;
        }
        fread(&id, 4, 1, fi);                       //read next 4 bytes - id
        if(id>maxId){                               //test id against max/min
            maxId=id;
        }
        if(id<minId){
            minId=id;
        }
        fread(&gpa, 4, 1, fi);                      //read next 4 byte - gpa
        if(gpa>maxGpa){                             //test gpa against max/min
            maxGpa=gpa;
        }
        if(gpa<minGpa){
            minGpa=gpa;
        }
    }
    //print results
    printf("Student with longest name: %s %s\nStudent with shortest name: %s %s\nHighest ID: %i\nLowest ID: %i\nHighest GPA: %1.1f\nLowest GPA: %1.1f\n", maxF, maxL, minF, minL, maxId, minId, maxGpa, minGpa);
    fflush(stdout);
    return 0;
}
