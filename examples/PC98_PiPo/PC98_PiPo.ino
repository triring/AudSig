/*
 * PC98_PiPo.ino - Example for Auditory signals Library.
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
 * PC98_PiPo	国民機パソコン PC98の起動音
 * これは、報知音Caution signal ではないが、このAudSigの応用例として作成した。
 * PC98の起動音の仕様
 * 6B 6オクターブのシ 1980 Hz  100ms
 * 5B 5オクターブのシ  990 Hz  100ms
 */

#define PI 1980     // 6B 6オクターブのシ
#define PO  990     // 5B 5オクターブのシ

const int BUZZER_PIN = 22;  // ピエゾブザーの接続ピン番号

// noteの生成
AudSig note_O6B(BUZZER_PIN, 100,0);
AudSig note_O5B(BUZZER_PIN, 120,0);

void setup() {
  // begin()でピンモードの設定を行う。
  note_O6B.begin();  // 6B 6オクターブのシ の初期設定
  note_O6B.setFrequency(PI); // 周波数を設定
  note_O5B.begin();  // 5B 5オクターブのシ の初期設定
  note_O5B.setFrequency(PO); // 周波数を設定
}

void loop() {
  note_O6B.ring();
  delay(20);
  note_O5B.ring();
  delay(5000);
}
