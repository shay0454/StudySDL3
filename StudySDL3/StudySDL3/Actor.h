#pragma once
#include<vector>

class Actor {
	public:
		enum State {
			EActive, EPaused, EDead							// ������ ���¸� ����ϱ� ���� enum
		};
		// game�� ����� ����ϱ� ���� �Ű������� �����ɴϴ�.
		Actor(class Game* game);
		virtual ~Actor();

		void Update(float deltaTime);				// game���Լ� ���� ������Ʈ�� ���� �� �����ϱ� ���� �Լ��Դϴ�.
		void UpdateComponents(float deltaTime);		// ���Ͱ� ���� ������Ʈ���� ������Ʈ �մϴ�.
		virtual void UpdateActor(float deltaTime);	// ���� ��ü�� ������Ʈ �մϴ�.

	public:
		void AddComponent(class Component* component);		// ������Ʈ�� �߰��մϴ�.
		void RemoveComponent(class Component* component);	// ������Ʈ�� �����մϴ�.

		void SetState(State state) { mState = state; }		
		State GetState() const { return mState; }			

	private:
		State mState;										// ������ ���¿� ���� �۵��� �����ϱ� ���� ����մϴ�.
		std::vector<class Component*> mComponents;			// ������Ʈ�� ������Ʈ �ϱ� ���� ����
		class Game* mGame;									// ���� �ý����� ����� ����ϱ� ���� ����

		float mX, mY;										// ���� ��ǥ
};

