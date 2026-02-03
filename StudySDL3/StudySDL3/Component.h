#pragma once
class Component {
	public:
		// 액터의 기능을 쓰기 위해 가져오고, 업데이트 우선순위를 두기 위해 updateOrder를 추가합니다.
		Component(class Actor* owner, int updateOrder = 100);	
		~Component();

		virtual void Update(float deltaTime);				// 업데이트
	
		int GetUpdateOrder() const { return mUpdateOrder; }	// 업데이트 순서 반환
	
	private:
		class Actor* mOwner;								// 해당 컴포넌트를 가진 액터
		int mUpdateOrder;									// 우선 순위를 두어, 실행 순서를 제어합니다.
};

