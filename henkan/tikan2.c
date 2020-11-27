#include <stdio.h>
#include <string.h>
int main (void){
	FILE *fp1;
	FILE *fp2;
	char str[50000];
	char str1[50000];
	int i=0;
	fp1 = fopen("MOJI.txt","r");
	fp2 = fopen("HMOJI.txt","w");
	if(fp1==NULL){
		printf("ファイルオープン失敗\n");
		return -1;
	}
	while( (str[i]=fgetc(fp1)) != EOF ){
		str1[i]=str[i];
		if(65<=str[i] && 90>=str[i] || str[i]==32){
		}
		else if(97<=str[i]&&122>=str[i]){
			str[i]=str[i]-32;
		}
		else{
			str[i] = 32; 
		}
		
		i++;
	}
	fprintf(fp2,"%s",str);
	printf("置換前\n");
	for(i=0; i <=10; i++){
		printf("%c",str1[i]);
	}
	printf("\n置換後\n");
	for(i=0; i <=10; i++){
		printf("%c",str[i]);	
	}
	printf("\n");
	fclose(fp1);
	fclose(fp2);
	return 0;
}
