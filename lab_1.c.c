#include <stdio.h>

int main (void) {
    struct stud {
        char name[50];
        char usn[10];
        double phone;
    };

    struct stud s1;
    
    printf("Your details : \n");
    
    printf("Name : "); 
    scanf("%s", s1.name);

    printf("USN : "); 
    scanf("%s", s1.usn);

    printf("Phone : "); 
    scanf("%lf", &s1.phone);
    
    printf("%s %s %lf\n", s1.name, s1.usn, s1.phone);
}
