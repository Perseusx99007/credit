#include <stdio.h>

int count(long long int c);

int calculate(long long int c);

int first2Numbers(long long c);

int firstNumber(long long c);

int main(void)
{
    long long int n;
    int a = 0;
    printf("Enter Credit Card number :- ");
    scanf("%lld", &n);

    // printf("%d\n", count(n));
    // printf("%d\n", calculate(n));
    // printf("%d\n", first2Numbers(n));
    // printf("%d\n", firstNumber(n));

    if(count(n) >= 13 && count(n) <= 16 && calculate(n) % 10 == 0)
    {
        if((first2Numbers(n) == 81 || first2Numbers(n) == 82 || firstNumber(n) == 6) && count(n) == 16)
        {
            printf("RuPay\n");
        }
        else
        if(first2Numbers(n) >= 51 && first2Numbers(n) <= 55  && count(n) == 16)
        {
            printf("Mastercard\n");
        }
        else
        if(first2Numbers(n) >= 34 && first2Numbers(n) <= 37  && count(n) == 15)
        {
            printf("American Express\n");
        }
        else
        if(firstNumber(n) == 4 && (count(n) == 13 || count(n) ==16))
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }

}

int count(long long int c)
{
    int n = 0;
    do
    {
        c = c / 10;
        n++;
    } while (c != 0);
    
    return n;
}

int calculate(long long int c)
{
    int a[30];
    int i = 0;
    int s = 0;
    int q = 0;
    int k = 0;
    int r = 0;
    int v = 0;

    while (c != 0)
    {
        r = c % 10;
        a[i] = r;
        if(i % 2 != 0)
        {
            v = 2 * a[i]; 

            if(v > 9)
            {
                v = v - 9;
                s = s + v;
            }
            else
            {
                s = s + v;
            }
        }
        else
        {
            q = q + a[i];
        }
        i++;
        c = c / 10;
    }
    k = s + q;
    // printf("%d\n", s);
    // printf("%d\n", q);
    // printf("%d\n", k);

    return k;
}

int first2Numbers(long long c)
{
    long long int s = c;

    while(s >= 100)
    {
        s = s / 10;
    }

    return s;
}

int firstNumber(long long c)
{
    long long int s = c;
    
    while(s >= 10)
    {
        s = s / 10;
    }

    return s;
}