#include <string>
#include <vector>
#include <algorithm>
/// 
/// BFS �ʺ� �켱 Ž��  �˰����� ��� �ؾ��Ѵ�.
/// 
/// 3 �� maps�� ���� �� 100
/// 3 �� maps[i]�� ���� �� 100
/// maps[i]�� 'X' �Ǵ� 1 �� 9 ������ �ڿ����� �̷���� ���ڿ��Դϴ�.
/// ������ ���簢�� �����Դϴ�
/// 
using namespace std;

//����
//������ �迭�� 3 �� maps[i]�� ���� �� 100
//�̱� ������ 101�� ���� ������.
bool check[101][101];

//�ʺ� �켱 Ž�� �˰���
int bfs(int x, int y, vector<string>& maps)
{
    //x�� y�� 0���� �۰ų� x�� maps�� ��ü ���̺��� ũ�ų� y�� maps[0]�� ���̺��� ũ��  maps[x][y] == 'X'�� 0�̸� ���� 0
    //check[x][y] �� ������ �ǹ��ϴ°�? true�̸� �ѹ��� ������� �ʱ� ���ؼ�
    if (x < 0 || x >= maps.size() || y < 0 || y >= maps[0].size() || check[x][y] || maps[x][y] == 'X') { return 0; }
   
    check[x][y] = true;

    //maps[x][y] - '0' : string ������ ���� �޾ұ� ������ ���������� ��ȯ�ϱ� ���� ������ش�.
    //����Լ��� ���
    return (maps[x][y] - '0') + bfs(x - 1, y, maps) + bfs(x + 1, y, maps) + bfs(x, y - 1, maps) + bfs(x, y + 1, maps);
}

//maps ���ڿ��� ���� ["X591X","X1X5X","X231X", "1XXX1"]
vector<int> solution(vector<string> maps) {
    vector<int> answer;
    //���ڿ��� ������ 4��ŭ i�� �ݺ�
    for (int i = 0; i < maps.size(); i++)
    {
        int sum = 0;
        //maps[i]�� ���� ��ŭ �ݺ� ["X591X","X1X5X","X231X", "1XXX1"]
        //maps[1]�̸� X591X�� ������ 5�� �ݺ�
        for (int j = 0; j < maps[i].size(); j++)
        {
            //1,1���� ���� 4,5���� �ݺ� 
            sum = bfs(i, j, maps);
            // sum�� ���� ������ ũ��
            if (sum > 0)
            {
                //��Ʈ�� ���� �迭�� �߰�
                answer.push_back(sum);
            }
        }
    }
    //answer�� ���� ����
    sort(answer.begin(), answer.end());
    if (answer.empty())
    {
        return { -1 };
    }
    return answer;
}