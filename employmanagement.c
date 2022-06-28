#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ARRAY_SIZE 2
#define NAME_SIZE 10
struct Employee
{
    int id;
    char name[NAME_SIZE];
    float salary;
};
int main()
{
    struct Employee emp[ARRAY_SIZE];
    int index = 0;;
    for(index = 0; index < ARRAY_SIZE; ++index )
    {
        printf("\nEnter details of Employee %d\n", index+1);
        printf("Enter id number: ");
        scanf("%d", &emp[index].id);
        fflush(stdin);
        printf("Enter Emp name: ");
        if(fgets(emp[index].name,NAME_SIZE,stdin) == NULL)
        {
            printf("Error in reading the string\n");
            exit(1);
        }
        else
        {
            char *p = strchr(emp[index].name, '\n');
            if (p)
            {
                *p = '\0';
            }
        }
        printf("Enter Emp Salary: ");
        scanf("%f", &emp[index].salary);
    }
    printf("\n\n");
    printf("Emp Name\tId\tSalary\n");
    for(index = 0; index < ARRAY_SIZE; ++index )
    {
        printf("%s\t%d\t%.2f\n",
               emp[index].name, emp[index].id, emp[index].salary);
    }
    return 0;
}
