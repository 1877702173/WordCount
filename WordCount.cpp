#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int CharsNum(FILE *p);//统计字符数 
int WordsNum(FILE *p);//统计单词数 

int main(int argc, char* argv[]){
	FILE *p;
	int num;
	p=fopen(argv[2],"r");//argv[2]为同目录下文件名 
	if(p != NULL){
		if(strcmp(argv[1],"-c") == 0){//通过控制“-c”参数判断为字符统计 
			num = CharsNum(p);
			printf("字符数：%d",num);
		}
		else if(strcmp(argv[1],"-w") == 0){//通过控制“-w”参数判断为单词统计 
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
	while(!feof(p)){//判断 文件是否读取完毕 
		c = fgetc(p);
		num++;
	}
	rewind(p);//使文件p的位置指针指向文件开始
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
			num++;//统计单词数 
		}
		else if(x == 0 && c != ',' && c != ' '){
		
			x = 1;
		}
	}
	if(x == 1){//判断文本末尾情况 
		num++; 
	}
	rewind(p);
	return num;
}
