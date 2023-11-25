#include <bits/stdc++.h>
using namespace std;

/**
 * 型 *ポインタ; //宣言
 * &変数 //アドレス取得
 * *ポインタ //ポインタがさす値の読み書き
 * ポインタ //ポインタそのものへのアクセス
 * ポインタ->メンバ //ポインタ経由でのメンバアクセス
*/

//pointerがさす先のメンバアクセス
struct A{
    int data;
    void print(){
        cout << data << endl;
    }
};

int main(){
    //型のバイト数を知る
    cout << sizeof(int32_t) << endl;

    /*pointer*/
    int x = 1;
    int *p; //pointerの宣言
    p = &x; //アドレスで初期化
    *p = 2; //ポインタがさすメモリへの書き込み
    cout << x << endl; //2

    int y;
    y = *p; //pointer経由でxの値を読み取る(xと同じobjになったわけではない)
    cout << y << endl;

    A a = A{1};
    A *p1 = &a; //aを指すポインタ
    p1->print();
    p1->data = 2; //a.dataの書き換え
    p1->print();

    //pointerの値そのものを出力(==や!=で比較可能)
    cout << p1 << endl;

    /**
     * スタック領域とヒープ領域
     * 静的領域
     *  グローバル編素のメモリ割り当て、解放はコンパイラが自動で行う
     *  メモリ上から削除する必要がないので
     * 
     * スタック領域
     *  ローカル変数はスコープの始まりで確保し、終わりで解放する
     *  この時配置されるメモリ領域がスタック領域
     * 
     * ヒープ領域
     *  スコープの範囲を超えて何らかの銃砲を使いたいときに使用
     *  メモリを有効活用する必要がないならあらかじめグローバルで確保すれば十分
    */

   //メモリの確保(型 *pointer = new 型, new 型(), new 型[n])
   //メモリの解放(delete pointer, delete[] pointer)
   
   //単一領域の確保
   uint32_t *p2;
   p2 = nullptr;  //初期化していなかったり、有効なアドレスを指していないことを明示するために用いる。0を意味する(多くの場合)
   p2 = new uint32_t;
   *p2 = 123;
   cout << *p2 << endl;
   p2 = nullptr; //使い終わった場合もnullptrを入れておく
   delete p2;

    //連続領域の確保
    /**
     * Tという型のポインタpに対し
     * p+dとしたとき、それはp + sizeof(T) * dバイトというアドレスになる
    */
    uint32_t *p3;
    uint32_t *q1 = nullptr;
    p3 = new uint32_t[10]; //4*10バイト分確保
    for(int i=0; i<10; i++){
        q1 = p3 + i; //pointerの加減算
        *q1 = i; //書き込み
    }
    q1 = p3; //元の位置に戻す
    for(int i=0; i<10; i++){
        cout << *q1 << endl;
        q1++;//次の要素を指すように変更
    }
    delete[] p3; //解放

    /**
     * 複数バイトの変数: 1バイトより大きいデータがどうやって保存されるかは
     * コンパイラなどに依存する。ビッグエンディアンorリトルエンディアン
     * 
    */

}