const fs = require("fs");
// const input = fs.readFileSync("test.txt").toString().trim().split("\n");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");

const N = Number(input[0]);
const T = [];
const P = [];
for (let i = 0; i < N; i++) {
  const [time, pay] = input[i + 1].split(" ").map(Number);
  T[i] = time;
  P[i] = pay;
}

const dp = Array(N + 1).fill(0);

function solution() {
  let max = 0;

  for (let i = 0; i < N; i++) {
    max = Math.max(max, dp[i]);

    if (i + T[i] <= N) dp[i + T[i]] = Math.max(max + P[i], dp[i + T[i]]);
  }

  return Math.max(...dp);
}

console.log(solution());
