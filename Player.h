#pragma once
#include "math/Vector2.h"

using namespace KamataEngine;

//�v���C���[
class Player {

private:

	// �ʒu
	Vector2 position_;

	// ����
	float speed_ = 2.0f;

public:

	void Initialize();

	void Update();

	void Draw();

	/// �E�ړ�
	void MoveRight();

	/// ���ړ�
	void MoveLeft();
};