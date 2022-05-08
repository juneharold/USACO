/*
dp[i][j][0,1]=범위 i-j를 k로 만들기
이때, k는 최대 400개의 숫자

dp[i][j][1]=dp[i][j-1][0]+cost(num[j]-num[j-1]) or 
dp[i][j][0]=dp[i+1][j][k]+cost(num[i]-num[i+1])

basecase
dp[i][i][num[i]]=0;
else 1e9
*/
