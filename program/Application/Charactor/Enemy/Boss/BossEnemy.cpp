#include "BossEnemy.h"

void Chara::BossEnemy::Attack(Chara::CharaBase& target)
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

void Chara::BossEnemy::FireBreath(Chara::CharaBase& target)
{
	// 対象が死亡していたら処理しない
	if(target.IsDead())
	{
		return;
	}

	// ダメージ計算処理（炎の息吹は魔法攻撃力を使用する）
	int damage = this->GetMagicAttack() - target.GetDefence();

	// ダメージ適用（魔法攻撃力を使用）
	target.ApplyDamage(this->GetMagicAttack());
}