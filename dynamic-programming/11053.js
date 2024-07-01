const fs = require("fs");
// const input = fs.readFileSync("test.txt").toString().trim().split("\n");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");

const N = Number(input[0]);
const A = input[1].split(" ").map((v) => Number(v));
const dp = [1];

function main() {
  for (let i = 1; i < N; i++) {
    let max = 0;
    for (let j = 0; j < i; j++) {
      if (A[j] < A[i]) {
        max = Math.max(max, dp[j]);
      }
    }
    dp[i] = max + 1;
  }

  console.log(Math.max(...dp));
}

main();
