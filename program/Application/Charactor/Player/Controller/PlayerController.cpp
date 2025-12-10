#include "Application/Charactor/Player/Controller/PlayerController.hpp"
#include "System/Input/Key.hpp"

Math::Point Player::Controller::GetInputVelocity()
{
    //  キー入力があるときだけ
    if (_kbhit())
    {
        auto input = Input::GetKey();
        switch (input.code)
        {
            //  上
        case Input::KeyCode::ArrowUp:
            return Math::Point::Up;

            //  左
        case Input::KeyCode::ArrowLeft:
            return Math::Point::Left;

            //  下
        case Input::KeyCode::ArrowDown:
            return Math::Point::Down;

            //  右
        case Input::KeyCode::ArrowRight:
            return Math::Point::Right;

            //  移動キー以外
        default:
            return Math::Point(0, 0);
            break;
        }
    }
}
