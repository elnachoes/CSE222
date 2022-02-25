#include <stdio.h>

int main(int argc, char** argv)
{
        Node root=NULL;
        FILE *file_name;
        char read[100];
        int i,n;
        int x;
        int parsednum;
        char plate[100],first[100],last[100];
        char command[100];
        char item[100];
        char intake[100];
        if(argc!=2)
        {
                printf("ERROR\n");
                return(1);
        }

        if(file_name==NULL)
        {
                printf("ERROR\n");
                return(1);
        }

        file_name=fopen(argv[1],"r");

//              file_name=fopen(argv[1],"r");
        while(NULL!=fgets(read,100,file_name))
        {
//              read[strlen(read)-1]='\0';
                sscanf(read,"%s%s%s",plate,first,last);
                root=add(root,plate,first,last);
                printf("Input=  %s %s %s  \n",plate,first,last);
        }
                fclose(file_name);//if not closed you will have a memory leak of about 56
while(1)
                {
                        printf("Enter command or plate: ");
                        if(fgets(intake,100,stdin)!=NULL)
                        {
//                              printf("Enter command or plate: ");
//                              fgets(intake,100,stdin);
                                parsednum=sscanf(intake,"%s%s",command,item);
                                printf("This is command =   %s\n",command);//test
                                printf("This is item =   %s\n",item);//test
                                printf("This is intake =   %s\n",intake);//test

                                printf("This is the value of strcmp Dump: %d  \n",(strcmp(intake,"DUMP\n")));//test
                                printf("This is the value of strcmp Delete: %d  \n",(strcmp(command,"DELETE")));//test

                                if(strcmp(intake,"DUMP\n")==0)
  {
                                        printf("We are in dump\n");//
                                        printf("the height of the tree is %d \n",height(root));
                                        //break;
                                }
                                else if(strcmp(command,"DELETE")==0)
                                {
                                printf("We are in Delete\n");
//                              break;
                                }
                                else
                                {
                                        printf("We are in the add plate\n");
                                }
                        }
                        else
                        {
                                printf("We are in the exit  \n");
//                              fclose(file_name);
                                return(0);
                        }
                }
//      fclose(file_name);
//      return(1);
}