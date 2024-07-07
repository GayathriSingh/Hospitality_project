#include<stdio.h>
#include<stdlib.h>
struct node
{   
    char name[100];
    int age;
    char address[100];
    int phone;
    char bloodgroup[100];
    int reg;
    int priority;
    struct node *next;
};

struct node *start = NULL;
struct node *insert(struct node *);
struct node *delete(struct node *);
void display(struct node *);
void table();

int main()
{
    int option;
    do {
        printf("\n\n\n\n WELCOME TO SREE HOSPITAL!\n");
        printf("\n------------------------------\n");
        printf("1. ADD A PATIENT\n");
        printf("2. DELETE A RECORD\n");
        printf("3. DISPLAY ALL APPOINTMENTS BASED ON PRIORITY\n");
        printf("4. EXIT\n");
        printf("Enter your choice:");
        scanf("%d", &option);
        
        switch(option)
        {
            case 1:
                start = insert(start);
                getchar(); // to consume the newline character
                break;
            case 2:
                start = delete(start);
                getchar(); // to consume the newline character
                break;
            case 3:
                display(start);
                getchar(); // to consume the newline character
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("Invalid option! Please enter a valid option.\n");
                break;
        }
    } while(option != 4);
    
    return 0;
}

struct node *insert(struct node *start)
{
    struct node *ptr, *p;
    ptr = (struct node*)malloc(sizeof(struct node));
    
    printf("Enter patient Name: ");
    scanf(" %s", ptr->name);
    
    printf("Enter the patient's age: ");
    scanf("%d", &ptr->age);
    
    printf("Enter your home address: ");
    scanf(" %s", ptr->address);
    
    printf("Enter your phone number: ");
    scanf("%d", &ptr->phone);
    
    printf("Enter the blood group of Patient: ");
    scanf(" %s", ptr->bloodgroup);
    
    printf("Enter the reg no: ");
    scanf("%d", &ptr->reg);
    
    table(); // Display the table for disease selection
    
    printf("Enter your disease Number: ");
    scanf("%d", &ptr->priority);
    
    if(start == NULL || ptr->priority < start->priority)
    {
        ptr->next = start;
        start = ptr;
    }
    else
    {
        p = start;
        while(p->next != NULL && p->next->priority <= ptr->priority)
            p = p->next;
        
        ptr->next = p->next;
        p->next = ptr;
    }
    
    return start;
}

struct node *delete(struct node *start)
{
    struct node *ptr;
    if(start == NULL)
    {
        printf("\nNO PATIENT RECORD TO DELETE\n");
        return start;
    }
    else
    {
        ptr = start;
        printf("\nDeleted Record reg num is: %d\n", ptr->reg);
        start = start->next;
        free(ptr);
    }
    
    return start;
}

void display(struct node *start)
{
    struct node *ptr;
    ptr = start;
    
    if(start == NULL)
    {
        printf("\nTHERE IS NO PATIENT\n");
    }
    else
    {
        printf("\nPriority wise appointments are:\n");
        while(ptr != NULL)
        {
            printf("Name: %s\n", ptr->name);
            printf("Age: %d\n", ptr->age);
            printf("Address: %s\n", ptr->address);
            printf("Phone: %d\n", ptr->phone);
            printf("Blood Group: %s\n", ptr->bloodgroup);
            printf("Reg No: %d\n", ptr->reg);
            printf("Priority: %d\n", ptr->priority);
            printf("---------------------------------\n");
            ptr = ptr->next;
        }
    }
}

void table()
{
    printf("\nPlease Refer this Table for your disease!\n");
    printf("1. Heart attack\n");
    printf("2. Severe wound/Bleeding\n");
    printf("3. Cancer\n");
    printf("4. Chest pain\n");
    printf("5. Fracture\n");
    printf("6. Diabetes Checkup\n");
    printf("7. Infection\n");
    printf("8. Viral Fever\n");
    printf("9. Common Cold/Head ache\n");
}
