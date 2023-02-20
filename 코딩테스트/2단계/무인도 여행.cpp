#include <string>
#include <vector>
#include <algorithm>
/// 
/// BFS 너비 우선 탐색  알고리즘을 사용 해야한다.
/// 
/// 3 ≤ maps의 길이 ≤ 100
/// 3 ≤ maps[i]의 길이 ≤ 100
/// maps[i]는 'X' 또는 1 과 9 사이의 자연수로 이루어진 문자열입니다.
/// 지도는 직사각형 형태입니다
/// 
using namespace std;

//지도
//지도의 배열은 3 ≤ maps[i]의 길이 ≤ 100
//이기 때문에 101의 값을 가진다.
bool check[101][101];

//너비 우선 탐색 알고리즘
int bfs(int x, int y, vector<string>& maps)
{
    //x와 y가 0보다 작거나 x가 maps의 전체 길이보다 크거나 y가 maps[0]의 길이보다 크고  maps[x][y] == 'X'가 0이면 리턴 0
    //check[x][y] 이 조건이 의미하는거? true이면 한번더 계산하지 않기 위해서
    if (x < 0 || x >= maps.size() || y < 0 || y >= maps[0].size() || check[x][y] || maps[x][y] == 'X') { return 0; }
   
    check[x][y] = true;

    //maps[x][y] - '0' : string 형으로 값을 받았기 때문에 정수값으로 변환하기 위해 사용해준다.
    //재귀함수로 사용
    return (maps[x][y] - '0') + bfs(x - 1, y, maps) + bfs(x + 1, y, maps) + bfs(x, y - 1, maps) + bfs(x, y + 1, maps);
}

//maps 문자열이 들어옴 ["X591X","X1X5X","X231X", "1XXX1"]
vector<int> solution(vector<string> maps) {
    vector<int> answer;
    //문자열의 사이즈 4만큼 i를 반복
    for (int i = 0; i < maps.size(); i++)
    {
        int sum = 0;
        //maps[i]의 길이 만큼 반복 ["X591X","X1X5X","X231X", "1XXX1"]
        //maps[1]이면 X591X의 사이즈 5를 반복
        for (int j = 0; j < maps[i].size(); j++)
        {
            //1,1에서 부터 4,5까지 반복 
            sum = bfs(i, j, maps);
            // sum의 값이 영보다 크면
            if (sum > 0)
            {
                //인트형 벡터 배열에 추가
                answer.push_back(sum);
            }
        }
    }
    //answer의 값을 정렬
    sort(answer.begin(), answer.end());
    if (answer.empty())
    {
        return { -1 };
    }
    return answer;
}