#include <stdio.h>
#include <string.h>
#include <stack>

char str[2010];

int func(){

	int i, len, changes = 0;
	std ::stack<char> st;

	len = strlen(str);
	for(i = 0 ; i < len ; i++){
		if(str[i] == '{')
			st.push(str[i]);
		else if(str[i] == '}'){
			if(!st.empty())
				st.pop();
			else{
				st.push('{');
				changes++;
			}
		}
	}
	if(!st.empty())
		changes += (st.size() / 2);

	return changes;
}

int main(){

	int changes;
	long long int testCaseNo = 1;

	while(1){

		scanf("%s",str);

		if(str[0] == '-')
			break;
		changes = func();

		printf("%lld. %d\n", testCaseNo++, changes);
	}

	return 0;
}