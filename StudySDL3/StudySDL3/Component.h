#pragma once
class Component {
	public:
		// ������ ����� ���� ���� ��������, ������Ʈ �켱������ �α� ���� updateOrder�� �߰��մϴ�.
		Component(class Actor* owner, int updateOrder = 100);	
		~Component();

		virtual void Update(float deltaTime);				// ������Ʈ
	
		int GetUpdateOrder() const { return mUpdateOrder; }	// ������Ʈ ���� ��ȯ

	public:
		class Actor* GetOwner()const { return mOwner; }

	private:
		class Actor* mOwner;								// �ش� ������Ʈ�� ���� ����
		int mUpdateOrder;									// �켱 ������ �ξ�, ���� ������ �����մϴ�.
};

