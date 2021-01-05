#pragma once

class Player {
public:
	int HP;

public:
	Player();
	void setHp(int HP);
	int getHp();
	void Player::resetDamage();
};

