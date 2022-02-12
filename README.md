## 設定ファイルを読み込む
```bash
source edksetup.sh
```

## qemu で実行する
```bash
$HOME/osbook/devenv/run_qemu.sh Loader.efi

$HOME/osbook/devenv/run_qemu.sh Build/MikanLoaderX64/DEBUG_CLANG38/X64/Loader.efi $HOME/workspace/mikanos/kernel/kernel.elf
```


## 実行ファイルをコピーする
```bash
cp /home/takahiro/edk2/Build/MikanLoaderX64/DEBUG_CLANG38/X64/Loader.efi $HOME/workspace/bin/Loader.efi
```

## kernel の コンパイル・リンク

```bash
source $HOME/osbook/devenv/buildenv.sh

clang++ $CPPFLAGS -O2 --target=x86_64-elf -fno-exceptions -ffreestanding -c main.cpp

ld.lld $LDFLAGS --entry KernelMain -z norelro --image-base 0x100000 --static -z separate-code -o kernel.elf main.o
```

> 必ずホストOSでコンパイル・リンクを行うこと(virtual box の方ではなく)

## quita 記事

Uefiで遊ぶ  https://qiita.com/tnishinaga/items/40755f414557faf45dcb


## miksn OS github
https://github.com/uchan-nos/mikanos/blob/osbook_day02b/MikanLoaderPkg/Main.c

## EDK II
- ドキュメント  https://github.com/tianocore/tianocore.github.io/wiki/EDK-II-Documents


## 注意事項
- gBS->ExitBootServices の直前に Print() をはさんだだけでメモリを消費し、success exit できなくなるので注意
