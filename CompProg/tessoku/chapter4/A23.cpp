//bit_dp
#include <bits/stdc++.h>
using namespace std;

int main(){
    /*
    011だったら、品物1と2が1枚のクーポンで無料になる
    初期dp[0][{}] = 0 クーポン券0枚までのうち、空集合の品物をクーポン券0枚で買える
    初期dp[3][{1,3}] = 2 クーポン券3枚までのうち、1,3の品物をクーポン券2枚で買えるか
    集合をsとし、i枚目のクーポン券を使ったときに無料で買える品物の集合をT_iとする
    dp[3][{1,3}] -> dp[4][{1,3}] クーポン券を使わないとき、値はそのまま dp[i-1][S]
        使わないときは-1以外
    クーポン券を使う時、値はdp[i-1][S|T] = min(dp[i][S|T], dp[i-1][S] + 1); <- 1枚使うので

    実装に関して、setを整数にしたいのでbitを使う
    dp[4][{1,3}]なら{1,3}=00101として,dp[4][5]と表現する
    */

    int N,M;
    //1<<10 = 1024
    int A[109][19], dp[109][1029] ;
    cin >> N >> M;
    for(int i=1; i<=M ; i++){
        for (int j=1; j<=N; j++) cin >> A[i][j];
    }

    //1'000'000'000 = x
    for(int i=0; i<=M; i++){
        for(int j=0; j<=1029; j++) dp[i][j] = 1'000'000'000;
    }
    //dp[0][{}]
    dp[0][0] = 0;
    for(int i=1; i<=M; i++){
        for(int j=0; j<(1<<N); j++){
            
            //1-既に無料(クーポン券を買わなくても), Nは桁数
            int already_free[19];
            for(int k=1; k<=N; k++){
                if((j / (1 << (k-1))) % 2 == 0) already_free[k] = 0;
                else already_free[k] = 1;
            }

            //2-クーポン券を選んだ時の処理
            int v = 0;
            for(int k = 1; k<=N; k++){
                if(already_free[k] == 1 || A[i][k] == 1) v += (1<<(k-1));
            }
            
            //2.5-満たすものを処理する場合
            // クーポンだけでいけるのは、1
            // クーポンと既に無料の和でいけるのはdp[i][v]と同じ

            //3-遷移処理(全部の品物を買うものを求めているので、{1}が1'000'000'000でも構わない)
            dp[i][j] = min(dp[i][j], dp[i-1][j]); //クーポン不使用
            dp[i][v] = min(dp[i][v], dp[i-1][j] + 1); //クーポン使用
        }
    }


    if(dp[M][(1<<N)-1] == 1'000'000'000) cout << "-1" << endl;
    else cout << dp[M][(1<<N)-1] << endl;
    return 0;

}

