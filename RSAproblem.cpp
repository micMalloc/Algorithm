#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int cnt, bi[100];

int GCD(int num1, int num2)
{
    int i, gcd = 1;
    for (i = 2; i <= (num1 > num2 ? num2 : num1); i++)
        if (num1%i == 0 && num2%i == 0)
            gcd = i;
    
    return gcd;
}

void reapeatSquar(int a)
{
    cnt = 0;
    while (a > 0)
    {
        bi[cnt++] = a % 2;
        a = a / 2;
    }
}

int ModExp(int a, int b, int n)
{
    int c = 0, d = 1;
    int x;
    
    reapeatSquar(b);
    for (x = cnt - 1; x >= 0; x--)
    {
        c *= 2;
        d = (d*d) % n;
        if (bi[x] == 1)
        {
            c += 1;
            d = (d*a) % n;
        }
    }
    return d;
}

int mulmod(int a, int b, int mod)
{
    int x = 0, y = a % mod;
    while (b > 0)
    {
        if (b % 2 == 1)
        {
            x = (x + y) % mod;
        }
        y = (y * 2) % mod;
        b /= 2;
    }
    return x % mod;
}

int modulo(int base, int exponent, int mod)
{
    int x = 1;
    int y = base;
    while (exponent > 0)
    {
        if (exponent % 2 == 1)
            x = (x * y) % mod;
        y = (y * y) % mod;
        exponent = exponent / 2;
    }
    return x % mod;
}

int millerRabin(int p, int iteration)
{
    int i;
    int s, a;
    int arr[7] = { 561, 1105, 1729, 2465, 2821, 6601, 9811 };
    if (p < 2)
    {
        return 0;
    }
    if (p != 2 && p % 2 == 0)
    {
        return 0;
    }
    s = p - 1;
    while (s % 2 == 0)
    {
        s /= 2;
    }
    for (i = 0; i < iteration; i++)
    {
        int a = rand() % (p - 1) + 1, temp = s;
        int mod = modulo(a, temp, p);
        while (temp != p - 1 && mod != 1 && mod != p - 1)
        {
            mod = mulmod(mod, mod, p);
            temp *= 2;
        }
        if (mod != p - 1 && temp % 2 == 0)
        {
            for (a = 0; a < 7; a++)
            {
                if (p == arr[a])
                    return -1;
            }
            return 0;
        }
    }
    return 1;
}

int compute_e(int k)
{
    int a = 3;
    while (1)
    {
        if (GCD(a, k) == 1 && a % 2 == 1)
            return a;
        ++a;
    }
    return -1;
}

int compute_d(int e, int k){
    
    int a = 1;
    while (1)
    {
        if (((a*k) + 1) % e == 0 && ((a*k) + 1) / e < k)
            return ((a*k) + 1) / e;
        ++a;
    }
    return -1;
}

int main(){
    
    int p, q, n, e, d;
    int ps, cy;
    
    printf("Enter message : ");
    scanf("%d", &ps);
    printf("Enter P and Q : ");
    scanf("%d %d", &p, &q);
    
    n = p * q;
    printf("n = %d\n", n);
    
    e = compute_e((p - 1)*(q - 1));
    printf("Public key (e = %d, n = %d)\n", e, n);
    
    d = compute_d(e, (p - 1)*(q - 1));
    printf("Secret key (d = %d, n = %d)\n", d, n);
    
    cy = ModExp(ps, e, n);
    printf("Cipher text : %d\n", cy);
    printf("Decrypt cipher text : %d\n", ModExp(cy, d, n));
    
    return 0;
}

