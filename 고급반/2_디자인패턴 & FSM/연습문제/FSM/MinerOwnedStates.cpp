#include "MinerOwnedStates.h"
#include "EntityNames.h"
#include "ConsoleUtils.h"

// EnterMineAndDigForNugget ------------------------------------
EnterMineAndDigForNugget* EnterMineAndDigForNugget::Instance()
{
	static EnterMineAndDigForNugget instance;
	return &instance;
}

void EnterMineAndDigForNugget::Enter(Miner* pMiner)
{
	if (pMiner->Location() != Location_Type::gold_mine)
	{
		SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
		std::cout << GetNameOfEntity(pMiner->ID()) << ":�������� �ɾ��" << std::endl;

		pMiner->ChangeLocation(Location_Type::gold_mine);
	}
}

void EnterMineAndDigForNugget::Excute(Miner* pMiner)
{
	pMiner->AddToGoldCarried(1);

	pMiner->IncreaseFatigue();

	SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
	std::cout << GetNameOfEntity(pMiner->ID()) << ":�ݵ��� 1���� ä��" << std::endl;

	// �ָӴϰ� ��������,
	if (pMiner->PocketsFull())
	{
		// ������ ���� ���� �湮.
		pMiner->ChangeState(VisitBankAndDepositGold::Instance());
	}

	// ���� ������,
	if (pMiner->Thirsty())
	{
		// �񸶸� �ؼҸ� ���� �ൿ.
		pMiner->ChangeState(QuenchThirst::Instance());
	}
}

void EnterMineAndDigForNugget::Exit(Miner* pMiner)
{
	SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
	std::cout << GetNameOfEntity(pMiner->ID()) << ":�ݵ��� " << pMiner->GoldCarried() << "���� ������ ������ ������" << std::endl;
}
// -------------------------------------------------------------

// VisitBankAndDepositGold ------------------------------------
VisitBankAndDepositGold* VisitBankAndDepositGold::Instance()
{
	static VisitBankAndDepositGold instance;
	return &instance;
}

void VisitBankAndDepositGold::Enter(Miner* pMiner)
{
	if (pMiner->Location() != Location_Type::bank)
	{
		SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
		std::cout << GetNameOfEntity(pMiner->ID()) << ":�������� �̵�" << std::endl;

		pMiner->ChangeLocation(Location_Type::bank);
	}
}

void VisitBankAndDepositGold::Excute(Miner* pMiner)
{
	pMiner->AddToWealth(pMiner->GoldCarried());

	pMiner->SetGoldCarried(0);

	SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
	std::cout << GetNameOfEntity(pMiner->ID()) << ":�ݵ��� ����\n\n���� �ܱ�:" << pMiner->Wealth() << std::endl << std::endl;

	// ���� �ݾ��� Ȯ��,
	if (pMiner->Wealth() >= COMFORT_LEVEL)
	{
		// ������ ��ŭ ���� ��Ҵ�.
		SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
		std::cout << GetNameOfEntity(pMiner->ID()) << ":\"���! ���� ���� ���ڴ�. ���� �ִ� �Ƴ����Է� ���ư���.\"" << std::endl;

		pMiner->ChangeState(GoHomeAndSleepTilRested::Instance());
	}
	else
	{
		// ���� ���� �����ϴ�. �ٽ� ��������.
		pMiner->ChangeState(EnterMineAndDigForNugget::Instance());
	}
}

void VisitBankAndDepositGold::Exit(Miner* pMiner)
{
	SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
	std::cout << GetNameOfEntity(pMiner->ID()) << ":������ ������" << std::endl;
}
// -------------------------------------------------------------

// GoHomeAndSleepTilRested -------------------------------------
GoHomeAndSleepTilRested* GoHomeAndSleepTilRested::Instance()
{
	static GoHomeAndSleepTilRested instance;
	return &instance;
}

void GoHomeAndSleepTilRested::Enter(Miner* pMiner)
{
	if (pMiner->Location() != Location_Type::shack)
	{
		SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
		std::cout << GetNameOfEntity(pMiner->ID()) << ":������ ����" << std::endl;

		pMiner->ChangeLocation(Location_Type::shack);
	}
}

void GoHomeAndSleepTilRested::Excute(Miner* pMiner)
{
	// �Ƿε��� Ȯ��.
	if (!pMiner->Fatigued())
	{
		// �Ƿΰ� �� �ʸ��� �ٽ� ���� ĳ������.
		SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
		std::cout << GetNameOfEntity(pMiner->ID()) << ":\"������ �þ����� ���! �ٽ� ���� ĳ�� ���߰ڱ�.\"" << std::endl;

		pMiner->ChangeState(EnterMineAndDigForNugget::Instance());
	}
	else
	{
		// �ǰ��ϴ� ���� �ܴ�.
		pMiner->DecreaseFatigue();

		SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
		std::cout << GetNameOfEntity(pMiner->ID()) << ":...zZ" << std::endl;
	}
}

void GoHomeAndSleepTilRested::Exit(Miner* pMiner)
{
	SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
	std::cout << GetNameOfEntity(pMiner->ID()) << ":���� ������" << std::endl;
}
// -------------------------------------------------------------

// QuenchThirst ------------------------------------------------
QuenchThirst* QuenchThirst::Instance()
{
	static QuenchThirst instance;
	return &instance;
}

void QuenchThirst::Enter(Miner* pMiner)
{
	if (pMiner->Location() != Location_Type::saloon)
	{
		SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
		std::cout << GetNameOfEntity(pMiner->ID()) << ":\"���� ������!\"" << std::endl;
		std::cout << GetNameOfEntity(pMiner->ID()) << ":�������� ����" << std::endl;

		pMiner->ChangeLocation(Location_Type::saloon);
	}
}

void QuenchThirst::Excute(Miner* pMiner)
{
	// ������ �ִٸ�,
	if (pMiner->Thirsty())
	{
		// ���� ������ ���� ������.
		pMiner->BuyAndDrinkAWhiskey();

		SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
		std::cout << GetNameOfEntity(pMiner->ID()) << ":���� ���Ŵ�" << std::endl;

		SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
		std::cout << "\n���� �ܱ�:" << pMiner->Wealth() << std::endl << std::endl;

		pMiner->ChangeState(EnterMineAndDigForNugget::Instance());
	}
	else
	{
		SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
		std::cout << "\nError!\nError!!\nError!!!" << std::endl;
	}
}

void QuenchThirst::Exit(Miner* pMiner)
{
	SetTextColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
	std::cout << GetNameOfEntity(pMiner->ID()) << ":������ ������" << std::endl;
}
// -------------------------------------------------------------