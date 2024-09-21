//基礎簡易的版本控制系統 : 支持提交、查看和回滾文件版本

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERSION 10
#define MAX_FILE_SIZE 1024

char versions[MAX_VERSION][MAX_FILE_SIZE];
int version_count = 0;


void commitFile(char *fileContent){
    
    if(version_count >= MAX_VERSION){
        printf("already reach the upper limit!\n");
        return;
    }else{
        strcpy(versions[version_count], fileContent);
        version_count++;
        printf("submit success! the version is %d now!\n", version_count);
    }

}

void viewVersion(int view_version){
    if(view_version > 0 && view_version <= version_count){
        printf("the version is %d now; and the content:\n%s", view_version, versions[view_version - 1]);
    }else{
        printf("invalid version!\n");
    }
}

void rollBackVersion(int rollback_version){

    if(rollback_version > 0 && rollback_version <= version_count){
        version_count = rollback_version;
        printf("already roll back to the version %d !\n", version_count);
    }else{
        printf("Invalid version!\n");
    }

}


int main(){

    int choice, version;
    char fileContent[MAX_FILE_SIZE];

    while (1) {
        printf("1. commit file\n2. view file version\n3. rollback version\n4. exit\n Option choice: ");
        scanf("%d", &choice);


        switch (choice){
            case 1:

                printf("please enter the file content: ");
                getchar();
                fgets(fileContent, MAX_FILE_SIZE, stdin);
                commitFile(fileContent);
                break;

            case 2:
            
                int view_version;
                printf("please enter the version you want to view: \n");
                scanf("%d",&view_version);
                viewVersion(view_version);
                break;

            case 3:
             
                int rollback_version;
                printf("please enter the version you want to roll back to: ");
                scanf("%d", &rollback_version);
                rollBackVersion(rollback_version);
                break;

            case 4:
                 
                return 0;
                
            default:
                
                printf("invalid choice!\n");
        }
    
    }

}
