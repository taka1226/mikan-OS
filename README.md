## 設定ファイルを読み込む
```bash
source edksetup.sh
```

## qemu で実行する
```bash
$HOME/osbook/devenv/run_qemu.sh Loader.efi
```


## 実行ファイルをコピーする
```bash
cp /home/takahiro/edk2/Build/MikanLoaderX64/DEBUG_CLANG38/X64/Loader.efi $HOME/workspace/bin/Loader.efi
```

## quita 記事

Uefiで遊ぶ  https://qiita.com/tnishinaga/items/40755f414557faf45dcb


## miksn OS github
https://github.com/uchan-nos/mikanos/blob/osbook_day02b/MikanLoaderPkg/Main.c

## EDK II
- ドキュメント  https://github.com/tianocore/tianocore.github.io/wiki/EDK-II-Documents
