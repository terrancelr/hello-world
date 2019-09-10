//Terrance Rutledge: This program gets the name of the input file and the sequence of cipher commands from the command line. It then writes the cipher to standard output.
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

void left(char *);
void right(char *);
void increment(char *);
void decrement(char *);
int main(int argc, char *argv[]){

	FILE *fp = fopen(argv[1], "r");
	if(fp == NULL){
		printf("The input file %s does not exist\n", argv[1]);
	}
	char word[100];
	fscanf(fp, "%s", word);
	while(!feof(fp)){
		if(strcmp(argv[2], "L")==0){
			left(word);
			printf("%s\n", word);}
		if(strcmp(argv[2], "R")==0){
			right(word);
			printf("%s\n", word);}
		if(strcmp(argv[2], "I")==0){
			increment(word);
			printf("%s\n", word);}
		if(strcmp(argv[2], "D")==0){
			decrement(word);
			printf("%s\n", word);}
		if(strcmp(argv[2], "LIDR")==0||strcmp(argv[2],"ID")==0||strcmp(argv[2],"DI")==0||strcmp(argv[2],"IDRL")==0||strcmp(argv[2],"DRLI")==0||strcmp(argv[2],"RLID")==0||strcmp(argv[2],"RL")==0||strcmp(argv[2],"LR")==0){
			printf("%s\n", word);}
		fscanf(fp, "%s", word);
	}



	return 0;
}
void left(char *string){
	int i;
	for(i = 0; i<(strlen(string)-1);i++){
		string[i] = string[i+1];
	}

	return;
}
void increment(char *string){
	int i;
	for(i = 0; i<strlen(string); i++){
		string[i]++;
		}
	return;
}
void decrement(char* str){
	int i;
	for(i = 0; i<strlen(str); i++){
		str[i]--;
		}
	return;

}
void right(char *string){
	/*char temp;
	int len = strlen(string);
	int i;
	for(i = 0;i<(len/2);i++){
		temp = string[i];
		string[i] = string[(len-1)-i];
		string[(len)-i-1] = temp;
	}*/
	int i;
	for(i = 0; i<strlen(string)-1;i++){
		string[i] = string[i+1];
	}
}
