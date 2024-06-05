#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSTRINGSIZE 10
#define LINESIZE 128

struct person{
    char firstName[MAXSTRINGSIZE];
    char lastName[MAXSTRINGSIZE];
    char gender[MAXSTRINGSIZE];
    int birthYear;
    struct person *next;
} *first, *current;


int main (void){
    static const char filename[] = "barang.txt";
    FILE *myfile = fopen ( "barang.txt", "r" );

    int i=0;
    int j=0;
    int k=0;
    int l=0;
    char *result[10][4];
    char line[LINESIZE];
    char *value;

    for(i=0; i<9; i++){
        for(j=0;j<4;j++){
            result[i][j] = NULL;
        }
    }
    i=0;

    // loop through each entry in Assignment1file
    while(fgets(line, sizeof(line), myfile)){

        //load last name
        value = strtok(line, ",");
        result[i][0] = value;
        printf("%i 0 %s", i, value);


        //load first time
        value = strtok(NULL, ",");
        result[i][1] = value;
        printf("%i 1 %s", i, value);

        // load gender
        value = strtok(NULL, ",");
        result[i][2] = value;
        printf("%i 2 %s", i, value);

        // load birth year
        value = strtok(NULL, "\n");
        result[i][3] = value;
        printf("%i 3 %s", i, value);
        printf("\n");

        for(j=0;j<4;j++){
            printf("%s\n", result[i][j]);
        }


        //go to next line
        i++;
    }

    // read out the array
    for(k=0; k<5; k++){
        for(j=0;j<4;j++){
            printf("%s\n", result[k][j]);
        }
    }

    fclose(myfile);
    return 0;
}
