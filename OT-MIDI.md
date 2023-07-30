<!---
marp: true
theme: gaia
footer:"tes"
--->
# テルミンのMIDI活用事例
---
## 導入
<details>
<summary></summary>

- 動機：John Cageのテルミニストdis (1937,[出典](https://archive.org/details/silencelecturesw1961cage/page/4/mode/2up?q=Theremin))
<!--
テルミン博士が真に新しい可能性を持つ楽器を提供したにもかかわらず、
テルミニストはこの楽器を古い楽器のように聴かせることに全力を尽くし、
気持ち悪いほど甘〜いビブラートをかけ、過去の名作を苦労して演奏している。
テルミニスト＝検閲官によって、私たちは新しい音の体験から遮られている。
-->
---

- 狙い：音色やエフェクトの柔軟なコントロール、外部連携、音以外も含めた多様な表現のために

CV出力、MIDI出力を備えた（主な）テルミン

||model|CV out|MIDI out|
|--|--|--|--|
|moog|Claravox Centennial|O  (Pitch,Vol)|O|
|moog|Etherwave (new, Plus)|O   (Pitch,Vol,Gate)|-|
|moog|Theremini|O  (Pitch __or__  Vol)|O|
|**GaudiLabs**|**OpenTheremin**|O  (Pitch,Vol)|△|

</details>

---
## OpenTheremin(OT)補足
- [OT内蔵の波形](https://twitter.com/hrsm/status/1635980539391016960)
- Audio出力→オシロ表示
- [Wave Table Generator](https://www.gaudi.ch/WaveGenerator/)でお好みの波形を作成
- [Etherwaveの波形](https://twitter.com/hrsm/status/1634918884951363584)
- 波形差し替え&ファームウェア（FW）書き込み
- CV出力→オシロ表示、その他何かをつなぐ

オシロ KORG [NTS-2](https://www.korg.com/jp/products/dj/nts_2/) |
Bastle [KASTLE](https://umbrella-company.jp/bastl-instruments-kastle-v1.5.html) | 
<!--LittleBits [SynthKit](https://www.littlebits-jp.com/synth-kit)-->
- ノイズ対策

---
## OTのMIDI出力追加


- MIDIインタフェース基板 XIAO [RP2040](https://www.switch-science.com/products/7634) + FW(fw02if)
- [before/after](https://twitter.com/hrsm/status/1635315290937638914)
- ケースの3Dプリント 
オリジナル[by gaudi](https://www.thingiverse.com/thing:5022371) | 3D-CAD [Fusion360](https://www.autodesk.co.jp/products/fusion-360/personal) | MIDI対応ケース [STL](https://github.com/nomargin/opentheremin-synth/blob/main/case/OTv4midi-case4.stl) | 材料選択 [Resin A1 Pro](https://twitter.com/hrsm/status/1657014608954290177), エコノミーナイロン | [発注](https://make.dmm.com/mypage/orders/) ~ モデル修正のやりとり 
- FWの変更 
[オリジナル](https://raw.githubusercontent.com/MrDham/OpenTheremin_V3_with_MIDI/master/Quick%20guide%20open%20theremin%20midi.bmp) 
fw/OT4_midi_PV14: 本体側のUSB端子から書き込み
fw/midi_fwd: RP2040のUSB端子から書き込み

---
## MIDI出力に何かを繋ぐ

- テルミンの特徴を活かす（動作との同期、音を操っている感）
- pitch,volデータのアサイン
- その他のパラメータのコントロール
- 演奏中の操作のために 
GamePad [8BitDo Zero2](https://www.8bitdo.com/zero2/) 
Smart Ring [GENKI Wave Ring](https://twitter.com/hrsm/status/1510962165749981188) 
AppleWatch App [Holon.ist](https://holon.ist/sensors/)

---
## OT-PC-PureData(Pd), Max
[Pd](https://puredata.info/downloads/pure-data) | [Cycling'74 Max](https://cycling74.com/products/max)


<!-- https://twitter.com/hrsm/status/1434858040449064961 -->
- https://twitter.com/hrsm/status/1630948258364411905
- エフェクト：リバーブ・ディレイ、フィルタ、サンプラー
- vol/pitchカーブを変える 
<!-- velocityの導入 -->
- [pitchズレの可視化](https://www.youtube.com/watch?v=sdA-xh-cczo) 
- 擦弦楽器 [過去の失敗作](https://twitter.com/hrsm/status/1256485884989300736)　から物理モデリング導入へ
<!-- 両手でpitch 
haptic feedback-->

---
## OT-PC-Pd-NSX39
大人の科学[ポケット・ミク](https://otonanokagaku.net/nsx39/)に繋いでテルミンに歌わせよう
歌詞情報の同期再生
[サンプル曲](https://youtu.be/P2sz72szwRA)

## OT-{iPhone|Android}-Pd
スマホで動作するPd環境 [mobmuplat](https://danieliglesia.com/mobmuplat/)

## OT-PC-ソフトシンセ
Virtual EuroRack Studio [VCV Rack2](https://vcvrack.com/Rack)

## OT-{iPhone|iPad}アプリ
[moog Model 15](https://apps.apple.com/jp/app/model-15-modular-synthesizer/id1041465860) | 
[miRack](https://mirack.app/)

## OT-PC-DAW
Apple Logic Pro X | Ableton Live

*** 
以下、番外編（未定）

## OT-PC-Visual系の何か
[Processing](https://processing.org/)
お絵描き・文字を書いてみよう

## OT-PC-ロボット系の何かを動かそう
[Sony toio](https://toio.io/programming/#28) | 
ミニドローン [DJI Tello](https://www.ryzerobotics.com/jp/tello-edu)

## OT-PC~~スマホのWebブラウザ上のシンセ
WiFi経由で演奏情報を配信してみよう

***

## まとめ
- デジタルな演奏データの活用、外部連携
- 手が足りない問題：自力（コントローラ追加・ジェスチャ認識）/DAWのシーケンス援用/他の誰か　によるパラメータ操作

### 今回使用したファイルの置き場所 [github](https://github.com/nomargin/opentheremin-synth)