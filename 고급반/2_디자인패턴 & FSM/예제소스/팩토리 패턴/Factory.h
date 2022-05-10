#pragma once
#include <iostream>

// GoF /////////////////////////////////////////

namespace Abstract
{
	class Weapon
	{
	public:
		virtual int Power() abstract;
	};
	class Bow : public Weapon
	{
	public:
		int Power() override
		{
			return 200;
		}
	};
	class Sword : public Weapon
	{
	public:
		int Power() override
		{
			return 50;
		}
	};

	class Armor
	{
	public:
		virtual int Defence() abstract;
	};
	class Leather : public Armor
	{
	public:
		int Defence() override
		{
			return 50;
		}
	};
	class Plate : public Armor
	{
	public:
		int Defence() override
		{
			return 200;
		}
	};

	class EquipmentAbstractFactory
	{
	public:
		virtual Weapon* CreateWeapon() abstract;
		virtual Armor* CreateArmor() abstract;
	};
	// �������̽� �������� � ��ü�� ������ ����.
	class ArcherEquipment : public EquipmentAbstractFactory
	{
	public:
		Weapon* CreateWeapon() override
		{
			return new Bow;
		}
		Armor* CreateArmor() override
		{
			return new Leather;
		}
	};
	class WarriorEquipment : public EquipmentAbstractFactory
	{
	public:
		Weapon* CreateWeapon() override
		{
			return new Sword;
		}
		Armor* CreateArmor() override
		{
			return new Plate;
		}
	};

	class Character
	{
	protected:
		Weapon* m_Weapon;
		Armor* m_Armor;

	public:
		Character(EquipmentAbstractFactory* equipment)
		{
			this->m_Weapon = equipment->CreateWeapon();
			this->m_Armor = equipment->CreateArmor();
		}
		virtual ~Character() { delete this->m_Weapon; delete this->m_Armor; }
		virtual void Attack() abstract;
	};
	class Archer : public Character
	{
	public:
		Archer(EquipmentAbstractFactory* equipment) : Character(equipment) {}
		void Attack() override
		{
			std::cout << "Ȱ�� ��� ����!! " << m_Weapon->Power() << "�� ���ظ� �����ϴ�!" << std::endl;
		}
	};
	class Warrior : public Character
	{
	public:
		Warrior(EquipmentAbstractFactory* equipment) : Character(equipment) {}
		void Attack() override
		{
			std::cout << "���� �ֵѷ� ����!! " << m_Weapon->Power() << "�� ���ظ� �����ϴ�!" << std::endl;
		}
	};
}

namespace Method
{
	class Character
	{
	public:
		virtual void Attack() abstract;
	};
	class Archer : public Character
	{
	public:
		void Attack() override
		{
			std::cout << "Ȱ�� ���." << std::endl;
		}
	};
	class Warrior : public Character
	{
	public:
		void Attack() override
		{
			std::cout << "���� �ֵθ���." << std::endl;
		}
	};

	class CreateCharacter
	{
	private:
		virtual Character* FactoryMethod() abstract;
	public:		
		Character* Create()
		{
			return FactoryMethod();
		}
	};
	class ArcherCreate : public CreateCharacter
	{
	private:
		Character* FactoryMethod() override // ���� ��ü�� �ڽ� Ŭ���� �޼ҵ�(�Լ�)���� ����.
		{
			return new Archer;
		}
	};
	class WarriorCreate : public CreateCharacter
	{
	private:
		Character* FactoryMethod() override
		{
			return new Warrior;
		}
	};
}