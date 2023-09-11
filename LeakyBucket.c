#include <stdio.h>
#include <stdlib.h>
int main()
{
    int bucketSize, output, num, flag = 1, spaceRemaining;
    printf("Enter size of bucket and output\n");
    scanf("%d %d", &bucketSize, &output);
    spaceRemaining = bucketSize;
    while (flag)
    {
        num = rand() % 1000;
        if (num < spaceRemaining)
        {
            spaceRemaining -= num;
            printf("%d bytes accepted\n", num);
        }
        else
        {
            printf("%d bytes discarded\n", num);
        }

        if (bucketSize - spaceRemaining > output)
        {
            spaceRemaining += output;
            printf("%d bytes sent\n", output);
        }
        else
        {
            int x = bucketSize - spaceRemaining;
            spaceRemaining = bucketSize;
            printf("%d bytes sent\n", x);
        }
        printf("Space remaining %d\n", spaceRemaining);
        printf("If you want to continue sending press 1 or else 0\n");
        scanf("%d", &flag);
    }
    
    while (spaceRemaining < bucketSize)
    {
        if (bucketSize - spaceRemaining > output)
        {
            spaceRemaining += output;
            printf("%d bytes sent\n", output);
        }
        else
        {
            int x = bucketSize - spaceRemaining;
            spaceRemaining = bucketSize;
            printf("%d bytes sent\n", x);
        }
    }
    return 0;
}
