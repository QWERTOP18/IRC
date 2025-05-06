## coding の際に気をつけてること

### 命名規則
m_snake_case member of Class
m_UPPER container member 
t_ argument
k_ constant value


### Error Message
Error Messageは名前空間で区切ってすべてヘッダーに書く



### Classの責務
なるべくネストしない
今回の場合だとServer -> Parser -> Command
という順番だけどParserはあくまでCommandのポインタを返すだけで発火するのはServerの仕事(ポインタで返すことで、ServerがCommandが何かを意識しなくてもいいようになっている)