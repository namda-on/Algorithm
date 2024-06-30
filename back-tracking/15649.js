const fs = require("fs");
// const input = fs.readFileSync("test.txt").toString().trim().split("\n");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");

const [N, M] = input[0].split(" ").map((v) => Number(v));

const checked = Array(N + 1).fill(false);
const arr = [];

function dfs(m) {
  if (m === M) {
    console.log(arr.join(" "));
    return;
  }

  for (let i = 1; i <= N; i++) {
    if (!checked[i]) {
      checked[i] = true;
      arr[m] = i;
      dfs(m + 1);
      checked[i] = false;
    }
  }
}

dfs(0);
