function contarDivisores(numero) {
function calculateDistance(row, col, board) {
    const n = board.length;
    const m = board[0].length;
    const directions = [[-1, 0], [1, 0], [0, -1], [0, 1]];
    let minDistance = Infinity;
    
    for (let [dx, dy] of directions) {
        let x = row + dx;
        let y = col + dy;
        let distance = 1;

        while (x >= 0 && x < n && y >= 0 && y < m) {
            if (board[x][y] === '0') {
                minDistance = Math.min(minDistance, distance);
                break;
            }
            x += dx;
            y += dy;
            distance++;
        }
    }
    
    return Math.min(minDistance, 9);
}

function colorizeBoard(N, board) {
    const coloredBoard = [];

    for (let i = 0; i < N; i++) {
        const newRow = [];
        for (let j = 0; j < N; j++) {
            if (board[i][j] === '*') {
                newRow.push(calculateDistance(i, j, board));
            } else {
                newRow.push(board[i][j]);
            }
        }
        coloredBoard.push(newRow.join(''));
    }

    return coloredBoard;
}

function printBoard(board) {
    for (let row of board) {
        console.log(row);
    }
}

// Exemplo de uso
const input1 = [
    "**000***",
    "********",
    "*****0**",
    "********",
    "*****000",
    "*******0",
    "0******0",
    "********"
];

const input2 = [
    "***",
    "***",
    "**0"
];

const N1 = input1.length;
const N2 = input2.length;

const output1 = colorizeBoard(N1, input1);
const output2 = colorizeBoard(N2, input2);

printBoard(output1);
console.log();
printBoard(output2);
