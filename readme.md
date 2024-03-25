# AudSig

Arduino library to Auditory signals for elderly and disabled consumer products.  
高齢者・障害者に配慮した消費生活製品の報知音を再生するライブラリ  

## Description	説明

This is a Arduino sound library Auditory signals for elderly and disabled consumer products.  
このライブラリは、以下の規格に準拠した報知音を再生するために、試験的に作成したものである。  

> JIS S 0013:2022  
> アクセシブルデザインー消費生活用製品の報知音  
> Accessible design -- Auditory signals for consumer products  

JIS S 0013:2022は、高齢者や障害者にも聞き取りやすい報知音を生成するための指針が書かれている。  
我々が、日常生活でよく聴いている以下のような家電製品の報知音は、この規格に基づき、デザインされている。  

* 洗濯機の蓋が開いた状態であることを知らせる報知音
* 過加熱のため，電気オーブンが加熱を中止したことを知らせる報知音
* 複写機の紙切れの報知音又はトナー切れの報知音
* タイマーの終了音
* etc

JISで規定されたと聞くと難しいものと思われるかもしれないが、配慮すべきは、以下の2点だけである。  

* 音の高さ(周波数)は，聴力の衰えた高齢者にも聞き取りやすいよう，2KHz近傍にすることが望ましい。
* 用途・目的に応じ、例示されたon/offパターンに従って対象の報知音を再生する。

定義された報知音は、以下のように分類されており、28種類のパターンがある。  

* 操作受付音	Operation reception signal  
	1. 受付・スタート音	reception and start signal  
	2. 停止音	stop signal  
	3. 基点音	starting position signal  
* 操作無効音	Operation invalid signal  
	4. 受付無効音	reception invalid signal  
	5. 作業不備音	incomplete work signal  
* 終了音	End signal  
	6. 終了音（遠）	end far signal  
	7. 終了音（近）	end near signal  
* 注意音	Caution signal  
	8. 弱注意音	weak caution signal  
	9. 強注意音	strong caution signal  

## Development environment	開発環境  

以下のIDEとデバイスで実装および検証を行った。  

* [Arduino IDE](https://www.arduino.cc/en/software)
	Ver. 2.3.2で検証を行った。  
* Arduino 或いはその互換マイコンボードにブザー素子を取り付けたもの  
	今回は、[cytron](https://www.cytron.io/)社の以下の製品を使用した。
	CPUは、Raspberry Pi財団が独自に開発したARM Cortex M0+デュアルコアのRP2040が搭載されている。  
	GPIO 22番ピンに圧電ブザーが接続されている。  
	Maker Nano RP2040: Simplifying Projects with Raspberry Pi RP2040  
	https://www.cytron.io/c-development-tools/c-maker-series/p-maker-nano-rp2040-simplifying-projects-with-raspberry-pi-rp2040

## Setup	導入方法

IDEにライブラリをインストールしない場合は、以下の2つのファイルをArduinoのソースコード.inoファイルと同じディレクトリにコピーしてからコンパイルする。  

* AudSig.cpp
* AudSig.h

IDEにライブラリをインストールする場合は、次の手順で導入する。  

### Install the library	ライブラリのインストール

1. 以下のZipファイルをダウンロードし、ローカルのストレージに保管する。  
[AudSig_1.0.0.zip](dist/AudSig_1.0.0.zip)

2. Arduino IDEを起動し、メニューバーから、以下のサブメニューを辿り、事前にダウンロードしたZipファイルを導入する。  
* スケッチ
	- ライブラリーをインクルード
		- ZIP形式のライブラリーをインストール

## How to use	使い方

以下は、AudSigライブラリを使った最も簡単なサンプルである。  
これをもとにして、使用方法を解説する。  

```
#include "AudSig.h"   // 1. 報知音ライブラリをインクルードする。

AudSig starting_position(  22,  50,  50,  50,  0 );   // 2. コンストラクタを実行し、報知音オブジェクトを生成する。

void setup() {
  starting_position.begin(); // 3. 報知音オブジェクトを初期化する。
}

void loop() {
  starting_position.ring();  // 4. 報知音を再生する。
  delay(5000);               // 5秒間の休止
}
```

1. ヘッダファイルのインクルード  
	ソースコードの先頭部分で報知音ライブラリのヘッダファイル <AudSig.h> をインクルードする。  
2. コンストラクタを実行し、報知音オブジェクトを生成  
	コンストラクタの引数は、以下の通りである。  
	
	* 引数は、全て整数型のint  
	* 第1引数はブザーのピン番号  
	* 第2引数以降は、ミリ秒単位で報知音の再生バターンをon/offの繰り返しで指定する。  
	* 再生バターンの設定部分は、可変引数として定義してあるが、概ね30個以下にすること。  
	* データの終了を表す番兵(sentinel)として '0' を末尾に入れること。  

		AudSig starting_position(  22,  50,  50,  50,  0 );

	上記の例では、ブザーの接続先を22番ピンに指定し、報知音のパターンを50msOn、50msOff、50msOn、停止に設定している。  
	最後の '0' は、報知音のデータの終わりを示すsentinel(番兵)である。

3. 報知音オブジェクトの初期化  
	setup()関数内でbegin()関数を呼び出す。  	

4. 報知音の再生  
	ring() 関数を呼び出す。  

## examples	サンプル

examplesディレクトリ内のサンプルソースコードは、以下の通りである。  

* StartingPosition	基点音
* OperationReception	操作受付音
* OperationInvalid	操作無効音
* Caution	注意音
* End	終了音

* SOS	モールス符号による遭難信号
* Jihou	NHKの時報
* WestminsterChime	ウェストミンスターの鐘
* PC98_PiPo	国民機パソコン PC98の起動音

IDEにライブラリをインストールした場合は、メニューバーから、以下のように辿るとこれらのサンプルを開くことができる。  

* ファイル
	- スケッチ例
		- AudSig

## Trial listening	試聴

このライブラリを使う前に、報知音がどのような音かを聞いてみたいという要望があった。  
昔、報知音のサウンドファイルを生成するプログラムを作成していたので、それを整理して以下のリポジトリで公開した。

[JIS_S0013](https://github.com/triring/JIS_S0013)  

ここから、報知音のサウンドファイルをダウンロードし、試聴することが可能である。  

## References	参考文献

* [JIS S 0013:2022](https://webdesk.jsa.or.jp/books/W11M0090/index/?bunsyo_id=JIS+S+0013%3A2022)  
	アクセシブルデザインー消費生活用製品の報知音  
	Accessible design -- Auditory signals for consumer products  

* [家電製品における操作性向上のための報知音に関するガイドライン第2版［改訂］](https://www.aeha.or.jp/ud/pdf/ud_guideline_5.htm)  
2018年(平成30年)3月  
一般財団法人 家電製品協会 ユニバーサルデザイン技術委員会  

* [報知音推奨音 - JSA Webdesk](https://webdesk.jsa.or.jp/link/Cor/Setsumei/jis_s_00013_000_000_2022_Setsumei_1_2022.pdf)  

## License	ライセンス

[Poul-Henning Kamp](https://people.freebsd.org/%7Ephk/) 氏が提唱しているBEER-WAREライセンスを踏襲します。  

### "THE BEER-WARE LICENSE" (Revision 42):
<akio@triring.net> wrote this file. As long as you retain this notice you
can do whatever you want with this stuff. If we meet some day, and you think this stuff is worth it, you can buy me a beer in return.
Copyright (c) 2024 Akio MIWA @triring  

### "THE BEER-WARE LICENSE" (第42版):
このファイルは、<akio@triring.net> が書きました。あなたがこの条文を載せている限り、あなたはソフトウェアをどのようにでも扱うことができます。
もし、いつか私達が出会った時、あなたがこのソフトに価値があると感じたなら、見返りとして私にビールを奢ることができます。  
Copyright (c) 2024 Akio MIWA @triring  

