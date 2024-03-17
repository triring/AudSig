/*
 * SOS.ino - Example for Auditory signals Library.
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

#include <AudSig.h>

/*
 * WestminsterChime	ウェストミンスターの鐘（ウェストミンスターのかね、英語：Westminster Quarters）
 * これは、報知音Caution signal ではないが、このAudSigの応用例として作成した。
 * イギリスのロンドン中心部、テムズ川河畔のウェストミンスター宮殿の
 * 時計塔ビッグ・ベンで使われている時鐘のメロディ
 * 日本では学校のチャイムとして使われている。
 */

#define DottedHalfNote  2250 // 付点2分音符
#define HalfNote        1500 // 2分音符
#define QuarterNote      750 // 4分音符

const int BUZZER_PIN = 22;  // ピエゾブザーの接続ピン番号

AudSig O4G_L2_DOT(BUZZER_PIN, DottedHalfNote, 0);
AudSig O4G_L4(BUZZER_PIN, QuarterNote, 0);
AudSig O5C_L2_DOT(BUZZER_PIN, DottedHalfNote, 0);
AudSig O5C_L4(BUZZER_PIN, QuarterNote, 0);
AudSig O5D_L4(BUZZER_PIN, QuarterNote, 0);
AudSig O5E_L4(BUZZER_PIN, QuarterNote, 0);

void setup() {
 // begin()でピンモードの設定を行う。
 O4G_L2_DOT.begin(); O4G_L2_DOT.setFrequency(396);
 O4G_L4.begin();     O4G_L4.setFrequency(396);
 O5C_L2_DOT.begin(); O5C_L2_DOT.setFrequency(528);
 O5C_L4.begin();     O5C_L4.setFrequency(528);
 O5D_L4.begin();     O5D_L4.setFrequency(594);
 O5E_L4.begin();     O5E_L4.setFrequency(660);
}

// tempo = 80
void loop() {
  O5C_L4.ring();
  O5E_L4.ring();
  O5D_L4.ring();
  O4G_L2_DOT.ring();

  O5C_L4.ring();
  O5D_L4.ring();
  O5E_L4.ring();
  O5C_L2_DOT.ring();

  O5E_L4.ring();
  O5C_L4.ring();
  O5D_L4.ring();
  O4G_L2_DOT.ring();

  O4G_L4.ring();
  O5D_L4.ring();
  O5E_L4.ring();
  O5C_L2_DOT.ring();

  delay(3000);



}
