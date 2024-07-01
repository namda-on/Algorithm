const fs = require("fs");
// const input = fs.readFileSync("test.txt").toString().trim().split("\n");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");

const N = Number(input[0]);
const dp = [1, 2];

function main() {
  for (let i = 2; i < N; i++) {
    dp[i] = (dp[i - 2] + dp[i - 1]) % 10007;
  }
  console.log(dp[N - 1]);
}

main();
