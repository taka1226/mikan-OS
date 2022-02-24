/**
* @file paging.hpp
*
* メモリページング用のプログラムを集めたファイル
*/

#pragma once

#include <cstddef>

/** @brief 静的に確保するページディレクトリの個数
*
* この定数は SetupIdentityPageMap で使用される
*/
const size_t kPageDirectoryCount = 64;

/** @brief 仮想アドレス = 物理アドレスとなるようにページテーブルを設定する
* 最終的に CR3 レジスタがページテーブルのポインタをさすようになる
*/
void SetupIdentityPageTable();
