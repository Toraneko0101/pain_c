/**
 * ライブラリ更新と互換性
 * ⇒ライブラリの更新があった場合、必要な作業を考える
 * 
 * まずは場合分け
 * ⇒静的ライブラリ or 動的ライブラリ
 * ⇒更新前後でのAPI互換性
 * ⇒更新前後でのABI互換性
 * 
 * API互換性がない
 * ⇒コード修正⇒ビルド
 * 
 * API互換性あり⇒静的ライブラリ
 * ⇒ビルド
 * 
 * API互換性あり⇒動的ライブラリ⇒ABI互換性なし
 * ⇒ビルド
 * 
 * API互換性あり⇒動的ライブラリ⇒ABI互換性あり
 * ⇒そのままOK
*/

/**
 * API互換性
 * Application programming interface
 * ソースコードレベルでのinterface
 * 
 * 更新前のライブラリに存在するAPIを更新後のライブラリで
 * そのまま使用できればAPI互換性あり
 * 
 * ⇒コメント追加や実装変更はAPI互換性あり
 * ⇒APIの新規追加や拡張はAPI互換性あり
 * ⇒APIの削除と仕様を維持せず変更は互換性なし
*/

/**
 * 静的ライブラリ or 動的ライブラリ
 * 
 * 静的
 * ⇒ar rcで作ったもの
 * ⇒これはライブラリを使用するプログラムにそのまま配置されるので再ビルド不可欠
 * 
 * 動的
 * ⇒soなど
 * ⇒ライブラリの中身を変更すれば十分
 * ⇒ただしa.outの再起動がいる
 * 
 * 静的ライブラリ⇒再ビルド不可欠
 * 動的ライブラリ⇒API,ABI互換性を満たせば再ビルド不要。ただし適用には再起動
 * 動的ロード⇒再起動不要。
*/

/**
 * ABI互換性
 * Application Binary Interface
 * ⇒バイナリレベルでのinterface
 * ⇒通常はAPIがあればABIもあり、逆もまた然り
 * 
 * ABI互換性あり
 * ⇒クラスに属さない関数や変数の追加
 * 
 * ABI互換性なし
 * ⇒クラスにデータメンバを追加⇒オブジェクトのサイズ変更
 * ⇒データメンバの宣言順序を変更⇒オブジェクトのメモリ配置変更
 * ⇒仮想関数の追加
 * 
 * ABIはコンパイラ依存なので
 * ⇒同じコンパイラでもversion違いでABI互換性がなくなることがある
 * ⇒一方でClangでビルドしたものをGCCで使えることがあったりもする
 * ⇒デフォルトは互換性がなくても、設定を変えることで互換性があるようにビルドすることが可能になることもある
*/