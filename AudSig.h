/*
 * AudSig.h - Library for Auditory signals.
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

#ifndef AudSig_h
#define AudSig_h
#include <stdarg.h>
#include "Arduino.h"

class AudSig {
public:
  AudSig(int pin, ...); // コンストラクタ 
  /*
  引数は、全て整数型のint
  第1引数はブザーのピン番号
  第2引数以降は、ミリ秒単位で報知音の再生バターンをon/offの繰り返しで指定する。
  再生バターンの設定部分は、可変引数として定義してあるが、概ね30個以下にすること。
  また、データの終わりを示すsentinel(番兵)として '0' を末尾に入れること。
  */
  void begin(); // コンストラクタを初期化する。ピンモードの設定
  void setFrequency(int freq); // 発振周波数を設定する。
  void ring();  // 報知音を鳴らす。
private:
  int buzz_pin = 22;   // 圧電ブザーを接続しているピン番号
  int size; // 信号データの数
  // JIS S 0013 では報知音の周波数を2kHz近傍と規定しているので、
  // 純正律の中で、周波数が最も近い シ/B6(1980Hz)に設定する。
  unsigned int frequency = 1980;  // Ringing frequency 報知音の周波数
  unsigned long pattern[32];      // 再生パターンを保存する配列。使用時はデータの最後に番兵(sentinel)として0を追加すること。
};

#endif
