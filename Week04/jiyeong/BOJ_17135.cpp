//캐슬 디펜스 (골드 3)
/*
1. 적 구조체(좌표, 죽음 여부)를 활용하여 enemy 벡터 만듦
2. 궁수 3명의 위치를 3중 반복문으로 뽑음
3. enemy 벡터를 복사하여 적들이 없어질 때까지
   죽일 적의 위치 찾기 + 죽이고 죽인 적의 수 카운팅 + 아래로 한칸씩 이동 반복
4. 가장 많은 적은 죽인 경우 찾기
*/

#include <iostream>
#include <vector>

using namespace std;

struct Enemy {   //적 구조체 (좌표, 죽음여부)
   int y, x;
   bool death;
};

int n, m, d;   //행과 열의 크기, 공격 거리 제한

int findKillEnemy(int loc, vector<Enemy>& enemy) {   //죽일 적의 인덱스 찾기
   int minD = d;   //가장 가까운 적
   int index=-1;   //죽일 적의 인덱스
   for (int i = 0; i < enemy.size(); i++)
      if (!enemy[i].death) {   //적이 아직 살아있을 때   
         int dis = abs(n - enemy[i].y) + abs(loc - enemy[i].x); //거리 구하기
         if (minD > dis) {   //현재 최소 거리보다 작은 경우
            minD = dis;
            index = i;
         }
         else if (minD == dis) {      //현재 최소 거리와 같은 경우
            if (index == -1)   //아직 목표 적이 없을 때
               index = i;
            else if (enemy[index].x > enemy[i].x)   //왼쪽에 있는 적 찾기
               index = i;
         }
      }
   return index;
}

int main()
{
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   vector<Enemy> enemy;   //적들의 초기 위치 정보
   cin >> n >> m >> d;   
   for (int i = 0; i < n ; i++)
      for (int j = 0; j < m; j++) {
         int state;   //현재 좌표 값의 상태
         cin >> state;
         if (state == 1)      //적이 있는 칸인 경우
            enemy.push_back({ i, j, false });   //현재 좌표 위치, 안죽음 정보를 벡터에 저장
      }
   
   int maxK = 0;   //최대 죽일 수 있는 적의 수

   for (int a = 0 ; a < m-2 ; a++)
      for (int b = a+1 ; b < m-1 ; b++)
         for (int c = b + 1; c < m; c++) {   //궁수 위치 뽑기
            vector<Enemy> nEnemy = enemy;   //적들의 현재 정보
            int numE = (int)nEnemy.size();   //아직 살아 있는 적의 수
            int killE = 0;   //죽인 적의 수
            while (numE > 0) {
               int indexa = findKillEnemy(a, nEnemy);   //죽일 적의 인덱스 찾기
               int indexb = findKillEnemy(b, nEnemy);
               int indexc = findKillEnemy(c, nEnemy);

               if (indexa > -1 && !nEnemy[indexa].death) {   //죽일 적이 살아 있는 경우만
                  nEnemy[indexa].death = true;   //죽이고 적의 수 감소 시키고 죽인 적의 수 증가
                  numE--;
                  killE++;
               }
               if (indexb > -1 && !nEnemy[indexb].death) {
                  nEnemy[indexb].death = true;
                  numE--;
                  killE++;
               }
               if (indexc > -1 && !nEnemy[indexc].death) {
                  nEnemy[indexc].death = true;
                  numE--;
                  killE++;
               }
               for (int i = 0; i < nEnemy.size(); i++) {   //살이 있는 적들을 아래 한 칸 이동
                  if (!nEnemy[i].death) {
                     if (nEnemy[i].y == n - 1) {      //가장 밑에 있는 경우는 제외시킴
                        nEnemy[i].death = true;      //죽이고 적 수 감소
                        numE--;
                     }
                     else
                        nEnemy[i].y++;   //행의 수 증가시킴
                  }
               }
            }
            if (maxK < killE)   //최댓값 찾기
               maxK = killE;
         }
   cout << maxK << endl;
} 
