# irssi の使い方まとめ

## インストール

```bash
# Debian/Ubuntu系
sudo apt install irssi

# macOS (Homebrew)
brew install irssi
```

## 起動

```bash
irssi
```

---

## IRC サーバーへの接続

```bash
/connect <サーバー名> <ポート> -ssl
# 例:
# /connect irc.libera.chat 6697 -ssl
```

ユーザー情報の設定:

```bash
/set nick <ニックネーム>
/set user_name <ユーザー名>
/set real_name <本名（任意）>
```

---

## チャンネルに参加・退出

```bash
/join #チャンネル名
/part #チャンネル名
```

---

## メッセージ送信

- **チャンネル内で送信**:
  そのままメッセージを打って Enter。

- **個人メッセージ（PM）**:

  ```bash
  /msg <ニックネーム> メッセージ内容
  ```

---

## ウィンドウ操作（チャンネル切り替え）

| 操作               | キー                                   |
| ------------------ | -------------------------------------- |
| 次のウィンドウ     | `Ctrl + n`                             |
| 前のウィンドウ     | `Ctrl + p`                             |
| ウィンドウ番号へ   | `Alt + <数字>` または `Esc` → `<数字>` |
| ウィンドウを閉じる | `/close` または `/part`                |

---

## ウィンドウ・チャンネルの管理

```bash
/window list           # ウィンドウ一覧表示
/window close          # 現在のウィンドウを閉じる
```

---

## ログ記録

ログを保存するには以下を設定:

```bash
/set autolog on
/set log_dir ~/irclogs/
```

---

## カスタマイズ・設定保存

設定を保存:

```bash
/save
```

テーマやキーバインド変更も可能（詳細は公式ドキュメント参照）。

---

## 終了

```bash
/quit
```

---

## よく使うコマンドまとめ

| コマンド   | 説明               |
| ---------- | ------------------ |
| `/connect` | IRC サーバーに接続 |
| `/join`    | チャンネルに入る   |
| `/part`    | チャンネルから退出 |
| `/msg`     | 個別メッセージ送信 |
| `/quit`    | irssi の終了       |
| `/window`  | ウィンドウ操作関連 |
| `/set`     | 設定変更           |
| `/save`    | 設定保存           |

---

## 参考リンク

- [irssi 公式サイト](https://irssi.org/)
- `man irssi`（ターミナルで使えるマニュアル）
