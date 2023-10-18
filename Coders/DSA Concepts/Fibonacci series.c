#include <stdio.h>

int main()
{
    int num, num1 = 0, num2 = 1, nextTerm;

    printf("Enter a number: ");
    scanf("%d", &num);

    printf("Fibonacci Series: %d, %d, ", num1, num2);
    nextTerm = num1 + num2;

    while(nextTerm <= num)
    {
        printf("%d, ",nextTerm);
        num1 = num2;
        num2 = nextTerm;
        nextTerm = num1 + num2;
    }

    return 0;
}
