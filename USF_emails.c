/*
Name: Sumit Subhash Jadhav(U89612131)
This program iterates through user specified file to check for intended parameters of emails usf.edu segregating to another file.
*/
#include <stdio.h>
#include<string.h>    //Initializing libraries and defining macros
#define MAXIMUM_LENGTH 2000 //Length of email addresses is no more than 2000 characters
#define STRING_LENGTH 100   //The input file name wouldn't be more than 100 characters

//Defining function
int is_USF_email(char *email)
{
    char check_USF[]="usf.edu",*search_str;
    search_str = strstr(email,check_USF);

    if (search_str!=NULL)
    {
        return 1;   //Returns 1 if email address contains usf.edu
    }
    else
    {
        return 0;   //Returns 0 if email address does not contain usf.edu
    }
}

int main()
{
    char targetfile[STRING_LENGTH+1],OutputPrefix[]="USF_",str[MAXIMUM_LENGTH+1];
    // input from user,name of output file ,reading each string of target file
    FILE *readFile;  //pointer for to be read file
    FILE *writeFile;   //pointer for writing to new file, the desired data

    printf("Enter input file(Please enter along with file format): ");
    scanf("%s", targetfile);

    readFile=fopen(targetfile,"r");
    if(readFile==NULL)
    {
        printf("Error opening the input file");  //checking for null file
        return 1;
    }

    strcat(OutputPrefix,targetfile);
    printf("Output file is: %s", OutputPrefix);


    writeFile=fopen(OutputPrefix,"w");
    if(writeFile==NULL)
    {
        printf("Error opening the output file");   //won't give an empty file
        return 1;
    }


   while (fgets (str, MAXIMUM_LENGTH+1, readFile ) != NULL) //Reading data from target file line by line
    {
        if (is_USF_email(str)==1)
        {
            fprintf(writeFile,"%s",str);  //writing the segregated data in the new file
        }

    }


    fclose(readFile);   //Closes the target file
    fclose(writeFile);  //Closes the newly created file


    return 0;
}
