#include<stdio.h>

int main()
{
    char ch,numch;
    int count;
    int k;
    printf("Enter a character: ");
    scanf("%c", &ch);
    printf("The entered character is:");
    while (ch  != 'q')// loop until 'q' is entered
    {
        if (ch>='0'&&ch<='9')
        {
            count = ch-'0';// convert character to number
            //scanf("%c", &numch);
            //for (k = 0; k < count; k++)//
            {
                printf("%d", count);// print character number
            }
        }
        else
        {
            printf("%c", ch); //  print character
        }
        printf("\nEnter a character: ");
        scanf("%c", &ch);// read character
    }
    printf("quit\n");
    return 0;

}