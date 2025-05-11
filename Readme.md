# IRC

[notion](https://www.notion.so/IRC-1e9d2242f53b8028ac3ccb5b460fbc9a)

## setup

```sh
make
./IRC <port> <password>
```

## client

```sh
brew install irssi nc
/connect -ssl irc.libera.chat 6697
```
[how to use irssi](./DOCS/irssi.md)

```sh
nc localhost <port>
```

## test

```sh
# 特定のテストファイルを実行
./test_irc "--gtest_filter=ModelTest.*"

# 特定のテストケースを実行
./test_irc "--gtest_filter=ModelClientTests.*"

# 特定のテストを実行
./test_irc "--gtest_filter=ModelTest.AddClient_Success"
```

## coding の際に気をつけてること

### 副作用

#### IOもテストがしたい

LOGはTestしなくてもいい出力の時に使う。DEBUG_LOGはmake debugで実行した時のみ出力される。
Clientに送るレスポンスは最低限statusだけでもテストがしたい。

> :kotaro!user@localhost JOIN :#test
> :localhost 332 kotaro #test :チャンネルのトピック
> :localhost 353 kotaro = #test :kotaro
> :localhost 366 kotaro #test :End of /NAMES list.

#### buffering

IOをテストするためにもbufferingをしているが、パーサーなどがbufferにアクセスする際にどうしても変更を加えてしまう

### 命名規則

```
m*snake_case member of Class
m_UPPER container member
t* argument
k\_ constant value

```

[detail](https://www.notion.so/coding-1e4d2242f53b80b98125cdce66dd2b6f)

### Error Message

[RFC1459](https://datatracker.ietf.org/doc/html/rfc1459#section-4.1.1)

Error Message は名前空間で区切ってすべてヘッダーに書く

### Class の責務

なるべくネストしない
今回の場合だと Server -> Parser -> Command -> Client Channel
という順番だけど Parser はあくまで Command のポインタを返すだけで発火するのは Server の仕事(ポインタで返すことで、Server が Command が何かを意識しなくてもいいようになっている)

流れを補足すると
Server がポーリングしていて（ClientList を継承した Poll クラスの責務）、Client からのインプットがあったら Parser にわたし、改行があれば Command のポインタが返ってくるので、Serverが発火。
Commandは、種類によってClient, Channelクラスのメソッドを使用する。例えばKickだったらChannelクラスのKickメソッド->ChannelのClientListからClientを削除

```

```
