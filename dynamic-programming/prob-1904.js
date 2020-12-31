const readline = require("readline");

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

let n;

rl.on("line", async (line) => {
  n = line;
  const dp = Array.from({ length: 1000001 }, () => -1);

  dp[1] = 1;
  dp[2] = 2;
  for (let i = 3; i <= n; i++) {
    dp[i] = (dp[i - 1] + dp[i - 2]) % 15746;
  }

  console.log(dp[n]);
  process.exit();
});
