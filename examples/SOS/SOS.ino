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
 * SOS	モールス符号による遭難信号
 * これは、報知音Caution signal ではないが、このAudSigの応用例として作成した。
 * モールス信号の仕様
 * 短点の長さを１とする。今回は、100ms
 * 長点の長さは、短点３点分。
 * 一つの符号を作る長点や短点との間隔は、短点１点分
 * 符号間は３短点分、単語間は７短点分空ける
 ***********************************************************
 * 諸説あるが、SOSの由来は、以下のような3単語の文の頭文字と言われてる。
 * "Save Our Ship"（我が船を救え）
 * "Send Out Succor"（救援の送信）
 * "Suspend Other Service"（他の通信は沈黙せよ）
 */

#define DIT 100              // or dot  (.): "dit duration" is one time unit long
#define DAH DIT * 3          // or dash (-): three time units long
#define ELEMENT_GAP DIT      // inter-element gap between the dits and dahs within a character: one dot duration or one unit long
#define LETTERS_GAP DIT * 3  // three time units long
#define WORDS_GAP DIT * 7    // seven time units long

const int BUZZER_PIN = 22;  // ピエゾブザーの接続ピン番号

// アルファベット 'S' オブジェクトの生成
AudSig char_s(BUZZER_PIN, DIT, ELEMENT_GAP, DIT, ELEMENT_GAP, DIT, LETTERS_GAP, 0);
// アルファベット 'O' オブジェクトの生成
AudSig char_o(BUZZER_PIN, DAH, ELEMENT_GAP, DAH, ELEMENT_GAP, DAH, LETTERS_GAP, 0);

void setup() {
  // begin()でピンモードの設定を行う。
  char_s.begin();  // アルファベット 'S'(...) の初期設定
  char_o.begin();  // アルファベット 'O'(...) の初期設定
}

void loop() {
  char_s.ring();  // 'S'(...) の再生 Save
  delay(LETTERS_GAP);
  char_o.ring();  // 'O'(---) の再生 Our
  delay(LETTERS_GAP);
  char_s.ring();  // 'S'(...) の再生 Ship
  delay(WORDS_GAP);
}
