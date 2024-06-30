const fs = require("fs");
const input = fs.readFileSync("test.txt").toString().trim().split("\n");
// const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");

const [R, C, K] = input[0].split(" ").map((v) => Number(v));
const map = Array(5)
  .fill(null)
  .map(() => Array(5).fill(null));

for (let i = 0; i < R; i++) {
  for (let j = 0; j < C; j++) {
    map[R - i - 1][j] = input[i + 1][j];
  }
}

let answer = 0;
const arr = [{ r: 0, c: 0 }];
const checked = Array(5)
  .fill(null)
  .map(() => Array(5).fill(false));

checked[0][0] = true;

function dfs(k) {
  // prev Position
  const { r, c } = arr[k];
  if (k === K - 1) {
    if (r === R - 1 && c === C - 1) {
      answer++;
    }

    return;
  }

  // 상
  if (r + 1 < R && !checked[r + 1][c] && map[r + 1][c] !== "T") {
    checked[r + 1][c] = true;
    arr[k + 1] = { r: r + 1, c };
    dfs(k + 1);
    checked[r + 1][c] = false;
  }

  // 하
  if (r - 1 >= 0 && !checked[r - 1][c] && map[r - 1][c] !== "T") {
    checked[r - 1][c] = true;
    arr[k + 1] = { r: r - 1, c };
    dfs(k + 1);
    checked[r - 1][c] = false;
  }

  // 좌
  if (c - 1 >= 0 && !checked[r][c - 1] && map[r][c - 1] !== "T") {
    checked[r][c - 1] = true;
    arr[k + 1] = { r, c: c - 1 };
    dfs(k + 1);
    checked[r][c - 1] = false;
  }

  // 우
  if (c + 1 < C && !checked[r][c + 1] && map[r][c + 1] !== "T") {
    checked[r][c + 1] = true;
    arr[k + 1] = { r, c: c + 1 };
    dfs(k + 1);
    checked[r][c + 1] = false;
  }
}

dfs(0);

console.log(answer);
