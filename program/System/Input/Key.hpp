#pragma once
#include<conio.h>

namespace Input
{
	enum class KeyCode
	{
        // シングルコード系
        Escape = 27,
        Enter = 13,

        // 特殊キーの先頭
        SpecialPrefix = 224,

        //  数字キー
        Num0 = '0',
        Num1 = '1',
        Num2 = '2',
        Num3 = '3',
        Num4 = '4',
        Num5 = '5',
        Num6 = '6',
        Num7 = '7',
        Num8 = '8',
        Num9 = '9',

        // 特殊キー本体
        ArrowUp = 72,
        ArrowDown = 80,
        ArrowLeft = 75,
        ArrowRight = 77,
	};

    /// <summary>
    /// 特殊キーか判定と何が押されたかどうか判定するメソッド
    /// </summary>
    struct KeyInput
    {
        bool isSpecial = false;
        KeyCode code = KeyCode::Enter;
    };

    /// <summary>
    /// キー取得
    /// </summary>
    /// <returns></returns>
    inline KeyInput GetKey()
    {
        int key = _getch();

        //  特殊キー判定
        if (key == static_cast<int>(KeyCode::SpecialPrefix))
        {
            int ext = _getch();
            return KeyInput(true, static_cast<KeyCode>(ext));
        }

        //  通常キー
        return KeyInput(false, static_cast<KeyCode>(key));
    }

}

