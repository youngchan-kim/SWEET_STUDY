#include "Character.h"

Character::Character(){}
Character::~Character(){}
//�ΰ�����
void Human::Make_Body()
{
	cout << m_szname << "�� ������!!" << endl;
}
void Human::Make_Arms()
{
	cout << m_szname << "�� �Ȼ���!!" << endl;
}
void Human::Make_Legs()
{
	cout << m_szname << "�� �ٸ�����!!" << endl;
}
void Human::Make_Face()
{
	cout << m_szname << "�� �󱼻���!!" << endl;
}
void Human::Make_Trait()
{
	cout << endl << m_szname << "�� Ư������!!" << endl;
	vec_Trait.push_back("�ΰ��� �����");
	vec_Trait.push_back("�ܱ�");
	vec_Trait.push_back("�ΰ��� ���ŷ�");
	int i = 1;
	for (auto iter = vec_Trait.begin(); iter != vec_Trait.end(); iter++,i++)
		cout << "Ư��" << i << " : " << *iter << " ����!!" << endl;
}

//���������
void Dwarf::Make_Body()
{
	cout << m_szname << "�� ������!!" << endl;
}
void Dwarf::Make_Arms()
{
	cout << m_szname << "�� �Ȼ���!!" << endl;
}
void Dwarf::Make_Legs()
{
	cout << m_szname << "�� �ٸ�����!!" << endl;
}
void Dwarf::Make_Face()
{
	cout << m_szname << "�� �󱼻���!!" << endl;
}
void Dwarf::Make_Trait()
{
	cout << endl << m_szname << "�� Ư������!!" << endl;
	vec_Trait.push_back("Ž�谡");
	vec_Trait.push_back("�ñ� ���� ����");
	vec_Trait.push_back("���� ������");
	vec_Trait.push_back("��ȭ");
	int i = 1;
	for (auto iter = vec_Trait.begin(); iter != vec_Trait.end(); iter++, i++)
		cout << "Ư��" << i << " : " << *iter << " ����!!" << endl;
}

//����Ʈ���� ����
void Night_Elf::Make_Body()
{
	cout << m_szname << "�� ������!!" << endl;
}
void Night_Elf::Make_Arms()
{
	cout << m_szname << "�� �Ȼ���!!" << endl;
}
void Night_Elf::Make_Legs()
{
	cout << m_szname << "�� �ٸ�����!!" << endl;
}
void Night_Elf::Make_Face()
{
	cout << m_szname << "�� �󱼻���!!" << endl;
}
void Night_Elf::Make_Trait()
{
	cout << endl << m_szname << "�� Ư������!!" << endl;
	vec_Trait.push_back("�׸��� ����");
	vec_Trait.push_back("������ ��ȥ");
	vec_Trait.push_back("�ڿ� ���׷�");
	vec_Trait.push_back("��ø");
	vec_Trait.push_back("������ �ձ�");
	int i = 1;
	for (auto iter = vec_Trait.begin(); iter != vec_Trait.end(); iter++, i++)
		cout << "Ư��" << i << " : " << *iter << " ����!!" << endl;
}



//�������
void Gnome::Make_Body()
{
	cout << m_szname << "�� ������!!" << endl;
}
void Gnome::Make_Arms()
{
	cout << m_szname << "�� �Ȼ���!!" << endl;
}
void Gnome::Make_Legs()
{
	cout << m_szname << "�� �ٸ�����!!" << endl;
}
void Gnome::Make_Face()
{
	cout << m_szname << "�� �󱼻���!!" << endl;
}
void Gnome::Make_Trait()
{
	cout << endl << m_szname << "�� Ư������!!" << endl;
	vec_Trait.push_back("Ż���� ���");
	vec_Trait.push_back("���� ���׷�");
	vec_Trait.push_back("������");
	vec_Trait.push_back("������ ����ȭ");
	vec_Trait.push_back("������ �հ���");
	int i = 1;
	for (auto iter = vec_Trait.begin(); iter != vec_Trait.end(); iter++, i++)
		cout << "Ư��" << i << " : " << *iter << " ����!!" << endl;
}

//�巹��������
void Draenei::Make_Body()
{
	cout << m_szname << "�� ������!!" << endl;
}
void Draenei::Make_Arms()
{
	cout << m_szname << "�� �Ȼ���!!" << endl;
}
void Draenei::Make_Legs()
{
	cout << m_szname << "�� �ٸ�����!!" << endl;
}
void Draenei::Make_Face()
{
	cout << m_szname << "�� �󱼻���!!" << endl;
}
void Draenei::Make_Trait()
{
	cout << endl << m_szname << "�� Ư������!!" << endl;
	vec_Trait.push_back("������ ����");
	vec_Trait.push_back("����� ���");
	vec_Trait.push_back("���� ���׷�");
	vec_Trait.push_back("���� ������");
	int i = 1;
	for (auto iter = vec_Trait.begin(); iter != vec_Trait.end(); iter++, i++)
		cout << "Ư��" << i << " : " << *iter << " ����!!" << endl;
}

//�����ΰ�����
void Worgen::Make_Body()
{
	cout << m_szname << "�� ������!!" << endl;
}
void Worgen::Make_Arms()
{
	cout << m_szname << "�� �Ȼ���!!" << endl;
}
void Worgen::Make_Legs()
{
	cout << m_szname << "�� �ٸ�����!!" << endl;
}
void Worgen::Make_Face()
{
	cout << m_szname << "�� �󱼻���!!" << endl;
}
void Worgen::Make_Trait()
{
	cout << endl << m_szname << "�� Ư������!!" << endl;
	vec_Trait.push_back("�߻� ����");
	vec_Trait.push_back("��������");
	vec_Trait.push_back("���決��");
	vec_Trait.push_back("������");
	vec_Trait.push_back("������");
	vec_Trait.push_back("�� ���� ���");
	int i = 1;
	for (auto iter = vec_Trait.begin(); iter != vec_Trait.end(); iter++, i++)
		cout << "Ư��" << i << " : " << *iter << " ����!!" << endl;
}

//�Ǵٷ�����
void Pandaren::Make_Body()
{
	cout << m_szname << "�� ������!!" << endl;
}
void Pandaren::Make_Arms()
{
	cout << m_szname << "�� �Ȼ���!!" << endl;
}
void Pandaren::Make_Legs()
{
	cout << m_szname << "�� �ٸ�����!!" << endl;
}
void Pandaren::Make_Face()
{
	cout << m_szname << "�� �󱼻���!!" << endl;
}
void Pandaren::Make_Trait()
{
	cout << endl << m_szname << "�� Ư������!!" << endl;
	vec_Trait.push_back("����: �߸�");
	vec_Trait.push_back("�ĵ���");
	vec_Trait.push_back("��İ�");
	vec_Trait.push_back("����");
	vec_Trait.push_back("������");
	vec_Trait.push_back("������ ��ǳ");
	int i = 1;
	for (auto iter = vec_Trait.begin(); iter != vec_Trait.end(); iter++, i++)
		cout << "Ư��" << i << " : " << *iter << " ����!!" << endl;
}

//��ũ����
void Orc::Make_Body()
{
	cout << m_szname << "�� ������!!" << endl;
}
void Orc::Make_Arms()
{
	cout << m_szname << "�� �Ȼ���!!" << endl;
}
void Orc::Make_Legs()
{
	cout << m_szname << "�� �ٸ�����!!" << endl;
}
void Orc::Make_Face()
{
	cout << m_szname << "�� �󱼻���!!" << endl;
}
void Orc::Make_Trait()
{
	cout << endl << m_szname << "�� Ư������!!" << endl;
	vec_Trait.push_back("���� �ݳ�");
	vec_Trait.push_back("������");
	vec_Trait.push_back("����");
	int i = 1;
	for (auto iter = vec_Trait.begin(); iter != vec_Trait.end(); iter++, i++)
		cout << "Ư��" << i << " : " << *iter << " ����!!" << endl;
}

//�𵥵�����
void Undead::Make_Body()
{
	cout << m_szname << "�� ������!!" << endl;
}
void Undead::Make_Arms()
{
	cout << m_szname << "�� �Ȼ���!!" << endl;
}
void Undead::Make_Legs()
{
	cout << m_szname << "�� �ٸ�����!!" << endl;
}
void Undead::Make_Face()
{
	cout << m_szname << "�� �󱼻���!!" << endl;
}
void Undead::Make_Trait()
{
	cout << endl << m_szname << "�� Ư������!!" << endl;
	vec_Trait.push_back("������ū�� ����");
	vec_Trait.push_back("���� ���׷�");
	vec_Trait.push_back("��ü�Ա�");
	vec_Trait.push_back("������ �ձ�");
	int i = 1;
	for (auto iter = vec_Trait.begin(); iter != vec_Trait.end(); iter++, i++)
		cout << "Ư��" << i << " : " << *iter << " ����!!" << endl;
}

//Ÿ�췻����
void Tauren::Make_Body()
{
	cout << m_szname << "�� ������!!" << endl;
}
void Tauren::Make_Arms()
{
	cout << m_szname << "�� �Ȼ���!!" << endl;
}
void Tauren::Make_Legs()
{
	cout << m_szname << "�� �ٸ�����!!" << endl;
}
void Tauren::Make_Face()
{
	cout << m_szname << "�� �󱼻���!!" << endl;
}
void Tauren::Make_Trait()
{
	cout << endl << m_szname << "�� Ư������!!" << endl;
	vec_Trait.push_back("������");
	vec_Trait.push_back("���");
	vec_Trait.push_back("�γ���");
	vec_Trait.push_back("�ڿ� ���׷�");
	vec_Trait.push_back("���� �߱�����");
	int i = 1;
	for (auto iter = vec_Trait.begin(); iter != vec_Trait.end(); iter++, i++)
		cout << "Ư��" << i << " : " << *iter << " ����!!" << endl;
}

//Ʈ������
void Troll::Make_Body()
{
	cout << m_szname << "�� ������!!" << endl;
}
void Troll::Make_Arms()
{
	cout << m_szname << "�� �Ȼ���!!" << endl;
}
void Troll::Make_Legs()
{
	cout << m_szname << "�� �ٸ�����!!" << endl;
}
void Troll::Make_Face()
{
	cout << m_szname << "�� �󱼻���!!" << endl;
}
void Troll::Make_Trait()
{
	cout << endl << m_szname << "�� Ư������!!" << endl;
	vec_Trait.push_back("����ȭ");
	vec_Trait.push_back("�ε� ��");
	vec_Trait.push_back("�����");
	vec_Trait.push_back("�߼� ��� ����ȭ");
	int i = 1;
	for (auto iter = vec_Trait.begin(); iter != vec_Trait.end(); iter++, i++)
		cout << "Ư��" << i << " : " << *iter << " ����!!" << endl;
}

//���忤������
void Blood_Elf::Make_Body()
{
	cout << m_szname << "�� ������!!" << endl;
}
void Blood_Elf::Make_Arms()
{
	cout << m_szname << "�� �Ȼ���!!" << endl;
}
void Blood_Elf::Make_Legs()
{
	cout << m_szname << "�� �ٸ�����!!" << endl;
}
void Blood_Elf::Make_Face()
{
	cout << m_szname << "�� �󱼻���!!" << endl;
}
void Blood_Elf::Make_Trait()
{
	cout << endl << m_szname << "�� Ư������!!" << endl;
	vec_Trait.push_back("���� ����");
	vec_Trait.push_back("���� �ݷ�");
	vec_Trait.push_back("���� ģȭ");
	vec_Trait.push_back("���� ���׷�");
	int i = 1;
	for (auto iter = vec_Trait.begin(); iter != vec_Trait.end(); iter++, i++)
		cout << "Ư��" << i << " : " << *iter << " ����!!" << endl;
}

//�������
void Goblin::Make_Body()
{
	cout << m_szname << "�� ������!!" << endl;
}
void Goblin::Make_Arms()
{
	cout << m_szname << "�� �Ȼ���!!" << endl;
}
void Goblin::Make_Legs()
{
	cout << m_szname << "�� �ٸ�����!!" << endl;
}
void Goblin::Make_Face()
{
	cout << m_szname << "�� �󱼻���!!" << endl;
}
void Goblin::Make_Trait()
{
	cout << endl << m_szname << "�� Ư������!!" << endl;
	vec_Trait.push_back("���� ����");
	vec_Trait.push_back("���� ����ź");
	vec_Trait.push_back("���� ������");
	vec_Trait.push_back("�ŷ��� ����");
	vec_Trait.push_back("�ð��� ��");
	vec_Trait.push_back("���ݼ��� �������� ��");
	int i = 1;
	for (auto iter = vec_Trait.begin(); iter != vec_Trait.end(); iter++, i++)
		cout << "Ư��" << i << " : " << *iter << " ����!!" << endl;
}

