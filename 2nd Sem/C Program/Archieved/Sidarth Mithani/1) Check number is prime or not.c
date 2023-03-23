#include <stdio.h>
int main()
{
    // To check for the prime number
    int guess=0;
    printf("Enter the number: ");
    scanf("%d", guess);
    // Flag variable to check for prime
    int flag = 0;
    for (int i = 0; i < guess; i++)
    {
        if (guess % i == 0)
            flag++;
    }
    if (flag == 0)
        printf("The enterd number is prime");
    else
        printf("The enterd number is not prime");
    return 0;
}
