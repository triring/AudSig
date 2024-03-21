/*
 * OperationInvalid.ino - Example for Auditory signals Library.
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

// 操作無効音	Operation invalid signal

// 受付無効音	reception invalid signal オブジェクトの生成
AudSig reception_invalid(BUZZER_PIN, 100, 100, 500, 0);
// 作業不備音1 incomplete work signal オブジェクトの生成
AudSig incomplete_work1(BUZZER_PIN, 100, 100, 100, 100, 100, 0);
// 作業不備音2 incomplete work signal オブジェクトの生成
AudSig incomplete_work2(BUZZER_PIN, 50, 50, 50, 50, 50, 50, 50, 0);

void setup() {
  // begin()でピンモードの設定を行う。
  reception_invalid.begin();  // 受付無効音   の初期設定
  incomplete_work1.begin();   // 作業不備音1  の初期設定
  incomplete_work2.begin();   // 作業不備音2  の初期設定
}

void loop() {
  reception_invalid.ring();  // 受付無効音 の再生
  delay(5000);               // 5秒間の休止
  incomplete_work1.ring();   // 作業不備音1	の再生
  delay(5000);               // 5秒間の休止
  incomplete_work2.ring();   // 作業不備音2	の再生
  delay(5000);               // 5秒間の休止
}
