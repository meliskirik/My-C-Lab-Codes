#include <stdio.h>

int main()
{
    int i;
    char *cityNames[4] = {"istanbul", "newyork", "paris", "londra"};
      printf("The citiesin the list are: \n");

      for (i = 0; i < 4; i++){
        printf("%s \n", cityNames[i]);
      }
     printf("\n------------------------------ \n");

     printf("\nThe second city: %s \n", cityNames[1]);
     
     printf("\n------------------------------ \n");

     printf("\nThe last letter of the third city : %s \n", cityNames[2]+4);


    return 0;
}