const readline = require("readline");
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

const input = [];
rl.on("line", async (line) => {
  input.push(line);
}).on("close", () => {
  const num = Number(input[0]);
  const time = input[1]
    .split(" ")
    .map((e) => Number(e))
    .sort((a, b) => a - b);
  console.log(solver(time));
});

const solver = (array) => {
  let total = 0;
  const last = array.reduce((acc, t) => {
    total += acc;
    return acc + t;
  });
  total += last;
  return total;
};
