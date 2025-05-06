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
```

```sh
nc localhost <port>
```

## coding の際に気をつけてること

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
