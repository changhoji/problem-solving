# 1018번: 체스판 다시 칠하기

[문제 바로가기](https://www.acmicpc.net/problem/1018)

## 해결한 과정

### 8*8 체스판 다시 칠하기

우선 8*8 사이즈의 체스판에서 색깔을 알맞게 다시 칠하는 경우를 구하는 방법을 생각했다.

맨 왼쪽 위의 칸을 검은색으로 칠한다 생각하자. 이때 각각의 칸을 이차원 배열로 생각해 접근하면 `board[r][c]`의 칸을 살펴볼때, 아래와 같은 조건에서 다시 칠해야 한다.

```
((r+c)%2 == 0) and board[r][c] == 'W' or
((r+c)%2 == 1) and board[r][c] == 'B'
```

말로 설명하자면 (r+c)%2 == 0 은 행과 열 번호를 구한게 2의 배수, 즉 맨 왼쪽 위의 칸과 같이 검은색으로 칠해야 하는 칸임을 나타낸다. 따라서 이때 칸의 색이 흰색(W)이면 다시 칠해야 한다. (r+c)%2 == 1 일때도 이와 마찬가지로 생각할 수 있다.

이렇게 위 코드의 조건을 만족시키는 칸의 개수를 구하면 맨 왼쪽 위칸을 검은색으로 칠하려 할때 다시 칠해야 하는 칸의 개수가 된다. 다만 맨 왼쪽 위칸을 검은색으로 칠해야만 하는 것이 아니라, 만약 하얀색으로 칠했을때 다시 칠해야 하는 칸이 더 적으면 그쪽을 택해야 한다.

이는 간단히 해결할 수 있는데, 맨 왼쪽 위칸이 검은색일때와, 흰색일때 체스판의 각각의 칸은 모두 색이 다르다. 즉, 앞서 구한 다시 칠해야 하는 칸의 개수를 8*8=64 에서 빼주면 맨 왼쪽 위를 흰색으로 할때, 다시 칠해야 하는 칸의 개수를 구할 수 있다.

마지막으로, 구한 두개의 count중 작은것을 택하면 된다.

### 8*8 체스판 고르기

앞서 8*8 체스판에서 다시 칠해야 하는 칸의 최소 개수를 구하는 법을 생각해 보았다. 다만 문제는 전체 보드가 8\*8보다 클 수 있다는 것이다.

이에 먼저 간단한 해결책이 떠올랐는데, 전체 보드에서 가능한 8\*8 크기의 보드들에서 각각 최소 개수를 구하고, 그중에서 최솟값을 구하는 방법이다.

이 풀이가 가능한지 생각해 보기 위해 입력과 조건을 살펴보면 N과 M의 최대는 50인데, 
```
(가능한 최대 8*8 보드의 개수) < 50*50
(각각의 8*8 체스판에서 최소 개수를 구하는 시간) = O(n) => 64
```
이때 2500 * 64 = 160000, 즉 시간제한 2초에 비하면 매우 충분하기 때문에 브루트포스 알고리즘으로 문제를 풀수 있겠다 생각했다.

그렇다면 N과 M의 크기에 따라 가능한 `8*8` 체스판의 개수는 어떻게 될까?

`N=10, M=9`일때를 생각해 보면 전체 보드가 세로로 10이므로 1\~8, 2\~9, 3\~10 세개를 택할 수 있고, 가로로 9이므로 1\~8, 2\~9를 택할 수 있다.

즉, n행 m열의 칸에 대해 `1<=n<=N, 1<=m<=M` 이라고 하면 가능한 각각의 `8*8` 체스판의 맨 왼쪽 위 칸은 (1,1), (1,2), (2,1), (2,2), (3,1), (3,2) 여섯개가 된다. 이때 맨 왼쪽위 칸의 가능한 행 번호는 1부터 N-7까지이고, 열 번호는 1부터 M-7까지임을 알 수 있다.

## 구현

아래 코드는 각각의 8*8 체스판의 맨 왼쪽 위 칸을 나타내는 반복문이다. `min_cnt`는 결과값이 들어가는데 우선 최대 32이기 때문에 32로 초기화했다.
```c++
int min_cnt = 32;
for(int i = 0; i < N-7; i++){
    for(int j = 0; j < N-7; j++){
        // progress of calculating each minimum count of
        // required re-painted sector
    }
}
```

그리고 그 반복문 안에 다음과 같이 `8*8`만큼 다시 반복문을 돌면서 다시 칠해야 하는 칸인지 체크했다. 그 후, 반복문을 빠져나오면 색깔을 반전시키는게 더 적게 칠하는지 확인한 후, 이전까지 최소였던 값과 비교해 업데이트한다.
```c++
int cnt = 0;
    for(int r = i; r < i+8; r++){
        for(int c = j; c < j+8; c++){
            if(((r+c)%2 == 0) && board[r][c] == 'W') cnt++;
            if(((r+c)%2 == 1) && board[r][c] == 'B') cnt++;
        }
    }
    if(cnt > 32) cnt = 64 - cnt;
    if(min_cnt > cnt) min_cnt = cnt;
```
---
## 전체 코드
```c++
#include <iostream>
using namespace std;

int main(){
    int N, M;
    char board[50][50];

    cin >> N >> M;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            cin >> board[i][j];

    int min_cnt = 32;

    for(int i = 0; i < N-7; i++){
        for(int j = 0; j < M-7; j++){
            // start at the pos where can get 8x8 size
            
            int cnt = 0;
            for(int r = i; r < i+8; r++){
                for(int c = j; c < j+8; c++){
                    if(((r+c)%2 == 0) && board[r][c] == 'W') cnt++;
                    if(((r+c)%2 == 1) && board[r][c] == 'B') cnt++;
                }
            }
            if(cnt > 32) cnt = 64 - cnt;
            if(min_cnt > cnt) min_cnt = cnt;
        }
    }

    cout << min_cnt << '\n';

    return 0;
}

```