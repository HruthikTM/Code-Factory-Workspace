#include <stdio.h>

// int main()
// {
//     char c[2]="A";

//     printf("%c\n",c[0]);
//     printf("%s\n",c);

//     return 0;
// }


// int main()
// {
//     char s[]="Get organized";

//     printf("%s\n",&s[0]);
//     printf("%s\n",s);
//     printf("%s\n",&s);
//     printf("%c\n",s[2]);

//     return 0;
// }


// int main()
// {
//     char s[]="N0 two virus work similarly";

//     int i=0;
//     while(s[i]!=0)
//     {
//         printf("%c %c\n",s[i],*(s+i));
//         printf("%c %c\n",i[s],*(i+s));

//         i++;
//     }

//     return 0;
// }

int main()
{
    char  s[ ]="Churchgate: no church no gate";
    char  t[25];
    char  *ss, *tt;
    ss = s;
    while (*ss != '\0') {
        *ss++ = *tt++;
    }

    printf ("\n%s",t) ;

    return 0;

}
