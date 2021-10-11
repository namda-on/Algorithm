const cal = (a = 1) => {
  let sum = 9;
  for (let i = 2; i <= a; i++) {
    sum += i * 9 * Math.pow(10, i - 1);
  }
  return sum;
};

const solution = (n = 1) => {
  let ten = 1; //자릿수
  while (true) {
    if (n < cal(ten)) {
      break;
    }
    ten++;
  }

  let remain = ten === 1 ? n : n - cal(ten - 1);
  const quotient = Math.floor(remain / ten);
  const remainder = remain % ten;

  let result = Math.pow(10, ten - 1) - 1;
  result += remainder === 0 ? quotient : quotient + 1; //최종 숫자

  if (remainder === 0) {
    return result.toString().slice(-1);
  }

  return result.toString().charAt(remainder - 1);
};

console.log(solution(5));
console.log(solution(15));
