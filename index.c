
#include <stdio>
#include"registration.c"
#include"issuebooks.c"
#include"returnbooks.c"
#include"addbooks.c"

extern int registration ();
extern int issuebooks();
extern int returnbooks();
extern int addbooks();

void main() {
	int select ;
    do{
	printf("select ur choice\n");
	printf("press 1 for new registration of student\n");
	printf("press 2 for issue books\n");
	printf("pres 3 for returning books\n");
	printf("pres 4 for add new books\n");
	printf("pres 0 for exit program\n");
	scanf("%d",&select);
	switch(select)
    {
        case 1:
        registration ();
        printf("\n\n\n");
        break;

        case 2:
        issuebooks();
        printf("\n\n\n");
        break;

        case 3:
        returnbooks();
        printf("\n\n\n");
        break;

        case 4:
        addbooks();
        printf("\n\n\n");
        break;

        default:
            printf("pls enter valid option\n");
            break;     
        }
    }while(select!=0);  
       printf("you are exit from program\n");
        
}
