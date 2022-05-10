#pragma once
#include "BaseGameEntity.h"
#include "Locations.h"

#define COMFORT_LEVEL		5	// �ȶ����� ������ �ݵ����� ��.
#define MAX_NUGGETS			3	// �ִ� ������.
#define THIRST_LEVEL		5	// ���� �Ѱ�.
#define TIREDNESS_THRESHOLD	5	// �Ƿ� �Ѱ�.

class Miner;
class State
{
public:
	virtual ~State() {}

	virtual void Enter(Miner*) abstract;
	virtual void Excute(Miner*) abstract;
	virtual void Exit(Miner*) abstract;
};

class Miner : public BaseGameEntity
{
private:
	State*			m_pCurrState;
	Location_Type	m_Location;
	int				m_nGoldCarried;	// ���ΰ� ���꿡�� ĵ �ݵ����� ��.
	int				m_nMoneyInBank;	// ���� �ݾ�.
	int				m_nThirst;		// ������.
	int				m_nFatigue;		// �Ƿε�.

public:
	Miner(const int& id);
	virtual ~Miner() {}

	void Update() override;
	void ChangeState(State*);

	Location_Type Location() const { return m_Location; }
	void ChangeLocation(const Location_Type& loc_type) { m_Location = loc_type; }

	int GoldCarried() const { return m_nGoldCarried; }
	void SetGoldCarried(const int& value) { m_nGoldCarried = value; }
	void AddToGoldCarried(const int&);
	bool PocketsFull() const { return (MAX_NUGGETS <= m_nGoldCarried); }

	bool Fatigued() const;
	void DecreaseFatigue() { m_nFatigue--; }
	void IncreaseFatigue() { m_nFatigue++; }

	int Wealth() const { return m_nMoneyInBank; }
	void SetWealth(const int& value) { m_nMoneyInBank = value; }
	void AddToWealth(const int&);

	bool Thirsty() const;
	void BuyAndDrinkAWhiskey() { m_nThirst = 0; m_nMoneyInBank -= 2; }
};