#include <stdio.h>
#include <string.h>
int main (void){
	FILE *fp1;
	FILE *fp2;
	char str[50000];
	char hin[26][2] = {{' ','0'},{'A','0',},{'B','0'},{'C','0'},{'E','0'},{'F','0'},{'G','0'},{'H','0'},{'I','0'},{'J','0'},{'K','0'},{'L','0'},{'M','0'},{'N','0'},{'O','0'},{'P','0'},{'Q','0'},{'R','0'},{'S','0'},{'T','0'},{'U','0'},{'V','0'},{'W','0'},{'X','0'},{'Y','0'},{'Z','0'}};
	int i=0, j, k=0;
	int c=0, s=0, m=0;
	char hin2[10000][2]={0};
	char hin3[10000][3]={0};
	int cot[26] = {0};
	int cot2[10000] = {0};
	int cot3[20000] = {0};
	int temp; 
	char ctemp, atemp, dtemp;
	fp1 = fopen("HMOJI.txt","r");
	fp2 = fopen("HINDO.txt","w");
	if(fp1==NULL){
		printf("ファイルオープン失敗\n");
		return -1;
	}
	while( (str[i]=fgetc(fp1)) != EOF ){
		if(i >= 1){
			for(j=0; j <= s; j++){
				if(hin2[j][0] == str[i-1] && hin2[j][1] == str[i]){
					cot2[j]++;
					c=1;
					j=s;
				}
			}
			if(c!=1){
				hin2[s][0] = str[i-1];
				hin2[s][1] = str[i];
				s++;
				cot2[s]++;
			}
			c=0;

		}
		if(i >= 2){
			for(j=0; j <= m; j++){ 
				if(hin3[j][0] == str[i-2] && hin3[j][1] == str[i-1] && hin3[j][2] == str[i]){
					cot3[j]++;
					c=1;
					j=m;
				}
			}
			if(c!=1){ 
				hin3[m][0] = str[i-2];
				hin3[m][1] = str[i-1];
				hin3[m][2] = str[i]; 
				m++;
				cot3[m]++;
			}
			c=0;
		}
	i++;
	}
	for (j=0; j<s; j++){
		for(k=s; k>j; k--){
			if(cot2[k-1]<cot2[k]){
				temp = cot2[k-1];
				ctemp = hin2[k-1][0];
				atemp = hin2[k-1][1];
				cot2[k-1] = cot2[k];
				hin2[k-1][0] = hin2[k][0];
				hin2[k-1][1] = hin2[k][1];
				cot2[k] = temp;
				hin2[k][0] = ctemp;
				hin2[k][1] = atemp;
				 
			}
		}
	}

	for (j=0; j<m; j++){
		for(k=m; k>j; k--){
			if(cot3[k-1]<cot3[k]){
				temp = cot3[k-1];
				ctemp = hin3[k-1][0];
				atemp = hin3[k-1][1];
				dtemp = hin3[k-1][2];
				cot3[k-1] = cot3[k];
                                hin3[k-1][0] = hin3[k][0];
                                hin3[k-1][1] = hin3[k][1];
				hin3[k-1][2] = hin3[k][2];
                                cot3[k] = temp;
                                hin3[k][0] = ctemp;
                                hin3[k][1] = atemp;
				hin3[k][2] = dtemp;
			}
		}
	}
	int tot = i;

	for(i=0; i<=25; i++){
		fprintf(fp2, "%c %d\r\n",hin[i][0],cot[i]);
	//	printf("%c %d\n",hin[i][0],cot[i]);
	}
	printf("第2次近似\n");	
	for(i=0; i<=19; i++){
		printf("%2d	%c%c %d\n",i+1,hin2[i][0], hin2[i][1] ,cot2[i]);
	}
	printf("第3次近似\n");
	for(i=0; i<=19; i++){ 
		printf("%2d	%c%c%c %d\n",i+1,hin3[i][0], hin3[i][1], hin3[i][2], cot3[i]);
	}
	printf("合計文字数%d\n",tot);
	fclose(fp1);
	fclose(fp2);
	return 0;
}
