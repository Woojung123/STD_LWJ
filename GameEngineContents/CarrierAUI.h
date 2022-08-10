
#pragma once
#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class CarrierAUI : public GameEngineActor
{
public:
	// constrcuter destructer
	CarrierAUI();
	~CarrierAUI();

	// delete Function
	CarrierAUI(const CarrierAUI& _Other) = delete;
	CarrierAUI(CarrierAUI&& _Other) noexcept = delete;
	CarrierAUI& operator=(const CarrierAUI& _Other) = delete;
	CarrierAUI& operator=(CarrierAUI&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) {}
	void End() {}

private:

};

