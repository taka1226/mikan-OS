/**
* @file window.hpp
*
* 表示領域を表す クラス
*/

#pragma once

#include <vector>
#include <optional>
#include "graphics.hpp"

class Window {
public:
    /** @brief WindowWriter は Window と関連付けられた PixelWriter を提供する
    */

    // #@@range_begin(windowwriter)
    class WindowWriter : public PixelWriter {
    public:
        WindowWriter(Window& window) : window_{window} {}
        /** @brief 指定された位置に指定された色を描く */
        virtual void Write(int x, int y, const PixelColor& c) override {
            window_.At(x, y) = c;
        }
        /** @brief 横幅を取得 */
        virtual int Width() const override { return window_.Width(); }
        /** @brief 高さを取得 */
        virtual int Height() const override { return window_.Height(); }
    private:
        Window& window_;
    };
    // #@@range_end(windowwriter)


    /** @brief 指定されたピクセル数の平面描画領域を作成する */
    Window(int width, int height);
    ~Window() = default;
    Window(const Window& rhs) = delete;
    Window& operator=(const Window& rhs) = delete;

    /** @brief 与えられた PixelWriter にこのウィンドウの表示領域を描画する
    *
    * @param writer 描画先
    * @param position writer の左上(基準点)
    */
    void DrawTo(PixelWriter& writer, Vector2D<int> position);

    /** @brief 透過色を設定する */
    void SetTransparentColor(std::optional<PixelColor> c);

    /** @brief このインスタンスに紐づいた WindowWriter を取得する */
    WindowWriter* Writer();

    /** @brief 指定した位置のピクセルを返す */
    PixelColor& At(int x, int y);

    /** @brief 指定した位置のピクセルを返す */
    const PixelColor& At(int x, int y) const;

    /** @brief 幅取得 */
    int Width() const;

    /** @brief 高さ取得 */
    int Height() const;

private:
    int width_, height_;
    std::vector<std::vector<PixelColor>> data_{};
    WindowWriter writer_{*this};
    std::optional<PixelColor> transparent_color_{std::nullopt};

};
