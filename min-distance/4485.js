const fs = require("fs");
// const input = fs.readFileSync("test.txt").toString().trim().split("\n");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");

let inputLine = 0;
let testCase = 1;

while (true) {
  const N = Number(input[inputLine]);
  if (N === 0) break;

  const D = [];
  for (let k = 0; k < N; k++) {
    D[k] = input[inputLine + k + 1].split(" ").map(Number);
  }
  const visited = Array.from({ length: N }, () => Array(N).fill(false));
  const minD = Array.from({ length: N }, () => Array(N).fill(Infinity));
  let i = 0,
    j = 0;

  minD[0][0] = D[0][0];
  visited[0][0] = true;
  while (true) {
    const current = minD[i][j];
    // 오른쪽
    if (j + 1 < N) {
      minD[i][j + 1] = Math.min(minD[i][j + 1], current + D[i][j + 1]);
    }
    // 왼쪽
    if (j - 1 >= 0) {
      minD[i][j - 1] = Math.min(minD[i][j - 1], current + D[i][j - 1]);
    }
    // 아래쪽
    if (i + 1 < N) {
      minD[i + 1][j] = Math.min(minD[i + 1][j], current + D[i + 1][j]);
    }
    // 위쪽
    if (i - 1 >= 0) {
      minD[i - 1][j] = Math.min(minD[i - 1][j], current + D[i - 1][j]);
    }

    // 다음 정점 정하기
    let min = Infinity;
    let minIndex = {};
    for (let a = 0; a < N; a++) {
      for (let b = 0; b < N; b++) {
        if (visited[a][b]) continue;
        if (minD[a][b] < min) {
          min = minD[a][b];
          minIndex.x = a;
          minIndex.y = b;
        }
      }
    }
    // 모두 방문한 경우
    if (!minIndex.x && !minIndex.y) {
      break;
    }

    i = minIndex.x;
    j = minIndex.y;
    visited[i][j] = true;
  }
  console.log(`Problem ${testCase}: ${minD[N - 1][N - 1]}`);
  testCase++;
  inputLine += N + 1;
}
