/*
*/
public class TicTacToe {
private int[] rows;
private int[] cols;
private int diagonal;
private int antiDiagonal;

/** Initialize your data structure here. */
public TicTacToe(int n) {
    rows = new int[n];
    cols = new int[n];
}

/** Player {player} makes a move at ({row}, {col}).
    @param row The row of the board.
    @param col The column of the board.
    @param player The player, can be either 1 or 2.
    @return The current winning condition, can be either:
            0: No one wins.
            1: Player 1 wins.
            2: Player 2 wins. */
public int move(int row, int col, int player) {
    int toAdd = player == 1 ? 1 : -1;

    rows[row] += toAdd;
    cols[col] += toAdd;
    if (row == col)
        diagonal += toAdd;

    if (col == (cols.length - row - 1))
        antiDiagonal += toAdd;

    int size = rows.length;
    if (rows[row] == size || rows[row] == -size)
        return rows[row] < 0 ? 2 : 1;

    if (cols[col] == size || cols[col] == -size)
        return cols[col] < 0 ? 2 : 1;

    if (diagonal == size || diagonal == -size)
        return diagonal < 0 ? 2 : 1;

    if (antiDiagonal == size || antiDiagonal == -size)
        return antiDiagonal < 0 ? 2 : 1;

    return 0;
}

