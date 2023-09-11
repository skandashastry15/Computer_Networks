#include <stdio.h>

void encoding(char window[], char dataword[], char encodedDataword[], char divisor[], int len, int ds, int dw)
{
    int i, j = ds - 1, k;
    for (i = 0; i < ds; i++)
    {
        window[i] = dataword[i];
    }

    printf("\n");
    while (i < len + 1)
    {
        while (j >= 0)
        {
            if (window[j] == divisor[j])
            {
                window[j] = '0';
            }
            else
            {
                window[j] = '1';
            }
            j--;
        }
        j = ds - 1;
        if (i == len)
            break;
        while (window[0] == '0' && i < len)
        {
            for (k = 0; k < ds - 1; k++)
            {

                window[k] = window[k + 1];
            }
            window[ds - 1] = dataword[i];
            i++;
        }
    }
    for (int p = 0; p < ds; p++)
    {
        printf("%c", window[p]);
    }

    printf("\nThe encoded dataword is: ");
    j = 1;
    for (int i = dw; i < len; i++)
    {
        dataword[i] = window[j++];
    }
    for (int i = 0; i < len; i++)
    {
        printf("%c", dataword[i]);
        encodedDataword[i] = dataword[i];
    }
}

void decoding(char window[], char encodedDataword[], char divisor[], int len, int ds, int dw)
{
    int i, j = ds - 1, k;
    for (i = 0; i < ds; i++)
    {
        window[i] = encodedDataword[i];
    }

    while (i < len + 1)
    {
        while (j >= 0)
        {
            if (window[j] == divisor[j])
            {
                window[j] = '0';
            }
            else
            {
                window[j] = '1';
            }
            j--;
        }
        j = ds - 1;
        if (i == len)
            break;
        while (window[0] == '0' && i < len)
        {
            for (k = 0; k < ds - 1; k++)
            {
                window[k] = window[k + 1];
            }
            window[ds - 1] = encodedDataword[i];
            i++;
        }
    }
    for (int i = 0; i < ds; i++)
    {
        if (window[i] != '0')
        {
            printf("\nError!");
            return;
        }
    }
    printf("\nNo error\n");
}

int main()
{
    int dw, ds;

    printf("Enter the divisor length and elements\n");
    scanf("%d", &ds);
    char divisor[ds];
    for (int i = 0; i < ds; i++)
    {
        scanf("%s", &divisor[i]);
    }

    printf("Enter the dataword length and elements\n");
    scanf("%d", &dw);
    int len = dw + ds - 1;
    char dataword[len], encodedDataword[len];

    for (int i = 0; i < len; i++)
    {
        if (i < dw)
            scanf("%s", &dataword[i]);
        else
            dataword[i] = '0';
    }

    char window[ds];
    encoding(window, dataword, encodedDataword, divisor, len, ds, dw);
    decoding(window, encodedDataword, divisor, len, ds, dw);
}
