#include <string>
#include <vector>
#include <algorithm>
/// 메리는 여름을 맞아 무인도로 여행을 가기 위해 지도를 보고 있습니다. 
/// 지도에는 바다와 무인도들에 대한 정보가 표시돼 있습니다. 
/// 지도는 1 x 1크기의 사각형들로 이루어진 직사각형 격자 형태이며, 
/// 격자의 각 칸에는 'X' 또는 1에서 9 사이의 자연수가 적혀있습니다. 
/// 지도의 'X'는 바다를 나타내며, 숫자는 무인도를 나타냅니다. 
/// 이때, 상, 하, 좌, 우로 연결되는 땅들은 하나의 무인도를 이룹니다. 
/// 지도의 각 칸에 적힌 숫자는 식량을 나타내는데, 
/// 상, 하, 좌, 우로 연결되는 칸에 적힌 숫자를 모두 합한 값은 해당 무인도에서 최대 며칠동안 머물 수 있는지를 나타냅니다. 
/// 어떤 섬으로 놀러 갈지 못 정한 메리는 우선 각 섬에서 최대 며칠씩 머물 수 있는지 알아본 후 놀러갈 섬을 결정하려 합니다.
/// 지도를 나타내는 문자열 배열 maps가 매개변수로 주어질 때, 
/// 각 섬에서 최대 며칠씩 머무를 수 있는지 배열에 오름차순으로 담아 return 하는 solution 함수를 완성해주세요.
/// 만약 지낼 수 있는 무인도가 없다면 - 1을 배열에 담아 return 해주세요.
///
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
    if (x < 0 || x >= maps.size() || y < 0 || y >= maps[0].size() || check[x][y] || maps[x][y] == 'X') { return 0; }
    //아니면check[x][y]은  true
    check[x][y] = true;
    //maps[x][y] - '0'??

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