/* 
Program summary: From the command line, this program will read a file that contains integers.  It will sort them
    and display the number of times that each number appears in the file.
 */


#include<stdio.h>
#include<stdlib.h>

int compare(const void *s, const void *t);      //function declaration//

int main(int argc, char *argv[]) /*argc is number of strings on cmd line, argv is array of pointers to char*/

{
    if(argc != 2)   /*the filename on cmd line cannot be spaced, so 2 strings are required*/
    {
        printf("Usage: program_name filename\n");
        exit(1);
    }

    FILE *infile;
    infile=fopen(argv[1],"r");  /*open file*/
    if (!infile)    /* if infile is a null pointer...*/
    {

        printf("unable to open %s\n",argv[1]);  /*unsuccessful operation*/
        exit(1);

    }


    int store[1000];    /*max of 1000 ints can be sorted*/
    int p;
    for(p=0;p<1000;p++)
        store[p]=0;     /*just in case, intialize array to zero*/

   int i=0;
    do
    {
    fscanf(infile, "%d", &store[i]);   /* read from infile into int variable in */
    if (!feof(infile))           /* only process in if didn't reach end of file */
        {
            i++;
                    /* process in, the last int read, here */
        }
    } while (!feof(infile));


    fclose(infile);     /*don't need file anymore*/

    int copyStore[i];   /*used for copy*/
    int j;
    for(j=0;j<i;j++)
        copyStore[j]=store[j]; /*make a copy of first array, so that the excess elements are trimmed*/

    qsort(copyStore, i,sizeof(int),compare);    /*sorted least to greatest, compare is a function*/




    printf("Sorted with duplicates:\n");
    int y,z,theCount;
    for(y=0;y<i;y++)
    {
        theCount=0;     /*intial count is 0*/
            for(z=0;z<i;z++)    /*for the 1st array element, loop through the array to find a match*/
            {
                if (copyStore[y]==copyStore[z])
                       theCount++;  /*up the count, if there is a match*/
            }

        if(theCount>1)
        {
            printf("%d   (%d)\n",copyStore[y],theCount);
            y=y+(theCount-1); /*in this case, manually increment. The -1 cancels out the y++ increment in the 1st for loop*/

        }
        else    /*the count will always be 1 or greater.  If 1, print normally and let the loop increment*/
        {
            printf("%d   (%d)\n",copyStore[y],theCount);
        }

    }
}


int compare(const void *s, const void *t)
{
   return *(const int *)s - *(const int *)t;
}

