#include <stdio.h>
#include <string.h>
int main (void){
	FILE *fp1;
	FILE *fp2;
	char str[50000];
	char hin[26][2] = {{' ','0'},{'A','0',},{'B','0'},{'C','0'},{'E','0'},{'F','0'},{'G','0'},{'H','0'},{'I','0'},{'J','0'},{'K','0'},{'L','0'},{'M','0'},{'N','0'},{'O','0'},{'P','0'},{'Q','0'},{'R','0'},{'S','0'},{'T','0'},{'U','0'},{'V','0'},{'W','0'},{'X','0'},{'Y','0'},{'Z','0'}};
	int i=0, j, k=0;
	int cot[26];
	int temp; 
	char ctemp;
	fp1 = fopen("HMOJI.txt","r");
	fp2 = fopen("HINDO.txt","w");
	if(fp1==NULL){
		printf("ファイルオープン失敗\n");
		return -1;
	}
	while( (str[i]=fgetc(fp1)) != EOF ){
		for(k = 0; k <= 26; k++){
			if(hin[k][0]==str[i]){
				cot[k]++;
			}
		}
		i++;
	}
	int tot = i;
	for (j = 0; j < 25; j++) {
		for (k = 25; k > j; k--) {
			if (cot[k-1] < cot[k]){
				temp = cot[k-1];
				ctemp = hin[k-1][0];		
				cot[k-1] = cot[k];
				hin[k-1][0] = hin[k][0];
				cot[k] = temp;
				hin[k][0] = ctemp;
      			}
		}
	}
	for(i=0; i<=25; i++){
		fprintf(fp2, "%c %d\r\n",hin[i][0],cot[i]);
		printf("%c %d\n",hin[i][0],cot[i]);
	}	
	printf("合計文字数%d\n",tot);
	fclose(fp1);
	fclose(fp2);
	return 0;
}
