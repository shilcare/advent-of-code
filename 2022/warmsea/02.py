import util


def p1():
    input_lines = util.get_input_lines(__file__, "02.input")

    def calc_score(line):
        left, right = line.split()
        left = ord(left) - ord("A") + 1
        right = ord(right) - ord("X") + 1
        return right + (right - left + 3 + 1) % 3 * 3

    return sum(map(calc_score, input_lines))


def p2():
    input_lines = util.get_input_lines(__file__, "02.input")

    def calc_score(line):
        left, strategy = line.split()
        left = ord(left) - ord("A") + 1
        if strategy == "X":  # lose
            return (left - 1 + 3 - 1) % 3 + 1
        elif strategy == "Y":  # draw
            return 3 + left
        else:  # win
            return 6 + left % 3 + 1

    return sum(map(calc_score, input_lines))


if __name__ == "__main__":
    print(p1())
    print(p2())
