/*
 * AudSig.cpp - Library for Auditory signals.
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

// #include "Arduino.h"
#include <stdarg.h>
#include "AudSig.h"

AudSig::AudSig(int buzz_pin, ...) {
  this->buzz_pin = buzz_pin;   // ブザーのピン番号を設定する。
  // 第2引数以降の報知音のOn/Offパターンの読み込みを開始する。
  int i;
  int patternData = (sizeof pattern / sizeof pattern[0]) - 1;
  va_list vl;
  va_start(vl, buzz_pin);
  for (i = 0; i < patternData; i++) {
    pattern[i] = (unsigned long)va_arg(vl, int);
    if (0 == pattern[i]) {
    	// 報知音パターンデータの終端を示す番兵(sentinel)としての '0' を検出したら、ここで読み込みを完了する。
      break;
    }
  }
  va_end(vl);
	// 以下は、万が一、番兵(sentinel)としての '0' がなかった場合のための予防処置
  i++;
  pattern[i] = 0;
  this->size = i;
}



void AudSig::begin() {
	// ブザーのピンモードを出力用に設定する。
  pinMode(this->buzz_pin, OUTPUT);
}

void AudSig::setFrequency(int freq) {
	// 報知音の周波数をデフォルト値以外に設定する場合に使用する。
  this->frequency = (unsigned int)freq; 
}

void AudSig::ring() {
	// 報知音のOn/Offパターンに従って、ブザーを鳴らす。
  for (int i = 0; i < this->size; i++) {
    if (0 == pattern[i]) {
      noTone(this->buzz_pin);
      break;
    }
    if (0 == (i % 2)) {
      tone(this->buzz_pin, this->frequency, pattern[i]);
      delay(pattern[i]);
    } else {
      noTone(this->buzz_pin);
      delay(pattern[i]);
    }
  }
  noTone(this->buzz_pin);
}
