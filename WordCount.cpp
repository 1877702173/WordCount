#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int CharsNum(FILE *p);//ͳ���ַ��� 
int WordsNum(FILE *p);//ͳ�Ƶ����� 

int main(int argc, char* argv[]){
	FILE *p;
	int num;
	p=fopen(argv[2],"r");//argv[2]ΪͬĿ¼���ļ��� 
	if(p != NULL){
		if(strcmp(argv[1],"-c") == 0){//ͨ�����ơ�-c�������ж�Ϊ�ַ�ͳ�� 
			num = CharsNum(p);
			printf("�ַ�����%d",num);
		}
		else if(strcmp(argv[1],"-w") == 0){//ͨ�����ơ�-w�������ж�Ϊ����ͳ�� 
			num = WordsNum(p);
			printf("��������%d",num);
		}
	}
	else{
		printf("�ļ���ʧ��");
	} 
} 

int CharsNum(FILE *p){
	int num = 0;
	char c;
	while(!feof(p)){//�ж� �ļ��Ƿ��ȡ��� 
		c = fgetc(p);
		num++;
	}
	rewind(p);//ʹ�ļ�p��λ��ָ��ָ���ļ���ʼ
	return num;
}
int WordsNum(FILE *p){
	int num = 0;
	int x = 0;
	char c;
	while(!feof(p)){
		c = fgetc(p);
		if( x == 1 && (c == ',' || c == ' ')){ 
			x = 0;
			num++;//ͳ�Ƶ����� 
		}
		else if(x == 0 && c != ',' && c != ' '){
		
			x = 1;
		}
	}
	if(x == 1){//�ж��ı�ĩβ��� 
		num++; 
	}
	rewind(p);
	return num;
}
