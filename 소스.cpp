#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;
//�������� ��Ʈ������ �ٲ�
int ConvertToInt(string book_time, bool isEndTime)
{
    //stoi�� �������� ���������� �ٲ�
    int h = stoi(book_time.substr(0, 2));
    int m = stoi(book_time.substr(3, 2));

    //10�� ����
    if (isEndTime)
    {
        if (m >= 50)
        {
            h += 1;
            m -= 50;
        }
        else
        {
            m += 10;
        }
    }

    return h * 100 + m;
}

int solution(vector<vector<string>> book_time) {

    //���ڿ��� �� ���� �ð��� �޾��� 2���� ���� �迭�� �ʿ� 
    vector<pair<int, int>> Intbook_time;

    for (vector<string> time : book_time)
    {
        //�������
        int start = ConvertToInt(time[0], false);
        //�������
        int end = ConvertToInt(time[1], true);
        //���������� �ٲپ� Intbook_time�迭�� �Է���
        Intbook_time.push_back({ start, end });
    }
    // ���� �������� ���� sort �Լ��� ����ϱ� ���ؼ��� #include<algorithm>�� ����ؾ��Ѵ�.
    sort(Intbook_time.begin(), Intbook_time.end());

    int answer = 0;
    // ��Ʈ�� filled 2���� vector�� ����
    vector < pair<int, int>> filled;

    //��Ʈ������ ��ȯ�� üũ�� Ÿ���� 
    //��Ʈ�� time �迭�� �Է��ϸ鼭 ���̻� �Է��Ұ� ������������ �ݺ�
    for (pair<int, int> time : Intbook_time)
    {
        //start �� ���۽ð��� ����
        int start = time.first;

        //��Ʈ�� �ӽ� ���͸� ����
        vector<pair<int, int>> temp;

        //��Ʈ�� 2���� �迭 �� filled�� �����ϸ鼭 �ݺ� 
        for (pair<int, int>room : filled)
        {
            //���� �ð��� ��迭�� ��Ľð� ���� ������
            if (start < room.second)
            {
                //�ӽú��͹迭�� ���� ������ �Է�
                temp.push_back(room);
            }
        }
        //�ӽú��͹迭�� ����(���� ����)�� filled ���ͺ����� �Է�
        filled = temp;
        //�� �뿡 ���� �ð��� �߰� �Է�
        filled.push_back(time);
        //answer�� filled������ �� ū ���� answer�� ����ϰ���
        answer = max(answer, (int)filled.size());

        return answer;
    }
}