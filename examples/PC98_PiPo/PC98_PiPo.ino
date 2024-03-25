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
 * PC98_PiPo	国民機パソコン PC-9801シリーズの起動音	ピッポ!!
 * これは、報知音Caution signal ではないが、このAudSigの応用例として作成した。
 * PC9801の起動音の仕様
 * ネットで公開されていたPC-9801シリーズの起動音を分析した結果、約2000Hzを50ms,約1000Hzを50msと連続で鳴らしていた。
 * しかし、以下の2点が気になった。
 *  - 絶対音感を持つ人は、音階とのズレが気になるのではないか。
 *  - 鳴動時間が短いので聞き取りにくい。
 * そこで、周波数を純正律の音階に合わせ、鳴動時間を100msと少し長めに設定する。
 *  - 6B 6オクターブのシ 1980 Hz  100ms
 *  - 5B 5オクターブのシ  990 Hz  100ms
 */

#define PI 1980  // 6B 6オクターブのシ
#define PO 990   // 5B 5オクターブのシ

const int BUZZER_PIN = 22;  // ピエゾブザーの接続ピン番号

// noteの生成
AudSig note_O6B(BUZZER_PIN, 100, 0);
AudSig note_O5B(BUZZER_PIN, 120, 0);

void setup() {
  // begin()でピンモードの設定を行う。
  note_O6B.begin();           // 6B 6オクターブのシ の初期設定
  note_O6B.setFrequency(PI);  // 周波数を設定
  note_O5B.begin();           // 5B 5オクターブのシ の初期設定
  note_O5B.setFrequency(PO);  // 周波数を設定
}

void loop() {
  note_O6B.ring();
  delay(20);
  note_O5B.ring();
  delay(5000);
}
