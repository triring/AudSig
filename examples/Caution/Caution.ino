/*
 * Caution.ino - Example for Auditory signals Library.
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

// 注意音	Caution signal
// 弱注意音1	weak caution1   オブジェクトの生成
AudSig weak_caution1(BUZZER_PIN, 500, 200, 500, 200, 500, 200, 500, 200, 0);
// 弱注意音2	weak caution2   オブジェクトの生成
AudSig weak_caution2(BUZZER_PIN, 100, 50, 100, 500, 100, 50, 100, 500, 100, 50, 100, 500, 100, 50, 100, 500, 100, 50, 100, 500, 0);
// 強注意音1	strong caution1 オブジェクトの生成
AudSig strong_caution1(BUZZER_PIN, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 0);
// 強注意音2	strong caution2 オブジェクトの生成
AudSig strong_caution2(BUZZER_PIN, 300, 100, 300, 100, 300, 100, 300, 100, 300, 100, 300, 100, 300, 100, 300, 100, 300, 0);

void setup() {
  // begin()でピンモードの設定を行う。
  weak_caution1.begin();    // 弱注意音1  の初期設定
  weak_caution2.begin();    // 弱注意音2  の初期設定
  strong_caution1.begin();  // 強注意音1  の初期設定
  strong_caution2.begin();  // 強注意音2  の初期設定
}

void loop() {
  weak_caution1.ring();    // 弱注意音1  の再生
  delay(5000);             // 5秒間の休止
  weak_caution2.ring();    // 弱注意音2  の再生
  delay(5000);             // 5秒間の休止
  strong_caution1.ring();  // 強注意音1  の再生
  delay(5000);             // 5秒間の休止
  strong_caution2.ring();  // 強注意音2  の再生
  delay(5000);             // 5秒間の休止
}
