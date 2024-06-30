const fs = require("fs");
// const input = fs.readFileSync("test.txt").toString().trim().split("\n");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");

const N = Number(input[0]);

const A = Array.from({ length: 8 }, (_, idx) => idx + 1);

const arr = [];
const checked = [];

function dfs(n) {
  if (n === N) {
    console.log(arr.join(" "));
    return;
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
