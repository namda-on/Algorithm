const fs = require("fs");
// const input = fs.readFileSync("test.txt").toString().trim().split("\n");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");

const S = Array(20)
  .fill(null)
  .map(() => Array(20).fill(null));

const N = Number(input[0]);

for (let i = 0; i < N; i++) {
  input[i + 1]
    .split(" ")
    .map((v) => Number(v))
    .forEach((v, j) => {
      S[i][j] = v;
    });
}

let Answer = Infinity;
const arr = [];
const checked = [];

function dfs(n) {
  if (n === N / 2) {
    let sum = 0;
    let sum2 = 0;

    const arr2 = Array.from({ length: N }, (_, index) => index).filter(
      (v) => !arr.includes(v)
    );

    for (let i = 0; i < N / 2; i++) {
      for (let j = i + 1; j < N / 2; j++) {
        sum += S[arr[i]][arr[j]] + S[arr[j]][arr[i]];
        sum2 += S[arr2[i]][arr2[j]] + S[arr2[j]][arr2[i]];
      }
    }

    const diff = Math.abs(sum - sum2);
    if (diff < Answer) Answer = diff;

    return;
  }

  for (let i = 0; i < N; i++) {
    if (!checked[i]) {
      checked[i] = true;
      arr[n] = i;
      if (n === 0) dfs(n + 1);
      if (n >= 1 && i > arr[n - 1]) {
        dfs(n + 1);
      }
      checked[i] = false;
    }
  }
}

dfs(0);

console.log(Answer);
