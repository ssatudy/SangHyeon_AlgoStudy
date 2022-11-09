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
	//���� �����ϴ� ����Ʈ�� �յ� ����
	if (nxt[addr] != -1) { // ������ġ�� ���κ��� �ƴҰ��
		pre[nxt[addr]] = unused; // ���� ���������� pre���� ���ݻ����ϴ� �������ּ�
	}
	nxt[addr] = unused; // �����ѿ����� ���ʿ��Ҵ� �����ּҰ� ���� ���Կ���
	unused++;
}

int erase(int addr)
{
	nxt[pre[addr]] = nxt[addr];
	if (nxt[addr] != -1) //�����Ѻκ��� ���̾ƴϸ�
	{
		pre[nxt[addr]] = pre[addr]; // �������� pre�� �����ѹ迭�� pre���� ��������.
	}
	return pre[addr];
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	fill(pre, pre + maxs, -1);	//�߸ſ������� -1�� �ʱ�ȭ.
	fill(nxt, nxt + maxs, -1);
	int N, K;
	cin >> N >> K;
	for (int i = 1; i < N+1; i++)
	{
		insert(curs, i);		// ���Ḯ��Ʈ�� �� ���������� �־��ֱ�.
		curs++;
	}

	unused--;					// �������Ḯ��Ʈ �߸ŷ� ����
	nxt[unused] = 1;			// ������ ��������Ű�� ���� ù��° ������  // �ʱⰪ -1
	pre[1] = N;					// ù���� �������� -1�� �ƴ� ������ ������ // �ʱⰪ -1
	
	

	curs = 0;					// �պ��� K��ŭ
	int cnt = 0;
	if (N == 1)					// while���� cnt�� ������ �ɾ��� ������ 1 1 �Է½� curs�� ���� 0�̶� �����߻�.
	{
		curs = 1;				//���ǹ����� 1 1�� ��� ���� ó��.
	}							//�̴� ���� ����� ���� ����ó���ε� ���ܰ� ���� �ҷ��� cnt < N���� ������
								//dat[curs]�� ���� �ϳ��� �迭�� ���� �׸��� ������Ŀ� �°� ���
	cout << '<';
	while (cnt < N-1)			
	{
		for (int i = 0; i < K; i++)
		{
			curs = nxt[curs];	// K��° --> ���Ḯ��Ʈ���� �������� ����� ��Ʈ ����Ű��
		}
		cout << dat[curs] << ", "; 
		curs = erase(curs);		// �̹� ���� �����ʹ� �����.
		cnt++;
	}
	cout << dat[curs] <<'>' <<'\n'; //�巯�� ������� ���߱�.
	return 0;
}