const fs = require("fs");
// const input = fs.readFileSync("test.txt").toString().trim().split("\n");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");

const N = Number(input[0]);
const A = input[1].split(" ").map((v) => Number(v));

let answer = Number.NEGATIVE_INFINITY;
const arr = [];
const checked = [];

function dfs(n) {
  if (n === N) {
    let K = 0;
    for (let i = 0; i <= N - 2; i++) {
      K += Math.abs(arr[i] - arr[i + 1]);
    }

    answer = Math.max(answer, K);
  }

  for (let i = 0; i < N; i++) {
    if (!checked[i]) {
      checked[i] = true;
      arr[n] = A[i];
      dfs(n + 1);
      checked[i] = false;
    }
  }
}

dfs(0);

console.log(answer);
