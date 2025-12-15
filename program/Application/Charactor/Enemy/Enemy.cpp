#include "Enemy.h"

void Chara::Enemy::Attack(Chara::CharaBase& target, int damage)
{

	// 対象が死亡していたら処理しない
	if(target.IsDead())
	{
		return;
	}

	// ダメージ適用
	target.ApplyDamage(damage);

}

