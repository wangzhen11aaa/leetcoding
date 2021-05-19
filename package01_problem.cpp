#include <iostream>
#include <vector>

using namespace std;

int main(){
    int v[5] = {6,3,5,4,6};
    int w[5] = {2,2,6,5,4};
    int N =5;

    // 包可以承受最大重量
    int V = 10;

    // 初始化二维数据.
    // 数据Row为可以放多少物品，Column为最大重量V.
    vector<vector<int> > intermediate_result;   
    // 初始化第一行为0.因为没有放任何元素
    for(int r=0; r<N+1; r++){
        vector<int> tmp;
        for(int c=0; c<V+1; c++)
            tmp.push_back(0);
        intermediate_result.push_back(tmp);
    }
    
    //填充每一层的intermediate_result二维vector.
    for(int i=1; i<N+1; i++)
        for(int j=1; j<V+1; j++){
            int x;
            // i-1代表着数组中第ith的东西
            if(j-w[i-1] < 0){
                x = 0;
            }else{
                x = intermediate_result[i-1][j-w[i-1]]+v[i-1];
                // cout << "i :" << i << "j : " << j << endl;
                // cout << "x's value " << x;
            }
            intermediate_result[i][j] = max(intermediate_result[i-1][j], x);
        }
    cout << "Max value : " << intermediate_result[N][V];

    // 考虑使用一维数据,进行优化
    // 如果我们考虑复用 intermediate_result 数组

    int dp[V+1];
    //当背包为空时,价值为0
    memset(dp, 0, sizeof(dp));
    // 遍历所有物品
    for(int i=0; i<N; i++){
        // 对于某次的i,只要可以再次放入就继续循环
        // for(int j=V; j>=w[i]; --j){
        //     // cout << "dp[" << j <<"] : " << dp[j] << endl;
        //     // cout << "dp[j-w[i]]" << dp[j-w[i]] << endl;
        //     // cout << "v[i]" << v[i] << endl;
        //     dp[j] = max(dp[j], dp[j-w[i]]+v[i]);
        // }
        //如果顺序去赋值，那么当前循环被依赖的上一个循环的值会被覆盖,所以不能这么做.
        // 对于出界访问的恐惧，可以理解.
        for(int j=0; j<N && j>=w[i]; j++){
            dp[j] = max(dp[j], dp[j-w[i]]+v[i]);
        }
    }
    cout << "Max value from 1 dimension" <<  dp[V] << endl;

}