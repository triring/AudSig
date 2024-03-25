/*
 * Jihou.ino - Example for Auditory signals Library.
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

/*
 * NHKの時報
 * これは、報知音Caution signal ではないが、このAudSigの応用例として作成した。
 * 時報の仕様は以下の通り
 * 正時の3秒前から440ヘルツの予報音を3回
 * 正時に880ヘルツの正報音を1回
 * 正時の3秒後に正報終了
 */

const int BUZZER_PIN = 22;  // ピエゾブザーの接続ピン番号

AudSig Pi(BUZZER_PIN, 50, 950, 0);  // 予報音(440Hz)
AudSig Poon(BUZZER_PIN, 3000, 0);   // 正報音(880Hz)

void setup() {
  // begin()でピンモードの設定を行う。
  Pi.begin();             // 予報音の初期設定
  Pi.setFrequency(440);   // 周波数を440Hzに設定
  Poon.begin();           // 正報音の初期設定
  Poon.setFrequency(880); // 周波数を880Hzに設定
}

void loop() {
  Pi.ring();    // 予報音(440Hz)  の再生 0.05秒 + 休止 0.95秒 = 1秒
  Pi.ring();    // 予報音(440Hz)  の再生 0.05秒 + 休止 0.95秒 = 1秒
  Pi.ring();    // 予報音(440Hz)  の再生 0.05秒 + 休止 0.95秒 = 1秒
  Poon.ring();  // 正報音(880Hz)  の再生 3.00秒
  delay(4000);  // 4.00秒間の休止
}
