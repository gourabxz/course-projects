#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

main(){
    printf("Welcome to class routine application. \n Please avoid typing space while giving keyboard input.");
    char days[6][14] = {"saturday", "sunday", "monday", "tuesday", "thursday", "wednessday"};
   
    int count = 0; char *file;
    for (count=0; count<6; count++){
        if( access( days[count], F_OK ) != -1 ) {
            printf("\n\n %s class schedule: \n \n", days[count]);
            readData(days[count]);
            
        } 
    }
    count = 0;
    for (count=0; count<6; count++){
        if( access( days[count], F_OK ) == -1 ) {
            printf("\n\n\n %s class schedule not found.\n Do you want to add schedule for %s classes? (y/n)", days[count],  days[count]);
            char dici[100];
            scanf("%s", &dici);
            if((strcmp(dici, "y"))==0){
                writeData(days[count]);
            }
            else if((strcmp(dici, "n"))==0){
                continue;
            }
            else{
                printf("Please enter y or n to give command.");
            }
            
        } 
    }
}
writeData(char *dayName){
    printf("\nLets create class schedule data for %s \n", dayName);
   
    printf("How many classes you have on %s ? \n", dayName);
    
       int num_of_classes = 0;
       scanf("%d", &num_of_classes);
       
       int i =0; char className[200][200]; char time[200][200];
       for(i=0; i<num_of_classes; i++){
           printf("Enter the name of class number: %d \n", i+1);
           scanf("%s", &className[i]);
           
           printf("Enter the time of class number: %d \n", i+1);
           scanf("%s", &time[i]);
       }
        
        FILE *fp = fopen(("%s", dayName), "w");
        for(i=0; i<=num_of_classes; i++){
            strcat(className[i], " ");
            fprintf(fp, className[i]);
             
            strcat(time[i], " ");
            fprintf(fp, "%s", time[i]); 
        }
        fclose(fp);
        printf("\nSaved! %s class scedule will be shown next time you run the app.");
}
readData(char *dayName){
    FILE *fr;
    char str[1000];
    char* filename = dayName;
 
    fr = fopen(filename, "r");
    char text[1000];
    while (fgets(str, 1000, fr) != NULL)
        strcpy(text, str);
        
    fclose(fr);

    
    char *tok; int x = 0;
    for (tok = strtok(text, " "); tok != NULL; tok = strtok(NULL, " ")){
        x++;
        printf("%s", tok);
        if(x%2==0)
            printf("\n");
        else
            printf("---");
    }
}

