const fs = require("fs");
// const input = fs.readFileSync("test.txt").toString().trim().split("\n");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");

const N = Number(input[0]);
const M = Number(input[1]);
const isFixed = Array(N).fill(false);

for (let i = 2; i < M + 2; i++) {
  isFixed[Number(input[i]) - 1] = true;
}

function main() {
  const dp = [1];

  isFixed[0] || isFixed[1] ? (dp[1] = 1) : (dp[1] = 2);

  for (let i = 1; i < N - 1; i++) {
    // 현재 좌석 혹은 이전 좌석이 고정
    if (isFixed[i + 1] || isFixed[i]) {
      dp[i + 1] = dp[i];
      continue;
    }
    dp[i + 1] = dp[i] + dp[i - 1];
  }

  return dp[N - 1];
}

console.log(main());
