/*
 * OperationReception.ino - Example for Auditory signals Library.
 * Created by @triring := Akio miwa, 2024/03/11
 * Updated by @triring := Akio miwa, 2024/03/12
 * Released into "THE BEER-WARE LICENSE".
 * ----------------------------------------------------------------------------
 * "THE BEERd:\M5Stack\LSRUI\jis-S0013\AudSig_1.0.0.zip-WARE LICENSE" (Revision 42):
 * <akio@triring.net> wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return @triring := Akio MIWA
 * ----------------------------------------------------------------------------
 */

#include <AudSig.h>

// 操作受付音 Operation reception signal
// 基点音	starting position signal オブジェクトの生成  
//                       ピン, 再生, 休止, 再生,  0 <--データの終了は'0'
//                       番号, 時間, 時間, 時間, 番兵
AudSig starting_position(  22,   50,  50,   50,  0 );

// コンストラクタの引数
// 第1引数(int型)  ブザー接続ピン番号
// 第2引数(int型)以降は可変引数
// 報知音のパターンとして、単音の再生時間と休止時間を整数型(単位はミリ秒)で交互に必要なだけ設定する。
// データの終了には、必ず最後に'0'を入れること。

void setup() {
  starting_position.begin(); // 基点音	の初期設定
}

void loop() {
  starting_position.ring();  // 基点音	の再生　ピッピッという音
  delay(5000);               // 5秒間の休止
}