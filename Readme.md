#IRC

[RFC 1459 - Internet Relay Chat Protocol](https://tools.ietf.org/html/rfc1459)

## coding の際に気をつけてること

### 命名規則

m*snake_case member of Class
m_UPPER container member
t* argument
k\_ constant value

### Error Message

Error Message は名前空間で区切ってすべてヘッダーに書く

### Class の責務

なるべくネストしない
今回の場合だと Server -> Parser -> Command
という順番だけど Parser はあくまで Command のポインタを返すだけで発火するのは Server の仕事(ポインタで返すことで、Server が Command が何かを意識しなくてもいいようになっている)
