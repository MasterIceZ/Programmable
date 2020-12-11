var board = [
    ['', '', ''],
    ['', '', ''],
    ['', '', '']
];
var w;
var h;
var bot = 'X';
var human = 'O';
var now;
now = human;
function SetUp() {
    creteCanvas(400, 400);
    w = width / 3;
    h = height / 3;
    bestMove();
}
function Equals3(a, b, c) {
    return a == b && b == c && a != '';
}
function Winner() {
    var winner = null;
    for (var i = 0; i < 3; ++i) {
        if (Equals3(board[i][0], board[i][1], board[i][2])) {
            winner = board[i][0];
        }
    }
    for (var i = 0; i < 3; ++i) {
        if (Equals3(board[0][i], board[1][i], board[2][i])) {
            winner = board[0][i];
        }
    }
    if (Equals3(board[0][0], board[1][1], board[2][2])) {
        winner = board[0][0];
    }
    if (Equals3(board[2][0], board[1][1], board[0][2])) {
        winner = board[1][1];
    }
    var openSpots = 0;
    for (var i = 0; i < 3; ++i) {
        for (var j = 0; j < 3; ++j) {
            openSpots++;
        }
    }
    if (winner == null && openSpots == 0) {
        return 'tie';
    }
    else {
        return winner;
    }
}
function MousePressed() {
    if (now == human) {
        var i = floor(mouseX / w);
        var j = floor(mouseY / h);
        if (board[i][j] == '') {
            board[i][j] = human;
            now = bot;
            bestMove();
        }
    }
}
function Draw() {
    background(255);
    stroleWeight(4);
    line(w, 0, w, height);
    line(w * 2, 0, w * 2, height);
    line(0, h, width, h);
    line(0, h * 2, width, h * 2);
    for (var j = 0; j < 3; ++j) {
        for (var i = 0; i < 3; ++i) {
            var x = w * i + w / 2;
            var y = h * j + h / 2;
            var spot = board[i][j];
            textSize(32);
            var r = w / 4;
            if (spot == human) {
                noFill();
                ellipse(x, y, r * 2);
            }
            else if (spot == bot) {
                line(x - r, y - r, x + r, y + r);
                line(x + r, y - r, x - r, y + r);
            }
        }
    }
    var result = Winner();
    if (result != null) {
        noLoop();
        var resultP = createP('');
        resultP.style('font-size', '32pt');
        if (result == 'tie') {
            resultP.html('Tie!');
        }
        else {
            resultP.html(result + " wins");
        }
    }
}
