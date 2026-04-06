#include <stdio.h>
int main()
{
    int a[5];
    a[2]=3;   
    printf("");
    return 0;
}





int a=4;
    int* b=&a;
    printf("the number is = %i and the adress is %p",*b,b);

int main()
{
    int a[5]={2,3,4,5,6};
    
    printf("%p\n",a);
    printf("%p\n",(a+1));
    printf("%p\n",(a+2));
    printf("%p\n",(a+3));
    
    printf("%i\n",*a);
    printf("%i\n",*(a+1));
    printf("%i\n",*(a+2));
    printf("%i\n",*(a+3));
    
    int c = *(a+3) + *(a+4);
    
    printf("the sum is = %i ",c);
    return 0;
}