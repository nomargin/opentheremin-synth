# テルミンのMIDI活用事例

（適宜、デモ＆試奏を交えて）

## 導入
<details>
<summary></summary>

- 動機：John Cageのテルミニストdis
(1937,[出典](https://archive.org/details/silencelecturesw1961cage/page/4/mode/2up?q=Theremin))
<!--
テルミン博士が真に新しい可能性を持つ楽器を提供したにもかかわらず、
テルミニストはこの楽器を古い楽器のように聴かせることに全力を尽くし、
気持ち悪いほど甘〜いビブラートをかけ、過去の名作を苦労して演奏している。
テルミニスト＝検閲官によって、私たちは新しい音の体験から遮られている。
-->

- 狙い：音色やエフェクトの柔軟なコントロール、外部連携、音以外も含めた多様な表現のために
<details>
<summary>CV出力、MIDI出力を備えた（主な）テルミン</summary>

||model|CV out|MIDI out|
|--|--|--|--|
|moog|Claravox Centennial|O  (Pitch,Vol)|O|
|moog|Etherwave (new, Plus)|O   (Pitch,Vol,Gate)|-|
|moog|Theremini|O  (Pitch __or__  Vol)|O|
|GaudiLabs|OpenTheremin|O  (Pitch,Vol)|△|
</details>

---

</details>

## OpenTheremin(OT)補足
<details>
<summary></summary>

- OT内蔵の波形 https://twitter.com/hrsm/status/1635980539391016960
- EWの波形をオシロ表示 https://twitter.com/hrsm/status/1634918884951363584
- Etherwaveの波形取込み＆差し替え、ファームウェア（FW）書き込み　[fw01]
- CV出力とは、オシロ表示
- CV出力に何かを繋ぐ
[KORG NTS-2](https://www.korg.com/jp/products/dj/nts_2/) | 
[Bastle KASTLE](https://umbrella-company.jp/bastl-instruments-kastle-v1.5.html) | 
[LittleBits SynthKit](https://www.littlebits-jp.com/synth-kit)
</details>

## OTのMIDI拡張例
<details>
<summary></summary>

- MIDIインタフェース基板追加+はんだ付け
[XIAO RP2040](https://www.switch-science.com/products/7634) | 
[before/after](https://twitter.com/hrsm/status/1635315290937638914)
- ケースの3Dプリント 
[CAD](https://www.autodesk.co.jp/products/fusion-360/personal) | 
[STL](https://github.com/nomargin/opentheremin-synth/blob/main/case/OTv4midi-case4.stl) | 
材料=[Resin A1 Pro](https://twitter.com/hrsm/status/1657014608954290177), 
エコノミーナイロン | 
[発注](https://make.dmm.com/mypage/orders/)
- ファームウェア入れ替え
 
</details>


## MIDI出力に何かを繋ぐ
<details>
<summary></summary>

- テルミンの特徴を活かす
- PITCH,VOLデータのアサイン
- その他のパラメータ追加
- 演奏中の操作 GamePad | GENKI Wave Ring | AppleWatch
</details>

## OT-PC-PureData(Pd), Max
[Pd](https://puredata.info/downloads/pure-data) | 
[Cycling'74 Max](https://cycling74.com/products/max)

<!-- https://twitter.com/hrsm/status/1434858040449064961 -->
- https://twitter.com/hrsm/status/1630948258364411905

- velocity導入
- VOLカーブを変える
- PITCHずれの可視化
- 両手でPITCH
- haptic feedback


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

### 今回使用したファイルの置き場所 [github](https://github.com/nomargin/opentheremin-synth)

