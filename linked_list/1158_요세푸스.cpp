#include <iostream>
#include <string>
#include <algorithm>
#define maxs 5010
using namespace std;

int dat[maxs], pre[maxs], nxt[maxs];
int unused = 1;
int curs = 0;
void insert(int addr, int num)
{
	dat[unused] = num;
	pre[unused] = addr;
	nxt[unused] = nxt[addr];
	//먼저 삽입하는 리스트의 앞뒤 연결
	if (nxt[addr] != -1) { // 삽입위치가 끝부분이 아닐경우
		pre[nxt[addr]] = unused; // 삽입 다음원소의 pre값은 지금삽입하는 원소의주소
	}
	nxt[addr] = unused; // 삽입한원소의 왼쪽원소는 다음주소가 지금 삽입원소
	unused++;
}

int erase(int addr)
{
	nxt[pre[addr]] = nxt[addr];
	if (nxt[addr] != -1) //삭제한부분이 끝이아니면
	{
		pre[nxt[addr]] = pre[addr]; // 다음값의 pre를 삭제한배열의 pre값과 연결해줌.
	}
	return pre[addr];
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	fill(pre, pre + maxs, -1);	//야매연결위한 -1로 초기화.
	fill(nxt, nxt + maxs, -1);
	int N, K;
	cin >> N >> K;
	for (int i = 1; i < N+1; i++)
	{
		insert(curs, i);		// 연결리스트에 값 순차적으러 넣어주기.
		curs++;
	}

	unused--;					// 원형연결리스트 야매로 구현
	nxt[unused] = 1;			// 끝값의 다음가르키는 값을 첫번째 값으로  // 초기값 -1
	pre[1] = N;					// 첫값의 이전값을 -1이 아닌 마지막 값으로 // 초기값 -1
	
	

	curs = 0;					// 앞부터 K만큼
	int cnt = 0;
	if (N == 1)					// while문을 cnt로 조건을 걸었기 때문에 1 1 입력시 curs의 값이 0이라 문제발생.
	{
		curs = 1;				//조건문으로 1 1인 경우 예외 처리.
	}							//이는 편한 출력을 위한 예외처리인데 예외가 없게 할려면 cnt < N으로 수정후
								//dat[curs]의 값을 하나의 배열에 저장 그리고 출력형식에 맞게 출력
	cout << '<';
	while (cnt < N-1)			
	{
		for (int i = 0; i < K; i++)
		{
			curs = nxt[curs];	// K번째 --> 연결리스트에선 다음으로 연결된 노트 가르키기
		}
		cout << dat[curs] << ", "; 
		curs = erase(curs);		// 이미 빼낸 데이터는 지우기.
		cnt++;
	}
	cout << dat[curs] <<'>' <<'\n'; //드러운 출력형식 맞추기.
	return 0;
}