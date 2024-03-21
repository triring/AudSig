/*
 * OperationReception.ino - Example for Auditory signals Library.
 * Created by @triring := Akio miwa, 2024/03/11
 * Updated by @triring := Akio miwa, 2024/03/12
 * Released into "THE BEER-WARE LICENSE".
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <akio@triring.net> wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return @triring := Akio MIWA
 * ----------------------------------------------------------------------------
 */

#include "AudSig.h"

const int BUZZER_PIN = 22;  // ピエゾブザーの接続ピン番号

// 操作受付音 Operation reception signal
// 受付・スタート音	reception and start signal オブジェクトの生成
AudSig reception_start(BUZZER_PIN, 100, 0);
// 停止音	stop signal オブジェクトの生成
AudSig stop(BUZZER_PIN, 600, 0);
// 基点音	starting position signal オブジェクトの生成
AudSig starting_position(BUZZER_PIN, 50, 50, 50, 0);

void setup() {
  // begin()でピンモードの設定を行う。
  reception_start.begin();    // 受付・スタート音 の初期設定
  stop.begin();               // 停止音	の初期設定
  starting_position.begin();  // 基点音	の初期設定
}

void loop() {
  reception_start.ring();    // 受付・スタート音 の再生
  delay(5000);               // 5秒間の休止
  stop.ring();               // 停止音	の再生
  delay(5000);               // 5秒間の休止
  starting_position.ring();  // 基点音	の再生
  delay(5000);               // 5秒間の休止
}
