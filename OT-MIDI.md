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

今回の話題はClaravox, Thereminiでも適用可（たぶん）
</details>


---
## OpenTheremin(OT)補足
- [OT内蔵の波形](https://twitter.com/hrsm/status/1635980539391016960)
- [Etherwaveの波形](https://twitter.com/hrsm/status/1634918884951363584)をオシロで
- [Wave Table Generator](https://www.gaudi.ch/WaveGenerator/)でお好みの波形を作成してファームウェア（FW）書込み
- CV出力（DC）に何かを繋ぐ：オシロ KORG [NTS-2](https://www.korg.com/jp/products/dj/nts_2/) | Bastle [KASTLE](https://umbrella-company.jp/bastl-instruments-kastle-v1.5.html) 
<!--LittleBits [SynthKit](https://www.littlebits-jp.com/synth-kit)-->
- ノイズ対策：アース(GND)接続以外にOTとケーブルで繋がっている機器（PCなど）のACアダプタに注意．バッテリ駆動が望ましい

---
## OTのMIDI出力追加

- MIDIインタフェース基板 XIAO [RP2040](https://www.switch-science.com/products/7634) を追加
- USB Type-C端子の採用 [before/after](https://twitter.com/hrsm/status/1635315290937638914) はんだ付け（結線3本）
- ケースを3Dプリントする
  - 3D-CAD [Fusion360](https://www.autodesk.co.jp/products/fusion-360/personal) （個人利用は無料）
  - オリジナル[by gaudi](https://www.thingiverse.com/thing:5022371)を元に
  - 基板を収めるためのケース [STL](https://github.com/nomargin/opentheremin-synth/blob/main/case/OTv4midi-case4.stl) 
  - [プリントセンター](https://make.dmm.com/mypage/orders/)入稿 （要会員登録）
  - 材料選択はピンキリ
    - [Resin A1 Pro](https://twitter.com/hrsm/status/1657014608954290177)(￥2700~) ただしモデルを[分割出力](https://twitter.com/hrsm/status/1650527816440762371)（あとで要接着）
    - エコノミーナイロン(￥6500~) 一体で出力
  - 担当者とモデル修正のやりとり (厚さ不足による反り、変形などの対応)
- FWの変更
  - [オリジナルFW](https://raw.githubusercontent.com/MrDham/OpenTheremin_V3_with_MIDI/master/Quick%20guide%20open%20theremin%20midi.bmp) を元にMIDI出力対応の変更 
  - fw/OT4_midi_PV14 : 本体側のUSB端子から書き込み
  - fw/midi_fwd : RP2040のUSB端子から書き込み

---
## MIDI出力に何かを繋ぐ

- テルミンの特徴を活かす（動作との同期、音を操っている感など）
- ポイント：滑らかな変化、高分解能（14bit）ピッチ/ボリューム、低遅延、リニアリティ（等間隔）
- MIDIデータを処理できるPCソフト（開発環境,DAW,プラグイン）,スマホアプリ
- オシレータ・エフェクトなどの部品，VST/AUプラグインのパラメータへの割り当て，スケール変換・レスポンスカーブ
- DAW連携：Apple Logic Pro X | Ableton Live など
- その他のパラメータ操作のためのコントローラ（演奏を邪魔しない）
  - Smart Ring [GENKI Wave Ring](https://genkiinstruments.com/products/wave) 
  - AppleWatch App [Holon.ist](https://holon.ist/sensors/)

---
## OT-PC-PureData(Pd)ほか
MIDIメッセージをお好みで料理する環境 
- [ここ](https://puredata.info/downloads/pure-data)からPd（フリー）をダウンロードしてPC(Win/Mac)にインストール
<!--| [Cycling'74 Max](https://cycling74.com/products/max) -->
<!-- https://twitter.com/hrsm/status/1434858040449064961 -->
- Pdと同類のソフト[Cycling74 Max](https://twitter.com/hrsm/status/1630948258364411905)での動作例
- 擦弦楽器： [過去の失敗作](https://twitter.com/hrsm/status/1256485884989300736)　からの物理モデリング音源の導入へ，弓動作の再現
- Ableton Live M4L [ピッチずれを可視化する](https://www.youtube.com/watch?v=sdA-xh-cczo) 
<!-- 両手でpitch haptic feedback-->
<!-- velocityの導入 -->

---
## OT-PC-Pd-NSX39
大人の科学[ポケット・ミク](https://otonanokagaku.net/nsx39/)に繋いでテルミンに（で）歌わせよう　
- PC(Win/Mac)にPdをインストールし、OTとNSX39をPCにUSB接続
- Pdを起動して、パッチファイル：pd/nsx-39.pdを開く
- MIDIポートの設定：Media > MIDI Settings...
  - Input = XIAO RP2040
  - Output = NSX-39
  - Save All Settings しておけば以降も設定有効
- Startを押すとカラオケ音源aiffとmidiファイルが同期再生．歌詞が１文字ごとミクに送信される
- OTでミクのピッチ・ボリュームをコントロールする
- [パッチの説明](pd/nsx-39.pdf)
- [サンプル曲](https://youtu.be/P2sz72szwRA)


## OT-{iPhone|Android}-Pd
スマホ上でも動作するPd環境 [mobmuplat](https://danieliglesia.com/mobmuplat/)
- AppStoreでアプリ[mobmuplat](https://apps.apple.com/jp/app/mobmuplat/id597679399) をインストール
- USBでPCとスマホを接続
- mobフォルダ以下のファイルをスマホのmobmuplat配下のフォルダにコピーしてケーブルを外す
- OTをスマホにUSB接続(iPhoneの場合Lightning-USB変換)し、アプリmobmuplat起動
- 設定 > Audio/MIDI >
  - Select MIDI Input = XIAO RP2040 
  - Audio Buffer Size = 32
  - Select Document > OT.mmp
- [開発環境](https://twitter.com/hrsm/status/1639640535337168896)
- [iPhoneで動作](https://twitter.com/hrsm/status/1632759321804279809)

## OT-PC-モジュラー（ソフト）シンセ
Virtual EuroRack Studio [VCV Rack2](https://vcvrack.com/Rack)
- Rack 2 Free版を[ここ](https://vcvrack.com/Rack#get)からダウンロード&インストール
- OTをPCに接続
- vcv/OTv4-PV14-B.vcvを開く （MIDIマッピング設定済み）
- [動作例](https://twitter.com/hrsm/status/1657545338763505664)

## OT-{iPhone|iPad}アプリ
- [moog Model 15](https://apps.apple.com/jp/app/model-15-modular-synthesizer/id1041465860) 
- [miRack](https://apps.apple.com/jp/app/mirack/id1468259834) VCV Rackと同様のモジュラーシンセ
- AppStoreでアプリをインストール
- OTとUSB接続
- アプリ起動
- MIDI In設定：14bit CCをお好みのノブに割り当てる
  - ピッチ：CC#16-48
  - ボリューム：CC#7-39

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
- MIDIで手軽に外部連携していろいろ遊べる（CVよりも料理しやすい）
- パラメータ操作で演者の手が足りない問題
自力（コントローラ追加・ハンドジェスチャ認識）/ DAWのシーケンス援用 / 他の誰か　など

### 今回使用したファイル
- 置き場所 [github](https://github.com/nomargin/opentheremin-synth)
- 緑のボタン(Code) を押す．Download ZIPで丸ごとローカルに保存
