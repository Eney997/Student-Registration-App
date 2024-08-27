#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <io.h>


 struct students{
      int id;
      char name[100];
      char lastName[100];
      char cource[100];
    };


void studentRegistration(){

    int choice;

    controlMenuChde:
    printf("\n\n\n\t\t\tMain Menu\n");
    printf("\t\t\t===========\n\n");

    printf("\t\t\t1.Add a new student.\n"
           "\t\t\t2.Show all student.\n"
           "\t\t\t3.Search student.\n"
           "\t\t\t4.Delete all students information.\n"
           "\t\t\t5.Exit.\n\n");

           printf("\t\t\tPlease enter your choice: ");
           scanf("\t\t\t%d",&choice);

           switch(choice){
            case 1:
            system("cls");
            studAdd();
            system("cls");
            goto controlMenuChde;
            break;

            case 2:
            system("notepad.exe student.txt");
            system("cls");
            goto controlMenuChde;
            break;

            case 3:
            system("cls");
            studentSearch();
            system("cls");
            goto controlMenuChde;
            break;

            case 4:
            system("cls");
            studentDelete();
            system("cls");
            goto controlMenuChde;
            break;

            case 5:
            exit(0);
            break;

            default:
                printf("\n\t\t\tInvalid pick,Please enter only option numbers.");
                Sleep(3000);
                system("cls");
                goto controlMenuChde;
            break;
           }

    return 0;
}


int studAdd(){

    FILE * fileForSTUD = fopen("student.txt","a");
    struct students pick;
    if(fileForSTUD == -1){
        printf("Cant open file");
        perror("Error: ");
        return;
    }

    a1:
    printf("\n\n\n\t\t\t=============\n");

    printf("\t\t\tEnter studnent id: ");
    scanf("\t\t\t%d",&pick.id);

    printf("\t\t\tEnter studnent name: ");
    scanf("\t\t\t%s",pick.name);

    printf("\t\t\tEnter studnent lastname: ");
    scanf("\t\t\t%s",pick.lastName);

    printf("\t\t\tEnter studnent cource: ");
    scanf("\t\t\t%s",pick.cource);

        printf("\t\t\t=============");

        fprintf(fileForSTUD,"\n=============\n");

        fprintf(fileForSTUD,"Student id is %d\n",pick.id);
        fprintf(fileForSTUD,"Student name is %s\n",pick.name);
        fprintf(fileForSTUD,"Student lastname is %s\n",pick.lastName);
        fprintf(fileForSTUD,"Student cource is %s\n",pick.cource);

        fprintf(fileForSTUD,"=============");

    fclose(fileForSTUD);

    printf("\n\n\t\t\tStudent added successfully.");

    system("notepad.exe student.txt");

    return 0;
}


int studentSearch() {
    int idSearcher;
    int found = 0;

    printf("\n\n\n\n\t\t\tYou can search student by ID.");
    printf("\n\n\t\t\tEnter student ID here: ");
    scanf("%d", &idSearcher);

    struct students pick;

    FILE * fileForStud = fopen("student.txt","r");
    if(fileForStud == NULL){
     puts("File Open Error");
     perror("Error:");
     return -1;
    }

    if(fread(&pick,sizeof(struct students),1,fileForStud) == 1 ){

       if(pick.id == idSearcher){
          found = 1;

        printf("\n=============\n");

        printf("Student id is %d\n",pick.id);
        printf("Student name is %s\n",pick.name);
        printf("Student lastname is %s\n",pick.lastName);
        printf("Student cource is %s\n",pick.cource);

        printf("=============");

       }
    }

    if(!found){
        printf("\n\t\t\tWrong student ID.");
    }

    fclose(fileForStud);

    Sleep(4000);
    return 0;
}


int studentDelete(){

   return 0;
}
