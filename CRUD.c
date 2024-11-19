/*
2. CRUD Operations in File using C Language
Write a program where user records are stored as a list of users with fields such as unique
ID, Name, and Age. The file is named users.txt.
 Create: Add a new user to the file.
 Read: Display all users stored in the file.

 Update: Modify the details of a user based on ID.
 Delete: Remove a user by their ID.
Requirements
 The data should be stored in a structured format (object).
 Use text files to store the data.
 Implement functions to: Create a new file (if it doesn&#39;t exist), Read the file and
display the contents, update a specific record, delete a record by modifying the file
content.

*/




#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int Search(int id);

typedef struct{

int id,age;
char name[100];
} User;


int Search(int id)
{
    FILE* fp;
    fp = fopen("users.txt","rb");

    if(fp == NULL)
    {
        printf("Error: Unable to open file.\n");
        return 0;
    }

    User user;

    while(fread(&user,sizeof(user),1,fp)>0)
    {
        if(user.id == id)
        {
            // printf("User found.\n");
            // printf("ID: %d\n",user.id);
            // printf("Name: %s\n",user.name);
            // printf("Age: %d\n",user.age);
            break;
        }
    }
    
   int ans = feof(fp);
   fclose(fp);
    return ans;

}

void Create()
{
    FILE* fp;
    fp = fopen("users.txt","a");
    User user;
    if(!fp)
    {
        printf("Error: Unable to open file.\n");
        return;
    }

    printf("Enter the ID: ");
    scanf("%d",&user.id);

    

    if(!Search(user.id))
    {
        printf("Error: User already exists.\n");
        return;
    }

    getchar();

    printf("Enter the Name: ");
    fgets(user.name,100,stdin);
    user.name[strcspn(user.name, "\n")] = 0; // To Remove newline character

    printf("Enter the Age: ");
    scanf("%d",&user.age);

    fwrite(&user,sizeof(user),1,fp);

 
    fclose(fp);

    printf("User created successfully.\n");
}

void Read()
{
    FILE* fp;
    fp = fopen("users.txt","rb");
    if(fp == NULL)
    {
        printf("Error: Unable to open file.\n");
        return;
    }
    User user;
    printf("--------------------------\n");
    printf("ID\tName\tAge\n");
    printf("--------------------------\n");
    
    while(fread(&user,sizeof(user),1,fp)>0)
    {
        printf("%d\t%s\t%d\n", user.id, user.name, user.age);
    }
    printf("--------------------------\n");
    
    
    fclose(fp);

}

void Update()
{
    FILE* fp;
    fp = fopen("users.txt","r+");
    if(fp == NULL)
    {
        printf("Error: Unable to open file.\n");
        return;
    }
    User user;
    int id;
    printf("Enter the ID of the user you want to update: ");
    scanf("%d",&id);
    int found = 0;
   int n = CountRecords();
   for(int i = 0; i < n; i++)
   {
         fread(&user,sizeof(user),1,fp);
         if(user.id == id)
         {
              found = 1;
              printf("Enter the new Name: ");
              getchar();
              fgets(user.name,100,stdin);
              user.name[strcspn(user.name, "\n")] = 0; // To Remove newline character
              printf("Enter the new Age: ");
              scanf("%d",&user.age);
              fseek(fp,sizeof(user)*i,SEEK_SET);
              fwrite(&user,sizeof(user),1,fp);
              break;
         }
    }
     if(!found)
     {
          printf("Error: User not found.\n");
          return;
     }
     fclose(fp);
   }


void Delete()
{
    FILE* fp;
    FILE* fpv;
    fp = fopen("users.txt","r");
    fpv = fopen("temp.txt","a");
    if(fp == NULL)
    {
        printf("Error: Unable to open file.\n");
        return;
    }
    User user;
    int id;
    printf("Enter the ID of the user you want to delete: ");
    scanf("%d",&id);
    int found = 0;
    int n = CountRecords();
    for(int i = 0; i < n; i++)
    {
        fread(&user,sizeof(user),1,fp);
        if(user.id != id)
        {
            fwrite(&user,sizeof(user),1,fpv);
            fprintf(fpv,"%d\t,%s\t,%d\n", user.id, user.name, user.age);
        }
        else
            found = 1;
    }
    fclose(fp);
    fclose(fpv);
    remove("users.txt");
    rename("temp.txt","users.txt");
    if(!found)
    {
        printf("Error: User not found.\n");
    
    }
    else
    {
        printf("User deleted successfully.\n");
    }

}


int CountRecords()
{
    FILE* fp;
    fp = fopen("users.txt","r");
    if(fp == NULL)
    {
        // printf("Error: Unable to open file.\n");
        return 0;
    }
    User user;
    int count = 0;
    while(fread(&user,sizeof(user),1,fp)>0)
    {
        count++;
    }
    fclose(fp);
    return count;
}

int main()
{
    int choice;
    while(1)
    {
        printf("--------------------\n");
        printf("1. Create User\n");
        printf("2. Read User\n");
        printf("3. Update User\n");
        printf("4. Delete User\n");
        printf("5. Exit\n");
        printf("--------------------\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                Create();
                break;
            case 2:
                Read();
                break;
            case 3:
                Update();
                break;    
            case 4:
                Delete();
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice.\n");
        }

    } 
    
    return 0;
}