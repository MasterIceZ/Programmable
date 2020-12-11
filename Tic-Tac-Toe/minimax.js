function bestMove() {
    var bestScore = -Infinity;
    var move;
    for (var i = 0; i < 3; ++i) {
        for (var j = 0; j < 3; ++j) {
            if (board[i][j] == '') {
                board[i][j] = bot;
                var score = minimax(board, 0, false);
                board[i][j] = '';
                if (score > bestScore) {
                    bestScore = score;
                    move = { i: i, j: j };
                }
            }
        }
    }
    board[move.i][move.j] = bot;
    now = human;
}
var scores = {
    X: 10,
    O: -10,
    tie: 0
};
function minimax(board, depth, isMax) {
    var result = Winner();
    if (result !== null) {
        return scores[result];
    }
    if (isMax) {
        var bestScore = -Infinity;
        for (var i = 0; i < 3; ++i) {
            for (var j = 0; j < 3; ++j) {
                if (board[i][j] == '') {
                    board[i][j] = bot;
                    var score = minimax(board, depth + 1, false);
                    board[i][j] = '';
                    bestScore = max(score, bestScore);
                }
            }
        }
        return bestScore;
    }
    else {
        var bestScore = -Infinity;
        for (var i = 0; i < 3; ++i) {
            for (var j = 0; j < 3; ++j) {
                if (board[i][j] == '') {
                    board[i][j] = bot;
                    var score = minimax(board, depth + 1, true);
                    board[i][j] = '';
                    bestScore = min(score, bestScore);
                }
            }
        }
        return bestScore;
    }
}
