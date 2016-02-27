/* From the command line, convert base 10 integers to any number base from 2 to 36. */


#include<stdio.h>
#include<stdlib.h>


char *tobase(int, int );    //function prototype
int main(int argc, int *argv[]) //read cmd line arguments
{
    char *p;    //used to store returned pointer
	int value, base;
	if(argc==3) //correct number of arguments
    {
        value=atoi(argv[1]);    //convert them to ints
        base=atoi(argv[2]);     //argv[0]=name of file, argv[1]=value...
    }
    else if (argc==1)
    {
        printf("value -> ");	//prompt user (just typed the name of file)//
        scanf("%d",&value);
        printf("base -> ");
        scanf("%d",&base);
    }
    else
    {
        printf("Incorrect number of arguments");
        exit(1);    //unsuccessful operation
    }



	if(value<0)
    {
        printf("value must be non-negative");	//inform of usage//
        exit(1);
    }

	else if ((base<2)||(base>36))
    {
        printf("base must be between 2  and 36");
        exit(1);
    }

	p=tobase(value,base); //store the returned pointer
	int len=0;
	while(*(p+len)) //use the pointer to find the length of the array to print it
        len++;




    int i;
	for(i=0;i<len;i++)
        printf("%c",*(p +i));   //loop thru contents of what the array points to


    free(p);    //free the allocated memory the malloc

}
char *tobase(int value, int base)
{
	int digit;
	char numstring[34];
	numstring[33]='\0';	/*a string to store digit list*/
	int i = 32;
	while (value != 0)
	{
   	digit = value % base;   /* the next digit */
   	value = value / base ;  /* integer division: discard remainder */


   	if (digit < 10)
   numstring[i]= '0' + digit; 	/*get digit list from ASCII code, (0 - 9)*/
	if (digit >= 10)
   numstring[i]= 'a' + digit - 10;  /*ASCII , (a - z)*/
   	i--;
	}

    char *copy_string= (char *)malloc((33-i)*sizeof(char)); //malloc enough for the result
    int j=0;
	while(i != 34)
    {
          copy_string[j]=numstring[i+1]; /*copy string into an array of appropriate size, i+1 accounts for the last deincrement*/
          j++;
          i++;
    }


    copy_string[j+1]='\0';  //null terminate the array

    return copy_string; //return pointer
}
