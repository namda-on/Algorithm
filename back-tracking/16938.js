const fs = require("fs");
// const input = fs.readFileSync("test.txt").toString().trim().split("\n");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");

const [N, L, R, X] = input[0].split(" ").map((v) => Number(v));
const A = input[1].split(" ").map((v) => Number(v));

let answer = 0;
let arr = [];
let checked = [];

function dfs(count, maxCount) {
  // 조건 만족하는지 확인
  if (count === maxCount) {
    let max = -Infinity;
    let min = Infinity;

    let sumOfA = 0;

    for (let r = 0; r < maxCount; r++) {
      const current = arr[r];
      max = Math.max(max, A[current]);
      min = Math.min(min, A[current]);
      sumOfA += A[current];
    }

    if (sumOfA >= L && sumOfA <= R && Math.abs(max - min) >= X) {
      answer++;
    }

    return;
  }

  for (let i = count === 0 ? 0 : arr[count - 1]; i < N; i++) {
    if (!checked[i]) {
      checked[i] = true;
      arr[count] = i;
      dfs(count + 1, maxCount);
      checked[i] = false;
    }
  }
}

// 문제 수
for (let i = 2; i <= N; i++) {
  dfs(0, i);
}

console.log(answer);
