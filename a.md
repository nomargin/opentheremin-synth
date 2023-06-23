# テルミンのMIDI活用事例

（適宜、デモ＆試奏を交えて）

## 導入
<details>
<summary></summary>

- 動機：John Cageのテルミン奏者dis
- 狙い：音色やエフェクトのコントロール、音以外も含めた多様な表現のために
- CV出力、MIDI出力を備えたテルミン（メジャーなもの）
<details>
<summary>table</summary>

||model|CV out|MIDI out|
|--|--|--|--|
|moog|Claravox Centennial|O  (Pitch,Vol)|O|
|moog|Theremini|O  (Pitch *or*  Vol)|O|
|moog|Ehterwave (new, Plus)|O   (Pitch,Vol,Gate)|-|
|GaudiLabs|OpenTheremin|O  (Pitch,Vol)|△|
</details>

---

</details>

## OpenTheremin(OT)補足
<details>
<summary></summary>

- Etherwaveの波形取込み＆差し替え
- https://twitter.com/hrsm/status/1635980539391016960
- https://twitter.com/hrsm/status/1634918884951363584
- CV出力に何かを繋ぐ
[KORG NTS-2](https://www.korg.com/jp/products/dj/nts_2/) | 
[Bastle KASTLE](https://umbrella-company.jp/bastl-instruments-kastle-v1.5.html) | 
[LittleBits SynthKit](https://www.littlebits-jp.com/synth-kit)
</details>

## OTのMIDI拡張例
<details>
<summary></summary>

- MIDIインタフェース基板追加 
[Seeed Studio XIAO RP2040](https://www.switch-science.com/products/7634)
- ケースの3Dプリント 
[STL](https://github.com/nomargin/opentheremin-synth/blob/main/case/OTv4midi-case4.stl) | 材料=Resin A1 Pro, エコノミーナイロン | [発注](https://make.dmm.com/mypage/orders/)
- https://twitter.com/hrsm/status/1657014608954290177
- ファームウェア入れ替え

- https://twitter.com/hrsm/status/1635315290937638914
- 
</details>


## MIDI出力に何かを繋ぐ
<details>
<summary></summary>

- MIDIメッセージ、PITCH/VOLUMEデータのアサイン
- その他のパラメータ追加
- 演奏中のパラメータ変更 gamepad | smartRing
</details>

## OT-PC-PureData(Pd), Max
[Pd](https://puredata.info/downloads/pure-data) | 
[Cycling'74 Max](https://cycling74.com/products/max)

- https://twitter.com/hrsm/status/1434858040449064961
- https://twitter.com/hrsm/status/1630948258364411905
- https://twitter.com/hrsm/status/1634918884951363584

- 両手でPITCH
- VOLコントロールをパーカッシブに
- velocity導入


## OT-スマホ-Pd
[mobmuplat](https://danieliglesia.com/mobmuplat/)

## OT-PC-ソフトシンセ
[VCV Rack2](https://vcvrack.com/Rack)

## OT-iPhone/iPad-シンセアプリ
[moog Model 15](https://apps.apple.com/jp/app/model-15-modular-synthesizer/id1041465860) | 
[miRack](https://mirack.app/)

## OT-PC-DAW(Garageband,Logic,Live ..)

*** 
以下、番外編（未定）

## OT-PC-Visual系の何か(お絵描き)
[Processing](https://processing.org/)
- 文字を書いてみよう

## OT-PC-ロボット系の何か
[Sony toio](https://toio.io/programming/#28) | 
[DJI Tello](https://www.ryzerobotics.com/jp/tello-edu)

## OT-PC-(wifi/ws)-スマホのWebブラウザ上のシンセ（複数台）

***

## 今回使用したファイル
- 置き場所 [github](https://github.com/nomargin/opentheremin-synth)
- Pd, Maxパッチ
- Arduino ファームウェア
- ケースの3Dデータ (STL)


