#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * question1
 *
 * COMP 2160 SECTION A02
 * ASSIGNMENT    Assignment 2, question 1
 * AUTHOR        Nghia Dang, 7863117
 * DATE          30/10/2021
 *
 * PURPOSE: a program that prints process 3 file and do user input
 */

//constants of max length of string
#define MAX_INPUT 80
// constatnts of max that sperate string
const char SEPARATOR[] = ",\n";

/**
 * struct province
 * 
 *  PARAMETERS:
 *      - prov name
 *      - prov code
 *    
 */
typedef struct data1
{
    // name of province
    char prov_name[MAX_INPUT];
    char prov[MAX_INPUT];
} province;

/**
 * struct incomefile
 * 
 *  PARAMETERS:
 *      - prov name
 *      - int year
 *      -  int income
 *      - int IND
 *    
 */
typedef struct data2
{
    char prov[MAX_INPUT];
    int year;
    int income;
    int IND;
} incomefile;

/**
 * struct Codename
 * 
 *  PARAMETERS:
 *      - prov name
 *      - Int IND 
 *    
 */

typedef struct data3
{
    int IND;
    char prov[MAX_INPUT];
} Codename;

/**
 * struct finaldata
 * 
 *  PARAMETERS:
 *      this will be the final data that will be printed
 */

typedef struct data4
{
    char prov_name[MAX_INPUT];
    char prov[MAX_INPUT];
    int year;
    int income;
    int IND;
    char IND_name[MAX_INPUT];

} finaldata;

/////////////////////////////////// end of all struct function /////////////////////////////////////////////////

/**
 * start_with function
 * PURPOSE: check if the string start with the given string
 * INPUT PARAMETERS:
 * the string that will be checked
 * the string that will be checked with   
 * 
 * OUTPUT PARAMETERS:
 *  boolean value found it or not
 */

int start_with(const char *str, const char *prefix)
{
    return strncmp(str, prefix, strlen(prefix)) == 0;
}

/////////////////////////////////// end of strat_with function /////////////////////////////////////////////////

/**
 * compareFinal function
 * PURPOSE: sort the data final data
 * INPUT PARAMETERS:
 * the data that will be sorted
 * by the year
 * by prov name
 * by ind code
 * 
 * OUTPUT PARAMETERS:
 *  positon of the data
 */
int compareFinal(const void *s1, const void *s2)
{
    finaldata *e1 = (finaldata *)s1;
    finaldata *e2 = (finaldata *)s2;

    int compare_Prov = strcmp(e1->prov_name, e2->prov_name);
    int compare_Ind_name = strcmp(e1->IND_name, e2->IND_name);
    int compare_year = e1->year - e2->year;
    if (compare_year != 0)
        return compare_year;

    else
    {

        if (compare_Prov != 0)
            return compare_Prov;
        else
        {

            return compare_Ind_name;
        }
    }
}
/////////////////////////////////// end of compareFinal function /////////////////////////////////////////////////

/**
 * compareBYName function
 * PURPOSE: sort the data final data
 * INPUT PARAMETERS:
 * the data that will be sorted
 * by prov name
 * by year
 * by ind code
 * 
 * OUTPUT PARAMETERS:
 *  positon of the data
 */
int compareBYName(const void *s1, const void *s2)
{
    finaldata *e1 = (finaldata *)s1;
    finaldata *e2 = (finaldata *)s2;

    int compare_Prov = strcmp(e1->prov_name, e2->prov_name);
    int compare_Ind_name = strcmp(e1->IND_name, e2->IND_name);
    int compare_year = e1->year - e2->year;
    if (compare_Prov != 0)
        return compare_Prov;

    else
    {
        if (compare_year != 0)
            return compare_year;

        else
        {

            return compare_Ind_name;
        }
    }
}

/////////////////////////////////// end of compareBYName function /////////////////////////////////////////////////

/**
 * compareProv function
 * PURPOSE: sort the data final data
 * INPUT PARAMETERS:
 * the data that will be sorted
 * by prov name
 * by year
 *
 * 
 * OUTPUT PARAMETERS:
 *  positon of the data
 */
int compareProv(const void *s1, const void *s2)
{
    finaldata *e1 = (finaldata *)s1;
    finaldata *e2 = (finaldata *)s2;
    int compare_Prov = strcmp(e1->prov_name, e2->prov_name);
    int compare_year = e1->year - e2->year;
    if (compare_Prov != 0)
    {
        return compare_Prov;
    }
    else
    {

        return compare_year;
    }
}

/////////////////////////////////// end of compareBYName function /////////////////////////////////////////////////

/**
 * returnProv function
 * PURPOSE: find the prov name in the province data
 * INPUT PARAMETERS:
 *   char to find , data , array length 
 * OUTPUT PARAMETERS:
 *   return that prov name
 */

char *returnProv(char *toFind, province *data, int datalenth)

{

    for (int i = 0; i < datalenth; i++)
    {
        if (strcmp(toFind, data[i].prov) == 0)
        {
            return (char *)data[i].prov_name;
        }
    }

    return "";
}

/////////////////////////////////// end of returnProv function /////////////////////////////////////////////////

/**
 * FIND_Comand function
 * PURPOSE: procesing the FIND command
 * INPUT PARAMETERS:
 *   prov name , data , array length 
 * OUTPUT PARAMETERS:
 *   nonce
 */

void FIND_Comand(char *prov, int year, char *IND_name, finaldata *data, int datalength)

{
    printf("FIND command\n");
    // first find the position of the prov name and  teh year we want
    int pos = -1;
    for (int i = 0; i < datalength; i++)
    {
        if (start_with(data[i].prov_name, prov) && year == data[i].year && start_with(data[i].IND_name, IND_name))
        {

            pos = i;
            break;
        }
    }
    // orther wise the pos is not avaliable
    if (pos != -1)
        while (pos < datalength &&
               (start_with(data[pos].prov_name, prov) && year == data[pos].year && start_with(data[pos].IND_name, IND_name)))

        {
            // if the current pos is the same as the pos we want
            // then print it out
            printf("%s %d\n", data[pos].IND_name, data[pos].income);
            pos++;
        }
    else
        printf("No data found\n");

    printf("\n");
}

////////////////////////////////////////////////////// end of FIND_Comand function /////////////////////////////////////////////////

/**
 * Sum_by_Year function
 * PURPOSE: sum all the year in the prov
 * 
 * INPUT PARAMETERS:
 *  province to find , data , array length 
 * OUTPUT PARAMETERS:
 *   nonce
 */

void Sum_by_Year(char *prov, finaldata *data, int datalength)
{
    printf("\nSUM BY YEAR\n");
    // furst we find the position we first see the provname
    int pos = -1;
    for (int i = 0; i < datalength; i++)
    {
        if (start_with(data[i].prov_name, prov))
        {

            pos = i;
            break;
        }
    }

    // check if the positon is valid or not
    if (pos != -1)
    {
        // and we used the double while loop to find all the data that we need
        while (pos < datalength && start_with(data[pos].prov_name, prov))
        {
            // first check if the current data is the same with theprov we want
            int current_year = data[pos].year;
            int sum = 0;
            while (pos < datalength &&
                   start_with(data[pos].prov_name, prov) && data[pos].year == current_year)

            {
                // after that we need to sum all the data that have the same year
                sum = sum + data[pos].income;
                pos++;
            }
            // after we done with one prov and we print the result
            printf("%d : %d\n", current_year, sum);
        }
    }
    else
        printf("No data found\n");
}

////////////////////////////////////////////////////// end of Sum_by_Year function /////////////////////////////////////////////////
/*
 * Sum_by_Prov function
 * PURPOSE: sum all the IND in the yaer of all province
 * 
 * INPUT PARAMETERS:
 *  IND to find, the year , data , array length
 * OUTPUT PARAMETERS:
 *   nonce
 */

void sum_by_prov(char *Ind_name, int year, finaldata *data, int datalength)
{
    // so the data we passing now is already sorted by year
    // so we just need to find the first year that we want to sum
    int pos = -1;
    for (int i = 0; i < datalength; i++)
    {
        if (year == data[i].year)
        {

            pos = i;
            break;
        }
    }
    // if the pos still -1 that mead the pasing year is not good
    // then we let the user know that
    if (pos != -1)
    {
        printf("\nSUM BY PROVINCE\n");

        while (pos < datalength && year == data[pos].year)
        {
            // then we go over all the data that we have and find the IND that we want to sum
            if (start_with(data[pos].IND_name, Ind_name))
            {
                // one thing we need to chcek is that if the current data is has the same provnice or not and also the IND stat with what we want
                char *current_prov = data[pos].prov_name;
                int sum = 0;
                while (pos < datalength && start_with(data[pos].IND_name, Ind_name) && strcmp(current_prov, data[pos].prov_name) == 0)
                {
                    // if that is what we want then sum it by the income
                    sum = sum + data[pos].income;
                    pos++;
                }
                // print out the result
                printf("%s : %d\n", current_prov, sum);
            }
            else
                // orther wise we still need to move on because data may still have after the current data
                pos++;
        }
    }
    else
        printf("No data found\n");
}

////////////////////////////////////////////////////// end of Sum_by_Prov function /////////////////////////////////////////////////

/*
 * returnIND function
 * PURPOSE: find the IND name in the IND data
 * 
 * INPUT PARAMETERS:
 *  IND to find, num to find , data , array length
 * OUTPUT PARAMETERS:
 *   nonce
 */

void returnIND(char *result, int toFind, Codename *data, int datalenth)
{

    for (int i = 0; i < datalenth; i++)
    {
        if (toFind == data[i].IND)
        {
            strcpy(result, data[i].prov);
            break;
        }
    }
}
////////////////////////////////////////////////////// end of returnIND function /////////////////////////////////////////////////

/*
 * count_line function
 * PURPOSE: count total line in the file
 * 
 * INPUT PARAMETERS:
the file to read 

 * OUTPUT PARAMETERS:
 *   num line
 */

int count_line(FILE *filename)
{
    int count = 0;
    char ch[MAX_INPUT];
    while (NULL != fgets(ch, MAX_INPUT, filename))
    {
        if (strstr(ch, ","))
            count++;
    }
    fclose(filename);
    return count;
}
////////////////////////////////////////////////////// end of count_line function /////////////////////////////////////////////////
/*
 * read_file_province function
 * PURPOSE: read the file and store the data in the array of that data
 * 
 * INPUT PARAMETERS:
*  the file to read , the array length

 * OUTPUT PARAMETERS:
 *   the province data
 */
province *read_file_province(char *filename, int datalenth)
{
    FILE *file = fopen(filename, "r");

    province *data = (province *)malloc(sizeof(province) * datalenth);
    char line[MAX_INPUT];
    int i = 0;

    char *token;
    token = fgets(line, MAX_INPUT, file);
    // this will come in style
    // prov name ,prov code
    while (NULL != fgets(line, MAX_INPUT, file))
    {
        token = strtok(line, SEPARATOR);

        strncpy(data[i].prov_name, token, MAX_INPUT);
        token = strtok(NULL, SEPARATOR);
        strncpy(data[i].prov, token, MAX_INPUT);

        line[0] = '\0';

        i++;
    }

    // return data;
    fclose(file);
    return data;
}
////////////////////////////////////////////////////// end of read_file_province function /////////////////////////////////////////////////

/*
 * read_file_income function
 * PURPOSE: read the file and store the data in the array of that data
 * 
 * INPUT PARAMETERS:
 * the file to read , the array length

 * OUTPUT PARAMETERS:
 *   the inceome data
 */
incomefile *read_file_income(char *naem, int datalength)
{

    // read the file by the name of naem
    FILE *file = fopen(naem, "r");
    incomefile *data = (incomefile *)malloc(sizeof(incomefile) * datalength);
    char ch[MAX_INPUT];
    int i = 0;
    char *token;
    token = fgets(ch, MAX_INPUT, file);

    // the data will come in
    // the prov code,  the year, the income , the IND code
    while (NULL != fgets(ch, MAX_INPUT, file))
    {

        // sedarch by go through each of the ","

        token = strtok(ch, SEPARATOR);
        strcpy(data[i].prov, token);
        token = strtok(NULL, SEPARATOR);
        data[i].year = atoi(token);
        token = strtok(NULL, SEPARATOR);
        data[i].income = atoi(token);
        token = strtok(NULL, SEPARATOR);
        data[i].IND = atoi(token);
        i++;
    }
    // return the data back
    fclose(file);
    return data;
}
////////////////////////////////////////////////////// end of read_file_income function /////////////////////////////////////////////////

/*
 * read_file_Codename function
 * PURPOSE: read the file and store the data in the array of that data
 * 
 * INPUT PARAMETERS:
 * the file to read , the array length2
 * 

 * OUTPUT PARAMETERS:
 *  the Codename data
 */

Codename *read_file_Codename(char *name, int datalength)
{
    // read the file by the char name
    FILE *file = fopen(name, "r");
    Codename *data = (Codename *)malloc(sizeof(Codename) * datalength);
    // set the size for the array

    char ch[MAX_INPUT];
    int i = 0;
    char *token;
    token = fgets(ch, MAX_INPUT, file); // we dont need the first line in the data
    // the data will come in style
    // IND number , and the name of the IND
    while (NULL != fgets(ch, MAX_INPUT, file))
    { // so we just need to find the "," to process the data
        char *token = strtok(ch, ",");
        data[i].IND = atoi(token);
        token = strtok(NULL, ",");
        strcpy(data[i].prov, token);
        i++;
    }
    // and return back the data
    fclose(file);
    return data;
}

////////////////////////////////////////////////////// end of read_file_Codename function /////////////////////////////////////////////////

/*
 * process_the data function
 * PURPOSE: this will read all the struct data and do the command user
 * 
 * INPUT PARAMETERS:
 * the command to do , the data to do , the data length

 * OUTPUT PARAMETERS:
 * nonce  
 *  */

void process_data(province *datafile1, incomefile *datafile2, Codename *datafile3, finaldata *lastData, int longestdafile)
{

    // the ideal for this function is chekc the user input
    // if the user input contain
    char *containFind = "FIND";
    // FIND then we process the FIND command
    char *conatinByyear = "BY Year";
    // if it contain BY year then we process the BY year command
    char *conatinByProv = "BY Province";
    // if it contain BY Province then we process the BY Province command

    char User[MAX_INPUT]; // the user input
    // this will tokenize the user input into smaller part
    char *token1;
    char *token2;

    // loop for the user input
    while (fgets(User, MAX_INPUT, stdin) != NULL)
    {
        if (strstr(User, containFind))
        { // if the user input contain FIND
            // we will need 3 thing to process
            // the province name , the year and the IND name

            // the char string
            char *prov;

            int year = -1;
            // number of year
            char *ind;
            // the ind to find
            token1 = strtok(User, " ");
            // first token will find the first " "
            token1 = strtok(NULL, "\n");

            //then we make the string from it to the end of the string
            token2 = strtok(token1, ",");
            // find the first ","
            // that will be the province name
            if (token2 == NULL || token1 == NULL)
            {
                printf("Error In Command\n");
                continue;
            }
            prov = token2;
            token2 = strtok(NULL, ",");
            // the 2nd token will be the year
            if (token2 == NULL)
            {
                printf("Error In Command\n");
                continue;
            }
            year = atoi(token2);
            token2 = strtok(NULL, ",");

            // the 3rd token will be the ind
            if (token2 == NULL)
            {
                printf("Error In Command\n");
                continue;
            }
            ind = token2;

            // first I want to sort the data so it easy for me to find the data
            qsort(lastData, longestdafile, sizeof(finaldata), compareBYName);
            // after that process the data
            FIND_Comand(prov, year, ind, lastData, longestdafile);
        }
        else if (strstr(User, conatinByyear))
        {

            // if the user input contain BY year
            token1 = strtok(User, " ");
            // first token will find the first " "
            char *prov1 = strtok(NULL, " BY");
            if (token1 == NULL || prov1 == NULL)
            {
                printf("Error In Command\n");
                continue;
            }
            // this will find the province name

            // sort the data in the way we want
            qsort(lastData, longestdafile, sizeof(finaldata), compareProv);
            // process the SUM
            Sum_by_Year(prov1, lastData, longestdafile);
        }
        else if (strstr(User, conatinByProv))
        {

            // if the user input contain BY Province
            char copy[MAX_INPUT];
            strcpy(copy, User);

            token1 = strtok(User, " ");
            // first token will find the first " "
            char *IND = strtok(NULL, " IN");
            // this will be the IND
            token2 = strtok(copy, "IN");

            // this will be the year
            int year = atoi(strtok(NULL, " IN"));
            if (token1 == NULL || IND == NULL || token2 == NULL)
            {
                printf("Error In Command\n");
                continue;
            }

            // sort the data in the way we want
            qsort(lastData, longestdafile, sizeof(finaldata), compareFinal);
            // procerss the SUM BY Province
            sum_by_prov(IND, year, lastData, longestdafile);
        }
        else
        {
            printf("Error In Command\n");
        }
    }

    // and rember to free alll the file
    free(lastData);
    free(datafile2);
    free(datafile3);
    free(datafile1);
}

////////////////////////////////////////////////////// end of process_the data function /////////////////////////////////////////////////

/*
 * main() function
 * 
 */

int main()
{

    /// all the paremeert we need
    FILE *input1, *input2, *input3;
    char filename1[MAX_INPUT];
    char filename2[MAX_INPUT];
    char filename3[MAX_INPUT];
    char line1[MAX_INPUT], line2[MAX_INPUT], line3[MAX_INPUT];
    char *result1, *result2, *result3;
    /// this contain all the thing to process the input data
    ////////////////////////////////////////////
    int coun1 = 0; // the number of line in the file
    int coun2 = 0;
    int coun3 = 0;

    // this will check the file is good or not
    int check_file_name1 = 0;
    int check_file_name2 = 0;
    int check_file_name3 = 0;

    // *** open the files
    // use the same in lab 2

    /// read the input file
    printf("Please enter the first filename (The province file): ");
    fgets(filename1, MAX_INPUT, stdin);
    filename1[strlen(filename1) - 1] = '\0';
    input1 = fopen(filename1, "r");
    // the reason I need to checl the file is beacuase I dont want the file crash at the first
    if (strstr(filename1, "province"))
    {
        check_file_name1 = 1;
    }
    printf("Please enter the second filename  (The income file): ");
    fgets(filename2, MAX_INPUT, stdin);
    filename2[strlen(filename2) - 1] = '\0';
    input2 = fopen(filename2, "r");
    if (strstr(filename2, "income"))
    {
        check_file_name2 = 1;
    }

    printf("Please enter the second filename (The industry file): ");
    fgets(filename3, MAX_INPUT, stdin);
    filename3[strlen(filename3) - 1] = '\0';
    input3 = fopen(filename3, "r");

    if (strstr(filename3, "industry"))
    {
        check_file_name3 = 1;
    }

    if (NULL == input1 || NULL == input2 || NULL == input3)
    { //// if the file is not good
        // print the error message
        fprintf(stderr, "Unable to open an input file.\n");
    }
    else
    {
        if (check_file_name1 == 1 && check_file_name2 == 1 && check_file_name3 == 1)
        {

            /// ortherwise we need to read the if it in the order we want
            // count the number of line in the file
            coun1 = count_line(input1);
            coun2 = count_line(input2);
            coun3 = count_line(input3);
            // read the file and store the data in the array
            province *datafile1 = read_file_province(filename1, coun1);
            ;

            // this is for checking data only
            // for (int i = 0; i < coun1; i++)
            // {
            //     printf("%s %s\n", datafile1[i].prov_name, datafile1[i].prov);
            // }

            incomefile *datafile2 = read_file_income(filename2, coun2);
            ;

            // this is for checking data only

            // for (int i = 0; i < coun2; i++)
            // {
            //     printf("%s %d %d %d\n", datafile2[i].prov, datafile2[i].year, datafile2[i].income, datafile2[i].IND);
            // }
            Codename *datafile3 = read_file_Codename(filename3, coun3);
            ;

            //this is for checking data only
            // for (int i = 0; i < coun3 ; i++)
            // {
            //     printf("%d %s", datafile3[i].IND, datafile3[i].prov);
            // }

            // this will join 3 of the file together and store in the array
            finaldata *lastData = malloc(sizeof(finaldata) * coun2);
            for (int i = 0; i < coun2; i++)
            {
                strcpy(lastData[i].prov_name, returnProv(datafile2[i].prov, datafile1, coun1));
                strcpy(lastData[i].prov, datafile2[i].prov);
                lastData[i].year = datafile2[i].year;
                lastData[i].income = datafile2[i].income;
                lastData[i].IND = datafile2[i].IND;

                char test[MAX_INPUT] = "\0";
                returnIND(test, lastData[i].IND, datafile3, coun3);
                test[strlen(test) - 1] = '\0';
                strcpy(lastData[i].IND_name, test);
                test[0] = '\0';
            }
            // this is for checking data only
            //    for (int i = 0; i < coun2; i++)
            // {
            //         printf("%s %s %d %d %d %s\n", lastData[i].prov_name, lastData[i].prov, lastData[i].year, lastData[i].income, lastData[i].IND, lastData[i].IND_name);
            //  }
            // after this we will process the data and the user command
            printf("Please enter the command: \n");
            process_data(datafile1, datafile2, datafile3, lastData, coun2);
        }
        else
        {
            // if the file is not in order make sure the user know it
            printf("Wrong in the file name input please enter it in order\n");
            return 0;
        }
    }
    return 0;
}

////////////////////////////////////////////////////// end of main function /////////////////////////////////////////////////
