#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int CharsNum(FILE *p);
int WordsNum(FILE *p);

int main(int argc, char* argv[]){
	FILE *p;
	int num;
	p=fopen(argv[2],"r");
	if(p != NULL){
		if(strcmp(argv[1],"-c") == 0){
			num = CharsNum(p);
			printf("字符数：%d",num);
		}
		else if(strcmp(argv[1],"-w") == 0){
			num = WordsNum(p);
			printf("单词数：%d",num);
		}
	}
	else{
		printf("文件打开失败");
	} 
} 

int CharsNum(FILE *p){
	int num = 0;
	char c;
	while(!feof(p)){
		c = fgetc(p);
		num++;
	}
	rewind(p);
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
			num++;
		}
		else if(x == 0 && c != ',' && c != ' '){
		
			x = 1;
		}
	}
	if(x == 1){
		num++;
	}
	rewind(p);
	return num;
}
