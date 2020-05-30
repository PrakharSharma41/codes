#include <stdio.h>
#include <string.h>

int main() {
	// your code goes here
	int t;
	scanf("%d",&t);
	for(int m = 0; m< t; m++){
		char s[10003];
		scanf("%s",s);
		int n = strlen(s);
		if(n==1){
			printf("%s\n",s );
		}
		else if(n==2){
			if(s[0] == 49 && s[1] == 48){
				printf("9\n");
			}
			else if(s[0] > 49 && s[1] != 57){
				s[0]--;
				s[1] = 57;
				printf("%s\n",s);
			}
			else{
				printf("%s\n",s);
			}
		}
		else{
			if(s[0] > 49){
				int flag = 1;
				for (int i = 1; i < n && flag; ++i)
				{
					if(s[i] != 57){
						flag = 0;
					}
				}
				if(flag == 0){
					s[0]--;
					for (int i = 1; i < n; ++i)
					{
						s[i] = 57;
					}
				}
				printf("%s\n",s );
			}
			else{
				int k = 1;
				while(k<n){
					if(s[k]>48){
						break;
					}
					k++;
				}
				if(k == n){
					for (int i = 0; i < n; ++i)
					{
						s[i] = 57;
					}
					printf("%s\n",s+1);
				}
				else if(k == n-1){
					printf("%s\n",s );
				}
				else{
					int flag = 1;
					for (int i = k+1; i < n && flag; ++i)
					{
						if(s[i] != 57){
							flag = 0;
						}
					}
					if(flag == 1){
						printf("%s\n",s );
					}
					else{
						s[k]--;
						for (int i = k+1; i < n; ++i)
						{
							s[i] = 57;
						}
						printf("%s\n",s );
					}
				}
			}
		}
	}
	return 0;
}

