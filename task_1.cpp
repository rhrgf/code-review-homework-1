//�����ԭ����仯�������£�

//��ԭ����main�����Ĺ���ģ�黯�������㵥�ʺ�Ƶ�ʵĹ���д��һ��������
//���ǵ�ʵ���ԣ������˰�����Ƶ�����򣬺�д���ı��ĺ���

#include <stdio.h>
#include <string.h>
 
struct words   
{
    char word[20];
    int count;
};

int countword(FILE *fp ,struct words *word)
{
    int i=0,j=0,k=0,flag =0;
    char c;
	char tmp[]={0};
	while ((c= fgetc(fp))!=EOF)
    {    
        if (c!=',' && c!='.' && c!='?' && c!=' ' && c!='\n')
        {
            tmp[j] =(c>='A'&&c<='Z')?c+32:c; //ȫת��Сд 
			j++;
        }else
        {
            tmp[j] ='\0';
            j=0;
            flag = 0;
            //�жϵ����Ƿ��Ѿ���¼ ���������ʹ���ʼ�1
            for (k=0;k<i;k++)
            {
                if ( strcmp(tmp,word[k].word)==0 )
                {
                    word[k].count++;
                    flag = 1;
                    break;
                }
            }
            //û������뵥�ʽṹ�����鱣��
            if (!flag)
            {
                strcpy(word[i].word,tmp);
                word[i].count++;
                i++;
            }
        }
    }
	return i;
}

//ʹ��������
int order(int wordnum,struct words *word)
{
	int j,k;
	struct words stmp = {0};
	for (j=0;j<wordnum;j++)
    {
        for (k=0;k<wordnum-j-1;k++)
        {
            if (word[k].count>word[k+1].count)
            {
                stmp = word[k];
                word[k] = word[k+1];
                word[k+1] = stmp;
            }
        }
    }
	return 0;
}

int write(char *str,FILE *fp )
{	
	printf("Input the word to test.txt\n");
	gets(str);
	fwrite(str,strlen(str),1,fp);
	fseek(fp,0,SEEK_SET);
	return 0;
}
void main()
{
    struct words word[200] = {0};
	struct words stmp = {0};
    int wordnum=0,j=0,k=0,flag =0;
	char tmp[20]={0};
	char str[]={0};
    FILE *fp = NULL;
    fp =fopen("test.txt","w+");
	write(str,fp);
	wordnum=countword(fp,word);
    fclose(fp);
	order(wordnum,word);
    for (k=0;k<wordnum;k++)
    {
        printf("%s%4d\n",word[k].word,word[k].count);
    }
}