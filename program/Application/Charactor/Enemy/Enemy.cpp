#include "Enemy.h"

void Chara::Enemy::Attack(Chara::CharaBase& target)
{

	// 対象が死亡していたら処理しない
	if(target.IsDead())
	{
		return;
	}

	// ダメージ計算処理
	int damage = this->GetAttack() - target.GetDefence();

	// ダメージ適用
	target.ApplyDamage(damage);

}

