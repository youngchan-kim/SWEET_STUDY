#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;
//문자형을 인트형으로 바꿈
int ConvertToInt(string book_time, bool isEndTime)
{
    //stoi로 문자형을 정수형으로 바꿈
    int h = stoi(book_time.substr(0, 2));
    int m = stoi(book_time.substr(3, 2));

    //10분 단위
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

    //문자열로 된 예약 시간을 받아줄 2차월 정수 배열이 필요 
    vector<pair<int, int>> Intbook_time;

    for (vector<string> time : book_time)
    {
        //대실입장
        int start = ConvertToInt(time[0], false);
        //대실퇴장
        int end = ConvertToInt(time[1], true);
        //정수형으로 바꾸어 Intbook_time배열에 입력함
        Intbook_time.push_back({ start, end });
    }
    // 오름 차순으로 정리 sort 함수를 사용하기 위해서는 #include<algorithm>을 사용해야한다.
    sort(Intbook_time.begin(), Intbook_time.end());

    int answer = 0;
    // 인트형 filled 2차원 vector을 만듬
    vector < pair<int, int>> filled;

    //인트형으로 변환한 체크인 타임을 
    //인트형 time 배열에 입력하면서 더이상 입력할게 없어질때까지 반복
    for (pair<int, int> time : Intbook_time)
    {
        //start 는 시작시간을 가짐
        int start = time.first;

        //인트형 임시 벡터를 만듬
        vector<pair<int, int>> temp;

        //인트형 2차원 배열 에 filled를 대입하면서 반복 
        for (pair<int, int>room : filled)
        {
            //시작 시간이 룸배열의 퇴식시간 보다 작으면
            if (start < room.second)
            {
                //임시벡터배열에 룸의 정보를 입력
                temp.push_back(room);
            }
        }
        //임시벡터배열의 정보(룸의 정보)를 filled 벡터베열에 입력
        filled = temp;
        //각 룸에 대한 시간을 추가 입력
        filled.push_back(time);
        //answer과 filled사이즈 중 큰 값을 answer로 사용하겠음
        answer = max(answer, (int)filled.size());

        return answer;
    }
}