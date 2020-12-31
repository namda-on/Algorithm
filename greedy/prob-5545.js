const readline = require("readline");

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

const input = [];
let num, d, t, dow, topping;
rl.on("line", async (line) => {
  input.push(line);
}).on("close", () => {
  num = input[0];
  [d, t] = input[1].split(" ").map((e) => Number(e));
  dow = Number(input[2]);
  topping = input
    .splice(3, 3 + num)
    .map((a) => Number(a))
    .sort((x, y) => y - x);
  const result = solver();
  console.log(result);
  process.exit();
});

const solver = () => {
  let cost = d;
  let max = dow / cost;
  for (let i = 0; i < num; i++) {
    if ((max * cost + topping[i]) / (cost + t) > max) {
      max = (max * cost + topping[i]) / (cost + t);
      cost += t;
    } else break;
  }

  return Math.floor(max);
};
