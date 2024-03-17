/*
 * End.ino - Example for Auditory signals Library.
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

// 終了音	End signal
// 終了音（遠）1	end far signal  オブジェクトの生成
AudSig end_far1(BUZZER_PIN, 300, 500, 300, 500, 300, 500, 300, 0);
// 終了音（遠）2	end far signal  オブジェクトの生成
AudSig end_far2(BUZZER_PIN, 500, 800, 500, 800, 500, 800, 1500, 0);
// 終了音（遠）3	end far signal  オブジェクトの生成
AudSig end_far3(BUZZER_PIN, 500, 800, 500, 800, 500, 800, 500, 800, 1500, 0);
// 終了音（遠）4	end far signal  オブジェクトの生成
AudSig end_far4(BUZZER_PIN, 100, 100, 500, 500, 100, 100, 500, 500, 100, 100, 500, 500, 100, 100, 500, 500, 0);

// 終了音（近）1	end near signal オブジェクトの生成
AudSig end_near1(BUZZER_PIN, 800, 0);
// 終了音（近）2	end near signal オブジェクトの生成
AudSig end_near2(BUZZER_PIN, 100, 500, 100, 500, 100, 500, 800, 0);

void setup() {
  // begin()でピンモードの設定を行う。
  end_far1.begin();   // 終了音（遠）1 の初期設定
  end_far2.begin();   // 終了音（遠）2 の初期設定
  end_far3.begin();   // 終了音（遠）3 の初期設定
  end_far4.begin();   // 終了音（遠）4 の初期設定
  end_near1.begin();  // 終了音（近）1	の初期設定
  end_near2.begin();  // 終了音（近）2	の初期設定
}

void loop() {
  end_far1.ring();   // 終了音（遠）1 の再生
  delay(5000);       // 5秒間の休止
  end_far2.ring();   // 終了音（遠）2 の再生
  delay(5000);       // 5秒間の休止
  end_far3.ring();   // 終了音（遠）3 の再生
  delay(5000);       // 5秒間の休止
  end_far4.ring();   // 終了音（遠）4 の再生
  delay(5000);       // 5秒間の休止
  end_near1.ring();  // 終了音（近）1	の再生
  delay(5000);       // 5秒間の休止
  end_near2.ring();  // 終了音（近）2	の再生
  delay(5000);       // 5秒間の休止
}
