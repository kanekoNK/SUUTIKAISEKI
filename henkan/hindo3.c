#include <stdio.h>
#include <string.h>
int main (void){
	FILE *fp1;
	FILE *fp2;
	char str[50000];
	char hin[26][2] = {{' ','0'},{'A','0',},{'B','0'},{'C','0'},{'E','0'},{'F','0'},{'G','0'},{'H','0'},{'I','0'},{'J','0'},{'K','0'},{'L','0'},{'M','0'},{'N','0'},{'O','0'},{'P','0'},{'Q','0'},{'R','0'},{'S','0'},{'T','0'},{'U','0'},{'V','0'},{'W','0'},{'X','0'},{'Y','0'},{'Z','0'}};
	int i=0, j, k=0;
	int c=0, s=0, m=0,n=0,cot=0;
	char hin4[40000][30] = {0};
	char tan[30] = {0};
	int cot4[40000] = {0};
	int temp; 
	char ctemp[30], atemp[30], dtemp;
	fp1 = fopen("HMOJI.txt","r");
	if(fp1==NULL){
		printf("ファイルオープン失敗\n");
		return -1;
	}
	while( (str[i]=fgetc(fp1)) != EOF ){
		if(str[i]>64&&str[i]<91){
			tan[s]=str[i];
			s++;
			c=0;
		}
		else{ 
			c=1;
		}
		if(c!=0&&tan[0]!=0){
			for(j=0; j<=m; j++){
				for(k=0; k<=s;k++){
					if(hin4[j][k]==tan[k]){
						n++;			
					}
				}
				if(s==n){
					cot4[j]++;
					cot=1;
					j=m;
				}
				
			}
		
			if(cot!=1){
				for(j=0;j<=s; j++){
					hin4[m][j]=tan[j];
				}
				cot4[m]++;
				m++;
			}
			for(j=0;j<=30; j++){
				tan[j]=0;
			}
			cot=0;
		n=0;
		s=0;
		}
		
	i++;
	}
	int tot = i;
	for (j=0; j<m; j++){
		for(k=m; k>j; k--){
			if(cot4[k-1]<cot4[k]){
				temp = cot4[k-1];
				//for(i=0;i<30;i++){
				//	atemp[i] = hin4[k-1][i];
				//}
				cot4[k-1] = cot4[k];
				//for(i=0;i<30;i++){ 
				//	hin4[k-1][i] = hin4[k][i];
				//}
				cot4[k] = temp;
			//	for(i=0;i<30;i++){
			//		hin4[k][i] = atemp[i];
			//	}
			}
		}
	}

	printf("第2次近似\n");	
	for(i=0; i<20; i++){
		printf("%2d	%s %d\n",i+1,hin4[i] ,cot4[i]);
	}
	

	printf("合計文字数%d\n",tot);
	fclose(fp1);
	return 0;
}
