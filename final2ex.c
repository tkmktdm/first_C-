#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<dos.h>
int main(void)
{
    clock_t start,end;
   double time, suc,types,ranc;
    FILE *fp;
    int i,ch,len,mozisum,moziretu,keyin,scr1,scr2,scr3,judge,modo;
    int count=5;


    char str[256];

	system("cls");
	printf("\033[33m");
	printf("modo choose easy or hard (1or2)");
	scanf("%d",&modo);
	if(modo!=1&&modo!=2){
		printf("1��2��I�����Ă��������B\n");
		
		exit(0);
		}else if(modo==1){
			printf("\033[36m");
			fp = fopen("easy.txt","r");
    		if(fp == NULL){
        		printf("File Open Error\n");
        		return -1;
    		}
		}else if(modo==2){
			system("cls");
			
			printf("\033[31m");
			fp = fopen("hard.txt","r");
    		if(fp == NULL){
        		printf("File Open Error\n");
        		return -1;
    		}
		}			

    printf("input game type(1or2):");
    scanf("%d",&judge);
    if(judge!=1&&judge!=2){
        printf("1��2��I�����Ă��������B\n");
        exit(0);
    }

    else if(judge==1){
		

        keyin=0;
        moziretu=0;
        suc=0;

        printf("�ȉ��̕�������^�C�v���Ă�������.\n");

        while(count){
            printf("\r%2.2d",count);
            fflush(stdout);
            sleep(1);
            count--;
        }
        start = clock();
        printf("\n");
        while(fgets(str,256,fp) != NULL){
            len = strlen(str);
            str[len-1] = '\0';
            len = len - 1;
			
            printf("%s\n",str);
            for(i = 0; i < len; i++){
                while(1){
                    ch = getch();
                    keyin+=1;
                    if(ch == str[i]){
                        putch(ch);
                        moziretu+=1;
                        break;
                    }
                }
            }printf(" Now ���v%d/%d���ł�����I\r",keyin,moziretu);
            printf("\n");
        }
        end = clock();
        time = (double)(end - start)/CLOCKS_PER_SEC;

        suc=100*moziretu/keyin;

        types=0;
        types=keyin/time*60;
		

        printf("\n���v���Ԃ�%.1lf�b�ł�.\n",time);
        printf("�o�蕶����%d(key)",moziretu);
        printf("�S���͐�%d(key)",keyin);
        printf("���ŗ�%.1lf(%)",suc);
        printf("�^�C�v�X�s�[�h%.1lf(key/min)",types);

        ranc=0;
        ranc=suc*time;
        printf("\n");

        if(5000>=ranc){
            printf("\n");
            printf("���Ȃ���A�����N�ł�");
            scr1=+1;
        }else if(10000>=ranc){
            printf("���Ȃ���B�����N�ł��B");
            scr2+=1;
        }else{
            printf("���Ȃ���C�����N�ł�..........");
            scr3+=1;
        }
        fclose(fp);
        {
            FILE *fp;
            
            fp = fopen("sample.txt","a");
            if(fp == NULL){
                printf("File Open Error\n");
                return -1;
            }
            if(scr1==1){
                fprintf(fp,"\nA�����N�ł�");
            }else if(scr2==1){
                fprintf(fp,"\nB�����N�ł�");
            }else{
                fprintf(fp,"\nC�����N�ł�");
            }
            fprintf(fp,"\n���v���Ԃ�%.1lf�b�ł�.\n",time);
            fprintf(fp,"�o�蕶����%d(key)",moziretu);
            fprintf(fp,"�S���͐�%d(key)",keyin);
            fprintf(fp,"���ŗ�%.1lf(%)",suc);
            fprintf(fp,"�^�C�v�X�s�[�h%.1lf(key/min)\n",types);
            fclose(fp);
        }
    }
    else {//2�߂̃R�[�h
		
	keyin=0;
	moziretu=0;
	suc=0;
	
	
	printf("�ȉ��̕�������^�C�v���Ă�������.\n");
	while(count){
		printf("\r%2.2d",count);
		fflush(stdout);
		sleep(1);
		count--;
	}
	printf("\r");
	start = clock();
	while(fgets(str,256,fp) != NULL){
	    len = strlen(str);
		str[len-1] = '\0';
		len = len - 1;
		for(i = 0; i < len; i++){
			printf("%s \r",&str[i]);
			while(1){
				ch = getch();
				
				keyin+=1;
				
				if(ch == str[i]){
					moziretu+=1;
					break;
					}
			}
		}
	}
	end = clock();
	time = (double)(end - start)/CLOCKS_PER_SEC;
	
	
	
	suc=100*moziretu/keyin;
	
	types=0;
	types=keyin/time*60;
	
	printf("\n���v����%.1lf�b�ł�.\n",time);
	printf("�o�蕶����%d(key)",moziretu);
	printf("�S���͐�%d(key)",keyin);
	printf("���ŗ�%.1lf(%)",suc);
	printf("�^�C�v�X�s�[�h%.1lf(key/min)",types);
	
	
	ranc=0;
	ranc=suc*time;
	
	printf("\n");
	if(5000>=ranc){
		
		printf("���Ȃ���A�����N�ł��I");
	}else if(10000>=ranc){
		printf("���Ȃ���B�����N�ł��B");
	}else{
		printf("���Ȃ���C�����N�ł�..........");
	}
	fclose(fp);
	
	{
            FILE *fp;
            
            fp = fopen("sample.txt","a");
            if(fp == NULL){
                printf("File Open Error\n");
                return -1;
            }
            if(scr1==1){
                fprintf(fp,"\nA�����N�ł�");
            }else if(scr2==1){
                fprintf(fp,"\nB�����N�ł�");
            }else{
                fprintf(fp,"\nC�����N�ł�");
            }
            fprintf(fp,"\n���v���Ԃ�%.1lf�b�ł�.\n",time);
            fprintf(fp,"�o�蕶����%d(key)",moziretu);
            fprintf(fp,"�S���͐�%d(key)",keyin);
            fprintf(fp,"���ŗ�%.1lf(%)",suc);
            fprintf(fp,"�^�C�v�X�s�[�h%.1lf(key/min)\n",types);
            fclose(fp);
			
	}
	
	}return 0;
}